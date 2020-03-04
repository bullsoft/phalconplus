<?php

namespace PhalconPlus\Mvc;

use Phalcon\Mvc\Application as BaseApplication;
use Psr\Http\Message\ServerRequestInterface;
use Phalcon\Http\ResponseInterface;
use Phalcon\Http\Response as BaseResponse;
use PhalconPlus\Http\PsrResponseFactory;
use PhalconPlus\Http\NonPsrRequest;
use PhalconPlus\Base\Exception as BaseException;
use Phalcon\DiInterface;

class PsrApplication extends Phalcon\Mvc\Application
{

    protected $psrRequest = null;


    protected $nativeRequest = null;


    /**
     * @param mixed $psrRequest
     */
    public function setPsrRequest($psrRequest)
    {
    }


    public function getPsrRequest()
    {
    }


    public function getNativeRequest()
    {
    }

    /**
     * @param \Psr\Http\Message\ServerRequestInterface $psrRequest
     * @param \Phalcon\DiInterface $dependencyInjector
     */
    public function __construct(\Psr\Http\Message\ServerRequestInterface $psrRequest, \Phalcon\DiInterface $dependencyInjector = null)
    {
    }


    public function __destruct()
    {
    }

    /**
     * @param string $uri
     * @return ResponseInterface
     */
    public function handle(string $uri = null): ResponseInterface
    {
    }

}
