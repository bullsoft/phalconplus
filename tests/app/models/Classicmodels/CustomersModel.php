<?php

namespace PhalconPlus\Test\Models\Classicmodels;

/**
 * Phalcon Model: CustomersModel
 *
 * 此文件由代码自动生成，代码依赖PhalconPlus和Zend\Code\Generator
 *
 * @namespace PhalconPlus\Test\Models\Classicmodels
 * @version $Rev:2018-12-27 10:20:54$
 * @license PhalconPlus( http://plus.phalconphp.org/license-1.0.html )
 */
class CustomersModel extends ModelBase
{

    /**
     * @var integer
     * @table customers
     */
    public $id = null;

    /**
     * @var integer
     * @table customers
     */
    public $customerNumber = null;

    /**
     * @var string
     * @table customers
     */
    public $customerName = null;

    /**
     * @var string
     * @table customers
     */
    public $contactLastName = null;

    /**
     * @var string
     * @table customers
     */
    public $contactFirstName = null;

    /**
     * @var string
     * @table customers
     */
    public $phone = null;

    /**
     * @var string
     * @table customers
     */
    public $addressLine1 = null;

    /**
     * @var string
     * @table customers
     */
    public $addressLine2 = null;

    /**
     * @var string
     * @table customers
     */
    public $city = null;

    /**
     * @var string
     * @table customers
     */
    public $state = null;

    /**
     * @var string
     * @table customers
     */
    public $postalCode = null;

    /**
     * @var string
     * @table customers
     */
    public $country = null;

    /**
     * @var integer
     * @table customers
     */
    public $salesRepEmployeeNumber = null;

    /**
     * @var float
     * @table customers
     */
    public $creditLimit = null;

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
        $this->customerNumber = NULL;
        $this->customerName = NULL;
        $this->contactLastName = NULL;
        $this->contactFirstName = NULL;
        $this->phone = NULL;
        $this->addressLine1 = NULL;
        $this->addressLine2 = NULL;
        $this->city = NULL;
        $this->state = NULL;
        $this->postalCode = NULL;
        $this->country = NULL;
        $this->salesRepEmployeeNumber = NULL;
        $this->creditLimit = NULL;
    }

    /**
     * Column map for database fields and model properties
     */
    public function columnMap()
    {
        return array(
            'customerNumber' => 'customerNumber', 
            'customerName' => 'customerName', 
            'contactLastName' => 'contactLastName', 
            'contactFirstName' => 'contactFirstName', 
            'phone' => 'phone', 
            'addressLine1' => 'addressLine1', 
            'addressLine2' => 'addressLine2', 
            'city' => 'city', 
            'state' => 'state', 
            'postalCode' => 'postalCode', 
            'country' => 'country', 
            'salesRepEmployeeNumber' => 'salesRepEmployeeNumber', 
            'creditLimit' => 'creditLimit', 
        );
    }

    /**
     * return related table name
     */
    public function getSource()
    {
        return 'customers';
    }


}

