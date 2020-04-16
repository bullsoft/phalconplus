<?php
include dirname(__DIR__) . "/bootstrap.php";

use PhalconPlus\Assert\Assertion as Assert;

$eq1 = 1;
$eq2 = 2;
$eq3 = 1;
Assert::eq($eq1, $eq2, "错误错误");
assert(true, Assert::notEq($eq1, $eq2));
assert(true, Assert::eq($eq1, $eq3));