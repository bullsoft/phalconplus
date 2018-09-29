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
     */
    public function softClone(array $data) {}


    public function getResult() {}

    /**
     * @param array $result
     */
    public function setResult(array $result = array()) {}

    /**
     * @deprecated
     * @param mixed $val
     * @param mixed $key
     */
    public function pushItem($val, $key = null) {}

    /**
     * @param mixed $val
     * @param mixed $key
     */
    public function setItem($val, $key = null) {}

    /**
     * @param mixed $key
     */
    public function getItem($key = null) {}

}
