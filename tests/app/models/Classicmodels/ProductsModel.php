<?php

namespace PhalconPlus\Test\Models\Classicmodels;

/**
 * Phalcon Model: ProductsModel
 *
 * 此文件由代码自动生成，代码依赖PhalconPlus和Zend\Code\Generator
 *
 * @namespace PhalconPlus\Test\Models\Classicmodels
 * @version $Rev:2018-12-27 10:20:54$
 * @license PhalconPlus( http://plus.phalconphp.org/license-1.0.html )
 */
class ProductsModel extends ModelBase
{

    /**
     * @var integer
     * @table products
     */
    public $id = null;

    /**
     * @var string
     * @table products
     */
    public $productCode = null;

    /**
     * @var string
     * @table products
     */
    public $productName = null;

    /**
     * @var string
     * @table products
     */
    public $productLine = null;

    /**
     * @var string
     * @table products
     */
    public $productScale = null;

    /**
     * @var string
     * @table products
     */
    public $productVendor = null;

    /**
     * @var string
     * @table products
     */
    public $productDescription = null;

    /**
     * @var integer
     * @table products
     */
    public $quantityInStock = null;

    /**
     * @var float
     * @table products
     */
    public $buyPrice = null;

    /**
     * @var float
     * @table products
     */
    public $MSRP = null;

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
        $this->productCode = NULL;
        $this->productName = NULL;
        $this->productLine = NULL;
        $this->productScale = NULL;
        $this->productVendor = NULL;
        $this->productDescription = NULL;
        $this->quantityInStock = NULL;
        $this->buyPrice = NULL;
        $this->MSRP = NULL;
    }

    /**
     * Column map for database fields and model properties
     */
    public function columnMap()
    {
        return array(
            'productCode' => 'productCode', 
            'productName' => 'productName', 
            'productLine' => 'productLine', 
            'productScale' => 'productScale', 
            'productVendor' => 'productVendor', 
            'productDescription' => 'productDescription', 
            'quantityInStock' => 'quantityInStock', 
            'buyPrice' => 'buyPrice', 
            'MSRP' => 'MSRP', 
        );
    }

    /**
     * return related table name
     */
    public function getSource()
    {
        return 'products';
    }


}

