<?php

namespace PhalconPlus\Rpc\Server;

use PhalconPlus\Rpc\Server\AbstractServer;

class SimpleServer extends AbstractServer
{

    /**
     * @param \Phalcon\DI $di
     */
    final public function __construct(\Phalcon\DI $di)
    {
    }


    protected function onConstruct()
    {
    }

    /**
     * @param string $property
     */
    public function __get(string $property)
    {
    }

}
