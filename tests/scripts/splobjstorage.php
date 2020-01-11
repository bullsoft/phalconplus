<?php
define("AUTO_HANDLE", false);
include dirname(__DIR__) . "/bootstrap.php";

$objs = new \PhalconPlus\FeatureTest\SplObjectStorageTest();

$obj1 = new \stdClass();
$obj1->a = "b";
$obj1->c = "d";

$obj2 = new \stdClass();
$obj2->o = "p";
$obj2->r = "s";

$objs->insert("testObj1", $obj1, ["e" => "f", "g" => "h"]);
$objs->insert("testObj2", $obj2, ["u" => "v", "x" => "y"]);
$objs->exec();