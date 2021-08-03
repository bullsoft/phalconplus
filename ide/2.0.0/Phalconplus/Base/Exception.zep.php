<?php

namespace PhalconPlus\Base;

use PhalconPlus\Assert\Assertion as Assert;
use PhalconPlus\Enum\Sys;

/**
 * throw new Exception("error message");
 * throw new Exception(["error message", "hello"]);
 * throw new Exception(["error message", ["foo", "bar"]]);
 * throw new Exception(["error message", "text" => "", "args" => ["foo", "bar"]]);
 */
class Exception extends \Exception
{

    protected $level = \Phalcon\Logger::DEBUG;


    protected $info;


    /**
     * @param mixed $info
     * @param int $code
     */
    public function __construct($info = null, int $code = 0)
    {
    }


    public function getLevel()
    {
    }

    /**
     * @param mixed $level
     */
    public function setLevel($level)
    {
    }


    public function getInfo()
    {
    }

}
