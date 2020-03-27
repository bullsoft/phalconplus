<?php

namespace PhalconPlus\App\Driver;

use PhalconPlus\App\App as SuperApp;
use Phalcon\Di\Injectable;
use Phalcon\CLI\Console as TaskHandler;
use Phalcon\Cli\Task;

class Task extends Injectable implements \PhalconPlus\App\Driver\AppDriver
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
     * @return AppDriver|Task
     */
    public function exec(array $argv, \Phalcon\DI\FactoryDefault $di = null)
    {
    }

    /**
     * @param object $handler
     * @return AppDriver
     */
    public function setHandler($handler): AppDriver
    {
    }

    /**
     * @return object
     */
    public function getHandler()
    {
    }

}
