<?php
date_default_timezone_set('Asia/Shanghai');
ini_set("memory_limit", "4G");

$app = @(new PhalconPlus\Bootstrap(__DIR__))->app();

assert($app->getPrimaryModuleDef()->getName() == "tests");
assert($app->getPrimaryModule() instanceof PhalconPlus\Test\Cli);
assert($app->getModule("tests")->isPrimary() == true);
assert($app->getModuleDef("tests")->getName() == "tests");
