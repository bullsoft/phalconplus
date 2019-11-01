<?php

namespace PhalconPlus\Db\UnitOfWork;

use \PhalconPlus\Db\UnitOfWork;

class Field extends \PhalconPlus\Db\UnitOfWork\AbstractValue
{

    protected $model = null;


    protected $attr = '';


    /**
     * @param \Phalcon\Mvc\Model $model
     * @param string $attr
     */
    public function __construct(\Phalcon\Mvc\Model $model, string $attr)
    {
    }

    /**
     * @param \\PhalconPlus\Db\UnitOfWork $unitwork
     */
    public function getValue(\\PhalconPlus\Db\UnitOfWork $unitwork)
    {
    }

    /**
     * @param \\PhalconPlus\Db\UnitOfWork $unitwork
     */
    public function getField(\\PhalconPlus\Db\UnitOfWork $unitwork)
    {
    }


    public function __toString()
    {
    }

}
