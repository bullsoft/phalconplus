namespace PhalconPlus\Base;
use PhalconPlus\Base\Pagable;
use PhalconPlus\Assert\Assertion as Assert;
use Phalcon\Db\AdapterInterface;
use Phalcon\Mvc\Model\Transaction\Manager as TxManager;


// use Phalcon\Mvc\Model;
// use Phalcon\Mvc\ModelMessage;
// use Phalcon\Db\RawValue;

class Model extends \Phalcon\Mvc\Model
{
    // 记录创建时间
    public ctime;
    // 记录更新时间
    public mtime;

    public function initialize()
    {
        self::setUp([
            "notNullValidations" : false,
            "castOnHydrate" : true,
            "forceCasting" : true
        ]);
        this->useDynamicUpdate(true);
        this->keepSnapshots(true);
    }

    public function getMessage()
    {
        return this->getFirstMessage();
    }

    public function getFirstMessage()
    {
        if count(this->getMessages("")) {
            return (string) current(this->getMessages(""));
        }
        return false;
    }

    public function getLastMessage()
    {
        if count(this->getMessages("")) {
            return (string) end(this->getMessages(""));
        }
        return false;
    }

    public function createBuilder(string! alias = "") -> <\Phalcon\Mvc\Model\Query\BuilderInterface>
    {
        var source;
        if !empty alias {
            let source = [alias:get_called_class()];
        } else {
            let source  = get_called_class();
        }
        return this->getModelsManager()->createBuilder()->from(source);
    }

    public static function getInstance() -> <\Phalcon\Mvc\Model>
    {
        var className;
        let className = get_called_class();
        return new {className}();
    }

    public static function batchInsert(array columns, array rows)
    {
        var model, conn, e, row;
        var columnMap = [], newColumns = [];

        var className;
        let className = get_called_class();
        let model = new {className}();
        
        if method_exists(model, "columnMap") {
            let columnMap = array_flip(model->columnMap());
            var val;
            for val in columns {
                if isset(columnMap[val]) {
                    let newColumns[] = columnMap[val];
                }
            }
        } else {
            let newColumns = columns;
        }
        let conn = model->getWriteConnection();
        try {
            conn->begin();
            for row in rows {
                conn->insert(model->getSource(), row, newColumns);
            }
            conn->commit();
        } catch \Exception, e {
            conn->rollback();
            throw e;
        }
        
        return true;
    }

    public function beforeValidationOnCreate()
    {
        let this->ctime = date("Y-m-d H:i:s");
        let this->mtime = this->ctime;
    }

    public function afterFetch()
    {
        // nothing
    }

    public function beforeSave()
    {
        let this->mtime = date("Y-m-d H:i:s");
        return true;
    }

    /**
     * find with paginator
     * @var array params
     *    - params["columns"]
     *    - params["conditions"]
     *    - params["bind"]
     *
     */
    public function findByPagable(<Pagable> pagable, array params = [])
    {
        Assert::notNull(pagable, __CLASS__."::".__METHOD__ .": Pagable can not be null");
        
        var builder;
        let builder = this->createBuilder();
        
        var val, orderBys = [];

        let orderBys = array_map("strval", pagable->getOrderBys());
        if !empty orderBys {
            // error_log(var_export(orderBys, true));
            builder->orderBy(implode(", ", orderBys));
        }

        if fetch val, params["columns"] {
            builder->columns(val);
        } else {
            builder->columns("*");
        }

        var bind = [];
        if fetch val, params["bind"] {
            let bind = val;
        }
        
        if fetch val, params["conditions"] {
            if empty bind {
                builder->where(val);
            } else {
                builder->where(val, bind);
            }
        }
        var queryBuilder, page;
        let queryBuilder = new \Phalcon\Paginator\Adapter\QueryBuilder([
            "builder":builder,
            "limit":pagable->getPageSize(),
            "page":pagable->getPageNo()
        ]);
        
        let page = queryBuilder->getPaginate();
        // error_log(var_export(pagable->toArray(), true));

        return new Page(pagable, page->total_items, page->items);
    }

    /**
     * Check if a reord is already exists?
     */
    public function exists() -> boolean
    {
        var metaData, readConnection, schema, source, table;
        let
            metaData = this->getModelsMetaData(),
            readConnection = this->getReadConnection();
        let
            schema = this->getSchema(),
            source = this->getSource();

        if schema {
            let table = [schema, source];
        } else {
            let table = source;
        }

        if this->_exists(metaData, readConnection, table) {
            return true;
        } else {
            return false;
        }
    }

    public function toProtoBuffer(columns = null) -> <ProtoBuffer>
    {
        var proto, toArray, key, val;
        let toArray = this->toArray(columns);
        let proto = new ProtoBuffer();
        for key, val in toArray {
            let proto->{key} = is_scalar(val)?val:strval(val);
        }
        return proto;
    }

    /**
     *
     * Once in a transaction, a read-sql should always use the write connection for the data consistency.
     * But, if you do not like this, you can rewrite this method Or use <\PhalconPlus\Db\UnitOfWork>
     *
     */
    public function selectReadConnection() -> <AdapterInterface>
    {
        var txm, transaction;
        if !this->getDI()->has("txm") {
            return this->getReadConnection();
        }
        let txm = this->getDI()->get("txm");
        if !(txm instanceof TxManager) {
            return this->getReadConnection();
        }
        txm->setDbService(this->getWriteConnectionService());
        let transaction = txm->get(false); // just get an instance, not begin a transaction really
        if(transaction->isValid()) {
            return this->getWriteConnection();
        } else {
            return this->getReadConnection();
        }
    }
}
