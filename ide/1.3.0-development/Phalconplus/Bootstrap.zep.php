<?php

namespace PhalconPlus;

use PhalconPlus\Enum\Sys;
use PhalconPlus\App\App as SuperApp;
use Phalcon\Config;

final class Bootstrap
{

    protected $app = null;


    /**
     * @param string $moduleDir
     * @param string $env
     * @param string $runMode
     */
    public function __construct(string $moduleDir, string $env = '', string $runMode = '')
    {
    }

    /**
     * @return Config
     */
    protected function initConf(): Config
    {
    }

    /**
     * @return SuperApp
     */
    public function getApp(): SuperApp
    {
    }

    /**
     * @return SuperApp
     */
    public function app(): SuperApp
    {
    }


    public function terminate()
    {
    }

}
