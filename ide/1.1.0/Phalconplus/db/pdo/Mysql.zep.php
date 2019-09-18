<?php

namespace PhalconPlus\Db\Pdo;


class Mysql extends \PhalconPlus\Db\Pdo\AbstractMysql
{

    /**
     * @param array $descriptor
     * @param bool $autoConnect
     */
    public function __construct(array $descriptor, bool $autoConnect = true) {}

    /**
     * @param string $prop
     */
    public function __get(string $prop) {}

    /**
     * @return bool
     */
    public function isUnderTransaction(): bool {}

}
