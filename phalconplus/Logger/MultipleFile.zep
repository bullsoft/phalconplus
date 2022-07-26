namespace PhalconPlus\Logger;
use PhalconPlus\Logger\Processor\AbstractProcessor;
use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Formatter\FormatterInterface;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\Logger\Logger as PhLogger;

class MultiPleFile extends PhLogger
{
    protected processors = [] { get };

    protected options = [];

    /**
     *  options = [
     *          [
     *               "name" => "local",
     *               "filePath" => "/path/to/logger/file.log",
     *               "level"  => \Phalcon\Logger::DEBUG,
     *          ],
     *          [
     *               "name" => "remote",
     *               "filePath" => "/path/to/logger/file.log",
     *               "level" => \Phalcon\Logger::CUSTOM，
     *          ],
     *  ]
     */
    public function  __construct(array! options)
    {
        if empty options {
            throw new BaseException("Logger config can not be empty");
        }

        var opt, logger, level, name, dir;

        for opt in options {
            let level = opt["level"];
            let this->options[level] = opt;
            let dir = dirname(opt["filePath"]);
            if !is_dir(dir) {
                mkdir(dir, 0777, true);
            }
            let logger = new Stream(opt["filePath"]);
            if isset opt["name"] {
                this->addAdapter(opt["name"], logger);
            } else {
                let name = "adapter#".level;
                this->addAdapter(name, logger);
                let this->options[level]["name"] = name;
            }
        }
    }
    
    public function addProcessor(string! name, <AbstractProcessor> processor) -> <MultiPleFile>
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
        return "<empty>";
    }

    public function __get(string! property) -> string
    {
        return this->getProcessorVar(property);
    }

    protected function addMessage(int level, string message, array context = []) -> bool
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

        var options = this->options;
        if isset options[level] {
            unset(options[level]);
        } elseif isset options[self::CUSTOM] {
            unset(options[self::CUSTOM]);
        } else {
            // nothing here...
        }
        this->excludeAdapters(array_column(options, "name"));
        return parent::addMessage(level, message, custormContext);
    }

    public function setFormatter(<FormatterInterface> formatter) -> <MultiPleFile>
    {
        var adapter;
        for adapter in this->adapters {
            adapter->setFormatter(formatter);
        }
        return this;
    }
}