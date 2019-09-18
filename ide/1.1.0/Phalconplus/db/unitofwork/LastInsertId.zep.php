<?php

namespace PhalconPlus\Db\UnitOfWork;


class LastInsertId extends \PhalconPlus\Db\UnitOfWork\AbstractValue
{

    protected $model;


    /**
     * @param \Phalcon\Mvc\Model $model
     */
    public function __construct(\Phalcon\Mvc\Model $model) {}

    /**
     * @param \\PhalconPlus\Db\UnitOfWork $unitwork
     */
    public function getValue(\\PhalconPlus\Db\UnitOfWork $unitwork) {}


    public function __toString() {}

}
