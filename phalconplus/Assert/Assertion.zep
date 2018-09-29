namespace PhalconPlus\Assert;
use PhalconPlus\Enum\AssertionCode;

/**
 *
 * @ref https://github.com/beberlei/assert
 */
class Assertion
{
    protected static function createException(value, message, code, propertyPath, array constraints = [])
    {
        return new \PhalconPlus\Assert\InvalidArgumentException(message, code, propertyPath, value, constraints);
    }

    public static function eq(var value1, var value2, var message = null, var propertyPath = null) -> boolean
    {
        if value1 != value2 {
            var v1, v2;
            let v1 = self::stringify(value1);
            let v2 = self::stringify(value2);

            if message === null {
                let message = "Value " . v1 . " does not equal expected value " . v2 . ".";
            }

            throw static::createException(value1, message, AssertionCode::INVALID_SAME, propertyPath, ["expected": value2]);
        }

        return true;
    }

    public static function notEq(var value1, var value2, var message = null, var propertyPath = null) -> boolean
    {
        if value1 == value2 {
            let message = sprintf(
                message ? message : "Value \"%s\" is equal to expected value \"%s\".",
                static::stringify(value1),
                static::stringify(value2)
            );

            throw static::createException(value1, message, AssertionCode::INVALID_NOT_EQ, propertyPath, ["expected": value2]);
        }

        return true;
    }

    public static function same(var value1, var value2, var message = null, var propertyPath = null) -> boolean
    {
        if value1 !== value2 {
            var v1, v2;
            let v1 = self::stringify(value1);
            let v2 = self::stringify(value2);

            if message === null {
                let message = "Value " . v1 . " does not equal expected value " . v2 . ".";
            }

            throw static::createException(value1, message, AssertionCode::INVALID_EQ, propertyPath
                                          , ["expected": value2]);
        }

        return true;
    }

    public static function notEmpty(var value, var message = null, var propertyPath = null) -> boolean
    {
        if empty value {
            var v1;
            let v1 = self::stringify(value);
            if message === null {
                let message = "Value " . v1 . " is empty, but non empty value was expected.";
            }
            throw static::createException(value, message, AssertionCode::VALUE_EMPTY, propertyPath);
        }

        return true;
    }

    public static function notNull(var value, var message = null, var propertyPath = null) -> boolean
    {
        if value === null {
            var v1;
            let v1 = self::stringify(value);
            if message === null {
                let message = "Value " . v1 . " is null, but non null value was expected.";
            }
            throw static::createException(value, message, AssertionCode::VALUE_NULL, propertyPath);
        }
        return true;
    }

    public static function numeric(var value, var message = null, var propertyPath = null) -> boolean
    {
        if !is_numeric(value) {
            var v1;
            let v1 = self::stringify(value);
            if message === null {
                let message = "Value " . v1 . " is not numeric.";
            }
            throw static::createException(value, message, AssertionCode::INVALID_NUMERIC, propertyPath);
        }

        return true;
    }

    public static function range(var value, int minValue, int maxValue, var message = null, var propertyPath = null) -> boolean
    {
        static::numeric(value, message, propertyPath);
        if value < minValue || value > maxValue {
            let message = sprintf(
                message ? message : "Number \"%s\" was expected to be at least \"%d\" and at most \"%d\".",
                static::stringify(value),
                static::stringify(minValue),
                static::stringify(maxValue)
            );
            throw static::createException(value, message, AssertionCode::INVALID_RANGE, propertyPath
                                          , ["min": minValue, "max": maxValue]);
        }

        return true;
    }

    public static function min(var value, int minValue, var message = null, var propertyPath = null) -> boolean
    {
        static::numeric(value, message, propertyPath);

        if value < minValue {
            let message = sprintf(
                message ? message : "Number \"%s\" was expected to be at least \"%s\".",
                static::stringify(value),
                static::stringify(minValue)
            );
            throw static::createException(value, message, AssertionCode::INVALID_MIN, propertyPath
                                          , ["min": minValue]);
        }

        return true;
    }

    public static function max(var value, int maxValue, var message = null, var propertyPath = null) -> boolean
    {
        static::numeric(value, message, propertyPath);

        if value > maxValue {
            let message = sprintf(
                message ? message : "Number \"%s\" was expected to be at most \"%s\".",
                static::stringify(value),
                static::stringify(maxValue)
            );
            throw static::createException(value, message, AssertionCode::INVALID_MAX, propertyPath
                                          , ["max": maxValue]);
        }

        return true;
    }

    public static function isString(var value, var message = null, var propertyPath = null) -> boolean
    {
        if !is_string(value) {
            let message = sprintf(
                message ? message : "Value \"%s\" expected to be string, type %s given.",
                static::stringify(value),
                gettype(value)
            );
            throw static::createException(value, message, AssertionCode::INVALID_STRING, propertyPath);
        }

        return true;
    }

    public static function isArray(var value, var message = null, var propertyPath = null) -> boolean
    {
        if !is_array(value) {
            let message = sprintf(
                message ? message : "Value \"%s\" is not an array.",
                static::stringify(value)
            );
            throw static::createException(value, message, AssertionCode::INVALID_ARRAY, propertyPath);
        }
        return true;
    }

    public static function isJsonString(var value, var message = null, var propertyPath = null) -> boolean
    {
        static::isString(value, message, propertyPath);
        if null == json_decode(value) && JSON_ERROR_NONE != json_last_error() {
            let message = sprintf(
                message ? message : "Value \"%s\" is not a valid JSON string.",
                static::stringify(value)
            );

            throw static::createException(value, message, AssertionCode::INVALID_JSON_STRING, propertyPath);
        }

        return true;
    }

    private static function stringify(value)
    {
        if is_bool(value) {
            return value == true ? "TRUE" : "FALSE";
        }

        if value === NULL {
            return "NULL";
        }

        var val;
        if is_scalar(value) {
            let val = (string) value;
            if strlen(val) > 100 {
                let val = substr(val, 0, 96) . " ...";
            }
            return val;
        }

        if is_array(value) || is_object(value) || is_resource(value) {
            let val = print_r(value, true);
            let val = preg_replace("/\s+/", " ", val);
            if strlen(val) > 160 {
                return substr(val, 0, 156) . " ...";
            }
            return val;
        }

        return "unknown";
    }
}
