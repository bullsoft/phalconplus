<?php

namespace PhalconPlus\Enum;

use PhalconPlus\Enum\AbstractEnum;
use PhalconPlus\Base\Exception as BaseException;
use PhalconPlus\App\App as SuperApp;

final class Sys extends AbstractEnum
{

    const COMMON_NAME = 'common';


    const CONF_NAME = 'config';


    const LOAD_NAME = 'load';


    const PUB_NAME = 'public';


    const APP_NAME = 'app';


    const DS = '/';


    const EXT = '.php';


    const ENV_NAME = 'phalconplus.env';


    static private $rootDir = '';


    static private $primaryModuleDir = '';


    static private $requiredFiles = [];


    static private $app = null;


    /**
     * @param string $moduleDir
     * @return void
     */
    public static function init(string $moduleDir): void
    {
    }

    /**
     * @param \PhalconPlus\App\App $app
     * @return void
     */
    public static function initApp(\PhalconPlus\App\App $app): void
    {
    }

    /**
     * @return SuperApp
     */
    public static function app(): SuperApp
    {
    }

    /**
     * @return string
     */
    public static function getPrimaryModuleDir(): string
    {
    }

    /**
     * @return string
     */
    public static function getRootDir(): string
    {
    }

    /**
     * @return string
     */
    public static function getCommonDir(): string
    {
    }

    /**
     * @return string
     */
    public static function getGlobalConfigDir(): string
    {
    }

    /**
     * @return string
     */
    public static function getGlobalConfigPath(): string
    {
    }

    /**
     * @return string
     */
    public static function getGlobalLoadDir(): string
    {
    }

    /**
     * @param string $moduleName
     * @return string
     */
    public static function getModuleDirByName(string $moduleName): string
    {
    }

    /**
     * @param string $moduleDir
     * @return string
     */
    public static function getModuleNameByDir(string $moduleDir): string
    {
    }

    /**
     * @param string $moduleDir
     * @param string $modeName
     */
    public static function getModuleClassPath(string $moduleDir, string $modeName)
    {
    }

    /**
     * @param string $moduleDir
     */
    public static function getModuleConfigPath(string $moduleDir)
    {
    }


    public static function getComposerAutoloadPath()
    {
    }

    /**
     * @param string $className
     * @param string $classAlias
     * @return bool
     */
    public static function classAlias(string $className, string $classAlias): bool
    {
    }

    /**
     * @param string $filePath
     * @param array $context
     */
    public static function load(string $filePath, array $context = [])
    {
    }

}
