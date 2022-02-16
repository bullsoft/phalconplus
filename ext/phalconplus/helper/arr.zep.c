
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Helper_Arr)
{
	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Helper, Arr, phalconplus, helper_arr, phalconplus_helper_arr_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Helper_Arr, isAllKeyInt)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *inputArray, inputArray_sub, __$true, input, _1, _2, _3, expected;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputArray_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&expected);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(inputArray)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &inputArray);


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "isarray", &_0, 0, inputArray);
	zephir_check_call_status();
	if (zephir_fast_count_int(inputArray) <= 0) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_array_keys(&_1, inputArray);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "is_int");
	ZEPHIR_CALL_FUNCTION(&_3, "array_map", NULL, 64, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&input, "array_unique", NULL, 126, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&expected);
	zephir_create_array(&expected, 1, 0);
	zephir_array_fast_append(&expected, &__$true);
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&input, &expected));
}

PHP_METHOD(PhalconPlus_Helper_Arr, isAllKeyString)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *inputArray, inputArray_sub, __$true, input, _1, _2, _3, expected;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputArray_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&expected);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(inputArray)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &inputArray);


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "isarray", &_0, 0, inputArray);
	zephir_check_call_status();
	if (zephir_fast_count_int(inputArray) <= 0) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_array_keys(&_1, inputArray);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "is_string");
	ZEPHIR_CALL_FUNCTION(&_3, "array_map", NULL, 64, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&input, "array_unique", NULL, 126, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&expected);
	zephir_create_array(&expected, 1, 0);
	zephir_array_fast_append(&expected, &__$true);
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&input, &expected));
}

PHP_METHOD(PhalconPlus_Helper_Arr, isKeyNumericSequentialZeroBased)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *inputArray, inputArray_sub, input, expected, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputArray_sub);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&expected);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(inputArray)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &inputArray);


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "isarray", &_0, 0, inputArray);
	zephir_check_call_status();
	if (zephir_fast_count_int(inputArray) <= 0) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_VAR(&input);
	zephir_array_keys(&input, inputArray);
	ZVAL_LONG(&_1, 0);
	ZVAL_LONG(&_2, (zephir_fast_count_int(inputArray) - 1));
	ZEPHIR_CALL_FUNCTION(&expected, "range", NULL, 127, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&input, &expected));
}

PHP_METHOD(PhalconPlus_Helper_Arr, newProtoBuffer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *inputArray, inputArray_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputArray_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(inputArray)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &inputArray);


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "isarray", &_0, 0, inputArray);
	zephir_check_call_status();
	object_init_ex(return_value, phalconplus_base_protobuffer_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 76, inputArray);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(PhalconPlus_Helper_Arr, encodeJson)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *inputArray, inputArray_sub, str, _1, errCode, _2$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputArray_sub);
	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&errCode);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(inputArray)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &inputArray);


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "isarray", &_0, 0, inputArray);
	zephir_check_call_status();
	ZVAL_LONG(&_1, 256);
	ZEPHIR_INIT_VAR(&str);
	zephir_json_encode(&str, inputArray, zephir_get_intval(&_1) );
	ZEPHIR_CALL_FUNCTION(&errCode, "json_last_error", NULL, 66);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG(&errCode, 0)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalconplus_helper_exception_ce);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "json_last_error_msg", NULL, 128);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 2, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalconplus/Helper/Arr.zep", 52);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&str);
}

PHP_METHOD(PhalconPlus_Helper_Arr, firstKey)
{
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *inputArray, inputArray_sub, k, v, *_1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputArray_sub);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(inputArray)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &inputArray);


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "isarray", &_0, 0, inputArray);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(inputArray);
	ZEPHIR_CALL_FUNCTION(NULL, "reset", NULL, 70, inputArray);
	ZEPHIR_UNREF(inputArray);
	zephir_check_call_status();
	zephir_is_iterable(inputArray, 0, "phalconplus/Helper/Arr.zep", 64);
	if (Z_TYPE_P(inputArray) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(inputArray), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&k, _4);
			} else {
				ZVAL_LONG(&k, _3);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _1);
			RETURN_CCTOR(&k);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, inputArray, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, inputArray, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&k, inputArray, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&v, inputArray, "current", NULL, 0);
			zephir_check_call_status();
				RETURN_CCTOR(&k);
			ZEPHIR_CALL_METHOD(NULL, inputArray, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
}

