
extern zend_class_entry *phalconplus_app_engine_web_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_App_Engine_Web);

PHP_METHOD(PhalconPlus_App_Engine_Web, __construct);
PHP_METHOD(PhalconPlus_App_Engine_Web, exec);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_app_engine_web___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, appModule, PhalconPlus\\App\\Module\\AbstractModule, 0)
	ZEND_ARG_OBJ_INFO(0, handler, Phalcon\\Application\\AbstractApplication, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_engine_web_exec, 0, 0, Phalcon\\Http\\ResponseInterface, 0)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_app_engine_web_method_entry) {
	PHP_ME(PhalconPlus_App_Engine_Web, __construct, arginfo_phalconplus_app_engine_web___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_App_Engine_Web, exec, arginfo_phalconplus_app_engine_web_exec, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
