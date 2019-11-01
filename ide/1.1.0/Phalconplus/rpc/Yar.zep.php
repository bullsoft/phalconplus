<?php

namespace PhalconPlus\Rpc;

use Phalcon\DiInterface;

class Yar extends Phalcon\Application
{

    protected $serviceObj = null;


    protected $requestArgs = '';


    protected $responseBody = 'not supported http method';



    public function getServiceObj()
    {
    }


    public function getRequestArgs()
    {
    }


    public function getResponseBody()
    {
    }

    /**
     * @param \Phalcon\DiInterface $di
     */
    public function __construct(\Phalcon\DiInterface $di = null)
    {
    }


    public function handle()
    {
    }

}
