<?php

namespace PhalconPlus\App\Driver;

use PhalconPlus\App\App as SuperApp;
use Phalcon\Di\Injectable;
use Phalcon\CLI\Console as TaskHandler;
use Phalcon\Cli\Task;

class Task extends Injectable implements \PhalconPlus\App\Driver\AppDriver
{

    protected $app;


    protected $handler;


    protected $autoHandle = true;


    /**
     * @param \PhalconPlus\App\App $app
     * @param bool $autoHandle
     */
    public function __construct(\PhalconPlus\App\App $app, bool $autoHandle = true)
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
     * @param bool $autoHandle
     * @return AppDriver
     */
    public function setHandler($handler, bool $autoHandle = false): AppDriver
    {
    }

    /**
     * @return object
     */
    public function getHandler()
    {
    }

}
