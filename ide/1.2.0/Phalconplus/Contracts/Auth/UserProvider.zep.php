<?php

namespace PhalconPlus\Contracts\Auth;

interface UserProvider
{


    public function getById();


    public function getRole();

    /**
     * @return string
     */
    public function getIdName(): string;


    public function getIdValue();

    /**
     * @param mixed $val
     * @return UserProvider
     */
    public function setIdValue($val): UserProvider;

}
