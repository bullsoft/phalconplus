<?php
date_default_timezone_set('Asia/Shanghai');
ini_set("memory_limit", "4G");

if (!defined('AUTO_HANDLE')) {
    define('AUTO_HANDLE', true);
}

$bootstrap = new \PhalconPlus\Bootstrap(__DIR__);

if (file_exists(APP_ROOT_DIR . "vendor/autoload.php")) {
    include(APP_ROOT_DIR . "vendor/autoload.php");
}

$arguments = [];
foreach ($argv as $k => $arg) {
    if ($k == 1) {
        $arguments['task'] = $arg;
    } elseif ($k == 2) {
        $arguments['action'] = $arg;
    } elseif ($k >= 3) {
        $arguments['params'][] = $arg;
    }
}
$bootstrap->execTask($arguments, null, AUTO_HANDLE);


assert($bootstrap->getPrimaryModuleDef()->getName() == "tests");
assert($bootstrap->getPrimaryModule() instanceof \PhalconPlus\Test\Task);
assert($bootstrap->getModule("tests")->isPrimary() == true);
assert($bootstrap->getModuleDef("tests")->getName() == "tests");
