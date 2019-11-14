
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

	zend_declare_property_null(phalconplus_logger_processor_trace_ce, SL("skipClassesPartials"), ZEND_ACC_PRIVATE);

	zend_declare_property_long(phalconplus_logger_processor_trace_ce, SL("mode"), 0x0001, ZEND_ACC_PRIVATE);

	phalconplus_logger_processor_trace_ce->create_object = zephir_init_properties_PhalconPlus_Logger_Processor_Trace;
	zephir_declare_class_constant_long(phalconplus_logger_processor_trace_ce, SL("T_FILE"), 0x0001);

	zephir_declare_class_constant_long(phalconplus_logger_processor_trace_ce, SL("T_CLASS"), 0x0010);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Logger_Processor_Trace, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
		zephir_create_array(&_1$$3, 2, 0);
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

	zval trace, part, _1, trace1, trace2, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, _2$$3, *_3$$3, _4$$3, _5$$4, _6$$4, _7$$4, _8$$6, _9$$6, _10$$6, _24$$9, _25$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i, j = 0, _23;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&trace);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&trace1);
	ZVAL_UNDEF(&trace2);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$9);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(&trace, "debug_backtrace", NULL, 117);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&trace);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_0, 94, &trace);
	ZEPHIR_UNREF(&trace);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&trace);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_0, 94, &trace);
	ZEPHIR_UNREF(&trace);
	zephir_check_call_status();
	i = 0;
	CHECK:
	while (1) {
		zephir_array_fetch_long(&_1, &trace, i, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 33);
		if (!(zephir_array_isset_string(&_1, SL("class")))) {
			break;
		}
		zephir_read_property(&_2$$3, this_ptr, SL("skipClassesPartials"), PH_NOISY_CC | PH_READONLY);
		zephir_is_iterable(&_2$$3, 0, "phalconplus/Logger/Processor/Trace.zep", 41);
		if (Z_TYPE_P(&_2$$3) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_2$$3), _3$$3)
			{
				ZEPHIR_INIT_NVAR(&part);
				ZVAL_COPY(&part, _3$$3);
				zephir_array_fetch_long(&_5$$4, &trace, i, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 36);
				zephir_array_fetch_string(&_6$$4, &_5$$4, SL("class"), PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 36);
				ZEPHIR_INIT_NVAR(&_7$$4);
				zephir_fast_strpos(&_7$$4, &_6$$4, &part, 0 );
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&_7$$4)) {
					i = (i + 1);
					goto CHECK;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &_2$$3, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$3, &_2$$3, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&part, &_2$$3, "current", NULL, 0);
				zephir_check_call_status();
					zephir_array_fetch_long(&_8$$6, &trace, i, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 36);
					zephir_array_fetch_string(&_9$$6, &_8$$6, SL("class"), PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 36);
					ZEPHIR_INIT_NVAR(&_10$$6);
					zephir_fast_strpos(&_10$$6, &_9$$6, &part, 0 );
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&_10$$6)) {
						i = (i + 1);
						goto CHECK;
					}
				ZEPHIR_CALL_METHOD(NULL, &_2$$3, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&part);
		break;
	}
	ZEPHIR_INIT_VAR(&trace1);
	array_init(&trace1);
	ZEPHIR_INIT_VAR(&trace2);
	array_init(&trace2);
	j = (i - 1);
	ZEPHIR_INIT_VAR(&_11);
	zephir_create_array(&_11, 2, 0);
	ZEPHIR_INIT_VAR(&_12);
	zephir_array_fetch_long(&_13, &trace, j, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 48);
	if (zephir_array_isset_string(&_13, SL("file"))) {
		zephir_array_fetch_long(&_14, &trace, j, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 48);
		ZEPHIR_OBS_NVAR(&_12);
		zephir_array_fetch_string(&_12, &_14, SL("file"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 48);
	} else {
		ZEPHIR_INIT_NVAR(&_12);
		ZVAL_STRING(&_12, "Nil");
	}
	zephir_array_update_string(&_11, SL("file"), &_12, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_12);
	zephir_array_fetch_long(&_15, &trace, j, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 49);
	if (zephir_array_isset_string(&_15, SL("line"))) {
		zephir_array_fetch_long(&_16, &trace, j, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 49);
		ZEPHIR_OBS_NVAR(&_12);
		zephir_array_fetch_string(&_12, &_16, SL("line"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 49);
	} else {
		ZEPHIR_INIT_NVAR(&_12);
		ZVAL_LONG(&_12, -1);
	}
	zephir_array_update_string(&_11, SL("line"), &_12, PH_COPY | PH_SEPARATE);
	ZEPHIR_CPY_WRT(&trace1, &_11);
	ZEPHIR_INIT_VAR(&_17);
	zephir_create_array(&_17, 2, 0);
	ZEPHIR_INIT_NVAR(&_12);
	zephir_array_fetch_long(&_18, &trace, i, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 53);
	if (zephir_array_isset_string(&_18, SL("class"))) {
		zephir_array_fetch_long(&_19, &trace, i, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 53);
		ZEPHIR_OBS_NVAR(&_12);
		zephir_array_fetch_string(&_12, &_19, SL("class"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 53);
	} else {
		ZEPHIR_INIT_NVAR(&_12);
		ZVAL_STRING(&_12, "Nil");
	}
	zephir_array_update_string(&_17, SL("class"), &_12, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_12);
	zephir_array_fetch_long(&_20, &trace, i, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 54);
	if (zephir_array_isset_string(&_20, SL("function"))) {
		zephir_array_fetch_long(&_21, &trace, i, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 54);
		ZEPHIR_OBS_NVAR(&_12);
		zephir_array_fetch_string(&_12, &_21, SL("function"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 54);
	} else {
		ZEPHIR_INIT_NVAR(&_12);
		ZVAL_STRING(&_12, "Nil");
	}
	zephir_array_update_string(&_17, SL("function"), &_12, PH_COPY | PH_SEPARATE);
	ZEPHIR_CPY_WRT(&trace2, &_17);
	zephir_read_property(&_22, this_ptr, SL("mode"), PH_NOISY_CC | PH_READONLY);
	do {
		_23 = ((int) (zephir_get_numberval(&_22)) & 0x0011);
		if (_23 == 0x0010) {
			zephir_fast_join_str(return_value, SL(":"), &trace2);
			RETURN_MM();
		}
		if (_23 == 0x11) {
			ZEPHIR_INIT_VAR(&_24$$9);
			zephir_fast_join_str(&_24$$9, SL(":"), &trace1);
			ZEPHIR_INIT_VAR(&_25$$9);
			zephir_fast_join_str(&_25$$9, SL(":"), &trace2);
			ZEPHIR_CONCAT_VSV(return_value, &_24$$9, "][", &_25$$9);
			RETURN_MM();
		}
		zephir_fast_join_str(return_value, SL(":"), &trace1);
		RETURN_MM();
	} while(0);

	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_PhalconPlus_Logger_Processor_Trace(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

