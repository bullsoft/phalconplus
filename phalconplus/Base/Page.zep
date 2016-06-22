namespace PhalconPlus\Base;
use PhalconPlus\Assert\Assertion as Assert;

class Page extends ProtoBuffer
{
    private pagable;

    private data;

    private totalSize;

    private pageNo;

    private pageSize;

    private totalPage;

    public function __construct(<Pagable> pagable, totalSize, <\Phalcon\Mvc\Model\Resultset> data)
    {
        Assert::notNull(pagable);
        let this->pagable = pagable;
        let this->data = data;
        let this->totalSize = totalSize;

        // initialize
        this->setPageNo()
            ->setPageSize()
            ->setTotalPage();
    }

    public function setPageNo()
    {
        let this->pageNo = this->pagable->getPageNo();
        return this;
    }

    public function setPageSize()
    {
        let this->pageSize = this->pagable->getPageSize();
        return this;
    }

    public function setTotalPage()
    {
        let this->totalPage = ceil(this->totalSize / this->pageSize);
        return this;
    }

    public function getPageNo()
    {
        return this->pageNo;
    }

    public function getTotalPage()
    {
        return this->totalPage;
    }

    public function getTotalSize()
    {
        return this->totalSize;
    }

    public function hasPreviousPage()
    {
        return this->pageNo > 1;
    }

    public function isFirstPage()
    {
        return !this->hasPreviousPage();
    }

    public function isLastPage()
    {
        return !this->hasNextPage();
    }

    public function hasNextPage()
    {
        return this->getPageNo() < this->getTotalPage();
    }

    public function getData()
    {
        return this->data;
    }

    public function isEmpty()
    {
        return count(this->data) == 0;
    }

    public function data2Array()
    {
        let this->data = this->data->toArray();
        return this;
    }
}
