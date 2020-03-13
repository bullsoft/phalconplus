<?php

namespace PhalconPlus\Rpc\Client\Adapter;

use PhalconPlus\Rpc\Client\AbstractClient;

class Remote extends AbstractClient
{

    private $remoteServerUrl = '';


    private $client;


    /**
     * @param array $remoteServerUrl
     * @param array $opts
     */
    public function __construct(array $remoteServerUrl, array $opts = array())
    {
    }

    /**
     * @param array $rawData
     */
    public function callByObject(array $rawData)
    {
    }

    /**
     * @param string $method
     * @param array $args
     */
    public function __call(string $method, array $args)
    {
    }

}
