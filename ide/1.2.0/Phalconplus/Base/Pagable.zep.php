<?php

namespace PhalconPlus\Base;

use PhalconPlus\Enum\OrderByDirection;
use PhalconPlus\Base\ProtoOrderBy;

class Pagable extends \PhalconPlus\Base\ProtoBuffer
{

    const DEFAULT_PAGE_NO = 1;


    const DEFAULT_PAGE_SIZE = 20;


    protected $pageNo = 0;


    protected $pageSize = 0;


    protected $orderBys = array();


    /**
     * @param int $pageNo
     * @param int $pageSize
     * @param array $orderBys
     */
    public function __construct(int $pageNo = 0, int $pageSize = 0, array $orderBys = array())
    {
    }

    /**
     * @param array $pages
     * @param bool $cursor
     * @return Pagable
     */
    public static function fromArray(array $pages, bool $cursor = false): Pagable
    {
    }

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
     * @return ProtoOrderBy
     */
    public function getOrderBys(): ProtoOrderBy
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
     * @return Pagable
     */
    public function setOrderBy(\PhalconPlus\Base\ProtoOrderBy $orderBy): Pagable
    {
    }

    /**
     * @param array $orderBys
     * @return Pagable
     */
    public function setOrderBys(array $orderBys): Pagable
    {
    }

    /**
     * @return bool
     */
    public function hasOrderBy(): bool
    {
    }

    /**
     * @param mixed $pageNo
     * @return Pagable
     */
    public function setPageNo($pageNo): Pagable
    {
    }

    /**
     * @param mixed $pageSize
     * @return Pagable
     */
    public function setPageSize($pageSize): Pagable
    {
    }

}
