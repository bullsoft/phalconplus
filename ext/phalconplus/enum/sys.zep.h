
extern zend_class_entry *phalconplus_enum_sys_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Enum_Sys);

PHP_METHOD(PhalconPlus_Enum_Sys, init);
PHP_METHOD(PhalconPlus_Enum_Sys, initApp);
PHP_METHOD(PhalconPlus_Enum_Sys, app);
PHP_METHOD(PhalconPlus_Enum_Sys, getPrimaryModuleDir);
PHP_METHOD(PhalconPlus_Enum_Sys, getRootDir);
PHP_METHOD(PhalconPlus_Enum_Sys, getCommonDir);
PHP_METHOD(PhalconPlus_Enum_Sys, getGlobalConfigDir);
PHP_METHOD(PhalconPlus_Enum_Sys, getGlobalConfigPath);
PHP_METHOD(PhalconPlus_Enum_Sys, getGlobalLoadDir);
PHP_METHOD(PhalconPlus_Enum_Sys, getModuleDirByName);
PHP_METHOD(PhalconPlus_Enum_Sys, getModuleNameByDir);
PHP_METHOD(PhalconPlus_Enum_Sys, getModuleClassPath);
PHP_METHOD(PhalconPlus_Enum_Sys, getModuleConfigPath);
PHP_METHOD(PhalconPlus_Enum_Sys, getComposerAutoloadPath);
PHP_METHOD(PhalconPlus_Enum_Sys, classAlias);
PHP_METHOD(PhalconPlus_Enum_Sys, load);
void zephir_init_static_properties_PhalconPlus_Enum_Sys();

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_sys_init, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, moduleDir, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_sys_initapp, 0, 1, IS_VOID, 0)

	ZEND_ARG_OBJ_INFO(0, app, PhalconPlus\\App\\App, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_enum_sys_app, 0, 0, PhalconPlus\\App\\App, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_sys_getprimarymoduledir, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_sys_getrootdir, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_sys_getcommondir, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_sys_getglobalconfigdir, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_sys_getglobalconfigpath, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_sys_getgloballoaddir, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_sys_getmoduledirbyname, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, moduleName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_sys_getmodulenamebydir, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, moduleDir, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_sys_getmoduleclasspath, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, moduleDir, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, modeName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_sys_getmoduleconfigpath, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, moduleDir, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_sys_getcomposerautoloadpath, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_sys_classalias, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, className, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, classAlias, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_sys_load, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, filePath, IS_STRING, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, context, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, context, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_sys_zephir_init_static_properties_phalconplus_enum_sys, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_enum_sys_method_entry) {
	PHP_ME(PhalconPlus_Enum_Sys, init, arginfo_phalconplus_enum_sys_init, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_Sys, initApp, arginfo_phalconplus_enum_sys_initapp, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_Sys, app, arginfo_phalconplus_enum_sys_app, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_Sys, getPrimaryModuleDir, arginfo_phalconplus_enum_sys_getprimarymoduledir, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_Sys, getRootDir, arginfo_phalconplus_enum_sys_getrootdir, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_Sys, getCommonDir, arginfo_phalconplus_enum_sys_getcommondir, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_Sys, getGlobalConfigDir, arginfo_phalconplus_enum_sys_getglobalconfigdir, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_Sys, getGlobalConfigPath, arginfo_phalconplus_enum_sys_getglobalconfigpath, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_Sys, getGlobalLoadDir, arginfo_phalconplus_enum_sys_getgloballoaddir, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_Sys, getModuleDirByName, arginfo_phalconplus_enum_sys_getmoduledirbyname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_Sys, getModuleNameByDir, arginfo_phalconplus_enum_sys_getmodulenamebydir, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_Sys, getModuleClassPath, arginfo_phalconplus_enum_sys_getmoduleclasspath, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_Sys, getModuleConfigPath, arginfo_phalconplus_enum_sys_getmoduleconfigpath, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Enum_Sys, getComposerAutoloadPath, arginfo_phalconplus_enum_sys_getcomposerautoloadpath, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(PhalconPlus_Enum_Sys, getComposerAutoloadPath, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
	PHP_ME(PhalconPlus_Enum_Sys, classAlias, arginfo_phalconplus_enum_sys_classalias, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_Sys, load, arginfo_phalconplus_enum_sys_load, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
