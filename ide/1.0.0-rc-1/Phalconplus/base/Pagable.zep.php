<?php

namespace PhalconPlus\Base;


class Pagable extends \PhalconPlus\Base\ProtoBuffer
{

    const DEFAULT_PAGE_NO = 1;


    const DEFAULT_PAGE_SIZE = 15;


    private $pageNo = 0;


    private $pageSize = 0;


    private $orderBys = array();



    public function getPageNo() {}


    public function getPageSize() {}

    /**
     * @return \PhalconPlus\Base\ProtoOrderBy
     */
    public function getOrderBys(): \PhalconPlus\Base\ProtoOrderBy {}

    /**
     * @param \PhalconPlus\Base\ProtoOrderBy $orderBy
     */
    public function setOrderBy(\PhalconPlus\Base\ProtoOrderBy $orderBy) {}

    /**
     * @param mixed $pageNo
     */
    public function setPageNo($pageNo) {}

    /**
     * @param mixed $pageSize
     */
    public function setPageSize($pageSize) {}

}
