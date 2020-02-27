<?php

namespace PhalconPlus\Auth;

use PhalconPlus\Contracts\Auth\Access\ModelEvent;
use Phalcon\Mvc\Model as ARModel;
use Phalcon\Events\Event;
use PhalconPlus\Contracts\Auth\Policy as PolicyContract;
use PhalconPlus\Contracts\Auth\UserProvider;

class Model implements \PhalconPlus\Contracts\Auth\Access\ModelEvent
{

    protected $user;


    protected $policies = array();


    /**
     * @param \PhalconPlus\Contracts\Auth\UserProvider $user
     */
    public function __construct(\PhalconPlus\Contracts\Auth\UserProvider $user)
    {
    }

    /**
     * @param \Phalcon\Events\Event $event
     * @param \Phalcon\Mvc\Model $model
     * @return bool
     */
    public function beforeDelete(\Phalcon\Events\Event $event, \Phalcon\Mvc\Model $model): bool
    {
    }

    /**
     * @param \Phalcon\Events\Event $event
     * @param \Phalcon\Mvc\Model $model
     * @return bool
     */
    public function beforeCreate(\Phalcon\Events\Event $event, \Phalcon\Mvc\Model $model): bool
    {
    }

    /**
     * @param \Phalcon\Events\Event $event
     * @param \Phalcon\Mvc\Model $model
     * @return bool
     */
    public function beforeUpdate(\Phalcon\Events\Event $event, \Phalcon\Mvc\Model $model): bool
    {
    }

    /**
     * @param \Phalcon\Events\Event $event
     * @param \Phalcon\Mvc\Model $model
     * @return bool
     */
    public function beforeValidation(\Phalcon\Events\Event $event, \Phalcon\Mvc\Model $model): bool
    {
    }

    /**
     * @param mixed $model
     * @return mixed
     */
    public function getPolicy($model): ?PolicyContract
    {
    }

}
