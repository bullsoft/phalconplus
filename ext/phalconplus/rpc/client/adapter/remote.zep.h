
extern zend_class_entry *phalconplus_rpc_client_adapter_remote_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_RPC_Client_Adapter_Remote);

PHP_METHOD(PhalconPlus_RPC_Client_Adapter_Remote, __construct);
PHP_METHOD(PhalconPlus_RPC_Client_Adapter_Remote, callByObject);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_client_adapter_remote___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, remoteServerUrl, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_client_adapter_remote_callbyobject, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, rawData, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_rpc_client_adapter_remote_method_entry) {
	PHP_ME(PhalconPlus_RPC_Client_Adapter_Remote, __construct, arginfo_phalconplus_rpc_client_adapter_remote___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_RPC_Client_Adapter_Remote, callByObject, arginfo_phalconplus_rpc_client_adapter_remote_callbyobject, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
