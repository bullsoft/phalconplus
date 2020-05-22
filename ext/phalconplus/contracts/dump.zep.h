
extern zend_class_entry *phalconplus_contracts_dump_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_Dump);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_dump___debuginfo, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_dump___debuginfo, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_contracts_dump_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Dump, __debugInfo, arginfo_phalconplus_contracts_dump___debuginfo)
	PHP_FE_END
};
