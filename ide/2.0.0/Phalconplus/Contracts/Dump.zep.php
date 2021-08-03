<?php

namespace PhalconPlus\Contracts;

interface Dump
{

    /**
     * @return array
     */
    public function __debugInfo(): array;

}
