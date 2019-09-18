<?php

namespace PhalconPlus\Rpc\Server;


abstract class AbstractServer
{

    protected $di = null;


    protected $phpOnly = false;


    protected $eventsManager = null;



    public function getDi() {}


    public function getPhpOnly() {}

    /**
     * @param \Phalcon\DI $di
     */
    abstract public function __construct(\Phalcon\DI $di);

    /**
     * @param string $service
     * @param string $method
     * @param mixed $request
     */
    protected function callByParams(string $service, string $method, $request) {}

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
