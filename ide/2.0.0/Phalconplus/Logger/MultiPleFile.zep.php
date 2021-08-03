<?php

namespace PhalconPlus\Logger;

use PhalconPlus\Logger\Processor\AbstractProcessor;
use Phalcon\Logger\Adapter\Stream;
use Phalcon\Logger\Formatter\FormatterInterface;
use PhalconPlus\Base\Exception as BaseException;

class MultiPleFile extends Phalcon\Logger
{

    protected $processors = [];


    protected $options = [];



    public function getProcessors()
    {
    }

    /**
     *  options = [
     *          [
     *               "name" => "local",
     *               "filePath" => "/path/to/logger/file.log",
     *               "level"  => \Phalcon\Logger::DEBUG,
     *          ],
     *          [
     *               "name" => "remote",
     *               "filePath" => "/path/to/logger/file.log",
     *               "level" => \Phalcon\Logger::CUSTOM，
     *          ],
     *  ]
     *
     * @param array $options
     */
    public function __construct(array $options)
    {
    }

    /**
     * @param string $name
     * @param \PhalconPlus\Logger\Processor\AbstractProcessor $processor
     * @return MultiPleFile
     */
    public function addProcessor(string $name, \PhalconPlus\Logger\Processor\AbstractProcessor $processor): MultiPleFile
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
     * @param int $level
     * @param string $message
     * @param array $context
     * @return bool
     */
    protected function addMessage(int $level, string $message, array $context = []): bool
    {
    }

    /**
     * @param \Phalcon\Logger\Formatter\FormatterInterface $formatter
     * @return MultiPleFile
     */
    public function setFormatter(\Phalcon\Logger\Formatter\FormatterInterface $formatter): MultiPleFile
    {
    }

}
