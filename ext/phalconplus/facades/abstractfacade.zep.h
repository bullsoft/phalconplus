
extern zend_class_entry *phalconplus_facades_abstractfacade_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Facades_AbstractFacade);

PHP_METHOD(PhalconPlus_Facades_AbstractFacade, getName);
PHP_METHOD(PhalconPlus_Facades_AbstractFacade, resolve);
PHP_METHOD(PhalconPlus_Facades_AbstractFacade, setApp);
PHP_METHOD(PhalconPlus_Facades_AbstractFacade, app);
PHP_METHOD(PhalconPlus_Facades_AbstractFacade, getApp);
PHP_METHOD(PhalconPlus_Facades_AbstractFacade, itself);
PHP_METHOD(PhalconPlus_Facades_AbstractFacade, __callStatic);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_facades_abstractfacade_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_facades_abstractfacade_resolve, 0, 1, Phalcon\\Di, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\Di, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_facades_abstractfacade_setapp, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, app, PhalconPlus\\App\\App, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_facades_abstractfacade_app, 0, 0, PhalconPlus\\App\\App, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_facades_abstractfacade_getapp, 0, 0, PhalconPlus\\App\\App, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_facades_abstractfacade_itself, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_facades_abstractfacade___callstatic, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_facades_abstractfacade_method_entry) {
	PHP_ME(PhalconPlus_Facades_AbstractFacade, getName, arginfo_phalconplus_facades_abstractfacade_getname, ZEND_ACC_ABSTRACT|ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Facades_AbstractFacade, resolve, arginfo_phalconplus_facades_abstractfacade_resolve, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Facades_AbstractFacade, setApp, arginfo_phalconplus_facades_abstractfacade_setapp, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Facades_AbstractFacade, app, arginfo_phalconplus_facades_abstractfacade_app, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Facades_AbstractFacade, getApp, arginfo_phalconplus_facades_abstractfacade_getapp, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Facades_AbstractFacade, itself, arginfo_phalconplus_facades_abstractfacade_itself, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(PhalconPlus_Facades_AbstractFacade, itself, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
	PHP_ME(PhalconPlus_Facades_AbstractFacade, __callStatic, arginfo_phalconplus_facades_abstractfacade___callstatic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
