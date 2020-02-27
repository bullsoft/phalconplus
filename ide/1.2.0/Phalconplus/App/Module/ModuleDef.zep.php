<?php

namespace PhalconPlus\App\Module;

use PhalconPlus\Enum\Sys;
use PhalconPlus\App\App as SuperApp;
use PhalconPlus\Enum\RunMode;
use PhalconPlus\Base\AbstractModule;
use PhalconPlus\Bootstrap;
use PhalconPlus\Base\Exception as BaseException;

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
     * @param \PhalconPlus\App\App $app
     * @param string $moduleDir
     * @param bool $isPrimary
     */
    public function __construct(\PhalconPlus\App\App $app, string $moduleDir, bool $isPrimary = false)
    {
    }

    /**
     * @param \Phalcon\Di $di
     * @return AbstractModule
     */
    public function impl(\Phalcon\Di $di): AbstractModule
    {
    }


    public function isDefault()
    {
    }


    public function isPrimary()
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
     * @return Bootstrap
     */
    public function getBootstrap(): Bootstrap
    {
    }

    /**
     * @return string
     */
    public function getClassName(): string
    {
    }

    /**
     * @return RunMode
     */
    public function getRunMode(): RunMode
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
