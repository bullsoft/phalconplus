<?php

namespace PhalconPlus\Enum;


class Exception extends \PhalconPlus\Enum\AbstractEnum
{

    static protected $details;


    /**
     * @param mixed $eCode
     */
    protected static function has($eCode) {}

    /**
     * @param mixed $eCode
     */
    public static function getByCode($eCode) {}

    /**
     * @param mixed $e
     * @param \Phalcon\Logger\Adapter $logger
     */
    public static function newException($e, \Phalcon\Logger\Adapter $logger = null) {}


    public static function exceptionClassPrefix() {}


    public function getMessage() {}


    public function getLevel() {}


    public function getCode() {}

}
