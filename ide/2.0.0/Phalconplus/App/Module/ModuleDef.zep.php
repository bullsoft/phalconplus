<?php

namespace PhalconPlus\App\Module;

use PhalconPlus\Enum\Sys;
use PhalconPlus\App\App as SuperApp;
use PhalconPlus\Enum\RunMode;
use PhalconPlus\Base\AbstractModule;
use Phalcon\Config;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\DI\FactoryDefault as DefaultDI;
use Phalcon\DI\FactoryDefault\CLI as TaskDI;

class ModuleDef
{

    protected $classPath = '';


    protected $className = '';


    protected $name = '';


    protected $configPath = '';


    protected $dir = '';


    protected $config = null;


    protected $runMode = null;


    protected $app = null;


    protected $isPrimary = false;


    /**
     * @param \PhalconPlus\App\App $app
     * @param string $moduleDir
     * @param bool $isPrimary
     * @param string $runMode
     */
    public function __construct(\PhalconPlus\App\App $app, string $moduleDir, bool $isPrimary = false, string $runMode = '')
    {
    }

    /**
     * @return \Phalcon\Di
     */
    public function newDI(): \Phalcon\Di
    {
    }

    /**
     * @return AbstractModule
     */
    public function checkout(): AbstractModule
    {
    }

    /**
     * @return bool
     */
    public function isDefault(): bool
    {
    }

    /**
     * @return bool
     */
    public function isPrimary(): bool
    {
    }

    /**
     * @return bool
     */
    public function getIsPrimary(): bool
    {
    }

    /**
     * @return string
     */
    public function classPath(): string
    {
    }

    /**
     * @return string
     */
    public function getClassPath(): string
    {
    }

    /**
     * @return string
     */
    public function className(): string
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
    public function runMode(): RunMode
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
    public function mapClassName(): string
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
    public function mode(): string
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
    public function mame(): string
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
    public function ns(): string
    {
    }

    /**
     * @return string
     */
    public function getNs(): string
    {
    }

    /**
     * @return string
     */
    public function configPath(): string
    {
    }

    /**
     * @return string
     */
    public function getConfigPath(): string
    {
    }

    /**
     * @return Config
     */
    public function getConfig(): \Phalcon\Config
    {
    }

    /**
     * @return string
     */
    public function dir(): string
    {
    }

    /**
     * @return string
     */
    public function getDir(): string
    {
    }

    /**
     * @return Config
     */
    public function config(): \Phalcon\Config
    {
    }

    /**
     * @return SuperApp
     */
    public function app(): SuperApp
    {
    }

    /**
     * @return SuperApp
     */
    public function getApp(): SuperApp
    {
    }

    /**
     * @return \Phalcon\Di
     */
    public function di(): \Phalcon\Di
    {
    }

}
