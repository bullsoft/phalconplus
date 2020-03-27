
extern zend_class_entry *phalconplus_app_handler_module_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_App_Handler_Module);

PHP_METHOD(PhalconPlus_App_Handler_Module, __construct);
PHP_METHOD(PhalconPlus_App_Handler_Module, exec);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_app_handler_module___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, PhalconPlus\\App\\App, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, autoHandle, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, autoHandle)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_handler_module_exec, 0, 0, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_handler_module_exec, 0, 0, IS_OBJECT, "NULL", 0)
#endif
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_app_handler_module_method_entry) {
	PHP_ME(PhalconPlus_App_Handler_Module, __construct, arginfo_phalconplus_app_handler_module___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_App_Handler_Module, exec, arginfo_phalconplus_app_handler_module_exec, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
