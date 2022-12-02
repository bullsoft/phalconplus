
extern zend_class_entry *phalconplus_rpc_yarservice_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_YarService);

PHP_METHOD(PhalconPlus_Rpc_YarService, setServer);
PHP_METHOD(PhalconPlus_Rpc_YarService, handle);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_rpc_yarservice_setserver, 0, 1, PhalconPlus\\Rpc\\AbstractService, 0)
	ZEND_ARG_OBJ_INFO(0, obj, PhalconPlus\\Rpc\\Server\\AbstractServer, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_rpc_yarservice_handle, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_rpc_yarservice_method_entry) {
	PHP_ME(PhalconPlus_Rpc_YarService, setServer, arginfo_phalconplus_rpc_yarservice_setserver, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Rpc_YarService, handle, arginfo_phalconplus_rpc_yarservice_handle, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
