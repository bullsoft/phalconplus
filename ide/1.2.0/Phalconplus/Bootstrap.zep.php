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
     */
    public function __construct(string $moduleDir, string $env = '')
    {
    }

    /**
     * @return Config
     */
    protected function initConf(): Config
    {
    }


    public function exec()
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
