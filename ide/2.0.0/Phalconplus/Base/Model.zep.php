<?php

namespace PhalconPlus\Base;

use PhalconPlus\Base\Pagable;
use PhalconPlus\Assert\Assertion as Assert;
use Phalcon\Db\Adapter\AdapterInterface;
use Phalcon\Mvc\Model\Transaction\Manager as TxManager;
use Phalcon\Mvc\Model\MetaDataInterface;
use Phalcon\Mvc\Model\Resultset;
use PhalconPlus\Base\Exception as BaseException;

class Model extends Phalcon\Mvc\Model
{

    protected $_uniqueKeys = [];


    protected $optimisticLock = false;



    public function initialize()
    {
    }

    /**
     * @param mixed $params
     */
    public static function findFirstOrFail($params = null)
    {
    }

    /**
     * @param mixed $params
     */
    public static function findFirstOrEmpty($params = null)
    {
    }

    /**
     * @param mixed $params
     */
    public static function findOrFail($params = null)
    {
    }

    /**
     * @param mixed $data
     * @param mixed $whiteList
     * @return bool
     */
    public function saveOrFail($data = null, $whiteList = null): bool
    {
    }

    /**
     * @param mixed $data
     * @param mixed $whiteList
     * @return bool
     */
    public function createOrFail($data = null, $whiteList = null): bool
    {
    }

    /**
     * @param mixed $data
     * @param mixed $whiteList
     * @return bool
     */
    public function updateOrFail($data = null, $whiteList = null): bool
    {
    }

    /**
     * @return string|null
     */
    public function getMessage(): ?string
    {
    }

    /**
     * @return string|null
     */
    public function getFirstMessage(): ?string
    {
    }

    /**
     * @return string|null
     */
    public function getLastMessage(): ?string
    {
    }

    /**
     * @param string $alias
     * @return \Phalcon\Mvc\Model\Query\BuilderInterface
     */
    public function createBuilder(string $alias = ''): \Phalcon\Mvc\Model\Query\BuilderInterface
    {
    }

    /**
     * @return \Phalcon\Mvc\Model
     */
    public static function newInstance(): \Phalcon\Mvc\Model
    {
    }

    /**
     * @param array $columns
     * @param array $rows
     */
    public static function batchInsert(array $columns, array $rows)
    {
    }


    public function beforeValidationOnCreate()
    {
    }


    public function afterFetch()
    {
    }


    public function beforeCreate()
    {
    }


    public function beforeSave()
    {
    }


    public function afterSave()
    {
    }

    /**
     * @param mixed $columns
     * @return array
     */
    public function toArray($columns = null): array
    {
    }

    /**
     * @alias findByPagable()
     * @param \PhalconPlus\Base\Pagable $pagable
     * @param array $params
     */
    public function findByPageable(\PhalconPlus\Base\Pagable $pagable, array $params = [])
    {
    }

    /**
     * find with paginator
     * Sorry for the typo with method name
     *
     * @param array $params *    - params["columns"]
     *    - params["conditions"]
     *    - params["bind"]
     *    - params["hydration"]: \Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS | HYDRATE_ARRAYS | HYDRATE_RECORDS
     *
     * @param \PhalconPlus\Base\Pagable $pagable
     */
    public function findByPagable(\PhalconPlus\Base\Pagable $pagable, array $params = [])
    {
    }

    /**
     * Check if a reord is already exists?
     *
     * @param \Phalcon\Mvc\Model\MetaDataInterface $metaData
     * @param \Phalcon\Db\Adapter\AdapterInterface $connection
     * @return bool
     */
    public function exists(\Phalcon\Mvc\Model\MetaDataInterface $metaData = null, \Phalcon\Db\Adapter\AdapterInterface $connection = null): bool
    {
    }

    /**
     * 如果想在更新某条记录的时候额外加入其他条件，可以使用此方法
     * where = [
     *    'id > ?',  // 特别注意！！！ 占位符仅支持?形式，不支持:placeHolder这种形式
     *    'bind' => [
     *        14
     *    ]
     * ];
     *
     * @param array $params
     */
    public function setUpdateCondition(array $params)
    {
    }

    /**
     * columnMap field
     *
     * @param array $whereUk
     */
    public function setUniqueKeys(array $whereUk)
    {
    }

    /**
     * @param \Phalcon\Mvc\Model\MetaDataInterface $metaData
     * @param \Phalcon\Db\Adapter\AdapterInterface $connection
     */
    protected function __buildUniqueCondition(\Phalcon\Mvc\Model\MetaDataInterface $metaData, \Phalcon\Db\Adapter\AdapterInterface $connection)
    {
    }

    /**
     * @return array
     */
    public function getUniqueFields(): array
    {
    }

    /**
     * @return void
     */
    protected function resetUniqueFields(): void
    {
    }

    /**
     * @param mixed $columns
     * @return ProtoBuffer
     */
    public function toProtoBuffer($columns = null): ProtoBuffer
    {
    }

}
