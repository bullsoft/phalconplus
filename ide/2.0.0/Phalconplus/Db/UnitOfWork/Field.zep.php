<?php

namespace PhalconPlus\Db\UnitOfWork;

use PhalconPlus\Db\UnitOfWork;
use PhalconPlus\Base\Exception as BaseException;
use PhalconPlus\Contracts\Stringer;

class Field extends \PhalconPlus\Db\UnitOfWork\AbstractValue implements \PhalconPlus\Contracts\Stringer
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
     * @param \PhalconPlus\Db\UnitOfWork $unitwork
     */
    public function getValue(\PhalconPlus\Db\UnitOfWork $unitwork)
    {
    }

    /**
     * @param \PhalconPlus\Db\UnitOfWork $unitwork
     */
    public function getField(\PhalconPlus\Db\UnitOfWork $unitwork)
    {
    }

    /**
     * @return string
     */
    public function __toString(): string
    {
    }

}
