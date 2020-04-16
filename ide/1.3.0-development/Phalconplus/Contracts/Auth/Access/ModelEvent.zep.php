<?php

namespace PhalconPlus\Contracts\Auth\Access;

use Phalcon\Mvc\Model;
use Phalcon\Events\Event;

interface ModelEvent
{

    /**
     * @param \Phalcon\Events\Event $event
     * @param \Phalcon\Mvc\Model $model
     * @param mixed $context
     * @return bool
     */
    public function beforeDelete(\Phalcon\Events\Event $event, \Phalcon\Mvc\Model $model, $context = null): bool;

    /**
     * @param \Phalcon\Events\Event $event
     * @param \Phalcon\Mvc\Model $model
     * @param mixed $context
     * @return bool
     */
    public function beforeCreate(\Phalcon\Events\Event $event, \Phalcon\Mvc\Model $model, $context = null): bool;

    /**
     * @param \Phalcon\Events\Event $event
     * @param \Phalcon\Mvc\Model $model
     * @param mixed $context
     * @return bool
     */
    public function beforeUpdate(\Phalcon\Events\Event $event, \Phalcon\Mvc\Model $model, $context = null): bool;

    /**
     * @param \Phalcon\Events\Event $event
     * @param \Phalcon\Mvc\Model $model
     * @param mixed $context
     * @return bool
     */
    public function beforeValidation(\Phalcon\Events\Event $event, \Phalcon\Mvc\Model $model, $context = null): bool;

}
