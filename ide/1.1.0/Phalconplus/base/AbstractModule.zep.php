<?php

namespace PhalconPlus\Base;


abstract class AbstractModule
{

    protected $di = null;


    protected $def = null;


    /**
     * @param \Phalcon\DI $di
     * @param \PhalconPlus\Base\ModuleDef $def
     */
    public function __construct(\Phalcon\DI $di, \PhalconPlus\Base\ModuleDef $def = null) {}

    /**
     * @return \PhalconPlus\Base\ModuleDef
     */
    public function getDef(): \PhalconPlus\Base\ModuleDef {}

    /**
     * @return \Phalcon\Di
     */
    public function getDi(): \Phalcon\Di {}


    public function isPrimary() {}


    public function getBootstrap() {}


    abstract public function registerAutoloaders();


    abstract public function registerServices();

}
