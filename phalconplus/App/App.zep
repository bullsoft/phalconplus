namespace PhalconPlus\App;
use Phalcon\Application as BaseApplication;
use PhalconPlus\Enum\Sys as Sys;
use PhalconPlus\App\Module\ModuleDef;
use Phalcon\DiInterface;
use Phalcon\Di;
use PhalconPlus\App\Module\AbstractModule;
use PhalconPlus\Enum\RunEnv;
use PhalconPlus\Enum\Facade;
use Phalcon\Config;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\Events\ManagerInterface;

final class App extends BaseApplication
{
    // <\Phalcon\Debug>
    protected debug = null;
    // 默认运行环境
    // 其实框架定义了<\PhalconPlus\Enum\RunEnv>，但考虑再三，此处不能做枚举限制
    // Enum: ['dev', 'test', 'pre-production', 'production']
    protected env = RunEnv::DEV;
    protected booted = false;
    // 全局配置 <\Phalcon\Config>
    protected config = null { get };
   
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

        // 定义全局常量
        define("APP_ENV", this->env, false); // 为了兼容, 同下
        define("APP_RUN_ENV", this->env, false);
        define("APP_ROOT_DIR", Sys::getRootDir(), false);
        define("APP_MODULE_DIR", Sys::getPrimaryModuleDir(), false); // 为了兼容, 同下
        define("APP_PRI_MODULE_DIR", Sys::getPrimaryModuleDir(), false);
        define("APP_ROOT_COMMON_DIR", Sys::getCommonDir(), false);
        define("APP_ROOT_COMMON_LOAD_DIR", Sys::getGlobalLoadDir(), false);
        define("APP_ROOT_COMMON_CONF_DIR", Sys::getGlobalConfigDir(), false);

        // 加载Facacdes
        Facade::register(this, "\\Ph\\");

        return this->bootPrimaryModule(runMode);
    }

    private function bootPrimaryModule(string runMode = "") -> <App>
    {
        // 初始化主模块
        var primaryModuleDef;
        let primaryModuleDef = new ModuleDef(this, Sys::getPrimaryModuleDir(), true, runMode);
        this->setDI(primaryModuleDef->newDI());
        this->getDI()->setShared("superApp", this);
        this->getDI()->setShared("config", this->config);
        this->getDI()->setShared("loader", new \Phalcon\Loader());
        // App启动成功
        let this->booted = true;
        // 注册主模块
        var module = this->registerModule(primaryModuleDef);
        if module->isWeb() {
            if !RunEnv::isInProd(this->env) {
                let this->debug = new \Phalcon\Debug();
                this->debug->listen();
            }
        }
        return this;
    }

    private function registerModule(<ModuleDef> moduleDef) -> <AbstractModule>
    {
        if unlikely isset(this->_modules[moduleDef->getName()]) {
            return this->_modules[moduleDef->getName()];
        }
        if unlikely is_null(this->_dependencyInjector) {
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
        // checkout a module instance from it's defintion
        var module = moduleDef->checkout();
        if module->isPrimary() {
            let this->_defaultModule = module;
        }
        
        // Maintain a HashMap of loaded modules
        let this->_modules[moduleDef->getName()] = module;
        return module;
    }

    public function dependModule(string! moduleName) -> <AbstractModule>
    {
        var module, moduleDef, moduleDir, moduleConf;
        let moduleDir = Sys::getModuleDirByName(moduleName);
        let moduleDef = new ModuleDef(this, moduleDir);
        // 注册模块
        let module = this->registerModule(moduleDef);
        // 参与合并的模块配置
        var tmp = Sys::load(moduleDef->getConfigPath());
        let moduleConf = new Config(tmp);
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
        // this->getDI()->setShared("config", this->config);
        return this;
    }

    public function isDebug() -> boolean
    {
        return null !== this->debug;
    }

    public function isBooted() -> boolean
    {
        return this->booted === true;
    }

    public function getDebug() -> <\Phalcon\Debug>
    {
        return this->debug;
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
        if false == this->booted {
            this->bootPrimaryModule();
        }

        var eventsManager, response, params = func_get_args();

        let eventsManager = <ManagerInterface> this->_eventsManager;
        if typeof eventsManager == "object" {
            if eventsManager->fire("superapp:beforeExecModule", this, [this->_defaultModule, params]) === false {
                // 
                // error_log(var_export(params, true));
            }
        }

        let response = this->_defaultModule->exec(params);

        if typeof eventsManager == "object" {
            if eventsManager->fire("superapp:afterExecModule", this, [this->_defaultModule, response]) === false {
                // 
                // error_log(var_export(response, true));
            }
        }
        
        return response;
    }

    public function terminate()
    {
        if session_status() == PHP_SESSION_ACTIVE { 
            session_write_close(); 
        }

        // empty session id
        if !headers_sent() { session_id(""); }

        // reset global variables
        let _SESSION = [], _POST = [],  _GET = [], _SERVER = [],
            _REQUEST = [], _COOKIE = [], _FILES = [];

        let this->_modules = [];
        let this->_defaultModule = null;
        let this->booted = false;
        Di::reset();

        let this->_dependencyInjector = null;
        // let this->config = null;
        
    }

    public function getDefaultModuleDef() -> <ModuleDef>
    {
        return this->_defaultModule->def();
    }

    public function getPrimaryModuleDef() -> <ModuleDef>
    {
        return this->_defaultModule->def();
    }

    public function setDefaultModule(string defaultModule) -> <BaseApplication>
    {
        // 
        return this;
    }
    
    public function getDefaultModule() -> string
    {
        return this->_defaultModule->getName();
    }

    public function getPrimaryModule() -> <AbstractModule>
    {
        var name = this->_defaultModule->getName();
        if !isset(this->_modules[name]) {
            throw new BaseException("Module not exists: " . name);
        }
        return this->_modules[name];
    }

    public function getModule(string! name = "") -> <AbstractModule>
    {
        if name === "" {
            return this->_defaultModule;
        }
        if !isset(this->_modules[name]) {
            throw new BaseException("Module not exists: " . name);
        }
        return this->_modules[name];
    }

    public function getModuleDef(string! name = "") -> <ModuleDef>
    {
        if name === "" {
            return this->_defaultModule->def();
        }
        if !isset(this->_modules[name]) {
            throw new BaseException("Module not exists: " . name);
        }
        return this->_modules[name]->def();
    }

    public function config() -> <Config>
    {
        return this->config;
    }

    public function di() -> <Di>
    {
        return this->_dependencyInjector;
    }

    public function __call(string method, array params)
    {
        var dependencyInjector, service;
        if ! this->isBooted() {
            return null;
        }
        let dependencyInjector = <DiInterface> this->_dependencyInjector;
        if dependencyInjector->has(method) {
            let service = dependencyInjector->get(method, params);
            return service;
        }
        return null;
    }
}