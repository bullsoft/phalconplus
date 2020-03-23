
extern zend_class_entry *phalconplus_contracts_isempty_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_IsEmpty);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_isempty_isempty, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_isempty_isempty, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_contracts_isempty_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_IsEmpty, isEmpty, arginfo_phalconplus_contracts_isempty_isempty)
	PHP_FE_END
};
