<?php

namespace PhalconPlus\Base;


class Service
{

    protected $di;


    /**
     * @param \Phalcon\DI $di
     */
    final public function __construct(\Phalcon\DI $di) {}


    protected function onConstruct() {}

    /**
     * @return \Phalcon\DI
     */
    protected function getDI() {}

    /**
     * @param string $key
     */
    protected function __get($key) {}

}
