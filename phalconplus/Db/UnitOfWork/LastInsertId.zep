namespace PhalconPlus\Db\UnitOfWork;
use \PhalconPlus\Db\UnitOfWork;

class LastInsertId extends AbstractValue
{
    protected model;

    public function __construct(<\Phalcon\Mvc\Model> model)
    {
        let this->model = model;
    }

    public function getValue(<UnitOfWork> unitwork)
    {
        var modelClass = get_class(this->model);
        var modelHash = spl_object_hash(this->model);
        var inserted = unitwork->getInserted();
        inserted->rewind();
        while(inserted->valid()) {
            var obj = inserted->current();
            if inserted->getHash(obj) == modelHash {
                var info = inserted->getInfo();
                return info["last_insert_id"];
            }
            inserted->next();
        }
        throw new \PhalconPlus\Base\Exception("Object(".modelHash.") instance of ".modelClass." not in SplObjectStorage");
    }

    public function __toString()
    {
        return "LastInsertId: " . spl_object_hash(this->model);
    }
}
