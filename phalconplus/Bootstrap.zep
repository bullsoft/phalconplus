//<?php
namespace PhalconPlus;

final class Bootstrap
{
    // 全局配置文件
    protected config;
    // 全局DI容器
    protected di;
    protected application;
    // 自动加载器
    protected loader;
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
    // 运行环境
    protected env = "dev";

    // 定义类常量
    const COMMON_DIR_NAME      = "common";
    const COMMON_CONF_DIR_NAME = "config";
    const COMMON_LOAD_DIR_NAME = "load";
    const ROOT_PUB_DIR_NAME    = "public";
    const MODULE_APP_DIR_NAME  = "app";

    public function __construct(string! modulePath)
    {
        // 模块目录
        if !is_dir(modulePath) {
            throw new \Exception("Module directory not exists or not a dir, file positon: " . modulePath);
        }
        // 获取并初始化运行环境
        var env;
        let env = get_cfg_var("phalconplus.env");
        if !empty(env) {
            let this->env = env;
        }
        // 如果不是生产环境，打开Debug
        if this->env != "product" {
            var debug;
            let debug = new \Phalcon\Debug();
            debug->listen();
        }

        // 定义全局常量
        define("APP_ENV", this->env, true);
        define("APP_MODULE_DIR", rtrim(modulePath, "/") . "/", true);
        define("APP_ROOT_DIR", rtrim(dirname(modulePath), "/") . "/", true);
        define("APP_ROOT_PUB_DIR", APP_ROOT_DIR . self::ROOT_PUB_DIR_NAME . "/", true);
        define("APP_ROOT_COMMON_DIR", APP_ROOT_DIR . self::COMMON_DIR_NAME . "/", true);
        define("APP_ROOT_COMMON_CONF_DIR", APP_ROOT_COMMON_DIR . self::COMMON_CONF_DIR_NAME . "/", true);
        define("APP_ROOT_COMMON_LOAD_DIR", APP_ROOT_COMMON_DIR . self::COMMON_LOAD_DIR_NAME . "/", true);
    }

    private function setModule(array module)
    {
        var diff = [];
        let diff = array_diff_key(this->module, module);
        if !empty diff {
            throw new \Exception("Module is is not a legal module");
        }
        let this->module = module;
    }

    private function initConf()
    {
        var globalConfPath, moduleConfPath;
        var moduleConf;

        // 全局配置
        let globalConfPath = APP_ROOT_COMMON_CONF_DIR . "config.php";
        if !is_file(globalConfPath) {
            throw new \Phalcon\Config\Exception("Global config file not exist, file position: " . globalConfPath);
        }
        let this->config = new \Phalcon\Config(this->load(globalConfPath));
        
        // 模块配置
        let moduleConfPath = APP_MODULE_DIR . "/app/config/" . APP_ENV . ".php";
        if !is_file(moduleConfPath) {
            throw new \Phalcon\Config\Exception("Module config file not exist, file position: " . moduleConfPath);
        }
        let moduleConf  = new \Phalcon\Config(this->load(moduleConfPath));
        
        // 初始化模块三要素
        var module = [];
        let module["mode"] = ucfirst(strtolower(moduleConf->application->mode));
        let module["className"] = moduleConf->application->ns . this->modeMap[module["mode"]];
        let module["classPath"] = APP_MODULE_DIR . "app/" . this->modeMap[$module["mode"]] . ".php";

        // 定义工作模式
        define("APP_RUN_MODE", module["mode"], true);

        this->setModule(module);

        // 合并配置，Module配置优先级更高
        this->config->merge(moduleConf);
    }

    public function exec(var argv = null)
    {
        var handleMethod;
        this->initConf();
        let handleMethod = "exec" . this->modeMap[APP_RUN_MODE];
        this->{handleMethod}(argv);
    }
    
    public function execModule(var uri = null)
    {
        var moduleClass, module;
        // 应用初始化
        let this->loader = new \Phalcon\Loader();
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

    public function execTask(array argv, <\Phalcon\DI\FactoryDefault> di = null)
    {
        var moduleClass, module;

        this->initConf();
        let this->loader = new \Phalcon\Loader();

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

        this->application->handle($argv);
    }
    
    public function load(var filePath)
    {
        let {"rootPath"} = APP_ROOT_DIR;
        let {"loader"}   = this->loader;
        let {"config"}   = this->config;
        let {"application"} = this->application;
        let {"bootstrap"}   = this;
        let {"di"}          = this->di;
        return require filePath;
    }
}
