
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Processor_LogId) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Logger\\Processor, LogId, phalconplus, logger_processor_logid, phalconplus_logger_processor_abstractprocessor_ce, phalconplus_logger_processor_logid_method_entry, 0);

	zend_declare_property_string(phalconplus_logger_processor_logid_ce, SL("id"), "", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Logger_Processor_LogId, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *len = NULL, len_sub, __$true, _0, _1$$5, _2$$5, _3$$5, _4$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&len_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &len);

	if (!len) {
		len = &len_sub;
		ZEPHIR_INIT_VAR(len);
		ZVAL_LONG(len, 18);
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, phalconplus_logger_processor_logid_ce, SL("id"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		if (zephir_fast_strlen_ev(len) > 2) {
			zephir_update_static_property_ce(phalconplus_logger_processor_logid_ce, ZEND_STRL("id"), len);
		} else {
			ZEPHIR_INIT_VAR(&_1$$5);
			ZVAL_STRING(&_1$$5, "");
			ZEPHIR_CALL_FUNCTION(&_2$$5, "uniqid", NULL, 120, &_1$$5, &__$true);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_1$$5);
			ZVAL_STRING(&_1$$5, "md5");
			ZEPHIR_CALL_FUNCTION(&_3$$5, "hash", NULL, 121, &_1$$5, &_2$$5);
			zephir_check_call_status();
			ZVAL_LONG(&_4$$5, 0);
			ZEPHIR_INIT_NVAR(&_1$$5);
			zephir_substr(&_1$$5, &_3$$5, 0 , zephir_get_intval(len), 0);
			zephir_update_static_property_ce(phalconplus_logger_processor_logid_ce, ZEND_STRL("id"), &_1$$5);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Processor_LogId, setId) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *logId_param = NULL;
	zval logId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&logId);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &logId_param);

	if (UNEXPECTED(Z_TYPE_P(logId_param) != IS_STRING && Z_TYPE_P(logId_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'logId' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(logId_param) == IS_STRING)) {
		zephir_get_strval(&logId, logId_param);
	} else {
		ZEPHIR_INIT_VAR(&logId);
		ZVAL_EMPTY_STRING(&logId);
	}


	zephir_update_static_property_ce(phalconplus_logger_processor_logid_ce, ZEND_STRL("id"), &logId);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Processor_LogId, getId) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_static_property_ce(&_0, phalconplus_logger_processor_logid_ce, SL("id"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);

}

PHP_METHOD(PhalconPlus_Logger_Processor_LogId, __toString) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_static_property_ce(&_0, phalconplus_logger_processor_logid_ce, SL("id"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);

}

