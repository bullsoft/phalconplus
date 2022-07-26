namespace PhalconPlus;
use PhalconPlus\Enum\Sys as Sys;
use PhalconPlus\App\App as SuperApp;
use Phalcon\Config\Config;

final class Bootstrap
{
    // SuperApp: <\PhalconPlus\App\App>
    protected app = null;

    public function __construct(string! moduleDir, string env = "", string runMode = "")
    {
        // PrimaryModule Dir
        Sys::init(moduleDir);
        var config = this->initConf();
        let this->app = (new SuperApp(config))->boot(env, runMode);
        // Try to load composer-autoloader
        try {
            Sys::load(Sys::getComposerAutoloadPath());
        } catch \Exception {
            // nothing here...
        }
    }

    protected function initConf() -> <Config>
    {
        // Initial global config here
        var globalConf, e,
            globalConfPath = Sys::getGlobalConfigPath();
        
        try {
            let globalConf = new Config(Sys::load(globalConfPath));
        } catch \Exception, e {
            let globalConf = new Config([]);
            trigger_error("Global config file not exists: " . e->getMessage());
        }
        return globalConf;
    }

    public function getApp() -> <SuperApp>
    {
        return this->app;
    }

    public function app() -> <SuperApp>
    {
        return this->app;
    }

    public function terminate()
    {
        let this->app = null;
    }
}
