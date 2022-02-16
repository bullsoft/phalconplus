
extern zend_class_entry *phalconplus_assert_assertionfailedexception_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Assert_AssertionFailedException);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_assert_assertionfailedexception___construct, 0, 0, 3)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, propertyPath)
	ZEND_ARG_INFO(0, value)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, constraints, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, constraints, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_assert_assertionfailedexception_getpropertypath, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_assert_assertionfailedexception_getvalue, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_assert_assertionfailedexception_getconstraints, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_assert_assertionfailedexception_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_Assert_AssertionFailedException, __construct, arginfo_phalconplus_assert_assertionfailedexception___construct)
	PHP_ABSTRACT_ME(PhalconPlus_Assert_AssertionFailedException, getPropertyPath, arginfo_phalconplus_assert_assertionfailedexception_getpropertypath)
	PHP_ABSTRACT_ME(PhalconPlus_Assert_AssertionFailedException, getValue, arginfo_phalconplus_assert_assertionfailedexception_getvalue)
	PHP_ABSTRACT_ME(PhalconPlus_Assert_AssertionFailedException, getConstraints, arginfo_phalconplus_assert_assertionfailedexception_getconstraints)
	PHP_FE_END
};
