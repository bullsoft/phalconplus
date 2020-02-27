<?php

namespace PhalconPlus\Facades;

use Phalcon\Acl\Adapter\Memory as AclList;
use Phalcon\Di;

class Acl extends \PhalconPlus\Facades\AbstractFacade
{

    /**
     * @return string
     */
    protected function getName(): string
    {
    }

    /**
     * @param \Phalcon\Di $di
     * @return mixed
     */
    protected function resolve(\Phalcon\Di $di): ?Di
    {
    }

}
