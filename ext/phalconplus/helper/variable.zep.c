
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Helper_Variable) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Helper, Variable, phalconplus, helper_variable, phalconplus_helper_variable_method_entry, 0);

	zephir_declare_class_constant_string(phalconplus_helper_variable_ce, SL("NULL_VALUE"), "$Ph/Var/SoftNull$");

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Helper_Variable, softNull) {

	zval *this_ptr = getThis();


	RETURN_STRING("$Ph/Var/SoftNull$");

}

PHP_METHOD(PhalconPlus_Helper_Variable, isSoftNull) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *nil_param = NULL, _0;
	zval nil;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&nil);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &nil_param);

	zephir_get_strval(&nil, nil_param);


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "$Ph/Var/SoftNull$");
	RETURN_MM_BOOL(ZEPHIR_IS_IDENTICAL(&_0, &nil));

}

/**
 * if $a is null, exception will be thrown
 *
 * Variable::notNull($a)->callMethod()
 */
PHP_METHOD(PhalconPlus_Helper_Variable, notNull) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *val, val_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&val_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &val);



	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "notnull", &_0, 0, val);
	zephir_check_call_status();
	RETVAL_ZVAL(val, 1, 0);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Helper_Variable, notEmpty) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *val, val_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&val_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &val);



	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "notempty", &_0, 0, val);
	zephir_check_call_status();
	RETVAL_ZVAL(val, 1, 0);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Helper_Variable, isInt) {

	zval *input, input_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &input);



	RETURN_BOOL(Z_TYPE_P(input) == IS_LONG);

}

PHP_METHOD(PhalconPlus_Helper_Variable, isArray) {

	zval *input, input_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &input);



	RETURN_BOOL(Z_TYPE_P(input) == IS_ARRAY);

}

PHP_METHOD(PhalconPlus_Helper_Variable, isObject) {

	zval *input, input_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &input);



	RETURN_BOOL(Z_TYPE_P(input) == IS_OBJECT);

}

PHP_METHOD(PhalconPlus_Helper_Variable, isBool) {

	zval *input, input_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &input);



	RETURN_BOOL(((Z_TYPE_P(input) == IS_TRUE || Z_TYPE_P(input) == IS_FALSE) == 1));

}

PHP_METHOD(PhalconPlus_Helper_Variable, isString) {

	zval *input, input_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &input);



	RETURN_BOOL(Z_TYPE_P(input) == IS_STRING);

}

PHP_METHOD(PhalconPlus_Helper_Variable, isNull) {

	zval *input, input_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &input);



	RETURN_BOOL(Z_TYPE_P(input) == IS_NULL);

}

PHP_METHOD(PhalconPlus_Helper_Variable, isFloat) {

	zval *input, input_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &input);



	RETURN_BOOL(Z_TYPE_P(input) == IS_DOUBLE);

}

PHP_METHOD(PhalconPlus_Helper_Variable, isFunctional) {

	zval *input, input_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&input_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &input);



	RETURN_BOOL(zephir_is_callable(input) == 1);

}

PHP_METHOD(PhalconPlus_Helper_Variable, stringify) {

	zval _1$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool full, _7, _8, _2$$5, _12$$7;
	zval *value, value_sub, *full_param = NULL, __$true, _0$$3, val, _3$$6, _4$$6, _5$$6, _6$$6, _9$$7, _10$$7, _11$$7, _13$$8, _14$$8, _15$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_3$$6);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_1$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &full_param);

	if (!full_param) {
		full = 0;
	} else {
		full = zephir_get_boolval(full_param);
	}


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
	ZEPHIR_INIT_VAR(&val);
	ZVAL_STRING(&val, "");
	if (zephir_is_scalar(value)) {
		zephir_get_strval(&_1$$5, value);
		ZEPHIR_CPY_WRT(&val, &_1$$5);
		_2$$5 = full == 0;
		if (_2$$5) {
			_2$$5 = zephir_fast_strlen_ev(&val) > 100;
		}
		if (_2$$5) {
			ZVAL_LONG(&_3$$6, 0);
			ZVAL_LONG(&_4$$6, 96);
			ZEPHIR_INIT_VAR(&_5$$6);
			zephir_substr(&_5$$6, &val, 0 , 96 , 0);
			ZEPHIR_INIT_VAR(&_6$$6);
			ZEPHIR_CONCAT_VS(&_6$$6, &_5$$6, " ...");
			ZEPHIR_CPY_WRT(&val, &_6$$6);
		}
		RETURN_CCTOR(&val);
	}
	_7 = Z_TYPE_P(value) == IS_ARRAY;
	if (!(_7)) {
		_7 = Z_TYPE_P(value) == IS_OBJECT;
	}
	_8 = _7;
	if (!(_8)) {
		_8 = Z_TYPE_P(value) == IS_RESOURCE;
	}
	if (_8) {
		ZEPHIR_CALL_FUNCTION(&val, "print_r", NULL, 136, value, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_9$$7);
		ZVAL_STRING(&_9$$7, "/\\s+/");
		ZEPHIR_INIT_VAR(&_10$$7);
		ZVAL_STRING(&_10$$7, " ");
		ZEPHIR_CALL_FUNCTION(&_11$$7, "preg_replace", NULL, 137, &_9$$7, &_10$$7, &val);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&val, &_11$$7);
		_12$$7 = full == 0;
		if (_12$$7) {
			_12$$7 = zephir_fast_strlen_ev(&val) > 260;
		}
		if (_12$$7) {
			ZVAL_LONG(&_13$$8, 0);
			ZVAL_LONG(&_14$$8, 256);
			ZEPHIR_INIT_VAR(&_15$$8);
			zephir_substr(&_15$$8, &val, 0 , 256 , 0);
			ZEPHIR_CONCAT_VS(return_value, &_15$$8, " ...");
			RETURN_MM();
		}
		RETURN_CCTOR(&val);
	}
	RETURN_MM_STRING("unknown");

}

