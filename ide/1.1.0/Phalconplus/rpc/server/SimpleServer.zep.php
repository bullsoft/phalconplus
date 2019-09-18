<?php

namespace PhalconPlus\Rpc\Server;


class SimpleServer extends \PhalconPlus\Rpc\Server\AbstractServer
{

    /**
     * @param \Phalcon\DI $di
     */
    final public function __construct(\Phalcon\DI $di) {}


    protected function onConstruct() {}

    /**
     * @param string $property
     */
    public function __get(string $property) {}

}
