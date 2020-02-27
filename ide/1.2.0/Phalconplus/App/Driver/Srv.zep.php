<?php

namespace PhalconPlus\App\Driver;

use PhalconPlus\App\App as SuperApp;
use PhalconPlus\Rpc\Server\AbstractServer;
use PhalconPlus\Rpc\Server\SimpleServer;
use Phalcon\Di\Injectable;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\Http\Response as HttpResponse;
use Yar_Server;

class Srv extends Injectable implements \PhalconPlus\App\Driver\AppDriver
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
     * @return HttpResponse|AppDriver
     */
    public function exec()
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
