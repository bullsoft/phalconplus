
extern zend_class_entry *phalconplus_base_simpleresponse_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_SimpleResponse);

PHP_METHOD(PhalconPlus_Base_SimpleResponse, softClone);
PHP_METHOD(PhalconPlus_Base_SimpleResponse, getSelfVars);
PHP_METHOD(PhalconPlus_Base_SimpleResponse, getResult);
PHP_METHOD(PhalconPlus_Base_SimpleResponse, setResult);
PHP_METHOD(PhalconPlus_Base_SimpleResponse, setItem);
PHP_METHOD(PhalconPlus_Base_SimpleResponse, getItem);
PHP_METHOD(PhalconPlus_Base_SimpleResponse, hasItem);
PHP_METHOD(PhalconPlus_Base_SimpleResponse, __set);
PHP_METHOD(PhalconPlus_Base_SimpleResponse, __isset);
PHP_METHOD(PhalconPlus_Base_SimpleResponse, __get);
PHP_METHOD(PhalconPlus_Base_SimpleResponse, __unset);
PHP_METHOD(PhalconPlus_Base_SimpleResponse, isEmpty);
zend_object *zephir_init_properties_PhalconPlus_Base_SimpleResponse(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_simpleresponse_softclone, 0, 1, PhalconPlus\\Base\\ProtoBuffer, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_TYPE_INFO(0, deep, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_simpleresponse_getselfvars, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_simpleresponse_getresult, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_simpleresponse_setresult, 0, 0, PhalconPlus\\Base\\SimpleResponse, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, result, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, result, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_simpleresponse_setitem, 0, 1, PhalconPlus\\Base\\SimpleResponse, 0)
	ZEND_ARG_INFO(0, val)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_simpleresponse_getitem, 0, 0, 0)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_simpleresponse_hasitem, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_simpleresponse___set, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_simpleresponse___isset, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_simpleresponse___get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_simpleresponse___unset, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_simpleresponse_isempty, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_simpleresponse_zephir_init_properties_phalconplus_base_simpleresponse, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_simpleresponse_method_entry) {
	PHP_ME(PhalconPlus_Base_SimpleResponse, softClone, arginfo_phalconplus_base_simpleresponse_softclone, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleResponse, getSelfVars, arginfo_phalconplus_base_simpleresponse_getselfvars, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Base_SimpleResponse, getResult, arginfo_phalconplus_base_simpleresponse_getresult, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleResponse, setResult, arginfo_phalconplus_base_simpleresponse_setresult, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleResponse, setItem, arginfo_phalconplus_base_simpleresponse_setitem, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleResponse, getItem, arginfo_phalconplus_base_simpleresponse_getitem, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleResponse, hasItem, arginfo_phalconplus_base_simpleresponse_hasitem, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleResponse, __set, arginfo_phalconplus_base_simpleresponse___set, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleResponse, __isset, arginfo_phalconplus_base_simpleresponse___isset, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleResponse, __get, arginfo_phalconplus_base_simpleresponse___get, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleResponse, __unset, arginfo_phalconplus_base_simpleresponse___unset, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleResponse, isEmpty, arginfo_phalconplus_base_simpleresponse_isempty, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
