<?php
define("AUTO_HANDLE", false);
include dirname(__DIR__) . "/bootstrap.php";
use PhalconPlus\Test\Models\Classicmodels\OrdersModel;
use PhalconPlus\Test\Models\Classicmodels\OrderdetailsModel;
use PhalconPlus\Db\UnitOfWork;
use PhalconPlus\Db\UnitOfWork\LastInsertId;
use PhalconPlus\Db\UnitOfWork\Field;

$unitwork = new \PhalconPlus\Db\UnitOfWork("db");

$orderArray = [
    'orderDate' => date("Y-m-d"),
    'requiredDate' => date("Y-m-d", strtotime("+10 days")),
    'shippedDate' => date("Y-m-d", strtotime("+3 days")),
    'status' => 'In Process',
    'comments' => "测试 in Phalcon+++UnitofWork::insert",
    'customerNumber' => 119
];
$om = new OrdersModel();
$unitwork->insert("om", $om, $orderArray);

$orderDetailArray = [
    'orderNumber' => new LastInsertId($om),
    'productCode' => 'S12_3148',
    'quantityOrdered' => 10,
    'priceEach' => 100.00,
    'orderLineNumber' => new Field($om, "customerNumber"),
];

$odm = new OrderdetailsModel();
$unitwork->insert("odm", $odm, $orderDetailArray);
$result = $unitwork->exec();

assert($result == true);

if (true == $result) {
    $inserted = $unitwork->getInserted();
    assert($inserted[$om]["last_insert_id"] == $om->orderNumber);
    assert($inserted[$om]["last_insert_id"] == $odm->orderNumber);
} else {
    echo $unitwork->getException()->getMessage() . PHP_EOL;
}