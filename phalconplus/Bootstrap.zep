namespace PhalconPlus;
use PhalconPlus\Enum\Sys as Sys;
use PhalconPlus\App\App as SuperApp;

final class Bootstrap
{
    // SuperApp: <\PhalconPlus\App\App>
    protected app = null {
        get
    };
    protected loadedFiles = [] {
        get
    };

    public function __construct(string! moduleDir, string env = "")
    {
        // 模块目录, PrimaryModule Dir
        Sys::init(moduleDir);
        let this->app = new SuperApp(this);
        // 加载Composer库
        // if likely is_file(Sys::getComposerAutoloadPath()) {
        //     require Sys::getComposerAutoloadPath();
        // }
        this->app->boot(this->initConf(), env);
    }

    protected function initConf() -> <\Phalcon\Config>
    {
        // 全局配置
        var globalConf,
            globalConfPath = Sys::getGlobalConfigPath();

        if unlikely !is_file(globalConfPath) {
            // Trigger a warning here
            error_log("PHP Notice:  PhalconPlus\\Bootstrap Global config file not exists: " . globalConfPath);
            let globalConf = new \Phalcon\Config([]);
        } else {
            let globalConf = new \Phalcon\Config(this->load(globalConfPath));
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

    public function load(var filePath)
    {
        if unlikely !is_string(filePath) {
            return false;
        }
        if unlikely !is_file(filePath) {
            throw new \PhalconPlus\Base\Exception("The file you try to load is not exists. file position: " . filePath);
        }
        var loader, config, superapp, di;
        var bootstrap, rootPath, fileRet;

        if fetch fileRet, this->loadedFiles[filePath] {
            return fileRet;
        }

        let
          rootPath = "rootPath",
          loader = "loader",
          config = "config",
          superapp = "superapp",
          bootstrap = "bootstrap",
          di = "di";

        let {rootPath} = Sys::getRootDir();
        let {loader} = new \Phalcon\Loader();
        let {bootstrap} = this;

        if this->app->isBooted() {
            let {superapp} = this->app;
            let {config} = this->app->getConfig();
            let {di} = this->app->getDI();
        }
        
        /* PHP 7.1 and later version, forbid dynamic calls to scope introspection functions
        extract(["rootPath": APP_ROOT_DIR,
                 "loader": new \Phalcon\Loader(),
                 "config": this->config,
                 "application": this->application,
                 "bootstrap": this,
                 "di": this->di
        ]);
        */

        let fileRet = require filePath;
        let this->loadedFiles[filePath] = fileRet;
        return fileRet;
    }

    public function terminate()
    {
        if session_status() == PHP_SESSION_ACTIVE { session_write_close(); }
        if !headers_sent() { session_id(""); }
        session_unset();

        let _SESSION = [], _POST = [],  _GET = [], _SERVER = [],
            _REQUEST = [], _COOKIE = [], _FILES = [];

        this->app->terminate();
        let this->app = null;
        let this->loadedFiles = [];
    }

    public function __destruct()
    {
        this->terminate();
    }
}
