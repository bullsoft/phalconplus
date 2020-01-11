<?php

namespace PhalconPlus\Rpc\Client\Adapter;

use PhalconPlus\Rpc\Client\AbstractClient;
use PhalconPlus\Curl\Curl as HttpClient;

class Curl extends AbstractClient
{

    private $remoteServerUrl;


    private $client;


    private $response;


    private $formater = 'msgpack';



    public function getResponse()
    {
    }

    /**
     * @param array $remoteServerUrl
     * @param array $opts
     * @param string $formater
     */
    public function __construct(array $remoteServerUrl, array $opts = array(), string $formater = '')
    {
    }

    /**
     * @param array $rawData
     */
    public function callByObject(array $rawData)
    {
    }

}
