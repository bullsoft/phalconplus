<?php

namespace PhalconPlus\App\Engine;

use PhalconPlus\App\App as SuperApp;
use PhalconPlus\App\Module\AbstractModule as AppModule;
use PhalconPlus\Rpc\Server\AbstractServer;
use PhalconPlus\Rpc\Server\SimpleServer;
use PhalconPlus\Rpc\Yar as YarServerPlus;
use PhalconPlus\Rpc\YarServerWrapper;
use PhalconPlus\Rpc\AbstractYar;
use Phalcon\Application\AbstractApplication as BaseApplication;
use Phalcon\Di\DiInterface;
use Phalcon\Di\Injectable;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\Http\ResponseInterface as HttpResponse;

class Srv extends \PhalconPlus\App\Engine\AbstractEngine
{

    /**
     * @param \PhalconPlus\App\Module\AbstractModule $appModule
     * @param \Phalcon\Application\AbstractApplication $handler
     */
    public function __construct(\PhalconPlus\App\Module\AbstractModule $appModule, \Phalcon\Application\AbstractApplication $handler = null)
    {
    }

    /**
     * @param \Phalcon\Di\DiInterface $di
     * @return AbstractServer
     */
    private function newService(\Phalcon\Di\DiInterface $di): AbstractServer
    {
    }

    /**
     * @return HttpResponse
     */
    public function exec(): HttpResponse
    {
    }

}
