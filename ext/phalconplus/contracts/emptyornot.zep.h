
extern zend_class_entry *phalconplus_contracts_emptyornot_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_EmptyOrNot);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_emptyornot_isempty, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_contracts_emptyornot_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_EmptyOrNot, isEmpty, arginfo_phalconplus_contracts_emptyornot_isempty)
	PHP_FE_END
};
