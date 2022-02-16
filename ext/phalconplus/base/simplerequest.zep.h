
extern zend_class_entry *phalconplus_base_simplerequest_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_SimpleRequest);

PHP_METHOD(PhalconPlus_Base_SimpleRequest, softClone);
PHP_METHOD(PhalconPlus_Base_SimpleRequest, getSelfVars);
PHP_METHOD(PhalconPlus_Base_SimpleRequest, getParam);
PHP_METHOD(PhalconPlus_Base_SimpleRequest, hasParam);
PHP_METHOD(PhalconPlus_Base_SimpleRequest, setParams);
PHP_METHOD(PhalconPlus_Base_SimpleRequest, setParam);
PHP_METHOD(PhalconPlus_Base_SimpleRequest, getParams);
PHP_METHOD(PhalconPlus_Base_SimpleRequest, __set);
PHP_METHOD(PhalconPlus_Base_SimpleRequest, __isset);
PHP_METHOD(PhalconPlus_Base_SimpleRequest, __get);
PHP_METHOD(PhalconPlus_Base_SimpleRequest, __unset);
PHP_METHOD(PhalconPlus_Base_SimpleRequest, isEmpty);
zend_object *zephir_init_properties_PhalconPlus_Base_SimpleRequest(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_simplerequest_softclone, 0, 1, PhalconPlus\\Base\\ProtoBuffer, 0)
	ZEND_ARG_ARRAY_INFO(0, data, 0)
	ZEND_ARG_TYPE_INFO(0, deep, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_simplerequest_getselfvars, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_simplerequest_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, idx)
	ZEND_ARG_INFO(0, defaultValue)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_simplerequest_hasparam, 0, 0, 1)
	ZEND_ARG_INFO(0, idx)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_simplerequest_setparams, 0, 1, PhalconPlus\\Base\\SimpleRequest, 0)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_simplerequest_setparam, 0, 1, PhalconPlus\\Base\\SimpleRequest, 0)
	ZEND_ARG_INFO(0, val)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_simplerequest_getparams, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_simplerequest___set, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_simplerequest___isset, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_simplerequest___get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_simplerequest___unset, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_simplerequest_isempty, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_simplerequest_zephir_init_properties_phalconplus_base_simplerequest, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_simplerequest_method_entry) {
	PHP_ME(PhalconPlus_Base_SimpleRequest, softClone, arginfo_phalconplus_base_simplerequest_softclone, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleRequest, getSelfVars, arginfo_phalconplus_base_simplerequest_getselfvars, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Base_SimpleRequest, getParam, arginfo_phalconplus_base_simplerequest_getparam, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleRequest, hasParam, arginfo_phalconplus_base_simplerequest_hasparam, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleRequest, setParams, arginfo_phalconplus_base_simplerequest_setparams, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleRequest, setParam, arginfo_phalconplus_base_simplerequest_setparam, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleRequest, getParams, arginfo_phalconplus_base_simplerequest_getparams, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleRequest, __set, arginfo_phalconplus_base_simplerequest___set, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleRequest, __isset, arginfo_phalconplus_base_simplerequest___isset, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleRequest, __get, arginfo_phalconplus_base_simplerequest___get, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleRequest, __unset, arginfo_phalconplus_base_simplerequest___unset, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleRequest, isEmpty, arginfo_phalconplus_base_simplerequest_isempty, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
