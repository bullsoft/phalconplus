namespace PhalconPlus\Db\UnitOfWork;
use \PhalconPlus\Db\UnitOfWork;

class Field extends AbstractValue
{
    protected model = null;
    protected attr = "";

    public function __construct(<\Phalcon\Mvc\Model> model, string! attr)
    {
        let this->model = model;
        let this->attr = attr;
    }

    public function getValue(<UnitOfWork> unitwork)
    {
        var className = get_class(this->model);
        var hash = spl_object_hash(this->model);

        var objs = unitwork->getObjects();
        objs->rewind();
        while(objs->valid()) {
            var obj = objs->current();
            if objs->getHash(obj) == hash {
                var attr = this->attr;
                return obj->{attr};
            }
            objs->next();
        }
        throw new \Exception("Object(".hash.") instance of ".className." not in SplObjectStorage");
    }

    public function getField(<UnitOfWork> unitwork) 
    {
        return this->getValue(unitwork);
    }

    public function __toString()
    {
        return "Field" . spl_object_hash(this->model);
    }
}