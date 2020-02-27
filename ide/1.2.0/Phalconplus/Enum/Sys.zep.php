<?php

namespace PhalconPlus\Enum;

use PhalconPlus\Enum\AbstractEnum;
use PhalconPlus\Base\Exception as BaseException;

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


    /**
     * @param string $moduleDir
     */
    public static function init(string $moduleDir)
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
     * @param \PhalconPlus\Enum\RunMode $runMode
     */
    public static function getModuleClassPath(string $moduleDir, \PhalconPlus\Enum\RunMode $runMode)
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

}
