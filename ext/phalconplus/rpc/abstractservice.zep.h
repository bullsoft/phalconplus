
extern zend_class_entry *phalconplus_rpc_abstractservice_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_AbstractService);

PHP_METHOD(PhalconPlus_Rpc_AbstractService, getServer);
PHP_METHOD(PhalconPlus_Rpc_AbstractService, setServer);
PHP_METHOD(PhalconPlus_Rpc_AbstractService, handle);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_rpc_abstractservice_getserver, 0, 0, PhalconPlus\\Rpc\\Server\\AbstractServer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_rpc_abstractservice_setserver, 0, 1, PhalconPlus\\Rpc\\AbstractService, 0)
	ZEND_ARG_OBJ_INFO(0, obj, PhalconPlus\\Rpc\\Server\\AbstractServer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_rpc_abstractservice_handle, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_rpc_abstractservice_method_entry) {
	PHP_ME(PhalconPlus_Rpc_AbstractService, getServer, arginfo_phalconplus_rpc_abstractservice_getserver, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Rpc_AbstractService, setServer, arginfo_phalconplus_rpc_abstractservice_setserver, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Rpc_AbstractService, handle, arginfo_phalconplus_rpc_abstractservice_handle, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
