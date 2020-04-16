<?php

namespace PhalconPlus\Logger\Processor;

class Trace extends \PhalconPlus\Logger\Processor\AbstractProcessor
{

    const T_FILE = 0x0001;


    const T_CLASS = 0x0010;


    private $skipClassesPartials = array();


    private $mode = self::T_FILE;


    private $limit = 15;


    /**
     * @param int $mode
     * @param array $skipClassesPartials
     */
    public function __construct(int $mode = self::T_FILE, array $skipClassesPartials = array())
    {
    }

    /**
     * @param int $limit
     */
    public function setLimit(int $limit = 15)
    {
    }


    public function __toString()
    {
    }

}
