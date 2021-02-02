namespace PhalconPlus\Logger;
use PhalconPlus\Logger\Processor\AbstractProcessor;
use Phalcon\Logger\Adapter\Stream;

class MultiPleFile extends \Phalcon\Logger
{
    protected processors = [] { get };

    /**
     *  options = [
     *       "level" => Phalcon\Logger::INFO,
     *       "adapters" => [
     *          [
     *               "name" => "local",
     *               "filePath" => "/path/to/logger/file.log",
     *          ],
     *          [
     *               "name" => "local",
     *               "filePath" => "/path/to/logger/file.log",
     *          ],
     *       ]
     */
    public function  __construct(array! options)
    {
        if empty options {
            throw new \PhalconPlus\Base\Exception("Logger config can not empty");
        }

        var opt, logger, level;

        if isset(options["level"]) {
            let level = options["level"];
        } else {
            let level = options[0]["level"];
        }

        this->setLogLevel(level);

        if isset(options["adapters"]) {
            for opt in options["adapters"] {
                let logger = new Stream(opt["filePath"]);
                this->addAdapter(opt["name"], logger);
            }
        } else {
            var i = 1;
            for opt in options {
                let logger = new Stream(opt["filePath"]);
                this->addAdapter("message". i, logger);
                let i = i + 1;
            }
        }
    }
    
    public function addProcessor(string! name, <AbstractProcessor> processor)
    {
        let this->processors[name] = processor;
        return this;
    }

    public function getProcessorVar(string! name)  -> string
    {
        var processor;
        if fetch processor, this->processors[name] {
            return (string) processor;
        }
        return "";
    }

    public function __get(string! property) -> string
    {
        return this->getProcessorVar(property);
    }

	/**
	 * Sends a message to each registered logger
	 */
     public function log(level, message, array context = []) -> void
     {
         var name, processor, custormContext = [];
 
         if empty(context) {
             if !empty(this->processors) {
                for name, processor in this->processors {
                    let custormContext[name] = processor->__toString();
                }
            }
         } else {
             let custormContext = context;
         }

         parent::log(level, message, custormContext);
    }
}