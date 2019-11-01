
extern zend_class_entry *phalconplus_rpc_client_adapter_curl_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Client_Adapter_Curl);

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Curl, getResponse);
PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Curl, __construct);
PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Curl, callByObject);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_client_adapter_curl___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, remoteServerUrl, 0)
	ZEND_ARG_ARRAY_INFO(0, opts, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_client_adapter_curl_callbyobject, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, rawData, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_rpc_client_adapter_curl_method_entry) {
	PHP_ME(PhalconPlus_Rpc_Client_Adapter_Curl, getResponse, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Rpc_Client_Adapter_Curl, __construct, arginfo_phalconplus_rpc_client_adapter_curl___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Rpc_Client_Adapter_Curl, callByObject, arginfo_phalconplus_rpc_client_adapter_curl_callbyobject, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
