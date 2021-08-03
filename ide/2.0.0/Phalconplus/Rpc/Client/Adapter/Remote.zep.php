<?php

namespace PhalconPlus\Rpc\Client\Adapter;

use PhalconPlus\Rpc\Client\AbstractClient;
use PhalconPlus\Base\Exception as BaseException;

class Remote extends AbstractClient
{

    private $remoteServerUrl = '';


    private $client = null;


    /**
     * @param array $remoteServerUrl
     * @param array $opts
     */
    public function __construct(array $remoteServerUrl, array $opts = [])
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
