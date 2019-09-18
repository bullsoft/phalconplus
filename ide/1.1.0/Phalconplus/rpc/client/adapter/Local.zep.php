<?php

namespace PhalconPlus\Rpc\Client\Adapter;


class Local extends \PhalconPlus\Rpc\Client\AbstractClient
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
    private function callByParams(string $service, string $method, \PhalconPlus\Base\ProtoBuffer $request): ProtoBuffer {}

    /**
     * @param array $rawData
     */
    public function callByObject(array $rawData) {}

}
