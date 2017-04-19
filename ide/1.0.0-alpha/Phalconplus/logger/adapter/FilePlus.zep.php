<?php

namespace PhalconPlus\Logger\Adapter;


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
    public function __construct($filePath, array $options = array()) {}

    /**
     * @param string $filePath
     */
    private function open($filePath) {}

    /**
     * @param string $message
     * @param int $type
     * @param array $context
     */
    public function log($message, $type = \Phalcon\Logger::DEBUG, array $context = null) {}

    /**
     * @param string $ext
     * @param array $types
     */
    public function registerExtension($ext, array $types) {}


    public function close() {}


    public function __wakeup() {}

}
