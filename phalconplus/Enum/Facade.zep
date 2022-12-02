namespace PhalconPlus\Enum;
use PhalconPlus\Enum\AbstractEnum;
use PhalconPlus\Enum\Sys;
use PhalconPlus\App\App as SuperApp;
use PhalconPlus\Facades\AbstractFacade;

class Facade extends AbstractEnum
{
    const ANNO      = "Annotations";
    const ASSETS    = "Assets";
    const CONFIG    = "Config";
    const COOKIES   = "Cookies";
    const CRYPT     = "Crypt";
    const ESCAPER   = "Escaper";
    const EVENT_MGR = "EventsManager";
    const FILTER    = "Filter";
    const FLASH     = "Flash";

    const APP_MODULE      = "AppModule";
    const APP_ENGINE      = "AppEngine";
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
    const REDIS    = "Redis";

    const TAG  = "Tag";
    const LOG  = "Log";
    const URL  = "Url";
    const ACL  = "Acl";
    const APP  = "App";
    const DI   = "Di";
    const VIEW = "View";
    const USER = "User";

    protected static facades = [
        "Annotations", "Assets", "Config", "Cookies", "View",
        "Crypt", "Dispatcher", "Escaper", "EventsManager", "Filter",
        "Flash", "FlashSession", "Log", "ModelsCache", "ModelsManager",
        "ModelsMetadata", "Request", "Response", "Router", "Security", 
        "Service", "Session", "SessionBag", "Tag", "TransactionManager",
        "Url", "Acl", "App", "Di", "AppEngine", "Redis", "User", "AppModule"
    ];

    private static classPrefix = "PhalconPlus\\Facades\\";
    private static loaded = false;

    public static function register(<SuperApp> superApp) -> boolean
    {
        if self::loaded === true {
            return true; 
        }
        AbstractFacade::setApp(superApp);

        var alias, facades;
        string className;

        let facades = self::validValues();
        for alias in facades {
            let className = self::classPrefix.alias;
            // With Ph prefix - will remove in future
            Sys::classAlias(className, "Ph\\".alias);
            // With Plus prefix
            Sys::classAlias(className, "Plus\\".alias);
        }
        let self::loaded = true;
        return true;
    }
}