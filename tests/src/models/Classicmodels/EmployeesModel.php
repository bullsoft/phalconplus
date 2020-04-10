<?php

namespace PhalconPlus\Test\Models\Classicmodels;

/**
 * Phalcon Model: EmployeesModel
 *
 * 此文件由代码自动生成，代码依赖PhalconPlus和Zend\Code\Generator
 *
 * @namespace PhalconPlus\Test\Models\Classicmodels
 * @version $Rev:2018-12-27 10:20:54$
 * @license PhalconPlus( http://plus.phalconphp.org/license-1.0.html )
 */
class EmployeesModel extends ModelBase
{

    /**
     * @var integer
     * @table employees
     */
    public $id = null;

    /**
     * @var integer
     * @table employees
     */
    public $employeeNumber = null;

    /**
     * @var string
     * @table employees
     */
    public $lastName = null;

    /**
     * @var string
     * @table employees
     */
    public $firstName = null;

    /**
     * @var string
     * @table employees
     */
    public $extension = null;

    /**
     * @var string
     * @table employees
     */
    public $email = null;

    /**
     * @var string
     * @table employees
     */
    public $officeCode = null;

    /**
     * @var integer
     * @table employees
     */
    public $reportsTo = null;

    /**
     * @var string
     * @table employees
     */
    public $jobTitle = null;

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
        $this->employeeNumber = NULL;
        $this->lastName = NULL;
        $this->firstName = NULL;
        $this->extension = NULL;
        $this->email = NULL;
        $this->officeCode = NULL;
        $this->reportsTo = NULL;
        $this->jobTitle = NULL;
    }

    /**
     * Column map for database fields and model properties
     */
    public function columnMap()
    {
        return array(
            'employeeNumber' => 'employeeNumber', 
            'lastName' => 'lastName', 
            'firstName' => 'firstName', 
            'extension' => 'extension', 
            'email' => 'email', 
            'officeCode' => 'officeCode', 
            'reportsTo' => 'reportsTo', 
            'jobTitle' => 'jobTitle', 
        );
    }

    /**
     * return related table name
     */
    public function getSource() : string
    {
        return 'employees';
    }


}

