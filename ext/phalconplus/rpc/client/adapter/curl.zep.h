
extern zend_class_entry *phalconplus_rpc_client_adapter_curl_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Client_Adapter_Curl);

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Curl, getResponse);
PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Curl, __construct);
PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Curl, callByObject);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_client_adapter_curl_getresponse, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_client_adapter_curl___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, remoteServerUrl, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, opts, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, opts, 0)
#endif
	ZEND_ARG_TYPE_INFO(0, formater, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_client_adapter_curl_callbyobject, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, rawData, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_rpc_client_adapter_curl_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Rpc_Client_Adapter_Curl, getResponse, arginfo_phalconplus_rpc_client_adapter_curl_getresponse, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Rpc_Client_Adapter_Curl, getResponse, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(PhalconPlus_Rpc_Client_Adapter_Curl, __construct, arginfo_phalconplus_rpc_client_adapter_curl___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Rpc_Client_Adapter_Curl, callByObject, arginfo_phalconplus_rpc_client_adapter_curl_callbyobject, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
