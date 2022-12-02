namespace PhalconPlus\Db\UnitOfWork;
use PhalconPlus\Db\UnitOfWork;
use PhalconPlus\Base\Exception as BaseException;
use PhalconPlus\Contracts\Stringer;
use Phalcon\Mvc\Model as PhModel;

class Field extends AbstractValue implements Stringer
{
    protected model = null;
    protected attr = "";

    public function __construct(<PhModel> model, string! attr)
    {
        let this->model = model;
        let this->attr = attr;
    }

    public function getValue(<UnitOfWork> unitwork)
    {
        var className = get_class(this->model);
        var hash = spl_object_hash(this->model);
        var objs = unitwork->getObjects();

        if objs->contains(this->model) {
            var attr = this->attr;
            if property_exists(this->model, attr) {
                return this->model->{attr};
            }
            return null;
        }

        throw new BaseException("Object(".hash.") instance of ".className." not in SplObjectStorage");
    }

    public function getField(<UnitOfWork> unitwork)
    {
        return this->getValue(unitwork);
    }

    public function __toString() -> string
    {
        return "Field: " . this->attr . ", Hash: " . spl_object_hash(this->model);
    }
}
