namespace PhalconPlus\Logger\Adapter;
use PhalconPlus\Assert\Assertion as Assert;
use Phalcon\Logger\AdapterInterface;

class FilePlus extends \Phalcon\Logger\Adapter\File
{
    private type2Handler = [];
    private type2Ext = [];

    private mode; // file open mode

    private _path;
    private _options;
    private _fileHandler;

    public function __construct(string! filePath, array options = [])
    {
        Assert::notEmpty(filePath);

        var mode;
        if fetch mode, options["mode"] {
            if strpos(mode, "r") === false {
                let this->mode = mode;
            } else {
                throw new \InvalidArgumentException("Logger must be opened in append or write mode");
            }
        } else {
            let this->mode = "ab";
        }

        let this->_fileHandler = this->open(filePath);
        let this->_path = filePath;
        let this->_options = options;

        // store default file handler with index -1
        let this->type2Handler[-1] = this->_fileHandler;
        let this->type2Ext[-1] = "";
    }

    private function open(string! filePath)
    {
        var handler = null;
        let handler = fopen(filePath, this->mode);
        if handler == false {
            throw new \Exception("Cannot open log file " . filePath);
        }
        return handler;
    }

    // Compatible with PSR-3
    public function log(var type, var message = null, array! context = null) -> <AdapterInterface>
	{
		var handler, toggledType;

		if typeof type == "string" && typeof message == "integer" {
			let toggledType = message;
		} else {
			if typeof type == "string" && typeof message == "null" {
				let toggledType = message;
			} else {
				let toggledType = type;
			}
		}

		if typeof toggledType == "null" {
			let toggledType = \Phalcon\Logger::DEBUG;
		}

        if fetch handler, this->type2Handler[toggledType] {
            let this->_fileHandler = handler;
        } else {
            let this->_fileHandler = this->type2Handler[-1];
        }

        return parent::log(type, message, context);
    }

    /* Not compatibility for PSR3
    public function log(string! message, int type = \Phalcon\Logger::DEBUG, array context = null)
    {
        var handler;
        if fetch handler, this->type2Handler[type] {
            let this->_fileHandler = handler;
        } else {
            let this->_fileHandler = this->type2Handler[-1];
        }
        parent::logInternal(message, type, time(), context);
    }
    */


    public function registerExtension(string! ext, array types)
    {
        Assert::notEmpty(ext);
        Assert::notEmpty(types);

        var filePath, type, fileHandler;
        let filePath  = this->_path . ext;
        let fileHandler = this->open(filePath);
        for type in types {
            let this->type2Handler[type] = fileHandler;
            let this->type2Ext[type] = ext;
        }
    }

    public function close()
    {
        var type, handler;
        for type, handler in this->type2Handler {
            fclose(handler);
            unset(this->type2Handler[type]);
        }
    }

    public function __destruct()
    {
        this->close();
    }

    public function __wakeup()
    {
        var type, ext, handler, ext2Handler = [];
        for type, ext in this->type2Ext {
            if fetch handler, ext2Handler["ext"] {
                // do nothing
            } else {
                let handler = this->open(this->_path . ext);
                let ext2Handler[ext] = handler;
            }
            let this->type2Handler[type] = handler;
        }
        let this->_fileHandler = this->type2Handler[-1];
    }
}
