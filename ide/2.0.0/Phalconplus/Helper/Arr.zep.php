<?php

namespace PhalconPlus\Helper;

use PhalconPlus\Assert\Assertion as Assert;
use PhalconPlus\Base\ProtoBuffer;

class Arr
{

    /**
     * @param mixed $inputArray
     * @return bool
     */
    public static function isAllKeyInt($inputArray): bool
    {
    }

    /**
     * @param mixed $inputArray
     * @return bool
     */
    public static function isAllKeyString($inputArray): bool
    {
    }

    /**
     * @param mixed $inputArray
     * @return bool
     */
    public static function isKeyNumericSequentialZeroBased($inputArray): bool
    {
    }

    /**
     * @param mixed $inputArray
     * @return ProtoBuffer
     */
    public static function newProtoBuffer($inputArray): ProtoBuffer
    {
    }

    /**
     * @param mixed $inputArray
     * @return string
     */
    public static function encodeJson($inputArray): string
    {
    }

    /**
     * @param mixed $inputArray
     */
    public static function firstKey($inputArray)
    {
    }

    /**
     * @param mixed $inputArray
     */
    public static function lastKey($inputArray)
    {
    }

    /**
     * @param mixed $inputArray
     */
    public static function first($inputArray)
    {
    }

    /**
     * @param mixed $inputArray
     */
    public static function last($inputArray)
    {
    }

    /**
     *
     * handler = function(string | int key, mixed val) : string {
     *    return <string>
     * }
     *
     * @param mixed $inputArray
     * @param callable $handler
     * @return array
     */
    public static function groupBy($inputArray, $handler): array
    {
    }

}
