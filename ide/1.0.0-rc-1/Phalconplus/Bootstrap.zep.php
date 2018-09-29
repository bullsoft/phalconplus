<?php

namespace PhalconPlus;


final class Bootstrap
{

    protected $config = null;


    protected $di = null;


    protected $application = null;


    protected $primaryModuleDef = null;


    protected $activeModules = array();


    protected $debug = null;


    protected $env = \PhalconPlus\Enum\RunEnv::DEV;


    /**
     * @param string $moduleDir
     */
    public function __construct(string $moduleDir) {}

    /**
     * @param \PhalconPlus\Base\ModuleDef $moduleDef
     * @return \PhalconPlus\Base\AbstractModule
     */
    private function registerModule(\PhalconPlus\Base\ModuleDef $moduleDef): \PhalconPlus\Base\AbstractModule {}

    /**
     * @return \PhalconPlus\Bootstrap
     */
    public function initConf(): \PhalconPlus\Bootstrap {}


    public function exec() {}

    /**
     * @param mixed $uri
     * @param bool $needHandle
     */
    public function execModule($uri = null, bool $needHandle = true) {}

    /**
     * @param bool $needHandle
     */
    public function execSrv(bool $needHandle = true) {}

    /**
     * @param array $argv
     * @param \Phalcon\DI\FactoryDefault $di
     * @param mixed $needHandle
     */
    public function execTask(array $argv, \Phalcon\DI\FactoryDefault $di = null, $needHandle = true) {}

    /**
     * @return \PhalconPlus\Base\ModuleDef
     */
    public function getPrimaryModuleDef(): \PhalconPlus\Base\ModuleDef {}

    /**
     * @return \PhalconPlus\Base\AbstractModule
     */
    public function getPrimaryModule(): \PhalconPlus\Base\AbstractModule {}

    /**
     * @param string $name
     * @return \PhalconPlus\Base\AbstractModule
     */
    public function getModule(string $name): \PhalconPlus\Base\AbstractModule {}

    /**
     * @param string $name
     * @return \PhalconPlus\Base\ModuleDef
     */
    public function getModuleDef(string $name): \PhalconPlus\Base\ModuleDef {}

    /**
     * @param string $moduleName
     * @return \PhalconPlus\Base\AbstractModule
     */
    public function dependModule(string $moduleName): \PhalconPlus\Base\AbstractModule {}

    /**
     * @return bool
     */
    public function isDebug(): bool {}

    /**
     * @return \Phalcon\Debug
     */
    public function getDebug(): \Phalcon\Debug {}

    /**
     * @return string
     */
    public function getEnv(): string {}

    /**
     * @return \Phalcon\Config
     */
    public function getConfig(): \Phalcon\Config {}

    /**
     * @param \Phalcon\Config $config
     */
    public function setConfig(\Phalcon\Config $config) {}

    /**
     * @return \Phalcon\DI
     */
    public function getDI(): \Phalcon\DI {}

    /**
     * @param mixed $filePath
     */
    public function load($filePath) {}

}
