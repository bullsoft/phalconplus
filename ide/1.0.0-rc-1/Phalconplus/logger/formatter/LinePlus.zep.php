<?php

namespace PhalconPlus\Logger\Formatter;


class LinePlus extends Phalcon\Logger\Formatter implements \Phalcon\Logger\FormatterInterface
{

    private $processors = array();


    private $formatString = '[%date%][%type%] %message%';


    /**
     * @param string $formatString
     */
    public function __construct(string $formatString) {}

    /**
     * @param mixed $message
     * @param mixed $type
     * @param mixed $timestamp
     * @param mixed $context
     * @return string|array
     */
    public function format($message, $type, $timestamp, $context = null): string {}

    /**
     * @param string $name
     * @param \PhalconPlus\Logger\Processor\AbstractProcessor $processor
     */
    public function addProcessor(string $name, \PhalconPlus\Logger\Processor\AbstractProcessor $processor) {}

    /**
     * @param string $name
     */
    public function getProcessor(string $name) {}

    /**
     * @param string $key
     */
    public function __get(string $key) {}

}
