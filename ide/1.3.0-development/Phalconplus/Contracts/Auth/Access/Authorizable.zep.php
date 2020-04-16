<?php

namespace PhalconPlus\Contracts\Auth\Access;

interface Authorizable
{

    /**
     * @param string $ability
     * @param mixed $params
     * @return bool
     */
    public function can(string $ability, $params): bool;

}
