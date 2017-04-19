
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
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Processor_Trace) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Logger\\Processor, Trace, phalconplus, logger_processor_trace, phalconplus_logger_processor_abstractprocessor_ce, phalconplus_logger_processor_trace_method_entry, 0);

	zend_declare_property_null(phalconplus_logger_processor_trace_ce, SL("skipClassesPartials"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_long(phalconplus_logger_processor_trace_ce, SL("mode"), 0x0001, ZEND_ACC_PRIVATE TSRMLS_CC);

	phalconplus_logger_processor_trace_ce->create_object = zephir_init_properties_PhalconPlus_Logger_Processor_Trace;
	zend_declare_class_constant_long(phalconplus_logger_processor_trace_ce, SL("T_FILE"), 0x0001 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_logger_processor_trace_ce, SL("T_CLASS"), 0x0010 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Logger_Processor_Trace, __construct) {

	zval *skipClassesPartials = NULL, *_1$$3;
	zval *mode_param = NULL, *skipClassesPartials_param = NULL, *_0, *_2$$3 = NULL;
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


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(_0, mode);
	zephir_update_property_this(this_ptr, SL("mode"), _0 TSRMLS_CC);
	if (ZEPHIR_IS_EMPTY(skipClassesPartials)) {
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_array(_1$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_STRING(_2$$3, "PhalconPlus\\", 1);
		zephir_array_fast_append(_1$$3, _2$$3);
		ZEPHIR_INIT_NVAR(_2$$3);
		ZVAL_STRING(_2$$3, "Phalcon\\", 1);
		zephir_array_fast_append(_1$$3, _2$$3);
		zephir_update_property_this(this_ptr, SL("skipClassesPartials"), _1$$3 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Processor_Trace, __toString) {

	HashTable *_4$$3;
	HashPosition _3$$3;
	zval *trace = NULL, *part = NULL, *_1, *trace1 = NULL, *trace2 = NULL, *_9 = NULL, *_10, *_11, *_12, *_13, *_14, *_15, *_16, *_17, *_18, *_2$$3, **_5$$3, *_6$$4, *_7$$4, *_8$$4 = NULL, *_20$$7, *_21$$7;
	zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS, i, j = 0, _19;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&trace, "debug_backtrace", NULL, 57);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(trace);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_0, 58, trace);
	ZEPHIR_UNREF(trace);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(trace);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_0, 58, trace);
	ZEPHIR_UNREF(trace);
	zephir_check_call_status();
	i = 0;
	CHECK:
	while (1) {
		zephir_array_fetch_long(&_1, trace, i, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 33 TSRMLS_CC);
		if (!(zephir_array_isset_string(_1, SS("class")))) {
			break;
		}
		_2$$3 = zephir_fetch_nproperty_this(this_ptr, SL("skipClassesPartials"), PH_NOISY_CC);
		zephir_is_iterable(_2$$3, &_4$$3, &_3$$3, 0, 0, "phalconplus/Logger/Processor/Trace.zep", 41);
		for (
		  ; zend_hash_get_current_data_ex(_4$$3, (void**) &_5$$3, &_3$$3) == SUCCESS
		  ; zend_hash_move_forward_ex(_4$$3, &_3$$3)
		) {
			ZEPHIR_GET_HVALUE(part, _5$$3);
			zephir_array_fetch_long(&_6$$4, trace, i, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 36 TSRMLS_CC);
			zephir_array_fetch_string(&_7$$4, _6$$4, SL("class"), PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 36 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_8$$4);
			zephir_fast_strpos(_8$$4, _7$$4, part, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(_8$$4)) {
				i = (i + 1);
				goto CHECK;
			}
		}
		break;
	}
	ZEPHIR_INIT_VAR(trace1);
	array_init(trace1);
	ZEPHIR_INIT_VAR(trace2);
	array_init(trace2);
	j = (i - 1);
	ZEPHIR_INIT_NVAR(trace1);
	zephir_create_array(trace1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_9);
	zephir_array_fetch_long(&_10, trace, j, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 48 TSRMLS_CC);
	if (zephir_array_isset_string(_10, SS("file"))) {
		zephir_array_fetch_long(&_11, trace, j, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 48 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_9);
		zephir_array_fetch_string(&_9, _11, SL("file"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 48 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "Nil", 1);
	}
	zephir_array_update_string(&trace1, SL("file"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_9);
	zephir_array_fetch_long(&_12, trace, j, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 49 TSRMLS_CC);
	if (zephir_array_isset_string(_12, SS("line"))) {
		zephir_array_fetch_long(&_13, trace, j, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 49 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_9);
		zephir_array_fetch_string(&_9, _13, SL("line"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 49 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_LONG(_9, -1);
	}
	zephir_array_update_string(&trace1, SL("line"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(trace2);
	zephir_create_array(trace2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_9);
	zephir_array_fetch_long(&_14, trace, i, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 53 TSRMLS_CC);
	if (zephir_array_isset_string(_14, SS("class"))) {
		zephir_array_fetch_long(&_15, trace, i, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 53 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_9);
		zephir_array_fetch_string(&_9, _15, SL("class"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 53 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "Nil", 1);
	}
	zephir_array_update_string(&trace2, SL("class"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_9);
	zephir_array_fetch_long(&_16, trace, i, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 54 TSRMLS_CC);
	if (zephir_array_isset_string(_16, SS("function"))) {
		zephir_array_fetch_long(&_17, trace, i, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 54 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_9);
		zephir_array_fetch_string(&_9, _17, SL("function"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 54 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "Nil", 1);
	}
	zephir_array_update_string(&trace2, SL("function"), &_9, PH_COPY | PH_SEPARATE);
	_18 = zephir_fetch_nproperty_this(this_ptr, SL("mode"), PH_NOISY_CC);
	do {
		_19 = ((int) (zephir_get_numberval(_18)) & 0x0011);
		if (_19 == 0x0010) {
			zephir_fast_join_str(return_value, SL(":"), trace2 TSRMLS_CC);
			RETURN_MM();
		}
		if (_19 == 0x11) {
			ZEPHIR_INIT_VAR(_20$$7);
			zephir_fast_join_str(_20$$7, SL(":"), trace1 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_21$$7);
			zephir_fast_join_str(_21$$7, SL(":"), trace2 TSRMLS_CC);
			ZEPHIR_CONCAT_VSV(return_value, _20$$7, "][", _21$$7);
			RETURN_MM();
		}
		zephir_fast_join_str(return_value, SL(":"), trace1 TSRMLS_CC);
		RETURN_MM();
	} while(0);

	ZEPHIR_MM_RESTORE();

}

zend_object_value zephir_init_properties_PhalconPlus_Logger_Processor_Trace(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("skipClassesPartials"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("skipClassesPartials"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

