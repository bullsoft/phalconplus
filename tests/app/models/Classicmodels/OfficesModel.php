<?php

namespace PhalconPlus\Test\Models\Classicmodels;

/**
 * Phalcon Model: OfficesModel
 *
 * 此文件由代码自动生成，代码依赖PhalconPlus和Zend\Code\Generator
 *
 * @namespace PhalconPlus\Test\Models\Classicmodels
 * @version $Rev:2018-12-27 10:20:54$
 * @license PhalconPlus( http://plus.phalconphp.org/license-1.0.html )
 */
class OfficesModel extends ModelBase
{

    /**
     * @var integer
     * @table offices
     */
    public $id = null;

    /**
     * @var string
     * @table offices
     */
    public $officeCode = null;

    /**
     * @var string
     * @table offices
     */
    public $city = null;

    /**
     * @var string
     * @table offices
     */
    public $phone = null;

    /**
     * @var string
     * @table offices
     */
    public $addressLine1 = null;

    /**
     * @var string
     * @table offices
     */
    public $addressLine2 = null;

    /**
     * @var string
     * @table offices
     */
    public $state = null;

    /**
     * @var string
     * @table offices
     */
    public $country = null;

    /**
     * @var string
     * @table offices
     */
    public $postalCode = null;

    /**
     * @var string
     * @table offices
     */
    public $territory = null;

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
        $this->officeCode = NULL;
        $this->city = NULL;
        $this->phone = NULL;
        $this->addressLine1 = NULL;
        $this->addressLine2 = NULL;
        $this->state = NULL;
        $this->country = NULL;
        $this->postalCode = NULL;
        $this->territory = NULL;
    }

    /**
     * Column map for database fields and model properties
     */
    public function columnMap()
    {
        return array(
            'officeCode' => 'officeCode', 
            'city' => 'city', 
            'phone' => 'phone', 
            'addressLine1' => 'addressLine1', 
            'addressLine2' => 'addressLine2', 
            'state' => 'state', 
            'country' => 'country', 
            'postalCode' => 'postalCode', 
            'territory' => 'territory', 
        );
    }

    /**
     * return related table name
     */
    public function getSource()
    {
        return 'offices';
    }


}

