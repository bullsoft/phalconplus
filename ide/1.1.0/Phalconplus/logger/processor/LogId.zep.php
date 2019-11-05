<?php

namespace PhalconPlus\Logger\Processor;

class LogId extends \PhalconPlus\Logger\Processor\AbstractProcessor
{

    static private $id = '';


    /**
     * @param mixed $len
     */
    public function __construct($len = 18)
    {
    }

    /**
     * @param string $logId
     */
    public static function setId(string $logId)
    {
    }


    public function __toString()
    {
    }

}
