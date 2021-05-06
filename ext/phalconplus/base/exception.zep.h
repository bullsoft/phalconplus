
extern zend_class_entry *phalconplus_base_exception_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_Exception);

PHP_METHOD(PhalconPlus_Base_Exception, __construct);
PHP_METHOD(PhalconPlus_Base_Exception, getLevel);
PHP_METHOD(PhalconPlus_Base_Exception, setLevel);
PHP_METHOD(PhalconPlus_Base_Exception, getInfo);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_exception___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, info)
	ZEND_ARG_TYPE_INFO(0, code, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_exception_getlevel, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_exception_setlevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_exception_getinfo, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_exception_method_entry) {
	PHP_ME(PhalconPlus_Base_Exception, __construct, arginfo_phalconplus_base_exception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Exception, getLevel, arginfo_phalconplus_base_exception_getlevel, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Exception, getLevel, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(PhalconPlus_Base_Exception, setLevel, arginfo_phalconplus_base_exception_setlevel, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Exception, getInfo, arginfo_phalconplus_base_exception_getinfo, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Exception, getInfo, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
