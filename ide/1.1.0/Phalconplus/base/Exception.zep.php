<?php

namespace PhalconPlus\Base;

use PhalconPlus\Assert\Assertion as Assert;

/**
 * throw new Exception("error message");
 * throw new Exception(["error message", ["foo", "bar"]]);
 */
class Exception extends \Exception
{

    protected $message = '';


    protected $level = \Phalcon\Logger::DEBUG;


    protected $code = 0;


    protected $info = array();



    public function getInfo()
    {
    }

    /**
     * @param mixed $info
     * @param mixed $logger
     */
    public function __construct($info = '', $logger = null)
    {
    }


    public function getLevel()
    {
    }

    /**
     * @param mixed $code
     */
    public function setCode($code)
    {
    }

    /**
     * @param mixed $level
     */
    public function setLevel($level)
    {
    }

    /**
     * @param mixed $msg
     */
    public function setMessage($msg)
    {
    }

}
