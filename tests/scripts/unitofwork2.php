<?php
define("AUTO_HANDLE", false);
include dirname(__DIR__) . "/bootstrap.php";
use PhalconPlus\Test\Models\Classicmodels\OrdersModel;
use PhalconPlus\Test\Models\Classicmodels\OrderdetailsModel;

$unitwork = new \PhalconPlus\Db\UnitOfWork("db");

$order = OrdersModel::findFirst();

$orderDetail = OrderdetailsModel::find(
    [
        "orderNumber = ?0",
        "bind" => [
            $order->orderNumber
        ]
    ]
);

$unitwork->delete("order-detail", $orderDetail);
$unitwork->delete("order", $order);

$unitwork->exec();


