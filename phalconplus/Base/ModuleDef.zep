//<?php
namespace PhalconPlus\Base;
use PhalconPlus\Bootstrap as Bs;

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

    // <\Phalcon\Config>
    protected config = null;
    // <\PhalconPlus\Enum\RunMode>
    protected runMode = null;

    public function __construct(<\PhalconPlus\Bootstrap> boot, const string! modulePath)
    {
        if !is_dir(modulePath) {
            throw new \Exception("Module directory not exists or not a dir, file positon: " . modulePath);
        }

        // 模块配置, 如果找不到"app/config/{APP_ENV}.php"，则去找"app/config/config.php"
        var confPath, confPrefix;
        let confPrefix =  implode(Bs::DS, [
            Bs::APP_DIR_NAME,
            Bs::CONF_DIR_NAME,
            APP_ENV
        ]);
        let confPath = modulePath . confPrefix . Bs::EXT;
        if !is_file(confPath) {
            // TODO: 是否需要打WARNING日志？
            let confPrefix = implode(Bs::DS, [
                Bs::APP_DIR_NAME,
                Bs::CONF_DIR_NAME,
                Bs::CONF_FILE_NAME
            ]);
            let confPath = modulePath . confPrefix . Bs::EXT;
            if !is_file(confPath) {
                throw new \Phalcon\Config\Exception("Module config file not exist, file position: " . confPath);
            }
        }
        let this->configPath = confPath;

        // 模块配置
        let this->config = new \Phalcon\Config(boot->load(confPath));

        var appConfig = this->config->application;

        let this->name = appConfig->name;
        let this->runMode = new \PhalconPlus\Enum\RunMode(ucfirst(strtolower(appConfig->mode)));

        let this->className = appConfig->ns . this->runMode->getMapClassName();
        let this->classPath = modulePath . Bs::APP_DIR_NAME . Bs::DS . this->runMode->getMapClassName() . Bs::EXT;

        if !is_file(this->classPath) {
            throw new \Exception("Module class file not exists: " . this->classPath);
        }
    }

    public function mount(<\Phalcon\Di> di)
    {
        require this->classPath;
        if !class_exists(this->className) {
            throw new \Exception("Module class not exists: ". this->className);
        }
        var className = this->className;
        return new {className}(di);
    }

    public function getClassPath()
    {
        return this->classPath;
    }

    public function getClassName()
    {
        return this->className;
    }

    public function getRunMode() -> <\PhalconPlus\Enum\RunMode>
    {
        return this->runMode;
    }

    public function getMapClassName()
    {
        return this->runMode->getMapClassName();
    }

    public function getMode()
    {
        return this->runMode->getValue();
    }

    public function getName()
    {
        return this->name;
    }

    public function getConfigPath()
    {
        return this->configPath;
    }

    public function getConfig() -> <\Phalcon\Config>
    {
        return this->config;
    }
}
