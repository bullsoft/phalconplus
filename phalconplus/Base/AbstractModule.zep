//<?php
namespace PhalconPlus\Base;

abstract class AbstractModule
{
    protected di = null;
    
    public function __construct(<\Phalcon\DI> di)
    {
        let this->di = di;
        this->registerAutoloaders();
        this->registerServices();
    }

    abstract public function registerAutoloaders();
    abstract public function registerServices();
}