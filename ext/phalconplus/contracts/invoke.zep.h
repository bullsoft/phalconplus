
extern zend_class_entry *phalconplus_contracts_invoke_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_Invoke);

ZEPHIR_INIT_FUNCS(phalconplus_contracts_invoke_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Invoke, __invoke, NULL)
	PHP_FE_END
};
