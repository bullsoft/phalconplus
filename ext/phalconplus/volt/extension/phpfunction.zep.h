
extern zend_class_entry *phalconplus_volt_extension_phpfunction_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Volt_Extension_PhpFunction);

PHP_METHOD(PhalconPlus_Volt_Extension_PhpFunction, compileFunction);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_volt_extension_phpfunction_compilefunction, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, arguments)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_volt_extension_phpfunction_method_entry) {
	PHP_ME(PhalconPlus_Volt_Extension_PhpFunction, compileFunction, arginfo_phalconplus_volt_extension_phpfunction_compilefunction, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
