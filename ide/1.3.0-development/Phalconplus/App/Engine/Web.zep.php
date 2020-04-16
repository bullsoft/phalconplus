<?php

namespace PhalconPlus\App\Engine;

use PhalconPlus\App\App as SuperApp;
use Phalcon\Di\Injectable;
use Phalcon\Application as BaseApplication;
use PhalconPlus\App\Module\AbstractModule as AppModule;
use Phalcon\Mvc\Application as MvcHandler;
use Phalcon\Http\ResponseInterface as HttpResponse;

class Web extends Injectable implements \PhalconPlus\App\Engine\AppEngine
{

    protected $appModule = null;


    protected $handler = null;


    /**
     * @param \PhalconPlus\App\Module\AbstractModule $appModule
     * @param \Phalcon\Application $handler
     */
    public function __construct(\PhalconPlus\App\Module\AbstractModule $appModule, \Phalcon\Application $handler = null)
    {
    }

    /**
     * @request a uri string (for \Phalcon\Mvc\Application) or Psr\Http\Message\Request
     * @param mixed $uri
     * @return HttpResponse
     */
    public function exec($uri = null): HttpResponse
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
