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

    public static function commaString()
    {
        var vals = static::validValues(true);
        return implode(", ", vals);
    }

    public static function getList()
    {
        return static::validValues(false);
    }

    public static function getMap()
    {
        return static::validValues(true);
    }

    public static function getValues()
    {
        return static::validValues(true);
    }

    public static function validValues(bool assoc = false)
    {
        var reflection, consts;

        let reflection = new \ReflectionClass(get_called_class());
        let consts = reflection->getConstants();
        unset(consts["__default"]);

        var countValues;
        let countValues = array_count_values(consts);

        if count(consts) !== count(countValues) {
            var duplicated = [];
            let duplicated = array_filter(countValues, function(freq) {
                return freq > 1;
            });
            throw new \RuntimeException("Duplicated values were found in Enum Class: " . get_called_class(). " with values in " . json_encode(array_keys(duplicated)));
        }

        if assoc == true {
            return consts;
        } else {
            return array_values(consts);
        }
    }

    public function jsonSerialize() -> mixed
    {
        return this->getValue();
    }

    public function __toString()
    {
        return (string) this->getValue();
    }
}
