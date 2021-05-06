
extern zend_class_entry *phalconplus_enum_exception_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Enum_Exception);

PHP_METHOD(PhalconPlus_Enum_Exception, has);
PHP_METHOD(PhalconPlus_Enum_Exception, getByCode);
PHP_METHOD(PhalconPlus_Enum_Exception, newException);
PHP_METHOD(PhalconPlus_Enum_Exception, exceptionClassPrefix);
PHP_METHOD(PhalconPlus_Enum_Exception, getMessage);
PHP_METHOD(PhalconPlus_Enum_Exception, getLevel);
PHP_METHOD(PhalconPlus_Enum_Exception, getCode);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_exception_has, 0, 0, 1)
	ZEND_ARG_INFO(0, eCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_exception_getbycode, 0, 0, 1)
	ZEND_ARG_INFO(0, eCode)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_exception_newexception, 0, 0, 1)
	ZEND_ARG_INFO(0, e)
	ZEND_ARG_OBJ_INFO(0, logger, Phalcon\\Logger\\Adapter, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_exception_exceptionclassprefix, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_exception_getmessage, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_exception_getlevel, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_enum_exception_getcode, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_enum_exception_method_entry) {
	PHP_ME(PhalconPlus_Enum_Exception, has, arginfo_phalconplus_enum_exception_has, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_Exception, getByCode, arginfo_phalconplus_enum_exception_getbycode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Enum_Exception, newException, arginfo_phalconplus_enum_exception_newexception, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Enum_Exception, exceptionClassPrefix, arginfo_phalconplus_enum_exception_exceptionclassprefix, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(PhalconPlus_Enum_Exception, exceptionClassPrefix, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Enum_Exception, getMessage, arginfo_phalconplus_enum_exception_getmessage, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Enum_Exception, getMessage, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Enum_Exception, getLevel, arginfo_phalconplus_enum_exception_getlevel, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Enum_Exception, getLevel, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Enum_Exception, getCode, arginfo_phalconplus_enum_exception_getcode, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Enum_Exception, getCode, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
