<?php

namespace PhalconPlus\Base;

class Service
{
    /**
     * @var <\Phalcon\DI>
     */
    protected $di = null;


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
     * @return \Phalcon\DI
     */
    protected function getDI(): \Phalcon\DI
    {
    }

    /**
     * @param string $key
     */
    protected function __get(string $key)
    {
    }

}
