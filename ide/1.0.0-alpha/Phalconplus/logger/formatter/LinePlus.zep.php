<?php

namespace PhalconPlus\Logger\Formatter;


class LinePlus extends Phalcon\Logger\Formatter implements \Phalcon\Logger\FormatterInterface
{

    private $processors = array();


    private $formatString = "[%date%][%type%] %message%";


    /**
     * @param string $formatString
     */
    public function __construct($formatString) {}

    /**
     * @param string $message
     * @param mixed $type
     * @param mixed $date
     * @param mixed $context
     */
    public function format($message, $type, $date, $context = array()) {}

    /**
     * @param string $name
     * @param \PhalconPlus\Logger\Processor\AbstractProcessor $processor
     */
    public function addProcessor($name, \PhalconPlus\Logger\Processor\AbstractProcessor $processor) {}

    /**
     * @param string $key
     */
    public function __get($key) {}

}
