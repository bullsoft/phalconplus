<?php

namespace PhalconPlus\Mvc;

use Psr\Http\Message\ServerRequestInterface;
use Psr\Http\Message\ResponseInterface as PsrResponseInterface;
use Phalcon\Http\ResponseInterface;
use Phalcon\Http\Response as BaseResponse;
use Phalcon\Di\DiInterface;
use Phalcon\Application\AbstractApplication;
use Phalcon\Mvc\Application as MvcApplication;
use PhalconPlus\Http\PsrResponseFactory;
use PhalconPlus\Http\NonPsrRequest;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\Events\ManagerInterface;

class PsrApplication extends AbstractApplication
{

    protected $app = null;


    /**
     * @param \Phalcon\Di\DiInterface $di
     */
    public function __construct(\Phalcon\Di\DiInterface $di)
    {
    }

    /**
     * @param \Psr\Http\Message\ServerRequestInterface $request
     * @param bool $psr
     * @return ResponseInterface|PsrResponseInterface
     */
    public function handle(\Psr\Http\Message\ServerRequestInterface $request, bool $psr = false)
    {
    }

    /**
     * Sets the events manager
     *
     * @param \Phalcon\Events\ManagerInterface $eventsManager
     * @return void
     */
    public function setEventsManager(\Phalcon\Events\ManagerInterface $eventsManager): void
    {
    }

}
