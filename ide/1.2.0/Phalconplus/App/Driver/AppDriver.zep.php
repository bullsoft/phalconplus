<?php

namespace PhalconPlus\App\Driver;

interface AppDriver
{

    /**
     * @return object
     */
    public function getHandler();

    /**
     * @param object $handler
     * @return AppDriver
     */
    public function setHandler($handler): AppDriver;

}
