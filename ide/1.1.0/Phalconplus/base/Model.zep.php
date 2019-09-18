<?php

namespace PhalconPlus\Base;


class Model extends Phalcon\Mvc\Model
{

    public $ctime;


    public $mtime;


    protected $__p_UK = array();



    public function initialize() {}


    public function getMessage() {}


    public function getFirstMessage() {}


    public function getLastMessage() {}

    /**
     * @param string $alias
     * @return \Phalcon\Mvc\Model\Query\BuilderInterface
     */
    public function createBuilder(string $alias = ''): \Phalcon\Mvc\Model\Query\BuilderInterface {}

    /**
     * @deprecated 非单例，不建议用此方法名称，将在以后移除
     * @return \Phalcon\Mvc\Model
     */
    public static function getInstance(): \Phalcon\Mvc\Model {}

    /**
     * @return \Phalcon\Mvc\Model
     */
    public static function newInstance(): \Phalcon\Mvc\Model {}

    /**
     * @param array $columns
     * @param array $rows
     */
    public static function batchInsert(array $columns, array $rows) {}


    public function beforeValidationOnCreate() {}


    public function afterFetch() {}


    public function beforeCreate() {}


    public function beforeSave() {}

    /**
     * find with paginator
     *
     * @var array params
     *    - params["columns"]
     *    - params["conditions"]
     *    - params["bind"]
     *    - params["hydration"]: \Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS | HYDRATE_ARRAYS | HYDRATE_RECORDS
     *
     * @param \PhalconPlus\Base\Pagable $pagable
     * @param array $params
     */
    public function findByPagable(\PhalconPlus\Base\Pagable $pagable, array $params = array()) {}

    /**
     * Check if a reord is already exists?
     *
     * @return bool
     */
    public function exists(): bool {}

    /**
     * @alias setUpdateCondition()
     * @deprecated
     * @param array $params
     */
    public function setUpdateCond(array $params) {}

    /**
     * 如果想在更新某条记录的时候额外加入其他条件，可以使用此方法
     * where = [
     *         'id > ?',  // 占位符仅支持?形式，不支持:placeHolder这种形式
     *         'bind' => [
     *             14
     *         ]
     *     ];
     *
     * @param array $params
     */
    public function setUpdateCondition(array $params) {}

    /**
     * @alias setUniqueKeys
     * @deprecated
     * @param array $whereUk
     */
    public function setUqKeys(array $whereUk) {}

    /**
     * columnMap field
     *
     * @param array $whereUk
     */
    public function setUniqueKeys(array $whereUk) {}

    /**
     * @param \Phalcon\Mvc\Model\MetaDataInterface $metaData
     * @param \Phalcon\Db\AdapterInterface $connection
     */
    protected function _p_buildUkCond(\Phalcon\Mvc\Model\MetaDataInterface $metaData, \Phalcon\Db\AdapterInterface $connection) {}


    public function getUniqueFields() {}

    /**
     * @param mixed $columns
     * @return ProtoBuffer
     */
    public function toProtoBuffer($columns = null): ProtoBuffer {}

    /**
     * Gets the connection used to read data for the model
     *
     * Check transaction in writeConnection before `_transaction`
     *
     * @return \Phalcon\Db\AdapterInterface
     */
    public function getReadConnection(): AdapterInterface {}

}
