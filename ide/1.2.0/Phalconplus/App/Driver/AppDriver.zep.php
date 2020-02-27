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
     * @param bool $autoHandle
     * @return AppDriver
     */
    public function setHandler($handler, bool $autoHandle = false): AppDriver;

}
