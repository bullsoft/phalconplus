
extern zend_class_entry *phalconplus_logger_processor_msec_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Processor_Msec);

PHP_METHOD(PhalconPlus_Logger_Processor_Msec, __construct);
PHP_METHOD(PhalconPlus_Logger_Processor_Msec, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_processor_msec___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_logger_processor_msec___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_processor_msec___tostring, 0, 0, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_logger_processor_msec_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Logger_Processor_Msec, __construct, arginfo_phalconplus_logger_processor_msec___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#else
	PHP_ME(PhalconPlus_Logger_Processor_Msec, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Logger_Processor_Msec, __toString, arginfo_phalconplus_logger_processor_msec___tostring, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Logger_Processor_Msec, __toString, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
