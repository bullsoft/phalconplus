<?php

namespace PhalconPlus\Enum;


class RunMode extends \PhalconPlus\Enum\AbstractEnum
{

    const WEB = 'Web';


    const CLI = 'Cli';


    const SRV = 'Srv';


    const MICRO = 'Micro';


    const __default = 'Cli';


    protected $map = array('Web' => 'Module', 'Cli' => 'Task', 'Srv' => 'Srv', 'Micro' => 'Micro');



    public function getMapClassName() {}

}
