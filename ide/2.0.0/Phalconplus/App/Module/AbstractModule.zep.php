<?php

namespace PhalconPlus\App\Module;

use PhalconPlus\App\Module\ModuleDef;
use PhalconPlus\App\App as SuperApp;
use PhalconPlus\App\Engine\AbstractEngine;
use Phalcon\Di\Injectable;
use PhalconPlus\Base\Exception as BaseException;
use PhalconPlus\Enum\RunMode;
use Phalcon\Events\ManagerInterface;
use Phalcon\Http\ResponseInterface as HttpResponse;
use Phalcon\Cli\Task as CliTask;

abstract class AbstractModule extends Injectable
{

    protected $app = null;


    protected $def = null;


    protected $engine = null;



    public function getApp()
    {
    }


    public function getDef()
    {
    }


    public function getEngine()
    {
    }

    /**
     * @param \PhalconPlus\App\App $app
     * @param \PhalconPlus\App\Module\ModuleDef $def
     */
    public function __construct(\PhalconPlus\App\App $app, \PhalconPlus\App\Module\ModuleDef $def = null)
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
    public function isCli(): bool
    {
    }

    /**
     * @return bool
     */
    public function isWeb(): bool
    {
    }

    /**
     * @return bool
     */
    public function isSrv(): bool
    {
    }

    /**
     * @return bool
     */
    public function isMicro(): bool
    {
    }

    /**
     * @return string
     */
    public function getName(): string
    {
    }

    /**
     * @return SuperApp
     */
    public function app(): SuperApp
    {
    }

    /**
     * @return \Phalcon\Di
     */
    public function di(): \Phalcon\Di
    {
    }

    /**
     * @return ModuleDef
     */
    public function def(): ModuleDef
    {
    }

    /**
     * @return \Phalcon\Config
     */
    public function config(): \Phalcon\Config
    {
    }

    /**
     * @return AbstractEngine
     */
    public function engine(): AbstractEngine
    {
    }

    /**
     * @param string $method
     * @param array $params
     */
    public function __call(string $method, array $params = [])
    {
    }

    /**
     * @param array $params
     * @return HttpResponse|CliTask
     */
    public function exec(array $params = [])
    {
    }


    abstract public function registerAutoloaders();


    abstract public function registerServices();


    public function registerEvents()
    {
    }

    /**
     * @return AbstractModule
     */
    public function registerEngine(): AbstractModule
    {
    }

}
