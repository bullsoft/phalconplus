<?php

namespace PhalconPlus\Base;


class ProtoBuffer implements \JsonSerializable
{

    /**
     * @param array $data
     */
    public function softClone(array $data) {}

    /**
     * @param string $key
     * @param mixed $val
     */
    public function __set(string $key, $val) {}

    /**
     * @param string $key
     */
    public function __isset(string $key) {}

    /**
     * @param string $key
     */
    public function __get(string $key) {}

    /**
     * @return array
     */
    protected function getSelfVars() {}


    public function jsonSerialize() {}

    /**
     * @param bool $isArray
     * @param array $data
     */
    public function toArray(bool $isArray = false, array $data = array()) {}

}
