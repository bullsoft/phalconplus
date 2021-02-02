
extern zend_class_entry *phalconplus_assert_assertionfailedexception_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Assert_AssertionFailedException);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_assert_assertionfailedexception___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, propertyPath)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_ARRAY_INFO(0, constraints, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_assert_assertionfailedexception_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_Assert_AssertionFailedException, __construct, arginfo_phalconplus_assert_assertionfailedexception___construct)
	PHP_ABSTRACT_ME(PhalconPlus_Assert_AssertionFailedException, getPropertyPath, NULL)
	PHP_ABSTRACT_ME(PhalconPlus_Assert_AssertionFailedException, getValue, NULL)
	PHP_ABSTRACT_ME(PhalconPlus_Assert_AssertionFailedException, getConstraints, NULL)
	PHP_FE_END
};
