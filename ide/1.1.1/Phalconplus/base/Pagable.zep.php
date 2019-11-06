<?php

namespace PhalconPlus\Base;

use PhalconPlus\Enum\OrderByDirection;

class Pagable extends \PhalconPlus\Base\ProtoBuffer
{

    const DEFAULT_PAGE_NO = 1;


    const DEFAULT_PAGE_SIZE = 15;


    protected $pageNo = self::DEFAULT_PAGE_NO;


    protected $pageSize = self::DEFAULT_PAGE_SIZE;


    protected $orderBys = array();


    /**
     * @return int
     */
    public function getPageNo(): int
    {
    }

    /**
     * @return int
     */
    public function getPageSize(): int
    {
    }

    /**
     * @return \PhalconPlus\Base\ProtoOrderBy
     */
    public function getOrderBys(): \PhalconPlus\Base\ProtoOrderBy
    {
    }

    /**
     * @return int
     */
    public function getOffset(): int
    {
    }

    /**
     * @return int
     */
    public function getLimit(): int
    {
    }

    /**
     * @param \PhalconPlus\Base\ProtoOrderBy $orderBy
     */
    public function setOrderBy(\PhalconPlus\Base\ProtoOrderBy $orderBy)
    {
    }

    /**
     * @param array $orderBys
     */
    public function setOrderBys(array $orderBys)
    {
    }


    public function hasOrderBy()
    {
    }

    /**
     * @param mixed $pageNo
     */
    public function setPageNo($pageNo)
    {
    }

    /**
     * @param mixed $pageSize
     */
    public function setPageSize($pageSize)
    {
    }

}
