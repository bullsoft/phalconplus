<?php

namespace PhalconPlus\Enum;


class RunMode extends \PhalconPlus\Enum\AbstractEnum
{

    const WEB = 'Web';


    const CLI = 'Cli';


    const SRV = 'Srv';


    const MICRO = 'Micro';


    const __default = 'Cli';


    protected $mapClasses = array('Web' => 'Module', 'Cli' => 'Task', 'Srv' => 'Srv', 'Micro' => 'Micro');


    protected $scripts = array('Web' => 'default-web.php', 'Cli' => 'default-cli.php', 'Srv' => 'default-web.php', 'Micro' => 'default-micro.php');


    /**
     * @return string|null
     */
    public function getScriptPath(): ?string {}

    /**
     * @return string
     */
    public function getMapClassName(): string {}

}