PHP_METHOD(PhalconPlus_Helper_Arr, lastKey)
{
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *inputArray, inputArray_sub, k, v, *_1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputArray_sub);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(inputArray)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &inputArray);


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "isarray", &_0, 0, inputArray);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(inputArray);
	ZEPHIR_CALL_FUNCTION(NULL, "reset", NULL, 70, inputArray);
	ZEPHIR_UNREF(inputArray);
	zephir_check_call_status();
	zephir_is_iterable(inputArray, 0, "phalconplus/Helper/Arr.zep", 74);
	if (Z_TYPE_P(inputArray) == IS_ARRAY) {
		ZEND_HASH_REVERSE_FOREACH_KEY_VAL(Z_ARRVAL_P(inputArray), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&k, _4);
			} else {
				ZVAL_LONG(&k, _3);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _1);
			RETURN_CCTOR(&k);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, inputArray, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, inputArray, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&k, inputArray, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&v, inputArray, "current", NULL, 0);
			zephir_check_call_status();
				RETURN_CCTOR(&k);
			ZEPHIR_CALL_METHOD(NULL, inputArray, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
}

PHP_METHOD(PhalconPlus_Helper_Arr, first)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *inputArray, inputArray_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputArray_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(inputArray)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &inputArray);


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "isarray", &_0, 0, inputArray);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(inputArray);
	ZEPHIR_RETURN_CALL_FUNCTION("reset", NULL, 70, inputArray);
	ZEPHIR_UNREF(inputArray);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(PhalconPlus_Helper_Arr, last)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *inputArray, inputArray_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputArray_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(inputArray)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &inputArray);


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "isarray", &_0, 0, inputArray);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(inputArray);
	ZEPHIR_RETURN_CALL_FUNCTION("end", NULL, 71, inputArray);
	ZEPHIR_UNREF(inputArray);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * 
 * handler = function(string | int key, mixed val) : string {
 *    return <string>
 * }
 *
 */
PHP_METHOD(PhalconPlus_Helper_Arr, groupBy)
{
	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL;
	zval *inputArray, inputArray_sub, *handler, handler_sub, k, v, tmp, *_1, _2, group$$3, _6$$4, group$$5, _7$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputArray_sub);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&group$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&group$$5);
	ZVAL_UNDEF(&_7$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(inputArray)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &inputArray, &handler);


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "isarray", &_0, 0, inputArray);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&tmp);
	array_init(&tmp);
	zephir_is_iterable(inputArray, 0, "phalconplus/Helper/Arr.zep", 108);
	if (Z_TYPE_P(inputArray) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(inputArray), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&k, _4);
			} else {
				ZVAL_LONG(&k, _3);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _1);
			ZEPHIR_CALL_FUNCTION(&group$$3, "call_user_func", &_5, 129, handler, &k, &v);
			zephir_check_call_status();
			if (!(zephir_array_isset(&tmp, &group$$3))) {
				ZEPHIR_INIT_NVAR(&_6$$4);
				array_init(&_6$$4);
				zephir_array_update_zval(&tmp, &group$$3, &_6$$4, PH_COPY | PH_SEPARATE);
			}
			zephir_array_update_multi(&tmp, &v, SL("zz"), 2, &group$$3, &k);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, inputArray, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, inputArray, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&k, inputArray, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&v, inputArray, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&group$$5, "call_user_func", &_5, 129, handler, &k, &v);
				zephir_check_call_status();
				if (!(zephir_array_isset(&tmp, &group$$5))) {
					ZEPHIR_INIT_NVAR(&_7$$6);
					array_init(&_7$$6);
					zephir_array_update_zval(&tmp, &group$$5, &_7$$6, PH_COPY | PH_SEPARATE);
				}
				zephir_array_update_multi(&tmp, &v, SL("zz"), 2, &group$$5, &k);
			ZEPHIR_CALL_METHOD(NULL, inputArray, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	RETURN_CCTOR(&tmp);
}

