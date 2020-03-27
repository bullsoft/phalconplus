
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

	zend_declare_property_long(phalconplus_logger_processor_trace_ce, SL("limit"), 15, ZEND_ACC_PRIVATE);

	phalconplus_logger_processor_trace_ce->create_object = zephir_init_properties_PhalconPlus_Logger_Processor_Trace;
	zephir_declare_class_constant_long(phalconplus_logger_processor_trace_ce, SL("T_FILE"), 0x0001);

	zephir_declare_class_constant_long(phalconplus_logger_processor_trace_ce, SL("T_CLASS"), 0x0010);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Logger_Processor_Trace, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval skipClassesPartials, _1$$4;
	zval *mode_param = NULL, *skipClassesPartials_param = NULL, _0, _2$$4;
	zend_long mode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&skipClassesPartials);
	ZVAL_UNDEF(&_1$$4);

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
	if (!(ZEPHIR_IS_EMPTY(&skipClassesPartials))) {
		zephir_update_property_zval(this_ptr, SL("skipClassesPartials"), &skipClassesPartials);
	} else {
		ZEPHIR_INIT_VAR(&_1$$4);
		zephir_create_array(&_1$$4, 4, 0);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "PhalconPlus\\Logger\\");
		zephir_array_fast_append(&_1$$4, &_2$$4);
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "PhalconPlus\\Facades\\");
		zephir_array_fast_append(&_1$$4, &_2$$4);
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "Phalcon\\");
		zephir_array_fast_append(&_1$$4, &_2$$4);
		ZEPHIR_INIT_NVAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "Exception");
		zephir_array_fast_append(&_1$$4, &_2$$4);
		zephir_update_property_zval(this_ptr, SL("skipClassesPartials"), &_1$$4);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Processor_Trace, setLimit) {

	zval *limit_param = NULL, _0;
	zend_long limit;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(0, 1, &limit_param);

	if (!limit_param) {
		limit = 15;
	} else {
		limit = zephir_get_intval(limit_param);
	}


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, limit);
	zephir_update_property_zval(this_ptr, SL("limit"), &_0);

}

