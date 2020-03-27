
extern zend_class_entry *phalconplus_app_engine_cli_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_App_Engine_Cli);

PHP_METHOD(PhalconPlus_App_Engine_Cli, __construct);
PHP_METHOD(PhalconPlus_App_Engine_Cli, exec);
PHP_METHOD(PhalconPlus_App_Engine_Cli, setHandler);
PHP_METHOD(PhalconPlus_App_Engine_Cli, handler);
PHP_METHOD(PhalconPlus_App_Engine_Cli, getHandler);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_app_engine_cli___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, appModule, PhalconPlus\\App\\Module\\AbstractModule, 0)
	ZEND_ARG_OBJ_INFO(0, handler, PhalconPlus\\App\\Engine\\BaseApplication, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_engine_cli_exec, 0, 1, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_engine_cli_exec, 0, 1, IS_OBJECT, "NULL", 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, argv, 0)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DI\\FactoryDefault, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_engine_cli_sethandler, 0, 1, PhalconPlus\\App\\Engine\\AppEngine, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_engine_cli_sethandler, 0, 1, IS_OBJECT, "PhalconPlus\\App\\Engine\\AppEngine", 0)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_engine_cli_handler, 0, 0, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_engine_cli_handler, 0, 0, IS_OBJECT, "NULL", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_engine_cli_gethandler, 0, 0, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_engine_cli_gethandler, 0, 0, IS_OBJECT, "NULL", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_app_engine_cli_method_entry) {
	PHP_ME(PhalconPlus_App_Engine_Cli, __construct, arginfo_phalconplus_app_engine_cli___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_App_Engine_Cli, exec, arginfo_phalconplus_app_engine_cli_exec, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Engine_Cli, setHandler, arginfo_phalconplus_app_engine_cli_sethandler, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Engine_Cli, handler, arginfo_phalconplus_app_engine_cli_handler, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Engine_Cli, getHandler, arginfo_phalconplus_app_engine_cli_gethandler, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
