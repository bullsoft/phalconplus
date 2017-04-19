<?php

namespace PhalconPlus\Assert;


interface AssertionFailedException
{

    /**
     * @param mixed $message
     * @param mixed $code
     * @param mixed $propertyPath
     * @param mixed $value
     * @param array $constraints
     */
    public function __construct($message, $code, $propertyPath = null, $value, array $constraints = array());


    public function getPropertyPath();


    public function getValue();


    public function getConstraints();

}
