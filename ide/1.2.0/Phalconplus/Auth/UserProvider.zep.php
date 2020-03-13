<?php

namespace PhalconPlus\Auth;

use PhalconPlus\Contracts\Auth\UserProvider as UserProviderContract;
use Phalcon\Security;
use Phalcon\Text;
use Phalcon\Mvc\Model;

abstract class UserProvider implements UserProviderContract
{

    protected $id;


    protected $role = 'Guests';


    protected $name = '';


    protected $entity = null;



    public function getEntity()
    {
    }

    /**
     * @param \Phalcon\Mvc\Model $user
     * @param string $role
     */
    public function __construct(\Phalcon\Mvc\Model $user = null, string $role = 'Guests')
    {
    }

    /**
     * @param string $userId
     * @return UserProvider
     */
    public static function getById(string $userId): UserProvider
    {
    }

    /**
     * @param string $token
     * @return UserProvider
     */
    public static function getByToken(string $token): UserProvider
    {
    }

    /**
     * @param array $credentials
     * @return UserProvider
     */
    public static function getByCredentials(array $credentials): UserProvider
    {
    }

    /**
     * @param array $credentials
     * @return UserProvider
     */
    public static function loginByCredentials(array $credentials): UserProvider
    {
    }

    /**
     * @param array $credentials
     * @return UserProvider
     */
    public static function loginByToken(array $credentials): UserProvider
    {
    }

    /**
     * @return bool
     */
    public static function checkLogin(): bool
    {
    }

    /**
     * @return bool
     */
    public static function checkLoginByToken(): bool
    {
    }

    /**
     * @param \Phalcon\Mvc\Model $user
     * @param array $credentials
     * @return bool
     */
    public static function validateCredentials(\Phalcon\Mvc\Model $user, array $credentials): bool
    {
    }

    /**
     * @return UserProvider
     */
    public static function guest(): UserProvider
    {
    }

    /**
     * @param string $rawPasswd
     * @param bool $makeSalt
     * @return array
     */
    public static function hashPassword(string $rawPasswd, bool $makeSalt = false): array
    {
    }

    /**
     * @param string $rawPasswd
     * @param string $encryptedPasswd
     * @param string $salt
     * @return bool
     */
    public static function checkPassword(string $rawPasswd, string $encryptedPasswd, string $salt = ''): bool
    {
    }

    /**
     * @param string $ability
     * @param mixed $params
     * @return bool
     */
    public function can(string $ability, $params): bool
    {
    }

    /**
     * @return mixed
     */
    public function entity(): ?Model
    {
    }

    /**
     * @param string $roleName
     * @return bool
     */
    public function hasAccess(string $roleName): bool
    {
    }

    /**
     * @return string
     */
    public function getRole(): string
    {
    }

    /**
     * @return string
     */
    public function getName(): string
    {
    }

    /**
     * @return string
     */
    public function getIdName(): string
    {
    }

    /**
     * @return string
     */
    public function getUsernameName(): string
    {
    }

    /**
     * @return string
     */
    public function getRoleName(): string
    {
    }

}
