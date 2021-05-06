
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
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, constraints, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, constraints, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_assert_invalidargumentexception_getpropertypath, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_assert_invalidargumentexception_getvalue, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_assert_invalidargumentexception_getconstraints, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_assert_invalidargumentexception_method_entry) {
	PHP_ME(PhalconPlus_Assert_InvalidArgumentException, __construct, arginfo_phalconplus_assert_invalidargumentexception___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Assert_InvalidArgumentException, getPropertyPath, arginfo_phalconplus_assert_invalidargumentexception_getpropertypath, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Assert_InvalidArgumentException, getPropertyPath, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Assert_InvalidArgumentException, getValue, arginfo_phalconplus_assert_invalidargumentexception_getvalue, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Assert_InvalidArgumentException, getValue, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Assert_InvalidArgumentException, getConstraints, arginfo_phalconplus_assert_invalidargumentexception_getconstraints, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Assert_InvalidArgumentException, getConstraints, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
