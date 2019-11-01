<?php

namespace PhalconPlus\Rpc\Client\Adapter;

use PhalconPlus\Rpc\Client\AbstractClient;
use PhalconPlus\Curl\Curl;

class Curl extends AbstractClient
{

    private $remoteServerUrl;


    private $client;


    private $response;



    public function getResponse()
    {
    }

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

}
