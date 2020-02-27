<?php

namespace PhalconPlus\Enum;

use PhalconPlus\Enum\AbstractEnum;
use PhalconPlus\App\App as SuperApp;
use PhalconPlus\Facades\AbstractFacade;

class Facade extends AbstractEnum
{

    const ANNO = 'Annotations';


    const ASSETS = 'Assets';


    const BOOT = 'Bootstrap';


    const CONFIG = 'Config';


    const COOKIES = 'Cookies';


    const CRYPT = 'Crypt';


    const ESCAPER = 'Escaper';


    const EVENT_MGR = 'EventsManager';


    const FILTER = 'Filter';


    const FLASH = 'Flash';


    const DISPATCHER = 'Dispatcher';


    const FLASH_SESSION = 'FlashSession';


    const MODELS_CACHE = 'ModelsCache';


    const MODELS_MGR = 'ModelsManager';


    const MODELS_METADATA = 'ModelsMetadata';


    const SESSION_BAG = 'SessionBag';


    const SESSION = 'Session';


    const REQUEST = 'Request';


    const RESPONSE = 'Response';


    const ROUTER = 'Router';


    const SECURITY = 'Security';


    const SERVICE = 'Service';


    const TX_MGR = 'TransactionManager';


    const TAG = 'Tag';


    const LOG = 'Log';


    const URL = 'Url';


    const ACL = 'Acl';


    const APP = 'App';


    const DI = 'Di';


    const VIEW = 'View';


    static protected $facades = array('Annotations', 'Assets', 'Bootstrap', 'Config', 'Cookies', 'Crypt', 'Dispatcher', 'Escaper', 'EventsManager', 'Filter', 'Flash', 'FlashSession', 'Log', 'ModelsCache', 'ModelsManager', 'ModelsMetadata', 'Request', 'Response', 'Router', 'Security', 'Service', 'Session', 'SessionBag', 'Tag', 'TransactionManager', 'Url', 'Acl', 'App', 'Di', 'View');


    static private $classPrefix = '\\\\PhalconPlus\\\\Facades\\\\';


    static private $loaded = false;


    /**
     * @param \PhalconPlus\App\App $superApp
     * @param string $prefix
     * @return bool
     */
    public static function register(\PhalconPlus\App\App $superApp, string $prefix = ''): bool
    {
    }

}
