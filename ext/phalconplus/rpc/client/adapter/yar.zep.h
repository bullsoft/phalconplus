
extern zend_class_entry *phalconplus_rpc_client_adapter_yar_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Client_Adapter_Yar);

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Yar, __construct);
PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Yar, callByObject);
PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Yar, __call);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_client_adapter_yar___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, remoteServerUrl, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, opts, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, opts, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_client_adapter_yar_callbyobject, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, rawData, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_client_adapter_yar___call, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_rpc_client_adapter_yar_method_entry) {
	PHP_ME(PhalconPlus_Rpc_Client_Adapter_Yar, __construct, arginfo_phalconplus_rpc_client_adapter_yar___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Rpc_Client_Adapter_Yar, callByObject, arginfo_phalconplus_rpc_client_adapter_yar_callbyobject, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Rpc_Client_Adapter_Yar, __call, arginfo_phalconplus_rpc_client_adapter_yar___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
