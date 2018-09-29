
extern zend_class_entry *phalconplus_logger_formatter_lineplus_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Formatter_LinePlus);

PHP_METHOD(PhalconPlus_Logger_Formatter_LinePlus, __construct);
PHP_METHOD(PhalconPlus_Logger_Formatter_LinePlus, format);
PHP_METHOD(PhalconPlus_Logger_Formatter_LinePlus, addProcessor);
PHP_METHOD(PhalconPlus_Logger_Formatter_LinePlus, getProcessor);
PHP_METHOD(PhalconPlus_Logger_Formatter_LinePlus, __get);
zend_object_value zephir_init_properties_PhalconPlus_Logger_Formatter_LinePlus(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_formatter_lineplus___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, formatString)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_formatter_lineplus_format, 0, 0, 3)
	ZEND_ARG_INFO(0, message)
	ZEND_ARG_INFO(0, type)
	ZEND_ARG_INFO(0, timestamp)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_formatter_lineplus_addprocessor, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_OBJ_INFO(0, processor, PhalconPlus\\Logger\\Processor\\AbstractProcessor, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_formatter_lineplus_getprocessor, 0, 0, 1)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_formatter_lineplus___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_logger_formatter_lineplus_method_entry) {
	PHP_ME(PhalconPlus_Logger_Formatter_LinePlus, __construct, arginfo_phalconplus_logger_formatter_lineplus___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Logger_Formatter_LinePlus, format, arginfo_phalconplus_logger_formatter_lineplus_format, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Logger_Formatter_LinePlus, addProcessor, arginfo_phalconplus_logger_formatter_lineplus_addprocessor, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Logger_Formatter_LinePlus, getProcessor, arginfo_phalconplus_logger_formatter_lineplus_getprocessor, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Logger_Formatter_LinePlus, __get, arginfo_phalconplus_logger_formatter_lineplus___get, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
