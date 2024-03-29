namespace PhalconPlus\App;
use Phalcon\Application\AbstractApplication as BaseApplication;
use PhalconPlus\Enum\Sys as Sys;
use PhalconPlus\App\Module\ModuleDef;
use Phalcon\Di\DiInterface;
use Phalcon\Di\Di;
use PhalconPlus\App\Module\AbstractModule;
use PhalconPlus\Enum\RunEnv;
use Phalcon\Config\Config;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\Events\ManagerInterface;
use Phalcon\Autoload\Loader;

final class App extends BaseApplication
{
    // 默认运行环境
    // 其实框架定义了<\PhalconPlus\Enum\RunEnv>，但考虑再三，此处不能做枚举限制
    // Enum: ['dev', 'test', 'pre-production', 'production']
    protected env = RunEnv::DEV;
    protected booted = false;
    // 全局配置 <Config>
    protected config = null { get };
    // 处理请求次数
    protected requestNumber = 0;
    // 需要手动关闭的服务 []callable，一般是有状态服务，如Mysql、Redis等
    protected finalizers = [];
   
    public function __construct(<Config> config)
    {
        // 全局配置
        let this->config = config;
        Sys::initApp(this);
    }

    public function boot(string env = "", string runMode = "") -> <App>
    {
        // 获取并初始化运行环境
        if likely empty env {
            // 获取php.ini中设置的env    
            var sysEnv = trim(get_cfg_var(Sys::ENV_NAME));
            // 这里不能强约束env的值为枚举中的一个
            // 你可能会有非常多的环境，只要env值和配置文件名能对应上就行
            if !empty sysEnv { let this->env = sysEnv; }
        } else {
            let this->env = env;
        }

        // Define global constants
        define("APP_ENV",     this->env, false); // 为了兼容, 同下
        define("APP_RUN_ENV", this->env, false);
        define("APP_ROOT_DIR",   Sys::getRootDir(), false);
        define("APP_MODULE_DIR", Sys::getPrimaryModuleDir(),      false); // 为了兼容, 同下
        define("APP_PRI_MODULE_DIR",  Sys::getPrimaryModuleDir(), false);
        define("APP_ROOT_COMMON_DIR", Sys::getCommonDir(),        false);
        define("APP_ROOT_COMMON_LOAD_DIR", Sys::getGlobalLoadDir(),   false);
        define("APP_ROOT_COMMON_CONF_DIR", Sys::getGlobalConfigDir(), false);

        return this->bootPrimaryModule(runMode);
    }

    private function bootPrimaryModule(string runMode = "") -> <App>
    {
        // 初始化主模块
        var primaryModuleDef;
        let primaryModuleDef = new ModuleDef(this, Sys::getPrimaryModuleDir(), true, runMode);
        if this->container == null {
            this->setDI(primaryModuleDef->newDI());
            this->getDI()->setShared("superApp", this);
            this->getDI()->setShared("config", this->config);
            this->getDI()->setShared("loader", new Loader());
        }
        // App启动成功
        let this->booted = true;
        // 注册主模块
        var module = this->registerModule(primaryModuleDef);
        return this;
    }

    private function registerModule(<ModuleDef> moduleDef) -> <AbstractModule>
    {
        if unlikely isset(this->modules[moduleDef->getName()]) {
            return this->modules[moduleDef->getName()];
        }
        if unlikely is_null(this->container) {
            throw new BaseException("DI doesn't load yet, failed to register module " . moduleDef->getName());
        }
        if unlikely is_null(this->config) {
            throw new BaseException("Config doesn't initial yet, failed to register module " . moduleDef->getName());
        }
        // Load PrimaryModule-Related Config and Global-Script
        if moduleDef->isPrimary() {
            // 定义工作模式
            if !defined("APP_RUN_MODE") { define("APP_RUN_MODE", moduleDef->getMode(), false); }
            // 获取模块配置
            var moduleConf = moduleDef->getConfig();
            // 合并配置，Module配置优先级更高
            this->config->merge(moduleConf);
        }
        // Checkout a module instance from it's definition
        var module = moduleDef->checkout();
        if module->isPrimary() {
            let this->defaultModule = module;
        }
        // Maintain a HashMap of loaded modules
        let this->modules[moduleDef->getName()] = module;
        return module;
    }

    // import exportable module
    public function import(string! moduleName) -> <AbstractModule>
    {
        return this->dependModule(moduleName, false);
    }

