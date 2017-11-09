
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
#include "kernel/object.h"


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
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 22, message, code, propertyPath, value, &constraints);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Assert_Assertion, eq) {

	zval _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *value, value_sub, *value2, value2_sub, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, v1$$3, v2$$3, _1$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
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
	zephir_fetch_params(1, 2, 2, &value, &value2, &message, &propertyPath);

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


	if (!ZEPHIR_IS_EQUAL(value, value2)) {
		ZEPHIR_CALL_SELF(&v1$$3, "stringify", &_0, 23, value);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(&v2$$3, "stringify", &_0, 23, value2);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_NULL) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVSVS(message, "Value ", &v1$$3, " does not equal expected value ", &v2$$3, ".");
		}
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_2$$3, SL("expected"), value2, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_3$$3, 34);
		ZEPHIR_CALL_STATIC(&_1$$3, "createexception", NULL, 0, value, message, &_3$$3, propertyPath, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Assert/Assertion.zep", 28 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Assert_Assertion, same) {

	zval _2$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *value, value_sub, *value2, value2_sub, *message = NULL, message_sub, *propertyPath = NULL, propertyPath_sub, __$null, v1$$3, v2$$3, _1$$3, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
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
	zephir_fetch_params(1, 2, 2, &value, &value2, &message, &propertyPath);

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


	if (!ZEPHIR_IS_IDENTICAL(value, value2)) {
		ZEPHIR_CALL_SELF(&v1$$3, "stringify", &_0, 23, value);
		zephir_check_call_status();
		ZEPHIR_CALL_SELF(&v2$$3, "stringify", &_0, 23, value2);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_NULL) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVSVS(message, "Value ", &v1$$3, " does not equal expected value ", &v2$$3, ".");
		}
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_2$$3, SL("expected"), value2, PH_COPY | PH_SEPARATE);
		ZVAL_LONG(&_3$$3, 33);
		ZEPHIR_CALL_STATIC(&_1$$3, "createexception", NULL, 0, value, message, &_3$$3, propertyPath, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Assert/Assertion.zep", 43 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Assert_Assertion, notEmpty) {

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
		ZEPHIR_CALL_SELF(&v1$$3, "stringify", &_0, 23, value);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_NULL) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVS(message, "Value ", &v1$$3, " is empty, but non empty value was expected.");
		}
		ZVAL_LONG(&_2$$3, 14);
		ZEPHIR_CALL_STATIC(&_1$$3, "createexception", NULL, 0, value, message, &_2$$3, propertyPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Assert/Assertion.zep", 56 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Assert_Assertion, notNull) {

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
		ZEPHIR_CALL_SELF(&v1$$3, "stringify", &_0, 23, value);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_NULL) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVS(message, "Value ", &v1$$3, " is null, but non null value was expected.");
		}
		ZVAL_LONG(&_2$$3, 15);
		ZEPHIR_CALL_STATIC(&_1$$3, "createexception", NULL, 0, value, message, &_2$$3, propertyPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Assert/Assertion.zep", 68 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Assert_Assertion, numeric) {

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
		ZEPHIR_CALL_SELF(&v1$$3, "stringify", &_0, 23, value);
		zephir_check_call_status();
		if (Z_TYPE_P(message) == IS_NULL) {
			ZEPHIR_INIT_NVAR(message);
			ZEPHIR_CONCAT_SVS(message, "Value ", &v1$$3, " is not numeric");
		}
		ZVAL_LONG(&_2$$3, 23);
		ZEPHIR_CALL_STATIC(&_1$$3, "createexception", NULL, 0, value, message, &_2$$3, propertyPath);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Assert/Assertion.zep", 80 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Assert_Assertion, stringify) {

	zval _1$$4;
	zval *value, value_sub, _0$$3, val, _2$$5, _3$$5, _4$$5, _5$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &value);



	if ((Z_TYPE_P(value) == IS_TRUE || Z_TYPE_P(value) == IS_FALSE)) {
		ZEPHIR_INIT_VAR(&_0$$3);
		if (zephir_is_true(value)) {
			ZVAL_STRING(&_0$$3, "<TRUE>");
		} else {
			ZVAL_STRING(&_0$$3, "<FALSE>");
		}
		RETURN_CCTOR(&_0$$3);
	}
	if (zephir_is_scalar(value)) {
		zephir_get_strval(&_1$$4, value);
		ZEPHIR_CPY_WRT(&val, &_1$$4);
		if (zephir_fast_strlen_ev(&val) > 100) {
			ZVAL_LONG(&_2$$5, 0);
			ZVAL_LONG(&_3$$5, 97);
			ZEPHIR_INIT_VAR(&_4$$5);
			zephir_substr(&_4$$5, &val, 0 , 97 , 0);
			ZEPHIR_INIT_VAR(&_5$$5);
			ZEPHIR_CONCAT_VS(&_5$$5, &_4$$5, "...");
			ZEPHIR_CPY_WRT(&val, &_5$$5);
		}
		RETURN_CCTOR(&val);
	}
	if (Z_TYPE_P(value) == IS_ARRAY) {
		RETURN_MM_STRING("<ARRAY>");
	}
	if (Z_TYPE_P(value) == IS_OBJECT) {
		zephir_get_class(return_value, value, 0 TSRMLS_CC);
		RETURN_MM();
	}
	if (Z_TYPE_P(value) == IS_RESOURCE) {
		RETURN_MM_STRING("<RESOURCE>");
	}
	if (Z_TYPE_P(value) == IS_NULL) {
		RETURN_MM_STRING("<NULL>");
	}
	RETURN_MM_STRING("unknown");

}

