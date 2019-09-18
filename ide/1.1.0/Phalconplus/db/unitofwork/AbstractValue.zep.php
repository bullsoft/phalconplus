<?php

namespace PhalconPlus\Db\UnitOfWork;


abstract class AbstractValue
{

    /**
     * @param \\PhalconPlus\Db\UnitOfWork $unitwork
     */
    abstract public function getValue(\\PhalconPlus\Db\UnitOfWork $unitwork);

}
