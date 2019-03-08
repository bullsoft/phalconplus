
extern zend_class_entry *phalconplus_bootstrap_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Bootstrap);

PHP_METHOD(PhalconPlus_Bootstrap, __construct);
PHP_METHOD(PhalconPlus_Bootstrap, registerModule);
PHP_METHOD(PhalconPlus_Bootstrap, initConf);
PHP_METHOD(PhalconPlus_Bootstrap, exec);
PHP_METHOD(PhalconPlus_Bootstrap, execModule);
PHP_METHOD(PhalconPlus_Bootstrap, execSrv);
PHP_METHOD(PhalconPlus_Bootstrap, execTask);
PHP_METHOD(PhalconPlus_Bootstrap, getPrimaryModuleDef);
PHP_METHOD(PhalconPlus_Bootstrap, getPrimaryModule);
PHP_METHOD(PhalconPlus_Bootstrap, getModule);
PHP_METHOD(PhalconPlus_Bootstrap, getModuleDef);
PHP_METHOD(PhalconPlus_Bootstrap, dependModule);
PHP_METHOD(PhalconPlus_Bootstrap, isDebug);
PHP_METHOD(PhalconPlus_Bootstrap, getDebug);
PHP_METHOD(PhalconPlus_Bootstrap, getEnv);
PHP_METHOD(PhalconPlus_Bootstrap, getConfig);
PHP_METHOD(PhalconPlus_Bootstrap, setConfig);
PHP_METHOD(PhalconPlus_Bootstrap, getDI);
PHP_METHOD(PhalconPlus_Bootstrap, load);
zend_object *zephir_init_properties_PhalconPlus_Bootstrap(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_bootstrap___construct, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, moduleDir, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, moduleDir)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_bootstrap_registermodule, 0, 1, PhalconPlus\\Base\\AbstractModule, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_bootstrap_registermodule, 0, 1, IS_OBJECT, "PhalconPlus\\Base\\AbstractModule", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, moduleDef, PhalconPlus\\Base\\ModuleDef, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_bootstrap_initconf, 0, 0, PhalconPlus\\Bootstrap, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_bootstrap_initconf, 0, 0, IS_OBJECT, "PhalconPlus\\Bootstrap", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_bootstrap_execmodule, 0, 0, 0)
	ZEND_ARG_INFO(0, uri)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, needHandle, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, needHandle)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_bootstrap_execsrv, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, needHandle, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, needHandle)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_bootstrap_exectask, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, argv, 0)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DI\\FactoryDefault, 1)
	ZEND_ARG_INFO(0, needHandle)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_bootstrap_getprimarymoduledef, 0, 0, PhalconPlus\\Base\\ModuleDef, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_bootstrap_getprimarymoduledef, 0, 0, IS_OBJECT, "PhalconPlus\\Base\\ModuleDef", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_bootstrap_getprimarymodule, 0, 0, PhalconPlus\\Base\\AbstractModule, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_bootstrap_getprimarymodule, 0, 0, IS_OBJECT, "PhalconPlus\\Base\\AbstractModule", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_bootstrap_getmodule, 0, 1, PhalconPlus\\Base\\AbstractModule, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_bootstrap_getmodule, 0, 1, IS_OBJECT, "PhalconPlus\\Base\\AbstractModule", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_bootstrap_getmoduledef, 0, 1, PhalconPlus\\Base\\ModuleDef, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_bootstrap_getmoduledef, 0, 1, IS_OBJECT, "PhalconPlus\\Base\\ModuleDef", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_bootstrap_dependmodule, 0, 1, PhalconPlus\\Base\\AbstractModule, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_bootstrap_dependmodule, 0, 1, IS_OBJECT, "PhalconPlus\\Base\\AbstractModule", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, moduleName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, moduleName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_bootstrap_isdebug, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_bootstrap_isdebug, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_bootstrap_getdebug, 0, 0, Phalcon\\Debug, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_bootstrap_getdebug, 0, 0, IS_OBJECT, "Phalcon\\Debug", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_bootstrap_getenv, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_bootstrap_getenv, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_bootstrap_getconfig, 0, 0, Phalcon\\Config, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_bootstrap_getconfig, 0, 0, IS_OBJECT, "Phalcon\\Config", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_bootstrap_setconfig, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Config, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_bootstrap_getdi, 0, 0, Phalcon\\DI, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_bootstrap_getdi, 0, 0, IS_OBJECT, "Phalcon\\DI", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_bootstrap_load, 0, 0, 1)
	ZEND_ARG_INFO(0, filePath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_bootstrap_method_entry) {
	PHP_ME(PhalconPlus_Bootstrap, __construct, arginfo_phalconplus_bootstrap___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Bootstrap, registerModule, arginfo_phalconplus_bootstrap_registermodule, ZEND_ACC_PRIVATE)
	PHP_ME(PhalconPlus_Bootstrap, initConf, arginfo_phalconplus_bootstrap_initconf, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, exec, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, execModule, arginfo_phalconplus_bootstrap_execmodule, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, execSrv, arginfo_phalconplus_bootstrap_execsrv, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, execTask, arginfo_phalconplus_bootstrap_exectask, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, getPrimaryModuleDef, arginfo_phalconplus_bootstrap_getprimarymoduledef, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, getPrimaryModule, arginfo_phalconplus_bootstrap_getprimarymodule, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, getModule, arginfo_phalconplus_bootstrap_getmodule, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, getModuleDef, arginfo_phalconplus_bootstrap_getmoduledef, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, dependModule, arginfo_phalconplus_bootstrap_dependmodule, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, isDebug, arginfo_phalconplus_bootstrap_isdebug, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, getDebug, arginfo_phalconplus_bootstrap_getdebug, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, getEnv, arginfo_phalconplus_bootstrap_getenv, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, getConfig, arginfo_phalconplus_bootstrap_getconfig, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, setConfig, arginfo_phalconplus_bootstrap_setconfig, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, getDI, arginfo_phalconplus_bootstrap_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Bootstrap, load, arginfo_phalconplus_bootstrap_load, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
