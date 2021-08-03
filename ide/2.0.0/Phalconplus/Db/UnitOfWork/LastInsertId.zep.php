<?php

namespace PhalconPlus\Db\UnitOfWork;

use PhalconPlus\Db\UnitOfWork;
use PhalconPlus\Base\Exception as BaseException;
use PhalconPlus\Contracts\Stringer;

class LastInsertId extends \PhalconPlus\Db\UnitOfWork\AbstractValue implements \PhalconPlus\Contracts\Stringer
{

    protected $model;


    /**
     * @param \Phalcon\Mvc\Model $model
     */
    public function __construct(\Phalcon\Mvc\Model $model)
    {
    }

    /**
     * @param \PhalconPlus\Db\UnitOfWork $unitwork
     */
    public function getValue(\PhalconPlus\Db\UnitOfWork $unitwork)
    {
    }

    /**
     * @return string
     */
    public function __toString(): string
    {
    }

}
