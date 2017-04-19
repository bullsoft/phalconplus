<?php

namespace PhalconPlus\RPC\Client;


abstract class AbstractClient
{

    /**
     * @param array $rawData
     */
    abstract public function callByObject(array $rawData);

}