    public function dependModule(string! moduleName, bool force = true) -> <AbstractModule>
    {
        let moduleName = trim(moduleName);
        if unlikely isset(this->modules[moduleName]) {
            return this->modules[moduleName];
        }
        var moduleDef;
        let moduleDef = new ModuleDef(this, Sys::getModuleDirByName(moduleName));
        if force === false {
            if moduleDef->config()->path("application.exportable", false) == false {
                throw new BaseException(moduleName . " can't be imported as external library.");
            }
        }

        // 参与合并的模块配置
        var moduleConf = null,    
            arrayConf = Sys::load(moduleDef->getConfigPath()),
            // 注册模块
            module = this->registerModule(moduleDef);

        let moduleConf = new Config(arrayConf);

        // 全局配置文件优先级高于被依赖的模块
        moduleConf->merge(this->config);
        this->setConfig(moduleConf);
        return module;
    }

    // 传入的 Config 优先级更高
    public function setConfig(<Config> config) -> <App>
    {
        if is_null(this->config) {
            let this->config = new Config();
        }
        this->config->merge(config);
        return this;
    }

    public function isBooted() -> boolean
    {
        return this->booted === true;
    }

    public function getEnv() -> string
    {
        return this->env;
    }

    public function setEnv(string env) -> <App>
    {
        let this->env = env;
        return this;
    }

    public function handle()
    {
        let this->requestNumber = this->requestNumber + 1;
        // If app booted is false, reboot it again here.
        if false == this->booted {
            this->bootPrimaryModule();
        }

        var eventsManager = null, 
            response = null, 
            params = func_get_args();

        let eventsManager = <ManagerInterface> this->eventsManager;
        if typeof eventsManager == "object" {
            if eventsManager->fire("superapp:beforeExecModule", this, [this->defaultModule, params]) === false {
                // 
            }
        }
        // Exec primary module, and get response
        let response = this->defaultModule->exec(params);

        if typeof eventsManager == "object" {
            if eventsManager->fire("superapp:afterExecModule", this, [this->defaultModule, response]) === false {
                // 
            }
        }
        return response;
    }

    public function terminate(bool deeply = true)
    {
        // Close SESSION here
        if session_status() == PHP_SESSION_ACTIVE { 
            session_write_close(); 
        }

        // Empty session-id
        if !headers_sent() { session_id(""); }

        // Reset global variables
        let _SESSION = [], _POST = [], 
            _GET = [], _SERVER = [],
            _REQUEST = [], _COOKIE = [], _FILES = [];

        let this->modules = [];
        let this->defaultModule = null;
        let this->booted = false;

        var finalizer;
        for finalizer in this->finalizers {
            {finalizer}();
        }
        let this->finalizers = [];
        if deeply === true {
            Di::reset();
            let this->container = null;
        }
    }

    public function defer(callable handler)
    {
        let this->finalizers[] = handler;
        return this;
    }

    public function getRequestNumber() -> int
    {
        return this->requestNumber;
    }

    public function getDefaultModuleDef() -> <ModuleDef>
    {
        return this->defaultModule->def();
    }

    public function getPrimaryModuleDef() -> <ModuleDef>
    {
        return this->defaultModule->def();
    }

    public function setDefaultModule(string defaultModule) -> <BaseApplication>
    {
        // nothing here...
        return this;
    }
    
    public function getDefaultModule() -> string
    {
        // Constraited by parent class, have to return module-name as string
        return this->defaultModule->getName();
    }

    public function getPrimaryModule() -> <AbstractModule>
    {
        var name = this->defaultModule->getName();
        if !isset(this->modules[name]) {
            throw new BaseException("Module not exists: " . name);
        }
        return this->modules[name];
    }

    public function getModule(string! name = "") -> <AbstractModule>
    {
        if name === "" {
            return this->defaultModule;
        }
        if !isset(this->modules[name]) {
            throw new BaseException("Module not exists: " . name);
        }
        return this->modules[name];
    }

    public function getModuleDef(string! name = "") -> <ModuleDef>
    {
        if name === "" {
            return this->defaultModule->def();
        }
        if !isset(this->modules[name]) {
            throw new BaseException("Module not exists: " . name);
        }
        return this->modules[name]->def();
    }

    public function config() -> <Config>
    {
        return this->config;
    }

    public function di() -> <Di>
    {
        return this->container;
    }

    public function __call(string method, array params)
    {
        var dependencyInjector = null;
        
        // If App not booted, return null
        if ! this->isBooted() {
            return null;
        }

        let dependencyInjector = <DiInterface> this->container;
        if dependencyInjector->has(method) {
            return dependencyInjector->get(method, params);
        }
        return null;
    }
}