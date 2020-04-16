<?php
include dirname(__DIR__) . "/bootstrap.php";

use PhalconPlus\Test\Protos\Student;

// the data which we want to import
$data = json_decode('{"firstName": "foo", "lastName": "bar", "age": 1, "classes": {"grade": 1}}');

$student = \BullSoft\Proto::newInstance(Student::class, $data);


var_dump($student);
