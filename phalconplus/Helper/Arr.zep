namespace PhalconPlus\Helper;
use PhalconPlus\Assert\Assertion as Assert;
use PhalconPlus\Base\ProtoBuffer;

class Arr
{
    public static function isAllKeyInt(var inputArray) -> boolean
    {
        Assert::isArray(inputArray);
        if count(inputArray) <= 0 {
            return true;
        }
        var input = array_unique(array_map("is_int", array_keys(inputArray)));
        var expected = [true];
        return  input === expected;
    }
    
    public static function isAllKeyString(var inputArray) -> boolean
    {
        Assert::isArray(inputArray);
        if count(inputArray) <= 0 {
            return true;
        }
        var input = array_unique(array_map("is_string", array_keys(inputArray)));
        var expected = [true];
        return input === expected;
    }

    public static function isKeyNumericSequentialZeroBased(var inputArray) -> boolean
    {
        Assert::isArray(inputArray);
        if count(inputArray) <= 0 {
            return true;
        }
        var input = array_keys(inputArray);
        var expected = range(0, count(inputArray) - 1);
        return  input === expected;
    }

    public static function newProtoBuffer(inputArray) -> <ProtoBuffer>
    {
        Assert::isArray(inputArray);
        return new ProtoBuffer(inputArray);
    }

    public static function encodeJson(inputArray) -> string
    {
        Assert::isArray(inputArray);
        var str = json_encode(inputArray, JSON_UNESCAPED_UNICODE);
        var errCode = json_last_error();
        if JSON_ERROR_NONE != errCode {
            throw new Exception(json_last_error_msg());
        }
        return str;
    }

    public static function firstKey(inputArray)
    {
        Assert::isArray(inputArray);
        reset(inputArray);
        var k, v;
        for k, v in inputArray {
            return k;
        }
    }

    public static function lastKey(inputArray)
    {
        Assert::isArray(inputArray);
        reset(inputArray);
        var k, v;
        for k, v in reverse inputArray {
            return k;
        }
    }

    public static function first(inputArray)
    {
        Assert::isArray(inputArray);
        return reset(inputArray);
    }

    public static function last(inputArray)
    {
        Assert::isArray(inputArray);
        return end(inputArray);
    }

    /**
     * 
     * handler = function(string | int key, mixed val) : string {
     *    return <string>
     * }
     *
     */
    public static function groupBy(inputArray, callable handler) -> array
    {
        Assert::isArray(inputArray);
        
        var k, v;
        var tmp = [];
        for k, v in inputArray {
            var group = call_user_func(handler, k, v);
            if !isset tmp[group] {
                let tmp[group] = [];
            }
            let tmp[group][k] = v;
        }
        return tmp;
    }

}