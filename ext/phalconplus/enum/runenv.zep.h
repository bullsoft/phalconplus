
extern zend_class_entry *phalconplus_enum_runenv_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Enum_RunEnv);

PHP_METHOD(PhalconPlus_Enum_RunEnv, isInProd);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_runenv_isinprod, 0, 0, 1)
	ZEND_ARG_INFO(0, env)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_enum_runenv_method_entry) {
	PHP_ME(PhalconPlus_Enum_RunEnv, isInProd, arginfo_phalconplus_enum_runenv_isinprod, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
