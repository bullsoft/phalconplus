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


    protected $autoHandle = true;


    protected $loadedFiles = array();


    /**
     * @param mixed $di
     */
    public function setDi($di) {}


    public function getDi() {}

    /**
     * @param mixed $autoHandle
     */
    public function setAutoHandle($autoHandle) {}


    public function getAutoHandle() {}


    public function getLoadedFiles() {}

    /**
     * @param string $moduleDir
     * @param string $env
     */
    public function __construct(string $moduleDir, string $env = '') {}

    /**
     * @param \PhalconPlus\Base\ModuleDef $moduleDef
     * @return \PhalconPlus\Base\AbstractModule
     */
    private function registerModule(\PhalconPlus\Base\ModuleDef $moduleDef): \PhalconPlus\Base\AbstractModule {}

    /**
     * @return \PhalconPlus\Bootstrap
     */
    public function initConf(): \PhalconPlus\Bootstrap {}

    /**
     * @param object $app
     * @param bool $autoHandle
     * @return \PhalconPlus\Bootstrap
     */
    public function setApp($app, bool $autoHandle = false): \PhalconPlus\Bootstrap {}

    /**
     * @return object|null
     */
    public function getApp(): ? {}


    public function exec() {}


    public function terminate() {}


    public function __destruct() {}

    /**
     * @request a uri string (for \Phalcon\Mvc\Application) or Psr\Http\Message\Request
     * @param mixed $request
     * @return \PhalconPlus\Bootstrap|\Phalcon\Http\Response
     */
    public function execModule($request = null) {}

    /**
     * @return bool|\PhalconPlus\Bootstrap
     */
    public function execSrv() {}

    /**
     * @param array $argv
     * @param \Phalcon\DI\FactoryDefault $di
     */
    public function execTask(array $argv, \Phalcon\DI\FactoryDefault $di = null) {}

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
     * @param mixed $filePath
     */
    public function load($filePath) {}

}
