<?php

namespace PhalconPlus\RPC\Server;


abstract class AbstractServer
{

    protected $di = null;


    protected $config = null;


    protected $phpOnly = false;


    protected $eventsManager = null;


    /**
     * @param \Phalcon\DI $di
     */
    abstract public function __construct(\Phalcon\DI $di);

    /**
     * @param string $service
     * @param string $method
     * @param mixed $request
     */
    protected function callByParams($service, $method, $request) {}

    /**
     * @param array rawData
     * <code>
     *     rawData = ["service":"Demo", "method":"demo", "args": <ProtoBuffer>, "logId": "234fdfaf3334"]
     * </code>
     * @throw \Exception
     *
     * @param array $rawData
     * @return <ProtoBuffer>
     */
    public function callByObject(array $rawData) {}

}
