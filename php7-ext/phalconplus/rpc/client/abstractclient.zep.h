
extern zend_class_entry *phalconplus_rpc_client_abstractclient_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_RPC_Client_AbstractClient);

PHP_METHOD(PhalconPlus_RPC_Client_AbstractClient, callByObject);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_client_abstractclient_callbyobject, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, rawData, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_rpc_client_abstractclient_method_entry) {
	PHP_ME(PhalconPlus_RPC_Client_AbstractClient, callByObject, arginfo_phalconplus_rpc_client_abstractclient_callbyobject, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
