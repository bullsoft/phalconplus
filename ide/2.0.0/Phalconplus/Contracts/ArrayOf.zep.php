<?php

namespace PhalconPlus\Contracts;

interface ArrayOf
{

    /**
     * @param array $columns
     * @return array
     */
    public function toArray(array $columns = []): array;

}
