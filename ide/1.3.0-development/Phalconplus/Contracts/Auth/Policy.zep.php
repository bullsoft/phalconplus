<?php

namespace PhalconPlus\Contracts\Auth;

use Phalcon\Mvc\Model;

interface Policy
{

    /**
     * @param UserProvider $user
     * @param \Phalcon\Mvc\Model $model
     * @return bool
     */
    public function list(UserProvider $user, \Phalcon\Mvc\Model $model): bool;

    /**
     * @param UserProvider $user
     * @param \Phalcon\Mvc\Model $model
     * @return bool
     */
    public function view(UserProvider $user, \Phalcon\Mvc\Model $model): bool;

    /**
     * @param UserProvider $user
     * @param \Phalcon\Mvc\Model $model
     * @return bool
     */
    public function delete(UserProvider $user, \Phalcon\Mvc\Model $model): bool;

    /**
     * @param UserProvider $user
     * @param \Phalcon\Mvc\Model $model
     * @return bool
     */
    public function create(UserProvider $user, \Phalcon\Mvc\Model $model): bool;

    /**
     * @param UserProvider $user
     * @param \Phalcon\Mvc\Model $model
     * @return bool
     */
    public function update(UserProvider $user, \Phalcon\Mvc\Model $model): bool;

}
