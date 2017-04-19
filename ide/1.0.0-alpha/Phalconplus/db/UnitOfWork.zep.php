<?php

namespace PhalconPlus\Db;


class UnitOfWork
{

    protected $modelLocator = array();


    protected $dbServiceName;


    protected $objects;


    protected $inserted;


    protected $updated;


    protected $deleted;


    protected $exception;


    protected $failed;


    /**
     * @param mixed $dbServiceName
     */
    public function __construct($dbServiceName) {}

    /**
     * @param mixed $name
     * @param \PhalconPlus\Base\Model $model
     * @param array $initial_data
     */
    public function save($name, \PhalconPlus\Base\Model $model, array $initial_data = array()) {}

    /**
     * @param mixed $name
     * @param \Phalcon\Mvc\Model $model
     * @param array $initial_data
     * @param bool $assign
     */
    public function insert($name, \Phalcon\Mvc\Model $model, array $initial_data = array(), $assign = true) {}

    /**
     * @param mixed $name
     * @param \Phalcon\Mvc\Model $model
     * @param array $initial_data
     * @param bool $assign
     */
    public function update($name, \Phalcon\Mvc\Model $model, array $initial_data = array(), $assign = true) {}

    /**
     * @param mixed $name
     * @param \Phalcon\Mvc\Model $model
     */
    public function delete($name, \Phalcon\Mvc\Model $model) {}

    /**
     * @param mixed $model
     * @param mixed $info
     */
    protected function attach($model, $info) {}

    /**
     * @param mixed $model
     */
    public function detach($model) {}


    public function exec() {}

    /**
     * @param \Phalcon\Mvc\Model $model
     * @param array $info
     */
    public function execInsert(\Phalcon\Mvc\Model $model, array $info) {}

    /**
     * @param \Phalcon\Mvc\Model $model
     * @param array $info
     */
    public function execUpdate(\Phalcon\Mvc\Model $model, array $info = array()) {}

    /**
     * @param \Phalcon\Mvc\Model $model
     * @param array $info
     */
    public function execDelete(\Phalcon\Mvc\Model $model, array $info = array()) {}


    public function getObjects() {}


    public function getInserted() {}


    public function getUpdated() {}


    public function getDeleted() {}


    public function getException() {}


    public function getFailed() {}

}
