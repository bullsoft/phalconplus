<?php
namespace PhalconPlus\Test;

class Task extends \PhalconPlus\Base\AbstractModule
{
    public function registerAutoloaders()
    {
        $loader = new \Phalcon\Loader();
        $loader->registerNamespaces(array(
            __NAMESPACE__.'\\Tasks' => __DIR__.'/tasks/',
        ))->register();
    }

    public function registerServices()
    {
        $di = $this->di;

        if($this->isPrimary()) {
            $di->set('dispatcher', function() use ($di) {
                $dispatcher = new \Phalcon\Cli\Dispatcher();
                $dispatcher->setDefaultNamespace(__NAMESPACE__."\\Tasks\\");
                $dispatcher->setDefaultTask("help");
                return $dispatcher;
            });
        }

        $di->set("rpc", function() use ($di) {
            $client = new \PhalconPlus\RPC\Client\Adapter\Local($di);
            return $client;
        });
    }
}