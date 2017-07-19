//<?php
namespace PhalconPlus;

final class Bootstrap
{
    // 全局配置文件
    protected config;
    // 全局DI容器
    protected di;
    // 应用实例
    protected application;

    // 自动加载器, 不需要了...
    // protected loader;

    // 模块属性
    protected module = [
        "classPath" : "",
        "className" : "",
        "mode"      : ""
    ];
    // 运行模式
    protected modeMap = [
        "Web"     : "Module",
        "Cli"     : "Task",
        "Srv"     : "Srv",
        "Micro"   : "Micro"
    ];

    // 默认运行环境, Enum: ['dev', 'test', 'pre-production', 'production']
    protected env = "dev";

    // 定义类常量
    const COMMON_DIR_NAME      = "common";
    const COMMON_CONF_DIR_NAME = "config";
    const COMMON_LOAD_DIR_NAME = "load";
    const ROOT_PUB_DIR_NAME    = "public";
    const MODULE_APP_DIR_NAME  = "app";

    // 约定
    const DS = "/";
    const PHP_EXT = ".php";
    const ENV_NAME = "phalconplus.env";

    public function __construct(string! modulePath)
    {
        // 模块目录
        if !is_dir(modulePath) {
            throw new \Exception("Module directory not exists or not a dir, file positon: " . modulePath);
        }

        // 获取并初始化运行环境
        var env;
        let env = get_cfg_var(self::ENV_NAME);
        if !empty(env) {
            let this->env = env;
        }
        // 如果不是生产环境，打开Debug
        if substr(PHP_SAPI, 0, 3) != "cli" && substr(this->env, 0, 7) != "product"{
            var debug;
            let debug = new \Phalcon\Debug();
            debug->listen();
        }

        // 定义全局常量
        define("APP_ENV", this->env, true);
        define("APP_MODULE_DIR", rtrim(modulePath, "/") . "/", true);
        define("APP_ROOT_DIR", rtrim(dirname(modulePath), "/") . "/", true);
        define("APP_ROOT_COMMON_DIR", APP_ROOT_DIR . self::COMMON_DIR_NAME . "/", true);
        define("APP_ROOT_COMMON_CONF_DIR", APP_ROOT_COMMON_DIR . self::COMMON_CONF_DIR_NAME . "/", true);
        define("APP_ROOT_COMMON_LOAD_DIR", APP_ROOT_COMMON_DIR . self::COMMON_LOAD_DIR_NAME . "/", true);
    }

    private function setModule(array module)
    {
        var diff = [];
        let diff = array_diff_key(this->module, module);
        if !empty diff {
            throw new \Exception("Module is not a legal module, details: " .  json_encode(module));
        }
        let this->module = module;
    }

    public function initConf()
    {
        var globalConfPath, moduleConfPath;
        var moduleConf;

        // 全局配置
        let globalConfPath = APP_ROOT_COMMON_CONF_DIR . "config" . self::PHP_EXT;
        if !is_file(globalConfPath) {
            throw new \Phalcon\Config\Exception("Global config file not exist, file position: " . globalConfPath);
        }
        let this->config = new \Phalcon\Config(this->load(globalConfPath));

        // 模块配置, 如果找不到"app/config/{APP_ENV}.php"，则去找"app/config/config.php"
        let moduleConfPath = APP_MODULE_DIR . "app/config/" . APP_ENV . self::PHP_EXT;
        if !is_file(moduleConfPath) {
            let moduleConfPath = APP_MODULE_DIR . "app/config/config"  . self::PHP_EXT;
            if !is_file(moduleConfPath) {
                throw new \Phalcon\Config\Exception("Module config file not exist, file position: " . moduleConfPath);
            }
        }

        let moduleConf  = new \Phalcon\Config(this->load(moduleConfPath));

        // 初始化模块三要素
        var module = [];
        let module["mode"] = ucfirst(strtolower(moduleConf->application->mode));
        let module["className"] = moduleConf->application->ns . this->modeMap[module["mode"]];
        let module["classPath"] = APP_MODULE_DIR . "app/" . this->modeMap[$module["mode"]] . self::PHP_EXT;

        // 定义工作模式
        define("APP_RUN_MODE", module["mode"], true);

        this->setModule(module);

        // 合并配置，Module配置优先级更高
        this->config->merge(moduleConf);
    }

    public function exec()
    {
        var handleMethod;
        this->initConf();
        let handleMethod = "exec" . this->modeMap[APP_RUN_MODE];
        var params = [];
        let params = func_get_args();
        return call_user_func_array([this, handleMethod], params);
    }

