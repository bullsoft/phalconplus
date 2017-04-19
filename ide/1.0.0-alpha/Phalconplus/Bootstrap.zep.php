<?php

namespace PhalconPlus;


final class Bootstrap
{

    const COMMON_DIR_NAME = "common";


    const COMMON_CONF_DIR_NAME = "config";


    const COMMON_LOAD_DIR_NAME = "load";


    const ROOT_PUB_DIR_NAME = "public";


    const MODULE_APP_DIR_NAME = "app";


    const DS = "/";


    const PHP_EXT = ".php";


    const ENV_NAME = "phalconplus.env";


    protected $config;


    protected $di;


    protected $application;


    protected $module = array("classPath" => "", "className" => "", "mode" => "");


    protected $modeMap = array("Web" => "Module", "Cli" => "Task", "Srv" => "Srv", "Micro" => "Micro");


    protected $env = "dev";


    /**
     * @param string $modulePath
     */
    public function __construct($modulePath) {}

    /**
     * @param array $module
     */
    private function setModule(array $module) {}


    public function initConf() {}


    public function exec() {}

    /**
     * @param mixed $uri
     * @param bool $needHandle
     */
    public function execModule($uri = null, $needHandle = true) {}

    /**
     * @param bool $needHandle
     */
    public function execSrv($needHandle = true) {}

    /**
     * @param array $argv
     * @param \Phalcon\DI\FactoryDefault $di
     * @param mixed $needHandle
     */
    public function execTask(array $argv, \Phalcon\DI\FactoryDefault $di = null, $needHandle = true) {}

    /**
     * @param string $moduleName
     */
    public function dependModule($moduleName) {}

    /**
     * @return string
     */
    public function getEnv() {}

    /**
     * @return \Phalcon\Config
     */
    public function getConfig() {}

    /**
     * @param \Phalcon\Config $config
     */
    public function setConfig(\Phalcon\Config $config) {}

    /**
     * @return \Phalcon\DI
     */
    public function getDI() {}

    /**
     * @param mixed $filePath
     */
    public function load($filePath) {}

}
