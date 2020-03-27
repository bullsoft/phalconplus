<?php

namespace PhalconPlus\Base;

use PhalconPlus\Assert\Assertion as Assert;
use PhalconPlus\Enum\OrderByDirection;

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
    protected $alias = '';


    /**
     * @return string
     */
    public function getProperty(): string
    {
    }

    /**
     * @param string $property
     * @return ProtoOrderBy
     */
    public function setProperty(string $property): ProtoOrderBy
    {
    }

    /**
     * @param \PhalconPlus\Enum\OrderByDirection $orderBy
     * @return ProtoOrderBy
     */
    public function setDirection(\PhalconPlus\Enum\OrderByDirection $orderBy): ProtoOrderBy
    {
    }

    /**
     * @param string $alias
     * @return ProtoOrderBy
     */
    public function setAlias(string $alias): ProtoOrderBy
    {
    }

    /**
     * @return OrderByDirection
     */
    public function getDirection(): OrderByDirection
    {
    }

    /**
     * @return string
     */
    public function getAlias(): string
    {
    }


    public function __toString()
    {
    }

}
