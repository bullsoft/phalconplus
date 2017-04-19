<?php

namespace PhalconPlus\Assert;


class InvalidArgumentException extends \InvalidArgumentException implements \PhalconPlus\Assert\AssertionFailedException
{

    private $propertyPath;


    private $value;


    private $constraints;


    /**
     * @param mixed $message
     * @param mixed $code
     * @param mixed $propertyPath
     * @param mixed $value
     * @param array $constraints
     */
    public function __construct($message, $code, $propertyPath = null, $value, array $constraints = array()) {}


    public function getPropertyPath() {}


    public function getValue() {}


    public function getConstraints() {}

}
