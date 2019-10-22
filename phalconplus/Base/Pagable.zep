namespace PhalconPlus\Base;
use PhalconPlus\Enum\OrderByDirection as OrderByDirection;

class Pagable extends ProtoBuffer
{
    const DEFAULT_PAGE_NO = 1;
    const DEFAULT_PAGE_SIZE = 15;

    protected pageNo = self::DEFAULT_PAGE_NO;
    protected pageSize = self::DEFAULT_PAGE_SIZE;
    protected orderBys = [];

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

    public function setOrderBys(array orderBys)
    {
        var item;
        for item in orderBys {
            if isset(item["property"]) && isset(item["direction"]) {
                var orderBy, direction;
                let orderBy = new ProtoOrderBy();
                orderBy->setProperty(item["property"]);
                let direction = new OrderByDirection(item["direction"]);
                orderBy->setDirection(direction);
                this->setOrderBy(orderBy);
            }
        }
    }

    public function hasOrderBy()
    {
        return ! empty(this->orderBys);
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
