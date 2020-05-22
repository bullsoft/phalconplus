
extern zend_class_entry *phalconplus_contracts_stringer_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_Stringer);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_stringer___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_stringer___tostring, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_contracts_stringer_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Stringer, __toString, arginfo_phalconplus_contracts_stringer___tostring)
	PHP_FE_END
};
