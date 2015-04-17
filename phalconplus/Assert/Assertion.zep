namespace PhalconPlus\Assert;
use PhalconPlus\Enum\AssertionCode;

/**
 *
 * @ref https://github.com/beberlei/assert
 */
class Assertion
{
    // static protected exceptionClass = "\\PhalconPlus\\Assert\\InvalidArgumentException";
    
    protected static function createException(value, message, code, propertyPath, array constraints = [])
    {
        return new \PhalconPlus\Assert\InvalidArgumentException(message, code, propertyPath, value, constraints);
    }
    
    public static function eq(var value, var value2, var message = null, var propertyPath = null)
    {
        if value != value2 {
            var v1, v2;
            let v1 = self::stringify(value);
            let v2 = self::stringify(value2);

            if message === null {
                let message = "Value " . v1 . " does not equal expected value " . v2 . ".";
            }

            throw static::createException(value, message, AssertionCode::INVALID_SAME, propertyPath, ["expected": value2]);
        }
    }

    public static function same(var value, var value2, var message = null, var propertyPath = null)
    {
        if value !== value2 {
            var v1, v2;
            let v1 = self::stringify(value);
            let v2 = self::stringify(value2);

            if message === null {
                let message = "Value " . v1 . " does not equal expected value " . v2 . ".";
            }

            throw static::createException(value, message, AssertionCode::INVALID_EQ, propertyPath, ["expected": value2]);
        }
    }

    public static function notEmpty(var value, var message = null, var propertyPath = null)
    {
        if empty value {
            var v1;
            let v1 = self::stringify(value);
            if message === null {
                let message = "Value " . v1 . " is empty, but non empty value was expected.";
            }
            
            throw static::createException(value, message, AssertionCode::VALUE_EMPTY, propertyPath);
        }
    }

    public static function notNull(var value, var message = null, var propertyPath = null)
    {
        if value === null {
            var v1;
            let v1 = self::stringify(value);
            if message === null {
                let message = "Value " . v1 . " is null, but non null value was expected.";
            }
            throw static::createException(value, message, AssertionCode::VALUE_NULL, propertyPath);
        }
    }

    public static function numeric(var value, var message = null, var propertyPath = null)
    {
        if !is_numeric(value) {
            var v1;
            let v1 = self::stringify(value);
            if message === null {
                let message = "Value " . v1 . " is not numeric";
            }
            throw static::createException(value, message, AssertionCode::INVALID_NUMERIC, propertyPath);
        }
    }

    private static function stringify(value)
    {
        if is_bool(value) {
            return value ? "<TRUE>" : "<FALSE>";
        }
        var val;
        if is_scalar(value) {
            let val = (string) value;
            if (strlen(val) > 100) {
                let val = substr(val, 0, 97) . "...";
            }
            return val;
        }
        if is_array(value) {
            return "<ARRAY>";
        }
        if is_object(value) {
            return get_class(value);
        }
        if is_resource(value) {
            return "<RESOURCE>";
        }
        if value === NULL {
            return "<NULL>";
        }
        return "unknown";
    }
}