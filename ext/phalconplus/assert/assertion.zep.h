
extern zend_class_entry *phalconplus_assert_assertion_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Assert_Assertion);

PHP_METHOD(PhalconPlus_Assert_Assertion, createException);
PHP_METHOD(PhalconPlus_Assert_Assertion, eq);
PHP_METHOD(PhalconPlus_Assert_Assertion, notEq);
PHP_METHOD(PhalconPlus_Assert_Assertion, same);
PHP_METHOD(PhalconPlus_Assert_Assertion, notEmpty);
PHP_METHOD(PhalconPlus_Assert_Assertion, notNull);
PHP_METHOD(PhalconPlus_Assert_Assertion, numeric);
PHP_METHOD(PhalconPlus_Assert_Assertion, range);
PHP_METHOD(PhalconPlus_Assert_Assertion, min);
PHP_METHOD(PhalconPlus_Assert_Assertion, max);
PHP_METHOD(PhalconPlus_Assert_Assertion, isString);
PHP_METHOD(PhalconPlus_Assert_Assertion, isArray);
PHP_METHOD(PhalconPlus_Assert_Assertion, isJsonString);
PHP_METHOD(PhalconPlus_Assert_Assertion, stringify);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_assert_assertion_createexception, 0, 0, 4)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, code)
	ZEND_ARG_INFO(0, propertyPath)
	ZEND_ARG_ARRAY_INFO(0, constraints, 1)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_eq, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_eq, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, value1)
	ZEND_ARG_INFO(0, value2)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, propertyPath)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_noteq, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_noteq, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, value1)
	ZEND_ARG_INFO(0, value2)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, propertyPath)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_same, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_same, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, value1)
	ZEND_ARG_INFO(0, value2)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, propertyPath)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_notempty, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_notempty, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, propertyPath)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_notnull, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_notnull, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, propertyPath)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_numeric, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_numeric, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, propertyPath)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_range, 0, 3, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_range, 0, 3, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, minValue, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, maxValue, IS_LONG, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, propertyPath)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_min, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_min, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, minValue, IS_LONG, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, propertyPath)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_max, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_max, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, maxValue, IS_LONG, 0)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, propertyPath)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_isstring, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_isstring, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, propertyPath)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_isarray, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_isarray, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, propertyPath)
ZEND_END_ARG_INFO()

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_isjsonstring, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_assert_assertion_isjsonstring, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, propertyPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_assert_assertion_stringify, 0, 0, 1)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_assert_assertion_method_entry) {
	PHP_ME(PhalconPlus_Assert_Assertion, createException, arginfo_phalconplus_assert_assertion_createexception, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Assert_Assertion, eq, arginfo_phalconplus_assert_assertion_eq, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Assert_Assertion, notEq, arginfo_phalconplus_assert_assertion_noteq, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Assert_Assertion, same, arginfo_phalconplus_assert_assertion_same, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Assert_Assertion, notEmpty, arginfo_phalconplus_assert_assertion_notempty, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Assert_Assertion, notNull, arginfo_phalconplus_assert_assertion_notnull, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Assert_Assertion, numeric, arginfo_phalconplus_assert_assertion_numeric, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Assert_Assertion, range, arginfo_phalconplus_assert_assertion_range, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Assert_Assertion, min, arginfo_phalconplus_assert_assertion_min, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Assert_Assertion, max, arginfo_phalconplus_assert_assertion_max, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Assert_Assertion, isString, arginfo_phalconplus_assert_assertion_isstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Assert_Assertion, isArray, arginfo_phalconplus_assert_assertion_isarray, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Assert_Assertion, isJsonString, arginfo_phalconplus_assert_assertion_isjsonstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Assert_Assertion, stringify, arginfo_phalconplus_assert_assertion_stringify, ZEND_ACC_PRIVATE|ZEND_ACC_STATIC)
	PHP_FE_END
};
