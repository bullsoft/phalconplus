<?php
define("AUTO_HANDLE", false);
include dirname(__DIR__) . "/bootstrap.php";

use PhalconPlus\Test\Models\Classicmodels\EmployeesModel;

$a = EmployeesModel::newInstance();
$a->email = 'dmurphy@classicmodelcars.com';
$result = $a->setUniqueKeys(["email"])
            ->exists();
var_dump($result);


var_dump($a->getUniqueFields());