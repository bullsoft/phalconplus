namespace PhalconPlus\Enum;
use PhalconPlus\Enum\AbstractEnum;
use PhalconPlus\App\App as SuperApp;
use PhalconPlus\Facades\AbstractFacade;

class Facade extends AbstractEnum
{
    const ANNO      = "Annotations";
    const ASSETS    = "Assets";
    const BOOT      = "Bootstrap";
    const CONFIG    = "Config";
    const COOKIES   = "Cookies";
    const CRYPT     = "Crypt";
    const ESCAPER   = "Escaper";
    const EVENT_MGR = "EventsManager";
    const FILTER    = "Filter";
    const FLASH     = "Flash";

    const DISPATCHER      = "Dispatcher";
    const FLASH_SESSION   = "FlashSession";
    const MODELS_CACHE    = "ModelsCache";
    const MODELS_MGR      = "ModelsManager";
    const MODELS_METADATA = "ModelsMetadata";
    const SESSION_BAG     = "SessionBag";
    const SESSION  = "Session";
    const REQUEST  = "Request";
    const RESPONSE = "Response";
    const ROUTER   = "Router";
    const SECURITY = "Security";
    const SERVICE  = "Service";
    const TX_MGR   = "TransactionManager";

    const TAG  = "Tag";
    const LOG  = "Log";
    const URL  = "Url";
    const ACL  = "Acl";
    const APP  = "App";
    const DI   = "Di";
    const VIEW = "View";

    protected static facades = [
        "Annotations", "Assets", "Bootstrap", "Config", "Cookies",
        "Crypt", "Dispatcher", "Escaper", "EventsManager", "Filter",
        "Flash", "FlashSession", "Log", "ModelsCache", "ModelsManager",
        "ModelsMetadata", "Request", "Response", "Router", "Security", 
        "Service", "Session", "SessionBag", "Tag", "TransactionManager",
        "Url", "Acl", "App", "Di", "View"
    ];

    private static classPrefix = "\\PhalconPlus\\Facades\\";
    private static loaded = false;

    public static function register(<SuperApp> superApp, string prefix = "") -> boolean
    {
        if self::loaded === true {
            return true; 
        }
        AbstractFacade::setApp(superApp);

        var alias, facades;
        string className, classAlias;

        let facades = self::validValues();
        for alias in facades {
            let className = self::classPrefix.alias;
            let classAlias = prefix.alias;
            %{
                zend_class_entry *ce;
                ce = zephir_fetch_class(&className TSRMLS_CC);
                zend_register_class_alias_ex(Z_STRVAL(classAlias), Z_STRLEN(classAlias), ce);
            }%
        }
        let self::loaded = true;
        return true;
    }
}