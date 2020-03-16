namespace PhalconPlus;
use PhalconPlus\Enum\Sys as Sys;
use PhalconPlus\App\App as SuperApp;
use Phalcon\Config;

final class Bootstrap
{
    // SuperApp: <\PhalconPlus\App\App>
    protected app = null;

    public function __construct(string! moduleDir, string env = "", string runMode = "")
    {
        // 模块目录, PrimaryModule Dir
        Sys::init(moduleDir);
        var config = this->initConf();
        let this->app = (new SuperApp(config))->boot(env, runMode);
        // 加载Composer库
        Sys::load(Sys::getComposerAutoloadPath());
    }

    protected function initConf() -> <Config>
    {
        // 全局配置
        var globalConf,
            globalConfPath = Sys::getGlobalConfigPath();

        if unlikely !is_file(globalConfPath) {
            // Trigger a warning here
            error_log("PHP Notice:  PhalconPlus\\Bootstrap Global config file not exists: " . globalConfPath);
            let globalConf = new Config([]);
        } else {
            let globalConf = new Config(Sys::load(globalConfPath));
        }
        return globalConf;
    }

    public function exec()
    {
        return call_user_func_array(
            [this->app, "handle"], 
            func_get_args()
        );
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
