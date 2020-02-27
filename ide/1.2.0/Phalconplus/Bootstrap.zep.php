<?php

namespace PhalconPlus;

use PhalconPlus\Enum\Sys;
use PhalconPlus\App\App as SuperApp;

final class Bootstrap
{

    protected $app = null;


    protected $loadedFiles = array();



    public function getApp()
    {
    }


    public function getLoadedFiles()
    {
    }

    /**
     * @param string $moduleDir
     * @param string $env
     */
    public function __construct(string $moduleDir, string $env = '')
    {
    }

    /**
     * @return \Phalcon\Config
     */
    protected function initConf(): \Phalcon\Config
    {
    }


    public function exec()
    {
    }

    /**
     * @param mixed $filePath
     */
    public function load($filePath)
    {
    }


    public function terminate()
    {
    }


    public function __destruct()
    {
    }

}
