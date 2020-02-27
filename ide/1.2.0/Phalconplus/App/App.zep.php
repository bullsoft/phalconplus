<?php

namespace PhalconPlus\App;

use Phalcon\Application as BaseApplication;
use PhalconPlus\Enum\Sys;
use PhalconPlus\App\Module\ModuleDef;
use PhalconPlus\App\Module\AbstractModule;
use PhalconPlus\Enum\RunEnv;
use PhalconPlus\Enum\RunMode;
use PhalconPlus\Enum\Facade;
use Phalcon\Config;
use PhalconPlus\Bootstrap;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\Events\ManagerInterface;

final class App extends Phalcon\Application
{

    protected $debug = null;


    protected $env = RunEnv::DEV;


    protected $booted = false;


    protected $bootstrap = null;


    protected $config = null;


    protected $driver = null;


    protected $autoHandle = true;



    public function getBootstrap()
    {
    }


    public function getConfig()
    {
    }


    public function getDriver()
    {
    }

    /**
     * @param mixed $driver
     */
    public function setDriver($driver)
    {
    }

    /**
     * @param mixed $autoHandle
     */
    public function setAutoHandle($autoHandle)
    {
    }


    public function getAutoHandle()
    {
    }

    /**
     * @param \PhalconPlus\Bootstrap $boot
     */
    public function __construct(\PhalconPlus\Bootstrap $boot)
    {
    }

    /**
     * @param \Phalcon\Config $config
     * @param string $env
     * @return App
     */
    public function boot(\Phalcon\Config $config, string $env = ''): App
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
    public function dependModule(string $moduleName): AbstractModule
    {
    }

    /**
     * @param \Phalcon\Config $config
     */
    public function setConfig(\Phalcon\Config $config)
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


    public function terminate()
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
    public function getModule(string $name): AbstractModule
    {
    }

    /**
     * @param string $name
     * @return ModuleDef
     */
    public function getModuleDef(string $name): ModuleDef
    {
    }

}
