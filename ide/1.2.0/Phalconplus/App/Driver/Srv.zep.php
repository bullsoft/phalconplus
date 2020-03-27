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
     * @return HttpResponse|AppDriver
     */
    public function exec()
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
