
extern zend_class_entry *phalconplus_enum_runmode_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Enum_RunMode);

PHP_METHOD(PhalconPlus_Enum_RunMode, getMapClassName);
zend_object_value zephir_init_properties_PhalconPlus_Enum_RunMode(zend_class_entry *class_type TSRMLS_DC);

ZEPHIR_INIT_FUNCS(phalconplus_enum_runmode_method_entry) {
	PHP_ME(PhalconPlus_Enum_RunMode, getMapClassName, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
