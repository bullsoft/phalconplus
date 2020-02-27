<?php

namespace PhalconPlus\App\Module;

use PhalconPlus\App\Module\ModuleDef;

abstract class AbstractModule
{

    protected $di = null;


    protected $def = null;


    /**
     * @param \Phalcon\DI $di
     * @param \PhalconPlus\App\Module\ModuleDef $def
     */
    public function __construct(\Phalcon\DI $di, \PhalconPlus\App\Module\ModuleDef $def = null)
    {
    }


    public function getConfig()
    {
    }

    /**
     * @return \PhalconPlus\Base\ModuleDef
     */
    public function getDef(): \PhalconPlus\Base\ModuleDef
    {
    }

    /**
     * @return \Phalcon\Di
     */
    public function getDI(): \Phalcon\Di
    {
    }


    public function isPrimary()
    {
    }


    public function getName()
    {
    }


    public function getBootstrap()
    {
    }

    /**
     * @param string $method
     * @param array $params
     */
    public function __call(string $method, array $params = array())
    {
    }


    abstract public function registerAutoloaders();


    abstract public function registerServices();


    public function registerEvents()
    {
    }

}
