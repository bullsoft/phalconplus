<?php

namespace PhalconPlus\App\Engine;

use PhalconPlus\App\App as SuperApp;
use PhalconPlus\App\Module\AbstractModule as AppModule;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\Di\Injectable;
use Phalcon\Di\DiInterface;
use Phalcon\Application\AbstractApplication as BaseApplication;
use Phalcon\Cli\Console as TaskHandler;
use Phalcon\Cli\Task;

class Cli extends \PhalconPlus\App\Engine\AbstractEngine
{

    /**
     * @param \PhalconPlus\App\Module\AbstractModule $appModule
     * @param \Phalcon\Application\AbstractApplication $handler
     */
    public function __construct(\PhalconPlus\App\Module\AbstractModule $appModule, \Phalcon\Application\AbstractApplication $handler = null)
    {
    }

    /**
     * @param array $argv
     * @param \Phalcon\Di\DiInterface $di
     * @return Task
     */
    public function exec(array $argv, \Phalcon\Di\DiInterface $di = null): Task
    {
    }

}
