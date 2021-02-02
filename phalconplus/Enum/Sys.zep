namespace PhalconPlus\Enum;
use PhalconPlus\Enum\AbstractEnum;
use PhalconPlus\Base\Exception as BaseException;
use PhalconPlus\App\App as SuperApp;

final class Sys extends AbstractEnum
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
    private static requiredFiles = [];
    private static app = null;

    public static function init(string! moduleDir) -> void
    {
        if !empty(self::primaryModuleDir) {
            return ;
        }
        let moduleDir = rtrim(moduleDir, Sys::DS);
        if !is_dir(moduleDir) {
            throw new \Exception("Module directory not exists or not a dir, file positon: " . moduleDir);
        }
        let self::primaryModuleDir = moduleDir;
        let self::rootDir = dirname(moduleDir);
        // Alias classes for convenience.
        Sys::classAlias("PhalconPlus\\Enum\\Sys",   "Ph\\Sys");
        Sys::classAlias("PhalconPlus\\Helper\\Arr", "Ph\\Arr");
        Sys::classAlias("PhalconPlus\\Helper\\Str", "Ph\\Str");
        Sys::classAlias("PhalconPlus\\Helper\\Ns",  "Ph\\Ns");
        Sys::classAlias("PhalconPlus\\Helper\\Variable", "Ph\\Vars");
    }

    public static function initApp(<SuperApp> app) -> void
    {
        // Initial only once
        if self::app !== null {
            return ;
        }
        let self::app = app;
        // 加载Facacdes
        Facade::register(app, "Ph\\");
    }

    public static function app() -> <SuperApp>
    {
        if self::app == null {
            throw new \Exception("SuperApp has no instances yet");
        }
        return self::app;
    }

    // -> {APP_MODULE_DIR}
    public static function getPrimaryModuleDir() -> string
    {
        return self::primaryModuleDir;
    }

    // -> {APP_ROOT_DIR}
    public static function getRootDir() -> string
    {
        return self::rootDir;
    }

    // -> {APP_ROOT_DIR}/common
    public static function getCommonDir() -> string
    {
        return implode(Sys::DS, [
            self::rootDir,
            Sys::COMMON_NAME
        ]);
    }

    // -> {APP_ROOT_DIR}/common/config
    public static function getGlobalConfigDir() -> string
    {
        return implode(Sys::DS, [
            self::rootDir,
            Sys::COMMON_NAME,
            Sys::CONF_NAME
        ]);
    }

    // -> {APP_ROOT_DIR}/common/config/config.php
    public static function getGlobalConfigPath() -> string
    {
        return implode(Sys::DS, [
            self::rootDir,
            Sys::COMMON_NAME,
            Sys::CONF_NAME,
            Sys::CONF_NAME . Sys::EXT
        ]);
    }

    // -> {APP_ROOT_DIR}/common/load
    public static function getGlobalLoadDir() -> string
    {
        return implode(Sys::DS, [
            self::rootDir,
            Sys::COMMON_NAME,
            Sys::LOAD_NAME
        ]);
    }

    // -> {APP_ROOT_DIR}/{moduleName}
    public static function getModuleDirByName(string moduleName) -> string
    {
        return implode(Sys::DS, [
            self::rootDir,
            moduleName
        ]);
    }

    // foo/bar/baz -> baz
    public static function getModuleNameByDir(string moduleDir) -> string
    {
        return pathinfo(moduleDir, PATHINFO_FILENAME);
    }

    // {moduleDir}/app/{modeName}.php
    public static function getModuleClassPath(string moduleDir, string modeName)
    {
        return implode(Sys::DS, [
            moduleDir,
            Sys::APP_NAME,
            modeName . Sys::EXT
        ]);
    }

    // -> {moduleDir}/app/config/{APP_RUN_ENV | config}.php
    public static function getModuleConfigPath(string moduleDir)
    {
        var confPath = "";
        let confPath = implode(Sys::DS, [
            moduleDir,
            Sys::APP_NAME,
            Sys::CONF_NAME,
            APP_RUN_ENV . Sys::EXT
        ]);
        if !is_file(confPath) {
            let confPath = implode(Sys::DS, [
                moduleDir,
                Sys::APP_NAME,
                Sys::CONF_NAME,
                Sys::CONF_NAME . Sys::EXT
            ]);
        }
        if !is_file(confPath) {
            throw new BaseException("Module Config file not exists: " . confPath . " & " . APP_RUN_ENV . self::EXT);
        }
        return confPath;
    }

    // -> {APP_ROOT_DIR}/vendor/autoload.php
    public static function getComposerAutoloadPath()
    {
        return implode(Sys::DS, [
            self::rootDir,
            "vendor",
            "autoload.php"
        ]);
    }

    public static function classAlias(string className, string classAlias) -> bool
    {
        %{
            zend_class_entry *ce;
            ce = zephir_fetch_class(&className TSRMLS_CC);
            zend_register_class_alias_ex(Z_STRVAL(classAlias), Z_STRLEN(classAlias), ce);
        }%
        
        return true;
    }

    public static function load(string filePath, array context = [])
    {
        if unlikely !is_file(filePath) {
            throw new \Exception("The file you try to load is not exists. The Path is: " . filePath);
        }
        var result;
        if fetch result, self::requiredFiles[filePath] {
            return result;
        }
        var rootPath = "rootPath",
            di       = "di",
            loader   = "loader",
            config   = "config",
            superapp = "superapp";
        // Create a Symbol Table for require directive
        create_symbol_table(); 
        // ALL variables assigned with "let {zephir-var} = zephir-val" 
        // are ONLY visible in required file
        let {rootPath} = Sys::getRootDir();
        if typeof self::app == "object" {
            let {config} = self::app->config();
            if self::app->isBooted() {
                let {superapp} = self::app;
                let {di} = self::app->di();
                let {loader} = self::app->di()->get("loader");
            }
        }
        var name, value;
        for name, value in context {
            let {name} = value;
        }
        // Require file and hold the result for subsequent request.
        let result = require filePath;
        let self::requiredFiles[filePath] = result;
        return result;
    }

}
