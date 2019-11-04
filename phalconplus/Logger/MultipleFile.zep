namespace PhalconPlus\Logger;
use PhalconPlus\Logger\Processor\AbstractProcessor;

class MultiPleFile extends \Phalcon\Logger\MultiPle
{
    protected processors = [] { get };

    public function  __construct(array! options)
    {  
        var opt, logger;
        for opt in options {
            let logger = new \Phalcon\Logger\Adapter\File(opt["filePath"]);
            logger->setLogLevel(opt["level"]);
            this->push(logger);
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
     public function log(var type, var message = null, array! context = null)
     {
         var loggers, logger, name, processor, custormContext = [];
 
         if empty(context) {
             if !empty(this->processors) {
                for name, processor in this->processors {
                    let custormContext[name] = processor->__toString();
                }
            }
         } else {
             let custormContext = context;
         }

         let loggers = this->_loggers;
         if typeof loggers == "array" {
             for logger in loggers {
                 if logger->getLogLevel() === \Phalcon\Logger::SPECIAL { 
                    logger->log(type, message, custormContext);
                 }
                 if(logger->getLogLevel() === type) {
                    logger->log(type, message, custormContext);
                 }
             }
         }
    }
}