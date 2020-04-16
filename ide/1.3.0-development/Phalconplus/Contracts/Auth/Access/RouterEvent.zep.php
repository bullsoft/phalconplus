<?php

namespace PhalconPlus\Contracts\Auth\Access;

use Phalcon\Mvc\Router;
use Phalcon\Mvc\Router\Route;
use Phalcon\Events\Event;

interface RouterEvent
{

    /**
     * @param \Phalcon\Events\Event $event
     * @param \Phalcon\Mvc\Router $router
     * @param \Phalcon\Mvc\Router\Route $route
     */
    public function matchedRoute(\Phalcon\Events\Event $event, \Phalcon\Mvc\Router $router, \Phalcon\Mvc\Router\Route $route);

}
