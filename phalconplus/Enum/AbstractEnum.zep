namespace PhalconPlus\Enum;

abstract class AbstractEnum implements \JsonSerializable
{
    protected val;

    public function __construct(var val = "__PhalconPlus_AbstractEnum_DefaultValue__")
    {
        var reflection, defaultVal;

        let reflection = new \ReflectionClass(get_called_class());
        if(reflection->hasConstant("__default")) {
            let defaultVal = reflection->getConstant("__default");
            if !static::isValid(defaultVal) {
                throw new \OutOfRangeException(sprintf("Invalid __default enumeration %s for Enum %s", defaultVal, get_class(this)));
            }
        }
        
        if val == "__PhalconPlus_AbstractEnum_DefaultValue__" {
            this->setValue(defaultVal);
        } else {
            this->setValue(val);
        }
    }

    protected function setValue(var val)
    {
        if !static::isValid(val) {
            throw new \InvalidArgumentException(sprintf("Invalid enumeration %s for Enum %s", val, get_class(this)));
        }
        let this->val = val;
    }

    public function getValue()
    {
        return this->val;
    }

    public static function isValid(val)
    {
        if !in_array(val, static::validValues(), true) {
            return false;
        }
        return true;
    }

    public static function validValues(bool assoc = false)
    {
        var reflection, consts;
        
        let reflection = new \ReflectionClass(get_called_class());
        let consts = reflection->getConstants();
        unset(consts["__default"]);
        
        if assoc == true {
            return consts;
        } else {
            return array_values(consts);
        }
    }

    public function jsonSerialize()
    {
        return this->getValue();
    }

    public function __toString()
    {
        return (string) this->getValue();
    }
}