    public function execModule(var uri = null, bool needHandle = true)
    {
        var moduleClass, module;
        // 如果不需要handle，需要自己加载配置
        if !needHandle {
            this->initConf();
        }
        // 应用初始化
        // let this->loader = new \Phalcon\Loader();
        let this->di = new \Phalcon\DI\FactoryDefault();
        let this->application = new \Phalcon\Mvc\Application();
        this->application->setDI(this->di);

        // 加载Web模式依赖
        this->load(APP_ROOT_COMMON_LOAD_DIR . "default-web.php");
        // 把自己注入di
        this->di->setShared("bootstrap", this);
        // 包含模块化类
        require this->module["classPath"];
        // 模块初始化类
        let moduleClass = this->module["className"];
        // 实例化该类
        let module = new {moduleClass}(this->di);
        // 如果不需要handle，则直接返回
        if !needHandle {
            return true;
        }

        // 执行
        try {
            echo this->application->handle(uri)->getContent();
        } catch \Phalcon\Mvc\Application\Exception {
            var router, newUri;
            let router = this->di->get("router");
            let newUri = "/" . router->getDefaultModule() . router->getRewriteUri();
            echo this->application->handle(newUri)->getContent();
        }
    }

    public function execSrv(bool needHandle = true)
    {
        var backendSrv = null;
        var moduleClass, moduleObj;

        if !needHandle {
            this->initConf();
        }
        // no need to get `loader` here
        // let this->loader = new \Phalcon\Loader();
        let this->di = new \Phalcon\DI\FactoryDefault();

        this->di->setShared("bootstrap", this);
        this->load(APP_ROOT_COMMON_LOAD_DIR . "default-web.php");

        require this->module["classPath"];
        let moduleClass = this->module["className"];
        let moduleObj = new {moduleClass}(this->di);

        if !needHandle {
            return true;
        }

        let backendSrv = new \PhalconPlus\Base\BackendServer(this->di);
        let this->application = new \Yar_Server($backendSrv);

        this->application->handle();
    }

    public function execTask(array argv, <\Phalcon\DI\FactoryDefault> di = null, var needHandle = true)
    {
        var moduleClass, module;

        this->initConf();

        // no need to get `loader` here
        // let this->loader = new \Phalcon\Loader();

        if is_null(di) || ! (di instanceof \Phalcon\DI\FactoryDefault\CLI) {
            let this->di = new \Phalcon\DI\FactoryDefault\CLI();
        } else {
            let this->di = di;
        }

        let this->application = new \Phalcon\CLI\Console();
        this->application->setDI(this->di);

        this->load(APP_ROOT_COMMON_LOAD_DIR . "default-cli.php");
        this->di->setShared("bootstrap", this);

        // Load module
        require this->module["classPath"];
        let moduleClass = this->module["className"];
        let module = new {moduleClass}(this->di);

        if !needHandle {
            return true;
        }

        return this->application->handle(argv);
    }

    public function dependModule(string! moduleName)
    {
        var moduleConfPath, moduleConf, moduleClassName, moduleClassPath, moduleRunMode;
        let moduleConfPath = APP_ROOT_DIR . moduleName . "/app/config/" . APP_ENV . self::PHP_EXT;
        if !is_file(moduleConfPath) {
            let moduleConfPath = APP_ROOT_DIR . moduleName . "/app/config/config"  . self::PHP_EXT;
            if !is_file(moduleConfPath) {
                throw new \Phalcon\Config\Exception("Module config file not exist, file position: " . moduleConfPath);
            }
        }
        var reservedModuleConf;
        let moduleConf = new \Phalcon\Config(this->load(moduleConfPath));
        let reservedModuleConf = new \Phalcon\Config(this->load(moduleConfPath));

        let moduleRunMode = moduleConf->application->mode;

        // 获取模块类名
        let moduleClassName = moduleConf->application->ns . this->modeMap[moduleRunMode];
        let moduleClassPath = APP_ROOT_DIR . moduleName . "/app/" . this->modeMap[moduleRunMode] . self::PHP_EXT;
        if !is_file(moduleClassPath) {
            throw new \Exception("Module init file not exists, file position: " . moduleClassPath);
        }

        // 保留被依赖的模块的配置
        this->di->set("moduleConfig", reservedModuleConf);
        // 全局配置文件优先级高于被依赖的模块
        moduleConf->merge(this->config);
        this->setConfig(moduleConf);

        require moduleClassPath;
        return new {moduleClassName}(this->di);
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

    public function getDI() -> <\Phalcon\DI>
    {
        return this->di;
    }

    public function load(var filePath)
    {
        if !is_file(filePath) {
            throw new \Exception("The file you try to load is not exists. file position: " . filePath);
        }
        var rootPath, loader, config, application, bootstrap, di;

        let
          rootPath = "rootPath",
          loader = "loader",
          config = "config",
          application = "application",
          bootstrap = "bootstrap",
          di = "di";

        let {rootPath} = APP_ROOT_DIR;
        let {loader} = new \Phalcon\Loader();
        let {config} = this->config;
        let {application} = this->application;
        let {bootstrap} = this;
        let {di} = this->di;

        /*
        extract(["rootPath": APP_ROOT_DIR,
                 "loader": new \Phalcon\Loader(),
                 "config": this->config,
                 "application": this->application,
                 "bootstrap": this,
                 "di": this->di
        ]);
        */
        return require filePath;
    }
}
