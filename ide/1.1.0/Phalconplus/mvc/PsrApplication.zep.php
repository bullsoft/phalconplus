<?php

namespace PhalconPlus\Mvc;


class PsrApplication extends Phalcon\Mvc\Application
{

    protected $psrRequest = null;


    protected $nativeRequest = null;


    /**
     * @param mixed $psrRequest
     */
    public function setPsrRequest($psrRequest) {}


    public function getPsrRequest() {}


    public function getNativeRequest() {}

    /**
     * @param \Phalcon\DiInterface $dependencyInjector
     * @param \Psr\Http\Message\ServerRequestInterface $psrRequest
     */
    public function __construct(\Phalcon\DiInterface $dependencyInjector = null, \Psr\Http\Message\ServerRequestInterface $psrRequest = null) {}


    public function __destruct() {}

    /**
     * @param string $uri
     * @return bool|\Psr\Http\Message\ResponseInterface
     */
    public function handle(string $uri = null) {}

    /**
     * @param \Phalcon\Http\Response $response
     */
    protected function mapHeaders(\Phalcon\Http\Response $response) {}

}
