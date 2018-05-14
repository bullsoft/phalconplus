//<?php
namespace PhalconPlus\Base;

abstract class AbstractModule
{
    // <\Phalcon\DI>
    protected di = null;

    // <\PhalconPlus\Base\ModuleDef>
    protected def = null;

    public function __construct(<\Phalcon\DI> di, <\PhalconPlus\Base\ModuleDef> def = null)
    {
        let this->di = di;
        let this->def =def; // Module should have it's definition.
    }

    public function getDef() -> <\PhalconPlus\Base\ModuleDef>
    {
        return this->def;
    }

    abstract public function registerAutoloaders();
    abstract public function registerServices();
}
