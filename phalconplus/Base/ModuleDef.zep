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
    protected mode = "";

    // <\Phalcon\Config>
    protected config = null;

    // 运行模式
    protected modeMap = [
        "Web"     : "Module",
        "Cli"     : "Task",
        "Srv"     : "Srv",
        "Micro"   : "Micro"
    ];

    public function __construct(<\PhalconPlus\Bootstrap> boot)
    {
        // 模块配置, 如果找不到"app/config/{APP_ENV}.php"，则去找"app/config/config.php"
        var confPath;
        let confPath = APP_MODULE_DIR . "app" . Bs::DS . "config" . Bs::DS . APP_ENV . Bs::EXT;
        if !is_file(confPath) {
            // TODO: 是否需要打WARNING日志？
            let confPath = APP_MODULE_DIR . "app" . Bs::DS . "config" . Bs::DS . "config" . Bs::EXT;
            if !is_file(confPath) {
                throw new \Phalcon\Config\Exception("Module config file not exist, file position: " . confPath);
            }
        }
        // 模块配置
        let this->config = new \Phalcon\Config(boot->load(confPath));

        let this->mode = ucfirst(strtolower(this->config->application->mode));
        if !array_key_exists(this->mode, this->modeMap) {
            throw new \Exception("Module mode not exists: " . this->mode);
        }

        let this->className = this->config->application->ns . this->modeMap[this->mode];
        let this->classPath = APP_MODULE_DIR . "app" . Bs::DS . this->modeMap[this->mode] . Bs::EXT;

        if !is_file(this->classPath) {
            throw new \Exception("Module class file not exists: " . this->classPath);
        }
        require_once(this->classPath);
        if !class_exists(this->className) {
            throw new \Exception("Module class not exists: ". this->className);
        }

    }

    public function getClassPath()
    {
        return this->classPath;
    }

    public function getClassName()
    {
        return this->className;
    }

    public function getMode()
    {
        return this->mode;
    }

    public function getConfig() -> <\Phalcon\Config>
    {
        return this->config;
    }
}
