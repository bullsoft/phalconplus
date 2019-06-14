<?php
return [
    'application' => [
        "name"  => "tests",
        "ns"    => "PhalconPlus\\Test\\",
        "mode"  => "Cli",
        "logFilePath" => "/tmp/fp-test.log",
    ],
    'db' => [
        "host" => "127.0.0.1",
        "port" => 3306,
        "username" => "root",
        "password" => "Abc.123456",
        "dbname" => "classicmodels",
        "charset" => "utf8",
        "timeout" => 3, // 3 秒
        "retryInterval" => 200000, // 失败重试间隔200ms
        "retryTimes" => 5, //失败重试次数
    ],
    'version' => "1.0.0",
];
