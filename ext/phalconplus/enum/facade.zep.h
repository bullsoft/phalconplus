
extern zend_class_entry *phalconplus_enum_facade_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Enum_Facade);

PHP_METHOD(PhalconPlus_Enum_Facade, register);
void zephir_init_static_properties_PhalconPlus_Enum_Facade();

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_facade_register, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, superApp, PhalconPlus\\App\\App, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_facade_zephir_init_static_properties_phalconplus_enum_facade, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_enum_facade_method_entry) {
	PHP_ME(PhalconPlus_Enum_Facade, register, arginfo_phalconplus_enum_facade_register, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
