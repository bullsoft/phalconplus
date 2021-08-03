<?php

namespace PhalconPlus\App\Engine;

use PhalconPlus\App\App as SuperApp;
use Phalcon\Di\Injectable;
use Phalcon\Application\AbstractApplication as BaseApplication;
use PhalconPlus\App\Module\AbstractModule as AppModule;
use Phalcon\Http\ResponseInterface as HttpResponse;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\Mvc\Application as MvcHandler;
use PhalconPlus\Mvc\PsrApplication as PsrHandler;
use Psr\Http\Message\ServerRequestInterface;

class Web extends \PhalconPlus\App\Engine\AbstractEngine
{

    /**
     * @param \PhalconPlus\App\Module\AbstractModule $appModule
     * @param \Phalcon\Application\AbstractApplication $handler
     */
    public function __construct(\PhalconPlus\App\Module\AbstractModule $appModule, \Phalcon\Application\AbstractApplication $handler = null)
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

}
