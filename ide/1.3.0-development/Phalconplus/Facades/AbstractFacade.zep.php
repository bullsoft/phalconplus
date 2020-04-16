<?php

namespace PhalconPlus\Facades;

use Phalcon\Di;
use PhalconPlus\App\App as SuperApp;
use PhalconPlus\Base\Exception as BaseException;

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
     * @return SuperApp
     */
    public static function app(): SuperApp
    {
    }

    /**
     * @return SuperApp
     */
    public static function getApp(): SuperApp
    {
    }


    public static function itself()
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
