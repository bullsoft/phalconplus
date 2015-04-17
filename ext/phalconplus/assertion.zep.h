
extern zend_class_entry *phalconplus_assertion_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Assertion);

PHP_METHOD(PhalconPlus_Assertion, setUp);
PHP_METHOD(PhalconPlus_Assertion, equal);
PHP_METHOD(PhalconPlus_Assertion, greaterThan);
PHP_METHOD(PhalconPlus_Assertion, lessThan);
PHP_METHOD(PhalconPlus_Assertion, handler);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_assertion_equal, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_assertion_greaterthan, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_assertion_lessthan, 0, 0, 2)
	ZEND_ARG_INFO(0, a)
	ZEND_ARG_INFO(0, b)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_assertion_handler, 0, 0, 3)
	ZEND_ARG_INFO(0, file)
	ZEND_ARG_INFO(0, line)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, desc)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_assertion_method_entry) {
	PHP_ME(PhalconPlus_Assertion, setUp, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Assertion, equal, arginfo_phalconplus_assertion_equal, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Assertion, greaterThan, arginfo_phalconplus_assertion_greaterthan, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Assertion, lessThan, arginfo_phalconplus_assertion_lessthan, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Assertion, handler, arginfo_phalconplus_assertion_handler, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
  PHP_FE_END
};
