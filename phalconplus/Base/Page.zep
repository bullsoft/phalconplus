namespace PhalconPlus\Base;
use PhalconPlus\Assert\Assertion as Assert;
use Phalcon\Mvc\Model\Resultset;

class Page extends ProtoBuffer
{
    /**
     * @var <\Phalcon\Base\Pagable>
     */
    private pagable = null;

    /**
     * @var mixed array | <ArrayObject>
     */ 
    private data = null;

    private totalSize = 0;

    private pageNo = 0;

    private pageSize = 0;

    private totalPage = 0;

    public function __construct(<Pagable> pagable, totalSize, <\Phalcon\Mvc\Model\Resultset> data)
    {
        Assert::notNull(pagable);

        var hydrateMode, tmpData, item;

        let this->pagable = pagable;

        let hydrateMode = data->getHydrateMode();

        switch(hydrateMode) {
            case Resultset::HYDRATE_RECORDS:
                let tmpData = new \ArrayObject();
                let tmpData->modelName = get_class(data->getFirst());
                let tmpData->columnMap = data->getFirst()->columnMap();
                for item in iterator(data) {
                    tmpData->append(item->toArray());
                }
                break;
            default:
                let tmpData = [];
                for item in iterator(data) {
                    let tmpData[] = item;
                }
                break;
        }

        let this->data = tmpData;
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
}
