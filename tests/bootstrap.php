#!/usr/bin/env php
<?php
date_default_timezone_set('Asia/Shanghai');
ini_set("memory_limit", "4G");

$bootstrap = new \PhalconPlus\Bootstrap(__DIR__);
$di = new \Phalcon\DI\FactoryDefault\CLI();

$arguments = array();
foreach($argv as $k => $arg) {
    if($k == 1) {
        $arguments['task'] = $arg;
    } elseif($k == 2) {
        $arguments['action'] = $arg;
    } elseif($k >= 3) {
        $arguments['params'][] = $arg;
    }
}
$bootstrap->execTask($arguments, $di, false);

assert($bootstrap->getPrimaryModuleDef()->getName() == "test");
assert($bootstrap->getPrimaryModule() instanceof \PhalconPlus\Test\Task);
assert($bootstrap->getModule("test")->isPrimary() == true);
assert($bootstrap->getModuleDef("test")->getName() == "test");