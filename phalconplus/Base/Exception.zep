namespace PhalconPlus\Base;

class Exception extends \Exception
{
    protected message = "";
    protected level = \Phalcon\Logger::DEBUG;
    protected code = 0;

    public function __construct(var message = "", <\Phalcon\Logger\Adapter> logger = null)
    {
        if empty message {
            let message = "An exception created: " . get_called_class();
        }

        if !is_null(logger) {
            logger->log(message, this->getLevel());
        }

        if empty this->message {
            let this->message = message;
        }
    }

    public function getLevel()
    {
        return this->level;
    }

    public function setCode(var code)
    {
        let this->code = code;
        return this;
    }

    public function setLevel(var level)
    {
        let this->level = level;
        return this;
    }
}