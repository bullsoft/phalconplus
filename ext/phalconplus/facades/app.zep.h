
extern zend_class_entry *phalconplus_facades_app_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Facades_App);

PHP_METHOD(PhalconPlus_Facades_App, getName);
PHP_METHOD(PhalconPlus_Facades_App, resolve);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_facades_app_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_facades_app_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_facades_app_resolve, 0, 1, Phalcon\\Di, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_facades_app_resolve, 0, 1, IS_OBJECT, "Phalcon\\Di", 1)
#endif
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\Di, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_facades_app_method_entry) {
	PHP_ME(PhalconPlus_Facades_App, getName, arginfo_phalconplus_facades_app_getname, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Facades_App, resolve, arginfo_phalconplus_facades_app_resolve, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
