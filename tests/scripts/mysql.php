<?php
include dirname(__DIR__) . "/bootstrap.php";

$di = $app->di();

$result = $di->get("db")->query("select version();");
$record = $result->fetch();

assert(isset($record[0]));
assert(isset($record['version()']));
assert(!empty($record[0]));
assert(!empty($record['version()']));

assert(1 == preg_match("/\d{1,2}\.\d{1,2}\.\d{1,2}/", $record['version()']));
