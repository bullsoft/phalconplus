<?php

namespace PhalconPlus\Base;


class ProtoOrderBy extends \PhalconPlus\Base\ProtoBuffer
{
    /**
     * @required
     */
    private $property;

    /**
     * @required
     */
    private $direction;

    /**
     * @optional
     */
    private $alias = "";



    public function getProperty() {}

    /**
     * @param string $property
     */
    public function setProperty($property) {}

    /**
     * @param \PhalconPlus\Enum\OrderByDirection $orderBy
     */
    public function setDirection(\PhalconPlus\Enum\OrderByDirection $orderBy) {}


    public function getDirection() {}


    public function getAlias() {}

    /**
     * @param string $alias
     */
    public function setAlias($alias) {}


    public function __toString() {}

}
