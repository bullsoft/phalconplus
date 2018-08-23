
extern zend_class_entry *phalconplus_enum_abstractenum_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Enum_AbstractEnum);

PHP_METHOD(PhalconPlus_Enum_AbstractEnum, __construct);
PHP_METHOD(PhalconPlus_Enum_AbstractEnum, setValue);
PHP_METHOD(PhalconPlus_Enum_AbstractEnum, getValue);
PHP_METHOD(PhalconPlus_Enum_AbstractEnum, isValid);
PHP_METHOD(PhalconPlus_Enum_AbstractEnum, validValues);
PHP_METHOD(PhalconPlus_Enum_AbstractEnum, jsonSerialize);
PHP_METHOD(PhalconPlus_Enum_AbstractEnum, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_abstractenum___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_abstractenum_setvalue, 0, 0, 1)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_abstractenum_isvalid, 0, 0, 1)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_abstractenum_validvalues, 0, 0, 0)
	ZEND_ARG_TYPE_INFO(0, assoc, _IS_BOOL, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_enum_abstractenum_method_entry) {
	PHP_ME(PhalconPlus_Enum_AbstractEnum, __construct, arginfo_phalconplus_enum_abstractenum___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Enum_AbstractEnum, setValue, arginfo_phalconplus_enum_abstractenum_setvalue, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Enum_AbstractEnum, getValue, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Enum_AbstractEnum, isValid, arginfo_phalconplus_enum_abstractenum_isvalid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_AbstractEnum, validValues, arginfo_phalconplus_enum_abstractenum_validvalues, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_AbstractEnum, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Enum_AbstractEnum, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
