<?php

namespace PhalconPlus\Volt\Extension;


class PhpFunction
{

    private $ns = "";


    private $func = "__invoke__";


    /**
     * @param string $ns
     */
    public function setCustNamespace($ns) {}

    /**
     * @param string $func
     */
    public function setCustFuncName($func) {}


    public function compileFunction() {}

}
