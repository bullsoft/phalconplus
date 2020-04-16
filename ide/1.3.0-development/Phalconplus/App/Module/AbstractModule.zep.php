<?php

namespace PhalconPlus\App\Module;

use PhalconPlus\App\Module\ModuleDef;
use PhalconPlus\App\App as SuperApp;
use PhalconPlus\App\Engine\AppEngine;
use Phalcon\Di\Injectable;
use PhalconPlus\Base\Exception as BaseException;
use PhalconPlus\Enum\RunMode;

abstract class AbstractModule extends Injectable
{

    protected $app = null;


    protected $def = null;


    protected $engine = null;



    public function getApp()
    {
    }


    public function getDef()
    {
    }


    public function getEngine()
    {
    }

    /**
     * @param \PhalconPlus\App\App $app
     * @param \PhalconPlus\App\Module\ModuleDef $def
     */
    public function __construct(\PhalconPlus\App\App $app, \PhalconPlus\App\Module\ModuleDef $def = null)
    {
    }


    public function isPrimary()
    {
    }


    public function isCli()
    {
    }


    public function isWeb()
    {
    }


    public function isSrv()
    {
    }


    public function isMicro()
    {
    }


    public function getName()
    {
    }

    /**
     * @return SuperApp
     */
    public function app(): SuperApp
    {
    }

    /**
     * @return \Phalcon\Di
     */
    public function di(): \Phalcon\Di
    {
    }

    /**
     * @return ModuleDef
     */
    public function def(): ModuleDef
    {
    }

    /**
     * @return \Phalcon\Config
     */
    public function config(): \Phalcon\Config
    {
    }

    /**
     * @return AppEngine
     */
    public function engine(): AppEngine
    {
    }

    /**
     * @param string $method
     * @param array $params
     */
    public function __call(string $method, array $params = array())
    {
    }

    /**
     * @param array $params
     */
    public function exec(array $params = array())
    {
    }


    abstract public function registerAutoloaders();


    abstract public function registerServices();


    public function registerEvents()
    {
    }

    /**
     * @return AbstractModule
     */
    public function registerEngine(): AbstractModule
    {
    }

}
