
extern zend_class_entry *phalconplus_app_engine_srv_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_App_Engine_Srv);

PHP_METHOD(PhalconPlus_App_Engine_Srv, __construct);
PHP_METHOD(PhalconPlus_App_Engine_Srv, newServer);
PHP_METHOD(PhalconPlus_App_Engine_Srv, exec);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_app_engine_srv___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, appModule, PhalconPlus\\App\\Module\\AbstractModule, 0)
	ZEND_ARG_OBJ_INFO(0, handler, Phalcon\\Application\\AbstractApplication, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_engine_srv_newserver, 0, 1, PhalconPlus\\Rpc\\Server\\AbstractServer, 0)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_engine_srv_exec, 0, 0, Phalcon\\Http\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_app_engine_srv_method_entry) {
	PHP_ME(PhalconPlus_App_Engine_Srv, __construct, arginfo_phalconplus_app_engine_srv___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_App_Engine_Srv, newServer, arginfo_phalconplus_app_engine_srv_newserver, ZEND_ACC_PRIVATE)
	PHP_ME(PhalconPlus_App_Engine_Srv, exec, arginfo_phalconplus_app_engine_srv_exec, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
