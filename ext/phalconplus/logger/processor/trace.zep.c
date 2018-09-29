
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
	zephir_declare_class_constant_long(phalconplus_logger_processor_trace_ce, SL("T_FILE"), 0x0001);

	zephir_declare_class_constant_long(phalconplus_logger_processor_trace_ce, SL("T_CLASS"), 0x0010);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Logger_Processor_Trace, __construct) {

	zval skipClassesPartials, _1$$3;
	zval *mode_param = NULL, *skipClassesPartials_param = NULL, _0, _2$$3;
	zend_long mode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&skipClassesPartials);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &mode_param, &skipClassesPartials_param);

	if (!mode_param) {
		mode = 0x0001;
	} else {
		mode = zephir_get_intval(mode_param);
	}
	if (!skipClassesPartials_param) {
		ZEPHIR_INIT_VAR(&skipClassesPartials);
		array_init(&skipClassesPartials);
	} else {
		zephir_get_arrval(&skipClassesPartials, skipClassesPartials_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, mode);
	zephir_update_property_zval(this_ptr, SL("mode"), &_0);
	if (ZEPHIR_IS_EMPTY(&skipClassesPartials)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "PhalconPlus\\");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		ZEPHIR_INIT_NVAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "Phalcon\\");
		zephir_array_fast_append(&_1$$3, &_2$$3);
		zephir_update_property_zval(this_ptr, SL("skipClassesPartials"), &_1$$3);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Processor_Trace, __toString) {

	zval trace, part, _1, trace1, trace2, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _2$$3, *_3$$3, _4$$4, _5$$4, _6$$4, _18$$7, _19$$7;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i, j = 0, _17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&trace);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&trace1);
	ZVAL_UNDEF(&trace2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&trace, "debug_backtrace", NULL, 62);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&trace);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_0, 63, &trace);
	ZEPHIR_UNREF(&trace);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&trace);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_0, 63, &trace);
	ZEPHIR_UNREF(&trace);
	zephir_check_call_status();
	i = 0;
	CHECK:
	while (1) {
		zephir_array_fetch_long(&_1, &trace, i, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 33 TSRMLS_CC);
		if (!(zephir_array_isset_string(&_1, SL("class")))) {
			break;
		}
		zephir_read_property(&_2$$3, this_ptr, SL("skipClassesPartials"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_2$$3, 0, "phalconplus/Logger/Processor/Trace.zep", 41);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2$$3), _3$$3)
		{
			ZEPHIR_INIT_NVAR(&part);
			ZVAL_COPY(&part, _3$$3);
			zephir_array_fetch_long(&_4$$4, &trace, i, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 36 TSRMLS_CC);
			zephir_array_fetch_string(&_5$$4, &_4$$4, SL("class"), PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 36 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_6$$4);
			zephir_fast_strpos(&_6$$4, &_5$$4, &part, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&_6$$4)) {
				i = (i + 1);
				goto CHECK;
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&part);
		break;
	}
	ZEPHIR_INIT_VAR(&trace1);
	array_init(&trace1);
	ZEPHIR_INIT_VAR(&trace2);
	array_init(&trace2);
	j = (i - 1);
	ZEPHIR_INIT_NVAR(&trace1);
	zephir_create_array(&trace1, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_7);
	zephir_array_fetch_long(&_8, &trace, j, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 48 TSRMLS_CC);
	if (zephir_array_isset_string(&_8, SL("file"))) {
		zephir_array_fetch_long(&_9, &trace, j, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 48 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&_7);
		zephir_array_fetch_string(&_7, &_9, SL("file"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 48 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_STRING(&_7, "Nil");
	}
	zephir_array_update_string(&trace1, SL("file"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_7);
	zephir_array_fetch_long(&_10, &trace, j, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 49 TSRMLS_CC);
	if (zephir_array_isset_string(&_10, SL("line"))) {
		zephir_array_fetch_long(&_11, &trace, j, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 49 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&_7);
		zephir_array_fetch_string(&_7, &_11, SL("line"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 49 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_LONG(&_7, -1);
	}
	zephir_array_update_string(&trace1, SL("line"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&trace2);
	zephir_create_array(&trace2, 2, 0 TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_7);
	zephir_array_fetch_long(&_12, &trace, i, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 53 TSRMLS_CC);
	if (zephir_array_isset_string(&_12, SL("class"))) {
		zephir_array_fetch_long(&_13, &trace, i, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 53 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&_7);
		zephir_array_fetch_string(&_7, &_13, SL("class"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 53 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_STRING(&_7, "Nil");
	}
	zephir_array_update_string(&trace2, SL("class"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_LNVAR(_7);
	zephir_array_fetch_long(&_14, &trace, i, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 54 TSRMLS_CC);
	if (zephir_array_isset_string(&_14, SL("function"))) {
		zephir_array_fetch_long(&_15, &trace, i, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 54 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&_7);
		zephir_array_fetch_string(&_7, &_15, SL("function"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 54 TSRMLS_CC);
	} else {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_STRING(&_7, "Nil");
	}
	zephir_array_update_string(&trace2, SL("function"), &_7, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_16, this_ptr, SL("mode"), PH_NOISY_CC | PH_READONLY);
	do {
		_17 = ((int) (zephir_get_numberval(&_16)) & 0x0011);
		if (_17 == 0x0010) {
			zephir_fast_join_str(return_value, SL(":"), &trace2 TSRMLS_CC);
			RETURN_MM();
		}
		if (_17 == 0x11) {
			ZEPHIR_INIT_VAR(&_18$$7);
			zephir_fast_join_str(&_18$$7, SL(":"), &trace1 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_19$$7);
			zephir_fast_join_str(&_19$$7, SL(":"), &trace2 TSRMLS_CC);
			ZEPHIR_CONCAT_VSV(return_value, &_18$$7, "][", &_19$$7);
			RETURN_MM();
		}
		zephir_fast_join_str(return_value, SL(":"), &trace1 TSRMLS_CC);
		RETURN_MM();
	} while(0);

	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_PhalconPlus_Logger_Processor_Trace(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("skipClassesPartials"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("skipClassesPartials"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

