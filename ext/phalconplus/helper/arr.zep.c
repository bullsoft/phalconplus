
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


ZEPHIR_INIT_CLASS(PhalconPlus_Helper_Arr) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Helper, Arr, phalconplus, helper_arr, phalconplus_helper_arr_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Helper_Arr, isAllKeyInt) {

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
	ZEPHIR_CALL_FUNCTION(&_3, "array_map", NULL, 62, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&input, "array_unique", NULL, 123, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&expected);
	zephir_create_array(&expected, 1, 0);
	zephir_array_fast_append(&expected, &__$true);
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&input, &expected));

}

PHP_METHOD(PhalconPlus_Helper_Arr, isAllKeyString) {

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
	ZEPHIR_CALL_FUNCTION(&_3, "array_map", NULL, 62, &_2, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&input, "array_unique", NULL, 123, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&expected);
	zephir_create_array(&expected, 1, 0);
	zephir_array_fast_append(&expected, &__$true);
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&input, &expected));

}

PHP_METHOD(PhalconPlus_Helper_Arr, isKeyNumericSequentialZeroBased) {

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
	ZEPHIR_CALL_FUNCTION(&expected, "range", NULL, 124, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&input, &expected));

}

PHP_METHOD(PhalconPlus_Helper_Arr, newProtoBuffer) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *inputArray, inputArray_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputArray_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &inputArray);



	object_init_ex(return_value, phalconplus_base_protobuffer_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 74, inputArray);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Helper_Arr, encodeJson) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *inputArray, inputArray_sub, str, _0, errCode, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputArray_sub);
	ZVAL_UNDEF(&str);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&errCode);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &inputArray);



	ZVAL_LONG(&_0, 256);
	ZEPHIR_INIT_VAR(&str);
	zephir_json_encode(&str, inputArray, zephir_get_intval(&_0) );
	ZEPHIR_CALL_FUNCTION(&errCode, "json_last_error", NULL, 63);
	zephir_check_call_status();
	if (!ZEPHIR_IS_LONG(&errCode, 0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalconplus_helper_exception_ce);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "json_last_error_msg", NULL, 125);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 2, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Helper/Arr.zep", 50);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&str);

}

