
extern zend_class_entry *phalconplus_helper_variable_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Helper_Variable);

PHP_METHOD(PhalconPlus_Helper_Variable, softNull);
PHP_METHOD(PhalconPlus_Helper_Variable, isSoftNull);
PHP_METHOD(PhalconPlus_Helper_Variable, notNull);
PHP_METHOD(PhalconPlus_Helper_Variable, notEmpty);
PHP_METHOD(PhalconPlus_Helper_Variable, isInt);
PHP_METHOD(PhalconPlus_Helper_Variable, isArray);
PHP_METHOD(PhalconPlus_Helper_Variable, isObject);
PHP_METHOD(PhalconPlus_Helper_Variable, isBool);
PHP_METHOD(PhalconPlus_Helper_Variable, isString);
PHP_METHOD(PhalconPlus_Helper_Variable, isNull);
PHP_METHOD(PhalconPlus_Helper_Variable, isFloat);
PHP_METHOD(PhalconPlus_Helper_Variable, isFunctional);
PHP_METHOD(PhalconPlus_Helper_Variable, stringify);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_helper_variable_issoftnull, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, nil, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, nil)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_helper_variable_notnull, 0, 0, 1)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_helper_variable_notempty, 0, 0, 1)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_variable_isint, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_variable_isint, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_variable_isarray, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_variable_isarray, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_variable_isobject, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_variable_isobject, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_variable_isbool, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_variable_isbool, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_variable_isstring, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_variable_isstring, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_variable_isnull, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_variable_isnull, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_variable_isfloat, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_variable_isfloat, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_variable_isfunctional, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_variable_isfunctional, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, input)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_variable_stringify, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_variable_stringify, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, value)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, full, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, full)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_helper_variable_method_entry) {
	PHP_ME(PhalconPlus_Helper_Variable, softNull, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Variable, isSoftNull, arginfo_phalconplus_helper_variable_issoftnull, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Variable, notNull, arginfo_phalconplus_helper_variable_notnull, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Variable, notEmpty, arginfo_phalconplus_helper_variable_notempty, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Variable, isInt, arginfo_phalconplus_helper_variable_isint, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Variable, isArray, arginfo_phalconplus_helper_variable_isarray, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Variable, isObject, arginfo_phalconplus_helper_variable_isobject, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Variable, isBool, arginfo_phalconplus_helper_variable_isbool, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Variable, isString, arginfo_phalconplus_helper_variable_isstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Variable, isNull, arginfo_phalconplus_helper_variable_isnull, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Variable, isFloat, arginfo_phalconplus_helper_variable_isfloat, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Variable, isFunctional, arginfo_phalconplus_helper_variable_isfunctional, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Variable, stringify, arginfo_phalconplus_helper_variable_stringify, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
