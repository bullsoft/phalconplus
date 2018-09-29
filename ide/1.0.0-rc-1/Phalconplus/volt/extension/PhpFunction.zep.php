<?php

namespace PhalconPlus\Volt\Extension;


class PhpFunction
{

    private $ns = '';


    private $func = '__invoke__';


    /**
     * @param string $ns
     */
    public function setCustNamespace(string $ns) {}

    /**
     * @param string $func
     */
    public function setCustFuncName(string $func) {}


    public function compileFunction() {}

}
