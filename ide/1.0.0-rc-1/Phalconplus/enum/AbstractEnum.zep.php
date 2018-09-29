<?php

namespace PhalconPlus\Enum;


abstract class AbstractEnum implements \JsonSerializable
{

    const DEFAULT_VALUE = '__PhalconPlus_AbstractEnum_DefaultValue__';


    protected $val;


    /**
     * @param mixed $val
     */
    public function __construct($val = self::DEFAULT_VALUE) {}

    /**
     * @param mixed $val
     */
    protected function setValue($val) {}


    public function getValue() {}

    /**
     * @param mixed $val
     */
    public static function isValid($val) {}

    /**
     * @param bool $assoc
     */
    public static function validValues(bool $assoc = false) {}


    public function jsonSerialize() {}


    public function __toString() {}

}
