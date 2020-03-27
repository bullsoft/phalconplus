<?php

namespace PhalconPlus\Contracts\Auth\Access;

use Phalcon\Mvc\DispatcherInterface;
use Phalcon\Events\Event;

interface DispatchEvent
{

    /**
     * @param \Phalcon\Events\Event $event
     * @param \Phalcon\Mvc\DispatcherInterface $dispatcher
     * @return bool
     */
    public function beforeExecuteRoute(\Phalcon\Events\Event $event, \Phalcon\Mvc\DispatcherInterface $dispatcher): bool;

}
