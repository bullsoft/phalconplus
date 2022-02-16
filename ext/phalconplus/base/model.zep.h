
extern zend_class_entry *phalconplus_base_model_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_Model);

PHP_METHOD(PhalconPlus_Base_Model, initialize);
PHP_METHOD(PhalconPlus_Base_Model, findFirstOrFail);
PHP_METHOD(PhalconPlus_Base_Model, findFirstOrEmpty);
PHP_METHOD(PhalconPlus_Base_Model, findOrFail);
PHP_METHOD(PhalconPlus_Base_Model, saveOrFail);
PHP_METHOD(PhalconPlus_Base_Model, createOrFail);
PHP_METHOD(PhalconPlus_Base_Model, updateOrFail);
PHP_METHOD(PhalconPlus_Base_Model, getMessage);
PHP_METHOD(PhalconPlus_Base_Model, getFirstMessage);
PHP_METHOD(PhalconPlus_Base_Model, getLastMessage);
PHP_METHOD(PhalconPlus_Base_Model, createBuilder);
PHP_METHOD(PhalconPlus_Base_Model, newInstance);
PHP_METHOD(PhalconPlus_Base_Model, batchInsert);
PHP_METHOD(PhalconPlus_Base_Model, beforeValidationOnCreate);
PHP_METHOD(PhalconPlus_Base_Model, afterFetch);
PHP_METHOD(PhalconPlus_Base_Model, beforeCreate);
PHP_METHOD(PhalconPlus_Base_Model, beforeSave);
PHP_METHOD(PhalconPlus_Base_Model, afterSave);
PHP_METHOD(PhalconPlus_Base_Model, toArray);
PHP_METHOD(PhalconPlus_Base_Model, findByPageable);
PHP_METHOD(PhalconPlus_Base_Model, findByPagable);
PHP_METHOD(PhalconPlus_Base_Model, exists);
PHP_METHOD(PhalconPlus_Base_Model, setUpdateCondition);
PHP_METHOD(PhalconPlus_Base_Model, setUniqueKeys);
PHP_METHOD(PhalconPlus_Base_Model, __buildUniqueCondition);
PHP_METHOD(PhalconPlus_Base_Model, getUniqueFields);
PHP_METHOD(PhalconPlus_Base_Model, resetUniqueFields);
PHP_METHOD(PhalconPlus_Base_Model, toProtoBuffer);
zend_object *zephir_init_properties_PhalconPlus_Base_Model(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_initialize, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_findfirstorfail, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_findfirstorempty, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_findorfail, 0, 0, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_model_saveorfail, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_model_createorfail, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_model_updateorfail, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_INFO(0, data)
	ZEND_ARG_INFO(0, whiteList)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_model_getmessage, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_model_getfirstmessage, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_model_getlastmessage, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_model_createbuilder, 0, 0, Phalcon\\Mvc\\Model\\Query\\BuilderInterface, 0)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_model_newinstance, 0, 0, Phalcon\\Mvc\\Model, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_batchinsert, 0, 0, 2)
	ZEND_ARG_ARRAY_INFO(0, columns, 0)
	ZEND_ARG_ARRAY_INFO(0, rows, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_beforevalidationoncreate, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_afterfetch, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_beforecreate, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_beforesave, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_aftersave, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_model_toarray, 0, 0, IS_ARRAY, 0)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_findbypageable, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, pagable, PhalconPlus\\Base\\Pagable, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, params, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, params, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_findbypagable, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, pagable, PhalconPlus\\Base\\Pagable, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, params, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, params, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_model_exists, 0, 0, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, metaData, Phalcon\\Mvc\\Model\\MetaDataInterface, 1)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\Db\\Adapter\\AdapterInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_setupdatecondition, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_setuniquekeys, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, whereUk, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model___builduniquecondition, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, metaData, Phalcon\\Mvc\\Model\\MetaDataInterface, 0)
	ZEND_ARG_OBJ_INFO(0, connection, Phalcon\\Db\\Adapter\\AdapterInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_model_getuniquefields, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_model_resetuniquefields, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_model_toprotobuffer, 0, 0, PhalconPlus\\Base\\ProtoBuffer, 0)
	ZEND_ARG_INFO(0, columns)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_zephir_init_properties_phalconplus_base_model, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_model_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Model, initialize, arginfo_phalconplus_base_model_initialize, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Model, initialize, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(PhalconPlus_Base_Model, findFirstOrFail, arginfo_phalconplus_base_model_findfirstorfail, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Base_Model, findFirstOrEmpty, arginfo_phalconplus_base_model_findfirstorempty, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Base_Model, findOrFail, arginfo_phalconplus_base_model_findorfail, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Base_Model, saveOrFail, arginfo_phalconplus_base_model_saveorfail, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, createOrFail, arginfo_phalconplus_base_model_createorfail, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, updateOrFail, arginfo_phalconplus_base_model_updateorfail, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, getMessage, arginfo_phalconplus_base_model_getmessage, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, getFirstMessage, arginfo_phalconplus_base_model_getfirstmessage, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, getLastMessage, arginfo_phalconplus_base_model_getlastmessage, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, createBuilder, arginfo_phalconplus_base_model_createbuilder, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, newInstance, arginfo_phalconplus_base_model_newinstance, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Base_Model, batchInsert, arginfo_phalconplus_base_model_batchinsert, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Model, beforeValidationOnCreate, arginfo_phalconplus_base_model_beforevalidationoncreate, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Model, beforeValidationOnCreate, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Model, afterFetch, arginfo_phalconplus_base_model_afterfetch, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Model, afterFetch, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Model, beforeCreate, arginfo_phalconplus_base_model_beforecreate, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Model, beforeCreate, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Model, beforeSave, arginfo_phalconplus_base_model_beforesave, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Model, beforeSave, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Model, afterSave, arginfo_phalconplus_base_model_aftersave, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Model, afterSave, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(PhalconPlus_Base_Model, toArray, arginfo_phalconplus_base_model_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, findByPageable, arginfo_phalconplus_base_model_findbypageable, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, findByPagable, arginfo_phalconplus_base_model_findbypagable, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, exists, arginfo_phalconplus_base_model_exists, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, setUpdateCondition, arginfo_phalconplus_base_model_setupdatecondition, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, setUniqueKeys, arginfo_phalconplus_base_model_setuniquekeys, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, __buildUniqueCondition, arginfo_phalconplus_base_model___builduniquecondition, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Base_Model, getUniqueFields, arginfo_phalconplus_base_model_getuniquefields, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, resetUniqueFields, arginfo_phalconplus_base_model_resetuniquefields, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Base_Model, toProtoBuffer, arginfo_phalconplus_base_model_toprotobuffer, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
