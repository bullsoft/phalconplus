<?php

namespace PhalconPlus\Auth;

use PhalconPlus\Contracts\Auth\Access\ModelEvent;
use Phalcon\Mvc\Model as ARModel;
use Phalcon\Events\Event;
use PhalconPlus\Contracts\Auth\Policy as PolicyContract;
use PhalconPlus\Contracts\Auth\UserProvider;

class Model implements \PhalconPlus\Contracts\Auth\Access\ModelEvent
{

    protected $user = null;


    protected $policies = array();



    public function getUser()
    {
    }

    /**
     * @param \PhalconPlus\Contracts\Auth\UserProvider $user
     */
    public function __construct(\PhalconPlus\Contracts\Auth\UserProvider $user)
    {
    }

    /**
     * @param \PhalconPlus\Contracts\Auth\UserProvider $user
     * @return Model
     */
    public function setUser(\PhalconPlus\Contracts\Auth\UserProvider $user): Model
    {
    }

    /**
     * @param \Phalcon\Events\Event $event
     * @param \Phalcon\Mvc\Model $model
     * @param mixed $context
     * @return bool
     */
    public function beforeDelete(\Phalcon\Events\Event $event, \Phalcon\Mvc\Model $model, $context = null): bool
    {
    }

    /**
     * @param \Phalcon\Events\Event $event
     * @param \Phalcon\Mvc\Model $model
     * @param mixed $context
     * @return bool
     */
    public function beforeCreate(\Phalcon\Events\Event $event, \Phalcon\Mvc\Model $model, $context = null): bool
    {
    }

    /**
     * @param \Phalcon\Events\Event $event
     * @param \Phalcon\Mvc\Model $model
     * @param mixed $context
     * @return bool
     */
    public function beforeUpdate(\Phalcon\Events\Event $event, \Phalcon\Mvc\Model $model, $context = null): bool
    {
    }

    /**
     * @param \Phalcon\Events\Event $event
     * @param \Phalcon\Mvc\Model $model
     * @param mixed $context
     * @return bool
     */
    public function beforeValidation(\Phalcon\Events\Event $event, \Phalcon\Mvc\Model $model, $context = null): bool
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
