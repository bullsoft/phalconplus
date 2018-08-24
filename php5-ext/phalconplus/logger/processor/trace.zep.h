
extern zend_class_entry *phalconplus_logger_processor_trace_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Processor_Trace);

PHP_METHOD(PhalconPlus_Logger_Processor_Trace, __construct);
PHP_METHOD(PhalconPlus_Logger_Processor_Trace, __toString);
zend_object_value zephir_init_properties_PhalconPlus_Logger_Processor_Trace(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_processor_trace___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, mode)
	ZEND_ARG_ARRAY_INFO(0, skipClassesPartials, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_logger_processor_trace_method_entry) {
	PHP_ME(PhalconPlus_Logger_Processor_Trace, __construct, arginfo_phalconplus_logger_processor_trace___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Logger_Processor_Trace, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
