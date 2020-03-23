
extern zend_class_entry *phalconplus_helper_arr_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Helper_Arr);

PHP_METHOD(PhalconPlus_Helper_Arr, isAllKeyInt);
PHP_METHOD(PhalconPlus_Helper_Arr, isAllKeyString);
PHP_METHOD(PhalconPlus_Helper_Arr, isKeyNumericSequentialZeroBased);
PHP_METHOD(PhalconPlus_Helper_Arr, newProtoBuffer);
PHP_METHOD(PhalconPlus_Helper_Arr, encodeJson);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_helper_arr_isallkeyint, 0, 0, 1)
	ZEND_ARG_INFO(0, inputArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_helper_arr_isallkeystring, 0, 0, 1)
	ZEND_ARG_INFO(0, inputArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_helper_arr_iskeynumericsequentialzerobased, 0, 0, 1)
	ZEND_ARG_INFO(0, inputArray)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_helper_arr_newprotobuffer, 0, 0, 1)
	ZEND_ARG_INFO(0, inputArray)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_arr_encodejson, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_helper_arr_encodejson, 0, 1, IS_STRING, NULL, 0)
#endif
	ZEND_ARG_INFO(0, inputArray)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_helper_arr_method_entry) {
	PHP_ME(PhalconPlus_Helper_Arr, isAllKeyInt, arginfo_phalconplus_helper_arr_isallkeyint, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Arr, isAllKeyString, arginfo_phalconplus_helper_arr_isallkeystring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Arr, isKeyNumericSequentialZeroBased, arginfo_phalconplus_helper_arr_iskeynumericsequentialzerobased, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Arr, newProtoBuffer, arginfo_phalconplus_helper_arr_newprotobuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Helper_Arr, encodeJson, arginfo_phalconplus_helper_arr_encodejson, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
