
extern zend_class_entry *phalconplus_bootstrap_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Bootstrap);

PHP_METHOD(PhalconPlus_Bootstrap, getApp);
PHP_METHOD(PhalconPlus_Bootstrap, getLoadedFiles);
PHP_METHOD(PhalconPlus_Bootstrap, __construct);
PHP_METHOD(PhalconPlus_Bootstrap, initConf);
PHP_METHOD(PhalconPlus_Bootstrap, exec);
PHP_METHOD(PhalconPlus_Bootstrap, load);
PHP_METHOD(PhalconPlus_Bootstrap, terminate);
PHP_METHOD(PhalconPlus_Bootstrap, __destruct);
zend_object *zephir_init_properties_PhalconPlus_Bootstrap(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_bootstrap___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, moduleDir, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, moduleDir)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, env, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, env)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_bootstrap_initconf, 0, 0, Phalcon\\Config, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_bootstrap_initconf, 0, 0, IS_OBJECT, "Phalcon\\Config", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_bootstrap_load, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_bootstrap_method_entry) {
	PHP_ME(PhalconPlus_Bootstrap, getApp, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, getLoadedFiles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, __construct, arginfo_phalconplus_bootstrap___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Bootstrap, initConf, arginfo_phalconplus_bootstrap_initconf, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Bootstrap, exec, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, load, arginfo_phalconplus_bootstrap_load, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, terminate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_FE_END
};
