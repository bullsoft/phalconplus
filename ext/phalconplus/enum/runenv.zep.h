
extern zend_class_entry *phalconplus_enum_runenv_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Enum_RunEnv);

PHP_METHOD(PhalconPlus_Enum_RunEnv, isInProd);
PHP_METHOD(PhalconPlus_Enum_RunEnv, isInAbTest);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_runenv_isinprod, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, env, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_runenv_isinabtest, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_enum_runenv_method_entry) {
	PHP_ME(PhalconPlus_Enum_RunEnv, isInProd, arginfo_phalconplus_enum_runenv_isinprod, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Enum_RunEnv, isInAbTest, arginfo_phalconplus_enum_runenv_isinabtest, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Enum_RunEnv, isInAbTest, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
