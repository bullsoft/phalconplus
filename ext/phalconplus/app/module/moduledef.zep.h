
extern zend_class_entry *phalconplus_app_module_moduledef_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_App_Module_ModuleDef);

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, __construct);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, newDI);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, checkout);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, isDefault);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, isPrimary);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getIsPrimary);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getClassPath);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getClassName);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getRunMode);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getMapClassName);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getMode);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getName);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getConfigPath);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getConfig);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getDir);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, config);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, app);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_app_module_moduledef___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, app, PhalconPlus\\App\\App, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, moduleDir, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, moduleDir)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, isPrimary, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, isPrimary)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_module_moduledef_newdi, 0, 0, Phalcon\\Di, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_newdi, 0, 0, IS_OBJECT, "Phalcon\\Di", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_module_moduledef_checkout, 0, 0, PhalconPlus\\Base\\AbstractModule, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_checkout, 0, 0, IS_OBJECT, "PhalconPlus\\Base\\AbstractModule", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_isdefault, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_isdefault, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_isprimary, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_isprimary, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getisprimary, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getisprimary, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getclasspath, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getclasspath, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getclassname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getclassname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_module_moduledef_getrunmode, 0, 0, PhalconPlus\\Enum\\RunMode, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getrunmode, 0, 0, IS_OBJECT, "PhalconPlus\\Enum\\RunMode", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getmapclassname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getmapclassname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getmode, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getmode, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getconfigpath, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getconfigpath, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_module_moduledef_getconfig, 0, 0, Phalcon\\Config, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getconfig, 0, 0, IS_OBJECT, "Phalcon\\Config", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getdir, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getdir, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_module_moduledef_config, 0, 0, Phalcon\\Config, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_config, 0, 0, IS_OBJECT, "Phalcon\\Config", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_module_moduledef_app, 0, 0, PhalconPlus\\App\\App, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_app, 0, 0, IS_OBJECT, "PhalconPlus\\App\\App", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_app_module_moduledef_method_entry) {
	PHP_ME(PhalconPlus_App_Module_ModuleDef, __construct, arginfo_phalconplus_app_module_moduledef___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, newDI, arginfo_phalconplus_app_module_moduledef_newdi, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, checkout, arginfo_phalconplus_app_module_moduledef_checkout, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, isDefault, arginfo_phalconplus_app_module_moduledef_isdefault, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, isPrimary, arginfo_phalconplus_app_module_moduledef_isprimary, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getIsPrimary, arginfo_phalconplus_app_module_moduledef_getisprimary, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getClassPath, arginfo_phalconplus_app_module_moduledef_getclasspath, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getClassName, arginfo_phalconplus_app_module_moduledef_getclassname, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getRunMode, arginfo_phalconplus_app_module_moduledef_getrunmode, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getMapClassName, arginfo_phalconplus_app_module_moduledef_getmapclassname, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getMode, arginfo_phalconplus_app_module_moduledef_getmode, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getName, arginfo_phalconplus_app_module_moduledef_getname, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getConfigPath, arginfo_phalconplus_app_module_moduledef_getconfigpath, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getConfig, arginfo_phalconplus_app_module_moduledef_getconfig, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getDir, arginfo_phalconplus_app_module_moduledef_getdir, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, config, arginfo_phalconplus_app_module_moduledef_config, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, app, arginfo_phalconplus_app_module_moduledef_app, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
