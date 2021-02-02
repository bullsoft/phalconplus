
extern zend_class_entry *phalconplus_assert_invalidargumentexception_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Assert_InvalidArgumentException);

PHP_METHOD(PhalconPlus_Assert_InvalidArgumentException, __construct);
PHP_METHOD(PhalconPlus_Assert_InvalidArgumentException, getPropertyPath);
PHP_METHOD(PhalconPlus_Assert_InvalidArgumentException, getValue);
PHP_METHOD(PhalconPlus_Assert_InvalidArgumentException, getConstraints);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_assert_invalidargumentexception___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, propertyPath)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, constraints, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_assert_invalidargumentexception_method_entry) {
	PHP_ME(PhalconPlus_Assert_InvalidArgumentException, __construct, arginfo_phalconplus_assert_invalidargumentexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Assert_InvalidArgumentException, getPropertyPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Assert_InvalidArgumentException, getValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Assert_InvalidArgumentException, getConstraints, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
