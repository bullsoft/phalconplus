namespace PhalconPlus\Logger\Processor;

class LogId extends AbstractProcessor
{
    private static id = "";

    public function __construct(var len = 18)
    {
        if empty(self::id) {
            if (strlen(len) > 2) {
                let self::id = len;
            } else {
                let self::id = substr(hash("md5", uniqid("", true)), 0, len);
            }
        }
    }

    public static function setId(string! logId)
    {
        let self::id = logId;
    }

    public static function getId()
    {
        return self::id;
    }

    public function __toString()
    {
        return self::id;
    }
}
