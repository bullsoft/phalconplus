
extern zend_class_entry *phalconplus_rpc_server_abstractserver_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Server_AbstractServer);

PHP_METHOD(PhalconPlus_Rpc_Server_AbstractServer, getDi);
PHP_METHOD(PhalconPlus_Rpc_Server_AbstractServer, getPhpOnly);
PHP_METHOD(PhalconPlus_Rpc_Server_AbstractServer, __construct);
PHP_METHOD(PhalconPlus_Rpc_Server_AbstractServer, callByParams);
PHP_METHOD(PhalconPlus_Rpc_Server_AbstractServer, callByObject);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_server_abstractserver_getdi, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_server_abstractserver_getphponly, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_server_abstractserver___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DI, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_server_abstractserver_callbyparams, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, service, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_server_abstractserver_callbyobject, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, rawData, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_rpc_server_abstractserver_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Rpc_Server_AbstractServer, getDi, arginfo_phalconplus_rpc_server_abstractserver_getdi, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Rpc_Server_AbstractServer, getDi, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Rpc_Server_AbstractServer, getPhpOnly, arginfo_phalconplus_rpc_server_abstractserver_getphponly, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Rpc_Server_AbstractServer, getPhpOnly, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(PhalconPlus_Rpc_Server_AbstractServer, __construct, arginfo_phalconplus_rpc_server_abstractserver___construct, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Rpc_Server_AbstractServer, callByParams, arginfo_phalconplus_rpc_server_abstractserver_callbyparams, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Rpc_Server_AbstractServer, callByObject, arginfo_phalconplus_rpc_server_abstractserver_callbyobject, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
