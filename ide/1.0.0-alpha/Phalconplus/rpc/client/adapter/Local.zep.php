<?php

namespace PhalconPlus\RPC\Client\Adapter;


class Local extends \PhalconPlus\RPC\Client\AbstractClient
{

    private $config;


    private $di;


    /**
     * @param \Phalcon\DI $di
     */
    public function __construct(\Phalcon\DI $di) {}

    /**
     * @param string $service
     * @param string $method
     * @param \PhalconPlus\Base\ProtoBuffer $request
     * @return \PhalconPlus\Base\ProtoBuffer
     */
    private function callByParams($service, $method, \PhalconPlus\Base\ProtoBuffer $request) {}

    /**
     * @param array $rawData
     */
    public function callByObject(array $rawData) {}

}
