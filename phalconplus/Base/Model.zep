namespace PhalconPlus\Base;
use PhalconPlus\Base\Pagable;
use PhalconPlus\Assert\Assertion as Assert;
use Phalcon\Db\AdapterInterface;
use Phalcon\Mvc\Model\Transaction\Manager as TxManager;
use Phalcon\Mvc\Model\MetaDataInterface;
use Phalcon\Db\AdapterInterface;
use Phalcon\Mvc\Model\Resultset;

// use Phalcon\Mvc\Model;
// use Phalcon\Mvc\ModelMessage;
// use Phalcon\Db\RawValue;

class Model extends \Phalcon\Mvc\Model
{
    // 记录创建时间
    public ctime;
    public createdAt;
    // 记录更新时间
    public mtime;
    public updatedAt;

    // 自定义模型唯一键
    protected __uniqueKeys = [];

    protected optimisticLock = false;

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
        if count(this->getMessages()) {
            return (string) current(this->getMessages());
        }
        return false;
    }

    public function getLastMessage()
    {
        if count(this->getMessages()) {
            return (string) end(this->getMessages());
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

    public static function newInstance() -> <\Phalcon\Mvc\Model>
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
        if property_exists(this, "created_at") {
            let this->createdAt = this->ctime;
        }
        if property_exists(this, "updated_at") {
            let this->updatedAt = this->ctime;
        }
    }

    public function afterFetch()
    {
        // nothing
        let this->ctime = new \DateTime(this->ctime);
        let this->mtime = new \DateTime(this->mtime);
        if property_exists(this, "created_at") {
            let this->createdAt = new \DateTime(this->createdAt);
        }
        if property_exists(this, "updated_at") {
            let this->updatedAt = new \DateTime(this->updatedAt);
        }
    }

    public function beforeCreate()
    {
        let this->ctime = date("Y-m-d H:i:s");
        let this->mtime = this->ctime;
        if property_exists(this, "created_at") {
            let this->createdAt = this->ctime;
        }
        if property_exists(this, "updated_at") {
            let this->updatedAt = this->ctime;
        }
    }

    public function beforeSave()
    {
        var changedFields;
        if this->hasSnapshotData() {
            let changedFields = this->getChangedFields();
            if !empty changedFields {
                let this->mtime = date("Y-m-d H:i:s");
                if property_exists(this, "updated_at") {
                    let this->updatedAt =  this->mtime;
                }
            }
        }
        if is_object(this->ctime) && (this->ctime instanceof \DateTime) {
            let this->ctime = this->ctime->format("Y-m-d H:i:s");
        }
        if property_exists(this, "created_at") {
            if is_object(this->createdAt) && (this->createdAt instanceof \DateTime) {
               let this->createdAt = this->createdAt->format("Y-m-d H:i:s");
            }
        }

        if is_object(this->mtime) && (this->mtime instanceof \DateTime) {
            let this->mtime = this->mtime->format("Y-m-d H:i:s");
        }
        if property_exists(this, "updated_at") {
            if is_object(this->updatedAt) && (this->updatedAt instanceof \DateTime) {
                let this->updatedAt = this->updatedAt->format("Y-m-d H:i:s");
            }
        }

        return true;
    }

    public function afterSave()
    {
        if true == this->optimisticLock {
            this->resetUniqueFields();
            let this->optimisticLock = false;
        }
        return true;
    }

    public function toArray(columns = null) -> array
    {
        var fields, tmp, key, val;
        let fields = parent::toArray(columns),
            tmp = fields;
        for key, val in tmp {
            if is_object(val) && (val instanceof \DateTime) {
                let fields[key] = val->format("Y-m-d H:i:s");
            }
        }
        return fields;
    }

    /**
     * @alias findByPagable()
     */
    public function findByPageable(<Pagable> pagable, array params = [])
    {
        return this->findByPagable(pagable, params);
    }

    /**
     * find with paginator
     * Sorry for the typo with method name 
     *
     * @var array params
     *    - params["columns"]
     *    - params["conditions"]
     *    - params["bind"]
     *    - params["hydration"]: \Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS | HYDRATE_ARRAYS | HYDRATE_RECORDS
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

        if typeof page->items == "object" {
            var hydration;
            if fetch hydration, params["hydration"] {
                page->items->setHydrateMode(hydration);
            }
        }

        return new Page(pagable, page->total_items, page->items);
    }

    /**
     * Check if a reord is already exists?
     */
    public function exists() -> boolean
    {
        var metaData, readConnection, schema, source, table, builds, num;
        let
            metaData = this->getModelsMetaData(),
            readConnection = this->getReadConnection(),
            schema = this->getSchema(),
            source = this->getSource();

        if schema {
            let table = [schema, source];
        } else {
            let table = source;
        }

        if empty this->__uniqueKeys {
            if this->_exists(metaData, readConnection, table) {
                return true;
            }
            return false;
        }

        let builds = this->__buildUniqueCondition(metaData, readConnection);
        if empty builds {
            return false;
        }
        let num = readConnection->fetchOne(
            "SELECT COUNT(*) \"rowcount\" FROM " . readConnection->escapeIdentifier(table) . " WHERE " . builds["uniqueKey"],
            null,
            builds["uniqueParams"],
            builds["uniqueTypes"]
        );
        if num["rowcount"] {
            return true;
        }
        return false;
    }

    /**
     * 如果想在更新某条记录的时候额外加入其他条件，可以使用此方法
     * where = [
         'id > ?',  // 特别注意！！！ 占位符仅支持?形式，不支持:placeHolder这种形式
         'bind' => [
             14
         ]
     ];
     */
    public function setUpdateCondition(array params)
    {
        var metaData, writeConnection, columnMap, bindDataTypes, primaryKeys, attributeField;
        var pk, value, type;
        var whereUk = [], uniqueParams = [], uniqueTypes = [];

        let metaData = this->getModelsMetaData(),
            writeConnection = this->getWriteConnection(),
            columnMap = metaData->getColumnMap(this),
            bindDataTypes = metaData->getBindTypes(this);

        let primaryKeys = metaData->getPrimaryKeyAttributes(this);
        for pk in primaryKeys {
            /**
             * Check if the model has a column map
             */
            if typeof columnMap == "array" {
                if !fetch attributeField, columnMap[pk] {
                    throw new \PhalconPlus\Base\Exception("Model::setUpdateCond: Column '" . pk . "' isn't part of the column map");
                }
            } else {
                let attributeField = pk;
            }

            if !fetch type, bindDataTypes[pk] {
                throw new \PhalconPlus\Base\Exception("Model::setupdateCond: Column '" . pk . "' isn't part of the table columns");
            }

            if fetch value, this->{attributeField} {
                let uniqueParams[] = value;
            } else {
                let uniqueParams[] = null;
            }

            let whereUk[] = writeConnection->escapeIdentifier(pk) . " = ?";
            let uniqueTypes[] = type;
        }

        /**
         * Process conditions
         */
        var conditions, bind, bindTypes;
        if fetch conditions, params[0] {
        } else {
            if fetch conditions, params["conditions"] {
            }
        }

        if !empty this->_uniqueKey {
            let this->_uniqueKey = this->_uniqueKey . " AND ";
        }
        if typeof conditions == "array" {
            merge_append(whereUk, conditions);
            let this->_uniqueKey = this->_uniqueKey . join(" AND ", whereUk);
        } elseif typeof conditions == "string" {
            let conditions = join(" AND ", whereUk) . " AND " . conditions;
            let this->_uniqueKey = this->_uniqueKey . conditions;
        }

        let this->_uniqueKey = str_replace(array_values(columnMap), array_keys(columnMap), this->_uniqueKey);

        var countKeys = substr_count(this->_uniqueKey, "= ?");

        /**
         * Assign bind types
         */
        if fetch bind, params["bind"] {
            merge_append(uniqueParams, bind);
        }

        if this->_uniqueParams == null {
            let this->_uniqueParams = [];
        }
        merge_append(this->_uniqueParams, uniqueParams);
        let this->_uniqueParams = array_pad(this->_uniqueParams, countKeys, null);

        if fetch bindTypes, params["bindTypes"] {
            merge_append(uniqueTypes, bindTypes);
        }

        if this->_uniqueTypes == null {
            let this->_uniqueTypes = [];
        }
        merge_append(this->_uniqueTypes, uniqueTypes);
        let this->_uniqueTypes = array_pad(this->_uniqueTypes, countKeys, \Phalcon\Db\Column::BIND_SKIP);

        let this->optimisticLock = true;

        return this;
    }

    /**
     * columnMap field
     */
    public function setUniqueKeys(array whereUk)
    {
        /**
         * field 数据库字段
         * attributeField columnMap之后的字段
         */
        var field, attributeField, type, metaData, columnMap, bindDataTypes;

        let metaData = this->getModelsMetaData();
        let columnMap = metaData->getColumnMap(this);
        let bindDataTypes = metaData->getBindTypes(this);

        for attributeField in whereUk {
            if typeof columnMap == "array" {
                var tmp;
                let tmp = array_flip(columnMap);
                if !fetch field, tmp[attributeField] {
                    throw new \PhalconPlus\Base\Exception("Model::setUqKeys: Column '" . attributeField . "' isn't part of the column map");
                }
            } else {
                let field = attributeField;
            }

            let this->__uniqueKeys[attributeField]["field"] = field;

            if !fetch type, bindDataTypes[field] {
                throw new \PhalconPlus\Base\Exception("Model::setUqKeys: Column '" . field . "' isn't part of the table columns");
            }
            let this->__uniqueKeys[attributeField]["type"] = type;
            let this->__uniqueKeys[attributeField]["op"] = "=";
        }
        return this;
    }

    protected function __buildUniqueCondition(<MetaDataInterface> metaData, <AdapterInterface> connection)
    {
        var value, type, info, field, whereUk, uniqueParams, uniqueTypes, attributeField;

        let whereUk = [],
            uniqueParams = [],
            uniqueTypes = [];

        for attributeField, info in this->__uniqueKeys {
            let type = info["type"],
                field = info["field"],
                value = null;
            if fetch value, this->{attributeField} {
                var selfVal;
                if fetch selfVal, info["value"] {
                    let uniqueParams[] = selfVal;
                } else {
                    let uniqueParams[] = value;
                }
            } else {
                let uniqueParams[] = null;
            }
            let uniqueTypes[] = type,
                whereUk[] = connection->escapeIdentifier(field) . " ".info["op"]." ?";
        }

        var usefulParams = [];
        let usefulParams = array_filter(uniqueParams, function(elem){
            return !empty elem; // in zephir, empty means `null`, `empty string` and `empty array` 
        });

        if empty usefulParams {  // if no ukField is defined
            return false;
        }
        return [
            "uniqueKey" : join(" AND ", whereUk),
            "uniqueParams" : uniqueParams,
            "uniqueTypes" : uniqueTypes 
        ];
    }

    public function getUniqueFields() -> array
    {
        return [
            "key" : this->_uniqueKey,
            "params" : this->_uniqueParams,
            "types" : this->_uniqueTypes
        ];
    }

    protected function resetUniqueFields() -> void
    {
        let this->_uniqueKey = null;
        let this->_uniqueParams = null;
        let this->_uniqueTypes = null;
    }

    public function toProtoBuffer(columns = null) -> <ProtoBuffer>
    {
        var proto, toArray, key, val;
        let toArray = this->toArray(columns);
        let proto = new ProtoBuffer();
        for key, val in toArray {
            let proto->{key} = is_scalar(val)?val:strval(val);
        }
        var modelName, manager, relations, referenceModel, referencedEntity, options, alias, lowerAlias;

		let modelName = get_class(this), manager = this->getModelsManager();
        let relations = manager->getRelations(modelName);
        for val in relations {
            let referenceModel = val->getReferencedModel();
            let referencedEntity = strtolower(referenceModel);
            let options = val->getOptions();
            if fetch alias, options["alias"] {
                if typeof alias != "string" {
                    throw new \Exception("Relation alias must be a string");
                }
                let lowerAlias = strtolower(alias);
            } else {
                let lowerAlias = referencedEntity;
            }
            var method, property;
            let method = "get".alias;
            let property = lcfirst(alias);
            let proto->{property} = this->{method}()->toArray();
        }
        return proto;
    }

    /**
     * Gets the connection used to read data for the model
     *
     * Check transaction in writeConnection before `_transaction`
     */
    public function getReadConnection() -> <AdapterInterface>
    {
        var dbConn;
        let dbConn = this->getWriteConnection();
        if dbConn->isUnderTransaction() {
            return dbConn;
        } else {
            return parent::getReadConnection();
        }
    }
}
