<?php

namespace PhalconPlus\Base;

use PhalconPlus\Base\ProtoBuffer;

final class SimpleRequest extends \PhalconPlus\Base\AbstractRequest
{
    /**
     * @var array
     */
    private $params = [];


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
     * @param mixed $idx
     * @param mixed $defaultValue
     */
    public function getParam($idx, $defaultValue = null)
    {
    }

    /**
     * @param mixed $idx
     */
    public function hasParam($idx)
    {
    }

    /**
     * @param array $params
     * @return SimpleRequest
     */
    public function setParams(array $params): SimpleRequest
    {
    }

    /**
     * @param mixed $val
     * @param mixed $key
     * @return SimpleRequest
     */
    public function setParam($val, $key = null): SimpleRequest
    {
    }

    /**
     * @return array
     */
    public function getParams(): array
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
    public function __unset(string $key): void
    {
    }

    /**
     * @return bool
     */
    public function isEmpty(): bool
    {
    }

}
