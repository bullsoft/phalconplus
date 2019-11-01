<?php

namespace PhalconPlus\Enum;

use PhalconPlus\Enum\AbstractEnum;

class RunEnv extends AbstractEnum
{

    const DEV = 'dev';


    const DEBUG = 'debug';


    const TEST = 'test';


    const UAT = 'uat';


    const PRE_PRODUCTION = 'pre_production';


    const AB_TEST = 'ab_test';


    const PRODUCTION = 'production';


    const __default = 'dev';


    /**
     * @param string $env
     * @return bool
     */
    public static function isInProd(string $env): bool
    {
    }


    public function isInAbTest()
    {
    }

}
