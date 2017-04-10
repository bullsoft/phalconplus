namespace PhalconPlus\Base;

class Pagable extends ProtoBuffer
{
    const DEFAULT_PAGE_NO = 1;
    const DEFAULT_PAGE_SIZE = 15;

    private pageNo;
    private pageSize;
    private orderBys = [];

    public function getPageNo()
    {
        return this->pageNo;
    }

    public function getPageSize()
    {
        return this->pageSize;
    }

    public function getOrderBys() -> <\PhalconPlus\Base\ProtoOrderBy>
    {
        return this->orderBys;
    }

    public function setOrderBy(<\PhalconPlus\Base\ProtoOrderBy> orderBy)
    {
        array_push(this->orderBys, orderBy);
        return this;
    }

    public function setPageNo(var pageNo)
    {
        let this->pageNo = pageNo;
        return this;
    }

    public function setPageSize(var pageSize)
    {
        let this->pageSize = pageSize;
        return this;
    }

}
