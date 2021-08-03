<?php

namespace PhalconPlus\Helper;

use PhalconPlus\Assert\Assertion as Assert;

class Str
{

    /**
     * @param string $inputStr
     * @return array
     */
    public static function decodeJson(string $inputStr): array
    {
    }

    /**
     * @param string $full
     * @param string $partial
     * @return bool
     */
    public static function startsWith(string $full, string $partial): bool
    {
    }

    /**
     * @param string $full
     * @param string $partial
     * @return bool
     */
    public static function endsWith(string $full, string $partial): bool
    {
    }

    /**
     * @param string $full
     * @param string $partial
     * @return bool
     */
    public static function contains(string $full, string $partial): bool
    {
    }

    /**
     * @param string $inputStr
     * @param bool $padding
     * @return string
     */
    public static function safeBase64Encode(string $inputStr, bool $padding = false): string
    {
    }

    /**
     * @param string $inputStr
     */
    public static function safeBase64Decode(string $inputStr)
    {
    }

}
