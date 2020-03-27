
extern zend_class_entry *phalconplus_helper_str_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Helper_Str);

PHP_METHOD(PhalconPlus_Helper_Str, decodeJson);

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

ZEPHIR_INIT_FUNCS(phalconplus_helper_str_method_entry) {
	PHP_ME(PhalconPlus_Helper_Str, decodeJson, arginfo_phalconplus_helper_str_decodejson, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
