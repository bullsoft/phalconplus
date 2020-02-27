
extern zend_class_entry *phalconplus_facades_abstractfacade_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Facades_AbstractFacade);

PHP_METHOD(PhalconPlus_Facades_AbstractFacade, getName);
PHP_METHOD(PhalconPlus_Facades_AbstractFacade, resolve);
PHP_METHOD(PhalconPlus_Facades_AbstractFacade, setApp);
PHP_METHOD(PhalconPlus_Facades_AbstractFacade, __callStatic);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_facades_abstractfacade_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_facades_abstractfacade_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_facades_abstractfacade_resolve, 0, 1, Phalcon\\Di, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_facades_abstractfacade_resolve, 0, 1, IS_OBJECT, "Phalcon\\Di", 1)
#endif
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\Di, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_facades_abstractfacade_setapp, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, PhalconPlus\\App\\App, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_facades_abstractfacade___callstatic, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_facades_abstractfacade_method_entry) {
	PHP_ME(PhalconPlus_Facades_AbstractFacade, getName, arginfo_phalconplus_facades_abstractfacade_getname, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Facades_AbstractFacade, resolve, arginfo_phalconplus_facades_abstractfacade_resolve, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Facades_AbstractFacade, setApp, arginfo_phalconplus_facades_abstractfacade_setapp, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Facades_AbstractFacade, __callStatic, arginfo_phalconplus_facades_abstractfacade___callstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
