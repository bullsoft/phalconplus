
extern zend_class_entry *phalconplus_bootstrap_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Bootstrap);

PHP_METHOD(PhalconPlus_Bootstrap, __construct);
PHP_METHOD(PhalconPlus_Bootstrap, setModule);
PHP_METHOD(PhalconPlus_Bootstrap, initConf);
PHP_METHOD(PhalconPlus_Bootstrap, exec);
PHP_METHOD(PhalconPlus_Bootstrap, execModule);
PHP_METHOD(PhalconPlus_Bootstrap, execSrv);
PHP_METHOD(PhalconPlus_Bootstrap, execTask);
PHP_METHOD(PhalconPlus_Bootstrap, dependModule);
PHP_METHOD(PhalconPlus_Bootstrap, getEnv);
PHP_METHOD(PhalconPlus_Bootstrap, getConfig);
PHP_METHOD(PhalconPlus_Bootstrap, setConfig);
PHP_METHOD(PhalconPlus_Bootstrap, getDI);
PHP_METHOD(PhalconPlus_Bootstrap, load);
static void zephir_init_properties(zval *this_ptr TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_bootstrap___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, modulePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_bootstrap_setmodule, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, module, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_bootstrap_execmodule, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
	ZEND_ARG_INFO(0, needHandle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_bootstrap_execsrv, 0, 0, 0)
	ZEND_ARG_INFO(0, needHandle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_bootstrap_exectask, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, argv, 0)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DI\\FactoryDefault, 1)
	ZEND_ARG_INFO(0, needInitConf)
	ZEND_ARG_INFO(0, needHandle)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_bootstrap_dependmodule, 0, 0, 1)
	ZEND_ARG_INFO(0, moduleName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_bootstrap_setconfig, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_bootstrap_load, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_bootstrap_method_entry) {
	PHP_ME(PhalconPlus_Bootstrap, __construct, arginfo_phalconplus_bootstrap___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Bootstrap, setModule, arginfo_phalconplus_bootstrap_setmodule, ZEND_ACC_PRIVATE)
	PHP_ME(PhalconPlus_Bootstrap, initConf, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, exec, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, execModule, arginfo_phalconplus_bootstrap_execmodule, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, execSrv, arginfo_phalconplus_bootstrap_execsrv, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, execTask, arginfo_phalconplus_bootstrap_exectask, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, dependModule, arginfo_phalconplus_bootstrap_dependmodule, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, getEnv, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, getConfig, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, setConfig, arginfo_phalconplus_bootstrap_setconfig, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, getDI, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, load, arginfo_phalconplus_bootstrap_load, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
