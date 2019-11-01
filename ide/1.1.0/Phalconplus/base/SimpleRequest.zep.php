<?php

namespace PhalconPlus\Base;

final class SimpleRequest extends \PhalconPlus\Base\AbstractRequest
{
    /**
     * @var array
     */
    private $params = array();


    /**
     * @param array $data
     */
    public function softClone(array $data)
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
     * @return \PhalconPlus\Base\SimpleRequest
     */
    public function setParams(array $params): \PhalconPlus\Base\SimpleRequest
    {
    }

    /**
     * @param mixed $val
     * @param mixed $key
     * @return \PhalconPlus\Base\SimpleRequest
     */
    public function setParam($val, $key = null): \PhalconPlus\Base\SimpleRequest
    {
    }

    /**
     * @return array
     */
    public function getParams(): array
    {
    }

}
