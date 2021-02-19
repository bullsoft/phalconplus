namespace PhalconPlus\Base;
use \PhalconPlus\Assert\Assertion as Assert;
use \PhalconPlus\Enum\Sys as Sys;
/**
 * throw new Exception("error message");
 * throw new Exception(["error message", "hello"]);
 * throw new Exception(["error message", ["foo", "bar"]]);
 * throw new Exception(["error message", "text" => "", "args" => ["foo", "bar"]]);
 *
 */
class Exception extends \Exception
{
    protected level = \Phalcon\Logger::DEBUG;
    protected info;

    public function __construct(info = null, int code = 0)
    {
        var message = "", args = [];
        let message = "An exception created: " . get_class(this);
        if !empty info {
            if is_array(info) {
                let this->info = info;
                let message = message . ", message: " . strval(info[0]);
                if fetch args, info[1] {
                    let args = is_array(args) ? args : [strval(args)];
                } elseif fetch args, info["args"] {
                    let args = is_array(args) ? args : [strval(args)];
                }
            } elseif is_string(info) {
                let message = message . ", message: " . info;
            }
        }

        if Sys::app()->isBooted() && Sys::app()->di()->has("logger") {
            var logger = Sys::app()->di()->get("logger");
            var argsJson = json_encode(args, JSON_UNESCAPED_UNICODE);
            logger->log(this->getLevel(), message . ", args: ". argsJson);
        }

        var showMessage;
        if fetch showMessage, info["text"] {
            let showMessage = strval(showMessage);
        } elseif !empty this->message {
            let showMessage = this->message;
        } else {
            let showMessage = message;
        }
        var cnt = substr_count(showMessage, "%s");
        if cnt > 0 && count(args) >= cnt {
            let showMessage = vsprintf(showMessage, args);
        }
        if this->code > 0 {
            let code = this->code;
        }
        
        parent::__construct(showMessage, code);
    }

    public function getLevel()
    {
        return this->level;
    }

    public function setLevel(var level)
    {
        let this->level = level;
        return this;
    }

    public function getInfo()
    {
        return this->info;
    }
}