<?php

namespace PhalconPlus\Base;

final class SimpleResponse extends \PhalconPlus\Base\AbstractResponse
{
    /**
     * @var array
     */
    private $result = array();


    /**
     * @param array $data
     * @param bool $deep
     * @return ProtoBuffer
     */
    public function softClone(array $data, bool $deep = false): ProtoBuffer
    {
    }

    /**
     * @return array
     */
    protected function getSelfVars(): array
    {
    }

    /**
     * @return array
     */
    public function getResult(): array
    {
    }

    /**
     * @param array $result
     * @return SimpleResponse
     */
    public function setResult(array $result = array()): SimpleResponse
    {
    }

    /**
     * @param mixed $val
     * @param mixed $key
     * @return SimpleResponse
     */
    public function setItem($val, $key = null): SimpleResponse
    {
    }

    /**
     * @param mixed $key
     */
    public function getItem($key = null)
    {
    }

    /**
     * @param mixed $key
     */
    public function hasItem($key)
    {
    }

    /**
     * @param string $key
     * @param mixed $val
     */
    public function __set(string $key, $val)
    {
    }

    /**
     * @param string $key
     */
    public function __isset(string $key)
    {
    }

    /**
     * @param string $key
     */
    public function __get(string $key)
    {
    }

    /**
     * @param string $key
     * @return void
     */
    public function __unset(string $key)
    {
    }

    /**
     * @return bool
     */
    public function isEmpty(): bool
    {
    }

}
