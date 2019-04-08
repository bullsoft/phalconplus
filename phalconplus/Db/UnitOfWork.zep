namespace PhalconPlus\Db;

use SplObjectStorage;
use Exception;
use Phalcon\Mvc\Model\Transaction\Manager as TxManager;
use Phalcon\Mvc\Model\Transaction\Failed as TxFailed;
use PhalconPlus\Db\UnitOfWork\AbstractValue;
use Phalcon\Mvc\Model as Model;
use Phalcon\Mvc\Model\Resultset as Resultset;

class UnitOfWork
{
    protected modelLocator = [];

    protected dbServiceName;

    protected objects;

    protected inserted;

    protected updated;

    protected deleted;

    protected exception;

    protected failed;

    public function __construct(var dbServiceName)
    {
        let this->objects = new SplObjectStorage();
        let this->dbServiceName = dbServiceName;
    }

    public function save(var name, <\PhalconPlus\Base\Model> model, array initial_data = [])
    {
        if !empty initial_data {
            model->assign(initial_data);
        }
        if !model->exists() {
            this->insert(name, model, initial_data);
        } else {
            this->update(name, model, initial_data);
        }
    }

    public function insert(var name, <\PhalconPlus\Base\Model> model, array initial_data = [])
    {
        this->detach(model);
        this->attach(model, [
            "method" : "insert",
            "name" : name,
            "initial_data" : initial_data
        ]);
    }

    /**
     * @param \Phalcon\Mvc\Model | \Phalcon\Mvc\Model\Resultset model
     */
    public function update(var name, var model, array initial_data = [])
    {
        if (model instanceof Model) || (model instanceof Resultset) {
            this->detach(model);
            this->attach(model, [
                "method" : "update",
                "name" : name,
                "initial_data" : initial_data
            ]);
        } else {
            throw new Exception("UnitOfWork: Accept <Model> & <Resultset> only");
        }
    }

    /**
     * @param \Phalcon\Mvc\Model | \Phalcon\Mvc\Model\Resultset model
     */
    public function delete(var name, object model)
    {
        if (model instanceof Model) || (model instanceof Resultset) {
            this->detach(model);
            this->attach(model, [
                "method" : "delete",
                "name" : name
            ]);
        } else {
            throw new Exception("UnitOfWork: Accept <Model> & <Resultset> only");
        }
    }

    protected function attach(var model, var info)
    {
        this->objects->attach(model, info);
    }

    public function detach(model)
    {
        this->objects->detach(model);
    }

    public function exec() -> boolean
    {
        let this->exception = null;
        let this->failed = null;
        let this->deleted = new SplObjectStorage();
        let this->inserted = new SplObjectStorage();
        let this->updated = new SplObjectStorage();

        var txManager, transaction, e;

        let txManager = new TxManager();
        txManager->setDbService(this->dbServiceName);
        let transaction = txManager->get();

        var obj, info, newMethod;
        this->objects->rewind();

        try {
            while(this->objects->valid()) {
                let obj = this->objects->current();
                let info = this->objects->getInfo();
                var hash = spl_object_hash(obj);

                var method = info["method"]; unset(info["method"]);
                var name = info["name"]; unset(info["name"]);

                if obj instanceof \Phalcon\Mvc\Model {
                    obj->setTransaction(transaction);
                } elseif obj instanceof \Phalcon\Mvc\Model\Resultset {
                    iterator_apply(obj, function(<\Iterator> iterator, transaction) {
                        iterator->current()->setTransaction(transaction);
                    }, [obj, transaction]);
                }

                if !isset this->modelLocator[hash] {
                    let newMethod = "exec".ucfirst(method);
                    if this->{newMethod}(obj, info) == false {
                        transaction->rollback("Model exec failed: " . name . ":" . newMethod .
                                              ". Model Exception: " . json_encode(obj->getMessages())
                                             );
                    }
                    let this->modelLocator[hash] = obj;
                }
                //echo "Key: " . this->objects->key() . " Name: " . name . " Obj: " . get_class(obj) . PHP_EOL;
                this->objects->next();
            }
            transaction->commit();
        } catch TxFailed, e {
            let this->failed = obj;
            let this->exception = e;
            return false;
        }
        return true;
    }

    public function execInsert(<\Phalcon\Mvc\Model> model, array info)
    {
        var initial_data, result, last_insert_id;
        let initial_data = info["initial_data"];

        if !empty(initial_data) {
            var col, val;
            for col, val in initial_data {
                if is_object(val) && val instanceof AbstractValue {
                    if val instanceof \PhalconPlus\Db\UnitOfWork\LastInsertId {
                        let initial_data[col] = val->getValue(this);
                    } elseif val instanceof \PhalconPlus\Db\UnitOfWork\Field {
                        let initial_data[col] = val->getField(this);
                    }
                }
            }
            let result = model->create(initial_data);
        } else {
            let result = model->create();
        }
        if result == true {
            let last_insert_id = model->getWriteConnection()->lastInsertId();
            this->inserted->attach(model, [
                "last_insert_id" : last_insert_id
            ]);
        }
        return result;
    }

    public function execUpdate(var model, array info = [])
    {
        var result, initial_data;

        let initial_data = info["initial_data"];
        if !empty(initial_data) {
            var col, val;
            for col, val in initial_data {
                if is_object(val) && val instanceof AbstractValue {
                    let initial_data[col] = val->getValue(this);;
                }
            }
            let result = model->update(initial_data);
        } else {
            let result = model->update();
        }
        if result == true {
            this->updated->attach(model, [
                "updated_data": initial_data
            ]);
        }
        return result;
    }

    public function execDelete(var model, array info = [])
    {
        var result = model->delete();
        if result == true {
            this->deleted->attach(model);
        }
        return result;
    }

    public function getObjects()
    {
        return this->objects;
    }

    public function getInserted()
    {
        return this->inserted;
    }

    public function getUpdated()
    {
        return this->updated;
    }

    public function getDeleted()
    {
        return this->deleted;
    }

    public function getException()
    {
        return this->exception;
    }

    public function getFailed()
    {
        return this->failed;
    }
}
