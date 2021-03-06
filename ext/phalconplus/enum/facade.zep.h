
extern zend_class_entry *phalconplus_enum_facade_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Enum_Facade);

PHP_METHOD(PhalconPlus_Enum_Facade, register);
void zephir_init_static_properties_PhalconPlus_Enum_Facade(TSRMLS_D);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_facade_register, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_facade_register, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, superApp, PhalconPlus\\App\\App, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prefix, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, prefix)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_enum_facade_method_entry) {
	PHP_ME(PhalconPlus_Enum_Facade, register, arginfo_phalconplus_enum_facade_register, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
