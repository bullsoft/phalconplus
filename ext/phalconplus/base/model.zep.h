
extern zend_class_entry *phalconplus_base_model_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_Model);

PHP_METHOD(PhalconPlus_Base_Model, initialize);
PHP_METHOD(PhalconPlus_Base_Model, getMessage);
PHP_METHOD(PhalconPlus_Base_Model, getFirstMessage);
PHP_METHOD(PhalconPlus_Base_Model, getLastMessage);
PHP_METHOD(PhalconPlus_Base_Model, createBuilder);
PHP_METHOD(PhalconPlus_Base_Model, getInstance);
PHP_METHOD(PhalconPlus_Base_Model, newInstance);
PHP_METHOD(PhalconPlus_Base_Model, batchInsert);
PHP_METHOD(PhalconPlus_Base_Model, beforeValidationOnCreate);
PHP_METHOD(PhalconPlus_Base_Model, afterFetch);
PHP_METHOD(PhalconPlus_Base_Model, beforeCreate);
PHP_METHOD(PhalconPlus_Base_Model, beforeSave);
PHP_METHOD(PhalconPlus_Base_Model, findByPagable);
PHP_METHOD(PhalconPlus_Base_Model, exists);
PHP_METHOD(PhalconPlus_Base_Model, setUpdateCond);
PHP_METHOD(PhalconPlus_Base_Model, setUpdateCondition);
PHP_METHOD(PhalconPlus_Base_Model, setUniqueKeys);
PHP_METHOD(PhalconPlus_Base_Model, setUqKeys);
PHP_METHOD(PhalconPlus_Base_Model, _p_buildUkCond);
PHP_METHOD(PhalconPlus_Base_Model, getUniqueFields);
PHP_METHOD(PhalconPlus_Base_Model, toProtoBuffer);
PHP_METHOD(PhalconPlus_Base_Model, getReadConnection);
zend_object *zephir_init_properties_PhalconPlus_Base_Model(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_model_createbuilder, 0, 0, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_model_createbuilder, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\Model\\Query\\BuilderInterface", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, alias)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_model_getinstance, 0, 0, Phalcon\\Mvc\\Model, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_model_getinstance, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\Model", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_model_newinstance, 0, 0, Phalcon\\Mvc\\Model, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_model_newinstance, 0, 0, IS_OBJECT, "Phalcon\\Mvc\\Model", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_batchinsert, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, columns, 0)
	ZEND_ARG_ARRAY_INFO(0, rows, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_findbypagable, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, pagable, PhalconPlus\\Base\\Pagable, 0)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_model_exists, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_model_exists, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_setupdatecond, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_setupdatecondition, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_setuniquekeys, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, whereUk, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_setuqkeys, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, whereUk, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model__p_buildukcond, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, metaData, Phalcon\\Mvc\\Model\\MetaDataInterface, 0)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\Db\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_model_toprotobuffer, 0, 0, PhalconPlus\\Base\\ProtoBuffer, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_model_toprotobuffer, 0, 0, IS_OBJECT, "PhalconPlus\\Base\\ProtoBuffer", 0)
#endif
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_model_getreadconnection, 0, 0, Phalcon\\Db\\AdapterInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_model_getreadconnection, 0, 0, IS_OBJECT, "Phalcon\\Db\\AdapterInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_model_method_entry) {
	PHP_ME(PhalconPlus_Base_Model, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, getMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, getFirstMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, getLastMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, createBuilder, arginfo_phalconplus_base_model_createbuilder, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, getInstance, arginfo_phalconplus_base_model_getinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Base_Model, newInstance, arginfo_phalconplus_base_model_newinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Base_Model, batchInsert, arginfo_phalconplus_base_model_batchinsert, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Base_Model, beforeValidationOnCreate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, afterFetch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, beforeCreate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, beforeSave, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, findByPagable, arginfo_phalconplus_base_model_findbypagable, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, exists, arginfo_phalconplus_base_model_exists, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, setUpdateCond, arginfo_phalconplus_base_model_setupdatecond, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, setUpdateCondition, arginfo_phalconplus_base_model_setupdatecondition, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, setUniqueKeys, arginfo_phalconplus_base_model_setuniquekeys, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, setUqKeys, arginfo_phalconplus_base_model_setuqkeys, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, _p_buildUkCond, arginfo_phalconplus_base_model__p_buildukcond, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Base_Model, getUniqueFields, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, toProtoBuffer, arginfo_phalconplus_base_model_toprotobuffer, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, getReadConnection, arginfo_phalconplus_base_model_getreadconnection, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
