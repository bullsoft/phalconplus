namespace PhalconPlus\Helper;
use PhalconPlus\Assert\Assertion as Assert;

class Variable
{
    const NULL_VALUE = "$Ph/Var/SoftNull$";

    public static function softNull()
    {
        return Variable::NULL_VALUE;
    }

    public static function isSoftNull(string nil)
    {
        return Variable::NULL_VALUE === nil;
    }

    /**
     * if $a is null, exception will be thrown
     *
     * Variable::notNull($a)->callMethod()
     */ 
    public static function notNull(var val)
    {
        Assert::notNull(val);
        return val;
    }

    public static function notEmpty(var val) 
    {
        Assert::notEmpty(val);
        return val;
    }

    public static function isInt(var input) -> boolean
    {
        return typeof input == "integer";
    }

    public static function isArray(var input) -> boolean
    {
        return typeof input == "array";
    }

    public static function isObject(var input) -> boolean
    {
        return typeof input == "object";
    }

    public static function isBool(var input) -> boolean
    {
        return typeof input == "boolean";
    }

    public static function isString(var input) -> boolean
    {
        return typeof input == "string";
    }

    public static function isNull(var input) -> boolean
    {
        return typeof input == "null";
    }

    public static function isFloat(var input) -> boolean
    {
        return typeof input == "float";
    }

    public static function isFunctional(var input) -> boolean
    {
        return typeof input == "callable";
    }

    public static function stringify(var value, bool full = false) -> string
    {
        if is_bool(value) {
            return value == true ? "TRUE" : "FALSE";
        }
        if value === NULL { 
            return "NULL"; 
        }
        var val = "";
        if is_scalar(value) {
            let val = (string) value;
            if full == false && strlen(val) > 100 {
                let val = substr(val, 0, 96) . " ...";
            }
            return val;
        }
        if is_array(value) || is_object(value) || is_resource(value) {
            let val = print_r(value, true);
            let val = preg_replace("/\s+/", " ", val);
            if full == false && strlen(val) > 260 {
                return substr(val, 0, 256) . " ...";
            }
            return val;
        }
        return "unknown";
    }
}