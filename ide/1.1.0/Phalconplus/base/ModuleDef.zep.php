<?php

namespace PhalconPlus\Base;

use PhalconPlus\Bootstrap;
use PhalconPlus\Enum\Sys;

class ModuleDef
{

    protected $classPath = '';


    protected $className = '';


    protected $name = '';


    protected $configPath = '';


    protected $dir = '';


    static protected $loadedClasses = array();


    protected $config = null;


    protected $runMode = null;


    protected $bootstrap = null;


    protected $isPrimary = false;


    /**
     * @param \PhalconPlus\Bootstrap $boot
     * @param string $moduleDir
     * @param bool $isPrimary
     */
    public function __construct(\PhalconPlus\Bootstrap $boot, string $moduleDir, bool $isPrimary = false)
    {
    }

    /**
     * @param \Phalcon\Di $di
     * @return \PhalconPlus\Base\AbstractModule
     */
    public function impl(\Phalcon\Di $di): \PhalconPlus\Base\AbstractModule
    {
    }


    public function getIsPrimary()
    {
    }

    /**
     * @return string
     */
    public function getClassPath(): string
    {
    }

    /**
     * @return \PhalconPlus\Bootstrap
     */
    public function getBootstrap(): \PhalconPlus\Bootstrap
    {
    }

    /**
     * @return string
     */
    public function getClassName(): string
    {
    }

    /**
     * @return \PhalconPlus\Enum\RunMode
     */
    public function getRunMode(): \PhalconPlus\Enum\RunMode
    {
    }

    /**
     * @return string
     */
    public function getMapClassName(): string
    {
    }

    /**
     * @return string
     */
    public function getMode(): string
    {
    }

    /**
     * @return string
     */
    public function getName(): string
    {
    }

    /**
     * @return string
     */
    public function getConfigPath(): string
    {
    }

    /**
     * @return \Phalcon\Config
     */
    public function getConfig(): \Phalcon\Config
    {
    }

    /**
     * @return string
     */
    public function getDir(): string
    {
    }

}
