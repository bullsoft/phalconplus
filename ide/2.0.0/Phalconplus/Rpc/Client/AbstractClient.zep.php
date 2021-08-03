<?php

namespace PhalconPlus\Rpc\Client;

abstract class AbstractClient
{

    protected $namePrefix = '';


    protected $di = null;


    /**
     * @param string $prefix
     */
    public function setNamePrefix(string $prefix)
    {
    }

    /**
     * @param \Phalcon\DI $di
     * @return AbstractClient
     */
    public function setDI(\Phalcon\DI $di): AbstractClient
    {
    }

    /**
     * @param array $rawData
     */
    abstract public function callByObject(array $rawData);

}
