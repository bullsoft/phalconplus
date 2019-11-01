<?php

namespace PhalconPlus\Rpc\Server;

use PhalconPlus\Base\ProtoBuffer;

abstract class AbstractServer
{

    protected $di = null;


    protected $phpOnly = false;


    protected $eventsManager = null;



    public function getDi()
    {
    }


    public function getPhpOnly()
    {
    }

    /**
     * @param \Phalcon\DI $di
     */
    abstract public function __construct(\Phalcon\DI $di);

    /**
     * @param string $service
     * @param string $method
     * @param mixed $request
     */
    protected function callByParams(string $service, string $method, $request)
    {
    }

    /**
     * @param array $rawData * <code>
     *     rawData = ["service":"Demo", "method":"demo", "args": <ProtoBuffer>, "logId": "234fdfaf3334"]
     * </code>
     * @return <ProtoBuffer>
     * @throw \Exception
     *
     */
    public function callByObject(array $rawData)
    {
    }

}
