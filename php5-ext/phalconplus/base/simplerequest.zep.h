
extern zend_class_entry *phalconplus_base_simplerequest_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_SimpleRequest);

PHP_METHOD(PhalconPlus_Base_SimpleRequest, getParam);
PHP_METHOD(PhalconPlus_Base_SimpleRequest, setParams);
PHP_METHOD(PhalconPlus_Base_SimpleRequest, setParam);
PHP_METHOD(PhalconPlus_Base_SimpleRequest, getParams);
zend_object_value zephir_init_properties_PhalconPlus_Base_SimpleRequest(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_simplerequest_getparam, 0, 0, 1)
	ZEND_ARG_INFO(0, idx)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_simplerequest_setparams, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_simplerequest_setparam, 0, 0, 1)
	ZEND_ARG_INFO(0, val)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_simplerequest_method_entry) {
	PHP_ME(PhalconPlus_Base_SimpleRequest, getParam, arginfo_phalconplus_base_simplerequest_getparam, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleRequest, setParams, arginfo_phalconplus_base_simplerequest_setparams, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleRequest, setParam, arginfo_phalconplus_base_simplerequest_setparam, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_SimpleRequest, getParams, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
