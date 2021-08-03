<?php

namespace PhalconPlus\Db;

use SplObjectStorage;
use PhalconPlus\Base\Exception;
use Phalcon\Mvc\Model\Transaction\Manager as TxManager;
use Phalcon\Mvc\Model\Transaction\Failed as TxFailed;
use PhalconPlus\Db\UnitOfWork\AbstractValue;
use Phalcon\Mvc\Model;
use Phalcon\Mvc\Model\Resultset;

class UnitOfWork
{

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
    public function __construct($dbServiceName)
    {
    }

    /**
     * @param mixed $name
     * @param \PhalconPlus\Base\Model $model
     * @param array $initial_data
     */
    public function save($name, \PhalconPlus\Base\Model $model, array $initial_data = [])
    {
    }

    /**
     * @param mixed $name
     * @param \PhalconPlus\Base\Model $model
     * @param array $initial_data
     */
    public function insert($name, \PhalconPlus\Base\Model $model, array $initial_data = [])
    {
    }

    /**
     * @param \Phalcon\Mvc\Model | \Phalcon\Mvc\Model\Resultset $model
     * @param mixed $name
     * @param array $initial_data
     */
    public function update($name, $model, array $initial_data = [])
    {
    }

    /**
     * @param \Phalcon\Mvc\Model | \Phalcon\Mvc\Model\Resultset $model
     * @param mixed $name
     */
    public function delete($name, $model)
    {
    }

    /**
     * @param mixed $model
     * @param mixed $info
     */
    protected function attach($model, $info)
    {
    }

    /**
     * @param mixed $model
     */
    public function detach($model)
    {
    }

    /**
     * @return bool
     */
    public function exec(): bool
    {
    }

    /**
     * @param \Phalcon\Mvc\Model $model
     * @param array $info
     */
    public function execInsert(\Phalcon\Mvc\Model $model, array $info)
    {
    }

    /**
     * @param mixed $model
     * @param array $info
     */
    public function execUpdate($model, array $info = [])
    {
    }

    /**
     * @param mixed $model
     * @param array $info
     */
    public function execDelete($model, array $info = [])
    {
    }


    public function getObjects()
    {
    }


    public function getInserted()
    {
    }


    public function getUpdated()
    {
    }


    public function getDeleted()
    {
    }


    public function getException()
    {
    }


    public function getFailed()
    {
    }

}
