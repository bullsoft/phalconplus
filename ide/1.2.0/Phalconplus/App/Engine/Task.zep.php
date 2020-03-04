<?php

namespace PhalconPlus\App\Engine;

use PhalconPlus\App\App as SuperApp;
use Phalcon\Di\Injectable;
use Phalcon\CLI\Console as TaskHandler;
use Phalcon\Cli\Task;

class Task extends Injectable implements \PhalconPlus\App\Engine\AppEngine
{

    protected $app = null;


    protected $handler = null;


    /**
     * @param \PhalconPlus\App\App $app
     * @param BaseApplication $handler
     */
    public function __construct(\PhalconPlus\App\App $app, BaseApplication $handler = null)
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
    public function getHandler()
    {
    }

}
