<?php

namespace PhalconPlus\Test\Models\Classicmodels;

/**
 * Phalcon Model: ProductlinesModel
 *
 * 此文件由代码自动生成，代码依赖PhalconPlus和Zend\Code\Generator
 *
 * @namespace PhalconPlus\Test\Models\Classicmodels
 * @version $Rev:2018-12-27 10:20:54$
 * @license PhalconPlus( http://plus.phalconphp.org/license-1.0.html )
 */
class ProductlinesModel extends ModelBase
{

    /**
     * @var string
     * @table productlines
     */
    public $productLine = null;

    /**
     * @var string
     * @table productlines
     */
    public $textDescription = null;

    /**
     * @var string
     * @table productlines
     */
    public $htmlDescription = null;

    /**
     * @var unknown
     * @table productlines
     */
    public $image = null;

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
        $this->productLine = NULL;
        $this->textDescription = NULL;
        $this->htmlDescription = NULL;
        $this->image = NULL;
    }

    /**
     * Column map for database fields and model properties
     */
    public function columnMap()
    {
        return array(
            'productLine' => 'productLine', 
            'textDescription' => 'textDescription', 
            'htmlDescription' => 'htmlDescription', 
            'image' => 'image', 
        );
    }

    /**
     * return related table name
     */
    public function getSource()
    {
        return 'productlines';
    }


}

