<?php

namespace PhalconPlus\Base;

/**
 * throw new Exception("error message");
 * throw new Exception(["error message", ["foo", "bar"]]);
 */
class Exception extends \Exception
{

    protected $message = "";


    protected $level = \Phalcon\Logger::DEBUG;


    protected $code = 0;


    /**
     * @param mixed $info
     * @param \Phalcon\Logger\Adapter $logger
     */
    public function __construct($info = "", \Phalcon\Logger\Adapter $logger = null) {}


    public function getLevel() {}

    /**
     * @param mixed $code
     */
    public function setCode($code) {}

    /**
     * @param mixed $level
     */
    public function setLevel($level) {}

    /**
     * @param mixed $msg
     */
    public function setMessage($msg) {}

}
