
extern zend_class_entry *phalconplus_rpc_yar_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Yar);

PHP_METHOD(PhalconPlus_Rpc_Yar, getServiceObj);
PHP_METHOD(PhalconPlus_Rpc_Yar, getRequestArgs);
PHP_METHOD(PhalconPlus_Rpc_Yar, getResponseBody);
PHP_METHOD(PhalconPlus_Rpc_Yar, __construct);
PHP_METHOD(PhalconPlus_Rpc_Yar, setServer);
PHP_METHOD(PhalconPlus_Rpc_Yar, handle);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_yar___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DiInterface, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, formater, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, formater)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_yar_setserver, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, obj, PhalconPlus\\Rpc\\Server\\AbstractServer, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_rpc_yar_method_entry) {
	PHP_ME(PhalconPlus_Rpc_Yar, getServiceObj, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Rpc_Yar, getRequestArgs, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Rpc_Yar, getResponseBody, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Rpc_Yar, __construct, arginfo_phalconplus_rpc_yar___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Rpc_Yar, setServer, arginfo_phalconplus_rpc_yar_setserver, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Rpc_Yar, handle, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
