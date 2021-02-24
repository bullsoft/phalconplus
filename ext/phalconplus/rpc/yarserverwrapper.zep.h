
extern zend_class_entry *phalconplus_rpc_yarserverwrapper_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_YarServerWrapper);

PHP_METHOD(PhalconPlus_Rpc_YarServerWrapper, setServer);
PHP_METHOD(PhalconPlus_Rpc_YarServerWrapper, handle);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_rpc_yarserverwrapper_setserver, 0, 1, PhalconPlus\\Rpc\\AbstractYar, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_rpc_yarserverwrapper_setserver, 0, 1, IS_OBJECT, "PhalconPlus\\Rpc\\AbstractYar", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, obj, PhalconPlus\\Rpc\\Server\\AbstractServer, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_rpc_yarserverwrapper_handle, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_rpc_yarserverwrapper_handle, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_rpc_yarserverwrapper_method_entry) {
	PHP_ME(PhalconPlus_Rpc_YarServerWrapper, setServer, arginfo_phalconplus_rpc_yarserverwrapper_setserver, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Rpc_YarServerWrapper, handle, arginfo_phalconplus_rpc_yarserverwrapper_handle, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
