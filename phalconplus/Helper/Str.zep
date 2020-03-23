namespace PhalconPlus\Helper;
use PhalconPlus\Assert\Assertion as Assert;

class Str
{
    public static function decodeJson(string inputStr) -> <\ArrayObject>
    {
        var obj, e;
        let obj = new \ArrayObject([], \ArrayObject::ARRAY_AS_PROPS);
        try {
            Assert::isJsonString(inputStr, null, "/", obj);
        } catch \Exception, e {
            throw new Exception(e->getMessage());
        }
        return obj;
    }
}