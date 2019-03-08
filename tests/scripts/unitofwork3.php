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

$unitwork->update("order-detail", $orderDetail, ['orderLineNumber' => 19]);
$unitwork->update("order", $order, ['comments' => "dddd"]);

$result = $unitwork->exec();

if (true == $result) {
    $updated = $unitwork->getUpdated();
    var_dump($updated[$orderDetail]);
    var_dump($updated[$order]);
}


