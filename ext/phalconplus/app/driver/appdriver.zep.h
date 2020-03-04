
extern zend_class_entry *phalconplus_app_driver_appdriver_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_App_Driver_AppDriver);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_driver_appdriver_gethandler, 0, 0, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_driver_appdriver_gethandler, 0, 0, IS_OBJECT, "NULL", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_driver_appdriver_sethandler, 0, 1, PhalconPlus\\App\\Driver\\AppDriver, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_driver_appdriver_sethandler, 0, 1, IS_OBJECT, "PhalconPlus\\App\\Driver\\AppDriver", 0)
#endif
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_app_driver_appdriver_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_App_Driver_AppDriver, getHandler, arginfo_phalconplus_app_driver_appdriver_gethandler)
	PHP_ABSTRACT_ME(PhalconPlus_App_Driver_AppDriver, setHandler, arginfo_phalconplus_app_driver_appdriver_sethandler)
	PHP_FE_END
};
