
extern zend_class_entry *phalconplus_rpc_simpleservice_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_SimpleService);

PHP_METHOD(PhalconPlus_Rpc_SimpleService, __construct);
PHP_METHOD(PhalconPlus_Rpc_SimpleService, setServer);
PHP_METHOD(PhalconPlus_Rpc_SimpleService, handle);
PHP_METHOD(PhalconPlus_Rpc_SimpleService, defaultResponse);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_simpleservice___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\Di\\DiInterface, 1)
	ZEND_ARG_TYPE_INFO(0, formater, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_rpc_simpleservice_setserver, 0, 1, PhalconPlus\\Rpc\\AbstractService, 0)
	ZEND_ARG_OBJ_INFO(0, obj, PhalconPlus\\Rpc\\Server\\AbstractServer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_rpc_simpleservice_handle, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_rpc_simpleservice_defaultresponse, 0, 0, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, vals, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, vals, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_rpc_simpleservice_method_entry) {
	PHP_ME(PhalconPlus_Rpc_SimpleService, __construct, arginfo_phalconplus_rpc_simpleservice___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Rpc_SimpleService, setServer, arginfo_phalconplus_rpc_simpleservice_setserver, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Rpc_SimpleService, handle, arginfo_phalconplus_rpc_simpleservice_handle, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Rpc_SimpleService, defaultResponse, arginfo_phalconplus_rpc_simpleservice_defaultresponse, ZEND_ACC_PRIVATE)
	PHP_FE_END
};
