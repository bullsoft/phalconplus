
extern zend_class_entry *phalconplus_logger_processor_logid_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Processor_LogId);

PHP_METHOD(PhalconPlus_Logger_Processor_LogId, __construct);
PHP_METHOD(PhalconPlus_Logger_Processor_LogId, setId);
PHP_METHOD(PhalconPlus_Logger_Processor_LogId, getId);
PHP_METHOD(PhalconPlus_Logger_Processor_LogId, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_processor_logid___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, len)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_processor_logid_setid, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, logId, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_processor_logid_getid, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_logger_processor_logid___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_processor_logid___tostring, 0, 0, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_logger_processor_logid_method_entry) {
	PHP_ME(PhalconPlus_Logger_Processor_LogId, __construct, arginfo_phalconplus_logger_processor_logid___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Logger_Processor_LogId, setId, arginfo_phalconplus_logger_processor_logid_setid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Logger_Processor_LogId, getId, arginfo_phalconplus_logger_processor_logid_getid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#else
	PHP_ME(PhalconPlus_Logger_Processor_LogId, getId, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Logger_Processor_LogId, __toString, arginfo_phalconplus_logger_processor_logid___tostring, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Logger_Processor_LogId, __toString, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
