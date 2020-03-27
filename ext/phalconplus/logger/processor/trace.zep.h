
extern zend_class_entry *phalconplus_logger_processor_trace_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Processor_Trace);

PHP_METHOD(PhalconPlus_Logger_Processor_Trace, __construct);
PHP_METHOD(PhalconPlus_Logger_Processor_Trace, setLimit);
PHP_METHOD(PhalconPlus_Logger_Processor_Trace, __toString);
zend_object *zephir_init_properties_PhalconPlus_Logger_Processor_Trace(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_processor_trace___construct, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, mode)
#endif
	ZEND_ARG_ARRAY_INFO(0, skipClassesPartials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_processor_trace_setlimit, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, limit, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, limit)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_logger_processor_trace_method_entry) {
	PHP_ME(PhalconPlus_Logger_Processor_Trace, __construct, arginfo_phalconplus_logger_processor_trace___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Logger_Processor_Trace, setLimit, arginfo_phalconplus_logger_processor_trace_setlimit, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Logger_Processor_Trace, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
