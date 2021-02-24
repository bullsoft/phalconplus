
extern zend_class_entry *phalconplus_app_engine_abstractengine_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_App_Engine_AbstractEngine);

PHP_METHOD(PhalconPlus_App_Engine_AbstractEngine, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_app_engine_abstractengine___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, appModule, PhalconPlus\\App\\Module\\AbstractModule, 0)
	ZEND_ARG_OBJ_INFO(0, handler, Phalcon\\Application\\AbstractApplication, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_app_engine_abstractengine_method_entry) {
	PHP_ME(PhalconPlus_App_Engine_AbstractEngine, __construct, arginfo_phalconplus_app_engine_abstractengine___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
