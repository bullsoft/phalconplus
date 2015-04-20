
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"

ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Processor_Trace) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Logger\\Processor, Trace, phalconplus, logger_processor_trace, phalconplus_logger_processor_abstractprocessor_ce, phalconplus_logger_processor_trace_method_entry, 0);

	zend_declare_property_null(phalconplus_logger_processor_trace_ce, SL("skipClassesPartials"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_long(phalconplus_logger_processor_trace_ce, SL("mode"), 0x0001, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_logger_processor_trace_ce, SL("T_FILE"), 0x0001 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_logger_processor_trace_ce, SL("T_CLASS"), 0x0010 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Logger_Processor_Trace, __construct) {

	zval *skipClassesPartials = NULL, *_2;
	zval *mode_param = NULL, *skipClassesPartials_param = NULL, *_0, *_1, *_3 = NULL;
	int mode;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &mode_param, &skipClassesPartials_param);

	if (!mode_param) {
		mode = 0x0001;
	} else {
		mode = zephir_get_intval(mode_param);
	}
	if (!skipClassesPartials_param) {
		ZEPHIR_INIT_VAR(skipClassesPartials);
		array_init(skipClassesPartials);
	} else {
		zephir_get_arrval(skipClassesPartials, skipClassesPartials_param);
	}


	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("skipClassesPartials"), _0 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(_1, mode);
	zephir_update_property_this(this_ptr, SL("mode"), _1 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(skipClassesPartials)) {
		ZEPHIR_INIT_VAR(_2);
		zephir_create_array(_2, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_STRING(_3, "PhalconPlus\\", 1);
		zephir_array_fast_append(_2, _3);
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "Phalcon\\", 1);
		zephir_array_fast_append(_2, _3);
		zephir_update_property_this(this_ptr, SL("skipClassesPartials"), _2 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Processor_Trace, __toString) {

	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS, i = 0, j, _17;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL;
	zval *trace = NULL, *part = NULL, *_2, *_3, **_6, *_7, *_8, *_9 = NULL, *trace1 = NULL, *trace2 = NULL, *_10 = NULL, *_11, *_12, *_13, *_14, *_15, *_16, *_18;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(trace1);
	array_init(trace1);
	ZEPHIR_INIT_VAR(trace2);
	array_init(trace2);

	ZEPHIR_CALL_FUNCTION(&trace, "debug_backtrace", &_0);
	zephir_check_call_status();
	Z_SET_ISREF_P(trace);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_1, trace);
	Z_UNSET_ISREF_P(trace);
	zephir_check_call_status();
	Z_SET_ISREF_P(trace);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_1, trace);
	Z_UNSET_ISREF_P(trace);
	zephir_check_call_status();
	CHECK:
	while (1) {
		zephir_array_fetch_long(&_2, trace, i, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 33 TSRMLS_CC);
		if (!(zephir_array_isset_string(_2, SS("class")))) {
			break;
		}
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("skipClassesPartials"), PH_NOISY_CC);
		zephir_is_iterable(_3, &_5, &_4, 0, 0, "phalconplus/Logger/Processor/Trace.zep", 41);
		for (
		  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5, &_4)
		) {
			ZEPHIR_GET_HVALUE(part, _6);
			zephir_array_fetch_long(&_7, trace, i, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 36 TSRMLS_CC);
			zephir_array_fetch_string(&_8, _7, SL("class"), PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 36 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_9);
			zephir_fast_strpos(_9, _8, part, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(_9)) {
				i = (i + 1);
				goto CHECK;
			}
		}
		break;
	}
	j = (i - 1);
	ZEPHIR_INIT_NVAR(trace1);
	zephir_create_array(trace1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_10);
	zephir_array_fetch_long(&_7, trace, j, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 48 TSRMLS_CC);
	if (zephir_array_isset_string(_7, SS("file"))) {
		zephir_array_fetch_long(&_8, trace, j, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 48 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_10);
		zephir_array_fetch_string(&_10, _8, SL("file"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 48 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "Nil", 1);
	}
	zephir_array_update_string(&trace1, SL("file"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_10);
	zephir_array_fetch_long(&_11, trace, j, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 49 TSRMLS_CC);
	if (zephir_array_isset_string(_11, SS("line"))) {
		zephir_array_fetch_long(&_12, trace, j, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 49 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_10);
		zephir_array_fetch_string(&_10, _12, SL("line"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 49 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_LONG(_10, -1);
	}
	zephir_array_update_string(&trace1, SL("line"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(trace2);
	zephir_create_array(trace2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_10);
	zephir_array_fetch_long(&_13, trace, i, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 53 TSRMLS_CC);
	if (zephir_array_isset_string(_13, SS("class"))) {
		zephir_array_fetch_long(&_14, trace, i, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 53 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_10);
		zephir_array_fetch_string(&_10, _14, SL("class"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 53 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "Nil", 1);
	}
	zephir_array_update_string(&trace2, SL("class"), &_10, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_10);
	zephir_array_fetch_long(&_15, trace, i, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 54 TSRMLS_CC);
	if (zephir_array_isset_string(_15, SS("function"))) {
		zephir_array_fetch_long(&_16, trace, i, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 54 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_10);
		zephir_array_fetch_string(&_10, _16, SL("function"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 54 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_10);
		ZVAL_STRING(_10, "Nil", 1);
	}
	zephir_array_update_string(&trace2, SL("function"), &_10, PH_COPY | PH_SEPARATE);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("mode"), PH_NOISY_CC);
	do {
		_17 = ((int) (zephir_get_numberval(_3)) & 0x0011);
		if (_17 == 0x0010) {
			zephir_fast_join_str(return_value, SL(":"), trace2 TSRMLS_CC);
			RETURN_MM();
		}
		if (_17 == 0x11) {
			ZEPHIR_INIT_NVAR(_9);
			zephir_fast_join_str(_9, SL(":"), trace1 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_18);
			zephir_fast_join_str(_18, SL(":"), trace2 TSRMLS_CC);
			ZEPHIR_CONCAT_VSV(return_value, _9, "][", _18);
			RETURN_MM();
		}
		zephir_fast_join_str(return_value, SL(":"), trace1 TSRMLS_CC);
		RETURN_MM();
	} while(0);

	ZEPHIR_MM_RESTORE();

}

