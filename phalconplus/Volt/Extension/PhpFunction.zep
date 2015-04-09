//<?php
namespace PhalconPlus\Volt\Extension;

class PhpFunction
{
    public function compileFunction()
    {
        var params = [];
        var name;
        let params = func_get_args();
        let name = array_shift(params);
        array_pop(params);
        if function_exists(name) {
            return name . "(" . join(",", params) . ")";
        }
    }
}
