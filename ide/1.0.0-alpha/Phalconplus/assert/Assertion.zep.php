<?php

namespace PhalconPlus\Assert;

/**
 * @ref https://github.com/beberlei/assert
 */
class Assertion
{

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $code
     * @param mixed $propertyPath
     * @param array $constraints
     */
    protected static function createException($value, $message, $code, $propertyPath, array $constraints = array()) {}

    /**
     * @param mixed $value
     * @param mixed $value2
     * @param mixed $message
     * @param mixed $propertyPath
     */
    public static function eq($value, $value2, $message = null, $propertyPath = null) {}

    /**
     * @param mixed $value
     * @param mixed $value2
     * @param mixed $message
     * @param mixed $propertyPath
     */
    public static function same($value, $value2, $message = null, $propertyPath = null) {}

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $propertyPath
     */
    public static function notEmpty($value, $message = null, $propertyPath = null) {}

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $propertyPath
     */
    public static function notNull($value, $message = null, $propertyPath = null) {}

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $propertyPath
     */
    public static function numeric($value, $message = null, $propertyPath = null) {}

    /**
     * @param mixed $value
     */
    private static function stringify($value) {}

}
