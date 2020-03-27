
extern zend_class_entry *phalconplus_contracts_arrayof_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_ArrayOf);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_arrayof_toarray, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_arrayof_toarray, 0, 0, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_ARRAY_INFO(0, columns, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_contracts_arrayof_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_ArrayOf, toArray, arginfo_phalconplus_contracts_arrayof_toarray)
	PHP_FE_END
};
