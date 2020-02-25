
extern zend_class_entry *phalconplus_contracts_eventattachable_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_EventAttachable);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_contracts_eventattachable_attach, 0, 0, 1)
	ZEND_ARG_INFO(0, param)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_contracts_eventattachable_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_EventAttachable, attach, arginfo_phalconplus_contracts_eventattachable_attach)
	PHP_FE_END
};
