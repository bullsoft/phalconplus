//<?php
namespace PhalconPlus\Enum;
use PhalconPlus\Enum\AbstractEnum;

class Sys extends AbstractEnum
{
    // 定义类常量
    const COMMON_NAME = "common";
    const CONF_NAME   = "config";
    const LOAD_NAME   = "load";
    const PUB_NAME    = "public";
    const APP_NAME    = "app";

    const DS = DIRECTORY_SEPARATOR;
    const EXT = ".php";
    const ENV_NAME = "phalconplus.env";

    private static rootDir = "";  // without trailing /
    private static primaryModuleDir = ""; // without trailing /

    public static function init(string! moduleDir)
    {
        if !empty(self::primaryModuleDir) {
            return ;
        }
        let moduleDir = rtrim(moduleDir, self::DS);
        if !is_dir(moduleDir) {
            throw new \PhalconPlus\Base\Exception("Module directory not exists or not a dir, file positon: " . moduleDir);
        }
        let self::primaryModuleDir = moduleDir;
        let self::rootDir = dirname(moduleDir);
        return ;
    }

    // -> {APP_MODULE_DIR}
    public static function getPrimaryModuleDir() -> string
    {
        return self::primaryModuleDir . self::DS;
    }

    // -> {APP_ROOT_DIR}
    public static function getRootDir() -> string
    {
        return self::rootDir . self::DS;
    }

    // -> {APP_ROOT_DIR}/common/
    public static function getCommonDir() -> string
    {
        return implode(self::DS, [
            self::rootDir,
            self::COMMON_NAME,
            ""
        ]);
    }

    // -> {APP_ROOT_DIR}/common/config/
    public static function getGlobalConfigDir() -> string
    {
        return implode(self::DS, [
            self::rootDir,
            self::COMMON_NAME,
            self::CONF_NAME . self::EXT
        ]);
    }

    // -> {APP_ROOT_DIR}/common/config/config.php
    public static function getGlobalConfigPath() -> string
    {
        return implode(self::DS, [
            self::rootDir,
            self::COMMON_NAME,
            self::CONF_NAME,
            self::CONF_NAME . self::EXT
        ]);
    }

    // -> {APP_ROOT_DIR}/common/load/
    public static function getGlobalLoadDir() -> string
    {
        return implode(self::DS, [
            self::rootDir,
            self::COMMON_NAME,
            self::LOAD_NAME,
            ""
        ]);
    }

    // -> {APP_ROOT_DIR}/{moduleName}/
    public static function getModuleDirByName(string moduleName) -> string
    {
        return implode(self::DS, [
            self::rootDir,
            moduleName,
            ""
        ]);
    }

    // foo/bar/baz/ -> baz
    public static function getModuleNameByDir(string moduleDir) -> string
    {
        return pathinfo(moduleDir, PATHINFO_FILENAME);
    }

    public static function getModuleClassPath(string moduleDir, <\PhalconPlus\Enum\RunMode> runMode)
    {
        return implode("", [
            moduleDir,
            self::APP_NAME,
            self::DS,
            runMode->getMapClassName(),
            self::EXT
        ]);
    }

    // -> {APP_ROOT_DIR}/{moduleName}/app/config/{APP_RUN_ENV}.php
    public static function getModuleConfigPath(string moduleDir)
    {
        var confPrefix = "", confPath = "";

        let confPrefix = implode(self::DS, [
            rtrim(moduleDir, self::DS),
            self::APP_NAME,
            self::CONF_NAME,
            ""
        ]);

        let confPath = implode("", [
            confPrefix,
            APP_RUN_ENV,
            self::EXT
        ]);

        if !is_file(confPath) {
            let confPath = implode("", [
                confPrefix,
                self::CONF_NAME,
                self::EXT
            ]);
        }

        if !is_file(confPath) {
            throw new \PhalconPlus\Base\Exception("Module Config file not exists: " . confPath . " & " . APP_RUN_ENV . self::EXT);
        }

        return confPath;
    }

    // -> {APP_ROOT_DIR}/vendor/autoload.php
    public static function getComposerAutoloadPath()
    {
        return implode(self::DS, [
            self::rootDir,
            "vendor",
            "autoload.php"
        ]);
    }
}
