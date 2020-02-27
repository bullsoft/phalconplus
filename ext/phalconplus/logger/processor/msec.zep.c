
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/time.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Processor_Msec) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Logger\\Processor, Msec, phalconplus, logger_processor_msec, phalconplus_logger_processor_abstractprocessor_ce, phalconplus_logger_processor_msec_method_entry, 0);

	zend_declare_property_null(phalconplus_logger_processor_msec_ce, SL("msec"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Logger_Processor_Msec, __construct) {

	zval *this_ptr = getThis();



}

PHP_METHOD(PhalconPlus_Logger_Processor_Msec, __toString) {

	zval tmp, _0, _1, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_microtime(&_0, NULL);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "%f %d");
	ZEPHIR_CALL_FUNCTION(&tmp, "sscanf", NULL, 121, &_0, &_1);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &tmp, 0, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Msec.zep", 15);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "%03d");
	ZVAL_LONG(&_3, (zephir_get_numberval(&_2) * 1000));
	ZEPHIR_CALL_FUNCTION(&_4, "sprintf", NULL, 6, &_1, &_3);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("msec"), &_4);
	RETURN_MM_MEMBER(getThis(), "msec");

}

