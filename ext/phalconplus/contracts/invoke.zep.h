
extern zend_class_entry *phalconplus_contracts_invoke_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_Invoke);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_contracts_invoke___invoke, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_contracts_invoke_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Invoke, __invoke, arginfo_phalconplus_contracts_invoke___invoke)
	PHP_FE_END
};
