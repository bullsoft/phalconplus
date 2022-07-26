
extern zend_class_entry *phalconplus_enum_abstractenum_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Enum_AbstractEnum);

PHP_METHOD(PhalconPlus_Enum_AbstractEnum, __construct);
PHP_METHOD(PhalconPlus_Enum_AbstractEnum, setValue);
PHP_METHOD(PhalconPlus_Enum_AbstractEnum, getValue);
PHP_METHOD(PhalconPlus_Enum_AbstractEnum, isValid);
PHP_METHOD(PhalconPlus_Enum_AbstractEnum, commaString);
PHP_METHOD(PhalconPlus_Enum_AbstractEnum, getList);
PHP_METHOD(PhalconPlus_Enum_AbstractEnum, getMap);
PHP_METHOD(PhalconPlus_Enum_AbstractEnum, getValues);
PHP_METHOD(PhalconPlus_Enum_AbstractEnum, validValues);
PHP_METHOD(PhalconPlus_Enum_AbstractEnum, jsonSerialize);
PHP_METHOD(PhalconPlus_Enum_AbstractEnum, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_abstractenum___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_abstractenum_setvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_abstractenum_getvalue, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_abstractenum_isvalid, 0, 0, 1)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_abstractenum_commastring, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_abstractenum_getlist, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_abstractenum_getmap, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_abstractenum_getvalues, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_abstractenum_validvalues, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, assoc, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_abstractenum_jsonserialize, 0, 0, IS_MIXED, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_abstractenum_jsonserialize, 0, 0, IS_NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_enum_abstractenum___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_abstractenum___tostring, 0, 0, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_enum_abstractenum_method_entry) {
	PHP_ME(PhalconPlus_Enum_AbstractEnum, __construct, arginfo_phalconplus_enum_abstractenum___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Enum_AbstractEnum, setValue, arginfo_phalconplus_enum_abstractenum_setvalue, ZEND_ACC_PROTECTED)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Enum_AbstractEnum, getValue, arginfo_phalconplus_enum_abstractenum_getvalue, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Enum_AbstractEnum, getValue, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(PhalconPlus_Enum_AbstractEnum, isValid, arginfo_phalconplus_enum_abstractenum_isvalid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Enum_AbstractEnum, commaString, arginfo_phalconplus_enum_abstractenum_commastring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(PhalconPlus_Enum_AbstractEnum, commaString, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Enum_AbstractEnum, getList, arginfo_phalconplus_enum_abstractenum_getlist, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(PhalconPlus_Enum_AbstractEnum, getList, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Enum_AbstractEnum, getMap, arginfo_phalconplus_enum_abstractenum_getmap, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(PhalconPlus_Enum_AbstractEnum, getMap, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Enum_AbstractEnum, getValues, arginfo_phalconplus_enum_abstractenum_getvalues, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(PhalconPlus_Enum_AbstractEnum, getValues, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
	PHP_ME(PhalconPlus_Enum_AbstractEnum, validValues, arginfo_phalconplus_enum_abstractenum_validvalues, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_AbstractEnum, jsonSerialize, arginfo_phalconplus_enum_abstractenum_jsonserialize, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Enum_AbstractEnum, __toString, arginfo_phalconplus_enum_abstractenum___tostring, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Enum_AbstractEnum, __toString, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
