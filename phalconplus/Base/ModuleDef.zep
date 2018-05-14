//<?php
namespace PhalconPlus\Base;
use PhalconPlus\Bootstrap as Bs;
use PhalconPlus\Enum\Sys as Sys;

/* Module Structure for mode "Web"
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

    public function __construct(<\PhalconPlus\Bootstrap> boot, const string! moduleDir)
    {
        if !is_dir(moduleDir) {
            throw new \Exception("Module directory not exists or not a dir, file positon: " . moduleDir);
        }
        let this->dir = moduleDir;

        let this->configPath = Sys::getModuleConfigPath(moduleDir);

        // 模块配置
        let this->config = new \Phalcon\Config(boot->load(this->configPath));

        var appConfig = this->config->application;

        let this->name = appConfig->name;
        let this->runMode = new \PhalconPlus\Enum\RunMode(ucfirst(strtolower(appConfig->mode)));

        let this->className = appConfig->ns . this->runMode->getMapClassName();

        let this->classPath = Sys::getModuleClassPath(moduleDir, this->runMode);

        if !is_file(this->classPath) {
            throw new \Exception("Module class file not exists: " . this->classPath);
        }
    }

    public function impl(<\Phalcon\Di> di) -> <\PhalconPlus\Base\AbstractModule>
    {
        require this->classPath;
        if !class_exists(this->className) {
            throw new \Exception("Module class not exists: ". this->className);
        }
        var className = this->className;
        return new {className}(di, this);
    }

    public function getClassPath() -> string
    {
        return this->classPath;
    }

    public function getClassName() -> string
    {
        return this->className;
    }

    public function getRunMode() -> <\PhalconPlus\Enum\RunMode>
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
}
