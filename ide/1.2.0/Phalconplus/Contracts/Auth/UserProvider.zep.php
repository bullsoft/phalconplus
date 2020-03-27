<?php

namespace PhalconPlus\Contracts\Auth;

use Phalcon\Mvc\Model;

interface UserProvider
{

    /**
     * @return string
     */
    public function getRole(): string;

    /**
     * @return string
     */
    public function getName(): string;

    /**
     * @return string
     */
    public function getIdName(): string;

    /**
     * @return string
     */
    public function getUsernameName(): string;

}
