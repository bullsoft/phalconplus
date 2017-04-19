<?php

namespace PhalconPlus\Db;


class Mysql
{

    const RETRY_TIMES = 5;


    const RETRY_INTERVAL = 100000;


    private $di = null;


    private $descriptor = array();


    private $retryTimes = self::RETRY_TIMES;


    private $retryInterval = self::RETRY_INTERVAL;


    private $name;


    private $connection = null;


    private $connected = false;


    /**
     * @param \Phalcon\DI $di
     * @param string $name
     */
    public function __construct(\Phalcon\DI $di, $name) {}

    /**
     * @return \Phalcon\Db\Adapter\Pdo\Mysql
     */
    public function getConnection() {}

}
