<?php

namespace PhalconPlus\Logger;

use PhalconPlus\Logger\Processor\AbstractProcessor;

class MultiPleFile extends Phalcon\Logger\Multiple
{

    protected $processors = array();



    public function getProcessors()
    {
    }

    /**
     * @param array $options
     */
    public function __construct(array $options)
    {
    }

    /**
     * @param string $name
     * @param \PhalconPlus\Logger\Processor\AbstractProcessor $processor
     */
    public function addProcessor(string $name, \PhalconPlus\Logger\Processor\AbstractProcessor $processor)
    {
    }

    /**
     * @param string $name
     * @return string
     */
    public function getProcessorVar(string $name): string
    {
    }

    /**
     * @param string $property
     * @return string
     */
    public function __get(string $property): string
    {
    }

    /**
     * Sends a message to each registered logger
     *
     * @param mixed $type
     * @param mixed $message
     * @param array $context
     */
    public function log($type, $message = null, array $context = null)
    {
    }

}
