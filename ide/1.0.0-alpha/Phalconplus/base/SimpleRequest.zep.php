<?php

namespace PhalconPlus\Base;


class SimpleRequest extends \PhalconPlus\Base\ProtoBuffer
{

    private $params = array();


    /**
     * @param mixed $idx
     */
    public function getParam($idx) {}

    /**
     * @param array $params
     */
    public function setParams(array $params) {}

    /**
     * @param mixed $val
     * @param mixed $key
     */
    public function setParam($val, $key = null) {}


    public function getParams() {}

}
