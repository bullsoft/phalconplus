<?php

namespace PhalconPlus\RPC\Client\Adapter;


class Remote extends \PhalconPlus\RPC\Client\AbstractClient
{

    private $remoteServerUrl;


    private $client;


    /**
     * @param array $remoteServerUrl
     * @param array $opts
     */
    public function __construct(array $remoteServerUrl, array $opts = array()) {}

    /**
     * @param array $rawData
     */
    public function callByObject(array $rawData) {}

    /**
     * @param string $method
     * @param array $args
     */
    public function __call($method, array $args) {}

}
