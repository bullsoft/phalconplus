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
     * @param mixed $value1
     * @param mixed $value2
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function eq($value1, $value2, $message = null, $propertyPath = null): bool {}

    /**
     * @param mixed $value1
     * @param mixed $value2
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function notEq($value1, $value2, $message = null, $propertyPath = null): bool {}

    /**
     * @param mixed $value1
     * @param mixed $value2
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function same($value1, $value2, $message = null, $propertyPath = null): bool {}

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function notEmpty($value, $message = null, $propertyPath = null): bool {}

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function notNull($value, $message = null, $propertyPath = null): bool {}

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function numeric($value, $message = null, $propertyPath = null): bool {}

    /**
     * @param mixed $value
     * @param int $minValue
     * @param int $maxValue
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function range($value, int $minValue, int $maxValue, $message = null, $propertyPath = null): bool {}

    /**
     * @param mixed $value
     * @param int $minValue
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function min($value, int $minValue, $message = null, $propertyPath = null): bool {}

    /**
     * @param mixed $value
     * @param int $maxValue
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function max($value, int $maxValue, $message = null, $propertyPath = null): bool {}

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function isString($value, $message = null, $propertyPath = null): bool {}

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function isArray($value, $message = null, $propertyPath = null): bool {}

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function isJsonString($value, $message = null, $propertyPath = null): bool {}

    /**
     * @param mixed $value
     */
    private static function stringify($value) {}

}
