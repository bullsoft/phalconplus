<?php

namespace PhalconPlus\Base;

use PhalconPlus\Assert\Assertion as Assert;
use Phalcon\Mvc\Model\Resultset;

class Page extends \PhalconPlus\Base\ProtoBuffer
{
    /**
     * @var <\Phalcon\Base\Pagable>
     */
    private $pagable = null;

    /**
     * @var mixed array | <ArrayObject>
     */
    private $data = null;


    private $totalSize = 0;


    private $pageNo = 0;


    private $pageSize = 0;


    private $totalPage = 0;


    /**
     * @param Pagable $pagable
     * @param mixed $totalSize
     * @param \Phalcon\Mvc\Model\Resultset $data
     */
    public function __construct(Pagable $pagable, $totalSize, \Phalcon\Mvc\Model\Resultset $data)
    {
    }


    public function setPageNo()
    {
    }


    public function setPageSize()
    {
    }


    public function setTotalPage()
    {
    }


    public function getPageNo()
    {
    }


    public function getTotalPage()
    {
    }


    public function getTotalSize()
    {
    }


    public function hasPreviousPage()
    {
    }


    public function isFirstPage()
    {
    }


    public function isLastPage()
    {
    }


    public function hasNextPage()
    {
    }


    public function getData()
    {
    }


    public function isEmpty()
    {
    }

}
