namespace PhalconPlus\Logger\Processor;

class Msec extends AbstractProcessor
{
    protected msec;

    public function __construct()
    {
    }

    public function __toString()
    {
        var tmp;
        let tmp = sscanf(microtime(), "%f %d");
        let this->msec = sprintf("%03d", tmp[0] * 1000);
        return this->msec;
    }
}
