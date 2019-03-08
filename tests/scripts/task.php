<?php
define("AUTO_HANDLE", false);
include dirname(__DIR__) . "/bootstrap.php";

$helpTask = new \PhalconPlus\Test\Tasks\HelpTask();

assert(1 == $helpTask->return1Action());
