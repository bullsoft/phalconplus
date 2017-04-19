<?php

namespace PhalconPlus\Logger\Processor;


class Trace extends \PhalconPlus\Logger\Processor\AbstractProcessor
{

    const T_FILE = 0x0001;


    const T_CLASS = 0x0010;


    private $skipClassesPartials = array();


    private $mode = self::T_FILE;


    /**
     * @param int $mode
     * @param array $skipClassesPartials
     */
    public function __construct($mode = self::T_FILE, array $skipClassesPartials = array()) {}


    public function __toString() {}

}
