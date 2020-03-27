
extern zend_class_entry *phalconplus_app_handler_task_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_App_Handler_Task);

PHP_METHOD(PhalconPlus_App_Handler_Task, __construct);
PHP_METHOD(PhalconPlus_App_Handler_Task, exec);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_app_handler_task___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, PhalconPlus\\App\\App, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, autoHandle, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, autoHandle)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_app_handler_task_exec, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, argv, 0)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DI\\FactoryDefault, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_app_handler_task_method_entry) {
	PHP_ME(PhalconPlus_App_Handler_Task, __construct, arginfo_phalconplus_app_handler_task___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_App_Handler_Task, exec, arginfo_phalconplus_app_handler_task_exec, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
