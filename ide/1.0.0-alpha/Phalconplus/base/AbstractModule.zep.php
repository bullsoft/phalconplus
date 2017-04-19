<?php

namespace PhalconPlus\Base;


abstract class AbstractModule
{

    protected $di = null;


    /**
     * @param \Phalcon\DI $di
     */
    public function __construct(\Phalcon\DI $di) {}


    abstract public function registerAutoloaders();


    abstract public function registerServices();

}
