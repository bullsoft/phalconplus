<?php

namespace PhalconPlus\App\Engine;

use PhalconPlus\App\App as SuperApp;
use PhalconPlus\App\Module\AbstractModule as AppModule;
use Phalcon\Di\Injectable;
use Phalcon\CLI\Console as TaskHandler;
use Phalcon\Cli\Task;

class Cli extends Injectable implements \PhalconPlus\App\Engine\AppEngine
{

    protected $appModule = null;


    protected $handler = null;


    /**
     * @param \PhalconPlus\App\Module\AbstractModule $appModule
     * @param BaseApplication $handler
     */
    public function __construct(\PhalconPlus\App\Module\AbstractModule $appModule, BaseApplication $handler = null)
    {
    }

    /**
     * @param array $argv
     * @param \Phalcon\DI\FactoryDefault $di
     * @return AppEngine|Task
     */
    public function exec(array $argv, \Phalcon\DI\FactoryDefault $di = null)
    {
    }

    /**
     * @param object $handler
     * @return AppEngine
     */
    public function setHandler($handler): AppEngine
    {
    }

    /**
     * @return object
     */
    public function handler()
    {
    }

    /**
     * @return object
     */
    public function getHandler()
    {
    }

}
