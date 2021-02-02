
extern zend_class_entry *phalconplus_helper_ns_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Helper_Ns);

PHP_METHOD(PhalconPlus_Helper_Ns, super);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_ns_super, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_ns_super, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, ns, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, ns)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, levels, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, levels)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_helper_ns_method_entry) {
	PHP_ME(PhalconPlus_Helper_Ns, super, arginfo_phalconplus_helper_ns_super, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
