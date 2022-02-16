
extern zend_class_entry *phalconplus_bootstrap_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Bootstrap);

PHP_METHOD(PhalconPlus_Bootstrap, __construct);
PHP_METHOD(PhalconPlus_Bootstrap, initConf);
PHP_METHOD(PhalconPlus_Bootstrap, getApp);
PHP_METHOD(PhalconPlus_Bootstrap, app);
PHP_METHOD(PhalconPlus_Bootstrap, terminate);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_bootstrap___construct, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, moduleDir, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, env, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, runMode, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_bootstrap_initconf, 0, 0, Phalcon\\Config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_bootstrap_getapp, 0, 0, PhalconPlus\\App\\App, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_bootstrap_app, 0, 0, PhalconPlus\\App\\App, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_bootstrap_terminate, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_bootstrap_method_entry) {
	PHP_ME(PhalconPlus_Bootstrap, __construct, arginfo_phalconplus_bootstrap___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Bootstrap, initConf, arginfo_phalconplus_bootstrap_initconf, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Bootstrap, getApp, arginfo_phalconplus_bootstrap_getapp, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, app, arginfo_phalconplus_bootstrap_app, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Bootstrap, terminate, arginfo_phalconplus_bootstrap_terminate, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Bootstrap, terminate, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
