//<?php
namespace PhalconPlus;
use PhalconPlus\Enum\Sys as Sys;
use PhalconPlus\Enum\RunMode as RunMode;

final class Bootstrap
{
    // 全局配置 <\Phalcon\Config>
    protected config = null;
    // 全局DI容器 <\Phalcon\Di>
    protected di = null {
        set, get
    };
    // 应用实例 <\Phalcon\Application> | <\Yar_Server>
    protected application = null;
    // 模块实例 <\PhalconPlus\Base\ModuleDef>
    protected primaryModuleDef = null;
    // 加载的模块实例列表 <\PhalconPlus\Base\ModuleDef>[]
    protected activeModules = [];
    // <\Phalcon\Debug>
    protected debug = null;
    // 默认运行环境
    // 其实框架定义了<\PhalconPlus\Enum\RunEnv>，但考虑再三，此处不能做枚举限制
    // Enum: ['dev', 'test', 'pre-production', 'production']
    protected env = \PhalconPlus\Enum\RunEnv::DEV;
    // 自动处理应用
    protected autoHandle = true {
        set, get
    };

    protected loadedFiles = [] {
        get
    };

    public function __construct(string! moduleDir, string env = "")
    {
        // 模块目录, PrimaryModule Dir
        Sys::init(moduleDir);
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

        // 如果不是生产环境，打开Debug
        // 这里我们假设生产环境的env值会以"product"开头
        if substr(PHP_SAPI, 0, 3) != "cli" && !\PhalconPlus\Enum\RunEnv::isInProd(this->env) {
            let this->debug = new \Phalcon\Debug();
            this->debug->listen();
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

        // 加载Composer库
        if likely is_file(Sys::getComposerAutoloadPath()) {
            require Sys::getComposerAutoloadPath();
        }
    }

    private function registerModule(<\PhalconPlus\Base\ModuleDef> moduleDef) -> <\PhalconPlus\Base\AbstractModule>
    {
        if unlikely isset(this->activeModules[moduleDef->getName()]) {
            return this->activeModules[moduleDef->getName()];
        }
        if unlikely is_null(this->di) {
            throw new \PhalconPlus\Base\Exception("DI doesn't load yet, failed to register module " . moduleDef->getName());
        }
        if unlikely is_null(this->config) {
            throw new \PhalconPlus\Base\Exception("Config doesn't initial yet, failed to register module " . moduleDef->getName());
        }
        // Load PrimaryModule-Related Config and Global-Script
        if moduleDef->getIsPrimary() {
            // 定义工作模式
            if !defined("APP_RUN_MODE") { define("APP_RUN_MODE", moduleDef->getMode(), false); }
            // 获取模块配置
            var moduleConf = moduleDef->getConfig();
            // 合并配置，Module配置优先级更高
            this->config->merge(moduleConf);
            // 装载全局服务初始化文件
            this->load(moduleDef->getRunMode()->getScriptPath());
        }
        // Implement a module from it's defintion
        var module = moduleDef->impl(this->di);

        // Register autoloaders and di-services
        module->registerAutoloaders();
        module->registerServices();

        // Maintain a list of loaded modules
        let this->activeModules[moduleDef->getName()] = module;
        return module;
    }

    public function initConf() -> <\PhalconPlus\Bootstrap>
    {
        // 全局配置
        var globalConfPath = Sys::getGlobalConfigPath();
        if unlikely !is_file(globalConfPath) {
            // throw new \Phalcon\Config\Exception("Global config file not exist, file position: " . globalConfPath);
            // Make a warning here
            error_log("PHP Notice:  PhalconPlus\\Bootstrap Global config file not exists: " . globalConfPath);
            let this->config = new \Phalcon\Config([]);
        } else {
            let this->config = new \Phalcon\Config(this->load(globalConfPath));
        }
        // 初始化主模块
        if empty this->primaryModuleDef { 
            let this->primaryModuleDef = new \PhalconPlus\Base\ModuleDef(this, APP_MODULE_DIR, true);
        }
        // 返回对象本身
        return this;
    }

    public function setApp(object app, boolean autoHandle = false) -> <\PhalconPlus\Bootstrap>
    {
        if likely empty(this->application) {
            if likely (app instanceof \Phalcon\Application) || (app instanceof \Yar_Server) {
                let this->application = app;
                let this->autoHandle = autoHandle;
            } else {
                throw new \PhalconPlus\Base\Exception("Application must be instance of phalcon\\appliction or yar_server");
            }
        }
        return this;
    }

    // return object | null
    public function getApp() -> object | null
    {
        if unlikely empty(this->application) {
            throw new \PhalconPlus\Base\Exception("Sorry, empty application in bootstrap");
        }
        return this->application;
    }

    // 统一入口，也可分别调用各模式入口
    public function exec()
    {
        // 初始化配置
        this->initConf();
        // 主执行方法入口
        var handleMethod = "exec";
        let handleMethod .= this->primaryModuleDef->getMapClassName();
        return call_user_func_array([this, handleMethod], func_get_args());
    }

    public function terminate()
    {
        if session_status() == PHP_SESSION_ACTIVE { session_write_close(); }
        if !headers_sent() { session_id(""); }

        session_unset();

        let _SESSION = [];
        let _POST = [];
        let _GET = [];
        let _SERVER = [];
        let _REQUEST = [];
        let _COOKIE = [];
        let _FILES = [];

        \Phalcon\Di::reset();
        let this->di = null;
        let this->config = null;
        let this->application = null;
        let this->loadedFiles = [];
        let this->primaryModuleDef = null;
        let this->activeModules = [];
    }

    public function __destruct()
    {
        this->terminate();
    }

    /**
     * @request a uri string (for \Phalcon\Mvc\Application) or Psr\Http\Message\Request
     */
    public function execModule(var request = null) -> <\PhalconPlus\Bootstrap> | <\Phalcon\Http\Response>
    {
        // 如果此方法被直接调用需要自己加载配置
        if empty this->config { this->initConf(); }
        // 初始化容器
        if empty this->di {
            let this->di = new \Phalcon\DI\FactoryDefault(); 
            // 把自己注入di
            this->di->setShared("bootstrap", this);
        }

        // Phalcon Mvc Application
        if unlikely empty(this->application) {
            let this->application = new \Phalcon\Mvc\Application();
        }
        this->application->setDI(this->di);

        // 注册模块
        this->registerModule(this->primaryModuleDef);
        // 如果不需要handle，则直接返回
        if !this->autoHandle { return this; }

        // Handle
        return this->application->handle(request);
    }

    public function execSrv() -> boolean | <\PhalconPlus\Bootstrap>
    {
        // 如果此方法被直接调用需要自己加载配置
        if empty this->config { this->initConf(); }
        // 初始化容器
        if empty this->di { 
            let this->di = new \Phalcon\DI\FactoryDefault(); 
            this->di->setShared("bootstrap", this);
        }

        // 注册模块
        this->registerModule(this->primaryModuleDef);

        var backendSrv = null;
        // Backend Server, Default is SimpleServer 
        if unlikely this->di->has("backendSrv") {
            let backendSrv = this->di->get("backendSrv");
            if ! (backendSrv instanceof \PhalconPlus\RPC\Server\AbstractServer) {
                throw new \PhalconPlus\Base\Exception("Service object(DI[\"backendSrv\"]) must be type of \\PhalconPlus\\RPC\\Server\\AbstractServer");
            }
        } else {
            let backendSrv = new \PhalconPlus\Base\SimpleServer(this->di);
            this->di->set("backendSrv", backendSrv);
        }

        // Yar Server
        if unlikely empty(this->application) {
            let this->application = new \Yar_Server(backendSrv);
        }

        // 如果不需要handle，则直接返回
        if !this->autoHandle { return this; }

        // Handle
        return this->application->handle();
    }

    public function execTask(array argv, <\Phalcon\DI\FactoryDefault> di = null)
    {
        // 如果此方法被直接调用需要自己加载配置
        if empty this->config { this->initConf(); }
        if empty this->di {
            if likely is_null(di) || ! (di instanceof \Phalcon\DI\FactoryDefault\CLI) {
                let this->di = new \Phalcon\DI\FactoryDefault\CLI();
            } else {
                let this->di = di;
            }
            this->di->setShared("bootstrap", this);
        }

        // Phalcon Cli Application
        if unlikely empty(this->application) {
            let this->application = new \Phalcon\CLI\Console();
        }
        this->application->setDI(this->di);

        // 注册模块
        this->registerModule(this->primaryModuleDef);

        // 如果不需要handle，则直接返回
        if !this->autoHandle { return this; }

        // Handle
        return this->application->handle(argv);
    }

    public function getPrimaryModuleDef() -> <\PhalconPlus\Base\ModuleDef>
    {
        return this->primaryModuleDef;
    }

    public function getPrimaryModule() -> <\PhalconPlus\Base\AbstractModule>
    {
        var name = this->primaryModuleDef->getName();
        if !isset(this->activeModules[name]) {
            throw new \PhalconPlus\Base\Exception("Module not exists: " . name);
        }
        return this->activeModules[name];
    }

    public function getModule(string! name) -> <\PhalconPlus\Base\AbstractModule>
    {
        if !isset(this->activeModules[name]) {
            throw new \PhalconPlus\Base\Exception("Module not exists: " . name);
        }
        return this->activeModules[name];
    }

    public function getModuleDef(string! name) -> <\PhalconPlus\Base\ModuleDef>
    {
        if !isset(this->activeModules[name]) {
            throw new \PhalconPlus\Base\Exception("Module not exists: " . name);
        }
        return this->activeModules[name]->getDef();
    }

    public function dependModule(string! moduleName) -> <\PhalconPlus\Base\AbstractModule>
    {
        var module, moduleDef, moduleDir, moduleConf;
        let moduleDir = Sys::getModuleDirByName(moduleName);
        let moduleDef = new \PhalconPlus\Base\ModuleDef(this, moduleDir);
        // 注册模块
        let module = this->registerModule(moduleDef);

        // 保留被依赖的模块的配置, 已经移除
        // this->di->set("moduleConfig", moduleDef->getConfig());
        // Use `$bootstrap->getModuleDef($moduleName)->getConfig()` instead

        // 参与合并的模块配置
        let moduleConf = new \Phalcon\Config(this->load(moduleDef->getConfigPath()));
        // 全局配置文件优先级高于被依赖的模块
        moduleConf->merge(this->config);
        this->setConfig(moduleConf);
        return module;
    }

    public function isDebug() -> boolean
    {
        return null != this->debug;
    }

    public function getDebug() -> <\Phalcon\Debug>
    {
        return this->debug;
    }

    public function getEnv() -> string
    {
        return this->env;
    }

    public function getConfig() -> <\Phalcon\Config>
    {
        return this->config;
    }

    // 传入的 Config 优先级更高
    public function setConfig(<\Phalcon\Config> config)
    {
        var globalConf;
        if ! this->di->has("config") {
            let globalConf = new \Phalcon\Config();
        } else {
            let globalConf = this->di->getConfig();
        }
        globalConf->merge(config);
        let this->config = globalConf;
        this->di->set("config", this->config);
        return this;
    }

    public function load(var filePath)
    {
        if unlikely !is_string(filePath) {
            return false;
        }

        if unlikely !is_file(filePath) {
            throw new \PhalconPlus\Base\Exception("The file you try to load is not exists. file position: " . filePath);
        }

        var loader, config, application, di;
        var bootstrap, rootPath, fileRet;

        if fetch fileRet, this->loadedFiles[filePath] {
            return fileRet;
        }

        let
          rootPath = "rootPath",
          loader = "loader",
          config = "config",
          application = "application",
          bootstrap = "bootstrap",
          di = "di";

        let {rootPath} = Sys::getRootDir();
        let {loader} = new \Phalcon\Loader();
        let {config} = this->config;
        let {application} = this->application;
        let {bootstrap} = this;
        let {di} = this->di;

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
}
