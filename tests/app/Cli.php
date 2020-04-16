<?php
namespace PhalconPlus\Test;
use PhalconPlus\App\Module\AbstractModule as AppModule;
use Ph\Di;

class Cli extends AppModule
{
    public function registerAutoloaders()
    {
        Di::get('loader')->registerNamespaces(array(
            __NAMESPACE__.'\\Tasks'  => __DIR__.'/tasks/',
            __NAMESPACE__.'\\Protos' => $this->getDir().'/src/protos/',
            __NAMESPACE__.'\\Models' => $this->getDir().'/src/models/',
        ), true)->register();
    }

    public function registerServices()
    {
        $di = Di::itself();

        if($this->isPrimary()) {
            $di->set('dispatcher', function() use ($di) {
                $dispatcher = new \Phalcon\Cli\Dispatcher();
                $dispatcher->setDefaultNamespace(__NAMESPACE__."\\Tasks\\");
                $dispatcher->setDefaultTask("help");
                return $dispatcher;
            });
        }

        // register db write service
        $di->setShared('db', function() use ($di) {
            $mysql = new \PhalconPlus\Db\Mysql($di, "db");
            $conn = $mysql->getConnection(false);
            return $conn;
        });

        // register db write service
        $di->setShared('dbRead', function() use ($di) {
            $mysql = new \PhalconPlus\Db\Mysql($di, "db");
            $conn = $mysql->getConnection(false);
            return $conn;
        });
    }
}
