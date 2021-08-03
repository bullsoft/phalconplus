<?php

namespace PhalconPlus\Assert;

use PhalconPlus\Enum\AssertionCode;
use PhalconPlus\Assert\InvalidArgumentException;
use PhalconPlus\Helper\Variable;

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
    protected static function createException($value, $message, $code, $propertyPath, array $constraints = [])
    {
    }

    /**
     * @param mixed $value1
     * @param mixed $value2
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function eq($value1, $value2, $message = null, $propertyPath = null): bool
    {
    }

    /**
     * @param mixed $value1
     * @param mixed $value2
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function notEq($value1, $value2, $message = null, $propertyPath = null): bool
    {
    }

    /**
     * @param mixed $value1
     * @param mixed $value2
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function same($value1, $value2, $message = null, $propertyPath = null): bool
    {
    }

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function notEmpty($value, $message = null, $propertyPath = null): bool
    {
    }

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function notNull($value, $message = null, $propertyPath = null): bool
    {
    }

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool|null
     */
    public static function notBlank($value, $message = null, $propertyPath = null): ?bool
    {
    }

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function integer($value, $message = null, $propertyPath = null): bool
    {
    }

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function numeric($value, $message = null, $propertyPath = null): bool
    {
    }

    /**
     * @param mixed $value
     * @param int $minValue
     * @param int $maxValue
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function range($value, int $minValue, int $maxValue, $message = null, $propertyPath = null): bool
    {
    }

    /**
     * @param mixed $value
     * @param int $minLength
     * @param mixed $message
     * @param mixed $propertyPath
     * @param string $encodeing
     * @return bool|null
     */
    public static function minLength($value, int $minLength, $message = null, $propertyPath = null, string $encodeing = 'utf8'): ?bool
    {
    }

    /**
     * @param mixed $value
     * @param int $maxLength
     * @param mixed $message
     * @param mixed $propertyPath
     * @param string $encodeing
     * @return bool|null
     */
    public static function maxLength($value, int $maxLength, $message = null, $propertyPath = null, string $encodeing = 'utf8'): ?bool
    {
    }

    /**
     * @param mixed $value
     * @param int $minLength
     * @param int $maxLength
     * @param mixed $message
     * @param mixed $propertyPath
     * @param string $encodeing
     * @return bool|null
     */
    public static function betweenLength($value, int $minLength, int $maxLength, $message = null, $propertyPath = null, string $encodeing = 'utf8'): ?bool
    {
    }

    /**
     * @param mixed $value
     * @param int $minValue
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function min($value, int $minValue, $message = null, $propertyPath = null): bool
    {
    }

    /**
     * @param mixed $value
     * @param int $maxValue
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function max($value, int $maxValue, $message = null, $propertyPath = null): bool
    {
    }

    /**
     * @param mixed $value
     * @param mixed $needle
     * @param mixed $message
     * @param mixed $propertyPath
     * @param string $encodeing
     * @return bool|null
     */
    public static function contains($value, $needle, $message = null, $propertyPath = null, string $encodeing = 'utf8'): ?bool
    {
    }

    /**
     * @param mixed $value
     * @param mixed $needle
     * @param mixed $message
     * @param mixed $propertyPath
     * @param string $encodeing
     * @return bool|null
     */
    public static function notContains($value, $needle, $message = null, $propertyPath = null, string $encodeing = 'utf8'): ?bool
    {
    }

    /**
     * @param mixed $value
     * @param array $choices
     * @param mixed $message
     * @param mixed $propertyPath
     */
    public static function inArray($value, array $choices, $message = null, $propertyPath = null)
    {
    }

    /**
     * @param mixed $value
     * @param mixed $key
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool|null
     */
    public static function keyExists($value, $key, $message = null, $propertyPath = null): ?bool
    {
    }

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool|null
     */
    public static function isResource($value, $message = null, $propertyPath = null): ?bool
    {
    }

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function isString($value, $message = null, $propertyPath = null): bool
    {
    }

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function isArray($value, $message = null, $propertyPath = null): bool
    {
    }

    /**
     * @param mixed $value
     * @param mixed $message
     * @param string $propertyPath
     * @return bool
     */
    public static function isTraversable($value, $message = null, string $propertyPath = null): bool
    {
    }

    /**
     * @param mixed $value
     * @param mixed $message
     * @param string $propertyPath
     * @return bool
     */
    public static function isArrayAccessible($value, $message = null, string $propertyPath = null): bool
    {
    }

    /**
     * @param mixed $value
     * @param mixed $message
     * @param string $propertyPath
     * @return bool
     */
    public static function isCountable($value, $message = null, string $propertyPath = null): bool
    {
    }

    /**
     * @param object $value
     * @param mixed $classNames
     * @param mixed $message
     * @param mixed $propertyPath
     * @return bool
     */
    public static function isInstanceOf($value, $classNames, $message = null, $propertyPath = null): bool
    {
    }

    /**
     * @param mixed $value
     * @param mixed $message
     * @param mixed $propertyPath
     * @param \ArrayObject $obj
     * @return bool
     */
    public static function isJsonString($value, $message = null, $propertyPath = null, \ArrayObject $obj = null): bool
    {
    }

    /**
     * @param mixed $value
     */
    private static function stringify($value)
    {
    }

}
