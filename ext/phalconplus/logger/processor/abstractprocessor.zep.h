
extern zend_class_entry *phalconplus_logger_processor_abstractprocessor_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Processor_AbstractProcessor);

PHP_METHOD(PhalconPlus_Logger_Processor_AbstractProcessor, __toString);

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_logger_processor_abstractprocessor___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_processor_abstractprocessor___tostring, 0, 0, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_logger_processor_abstractprocessor_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Logger_Processor_AbstractProcessor, __toString, arginfo_phalconplus_logger_processor_abstractprocessor___tostring, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
#else
	PHP_ME(PhalconPlus_Logger_Processor_AbstractProcessor, __toString, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT)
#endif
	PHP_FE_END
};
