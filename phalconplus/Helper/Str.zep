namespace PhalconPlus\Helper;
use PhalconPlus\Assert\Assertion as Assert;

class Str
{
    public static function decodeJson(string inputStr) -> array
    {
        var obj, e;
        let obj = new \ArrayObject([], \ArrayObject::ARRAY_AS_PROPS);
        try {
            Assert::isJsonString(inputStr, null, "/", obj);
        } catch \Exception, e {
            throw new Exception(e->getMessage());
        }
        return obj->getArrayCopy();
    }

    public static function startsWith(string full, string partial) -> boolean
    {
        return partial === mb_substr(full, 0, strlen(partial));
    }

    public static function endsWith(string full, string partial) -> boolean
    {
        return partial === mb_substr(full, -1 * strlen(partial));
    }

    public static function contains(string full, string partial) -> boolean
    {
        return mb_substr_count(full, partial) > 0;
    }

    public static function safeBase64Encode(string inputStr, boolean padding = false) -> string
    {
        var s;
		let s = strtr(base64_encode(inputStr), "+/", "-_");

		if !padding {
			return rtrim(s, "=");
        }
        
		return s;
    }

    public static function safeBase64Decode(string inputStr)
    {
        return base64_decode(strtr(inputStr, "-_", "+/"));
    }
}