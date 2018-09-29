
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *constraints = NULL;
	zval *value, *message, *code, *propertyPath, *constraints_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 4, 1, &value, &message, &code, &propertyPath, &constraints_param);

	if (!constraints_param) {
		ZEPHIR_INIT_VAR(constraints);
		array_init(constraints);
	} else {
		zephir_get_arrval(constraints, constraints_param);
	}


	object_init_ex(return_value, phalconplus_assert_invalidargumentexception_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 22, message, code, propertyPath, value, constraints);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Assert_Assertion, eq) {

	zval *_2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *value1, *value2, *message = NULL, *propertyPath = NULL, *v1$$3 = NULL, *v2$$3 = NULL, *_1$$3 = NULL, *_3$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &value1, &value2, &message, &propertyPath);

	if (!message) {
		ZEPHIR_CPY_WRT(message, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = ZEPHIR_GLOBAL(global_null);
	}


	if (!ZEPHIR_IS_EQUAL(value1, value2)) {
		ZEPHIR_CALL_SELF(&v1$$3, "stringify", &_0, 23, value1);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(&v2$$3, "stringify", &_0, 23, value2);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_NULL) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVSVS(message, "Value ", v1$$3, " does not equal expected value ", v2$$3, ".");
		}
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_create_array(_2$$3, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_2$$3, SL("expected"), &value2, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_LONG(_3$$3, 34);
		ZEPHIR_CALL_STATIC(&_1$$3, "createexception", NULL, 0, value1, message, _3$$3, propertyPath, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalconplus/Assert/Assertion.zep", 26 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, notEq) {

	zval *_5$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *value1, *value2, *message = NULL, *propertyPath = NULL, *_0$$3 = NULL, *_1$$3 = NULL, *_3$$3 = NULL, *_4$$3 = NULL, *_6$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &value1, &value2, &message, &propertyPath);

	if (!message) {
		ZEPHIR_CPY_WRT(message, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = ZEPHIR_GLOBAL(global_null);
	}


	if (ZEPHIR_IS_EQUAL(value1, value2)) {
		ZEPHIR_INIT_VAR(_0$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(_0$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(_0$$3);
			ZVAL_STRING(_0$$3, "Value \"%s\" is equal to expected value \"%s\".", 1);
		}
		ZEPHIR_CALL_STATIC(&_1$$3, "stringify", &_2, 23, value1);
		zephir_check_call_status();
		ZEPHIR_CALL_STATIC(&_3$$3, "stringify", &_2, 23, value2);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&message, "sprintf", NULL, 13, _0$$3, _1$$3, _3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_5$$3);
		zephir_create_array(_5$$3, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_5$$3, SL("expected"), &value2, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_6$$3);
		ZVAL_LONG(_6$$3, 42);
		ZEPHIR_CALL_STATIC(&_4$$3, "createexception", NULL, 0, value1, message, _6$$3, propertyPath, _5$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$3, "phalconplus/Assert/Assertion.zep", 41 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, same) {

	zval *_2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *value1, *value2, *message = NULL, *propertyPath = NULL, *v1$$3 = NULL, *v2$$3 = NULL, *_1$$3 = NULL, *_3$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &value1, &value2, &message, &propertyPath);

	if (!message) {
		ZEPHIR_CPY_WRT(message, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = ZEPHIR_GLOBAL(global_null);
	}


	if (!ZEPHIR_IS_IDENTICAL(value1, value2)) {
		ZEPHIR_CALL_SELF(&v1$$3, "stringify", &_0, 23, value1);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(&v2$$3, "stringify", &_0, 23, value2);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_NULL) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVSVS(message, "Value ", v1$$3, " does not equal expected value ", v2$$3, ".");
		}
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_create_array(_2$$3, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_2$$3, SL("expected"), &value2, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_LONG(_3$$3, 33);
		ZEPHIR_CALL_STATIC(&_1$$3, "createexception", NULL, 0, value1, message, _3$$3, propertyPath, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalconplus/Assert/Assertion.zep", 59 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, notEmpty) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *value, *message = NULL, *propertyPath = NULL, *v1$$3 = NULL, *_1$$3 = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value, &message, &propertyPath);

	if (!message) {
		ZEPHIR_CPY_WRT(message, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = ZEPHIR_GLOBAL(global_null);
	}


	if (ZEPHIR_IS_EMPTY(value)) {
		ZEPHIR_CALL_SELF(&v1$$3, "stringify", &_0, 23, value);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_NULL) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVS(message, "Value ", v1$$3, " is empty, but non empty value was expected.");
		}
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_LONG(_2$$3, 14);
		ZEPHIR_CALL_STATIC(&_1$$3, "createexception", NULL, 0, value, message, _2$$3, propertyPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalconplus/Assert/Assertion.zep", 73 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, notNull) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *value, *message = NULL, *propertyPath = NULL, *v1$$3 = NULL, *_1$$3 = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value, &message, &propertyPath);

	if (!message) {
		ZEPHIR_CPY_WRT(message, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = ZEPHIR_GLOBAL(global_null);
	}


	if (Z_TYPE_P(value) == IS_NULL) {
		ZEPHIR_CALL_SELF(&v1$$3, "stringify", &_0, 23, value);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_NULL) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVS(message, "Value ", v1$$3, " is null, but non null value was expected.");
		}
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_LONG(_2$$3, 15);
		ZEPHIR_CALL_STATIC(&_1$$3, "createexception", NULL, 0, value, message, _2$$3, propertyPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalconplus/Assert/Assertion.zep", 87 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, numeric) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *value, *message = NULL, *propertyPath = NULL, *v1$$3 = NULL, *_1$$3 = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value, &message, &propertyPath);

	if (!message) {
		ZEPHIR_CPY_WRT(message, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = ZEPHIR_GLOBAL(global_null);
	}


	if (!(zephir_is_numeric(value))) {
		ZEPHIR_CALL_SELF(&v1$$3, "stringify", &_0, 23, value);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_NULL) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVS(message, "Value ", v1$$3, " is not numeric.");
		}
		ZEPHIR_INIT_VAR(_2$$3);
		ZVAL_LONG(_2$$3, 23);
		ZEPHIR_CALL_STATIC(&_1$$3, "createexception", NULL, 0, value, message, _2$$3, propertyPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalconplus/Assert/Assertion.zep", 100 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, range) {

	zval *_8$$3;
	zend_bool _0;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long minValue, maxValue, ZEPHIR_LAST_CALL_STATUS;
	zval *value, *minValue_param = NULL, *maxValue_param = NULL, *message = NULL, *propertyPath = NULL, *_1$$3 = NULL, *_2$$3 = NULL, *_4$$3 = NULL, *_5$$3 = NULL, *_6$$3 = NULL, *_7$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &value, &minValue_param, &maxValue_param, &message, &propertyPath);

	minValue = zephir_get_intval(minValue_param);
	maxValue = zephir_get_intval(maxValue_param);
	if (!message) {
		ZEPHIR_CPY_WRT(message, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_STATIC(NULL, "numeric", NULL, 0, value, message, propertyPath);
	zephir_check_call_status();
	_0 = ZEPHIR_LT_LONG(value, minValue);
	if (!(_0)) {
		_0 = ZEPHIR_GT_LONG(value, maxValue);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_1$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(_1$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(_1$$3);
			ZVAL_STRING(_1$$3, "Number \"%s\" was expected to be at least \"%d\" and at most \"%d\".", 1);
		}
		ZEPHIR_CALL_STATIC(&_2$$3, "stringify", &_3, 23, value);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_5$$3);
		ZVAL_LONG(_5$$3, minValue);
		ZEPHIR_CALL_STATIC(&_4$$3, "stringify", &_3, 23, _5$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_5$$3);
		ZVAL_LONG(_5$$3, maxValue);
		ZEPHIR_CALL_STATIC(&_6$$3, "stringify", &_3, 23, _5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&message, "sprintf", NULL, 13, _1$$3, _2$$3, _4$$3, _6$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_8$$3);
		zephir_create_array(_8$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_5$$3);
		ZVAL_LONG(_5$$3, minValue);
		zephir_array_update_string(&_8$$3, SL("min"), &_5$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_5$$3);
		ZVAL_LONG(_5$$3, maxValue);
		zephir_array_update_string(&_8$$3, SL("max"), &_5$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_5$$3);
		ZVAL_LONG(_5$$3, 30);
		ZEPHIR_CALL_STATIC(&_7$$3, "createexception", NULL, 0, value, message, _5$$3, propertyPath, _8$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_7$$3, "phalconplus/Assert/Assertion.zep", 117 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, min) {

	zval *_6$$3;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long minValue, ZEPHIR_LAST_CALL_STATUS;
	zval *value, *minValue_param = NULL, *message = NULL, *propertyPath = NULL, *_0$$3 = NULL, *_1$$3 = NULL, *_3$$3 = NULL, *_4$$3 = NULL, *_5$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &value, &minValue_param, &message, &propertyPath);

	minValue = zephir_get_intval(minValue_param);
	if (!message) {
		ZEPHIR_CPY_WRT(message, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_STATIC(NULL, "numeric", NULL, 0, value, message, propertyPath);
	zephir_check_call_status();
	if (ZEPHIR_LT_LONG(value, minValue)) {
		ZEPHIR_INIT_VAR(_0$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(_0$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(_0$$3);
			ZVAL_STRING(_0$$3, "Number \"%s\" was expected to be at least \"%s\".", 1);
		}
		ZEPHIR_CALL_STATIC(&_1$$3, "stringify", &_2, 23, value);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_LONG(_4$$3, minValue);
		ZEPHIR_CALL_STATIC(&_3$$3, "stringify", &_2, 23, _4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&message, "sprintf", NULL, 13, _0$$3, _1$$3, _3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6$$3);
		zephir_create_array(_6$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_LONG(_4$$3, minValue);
		zephir_array_update_string(&_6$$3, SL("min"), &_4$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_LONG(_4$$3, 35);
		ZEPHIR_CALL_STATIC(&_5$$3, "createexception", NULL, 0, value, message, _4$$3, propertyPath, _6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$3, "phalconplus/Assert/Assertion.zep", 134 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, max) {

	zval *_6$$3;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long maxValue, ZEPHIR_LAST_CALL_STATUS;
	zval *value, *maxValue_param = NULL, *message = NULL, *propertyPath = NULL, *_0$$3 = NULL, *_1$$3 = NULL, *_3$$3 = NULL, *_4$$3 = NULL, *_5$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &value, &maxValue_param, &message, &propertyPath);

	maxValue = zephir_get_intval(maxValue_param);
	if (!message) {
		ZEPHIR_CPY_WRT(message, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_STATIC(NULL, "numeric", NULL, 0, value, message, propertyPath);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(value, maxValue)) {
		ZEPHIR_INIT_VAR(_0$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(_0$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(_0$$3);
			ZVAL_STRING(_0$$3, "Number \"%s\" was expected to be at most \"%s\".", 1);
		}
		ZEPHIR_CALL_STATIC(&_1$$3, "stringify", &_2, 23, value);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_LONG(_4$$3, maxValue);
		ZEPHIR_CALL_STATIC(&_3$$3, "stringify", &_2, 23, _4$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&message, "sprintf", NULL, 13, _0$$3, _1$$3, _3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_6$$3);
		zephir_create_array(_6$$3, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_LONG(_4$$3, maxValue);
		zephir_array_update_string(&_6$$3, SL("max"), &_4$$3, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(_4$$3);
		ZVAL_LONG(_4$$3, 36);
		ZEPHIR_CALL_STATIC(&_5$$3, "createexception", NULL, 0, value, message, _4$$3, propertyPath, _6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_5$$3, "phalconplus/Assert/Assertion.zep", 151 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, isString) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *value, *message = NULL, *propertyPath = NULL, *_0$$3 = NULL, *_1$$3 = NULL, *_3$$3, *_4$$3 = NULL, *_5$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value, &message, &propertyPath);

	if (!message) {
		ZEPHIR_CPY_WRT(message, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = ZEPHIR_GLOBAL(global_null);
	}


	if (!(Z_TYPE_P(value) == IS_STRING)) {
		ZEPHIR_INIT_VAR(_0$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(_0$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(_0$$3);
			ZVAL_STRING(_0$$3, "Value \"%s\" expected to be string, type %s given.", 1);
		}
		ZEPHIR_CALL_STATIC(&_1$$3, "stringify", &_2, 23, value);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_3$$3);
		zephir_gettype(_3$$3, value TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&message, "sprintf", NULL, 13, _0$$3, _1$$3, _3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_5$$3);
		ZVAL_LONG(_5$$3, 16);
		ZEPHIR_CALL_STATIC(&_4$$3, "createexception", NULL, 0, value, message, _5$$3, propertyPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$3, "phalconplus/Assert/Assertion.zep", 165 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, isArray) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *value, *message = NULL, *propertyPath = NULL, *_0$$3 = NULL, *_1$$3 = NULL, *_3$$3 = NULL, *_4$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value, &message, &propertyPath);

	if (!message) {
		ZEPHIR_CPY_WRT(message, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = ZEPHIR_GLOBAL(global_null);
	}


	if (!(Z_TYPE_P(value) == IS_ARRAY)) {
		ZEPHIR_INIT_VAR(_0$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(_0$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(_0$$3);
			ZVAL_STRING(_0$$3, "Value \"%s\" is not an array.", 1);
		}
		ZEPHIR_CALL_STATIC(&_1$$3, "stringify", &_2, 23, value);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&message, "sprintf", NULL, 13, _0$$3, _1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4$$3);
		ZVAL_LONG(_4$$3, 24);
		ZEPHIR_CALL_STATIC(&_3$$3, "createexception", NULL, 0, value, message, _4$$3, propertyPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$3, "phalconplus/Assert/Assertion.zep", 178 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, isJsonString) {

	zend_bool _1;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, *message = NULL, *propertyPath = NULL, *_0, *_2 = NULL, *_3$$3 = NULL, *_4$$3 = NULL, *_6$$3 = NULL, *_7$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &value, &message, &propertyPath);

	if (!message) {
		ZEPHIR_CPY_WRT(message, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!propertyPath) {
		propertyPath = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_STATIC(NULL, "isstring", NULL, 0, value, message, propertyPath);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	zephir_json_decode(_0, &(_0), value, 0  TSRMLS_CC);
	_1 = Z_TYPE_P(_0) == IS_NULL;
	if (_1) {
		ZEPHIR_CALL_FUNCTION(&_2, "json_last_error", NULL, 24);
		zephir_check_call_status();
		_1 = !ZEPHIR_IS_LONG(_2, 0);
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_3$$3);
		if (zephir_is_true(message)) {
			ZEPHIR_CPY_WRT(_3$$3, message);
		} else {
			ZEPHIR_INIT_NVAR(_3$$3);
			ZVAL_STRING(_3$$3, "Value \"%s\" is not a valid JSON string.", 1);
		}
		ZEPHIR_CALL_STATIC(&_4$$3, "stringify", &_5, 23, value);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&message, "sprintf", NULL, 13, _3$$3, _4$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_7$$3);
		ZVAL_LONG(_7$$3, 206);
		ZEPHIR_CALL_STATIC(&_6$$3, "createexception", NULL, 0, value, message, _7$$3, propertyPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6$$3, "phalconplus/Assert/Assertion.zep", 192 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Assert_Assertion, stringify) {

	zval *_1$$5 = NULL;
	zend_bool _6, _7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *value, *_0$$3, *val = NULL, _2$$6, _3$$6, *_4$$6, *_5$$6, *_8$$7, *_9$$7, *_10$$7 = NULL, _11$$8, _12$$8, *_13$$8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if (Z_TYPE_P(value) == IS_BOOL) {
		ZEPHIR_INIT_VAR(_0$$3);
		if (ZEPHIR_IS_TRUE(value)) {
			ZVAL_STRING(_0$$3, "TRUE", 1);
		} else {
			ZVAL_STRING(_0$$3, "FALSE", 1);
		}
		RETURN_CCTOR(_0$$3);
	}
	if (Z_TYPE_P(value) == IS_NULL) {
		RETURN_MM_STRING("NULL", 1);
	}
	if (zephir_is_scalar(value)) {
		zephir_get_strval(_1$$5, value);
		ZEPHIR_CPY_WRT(val, _1$$5);
		if (zephir_fast_strlen_ev(val) > 100) {
			ZEPHIR_SINIT_VAR(_2$$6);
			ZVAL_LONG(&_2$$6, 0);
			ZEPHIR_SINIT_VAR(_3$$6);
			ZVAL_LONG(&_3$$6, 96);
			ZEPHIR_INIT_VAR(_4$$6);
			zephir_substr(_4$$6, val, 0 , 96 , 0);
			ZEPHIR_INIT_VAR(_5$$6);
			ZEPHIR_CONCAT_VS(_5$$6, _4$$6, " ...");
			ZEPHIR_CPY_WRT(val, _5$$6);
		}
		RETURN_CCTOR(val);
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
		ZEPHIR_CALL_FUNCTION(&val, "print_r", NULL, 25, value, ZEPHIR_GLOBAL(global_true));
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_8$$7);
		ZVAL_STRING(_8$$7, "/\\s+/", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_INIT_VAR(_9$$7);
		ZVAL_STRING(_9$$7, " ", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_FUNCTION(&_10$$7, "preg_replace", NULL, 26, _8$$7, _9$$7, val);
		zephir_check_temp_parameter(_8$$7);
		zephir_check_temp_parameter(_9$$7);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(val, _10$$7);
		if (zephir_fast_strlen_ev(val) > 160) {
			ZEPHIR_SINIT_VAR(_11$$8);
			ZVAL_LONG(&_11$$8, 0);
			ZEPHIR_SINIT_VAR(_12$$8);
			ZVAL_LONG(&_12$$8, 156);
			ZEPHIR_INIT_VAR(_13$$8);
			zephir_substr(_13$$8, val, 0 , 156 , 0);
			ZEPHIR_CONCAT_VS(return_value, _13$$8, " ...");
			RETURN_MM();
		}
		RETURN_CCTOR(val);
	}
	RETURN_MM_STRING("unknown", 1);

}

