<?php

namespace PhalconPlus\Base;


class Page extends \PhalconPlus\Base\ProtoBuffer
{

    private $pagable;


    private $data;


    private $totalSize;


    private $pageNo;


    private $pageSize;


    private $totalPage;


    /**
     * @param Pagable $pagable
     * @param mixed $totalSize
     * @param \Phalcon\Mvc\Model\Resultset $data
     */
    public function __construct(Pagable $pagable, $totalSize, \Phalcon\Mvc\Model\Resultset $data) {}


    public function setPageNo() {}


    public function setPageSize() {}


    public function setTotalPage() {}


    public function getPageNo() {}


    public function getTotalPage() {}


    public function getTotalSize() {}


    public function hasPreviousPage() {}


    public function isFirstPage() {}


    public function isLastPage() {}


    public function hasNextPage() {}


    public function getData() {}


    public function isEmpty() {}

}
