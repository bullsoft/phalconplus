<?php

namespace PhalconPlus\Base;

use PhalconPlus\Assert\Assertion;

class ProtoOrderBy extends \PhalconPlus\Base\ProtoBuffer
{
    /**
     * @required
     */
    protected $property;

    /**
     * @required
     */
    protected $direction;

    /**
     * @optional
     */
    private $alias = '';



    public function getProperty()
    {
    }

    /**
     * @param string $property
     */
    public function setProperty(string $property)
    {
    }

    /**
     * @param \PhalconPlus\Enum\OrderByDirection $orderBy
     */
    public function setDirection(\PhalconPlus\Enum\OrderByDirection $orderBy)
    {
    }


    public function getDirection()
    {
    }


    public function getAlias()
    {
    }

    /**
     * @param string $alias
     */
    public function setAlias(string $alias)
    {
    }


    public function __toString()
    {
    }

}
