namespace PhalconPlus\Base;
use PhalconPlus\Assert\Assertion as Assert;

/**
 * throw new Exception("error message");
 * throw new Exception(["error message", ["foo", "bar"]]);
 *
 */
class Exception extends \Exception
{
    protected message = "";
    protected level = \Phalcon\Logger::DEBUG;
    protected code = 0;
    protected info = [] { get };

    public function __construct(var info = "", var logger = null)
    {
        var message = "", args = [];
        let message = "An exception created: " . get_called_class();
        if empty info {
            // nothing to do here ...
        } else {
            if is_array(info) {
                let this->info = info;
                let message = message . ", message: " . strval(info[0]);
                if fetch args, info[1] {
                    let args = is_array(info[1]) ? info[1] : [strval(info[1])];
                }
            } elseif is_string(info) {
                let message = message . ", message: " . info;
            }
        }
        if !is_null(logger) {
            Assert::isInstanceOf(logger, [
                "\\Phalcon\\Logger\\Adapter",
                "\\Phalcon\\Logger\\Multiple"
            ]);
            logger->log(message . ", args: ". json_encode(args, JSON_UNESCAPED_UNICODE), this->getLevel());
        }

        if empty this->message {
            let this->message = message;
        }

        var cnt, argsCnt;
        let cnt = substr_count(this->message, "%s");
        let argsCnt = count(args);

        if argsCnt >= cnt {
            let this->message = vsprintf(this->message, args);
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

    public function setMessage(var msg)
    {
        let this->message = msg;
        return this;
    }
}