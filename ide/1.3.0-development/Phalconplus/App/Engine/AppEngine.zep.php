<?php

namespace PhalconPlus\App\Engine;

interface AppEngine
{

    /**
     * @return object
     */
    public function getHandler();

    /**
     * @param object $handler
     * @return AppEngine
     */
    public function setHandler($handler): AppEngine;

}
