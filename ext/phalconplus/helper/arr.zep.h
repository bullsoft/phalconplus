
extern zend_class_entry *phalconplus_helper_arr_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Helper_Arr);

PHP_METHOD(PhalconPlus_Helper_Arr, isAllKeyInt);
PHP_METHOD(PhalconPlus_Helper_Arr, isAllKeyString);
PHP_METHOD(PhalconPlus_Helper_Arr, isKeyNumericSequentialZeroBased);
PHP_METHOD(PhalconPlus_Helper_Arr, newProtoBuffer);
PHP_METHOD(PhalconPlus_Helper_Arr, encodeJson);
PHP_METHOD(PhalconPlus_Helper_Arr, firstKey);
PHP_METHOD(PhalconPlus_Helper_Arr, lastKey);
PHP_METHOD(PhalconPlus_Helper_Arr, first);
PHP_METHOD(PhalconPlus_Helper_Arr, last);
PHP_METHOD(PhalconPlus_Helper_Arr, groupBy);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_arr_isallkeyint, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_arr_isallkeyint, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, inputArray)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_arr_isallkeystring, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_arr_isallkeystring, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, inputArray)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_arr_iskeynumericsequentialzerobased, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_arr_iskeynumericsequentialzerobased, 0, 1, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_INFO(0, inputArray)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_helper_arr_newprotobuffer, 0, 1, PhalconPlus\\Base\\ProtoBuffer, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_arr_newprotobuffer, 0, 1, IS_OBJECT, "PhalconPlus\\Base\\ProtoBuffer", 0)
#endif
	ZEND_ARG_INFO(0, inputArray)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_arr_encodejson, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_arr_encodejson, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, inputArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_helper_arr_firstkey, 0, 0, 1)
	ZEND_ARG_INFO(0, inputArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_helper_arr_lastkey, 0, 0, 1)
	ZEND_ARG_INFO(0, inputArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_helper_arr_first, 0, 0, 1)
	ZEND_ARG_INFO(0, inputArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_helper_arr_last, 0, 0, 1)
	ZEND_ARG_INFO(0, inputArray)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_arr_groupby, 0, 2, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_arr_groupby, 0, 2, IS_ARRAY, NULL, 0)
#endif
	ZEND_ARG_INFO(0, inputArray)
	ZEND_ARG_INFO(0, handler)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_helper_arr_method_entry) {
	PHP_ME(PhalconPlus_Helper_Arr, isAllKeyInt, arginfo_phalconplus_helper_arr_isallkeyint, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Arr, isAllKeyString, arginfo_phalconplus_helper_arr_isallkeystring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Arr, isKeyNumericSequentialZeroBased, arginfo_phalconplus_helper_arr_iskeynumericsequentialzerobased, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Arr, newProtoBuffer, arginfo_phalconplus_helper_arr_newprotobuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Arr, encodeJson, arginfo_phalconplus_helper_arr_encodejson, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Arr, firstKey, arginfo_phalconplus_helper_arr_firstkey, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Arr, lastKey, arginfo_phalconplus_helper_arr_lastkey, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Arr, first, arginfo_phalconplus_helper_arr_first, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Arr, last, arginfo_phalconplus_helper_arr_last, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Arr, groupBy, arginfo_phalconplus_helper_arr_groupby, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
