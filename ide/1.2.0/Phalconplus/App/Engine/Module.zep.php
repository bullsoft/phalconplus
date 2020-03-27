<?php

namespace PhalconPlus\App\Engine;

use PhalconPlus\App\App as SuperApp;
use Phalcon\Di\Injectable;
use Phalcon\Application as BaseApplication;
use Phalcon\Mvc\Application as MvcHandler;
use Phalcon\Http\ResponseInterface as HttpResponse;

class Module extends Injectable implements \PhalconPlus\App\Engine\AppEngine
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
     * @return HttpResponse|AppEngine
     */
    public function exec($request = null)
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
