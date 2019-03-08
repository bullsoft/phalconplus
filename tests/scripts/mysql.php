<?php
define("AUTO_HANDLE", false);
include dirname(__DIR__) . "/bootstrap.php";

$di = $bootstrap->getDI();

$result = $di->get("db")->query("select version();");
$record = $result->fetch();

assert(isset($record[0]));
assert(isset($record['version()']));
assert(!empty($record[0]));
assert(!empty($record['version()']));

assert(1 == preg_match("/\d{1,2}\.\d{1,2}\.\d{1,2}/", $record['version()']));
