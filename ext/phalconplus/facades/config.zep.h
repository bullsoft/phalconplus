
extern zend_class_entry *phalconplus_facades_config_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Facades_Config);

PHP_METHOD(PhalconPlus_Facades_Config, getName);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_facades_config_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_facades_config_method_entry) {
	PHP_ME(PhalconPlus_Facades_Config, getName, arginfo_phalconplus_facades_config_getname, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
