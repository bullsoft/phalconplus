<?php

namespace PhalconPlus\Test\Models\Classicmodels;

/**
 * Phalcon Model: OrderdetailsModel
 *
 * 此文件由代码自动生成，代码依赖PhalconPlus和Zend\Code\Generator
 *
 * @namespace PhalconPlus\Test\Models\Classicmodels
 * @version $Rev:2018-12-27 10:20:54$
 * @license PhalconPlus( http://plus.phalconphp.org/license-1.0.html )
 */
class OrderdetailsModel extends ModelBase
{

    /**
     * @var integer
     * @table orderdetails
     */
    public $id = null;

    /**
     * @var integer
     * @table orderdetails
     */
    public $ordersId = null;

    /**
     * @var integer
     * @table orderdetails
     */
    public $orderNumber = null;

    /**
     * @var string
     * @table orderdetails
     */
    public $productCode = null;

    /**
     * @var integer
     * @table orderdetails
     */
    public $quantityOrdered = null;

    /**
     * @var float
     * @table orderdetails
     */
    public $priceEach = null;

    /**
     * @var integer
     * @table orderdetails
     */
    public $orderLineNumber = null;

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
        $this->productCode = NULL;
        $this->quantityOrdered = NULL;
        $this->priceEach = NULL;
        $this->orderLineNumber = NULL;
    }

    /**
     * Column map for database fields and model properties
     */
    public function columnMap()
    {
        return array(
            'orderNumber' => 'orderNumber', 
            'productCode' => 'productCode', 
            'quantityOrdered' => 'quantityOrdered', 
            'priceEach' => 'priceEach', 
            'orderLineNumber' => 'orderLineNumber', 
        );
    }

    /**
     * return related table name
     */
    public function getSource() : string
    {
        return 'orderdetails';
    }


}

