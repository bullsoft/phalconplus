<?php

namespace PhalconPlus\Rpc;

use Yar_Server;
use Phalcon\Di\DiInterface;
use Phalcon\Application\AbstractApplication;
use PhalconPlus\Rpc\Server\AbstractServer;
use PhalconPlus\Base\Exception as BaseException;

class YarServerWrapper extends \PhalconPlus\Rpc\AbstractYar
{

    protected $yar = null;


    /**
     * @param \PhalconPlus\Rpc\Server\AbstractServer $obj
     * @return AbstractYar
     */
    public function setServer(\PhalconPlus\Rpc\Server\AbstractServer $obj): AbstractYar
    {
    }

    /**
     * @return bool
     */
    public function handle(): bool
    {
    }

}
