//<?php
namespace PhalconPlus\Db;

use SplObjectStorage;
use Exception;
use Phalcon\Mvc\Model\Transaction\Manager as TxManager;
use Phalcon\Mvc\Model\Transaction\Failed as TxFailed;

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
            this->insert(name, model, initial_data, false);
        } else {
            this->update(name, model, initial_data, false);
        } 
    }
    
    public function insert(var name, <\Phalcon\Mvc\Model> model, array initial_data = [], boolean assign = true)
    {      
        if !empty initial_data && assign == true {
            model->assign(initial_data);
        }
        this->detach(model);
        this->attach(model, [
            "method" : "insert",
            "name" : name,
            "initial_data" : initial_data
        ]);
    }

    public function update(var name, <\Phalcon\Mvc\Model> model, array initial_data = [], boolean assign = true)
    {    
        if !empty initial_data && assign == true {
            model->assign(initial_data);
        }  
        this->detach(model);
        this->attach(model, [
            "method" : "update",
            "name" : name,
            "initial_data" : initial_data
        ]);
    }

    public function delete(var name, <\Phalcon\Mvc\Model> model)
    {
        this->detach(model);
        this->attach(model, [
            "method" : "delete",
            "name" : name
        ]);
    }

    protected function attach(var model, var info)
    {
        this->objects->attach(model, info);
    }

    public function detach(model)
    {
        this->objects->detach(model);
    }

    public function exec()
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

        var obj, info;
        this->objects->rewind();
        try {
            while(this->objects->valid()) {
                let obj = this->objects->current();
                let info = this->objects->getInfo();

                var method, name;
                let method = info["method"];
                let name = info["name"];

                unset(info["method"]); unset(info["name"]);

                obj->setTransaction(transaction);

                var newMethod;
                let newMethod = "exec".ucfirst(method);
                if (this->{newMethod}(obj, info) == false) {
                    transaction->rollback("Model exec failed: " . name . ":" . method);
                }
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
                if is_callable(val) {
                    let initial_data[col] = {val}();
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

    public function execUpdate(<\Phalcon\Mvc\Model> model, array info = [])
    {
        var result, initial_data;
        let initial_data = info["initial_data"];
        if(!empty(initial_data)) {
            var col, val;
            for col, val in initial_data {
                if is_callable(val) {
                    let initial_data[col] = {val}();
                }
            }
            let result = model->update(initial_data);
        } else {
            let result = model->update();
        }
        if result == true {
            this->updated->attach(model);
        }
        return result;
    }

    public function execDelete(<\Phalcon\Mvc\Model> model, array info = [])
    {
        var result;
        let result = model->delete();
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

