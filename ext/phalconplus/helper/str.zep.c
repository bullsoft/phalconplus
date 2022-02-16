
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
#include "kernel/memory.h"
#include "ext/spl/spl_array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Helper_Str)
{
	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Helper, Str, phalconplus, helper_str, phalconplus_helper_str_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Helper_Str, decodeJson)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *inputStr_param = NULL, obj, e, _0, _1, _5, _3$$3, _4$$3, _6$$4, _7$$4;
	zval inputStr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputStr);
	ZVAL_UNDEF(&obj);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(inputStr)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &inputStr_param);
	zephir_get_strval(&inputStr, inputStr_param);


	ZEPHIR_INIT_VAR(&obj);
	object_init_ex(&obj, spl_ce_ArrayObject);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_METHOD(NULL, &obj, "__construct", NULL, 80, &_0, &_1);
	zephir_check_call_status();

	/* try_start_1: */

		ZVAL_NULL(&_3$$3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "/");
		ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "isjsonstring", &_2, 0, &inputStr, &_3$$3, &_4$$3, &obj);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_OBJ(&_5, EG(exception));
		Z_ADDREF_P(&_5);
		if (zephir_is_instance_of(&_5, SL("Exception"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_5);
			ZEPHIR_INIT_VAR(&_6$$4);
			object_init_ex(&_6$$4, phalconplus_helper_exception_ce);
			ZEPHIR_CALL_METHOD(&_7$$4, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", NULL, 2, &_7$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$4, "phalconplus/Helper/Str.zep", 13);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_RETURN_CALL_METHOD(&obj, "getarraycopy", NULL, 131);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(PhalconPlus_Helper_Str, startsWith)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *full_param = NULL, *partial_param = NULL, _0, _1, _2;
	zval full, partial;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&full);
	ZVAL_UNDEF(&partial);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(full)
		Z_PARAM_STR(partial)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &full_param, &partial_param);
	zephir_get_strval(&full, full_param);
	zephir_get_strval(&partial, partial_param);


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, zephir_fast_strlen_ev(&partial));
	ZEPHIR_CALL_FUNCTION(&_2, "mb_substr", NULL, 132, &full, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&partial, &_2));
}

PHP_METHOD(PhalconPlus_Helper_Str, endsWith)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *full_param = NULL, *partial_param = NULL, _0, _1;
	zval full, partial;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&full);
	ZVAL_UNDEF(&partial);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(full)
		Z_PARAM_STR(partial)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &full_param, &partial_param);
	zephir_get_strval(&full, full_param);
	zephir_get_strval(&partial, partial_param);


	ZVAL_LONG(&_0, (-1 * zephir_fast_strlen_ev(&partial)));
	ZEPHIR_CALL_FUNCTION(&_1, "mb_substr", NULL, 132, &full, &_0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&partial, &_1));
}

PHP_METHOD(PhalconPlus_Helper_Str, contains)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *full_param = NULL, *partial_param = NULL, _0;
	zval full, partial;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&full);
	ZVAL_UNDEF(&partial);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(full)
		Z_PARAM_STR(partial)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &full_param, &partial_param);
	zephir_get_strval(&full, full_param);
	zephir_get_strval(&partial, partial_param);


	ZEPHIR_CALL_FUNCTION(&_0, "mb_substr_count", NULL, 133, &full, &partial);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_GT_LONG(&_0, 0));
}

PHP_METHOD(PhalconPlus_Helper_Str, safeBase64Encode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool padding;
	zval *inputStr_param = NULL, *padding_param = NULL, s, _0, _1, _2, _3$$3;
	zval inputStr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputStr);
	ZVAL_UNDEF(&s);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(inputStr)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(padding)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &inputStr_param, &padding_param);
	zephir_get_strval(&inputStr, inputStr_param);
	if (!padding_param) {
		padding = 0;
	} else {
		padding = zephir_get_boolval(padding_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "base64_encode", NULL, 134, &inputStr);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "+/");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "-_");
	ZEPHIR_CALL_FUNCTION(&s, "strtr", NULL, 130, &_0, &_1, &_2);
	zephir_check_call_status();
	if (!(padding)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "=");
		zephir_fast_trim(return_value, &s, &_3$$3, ZEPHIR_TRIM_RIGHT);
		RETURN_MM();
	}
	RETURN_CCTOR(&s);
}

PHP_METHOD(PhalconPlus_Helper_Str, safeBase64Decode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *inputStr_param = NULL, _0, _1, _2;
	zval inputStr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputStr);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(inputStr)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &inputStr_param);
	zephir_get_strval(&inputStr, inputStr_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "-_");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "+/");
	ZEPHIR_CALL_FUNCTION(&_2, "strtr", NULL, 130, &inputStr, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_FUNCTION("base64_decode", NULL, 135, &_2);
	zephir_check_call_status();
	RETURN_MM();
}

