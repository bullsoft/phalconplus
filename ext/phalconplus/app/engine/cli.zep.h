
extern zend_class_entry *phalconplus_app_engine_cli_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_App_Engine_Cli);

PHP_METHOD(PhalconPlus_App_Engine_Cli, __construct);
PHP_METHOD(PhalconPlus_App_Engine_Cli, exec);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_app_engine_cli___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, appModule, PhalconPlus\\App\\Module\\AbstractModule, 0)
	ZEND_ARG_OBJ_INFO(0, handler, Phalcon\\Application\\AbstractApplication, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_engine_cli_exec, 0, 1, Phalcon\\Cli\\Task, 0)
	ZEND_ARG_ARRAY_INFO(0, argv, 0)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\Di\\DiInterface, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_app_engine_cli_method_entry) {
	PHP_ME(PhalconPlus_App_Engine_Cli, __construct, arginfo_phalconplus_app_engine_cli___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_App_Engine_Cli, exec, arginfo_phalconplus_app_engine_cli_exec, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
