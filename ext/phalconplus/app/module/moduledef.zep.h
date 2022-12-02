
extern zend_class_entry *phalconplus_app_module_moduledef_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_App_Module_ModuleDef);

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, __construct);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, newDI);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, checkout);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, isDefault);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, isPrimary);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getIsPrimary);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, classPath);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getClassPath);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, className);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getClassName);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, runMode);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getRunMode);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, mapClassName);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getMapClassName);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, mode);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getMode);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, mame);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getName);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, ns);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getNs);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, configPath);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getConfigPath);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getConfig);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, dir);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getDir);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, config);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, app);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getApp);
PHP_METHOD(PhalconPlus_App_Module_ModuleDef, di);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_app_module_moduledef___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, app, PhalconPlus\\App\\App, 0)
	ZEND_ARG_TYPE_INFO(0, moduleDir, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, isPrimary, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, runMode, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_module_moduledef_newdi, 0, 0, Phalcon\\Di\\Di, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_module_moduledef_checkout, 0, 0, PhalconPlus\\Base\\AbstractModule, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_isdefault, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_isprimary, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getisprimary, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_classpath, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getclasspath, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_classname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getclassname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_module_moduledef_runmode, 0, 0, PhalconPlus\\Enum\\RunMode, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_module_moduledef_getrunmode, 0, 0, PhalconPlus\\Enum\\RunMode, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_mapclassname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getmapclassname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_mode, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getmode, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_mame, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_ns, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getns, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_configpath, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getconfigpath, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_module_moduledef_getconfig, 0, 0, Phalcon\\Config\\Config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_dir, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_moduledef_getdir, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_module_moduledef_config, 0, 0, Phalcon\\Config\\Config, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_module_moduledef_app, 0, 0, PhalconPlus\\App\\App, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_module_moduledef_getapp, 0, 0, PhalconPlus\\App\\App, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_module_moduledef_di, 0, 0, Phalcon\\Di\\Di, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_app_module_moduledef_method_entry) {
	PHP_ME(PhalconPlus_App_Module_ModuleDef, __construct, arginfo_phalconplus_app_module_moduledef___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, newDI, arginfo_phalconplus_app_module_moduledef_newdi, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, checkout, arginfo_phalconplus_app_module_moduledef_checkout, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, isDefault, arginfo_phalconplus_app_module_moduledef_isdefault, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, isPrimary, arginfo_phalconplus_app_module_moduledef_isprimary, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getIsPrimary, arginfo_phalconplus_app_module_moduledef_getisprimary, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, classPath, arginfo_phalconplus_app_module_moduledef_classpath, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getClassPath, arginfo_phalconplus_app_module_moduledef_getclasspath, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, className, arginfo_phalconplus_app_module_moduledef_classname, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getClassName, arginfo_phalconplus_app_module_moduledef_getclassname, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, runMode, arginfo_phalconplus_app_module_moduledef_runmode, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getRunMode, arginfo_phalconplus_app_module_moduledef_getrunmode, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, mapClassName, arginfo_phalconplus_app_module_moduledef_mapclassname, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getMapClassName, arginfo_phalconplus_app_module_moduledef_getmapclassname, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, mode, arginfo_phalconplus_app_module_moduledef_mode, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getMode, arginfo_phalconplus_app_module_moduledef_getmode, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, mame, arginfo_phalconplus_app_module_moduledef_mame, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getName, arginfo_phalconplus_app_module_moduledef_getname, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, ns, arginfo_phalconplus_app_module_moduledef_ns, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getNs, arginfo_phalconplus_app_module_moduledef_getns, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, configPath, arginfo_phalconplus_app_module_moduledef_configpath, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getConfigPath, arginfo_phalconplus_app_module_moduledef_getconfigpath, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getConfig, arginfo_phalconplus_app_module_moduledef_getconfig, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, dir, arginfo_phalconplus_app_module_moduledef_dir, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getDir, arginfo_phalconplus_app_module_moduledef_getdir, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, config, arginfo_phalconplus_app_module_moduledef_config, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, app, arginfo_phalconplus_app_module_moduledef_app, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, getApp, arginfo_phalconplus_app_module_moduledef_getapp, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_ModuleDef, di, arginfo_phalconplus_app_module_moduledef_di, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