PHP_METHOD(PhalconPlus_Logger_Processor_Trace, __toString) {

	zend_bool _4$$3;
	zval trace, _0, _1, j, part, k, trace1, trace2, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _22, tmp$$3, _3$$3, _5$$4, *_6$$4, _7$$4, _8$$5, _9$$5, _10$$7, _11$$7, _24$$10, _25$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, i, _23;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&trace);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&j);
	ZVAL_UNDEF(&part);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&trace1);
	ZVAL_UNDEF(&trace2);
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
	ZVAL_UNDEF(&tmp$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_25$$10);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("limit"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_FUNCTION(&trace, "debug_backtrace", NULL, 133, &_1, &_0);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&trace);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_2, 105, &trace);
	ZEPHIR_UNREF(&trace);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&trace);
	ZEPHIR_CALL_FUNCTION(NULL, "array_shift", &_2, 105, &trace);
	ZEPHIR_UNREF(&trace);
	zephir_check_call_status();
	i = 0;
	ZEPHIR_INIT_VAR(&j);
	ZVAL_LONG(&j, i);
	CHECK:
	while (1) {
		if (!(zephir_array_isset_long(&trace, i))) {
			break;
		}
		ZEPHIR_OBS_NVAR(&tmp$$3);
		zephir_array_fetch_long(&tmp$$3, &trace, i, PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 44);
		zephir_array_fetch_long(&_3$$3, &trace, i, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 47);
		_4$$3 = zephir_array_isset_string(&_3$$3, SL("class"));
		if (_4$$3) {
			_4$$3 = ZEPHIR_IS_LONG(&j, i);
		}
		if (_4$$3) {
			zephir_read_property(&_5$$4, this_ptr, SL("skipClassesPartials"), PH_NOISY_CC | PH_READONLY);
			zephir_is_iterable(&_5$$4, 0, "phalconplus/Logger/Processor/Trace.zep", 56);
			if (Z_TYPE_P(&_5$$4) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_5$$4), _6$$4)
				{
					ZEPHIR_INIT_NVAR(&part);
					ZVAL_COPY(&part, _6$$4);
					zephir_array_fetch_string(&_8$$5, &tmp$$3, SL("class"), PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 50);
					ZEPHIR_INIT_NVAR(&_9$$5);
					zephir_fast_strpos(&_9$$5, &_8$$5, &part, 0 );
					if (!ZEPHIR_IS_FALSE_IDENTICAL(&_9$$5)) {
						i = (i + 1);
						ZEPHIR_INIT_NVAR(&j);
						ZVAL_LONG(&j, i);
						goto CHECK;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_5$$4, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_7$$4, &_5$$4, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_7$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&part, &_5$$4, "current", NULL, 0);
					zephir_check_call_status();
						zephir_array_fetch_string(&_10$$7, &tmp$$3, SL("class"), PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 50);
						ZEPHIR_INIT_NVAR(&_11$$7);
						zephir_fast_strpos(&_11$$7, &_10$$7, &part, 0 );
						if (!ZEPHIR_IS_FALSE_IDENTICAL(&_11$$7)) {
							i = (i + 1);
							ZEPHIR_INIT_NVAR(&j);
							ZVAL_LONG(&j, i);
							goto CHECK;
						}
					ZEPHIR_CALL_METHOD(NULL, &_5$$4, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&part);
		}
		break;
	}
	ZEPHIR_INIT_VAR(&trace1);
	array_init(&trace1);
	ZEPHIR_INIT_VAR(&trace2);
	array_init(&trace2);
	ZEPHIR_INIT_VAR(&k);
	ZVAL_LONG(&k, (zephir_get_numberval(&j) - 1));
	ZEPHIR_INIT_VAR(&_12);
	zephir_create_array(&_12, 2, 0);
	ZEPHIR_INIT_VAR(&_13);
	zephir_array_fetch(&_14, &trace, &k, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 65);
	if (zephir_array_isset_string(&_14, SL("file"))) {
		zephir_array_fetch(&_15, &trace, &k, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 65);
		ZEPHIR_OBS_NVAR(&_13);
		zephir_array_fetch_string(&_13, &_15, SL("file"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 65);
	} else {
		ZEPHIR_INIT_NVAR(&_13);
		ZVAL_STRING(&_13, "Nil");
	}
	zephir_array_update_string(&_12, SL("file"), &_13, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_13);
	zephir_array_fetch(&_16, &trace, &k, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 66);
	if (zephir_array_isset_string(&_16, SL("line"))) {
		zephir_array_fetch(&_17, &trace, &k, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 66);
		ZEPHIR_OBS_NVAR(&_13);
		zephir_array_fetch_string(&_13, &_17, SL("line"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 66);
	} else {
		ZEPHIR_INIT_NVAR(&_13);
		ZVAL_LONG(&_13, -1);
	}
	zephir_array_update_string(&_12, SL("line"), &_13, PH_COPY | PH_SEPARATE);
	ZEPHIR_CPY_WRT(&trace1, &_12);
	ZEPHIR_INIT_VAR(&_18);
	zephir_create_array(&_18, 2, 0);
	ZEPHIR_INIT_NVAR(&_13);
	zephir_array_fetch(&_19, &trace, &j, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 70);
	if (zephir_array_isset_string(&_19, SL("class"))) {
		zephir_array_fetch(&_20, &trace, &j, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 70);
		ZEPHIR_OBS_NVAR(&_13);
		zephir_array_fetch_string(&_13, &_20, SL("class"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 70);
	} else {
		ZEPHIR_INIT_NVAR(&_13);
		ZVAL_STRING(&_13, "Nil");
	}
	zephir_array_update_string(&_18, SL("class"), &_13, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_13);
	zephir_array_fetch(&_21, &trace, &j, PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 71);
	if (zephir_array_isset_string(&_21, SL("function"))) {
		zephir_array_fetch(&_22, &trace, &j, PH_NOISY | PH_READONLY, "phalconplus/Logger/Processor/Trace.zep", 71);
		ZEPHIR_OBS_NVAR(&_13);
		zephir_array_fetch_string(&_13, &_22, SL("function"), PH_NOISY, "phalconplus/Logger/Processor/Trace.zep", 71);
	} else {
		ZEPHIR_INIT_NVAR(&_13);
		ZVAL_STRING(&_13, "Nil");
	}
	zephir_array_update_string(&_18, SL("function"), &_13, PH_COPY | PH_SEPARATE);
	ZEPHIR_CPY_WRT(&trace2, &_18);
	zephir_read_property(&_1, this_ptr, SL("mode"), PH_NOISY_CC | PH_READONLY);
	do {
		_23 = ((int) (zephir_get_numberval(&_1)) & 0x0011);
		if (_23 == 0x0010) {
			zephir_fast_join_str(return_value, SL(":"), &trace2);
			RETURN_MM();
		}
		if (_23 == 0x11) {
			ZEPHIR_INIT_VAR(&_24$$10);
			zephir_fast_join_str(&_24$$10, SL(":"), &trace1);
			ZEPHIR_INIT_VAR(&_25$$10);
			zephir_fast_join_str(&_25$$10, SL(":"), &trace2);
			ZEPHIR_CONCAT_VSV(return_value, &_24$$10, "][", &_25$$10);
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

