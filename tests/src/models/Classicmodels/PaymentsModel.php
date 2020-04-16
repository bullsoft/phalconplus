<?php

namespace PhalconPlus\Test\Models\Classicmodels;

/**
 * Phalcon Model: PaymentsModel
 *
 * 此文件由代码自动生成，代码依赖PhalconPlus和Zend\Code\Generator
 *
 * @namespace PhalconPlus\Test\Models\Classicmodels
 * @version $Rev:2018-12-27 10:20:54$
 * @license PhalconPlus( http://plus.phalconphp.org/license-1.0.html )
 */
class PaymentsModel extends ModelBase
{

    /**
     * @var integer
     * @table payments
     */
    public $id = null;

    /**
     * @var integer
     * @table payments
     */
    public $customerNumber = null;

    /**
     * @var string
     * @table payments
     */
    public $checkNumber = null;

    /**
     * @var date
     * @table payments
     */
    public $paymentDate = null;

    /**
     * @var float
     * @table payments
     */
    public $amount = null;

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
        $this->checkNumber = NULL;
        $this->paymentDate = NULL;
        $this->amount = NULL;
    }

    /**
     * Column map for database fields and model properties
     */
    public function columnMap()
    {
        return array(
            'customerNumber' => 'customerNumber', 
            'checkNumber' => 'checkNumber', 
            'paymentDate' => 'paymentDate', 
            'amount' => 'amount', 
        );
    }

    /**
     * return related table name
     */
    public function getSource()
    {
        return 'payments';
    }


}

