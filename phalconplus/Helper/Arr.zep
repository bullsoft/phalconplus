namespace PhalconPlus\Helper;
use PhalconPlus\Assert\Assertion as Assert;
use PhalconPlus\Base\ProtoBuffer;

class Arr
{
    public static function isAllKeyInt(var inputArray)
    {
        Assert::isArray(inputArray);
        if count(inputArray) <= 0 {
            return true;
        }
        var input = array_unique(array_map("is_int", array_keys(inputArray)));
        var expected = [true];
        return  input === expected;
    }
    
    public static function isAllKeyString(var inputArray)
    {
        Assert::isArray(inputArray);
        if count(inputArray) <= 0 {
            return true;
        }
        var input = array_unique(array_map("is_string", array_keys(inputArray)));
        var expected = [true];
        return input === expected;
    }

    public static function isKeyNumericSequentialZeroBased(var inputArray)
    {
        Assert::isArray(inputArray);
        if count(inputArray) <= 0 {
            return true;
        }
        var input = array_keys(inputArray);
        var expected = range(0, count(inputArray) - 1);
        return  input === expected;
    }

    public static function newProtoBuffer(inputArray)
    {
        return new ProtoBuffer(inputArray);
    }
}