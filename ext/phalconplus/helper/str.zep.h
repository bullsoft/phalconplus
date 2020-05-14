
extern zend_class_entry *phalconplus_helper_str_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Helper_Str);

PHP_METHOD(PhalconPlus_Helper_Str, decodeJson);
PHP_METHOD(PhalconPlus_Helper_Str, startsWith);
PHP_METHOD(PhalconPlus_Helper_Str, endsWith);
PHP_METHOD(PhalconPlus_Helper_Str, contains);
PHP_METHOD(PhalconPlus_Helper_Str, safeBase64Encode);
PHP_METHOD(PhalconPlus_Helper_Str, safeBase64Decode);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_helper_str_decodejson, 0, 1, ArrayObject, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_str_decodejson, 0, 1, IS_OBJECT, "ArrayObject", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, inputStr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, inputStr)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_str_startswith, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_str_startswith, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, full, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, full)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, partial, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, partial)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_str_endswith, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_str_endswith, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, full, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, full)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, partial, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, partial)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_str_contains, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_str_contains, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, full, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, full)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, partial, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, partial)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_str_safebase64encode, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_str_safebase64encode, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, inputStr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, inputStr)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, padding, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, padding)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_helper_str_safebase64decode, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, inputStr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, inputStr)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_helper_str_method_entry) {
	PHP_ME(PhalconPlus_Helper_Str, decodeJson, arginfo_phalconplus_helper_str_decodejson, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Str, startsWith, arginfo_phalconplus_helper_str_startswith, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Str, endsWith, arginfo_phalconplus_helper_str_endswith, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Str, contains, arginfo_phalconplus_helper_str_contains, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Str, safeBase64Encode, arginfo_phalconplus_helper_str_safebase64encode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Str, safeBase64Decode, arginfo_phalconplus_helper_str_safebase64decode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
