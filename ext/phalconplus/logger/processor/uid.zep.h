
extern zend_class_entry *phalconplus_logger_processor_uid_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Processor_Uid);

PHP_METHOD(PhalconPlus_Logger_Processor_Uid, __construct);
PHP_METHOD(PhalconPlus_Logger_Processor_Uid, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_processor_uid___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, len)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_logger_processor_uid_method_entry) {
	PHP_ME(PhalconPlus_Logger_Processor_Uid, __construct, arginfo_phalconplus_logger_processor_uid___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Logger_Processor_Uid, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
