<?php

namespace PhalconPlus\App\Engine;

use Phalcon\Di\Injectable;
use Phalcon\Application\AbstractApplication as BaseApplication;
use PhalconPlus\App\Module\AbstractModule as AppModule;
use PhalconPlus\App\App as SuperApp;
use PhalconPlus\Base\Exception as BaseException;

class AbstractEngine extends Injectable
{

    protected $appModule = null;


    protected $handler = null;


    /**
     * @param \PhalconPlus\App\Module\AbstractModule $appModule
     * @param \Phalcon\Application\AbstractApplication $handler
     */
    public function __construct(\PhalconPlus\App\Module\AbstractModule $appModule, \Phalcon\Application\AbstractApplication $handler = null)
    {
    }

    /**
     * @return BaseApplication
     */
    public function handler(): BaseApplication
    {
    }

    /**
     * @return BaseApplication
     */
    public function getHandler(): BaseApplication
    {
    }

    /**
     * @param \Phalcon\Application\AbstractApplication $handler
     * @return AbstractEngine
     */
    public function setHandler(\Phalcon\Application\AbstractApplication $handler): AbstractEngine
    {
    }

}
