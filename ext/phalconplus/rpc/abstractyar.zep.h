
extern zend_class_entry *phalconplus_rpc_abstractyar_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_AbstractYar);

PHP_METHOD(PhalconPlus_Rpc_AbstractYar, getServer);
PHP_METHOD(PhalconPlus_Rpc_AbstractYar, setServer);
PHP_METHOD(PhalconPlus_Rpc_AbstractYar, handle);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_rpc_abstractyar_getserver, 0, 0, PhalconPlus\\Rpc\\Server\\AbstractServer, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_rpc_abstractyar_getserver, 0, 0, IS_OBJECT, "PhalconPlus\\Rpc\\Server\\AbstractServer", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_rpc_abstractyar_setserver, 0, 1, PhalconPlus\\Rpc\\AbstractYar, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_rpc_abstractyar_setserver, 0, 1, IS_OBJECT, "PhalconPlus\\Rpc\\AbstractYar", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, obj, PhalconPlus\\Rpc\\Server\\AbstractServer, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_rpc_abstractyar_handle, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_rpc_abstractyar_handle, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_rpc_abstractyar_method_entry) {
	PHP_ME(PhalconPlus_Rpc_AbstractYar, getServer, arginfo_phalconplus_rpc_abstractyar_getserver, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Rpc_AbstractYar, setServer, arginfo_phalconplus_rpc_abstractyar_setserver, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Rpc_AbstractYar, handle, arginfo_phalconplus_rpc_abstractyar_handle, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
