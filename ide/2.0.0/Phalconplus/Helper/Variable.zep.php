<?php

namespace PhalconPlus\Helper;

use PhalconPlus\Assert\Assertion as Assert;

class Variable
{

    const NULL_VALUE = '$Ph/Var/SoftNull$';



    public static function softNull()
    {
    }

    /**
     * @param string $nil
     */
    public static function isSoftNull(string $nil)
    {
    }

    /**
     * if $a is null, exception will be thrown
     *
     * Variable::notNull($a)->callMethod()
     *
     * @param mixed $val
     */
    public static function notNull($val)
    {
    }

    /**
     * @param mixed $val
     */
    public static function notEmpty($val)
    {
    }

    /**
     * @param mixed $input
     * @return bool
     */
    public static function isInt($input): bool
    {
    }

    /**
     * @param mixed $input
     * @return bool
     */
    public static function isArray($input): bool
    {
    }

    /**
     * @param mixed $input
     * @return bool
     */
    public static function isObject($input): bool
    {
    }

    /**
     * @param mixed $input
     * @return bool
     */
    public static function isBool($input): bool
    {
    }

    /**
     * @param mixed $input
     * @return bool
     */
    public static function isString($input): bool
    {
    }

    /**
     * @param mixed $input
     * @return bool
     */
    public static function isNull($input): bool
    {
    }

    /**
     * @param mixed $input
     * @return bool
     */
    public static function isFloat($input): bool
    {
    }

    /**
     * @param mixed $input
     * @return bool
     */
    public static function isFunctional($input): bool
    {
    }

    /**
     * @param mixed $value
     * @param bool $full
     * @return string
     */
    public static function stringify($value, bool $full = false): string
    {
    }

}
