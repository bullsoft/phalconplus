<?php

namespace PhalconPlus\Rpc;

use Phalcon\Di\DiInterface;
use PhalconPlus\Rpc\Server\AbstractServer;
use Phalcon\Application\AbstractApplication;
use PhalconPlus\Enum\Sys;
use PhalconPlus\Enum\RunMode;
use PhalconPlus\Base\Exception as BaseException;

class Yar extends \PhalconPlus\Rpc\AbstractYar
{

    protected $formater = 'msgpack';


    protected $encoder = 'msgpack_pack';


    /**
     * @param \Phalcon\Di\DiInterface $di
     * @param string $formater
     */
    public function __construct(\Phalcon\Di\DiInterface $di = null, string $formater = 'json')
    {
    }

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

    /**
     * @param array $vals
     * @return string
     */
    private function defaultResponse(array $vals = []): string
    {
    }

}
