<?php

namespace PhalconPlus\Rpc;

use Phalcon\Di\DiInterface;
use PhalconPlus\Rpc\Server\AbstractServer;
use Phalcon\Application\AbstractApplication;

class AbstractYar extends AbstractApplication
{

    const NAME = 'backendSrv';


    /**
     * @return AbstractServer
     */
    public function getServer(): AbstractServer
    {
    }

    /**
     * @param \PhalconPlus\Rpc\Server\AbstractServer $obj
     * @return AbstractYar
     */
    abstract public function setServer(\PhalconPlus\Rpc\Server\AbstractServer $obj): AbstractYar;

    /**
     * @return bool
     */
    abstract public function handle(): bool;

}
