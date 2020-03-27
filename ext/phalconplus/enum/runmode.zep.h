
extern zend_class_entry *phalconplus_enum_runmode_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Enum_RunMode);

PHP_METHOD(PhalconPlus_Enum_RunMode, getScriptPath);
PHP_METHOD(PhalconPlus_Enum_RunMode, isCli);
PHP_METHOD(PhalconPlus_Enum_RunMode, isWeb);
PHP_METHOD(PhalconPlus_Enum_RunMode, isSrv);
PHP_METHOD(PhalconPlus_Enum_RunMode, isMicro);
PHP_METHOD(PhalconPlus_Enum_RunMode, getMapClassName);
zend_object *zephir_init_properties_PhalconPlus_Enum_RunMode(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_runmode_getscriptpath, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_runmode_getscriptpath, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_runmode_getmapclassname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_runmode_getmapclassname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_enum_runmode_method_entry) {
	PHP_ME(PhalconPlus_Enum_RunMode, getScriptPath, arginfo_phalconplus_enum_runmode_getscriptpath, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Enum_RunMode, isCli, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Enum_RunMode, isWeb, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Enum_RunMode, isSrv, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Enum_RunMode, isMicro, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Enum_RunMode, getMapClassName, arginfo_phalconplus_enum_runmode_getmapclassname, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
