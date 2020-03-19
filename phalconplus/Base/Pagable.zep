namespace PhalconPlus\Base;
use PhalconPlus\Enum\OrderByDirection;
use PhalconPlus\Base\ProtoOrderBy;

class Pagable extends ProtoBuffer
{
    const DEFAULT_PAGE_NO = 1;
    const DEFAULT_PAGE_SIZE = 20;

    protected pageNo = 0;
    protected pageSize = 0;
    protected orderBys = [];

    public function __construct(int pageNo = 0, int pageSize = 0, array orderBys = [])
    {
        if pageNo < 1 {
            let pageNo = Pagable::DEFAULT_PAGE_NO;
        }
        if pageSize < 1 {
            let pageSize = Pagable::DEFAULT_PAGE_SIZE;
        }
        
        this->setPageNo(pageNo)
            ->setPageSize(pageSize);

        if !empty orderBys {
            this->setOrderBys(orderBys);
        }
    }

    public static function fromArray(array pages, bool cursor = false)
    {
        int pageNo, pageSize;
        if cursor == false {
            let pageNo = isset(pages["pageNo"]) ? (int) pages["pageNo"] : 0;
            let pageSize = isset(pages["pageSize"]) ? (int) pages["pageSize"] : 0;
        } else {
            let pageSize = (int) pages["limit"];
            let pageNo = intval(ceil(intval(pages["offset"]) / pageSize)) + 1; 
        }
        var clsInst = null,
            clsName = get_called_class();
        let clsInst = new {clsName}(pageNo, pageSize);
        if isset pages["orderBys"] {
            clsInst->setOrderBys(pages["orderBys"]);
        }
        return clsInst;
    }

    public function getPageNo() -> int
    {
        return this->pageNo;
    }

    public function getPageSize() -> int
    {
        return this->pageSize;
    }

    public function getOrderBys() -> <ProtoOrderBy>
    {
        return this->orderBys;
    }

    public function getOffset() -> int
    {
        return (this->pageNo - 1) * this->pageSize;
    }

    public function getLimit() -> int
    {
        return this->pageSize;
    }

    public function setOrderBy(<ProtoOrderBy> orderBy)
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
        return this;
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
