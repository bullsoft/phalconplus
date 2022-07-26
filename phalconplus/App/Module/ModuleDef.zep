namespace PhalconPlus\App\Module;
use PhalconPlus\Enum\Sys as Sys;
use PhalconPlus\App\App as SuperApp;
use PhalconPlus\Enum\RunMode;
use PhalconPlus\Base\AbstractModule;
use Phalcon\Config\Config;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\DI\FactoryDefault as DefaultDI;
use Phalcon\DI\FactoryDefault\CLI as TaskDI;
use Phalcon\Di\Di;

/* Module Structure
    .
    ├── app
    │   ├── Module.php
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

    public function __construct(<SuperApp> app, const string! moduleDir, boolean isPrimary = false, string runMode = "")
    {
        if !is_dir(moduleDir) {
            throw new BaseException("Module directory not exists or not a dir, file positon: " . moduleDir);
        }
        let this->app = app;
        let this->isPrimary = isPrimary;
        let this->dir = moduleDir;
        let this->configPath = Sys::getModuleConfigPath(moduleDir);

        // 模块配置
        let this->config = new Config(
            Sys::load(this->configPath, [
                "def" : this,
                "app" : app
            ])
        );
        if !isset this->config["application"] {
            throw new BaseException("Config Path: /application must exists");
        }
        // Config
        var appConfig = this->config->application;

        let this->name = appConfig->name;

        if empty(runMode) {
            let this->runMode = new RunMode(ucfirst(strtolower(appConfig->mode)));
        } else {
            let this->runMode = new RunMode(runMode);
        }
        
        let this->classPath = Sys::getModuleClassPath(moduleDir, this->runMode->getMapClassName());
        if is_file(this->classPath) {
            let this->className = appConfig->ns . this->runMode->getMapClassName();
        } else {
            let this->classPath = Sys::getModuleClassPath(moduleDir, "Module");
            let this->className = appConfig->ns . "Module";
        }
    }

    public function newDI() -> <\Phalcon\Di>
    {
        var di;
        if this->runMode->isCli() {
            let di = new TaskDI();
        } else {
            let di = new DefaultDI();
        }
        di->setInternalEventsManager(di->get("eventsManager"));
        this->app->setEventsManager(di->get("eventsManager"));
        return di;
    }

    public function checkout() -> <AbstractModule>
    {
        var e;
        if this->isPrimary() {
            // 装载全局服务初始化文件
            try {
                Sys::load(this->runMode->getScriptPath());
            } catch \Exception, e {
                // nothing to do...
                trigger_error("Global load scripts not exists: " . e->getMessage());
            }
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

    public function classPath() -> string
    {
        return this->classPath;
    }

    public function getClassPath() -> string
    {
        return this->classPath;
    }

    public function className() -> string
    {
        return this->className;
    }

    public function getClassName() -> string
    {
        return this->className;
    }

    public function runMode() -> <RunMode>
    {
        return this->runMode;
    }

    public function getRunMode() -> <RunMode>
    {
        return this->runMode;
    }

    public function mapClassName() -> string
    {
        return this->runMode->getMapClassName();
    }

    public function getMapClassName() -> string
    {
        return this->runMode->getMapClassName();
    }

    public function mode() -> string
    {
        return this->runMode->getValue();
    }

    public function getMode() -> string
    {
        return this->runMode->getValue();
    }

    public function mame() -> string
    {
        return this->name;
    }

    public function getName() -> string
    {
        return this->name;
    }

    public function ns() -> string
    {
        return rtrim(this->config->path("application.ns"), "\\");
    }

    public function getNs() -> string
    {
        return rtrim(this->config->path("application.ns"), "\\");
    }

    public function configPath() -> string
    {
        return this->configPath;
    }

    public function getConfigPath() -> string
    {
        return this->configPath;
    }

    public function getConfig() -> <Config>
    {
        return this->config;
    }

    public function dir() -> string
    {
        return this->dir;
    }

    public function getDir() -> string
    {
        return this->dir;
    }

    public function config() -> <Config>
    {
        return this->config;
    }

    public function app() -> <SuperApp>
    {
        return this->app;
    }

    public function getApp() -> <SuperApp>
    {
        return this->app;
    }

    public function di() -> <Di>
    {
        return this->app->di();
    }
}
