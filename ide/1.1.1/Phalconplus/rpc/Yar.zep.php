<?php

namespace PhalconPlus\Rpc;

use Phalcon\DiInterface;

class Yar extends Phalcon\Application
{

    protected $serviceObj = null;


    protected $requestArgs = '';


    protected $responseBody = 'not supported http method';


    protected $formater = 'msgpack';


    protected $encoder = 'msgpack_pack';



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
     * @param string $formater
     */
    public function __construct(\Phalcon\DiInterface $di = null, string $formater = '')
    {
    }


    public function handle()
    {
    }

}
