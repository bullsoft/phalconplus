<?php

namespace PhalconPlus\Facades;

use Phalcon\Di;
use PhalconPlus\App\App as SuperApp;

abstract class AbstractFacade
{

    static private $app = null;


    /**
     * @return string
     */
    abstract protected function getName(): string;

    /**
     * @param \Phalcon\Di $di
     * @return mixed
     */
    protected function resolve(\Phalcon\Di $di): ?Di
    {
    }

    /**
     * @param \PhalconPlus\App\App $app
     */
    public static function setApp(\PhalconPlus\App\App $app)
    {
    }

    /**
     * @param string $method
     * @param array $params
     */
    public static function __callStatic(string $method, array $params)
    {
    }

}
