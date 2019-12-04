
extern zend_class_entry *phalconplus_enum_runenv_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Enum_RunEnv);

PHP_METHOD(PhalconPlus_Enum_RunEnv, isInProd);
PHP_METHOD(PhalconPlus_Enum_RunEnv, isInAbTest);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_runenv_isinprod, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_runenv_isinprod, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, env, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, env)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_enum_runenv_method_entry) {
	PHP_ME(PhalconPlus_Enum_RunEnv, isInProd, arginfo_phalconplus_enum_runenv_isinprod, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_RunEnv, isInAbTest, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
