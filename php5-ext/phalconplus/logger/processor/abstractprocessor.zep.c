
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Processor_AbstractProcessor) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Logger\\Processor, AbstractProcessor, phalconplus, logger_processor_abstractprocessor, phalconplus_logger_processor_abstractprocessor_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Logger_Processor_AbstractProcessor, __toString) {

}

