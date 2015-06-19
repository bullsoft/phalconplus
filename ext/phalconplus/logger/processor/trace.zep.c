
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

	zval *skipClassesPartials = NULL, *_1;
	zval *mode_param = NULL, *skipClassesPartials_param = NULL, *_0, *_2 = NULL;
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


	if (EG(called_scope) == phalconplus_logger_processor_trace_ce) {
		zephir_init_properties(this_ptr TSRMLS_CC);
	}
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, mode);
	zephir_update_property_this(this_ptr, SL("mode"), _0 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(skipClassesPartials)) {
		ZEPHIR_INIT_VAR(_1);
		zephir_create_array(_1, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		ZVAL_STRING(_2, "PhalconPlus\\", 1);
		zephir_array_fast_append(_1, _2);
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "Phalcon\\", 1);
		zephir_array_fast_append(_1, _2);
		zephir_update_property_this(this_ptr, SL("skipClassesPartials"), _1 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Processor_Trace, __toString) {

	HashTable *_4;
	HashPosition _3;
	zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, i = 0, j, _16;
	zval *trace = NULL, *part = NULL, *_1, *_2, **_5, *_6, *_7, *_8 = NULL, *trace1 = NULL, *trace2 = NULL, *_9 = NULL, *_10, *_11, *_12, *_13, *_14, *_15, *_17;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(trace1);
	array_init(trace1);
	ZEPHIR_INIT_VAR(trace2);
	array_init(trace2);

	ZEPHIR_CALL_FUNCTION(&trace, "debug_backtrace", NULL, 51);
	zephir_check_call_status();
	Z_SET_ISREF_P(trace);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_0, 52, trace);
	Z_UNSET_ISREF_P(trace);
	zephir_check_call_status();
	Z_SET_ISREF_P(trace);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_0, 52, trace);
	Z_UNSET_ISREF_P(trace);
	zephir_check_call_status();
	CHECK:
	while (1) {
		zephir_array_fetch_long(&_1, trace, i, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 33 TSRMLS_CC);
		if (!(zephir_array_isset_string(_1, SS("class")))) {
			break;
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("skipClassesPartials"), PH_NOISY_CC);
		zephir_is_iterable(_2, &_4, &_3, 0, 0, "phalconplus/Logger/Processor/Trace.zep", 41);
		for (
		  ; zephir_hash_get_current_data_ex(_4, (void**) &_5, &_3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4, &_3)
		) {
			ZEPHIR_GET_HVALUE(part, _5);
			zephir_array_fetch_long(&_6, trace, i, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 36 TSRMLS_CC);
			zephir_array_fetch_string(&_7, _6, SL("class"), PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 36 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_8);
			zephir_fast_strpos(_8, _7, part, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(_8)) {
				i = (i + 1);
				goto CHECK;
			}
		}
		break;
	}
	j = (i - 1);
	ZEPHIR_INIT_NVAR(trace1);
	zephir_create_array(trace1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_9);
	zephir_array_fetch_long(&_6, trace, j, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 48 TSRMLS_CC);
	if (zephir_array_isset_string(_6, SS("file"))) {
		zephir_array_fetch_long(&_7, trace, j, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 48 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_9);
		zephir_array_fetch_string(&_9, _7, SL("file"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 48 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "Nil", 1);
	}
	zephir_array_update_string(&trace1, SL("file"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_9);
	zephir_array_fetch_long(&_10, trace, j, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 49 TSRMLS_CC);
	if (zephir_array_isset_string(_10, SS("line"))) {
		zephir_array_fetch_long(&_11, trace, j, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 49 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_9);
		zephir_array_fetch_string(&_9, _11, SL("line"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 49 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_LONG(_9, -1);
	}
	zephir_array_update_string(&trace1, SL("line"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(trace2);
	zephir_create_array(trace2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_9);
	zephir_array_fetch_long(&_12, trace, i, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 53 TSRMLS_CC);
	if (zephir_array_isset_string(_12, SS("class"))) {
		zephir_array_fetch_long(&_13, trace, i, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 53 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_9);
		zephir_array_fetch_string(&_9, _13, SL("class"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 53 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "Nil", 1);
	}
	zephir_array_update_string(&trace2, SL("class"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_9);
	zephir_array_fetch_long(&_14, trace, i, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 54 TSRMLS_CC);
	if (zephir_array_isset_string(_14, SS("function"))) {
		zephir_array_fetch_long(&_15, trace, i, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 54 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_9);
		zephir_array_fetch_string(&_9, _15, SL("function"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 54 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "Nil", 1);
	}
	zephir_array_update_string(&trace2, SL("function"), &_9, PH_COPY | PH_SEPARATE);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("mode"), PH_NOISY_CC);
	do {
		_16 = ((int) (zephir_get_numberval(_2)) & 0x0011);
		if (_16 == 0x0010) {
			zephir_fast_join_str(return_value, SL(":"), trace2 TSRMLS_CC);
			RETURN_MM();
		}
		if (_16 == 0x11) {
			ZEPHIR_INIT_NVAR(_8);
			zephir_fast_join_str(_8, SL(":"), trace1 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_17);
			zephir_fast_join_str(_17, SL(":"), trace2 TSRMLS_CC);
			ZEPHIR_CONCAT_VSV(return_value, _8, "][", _17);
			RETURN_MM();
		}
		zephir_fast_join_str(return_value, SL(":"), trace1 TSRMLS_CC);
		RETURN_MM();
	} while(0);

	ZEPHIR_MM_RESTORE();

}

static void zephir_init_properties(zval *this_ptr TSRMLS_DC) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("skipClassesPartials"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

