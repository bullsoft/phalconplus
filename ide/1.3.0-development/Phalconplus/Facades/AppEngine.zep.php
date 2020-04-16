<?php

namespace PhalconPlus\Facades;

use Phalcon\Di;

class AppEngine extends \PhalconPlus\Facades\AbstractFacade
{

    /**
     * @return string
     */
    protected function getName(): string
    {
    }

    /**
     * @param string $controller
     * @param string $action
     * @param array $params
     * @param mixed $callback
     * @return string
     */
    public static function request(string $controller, string $action, array $params, $callback = null): string
    {
    }

}
