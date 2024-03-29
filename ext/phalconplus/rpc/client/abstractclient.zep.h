
extern zend_class_entry *phalconplus_rpc_client_abstractclient_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Client_AbstractClient);

PHP_METHOD(PhalconPlus_Rpc_Client_AbstractClient, setNamePrefix);
PHP_METHOD(PhalconPlus_Rpc_Client_AbstractClient, setDI);
PHP_METHOD(PhalconPlus_Rpc_Client_AbstractClient, callByObject);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_client_abstractclient_setnameprefix, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_rpc_client_abstractclient_setdi, 0, 1, PhalconPlus\\Rpc\\Client\\AbstractClient, 0)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_client_abstractclient_callbyobject, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, rawData, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_rpc_client_abstractclient_method_entry) {
	PHP_ME(PhalconPlus_Rpc_Client_AbstractClient, setNamePrefix, arginfo_phalconplus_rpc_client_abstractclient_setnameprefix, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Rpc_Client_AbstractClient, setDI, arginfo_phalconplus_rpc_client_abstractclient_setdi, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Rpc_Client_AbstractClient, callByObject, arginfo_phalconplus_rpc_client_abstractclient_callbyobject, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
