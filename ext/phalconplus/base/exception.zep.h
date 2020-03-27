
extern zend_class_entry *phalconplus_base_exception_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_Exception);

PHP_METHOD(PhalconPlus_Base_Exception, __construct);
PHP_METHOD(PhalconPlus_Base_Exception, getLevel);
PHP_METHOD(PhalconPlus_Base_Exception, setLevel);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_exception___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, info)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, code)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_exception_setlevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_exception_method_entry) {
	PHP_ME(PhalconPlus_Base_Exception, __construct, arginfo_phalconplus_base_exception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Base_Exception, getLevel, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Exception, setLevel, arginfo_phalconplus_base_exception_setlevel, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
