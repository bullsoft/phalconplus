
extern zend_class_entry *phalconplus_volt_extension_phpfunction_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Volt_Extension_PhpFunction);

PHP_METHOD(PhalconPlus_Volt_Extension_PhpFunction, compileFunction);

ZEPHIR_INIT_FUNCS(phalconplus_volt_extension_phpfunction_method_entry) {
	PHP_ME(PhalconPlus_Volt_Extension_PhpFunction, compileFunction, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
