
extern zend_class_entry *phalconplus_app_app_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_App_App);

PHP_METHOD(PhalconPlus_App_App, getConfig);
PHP_METHOD(PhalconPlus_App_App, __construct);
PHP_METHOD(PhalconPlus_App_App, boot);
PHP_METHOD(PhalconPlus_App_App, bootPrimaryModule);
PHP_METHOD(PhalconPlus_App_App, registerModule);
PHP_METHOD(PhalconPlus_App_App, import);
PHP_METHOD(PhalconPlus_App_App, dependModule);
PHP_METHOD(PhalconPlus_App_App, setConfig);
PHP_METHOD(PhalconPlus_App_App, isBooted);
PHP_METHOD(PhalconPlus_App_App, getEnv);
PHP_METHOD(PhalconPlus_App_App, setEnv);
PHP_METHOD(PhalconPlus_App_App, handle);
PHP_METHOD(PhalconPlus_App_App, terminate);
PHP_METHOD(PhalconPlus_App_App, defer);
PHP_METHOD(PhalconPlus_App_App, getRequestNumber);
PHP_METHOD(PhalconPlus_App_App, getDefaultModuleDef);
PHP_METHOD(PhalconPlus_App_App, getPrimaryModuleDef);
PHP_METHOD(PhalconPlus_App_App, setDefaultModule);
PHP_METHOD(PhalconPlus_App_App, getDefaultModule);
PHP_METHOD(PhalconPlus_App_App, getPrimaryModule);
PHP_METHOD(PhalconPlus_App_App, getModule);
PHP_METHOD(PhalconPlus_App_App, getModuleDef);
PHP_METHOD(PhalconPlus_App_App, config);
PHP_METHOD(PhalconPlus_App_App, di);
PHP_METHOD(PhalconPlus_App_App, __call);
zend_object *zephir_init_properties_PhalconPlus_App_App(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_app_app___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Config, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_app_boot, 0, 0, PhalconPlus\\App\\App, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_boot, 0, 0, IS_OBJECT, "PhalconPlus\\App\\App", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, env, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, env)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, runMode, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, runMode)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_app_bootprimarymodule, 0, 0, PhalconPlus\\App\\App, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_bootprimarymodule, 0, 0, IS_OBJECT, "PhalconPlus\\App\\App", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, runMode, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, runMode)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_app_registermodule, 0, 1, PhalconPlus\\App\\Module\\AbstractModule, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_registermodule, 0, 1, IS_OBJECT, "PhalconPlus\\App\\Module\\AbstractModule", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, moduleDef, PhalconPlus\\App\\Module\\ModuleDef, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_app_import, 0, 1, PhalconPlus\\App\\Module\\AbstractModule, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_import, 0, 1, IS_OBJECT, "PhalconPlus\\App\\Module\\AbstractModule", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, moduleName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, moduleName)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_app_dependmodule, 0, 1, PhalconPlus\\App\\Module\\AbstractModule, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_dependmodule, 0, 1, IS_OBJECT, "PhalconPlus\\App\\Module\\AbstractModule", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, moduleName, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, moduleName)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, force, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, force)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_app_setconfig, 0, 1, PhalconPlus\\App\\App, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_setconfig, 0, 1, IS_OBJECT, "PhalconPlus\\App\\App", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, config, Phalcon\\Config, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_isbooted, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_isbooted, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_getenv, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_getenv, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_app_setenv, 0, 1, PhalconPlus\\App\\App, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_setenv, 0, 1, IS_OBJECT, "PhalconPlus\\App\\App", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, env, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, env)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_app_app_terminate, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, deeply, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, deeply)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_app_app_defer, 0, 0, 1)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_getrequestnumber, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_getrequestnumber, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_app_getdefaultmoduledef, 0, 0, PhalconPlus\\App\\Module\\ModuleDef, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_getdefaultmoduledef, 0, 0, IS_OBJECT, "PhalconPlus\\App\\Module\\ModuleDef", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_app_getprimarymoduledef, 0, 0, PhalconPlus\\App\\Module\\ModuleDef, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_getprimarymoduledef, 0, 0, IS_OBJECT, "PhalconPlus\\App\\Module\\ModuleDef", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_app_setdefaultmodule, 0, 1, Phalcon\\Application, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_setdefaultmodule, 0, 1, IS_OBJECT, "Phalcon\\Application", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, defaultModule, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, defaultModule)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_getdefaultmodule, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_getdefaultmodule, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_app_getprimarymodule, 0, 0, PhalconPlus\\App\\Module\\AbstractModule, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_getprimarymodule, 0, 0, IS_OBJECT, "PhalconPlus\\App\\Module\\AbstractModule", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_app_getmodule, 0, 0, PhalconPlus\\App\\Module\\AbstractModule, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_getmodule, 0, 0, IS_OBJECT, "PhalconPlus\\App\\Module\\AbstractModule", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_app_getmoduledef, 0, 0, PhalconPlus\\App\\Module\\ModuleDef, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_getmoduledef, 0, 0, IS_OBJECT, "PhalconPlus\\App\\Module\\ModuleDef", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_app_config, 0, 0, Phalcon\\Config, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_config, 0, 0, IS_OBJECT, "Phalcon\\Config", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_app_di, 0, 0, Phalcon\\Di, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_app_di, 0, 0, IS_OBJECT, "Phalcon\\Di", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_app_app___call, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_app_app_method_entry) {
	PHP_ME(PhalconPlus_App_App, getConfig, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, __construct, arginfo_phalconplus_app_app___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_App_App, boot, arginfo_phalconplus_app_app_boot, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, bootPrimaryModule, arginfo_phalconplus_app_app_bootprimarymodule, ZEND_ACC_PRIVATE)
	PHP_ME(PhalconPlus_App_App, registerModule, arginfo_phalconplus_app_app_registermodule, ZEND_ACC_PRIVATE)
	PHP_ME(PhalconPlus_App_App, import, arginfo_phalconplus_app_app_import, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, dependModule, arginfo_phalconplus_app_app_dependmodule, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, setConfig, arginfo_phalconplus_app_app_setconfig, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, isBooted, arginfo_phalconplus_app_app_isbooted, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, getEnv, arginfo_phalconplus_app_app_getenv, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, setEnv, arginfo_phalconplus_app_app_setenv, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, handle, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, terminate, arginfo_phalconplus_app_app_terminate, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, defer, arginfo_phalconplus_app_app_defer, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, getRequestNumber, arginfo_phalconplus_app_app_getrequestnumber, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, getDefaultModuleDef, arginfo_phalconplus_app_app_getdefaultmoduledef, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, getPrimaryModuleDef, arginfo_phalconplus_app_app_getprimarymoduledef, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, setDefaultModule, arginfo_phalconplus_app_app_setdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, getDefaultModule, arginfo_phalconplus_app_app_getdefaultmodule, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, getPrimaryModule, arginfo_phalconplus_app_app_getprimarymodule, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, getModule, arginfo_phalconplus_app_app_getmodule, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, getModuleDef, arginfo_phalconplus_app_app_getmoduledef, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, config, arginfo_phalconplus_app_app_config, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, di, arginfo_phalconplus_app_app_di, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_App, __call, arginfo_phalconplus_app_app___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
