<?php

namespace PhalconPlus\Logger\Adapter;

use PhalconPlus\Assert\Assertion;
use Phalcon\Logger\AdapterInterface;

class FilePlus extends Phalcon\Logger\Adapter\File
{

    private $type2Handler = array();


    private $type2Ext = array();


    private $mode;


    private $_path;


    private $_options;


    private $_fileHandler;


    /**
     * @param string $filePath
     * @param array $options
     */
    public function __construct(string $filePath, array $options = array())
    {
    }

    /**
     * @param string $filePath
     */
    private function open(string $filePath)
    {
    }

    /**
     * @param mixed $type
     * @param mixed $message
     * @param array $context
     * @return \Phalcon\Logger\AdapterInterface
     */
    public function log($type, $message = null, array $context = null): AdapterInterface
    {
    }

    /**
     * @param string $ext
     * @param array $types
     */
    public function registerExtension(string $ext, array $types)
    {
    }

    /**
     * @return bool
     */
    public function close(): bool
    {
    }

    /**
     * @param string $key
     * @return string
     */
    public function getProcessorVar(string $key): string
    {
    }

    /**
     * @param string $property
     */
    public function __get(string $property)
    {
    }


    public function __destruct()
    {
    }


    public function __wakeup()
    {
    }

}
