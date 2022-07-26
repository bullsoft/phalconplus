namespace PhalconPlus\Db\UnitOfWork;
use PhalconPlus\Db\UnitOfWork;
use PhalconPlus\Base\Exception as BaseException;
use PhalconPlus\Contracts\Stringer;
use Phalcon\Mvc\Model as PhModel;

class LastInsertId extends AbstractValue implements Stringer
{
    protected model;

    public function __construct(<PhModel> model)
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
            if isset(info["last_insert_id"]) && info["last_insert_id"] > 0 {
                return intval(info["last_insert_id"]);
            }
            return 0;
        }

        throw new BaseException("Object(".hash.") instance of ".className." not in SplObjectStorage");
    }

    public function __toString() -> string
    {
        return "LastInsertId: " . spl_object_hash(this->model);
    }
}
