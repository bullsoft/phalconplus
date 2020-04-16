<?php

namespace PhalconPlus\Rpc\Client\Adapter;

use PhalconPlus\Rpc\Client\AbstractClient;
use PhalconPlus\Base\ProtoBuffer;
use PhalconPlus\Base\Exception as BaseException;

class Local extends AbstractClient
{

    private $config;


    private $di;


    /**
     * @param \Phalcon\DI $di
     */
    public function __construct(\Phalcon\DI $di)
    {
    }

    /**
     * @param string $service
     * @param string $method
     * @param mixed $request
     */
    private function callByParams(string $service, string $method, $request)
    {
    }

    /**
     * @param array $rawData
     */
    public function callByObject(array $rawData)
    {
    }

}
