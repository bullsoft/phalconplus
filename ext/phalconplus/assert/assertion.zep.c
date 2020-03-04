
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 *
 * @ref https://github.com/beberlei/assert
 */
ZEPHIR_INIT_CLASS(PhalconPlus_Assert_Assertion) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Assert, Assertion, phalconplus, assert_assertion, phalconplus_assert_assertion_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Assert_Assertion, createException) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval constraints;
	zval *value, value_sub, *message, message_sub, *code, code_sub, *propertyPath, propertyPath_sub, *constraints_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_UNDEF(&constraints);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &value, &message, &code, &propertyPath, &constraints_param);

	if (!constraints_param) {
		ZEPHIR_INIT_VAR(&constraints);
		array_init(&constraints);
	} else {
		zephir_get_arrval(&constraints, constraints_param);
	}


	object_init_ex(return_value, phalconplus_assert_invalidargumentexception_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 49, message, code, propertyPath, value, &constraints);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Assert_Assertion, eq) {

	zval _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *value1, value1_sub, *value2, value2_sub, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, v1$$3, v2$$3, _1$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value1_sub);
	ZVAL_UNDEF(&value2_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&v1$$3);
	ZVAL_UNDEF(&v2$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &value1, &value2, &message, &propertyPath);

	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}


	if (!ZEPHIR_IS_EQUAL(value1, value2)) {
		ZEPHIR_CALL_SELF(&v1$$3, "stringify", &_0, 50, value1);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(&v2$$3, "stringify", &_0, 50, value2);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_NULL) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVSVS(message, "Value ", &v1$$3, " does not equal expected value ", &v2$$3, ".");
		}
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 1, 0);
		zephir_array_update_string(&_2$$3, SL("expected"), value2, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_3$$3, 34);
		ZEPHIR_CALL_STATIC(&_1$$3, "createexception", NULL, 0, value1, message, &_3$$3, propertyPath, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Assert/Assertion.zep", 26);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, notEq) {

	zval _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *value1, value1_sub, *value2, value2_sub, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, _0$$3, _1$$3, _3$$3, _4$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value1_sub);
	ZVAL_UNDEF(&value2_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &value1, &value2, &message, &propertyPath);

	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}


	if (ZEPHIR_IS_EQUAL(value1, value2)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(&_0$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_STRING(&_0$$3, "Value \"%s\" is equal to expected value \"%s\".");
		}
		ZEPHIR_CALL_STATIC(&_1$$3, "stringify", &_2, 50, value1);
		zephir_check_call_status();
		ZEPHIR_CALL_STATIC(&_3$$3, "stringify", &_2, 50, value2);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(message, "sprintf", NULL, 6, &_0$$3, &_1$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_create_array(&_5$$3, 1, 0);
		zephir_array_update_string(&_5$$3, SL("expected"), value2, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_6$$3, 42);
		ZEPHIR_CALL_STATIC(&_4$$3, "createexception", NULL, 0, value1, message, &_6$$3, propertyPath, &_5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalconplus/Assert/Assertion.zep", 41);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, same) {

	zval _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *value1, value1_sub, *value2, value2_sub, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, v1$$3, v2$$3, _1$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value1_sub);
	ZVAL_UNDEF(&value2_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&v1$$3);
	ZVAL_UNDEF(&v2$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &value1, &value2, &message, &propertyPath);

	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}


	if (!ZEPHIR_IS_IDENTICAL(value1, value2)) {
		ZEPHIR_CALL_SELF(&v1$$3, "stringify", &_0, 50, value1);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(&v2$$3, "stringify", &_0, 50, value2);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_NULL) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVSVS(message, "Value ", &v1$$3, " does not equal expected value ", &v2$$3, ".");
		}
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 1, 0);
		zephir_array_update_string(&_2$$3, SL("expected"), value2, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_3$$3, 33);
		ZEPHIR_CALL_STATIC(&_1$$3, "createexception", NULL, 0, value1, message, &_3$$3, propertyPath, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Assert/Assertion.zep", 59);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, notEmpty) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *value, value_sub, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, v1$$3, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&v1$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value, &message, &propertyPath);

	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}


	if (ZEPHIR_IS_EMPTY(value)) {
		ZEPHIR_CALL_SELF(&v1$$3, "stringify", &_0, 50, value);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_NULL) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVS(message, "Value ", &v1$$3, " is empty, but non empty value was expected.");
		}
		ZVAL_LONG(&_2$$3, 14);
		ZEPHIR_CALL_STATIC(&_1$$3, "createexception", NULL, 0, value, message, &_2$$3, propertyPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Assert/Assertion.zep", 73);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, notNull) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *value, value_sub, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, v1$$3, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&v1$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value, &message, &propertyPath);

	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}


	if (Z_TYPE_P(value) == IS_NULL) {
		ZEPHIR_CALL_SELF(&v1$$3, "stringify", &_0, 50, value);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_NULL) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVS(message, "Value ", &v1$$3, " is null, but non null value was expected.");
		}
		ZVAL_LONG(&_2$$3, 15);
		ZEPHIR_CALL_STATIC(&_1$$3, "createexception", NULL, 0, value, message, &_2$$3, propertyPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Assert/Assertion.zep", 87);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, notBlank) {

	zend_bool _0, _1, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_9 = NULL;
	zval *value, value_sub, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, _2, _5, _6, _7$$3, _8$$3, _10$$3, _11$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value, &message, &propertyPath);

	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}


	_0 = ZEPHIR_IS_FALSE_IDENTICAL(value);
	if (!(_0)) {
		_1 = ZEPHIR_IS_EMPTY(value);
		if (_1) {
			ZEPHIR_INIT_VAR(&_2);
			ZVAL_STRING(&_2, "0");
			_1 = !ZEPHIR_IS_EQUAL(&_2, value);
		}
		_0 = _1;
	}
	_3 = _0;
	if (!(_3)) {
		_4 = Z_TYPE_P(value) == IS_STRING;
		if (_4) {
			ZEPHIR_INIT_VAR(&_5);
			zephir_fast_trim(&_5, value, NULL , ZEPHIR_TRIM_BOTH);
			ZEPHIR_INIT_VAR(&_6);
			ZVAL_STRING(&_6, "");
			_4 = ZEPHIR_IS_IDENTICAL(&_6, &_5);
		}
		_3 = _4;
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_7$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(&_7$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(&_7$$3);
			ZVAL_STRING(&_7$$3, "Value \"%s\" is blank, but was expected to contain a value.");
		}
		ZEPHIR_CALL_STATIC(&_8$$3, "stringify", &_9, 50, value);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(message, "sprintf", NULL, 6, &_7$$3, &_8$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_11$$3, 27);
		ZEPHIR_CALL_STATIC(&_10$$3, "createexception", NULL, 0, value, message, &_11$$3, propertyPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$3, "phalconplus/Assert/Assertion.zep", 99);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, integer) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, _0, _1$$4, _2$$4, _4$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value, &message, &propertyPath);

	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}


	ZEPHIR_CALL_FUNCTION(&_0, "\is_int", NULL, 51, value);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		if (Z_TYPE_P(message) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$4);
			if (zephir_is_true(message)) {
				ZEPHIR_CPY_WRT(&_1$$4, message);
			} else {
				ZEPHIR_INIT_NVAR(&_1$$4);
				ZVAL_STRING(&_1$$4, "Value \"%s\" is not an integer.");
			}
			ZEPHIR_CALL_STATIC(&_2$$4, "stringify", &_3, 50, value);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(message, "\sprintf", NULL, 52, &_1$$4, &_2$$4);
			zephir_check_call_status();
		}
		ZVAL_LONG(&_5$$3, 10);
		ZEPHIR_CALL_STATIC(&_4$$3, "createexception", NULL, 0, value, message, &_5$$3, propertyPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalconplus/Assert/Assertion.zep", 113);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, numeric) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *value, value_sub, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, v1$$3, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&v1$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value, &message, &propertyPath);

	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}


	if (!(zephir_is_numeric(value))) {
		ZEPHIR_CALL_SELF(&v1$$3, "stringify", &_0, 50, value);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_NULL) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVS(message, "Value ", &v1$$3, " is not numeric.");
		}
		ZVAL_LONG(&_2$$3, 23);
		ZEPHIR_CALL_STATIC(&_1$$3, "createexception", NULL, 0, value, message, &_2$$3, propertyPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Assert/Assertion.zep", 126);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, range) {

	zval _7$$3;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long minValue, maxValue, ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *minValue_param = NULL, *maxValue_param = NULL, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, _1$$3, _2$$3, _4$$3, _5$$3, _6$$3, _8$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &value, &minValue_param, &maxValue_param, &message, &propertyPath);

	minValue = zephir_get_intval(minValue_param);
	maxValue = zephir_get_intval(maxValue_param);
	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}


	ZEPHIR_CALL_STATIC(NULL, "numeric", NULL, 0, value, message, propertyPath);
	zephir_check_call_status();
	_0 = ZEPHIR_LT_LONG(value, minValue);
	if (!(_0)) {
		_0 = ZEPHIR_GT_LONG(value, maxValue);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(&_1$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "Number \"%s\" was expected to be at least \"%d\" and at most \"%d\".");
		}
		ZEPHIR_CALL_STATIC(&_2$$3, "stringify", &_3, 50, value);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, minValue);
		ZVAL_LONG(&_5$$3, maxValue);
		ZEPHIR_CALL_FUNCTION(message, "sprintf", NULL, 6, &_1$$3, &_2$$3, &_4$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_7$$3);
		zephir_create_array(&_7$$3, 2, 0);
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_LONG(&_8$$3, minValue);
		zephir_array_update_string(&_7$$3, SL("min"), &_8$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_8$$3);
		ZVAL_LONG(&_8$$3, maxValue);
		zephir_array_update_string(&_7$$3, SL("max"), &_8$$3, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_4$$3, 30);
		ZEPHIR_CALL_STATIC(&_6$$3, "createexception", NULL, 0, value, message, &_4$$3, propertyPath, &_7$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$3, "phalconplus/Assert/Assertion.zep", 143);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, minLength) {

	zval _8$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL;
	zval encodeing;
	zend_long minLength, ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *minLength_param = NULL, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, *encodeing_param = NULL, __$null, _0, _2$$3, _3$$3, _5$$3, _6$$3, _7$$3, _9$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&encodeing);
	ZVAL_UNDEF(&_8$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &value, &minLength_param, &message, &propertyPath, &encodeing_param);

	minLength = zephir_get_intval(minLength_param);
	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}
	if (!encodeing_param) {
		ZEPHIR_INIT_VAR(&encodeing);
		ZVAL_STRING(&encodeing, "utf8");
	} else {
		zephir_get_strval(&encodeing, encodeing_param);
	}


	ZEPHIR_CALL_STATIC(NULL, "isstring", NULL, 0, value, message, propertyPath);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "mb_strlen", &_1, 53, value, &encodeing);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(&_0, minLength)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(&_2$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "Value \"%s\" is too short, it should at least %d characters, but only has %d characters.");
		}
		ZEPHIR_CALL_STATIC(&_3$$3, "stringify", &_4, 50, value);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_5$$3, "mb_strlen", &_1, 53, value, &encodeing);
		zephir_check_call_status();
		ZVAL_LONG(&_6$$3, minLength);
		ZEPHIR_CALL_FUNCTION(message, "sprintf", NULL, 6, &_2$$3, &_3$$3, &_6$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$3);
		zephir_create_array(&_8$$3, 2, 0);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_LONG(&_9$$3, minLength);
		zephir_array_update_string(&_8$$3, SL("min_length"), &_9$$3, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_8$$3, SL("encoding"), &encodeing, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_6$$3, 18);
		ZEPHIR_CALL_STATIC(&_7$$3, "createexception", NULL, 0, value, message, &_6$$3, propertyPath, &_8$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$3, "phalconplus/Assert/Assertion.zep", 160);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, maxLength) {

	zval _8$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL;
	zval encodeing;
	zend_long maxLength, ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *maxLength_param = NULL, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, *encodeing_param = NULL, __$null, _0, _2$$3, _3$$3, _5$$3, _6$$3, _7$$3, _9$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&encodeing);
	ZVAL_UNDEF(&_8$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &value, &maxLength_param, &message, &propertyPath, &encodeing_param);

	maxLength = zephir_get_intval(maxLength_param);
	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}
	if (!encodeing_param) {
		ZEPHIR_INIT_VAR(&encodeing);
		ZVAL_STRING(&encodeing, "utf8");
	} else {
		zephir_get_strval(&encodeing, encodeing_param);
	}


	ZEPHIR_CALL_STATIC(NULL, "isstring", NULL, 0, value, message, propertyPath);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "mb_strlen", &_1, 53, value, &encodeing);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(&_0, maxLength)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(&_2$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_STRING(&_2$$3, "Value \"%s\" is too long, it should no more than %d characters, but has %d characters.");
		}
		ZEPHIR_CALL_STATIC(&_3$$3, "stringify", &_4, 50, value);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_5$$3, "mb_strlen", &_1, 53, value, &encodeing);
		zephir_check_call_status();
		ZVAL_LONG(&_6$$3, maxLength);
		ZEPHIR_CALL_FUNCTION(message, "sprintf", NULL, 6, &_2$$3, &_3$$3, &_6$$3, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$3);
		zephir_create_array(&_8$$3, 2, 0);
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_LONG(&_9$$3, maxLength);
		zephir_array_update_string(&_8$$3, SL("max_length"), &_9$$3, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_8$$3, SL("encoding"), &encodeing, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_6$$3, 19);
		ZEPHIR_CALL_STATIC(&_7$$3, "createexception", NULL, 0, value, message, &_6$$3, propertyPath, &_8$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$3, "phalconplus/Assert/Assertion.zep", 176);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, betweenLength) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval encodeing;
	zend_long minLength, maxLength, ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *minLength_param = NULL, *maxLength_param = NULL, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, *encodeing_param = NULL, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&encodeing);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 3, &value, &minLength_param, &maxLength_param, &message, &propertyPath, &encodeing_param);

	minLength = zephir_get_intval(minLength_param);
	maxLength = zephir_get_intval(maxLength_param);
	if (!message) {
		message = &message_sub;
		message = &__$null;
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}
	if (!encodeing_param) {
		ZEPHIR_INIT_VAR(&encodeing);
		ZVAL_STRING(&encodeing, "utf8");
	} else {
		zephir_get_strval(&encodeing, encodeing_param);
	}


	ZEPHIR_CALL_STATIC(NULL, "isstring", NULL, 0, value, message, propertyPath);
	zephir_check_call_status();
	ZVAL_LONG(&_0, minLength);
	ZEPHIR_CALL_STATIC(NULL, "minlength", NULL, 0, value, &_0, message, propertyPath, &encodeing);
	zephir_check_call_status();
	ZVAL_LONG(&_0, maxLength);
	ZEPHIR_CALL_STATIC(NULL, "maxlength", NULL, 0, value, &_0, message, propertyPath, &encodeing);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, min) {

	zval _6$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long minValue, ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *minValue_param = NULL, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, _0$$3, _1$$3, _3$$3, _4$$3, _5$$3, _7$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &value, &minValue_param, &message, &propertyPath);

	minValue = zephir_get_intval(minValue_param);
	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}


	ZEPHIR_CALL_STATIC(NULL, "numeric", NULL, 0, value, message, propertyPath);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(value, minValue)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(&_0$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_STRING(&_0$$3, "Number \"%s\" was expected to be at least \"%s\".");
		}
		ZEPHIR_CALL_STATIC(&_1$$3, "stringify", &_2, 50, value);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, minValue);
		ZEPHIR_CALL_STATIC(&_3$$3, "stringify", &_2, 50, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(message, "sprintf", NULL, 6, &_0$$3, &_1$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_create_array(&_6$$3, 1, 0);
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_LONG(&_7$$3, minValue);
		zephir_array_update_string(&_6$$3, SL("min"), &_7$$3, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_4$$3, 35);
		ZEPHIR_CALL_STATIC(&_5$$3, "createexception", NULL, 0, value, message, &_4$$3, propertyPath, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "phalconplus/Assert/Assertion.zep", 200);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, max) {

	zval _6$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long maxValue, ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *maxValue_param = NULL, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, _0$$3, _1$$3, _3$$3, _4$$3, _5$$3, _7$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &value, &maxValue_param, &message, &propertyPath);

	maxValue = zephir_get_intval(maxValue_param);
	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}


	ZEPHIR_CALL_STATIC(NULL, "numeric", NULL, 0, value, message, propertyPath);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(value, maxValue)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(&_0$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_STRING(&_0$$3, "Number \"%s\" was expected to be at most \"%s\".");
		}
		ZEPHIR_CALL_STATIC(&_1$$3, "stringify", &_2, 50, value);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, maxValue);
		ZEPHIR_CALL_STATIC(&_3$$3, "stringify", &_2, 50, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(message, "sprintf", NULL, 6, &_0$$3, &_1$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_create_array(&_6$$3, 1, 0);
		ZEPHIR_INIT_VAR(&_7$$3);
		ZVAL_LONG(&_7$$3, maxValue);
		zephir_array_update_string(&_6$$3, SL("max"), &_7$$3, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_4$$3, 36);
		ZEPHIR_CALL_STATIC(&_5$$3, "createexception", NULL, 0, value, message, &_4$$3, propertyPath, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "phalconplus/Assert/Assertion.zep", 217);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, contains) {

	zval _6$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval encodeing;
	zval *value, value_sub, *needle, needle_sub, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, *encodeing_param = NULL, __$null, _0, _1$$3, _2$$3, _4$$3, _5$$3, _7$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&needle_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&encodeing);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &value, &needle, &message, &propertyPath, &encodeing_param);

	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}
	if (!encodeing_param) {
		ZEPHIR_INIT_VAR(&encodeing);
		ZVAL_STRING(&encodeing, "utf8");
	} else {
		zephir_get_strval(&encodeing, encodeing_param);
	}


	ZEPHIR_CALL_STATIC(NULL, "isstring", NULL, 0, value, message, propertyPath);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "mb_strpos", NULL, 54, value, needle, &__$null, &encodeing);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(&_1$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "Value \"%s\" does not contain \"%s\".");
		}
		ZEPHIR_CALL_STATIC(&_2$$3, "stringify", &_3, 50, value);
		zephir_check_call_status();
		ZEPHIR_CALL_STATIC(&_4$$3, "stringify", &_3, 50, needle);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(message, "sprintf", NULL, 6, &_1$$3, &_2$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_create_array(&_6$$3, 2, 0);
		zephir_array_update_string(&_6$$3, SL("needle"), needle, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_6$$3, SL("encoding"), &encodeing, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_7$$3, 21);
		ZEPHIR_CALL_STATIC(&_5$$3, "createexception", NULL, 0, value, message, &_7$$3, propertyPath, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "phalconplus/Assert/Assertion.zep", 233);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, notContains) {

	zval _6$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval encodeing;
	zval *value, value_sub, *needle, needle_sub, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, *encodeing_param = NULL, __$null, _0, _1$$3, _2$$3, _4$$3, _5$$3, _7$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&needle_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&encodeing);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 3, &value, &needle, &message, &propertyPath, &encodeing_param);

	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}
	if (!encodeing_param) {
		ZEPHIR_INIT_VAR(&encodeing);
		ZVAL_STRING(&encodeing, "utf8");
	} else {
		zephir_get_strval(&encodeing, encodeing_param);
	}


	ZEPHIR_CALL_STATIC(NULL, "isstring", NULL, 0, value, message, propertyPath);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_0, "mb_strpos", NULL, 54, value, needle, &__$null, &encodeing);
	zephir_check_call_status();
	if (!ZEPHIR_IS_FALSE_IDENTICAL(&_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(&_1$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "Value \"%s\" contain \"%s\".");
		}
		ZEPHIR_CALL_STATIC(&_2$$3, "stringify", &_3, 50, value);
		zephir_check_call_status();
		ZEPHIR_CALL_STATIC(&_4$$3, "stringify", &_3, 50, needle);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(message, "sprintf", NULL, 6, &_1$$3, &_2$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_create_array(&_6$$3, 2, 0);
		zephir_array_update_string(&_6$$3, SL("needle"), needle, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_6$$3, SL("encoding"), &encodeing, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_7$$3, 229);
		ZEPHIR_CALL_STATIC(&_5$$3, "createexception", NULL, 0, value, message, &_7$$3, propertyPath, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$3, "phalconplus/Assert/Assertion.zep", 248);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, inArray) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval choices, _5$$3, _9$$3;
	zval *value, value_sub, *choices_param = NULL, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$true, __$null, _0, _1$$3, _2$$3, _4$$3, _6$$3, _7$$3, _8$$3, _10$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&choices);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_9$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &value, &choices_param, &message, &propertyPath);

	zephir_get_arrval(&choices, choices_param);
	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}


	ZEPHIR_CALL_FUNCTION(&_0, "in_array", NULL, 9, value, &choices, &__$true);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(&_1$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(&_1$$3);
			ZVAL_STRING(&_1$$3, "Value \"%s\" is not an element of the valid values: %s");
		}
		ZEPHIR_CALL_STATIC(&_2$$3, "stringify", &_3, 50, value);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_create_array(&_5$$3, 2, 0);
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_get_called_class(&_6$$3);
		zephir_array_fast_append(&_5$$3, &_6$$3);
		ZEPHIR_INIT_NVAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "stringify");
		zephir_array_fast_append(&_5$$3, &_6$$3);
		ZEPHIR_CALL_FUNCTION(&_7$$3, "array_map", NULL, 55, &_5$$3, &choices);
		zephir_check_call_status();
		zephir_fast_join_str(&_4$$3, SL(", "), &_7$$3);
		ZEPHIR_CALL_FUNCTION(message, "sprintf", NULL, 6, &_1$$3, &_2$$3, &_4$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$3);
		zephir_create_array(&_9$$3, 1, 0);
		zephir_array_update_string(&_9$$3, SL("choices"), &choices, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_10$$3, 22);
		ZEPHIR_CALL_STATIC(&_8$$3, "createexception", NULL, 0, value, message, &_10$$3, propertyPath, &_9$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_8$$3, "phalconplus/Assert/Assertion.zep", 262);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, keyExists) {

	zval _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *key, key_sub, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, _0$$3, _1$$3, _3$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &value, &key, &message, &propertyPath);

	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}


	ZEPHIR_CALL_STATIC(NULL, "isarray", NULL, 0, value, message, propertyPath);
	zephir_check_call_status();
	if (!(zephir_array_key_exists(value, key))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(&_0$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_STRING(&_0$$3, "Array does not contain an element with key \"%s\"");
		}
		ZEPHIR_CALL_STATIC(&_1$$3, "stringify", &_2, 50, key);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(message, "sprintf", NULL, 6, &_0$$3, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_create_array(&_4$$3, 1, 0);
		zephir_array_update_string(&_4$$3, SL("key"), key, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_5$$3, 26);
		ZEPHIR_CALL_STATIC(&_3$$3, "createexception", NULL, 0, value, message, &_5$$3, propertyPath, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalconplus/Assert/Assertion.zep", 276);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, isResource) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *value, value_sub, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, _0$$3, _1$$3, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value, &message, &propertyPath);

	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}


	if (!(Z_TYPE_P(value) == IS_RESOURCE)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(&_0$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_STRING(&_0$$3, "Value \"%s\" is not a resource");
		}
		ZEPHIR_CALL_STATIC(&_1$$3, "stringify", &_2, 50, value);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(message, "sprintf", NULL, 6, &_0$$3, &_1$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, 225);
		ZEPHIR_CALL_STATIC(&_3$$3, "createexception", NULL, 0, value, message, &_4$$3, propertyPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalconplus/Assert/Assertion.zep", 288);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, isString) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *value, value_sub, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, _0$$3, _1$$3, _3$$3, _4$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value, &message, &propertyPath);

	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}


	if (!(Z_TYPE_P(value) == IS_STRING)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(&_0$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_STRING(&_0$$3, "Value \"%s\" expected to be string, type %s given.");
		}
		ZEPHIR_CALL_STATIC(&_1$$3, "stringify", &_2, 50, value);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_gettype(&_3$$3, value);
		ZEPHIR_CALL_FUNCTION(message, "sprintf", NULL, 6, &_0$$3, &_1$$3, &_3$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_5$$3, 16);
		ZEPHIR_CALL_STATIC(&_4$$3, "createexception", NULL, 0, value, message, &_5$$3, propertyPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalconplus/Assert/Assertion.zep", 301);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, isArray) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *value, value_sub, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, _0$$3, _1$$3, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value, &message, &propertyPath);

	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}


	if (!(Z_TYPE_P(value) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(&_0$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_STRING(&_0$$3, "Value \"%s\" is not an array.");
		}
		ZEPHIR_CALL_STATIC(&_1$$3, "stringify", &_2, 50, value);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(message, "sprintf", NULL, 6, &_0$$3, &_1$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_4$$3, 24);
		ZEPHIR_CALL_STATIC(&_3$$3, "createexception", NULL, 0, value, message, &_4$$3, propertyPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalconplus/Assert/Assertion.zep", 314);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, isInstanceOf) {

	zval _8$$10;
	zend_bool result;
	zval classItem, _2$$6, _3$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *classNames, classNames_sub, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, tmp$$5, *_0$$5, _1$$5, _4$$10, _5$$10, _7$$10, _9$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&classNames_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&tmp$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&classItem);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$8);
	ZVAL_UNDEF(&_8$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &value, &classNames, &message, &propertyPath);

	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}


	result = 0;
	if (Z_TYPE_P(classNames) == IS_STRING) {
		zephir_get_strval(&classItem, classNames);
		if (zephir_is_instance_of(value, Z_STRVAL_P(&classItem), Z_STRLEN_P(&classItem))) {
			result = 1;
		}
	} else if (Z_TYPE_P(classNames) == IS_ARRAY) {
		zephir_is_iterable(classNames, 0, "phalconplus/Assert/Assertion.zep", 337);
		if (Z_TYPE_P(classNames) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(classNames), _0$$5)
			{
				ZEPHIR_INIT_NVAR(&tmp$$5);
				ZVAL_COPY(&tmp$$5, _0$$5);
				zephir_get_strval(&_2$$6, &tmp$$5);
				ZEPHIR_CPY_WRT(&classItem, &_2$$6);
				if (zephir_is_instance_of(value, Z_STRVAL_P(&classItem), Z_STRLEN_P(&classItem))) {
					result = 1;
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, classNames, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$5, classNames, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$5)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&tmp$$5, classNames, "current", NULL, 0);
				zephir_check_call_status();
					zephir_get_strval(&_3$$8, &tmp$$5);
					ZEPHIR_CPY_WRT(&classItem, &_3$$8);
					if (zephir_is_instance_of(value, Z_STRVAL_P(&classItem), Z_STRLEN_P(&classItem))) {
						result = 1;
						break;
					}
				ZEPHIR_CALL_METHOD(NULL, classNames, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&tmp$$5);
	}
	if (result == 0) {
		ZEPHIR_INIT_VAR(&_4$$10);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(&_4$$10, message);
		} else {
			ZEPHIR_INIT_NVAR(&_4$$10);
			ZVAL_STRING(&_4$$10, "Class \"%s\" was expected to be instanceof of \"%s\" but is not.");
		}
		ZEPHIR_CALL_STATIC(&_5$$10, "stringify", &_6, 50, value);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(message, "sprintf", NULL, 6, &_4$$10, &_5$$10, &classItem);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$10);
		zephir_create_array(&_8$$10, 1, 0);
		zephir_array_update_string(&_8$$10, SL("class"), &classItem, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_9$$10, 28);
		ZEPHIR_CALL_STATIC(&_7$$10, "createexception", NULL, 0, value, message, &_9$$10, propertyPath, &_8$$10);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$10, "phalconplus/Assert/Assertion.zep", 344);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, isJsonString) {

	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, _0, _2, _3$$3, _4$$3, _6$$3, _7$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value, &message, &propertyPath);

	if (!message) {
		message = &message_sub;
		ZEPHIR_CPY_WRT(message, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}


	ZEPHIR_CALL_STATIC(NULL, "isstring", NULL, 0, value, message, propertyPath);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_json_decode(&_0, value, 0 );
	_1 = Z_TYPE_P(&_0) == IS_NULL;
	if (_1) {
		ZEPHIR_CALL_FUNCTION(&_2, "json_last_error", NULL, 56);
		zephir_check_call_status();
		_1 = !ZEPHIR_IS_LONG(&_2, 0);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_3$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(&_3$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "Value \"%s\" is not a valid JSON string.");
		}
		ZEPHIR_CALL_STATIC(&_4$$3, "stringify", &_5, 50, value);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(message, "sprintf", NULL, 6, &_3$$3, &_4$$3);
		zephir_check_call_status();
		ZVAL_LONG(&_7$$3, 206);
		ZEPHIR_CALL_STATIC(&_6$$3, "createexception", NULL, 0, value, message, &_7$$3, propertyPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$3, "phalconplus/Assert/Assertion.zep", 358);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, stringify) {

	zval _1$$5;
	zend_bool _6, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, __$true, _0$$3, val, _2$$6, _3$$6, _4$$6, _5$$6, _8$$7, _9$$7, _10$$7, _11$$8, _12$$8, _13$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_1$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if ((Z_TYPE_P(value) == IS_TRUE || Z_TYPE_P(value) == IS_FALSE)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		if (ZEPHIR_IS_TRUE(value)) {
			ZVAL_STRING(&_0$$3, "TRUE");
		} else {
			ZVAL_STRING(&_0$$3, "FALSE");
		}
		RETURN_CCTOR(&_0$$3);
	}
	if (Z_TYPE_P(value) == IS_NULL) {
		RETURN_MM_STRING("NULL");
	}
	if (zephir_is_scalar(value)) {
		zephir_get_strval(&_1$$5, value);
		ZEPHIR_CPY_WRT(&val, &_1$$5);
		if (zephir_fast_strlen_ev(&val) > 100) {
			ZVAL_LONG(&_2$$6, 0);
			ZVAL_LONG(&_3$$6, 96);
			ZEPHIR_INIT_VAR(&_4$$6);
			zephir_substr(&_4$$6, &val, 0 , 96 , 0);
			ZEPHIR_INIT_VAR(&_5$$6);
			ZEPHIR_CONCAT_VS(&_5$$6, &_4$$6, " ...");
			ZEPHIR_CPY_WRT(&val, &_5$$6);
		}
		RETURN_CCTOR(&val);
	}
	_6 = Z_TYPE_P(value) == IS_ARRAY;
	if (!(_6)) {
		_6 = Z_TYPE_P(value) == IS_OBJECT;
	}
	_7 = _6;
	if (!(_7)) {
		_7 = Z_TYPE_P(value) == IS_RESOURCE;
	}
	if (_7) {
		ZEPHIR_CALL_FUNCTION(&val, "print_r", NULL, 57, value, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$7);
		ZVAL_STRING(&_8$$7, "/\\s+/");
		ZEPHIR_INIT_VAR(&_9$$7);
		ZVAL_STRING(&_9$$7, " ");
		ZEPHIR_CALL_FUNCTION(&_10$$7, "preg_replace", NULL, 58, &_8$$7, &_9$$7, &val);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&val, &_10$$7);
		if (zephir_fast_strlen_ev(&val) > 160) {
			ZVAL_LONG(&_11$$8, 0);
			ZVAL_LONG(&_12$$8, 156);
			ZEPHIR_INIT_VAR(&_13$$8);
			zephir_substr(&_13$$8, &val, 0 , 156 , 0);
			ZEPHIR_CONCAT_VS(return_value, &_13$$8, " ...");
			RETURN_MM();
		}
		RETURN_CCTOR(&val);
	}
	RETURN_MM_STRING("unknown");

}

