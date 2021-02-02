
extern zend_class_entry *phalconplus_logger_processor_msec_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Processor_Msec);

PHP_METHOD(PhalconPlus_Logger_Processor_Msec, __construct);
PHP_METHOD(PhalconPlus_Logger_Processor_Msec, __toString);

ZEPHIR_INIT_FUNCS(phalconplus_logger_processor_msec_method_entry) {
	PHP_ME(PhalconPlus_Logger_Processor_Msec, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Logger_Processor_Msec, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
