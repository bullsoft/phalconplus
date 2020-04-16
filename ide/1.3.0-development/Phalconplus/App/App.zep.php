<?php

namespace PhalconPlus\App;

use Phalcon\Application as BaseApplication;
use PhalconPlus\Enum\Sys;
use PhalconPlus\App\Module\ModuleDef;
use Phalcon\DiInterface;
use Phalcon\Di;
use PhalconPlus\App\Module\AbstractModule;
use PhalconPlus\Enum\RunEnv;
use Phalcon\Config;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\Events\ManagerInterface;

final class App extends Phalcon\Application
{

    protected $debug = null;


    protected $env = RunEnv::DEV;


    protected $booted = false;


    protected $config = null;


    protected $requestNumber = 0;


    protected $finalizers = array();



    public function getConfig()
    {
    }

    /**
     * @param \Phalcon\Config $config
     */
    public function __construct(\Phalcon\Config $config)
    {
    }

    /**
     * @param string $env
     * @param string $runMode
     * @return App
     */
    public function boot(string $env = '', string $runMode = ''): App
    {
    }

    /**
     * @param string $runMode
     * @return App
     */
    private function bootPrimaryModule(string $runMode = ''): App
    {
    }

    /**
     * @param \PhalconPlus\App\Module\ModuleDef $moduleDef
     * @return AbstractModule
     */
    private function registerModule(\PhalconPlus\App\Module\ModuleDef $moduleDef): AbstractModule
    {
    }

    /**
     * @param string $moduleName
     * @return AbstractModule
     */
    public function import(string $moduleName): AbstractModule
    {
    }

    /**
     * @param string $moduleName
     * @param bool $force
     * @return AbstractModule
     */
    public function dependModule(string $moduleName, bool $force = true): AbstractModule
    {
    }

    /**
     * @param \Phalcon\Config $config
     * @return App
     */
    public function setConfig(\Phalcon\Config $config): App
    {
    }

    /**
     * @return bool
     */
    public function isDebug(): bool
    {
    }

    /**
     * @return bool
     */
    public function isBooted(): bool
    {
    }

    /**
     * @return \Phalcon\Debug
     */
    public function getDebug(): \Phalcon\Debug
    {
    }

    /**
     * @return string
     */
    public function getEnv(): string
    {
    }

    /**
     * @param string $env
     * @return App
     */
    public function setEnv(string $env): App
    {
    }


    public function handle()
    {
    }

    /**
     * @param bool $deeply
     */
    public function terminate(bool $deeply = true)
    {
    }

    /**
     * @param callable $handler
     */
    public function defer($handler)
    {
    }

    /**
     * @return int
     */
    public function getRequestNumber(): int
    {
    }

    /**
     * @return ModuleDef
     */
    public function getDefaultModuleDef(): ModuleDef
    {
    }

    /**
     * @return ModuleDef
     */
    public function getPrimaryModuleDef(): ModuleDef
    {
    }

    /**
     * @param string $defaultModule
     * @return BaseApplication
     */
    public function setDefaultModule(string $defaultModule): BaseApplication
    {
    }

    /**
     * @return string
     */
    public function getDefaultModule(): string
    {
    }

    /**
     * @return AbstractModule
     */
    public function getPrimaryModule(): AbstractModule
    {
    }

    /**
     * @param string $name
     * @return AbstractModule
     */
    public function getModule(string $name = ''): AbstractModule
    {
    }

    /**
     * @param string $name
     * @return ModuleDef
     */
    public function getModuleDef(string $name = ''): ModuleDef
    {
    }

    /**
     * @return Config
     */
    public function config(): Config
    {
    }

    /**
     * @return Di
     */
    public function di(): Di
    {
    }

    /**
     * @param string $method
     * @param array $params
     */
    public function __call(string $method, array $params)
    {
    }

}
