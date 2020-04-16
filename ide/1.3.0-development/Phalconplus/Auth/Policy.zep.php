<?php

namespace PhalconPlus\Auth;

use PhalconPlus\Contracts\Auth\UserProvider;
use PhalconPlus\Contracts\Auth\Policy as PolicyContract;
use Phalcon\Mvc\Model;
use Phalcon\Di\Injectable;
use Phalcon\Acl\Adapter\Memory as AclList;
use PhalconPlus\Facades\Acl;

class Policy extends Injectable implements PolicyContract
{

    protected $acl;



    public function __construct()
    {
    }

    /**
     * @param \PhalconPlus\Contracts\Auth\UserProvider $user
     * @param \Phalcon\Mvc\Model $model
     * @return bool
     */
    public function list(\PhalconPlus\Contracts\Auth\UserProvider $user, \Phalcon\Mvc\Model $model): bool
    {
    }

    /**
     * @param \PhalconPlus\Contracts\Auth\UserProvider $user
     * @param \Phalcon\Mvc\Model $model
     * @return bool
     */
    public function view(\PhalconPlus\Contracts\Auth\UserProvider $user, \Phalcon\Mvc\Model $model): bool
    {
    }

    /**
     * @param \PhalconPlus\Contracts\Auth\UserProvider $user
     * @param \Phalcon\Mvc\Model $model
     * @return bool
     */
    public function delete(\PhalconPlus\Contracts\Auth\UserProvider $user, \Phalcon\Mvc\Model $model): bool
    {
    }

    /**
     * @param \PhalconPlus\Contracts\Auth\UserProvider $user
     * @param \Phalcon\Mvc\Model $model
     * @return bool
     */
    public function update(\PhalconPlus\Contracts\Auth\UserProvider $user, \Phalcon\Mvc\Model $model): bool
    {
    }

    /**
     * @param \PhalconPlus\Contracts\Auth\UserProvider $user
     * @param \Phalcon\Mvc\Model $model
     * @return bool
     */
    public function create(\PhalconPlus\Contracts\Auth\UserProvider $user, \Phalcon\Mvc\Model $model): bool
    {
    }

}
