<?php

namespace PhalconPlus\App\Driver;

use PhalconPlus\App\App as SuperApp;
use Phalcon\Di\Injectable;
use Phalcon\Application as BaseApplication;
use Phalcon\Mvc\Application as MvcHandler;
use Phalcon\Http\Response as HttpResponse;

class Module extends Injectable implements \PhalconPlus\App\Driver\AppDriver
{

    protected $app = null;


    protected $handler = null;


    /**
     * @param \PhalconPlus\App\App $app
     * @param \Phalcon\Application $handler
     */
    public function __construct(\PhalconPlus\App\App $app, \Phalcon\Application $handler = null)
    {
    }

    /**
     * @request a uri string (for \Phalcon\Mvc\Application) or Psr\Http\Message\Request
     * @param mixed $request
     * @return HttpResponse|AppDriver
     */
    public function exec($request = null)
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
