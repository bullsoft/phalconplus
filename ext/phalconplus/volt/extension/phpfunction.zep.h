
extern zend_class_entry *phalconplus_volt_extension_phpfunction_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Volt_Extension_PhpFunction);

PHP_METHOD(PhalconPlus_Volt_Extension_PhpFunction, setCustNamespace);
PHP_METHOD(PhalconPlus_Volt_Extension_PhpFunction, setCustFuncName);
PHP_METHOD(PhalconPlus_Volt_Extension_PhpFunction, compileFunction);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_volt_extension_phpfunction_setcustnamespace, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, ns, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_volt_extension_phpfunction_setcustfuncname, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, func, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_volt_extension_phpfunction_method_entry) {
	PHP_ME(PhalconPlus_Volt_Extension_PhpFunction, setCustNamespace, arginfo_phalconplus_volt_extension_phpfunction_setcustnamespace, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Volt_Extension_PhpFunction, setCustFuncName, arginfo_phalconplus_volt_extension_phpfunction_setcustfuncname, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Volt_Extension_PhpFunction, compileFunction, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
