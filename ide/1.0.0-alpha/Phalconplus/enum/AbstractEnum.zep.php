<?php

namespace PhalconPlus\Enum;


abstract class AbstractEnum implements \JsonSerializable
{

    protected $val;


    /**
     * @param mixed $val
     */
    public function __construct($val = "__PhalconPlus_AbstractEnum_DefaultValue__") {}

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
    public static function validValues($assoc = false) {}


    public function jsonSerialize() {}


    public function __toString() {}

}
