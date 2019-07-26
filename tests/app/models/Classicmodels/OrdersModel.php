<?php

namespace PhalconPlus\Test\Models\Classicmodels;

/**
 * Phalcon Model: OrdersModel
 *
 * 此文件由代码自动生成，代码依赖PhalconPlus和Zend\Code\Generator
 *
 * @namespace PhalconPlus\Test\Models\Classicmodels
 * @version $Rev:2018-12-27 10:20:54$
 * @license PhalconPlus( http://plus.phalconphp.org/license-1.0.html )
 */
class OrdersModel extends ModelBase
{

    /**
     * @var integer
     * @table orders
     */
    public $id = null;

    /**
     * @var integer
     * @table orders
     */
    public $orderNumber = null;

    /**
     * @var date
     * @table orders
     */
    public $orderDate = null;

    /**
     * @var date
     * @table orders
     */
    public $requiredDate = null;

    /**
     * @var date
     * @table orders
     */
    public $shippedDate = null;

    /**
     * @var string
     * @table orders
     */
    public $status = null;

    /**
     * @var string
     * @table orders
     */
    public $comments = null;

    /**
     * @var integer
     * @table orders
     */
    public $customerNumber = null;

    public function initialize()
    {
        parent::initialize();
        $this->setWriteConnectionService("db");
        $this->setReadConnectionService("dbRead");
    }

    /**
     * When an instance created, it would be executed
     */
    public function onConstruct()
    {
        $this->orderNumber = NULL;
        $this->orderDate = NULL;
        $this->requiredDate = NULL;
        $this->shippedDate = NULL;
        $this->status = NULL;
        $this->comments = NULL;
        $this->customerNumber = NULL;
    }

    /**
     * Column map for database fields and model properties
     */
    public function columnMap()
    {
        return array(
            'orderNumber' => 'orderNumber', 
            'orderDate' => 'orderDate', 
            'requiredDate' => 'requiredDate', 
            'shippedDate' => 'shippedDate', 
            'status' => 'status', 
            'comments' => 'comments', 
            'customerNumber' => 'customerNumber', 
        );
    }

    /**
     * return related table name
     */
    public function getSource() : string
    {
        return 'orders';
    }


}

