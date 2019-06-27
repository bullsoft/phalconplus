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
        var className = get_class(this->model);
        var hash = spl_object_hash(this->model);
        var inserted = unitwork->getInserted();

        if inserted->contains(this->model) {
            var info = inserted[this->model];
            return info["last_insert_id"];
        }

        throw new \PhalconPlus\Base\Exception("Object(".hash.") instance of ".className." not in SplObjectStorage");
    }

    public function __toString()
    {
        return "LastInsertId: " . spl_object_hash(this->model);
    }
}
