namespace PhalconPlus\Enum;
use PhalconPlus\Enum\AbstractEnum;

class Exception extends AbstractEnum
{
    protected static details;

    protected static function has(var eCode)
    {
        var code = null, details = [], className, val;
        let className = get_called_class();
        let code = new {className}(eCode);
        %{
        #if PHP_VERSION_ID >= 70000
        zend_class_entry *ce;
        ce = zephir_fetch_class_str_ex(Z_STRVAL_P(&className), Z_STRLEN_P(&className), ZEND_FETCH_CLASS_AUTO);
        zephir_read_static_property_ce(&details, ce, SL("details") TSRMLS_CC, 0);
        #else
        zephir_read_static_property_ce(&details, phalconplus_enum_exception_ce, SL("details") TSRMLS_CC);
        #endif
        }%        
        if fetch val, details[code->__toString()] {
            return val;
        } else {
            return [];
        }
    }

    public static function getByCode(var eCode)
    {
        var detail = [];
        let detail = static::has(eCode);
        if !empty detail {
            let detail["code"] = eCode;
        }
        return detail;
    }

    public static function newException(e, <\Phalcon\Logger\Adapter> logger = null)
    {
        var code, eCode, eName, map2Name, className;
        let map2Name = array_flip(static::validValues(true));
        let eCode = e->getCode();

        // e.g. USER_NOT_EXISTS -> UserNotExists
        let eName = \Phalcon\Text::camelize(map2Name[eCode]);

        var eClassName, exception;
        let eClassName = static::exceptionClassPrefix() . eName;

        let className = get_called_class();
        let code = new {className}(eCode);

        let exception = new {eClassName}(code->getMessage(), logger);

        exception->setCode(code->getCode());
        exception->setLevel(code->getLevel());
        exception->setMessage(e->getMessage());

        return exception;
    }

    public static function exceptionClassPrefix()
    {
        return __NAMESPACE__ . "\\Exception\\";
    }

    public function getMessage()
    {
        var detail, val;
        let detail = static::getByCode(this->getValue());
        if fetch val, detail["message"] {
            return val;
        } else {
            return "";
        }
    }

    public function getLevel()
    {
        var detail, val;
        let detail = static::getByCode(this->getValue());
        if fetch val, detail["level"] {
            return val;
        } else {
            return \Phalcon\Logger::DEBUG;
        }
    }

    public function getCode()
    {
        return this->getValue();
    }
}
