
extern zend_class_entry *phalconplus_logger_multiplefile_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Logger_MultiPleFile);

PHP_METHOD(PhalconPlus_Logger_MultiPleFile, getProcessors);
PHP_METHOD(PhalconPlus_Logger_MultiPleFile, __construct);
PHP_METHOD(PhalconPlus_Logger_MultiPleFile, addProcessor);
PHP_METHOD(PhalconPlus_Logger_MultiPleFile, getProcessorVar);
PHP_METHOD(PhalconPlus_Logger_MultiPleFile, __get);
PHP_METHOD(PhalconPlus_Logger_MultiPleFile, addMessage);
PHP_METHOD(PhalconPlus_Logger_MultiPleFile, setFormatter);
zend_object *zephir_init_properties_PhalconPlus_Logger_MultiPleFile(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_logger_multiplefile___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_logger_multiplefile_addprocessor, 0, 2, PhalconPlus\\Logger\\MultiPleFile, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_logger_multiplefile_addprocessor, 0, 2, IS_OBJECT, "PhalconPlus\\Logger\\MultiPleFile", 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_OBJ_INFO(0, processor, PhalconPlus\\Logger\\Processor\\AbstractProcessor, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_logger_multiplefile_getprocessorvar, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_logger_multiplefile_getprocessorvar, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_logger_multiplefile___get, 0, 1, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_logger_multiplefile___get, 0, 1, IS_STRING, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, property, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, property)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_logger_multiplefile_addmessage, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_logger_multiplefile_addmessage, 0, 2, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, level, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, level)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, message)
#endif
	ZEND_ARG_ARRAY_INFO(0, context, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_logger_multiplefile_setformatter, 0, 1, PhalconPlus\\Logger\\MultiPleFile, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_logger_multiplefile_setformatter, 0, 1, IS_OBJECT, "PhalconPlus\\Logger\\MultiPleFile", 0)
#endif
	ZEND_ARG_OBJ_INFO(0, formatter, Phalcon\\Logger\\Formatter\\FormatterInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_logger_multiplefile_method_entry) {
	PHP_ME(PhalconPlus_Logger_MultiPleFile, getProcessors, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Logger_MultiPleFile, __construct, arginfo_phalconplus_logger_multiplefile___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Logger_MultiPleFile, addProcessor, arginfo_phalconplus_logger_multiplefile_addprocessor, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Logger_MultiPleFile, getProcessorVar, arginfo_phalconplus_logger_multiplefile_getprocessorvar, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Logger_MultiPleFile, __get, arginfo_phalconplus_logger_multiplefile___get, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Logger_MultiPleFile, addMessage, arginfo_phalconplus_logger_multiplefile_addmessage, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Logger_MultiPleFile, setFormatter, arginfo_phalconplus_logger_multiplefile_setformatter, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
