<?php

namespace PhalconPlus\Rpc\Client;

abstract class AbstractClient
{

    protected $namePrefix = '';


    /**
     * @param string $prefix
     */
    public function setNamePrefix(string $prefix)
    {
    }

    /**
     * @param array $rawData
     */
    abstract public function callByObject(array $rawData);

}
