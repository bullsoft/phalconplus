
extern zend_class_entry *phalconplus_mvc_psrapplication_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Mvc_PsrApplication);

PHP_METHOD(PhalconPlus_Mvc_PsrApplication, __construct);
PHP_METHOD(PhalconPlus_Mvc_PsrApplication, handle);
PHP_METHOD(PhalconPlus_Mvc_PsrApplication, setEventsManager);
PHP_METHOD(PhalconPlus_Mvc_PsrApplication, getEventsManager);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_mvc_psrapplication___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\Di\\DiInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_mvc_psrapplication_handle, 0, 1, NULL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_mvc_psrapplication_handle, 0, 1, IS_OBJECT, "NULL", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, request, Psr\\Http\\Message\\ServerRequestInterface, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, psr, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, psr)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70100
#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_mvc_psrapplication_seteventsmanager, 0, 1, IS_VOID, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_mvc_psrapplication_seteventsmanager, 0, 1, IS_VOID, NULL, 0)
#endif
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_mvc_psrapplication_seteventsmanager, 0, 0, 1)
#define arginfo_phalconplus_mvc_psrapplication_seteventsmanager NULL
#endif

	ZEND_ARG_OBJ_INFO(0, eventsManager, Phalcon\\Events\\ManagerInterface, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_mvc_psrapplication_geteventsmanager, 0, 0, Phalcon\\Events\\ManagerInterface, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_mvc_psrapplication_geteventsmanager, 0, 0, IS_OBJECT, "Phalcon\\Events\\ManagerInterface", 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_mvc_psrapplication_method_entry) {
	PHP_ME(PhalconPlus_Mvc_PsrApplication, __construct, arginfo_phalconplus_mvc_psrapplication___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Mvc_PsrApplication, handle, arginfo_phalconplus_mvc_psrapplication_handle, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Mvc_PsrApplication, setEventsManager, arginfo_phalconplus_mvc_psrapplication_seteventsmanager, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Mvc_PsrApplication, getEventsManager, arginfo_phalconplus_mvc_psrapplication_geteventsmanager, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
