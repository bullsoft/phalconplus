namespace PhalconPlus\Logger\Processor;

class Uid extends AbstractProcessor
{
    private uid;

    public function __construct(var len = 18)
    {
        let this->uid = substr(hash("md5", uniqid("", true)), 0, len);
    }

    public function __toString()
    {
        return this->uid;
    }
}