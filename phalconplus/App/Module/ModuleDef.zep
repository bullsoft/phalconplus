namespace PhalconPlus\App\Module;
use PhalconPlus\Enum\Sys as Sys;
use PhalconPlus\App\App as SuperApp;
use PhalconPlus\Enum\RunMode;
use PhalconPlus\Base\AbstractModule;
use Phalcon\Config;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\DI\FactoryDefault as DefaultDI;
use Phalcon\DI\FactoryDefault\CLI as TaskDI;

/* Module Structure for mode "Web"
    .
    ├── app
    │   ├── Web.php
        │   ├── config
        │   │   └── dev.php
        │   ├── controllers
        │   │   ├── BaseController.php
        │   │   ├── ErrorController.php
        │   │   ├── IndexController.php
        │   │   └── apis
        │   └── views
        │       └── index
        └── public
        └── index.php
*/

class ModuleDef
{
    protected classPath = "";
    protected className = "";
    protected name = "";
    protected configPath = "";
    protected dir = "";

    // <\Phalcon\Config>
    protected config = null;
    // <\PhalconPlus\Enum\RunMode>
    protected runMode = null;
    // <SuperApp>
    protected app = null;

    // Is this a primary-module? false for default
    protected isPrimary = false;

    public function __construct(<SuperApp> app, const string! moduleDir, boolean isPrimary = false)
    {
        if !is_dir(moduleDir) {
            throw new BaseException("Module directory not exists or not a dir, file positon: " . moduleDir);
        }
        let this->app = app;

        let this->dir = moduleDir;
        let this->configPath = Sys::getModuleConfigPath(moduleDir);

        // 模块配置
        let this->config = new Config(Sys::load(this->configPath));
        if !isset this->config["application"] {
            throw new BaseException("Config Path: /application must exists");
        }
        // Config
        var appConfig = this->config->application;

        let this->name = appConfig->name;
        let this->runMode   = new RunMode(ucfirst(strtolower(appConfig->mode)));
        
        let this->classPath = Sys::getModuleClassPath(moduleDir, this->runMode->getMapClassName());
        if is_file(this->classPath) {
            let this->className = appConfig->ns . this->runMode->getMapClassName();
        } else {
            let this->classPath = Sys::getModuleClassPath(moduleDir, "Module");
            let this->className = appConfig->ns . "Module";
        }

        // if !is_file(this->classPath) {
        //     throw new BaseException("Module class file not exists: " . this->classPath);
        // }

        let this->isPrimary = isPrimary;
    }

    public function newDI() -> <\Phalcon\Di>
    {
        var mode = this->runMode->getValue();
        if mode == RunMode::CLI {
            return new TaskDI();
        } else {
            return new DefaultDI();
        }
    }

    public function checkout() -> <AbstractModule>
    {
        if this->isPrimary() {
            // 装载全局服务初始化文件
            Sys::load(this->runMode->getScriptPath());
        }

        Sys::load(this->classPath);

        if !class_exists(this->className) {
            throw new BaseException([
                "Module class (%s) not exists, ClassPath: %s ",
                [
                    this->className,
                    this->classPath
                ]
            ]);
        }

        var module, className = this->className;

        let module = new {className}(this->app, this);

        if this->isPrimary() {
            this->app->di()->setShared("appModule", module);
        }

        // Register autoloaders and di-services
        module->registerAutoloaders();
        module->registerServices();
        module->registerEvents();

        return module;
    }

    public function isDefault() -> boolean
    {
        return this->isPrimary === true;
    }

    public function isPrimary() -> boolean
    {
        return this->isPrimary === true;
    }

    public function getIsPrimary() -> boolean
    {
        return this->isPrimary;
    }

    public function getClassPath() -> string
    {
        return this->classPath;
    }

    public function getClassName() -> string
    {
        return this->className;
    }

    public function getRunMode() -> <RunMode>
    {
        return this->runMode;
    }

    public function getMapClassName() -> string
    {
        return this->runMode->getMapClassName();
    }

    public function getMode() -> string
    {
        return this->runMode->getValue();
    }

    public function getName() -> string
    {
        return this->name;
    }

    public function getConfigPath() -> string
    {
        return this->configPath;
    }

    public function getConfig() -> <\Phalcon\Config>
    {
        return this->config;
    }

    public function getDir() -> string
    {
        return this->dir;
    }

    public function config() -> <\Phalcon\Config>
    {
        return this->config;
    }

    public function app() -> <SuperApp>
    {
        return this->app;
    }
}
