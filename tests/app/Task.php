<?php
namespace PhalconPlus\Test;

class Task extends \PhalconPlus\Base\AbstractModule
{
    public function registerAutoloaders()
    {
        $loader = new \Phalcon\Loader();
        $loader->registerNamespaces(array(
            __NAMESPACE__.'\\Tasks' => __DIR__.'/tasks/',
            __NAMESPACE__.'\\Models' => __DIR__.'/models/',
            __NAMESPACE__.'\\Protos' => __DIR__.'/protos/',
        ))->register();
    }

    public function registerServices()
    {
        $di = $this->di;
        $config = $di->get("bootstrap")->getConfig();

        $di->set('config', function() use ($config) {
            return $config;
        });

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

        $di->set('modelsMetadata', function () use ($config) {
            $metaData = new \Phalcon\Mvc\Model\Metadata\Files(array(
                'metaDataDir' => getenv("HOME").'/tmp/metas/',
            ));
            return $metaData;
        });

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
