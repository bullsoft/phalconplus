<?php

namespace PhalconPlus\Base;

use PhalconPlus\Base\Exception as BaseException;
use PhalconPlus\Assert\Assertion as Assert;
use PhalconPlus\Contracts\EmptyOrNot;
use PhalconPlus\Contracts\ArrayOf;
use PhalconPlus\Helper\Variable;

class ProtoBuffer implements \JsonSerializable, \ArrayAccess, \Countable, \IteratorAggregate, \PhalconPlus\Contracts\EmptyOrNot, \PhalconPlus\Contracts\ArrayOf
{

    /**
     * @param mixed $data
     */
    public function __construct($data = array())
    {
    }

    /**
     * @param array $data
     * @param bool $deep
     * @return ProtoBuffer
     */
    public function softClone(array $data, bool $deep = false): ProtoBuffer
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
     * @param string $key
     */
    public function isSetGet(string $key)
    {
    }

    /**
     * @return array
     */
    protected function getSelfVars(): array
    {
    }


    public function jsonSerialize()
    {
    }

    /**
     * @param array $inputPros
     * @return array
     */
    public function toArray(array $inputPros = array()): array
    {
    }

    /**
     * @param mixed $offset
     * @param mixed $value
     * @return void
     */
    public function offsetSet($offset, $value)
    {
    }

    /**
     * @param mixed $offset
     * @return bool
     */
    public function offsetExists($offset): bool
    {
    }

    /**
     * @param mixed $offset
     * @return void
     */
    public function offsetUnset($offset)
    {
    }

    /**
     * @param mixed $offset
     */
    public function offsetGet($offset)
    {
    }

    /**
     * @return int
     */
    public function count(): int
    {
    }

    /**
     * @return bool
     */
    public function isEmpty(): bool
    {
    }

    /**
     * @return \RecursiveArrayIterator
     */
    public function getIterator(): \RecursiveArrayIterator
    {
    }

}
