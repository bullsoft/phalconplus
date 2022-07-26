
extern zend_class_entry *phalconplus_rpc_server_simpleserver_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Server_SimpleServer);

PHP_METHOD(PhalconPlus_Rpc_Server_SimpleServer, __construct);
PHP_METHOD(PhalconPlus_Rpc_Server_SimpleServer, onConstruct);
PHP_METHOD(PhalconPlus_Rpc_Server_SimpleServer, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_server_simpleserver___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\Di\\Di, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_server_simpleserver_onconstruct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_rpc_server_simpleserver___get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, property, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_rpc_server_simpleserver_method_entry) {
	PHP_ME(PhalconPlus_Rpc_Server_SimpleServer, __construct, arginfo_phalconplus_rpc_server_simpleserver___construct, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Rpc_Server_SimpleServer, onConstruct, arginfo_phalconplus_rpc_server_simpleserver_onconstruct, ZEND_ACC_PROTECTED)
#else
	PHP_ME(PhalconPlus_Rpc_Server_SimpleServer, onConstruct, NULL, ZEND_ACC_PROTECTED)
#endif
	PHP_ME(PhalconPlus_Rpc_Server_SimpleServer, __get, arginfo_phalconplus_rpc_server_simpleserver___get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
