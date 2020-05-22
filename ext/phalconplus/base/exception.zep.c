
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
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/string.h"


/**
 * throw new Exception("error message");
 * throw new Exception(["error message", "hello"]);
 * throw new Exception(["error message", ["foo", "bar"]]);
 * throw new Exception(["error message", "text" => "", "args" => ["foo", "bar"]]);
 *
 */
ZEPHIR_INIT_CLASS(PhalconPlus_Base_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, Exception, phalconplus, base_exception, zend_exception_get_default(TSRMLS_C), phalconplus_base_exception_method_entry, 0);

	zend_declare_property_long(phalconplus_base_exception_ce, SL("level"), 7, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_base_exception_ce, SL("info"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_Exception, __construct) {

	zend_bool _15, _28;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_13 = NULL;
	zend_long code, ZEPHIR_LAST_CALL_STATUS;
	zval *info, info_sub, *code_param = NULL, message, args, _0, _12, _14, _16, _17, _18, _19, showMessage, _26, cnt, _30, _32, _1$$4, _2$$4, _4$$4, _5$$5, _6$$5, _7$$5, _8$$6, _9$$6, _10$$6, _11$$7, logger$$8, _20$$8, _21$$8, _22$$8, argsJson$$8, _23$$8, _24$$8, _25$$8, _27$$9, _29$$12, _31$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&info_sub);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&showMessage);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&cnt);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&logger$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&argsJson$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_31$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &info, &code_param);

	if (!code_param) {
		code = 0;
	} else {
		code = zephir_get_intval(code_param);
	}


	ZEPHIR_INIT_VAR(&message);
	ZVAL_STRING(&message, "");
	ZEPHIR_INIT_VAR(&args);
	array_init(&args);
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_class(&_0, this_ptr, 0);
	ZEPHIR_INIT_NVAR(&message);
	ZEPHIR_CONCAT_SV(&message, "An exception created: ", &_0);
	if (!(ZEPHIR_IS_EMPTY(info))) {
		if (Z_TYPE_P(info) == IS_ARRAY) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("info"), info);
			zephir_array_fetch_long(&_1$$4, info, 0, PH_NOISY | PH_READONLY, "phalconplus/Base/Exception.zep", 23);
			ZEPHIR_CALL_FUNCTION(&_2$$4, "strval", &_3, 27, &_1$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_4$$4);
			ZEPHIR_CONCAT_VSV(&_4$$4, &message, ", message: ", &_2$$4);
			ZEPHIR_CPY_WRT(&message, &_4$$4);
			ZEPHIR_OBS_NVAR(&args);
			ZEPHIR_OBS_NVAR(&args);
			if (zephir_array_isset_long_fetch(&args, info, 1, 0)) {
				ZEPHIR_INIT_VAR(&_5$$5);
				if (Z_TYPE_P(&args) == IS_ARRAY) {
					ZEPHIR_CPY_WRT(&_5$$5, &args);
				} else {
					ZEPHIR_INIT_VAR(&_6$$5);
					zephir_create_array(&_6$$5, 1, 0);
					ZEPHIR_CALL_FUNCTION(&_7$$5, "strval", &_3, 27, &args);
					zephir_check_call_status();
					zephir_array_fast_append(&_6$$5, &_7$$5);
					ZEPHIR_CPY_WRT(&_5$$5, &_6$$5);
				}
				ZEPHIR_CPY_WRT(&args, &_5$$5);
			} else if (zephir_array_isset_string_fetch(&args, info, SL("args"), 0)) {
				ZEPHIR_INIT_VAR(&_8$$6);
				if (Z_TYPE_P(&args) == IS_ARRAY) {
					ZEPHIR_CPY_WRT(&_8$$6, &args);
				} else {
					ZEPHIR_INIT_VAR(&_9$$6);
					zephir_create_array(&_9$$6, 1, 0);
					ZEPHIR_CALL_FUNCTION(&_10$$6, "strval", &_3, 27, &args);
					zephir_check_call_status();
					zephir_array_fast_append(&_9$$6, &_10$$6);
					ZEPHIR_CPY_WRT(&_8$$6, &_9$$6);
				}
				ZEPHIR_CPY_WRT(&args, &_8$$6);
			}
		} else if (Z_TYPE_P(info) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_11$$7);
			ZEPHIR_CONCAT_VSV(&_11$$7, &message, ", message: ", info);
			ZEPHIR_CPY_WRT(&message, &_11$$7);
		}
	}
	ZEPHIR_CALL_CE_STATIC(&_12, phalconplus_enum_sys_ce, "app", &_13, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_14, &_12, "isbooted", NULL, 0);
	zephir_check_call_status();
	_15 = zephir_is_true(&_14);
	if (_15) {
		ZEPHIR_CALL_CE_STATIC(&_16, phalconplus_enum_sys_ce, "app", &_13, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_17, &_16, "di", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_19);
		ZVAL_STRING(&_19, "logger");
		ZEPHIR_CALL_METHOD(&_18, &_17, "has", NULL, 0, &_19);
		zephir_check_call_status();
		_15 = zephir_is_true(&_18);
	}
	if (_15) {
		ZEPHIR_CALL_CE_STATIC(&_20$$8, phalconplus_enum_sys_ce, "app", &_13, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_21$$8, &_20$$8, "di", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_22$$8);
		ZVAL_STRING(&_22$$8, "logger");
		ZEPHIR_CALL_METHOD(&logger$$8, &_21$$8, "get", NULL, 0, &_22$$8);
		zephir_check_call_status();
		ZVAL_LONG(&_23$$8, 256);
		ZEPHIR_INIT_VAR(&argsJson$$8);
		zephir_json_encode(&argsJson$$8, &args, zephir_get_intval(&_23$$8) );
		ZEPHIR_INIT_VAR(&_24$$8);
		ZEPHIR_CONCAT_VSV(&_24$$8, &message, ", args: ", &argsJson$$8);
		ZEPHIR_CALL_METHOD(&_25$$8, this_ptr, "getlevel", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &logger$$8, "log", NULL, 0, &_24$$8, &_25$$8);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&showMessage);
	zephir_read_property(&_26, this_ptr, ZEND_STRL("message"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string_fetch(&showMessage, info, SL("text"), 0)) {
		ZEPHIR_CALL_FUNCTION(&_27$$9, "strval", &_3, 27, &showMessage);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&showMessage, &_27$$9);
	} else if (!(ZEPHIR_IS_EMPTY(&_26))) {
		ZEPHIR_OBS_NVAR(&showMessage);
		zephir_read_property(&showMessage, this_ptr, ZEND_STRL("message"), PH_NOISY_CC);
	} else {
		ZEPHIR_CPY_WRT(&showMessage, &message);
	}
	ZEPHIR_INIT_NVAR(&_19);
	ZVAL_STRING(&_19, "%s");
	ZEPHIR_CALL_FUNCTION(&cnt, "substr_count", NULL, 28, &showMessage, &_19);
	zephir_check_call_status();
	_28 = ZEPHIR_GT_LONG(&cnt, 0);
	if (_28) {
		_28 = ZEPHIR_LE_LONG(&cnt, zephir_fast_count_int(&args));
	}
	if (_28) {
		ZEPHIR_CALL_FUNCTION(&_29$$12, "vsprintf", NULL, 29, &showMessage, &args);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&showMessage, &_29$$12);
	}
	zephir_read_property(&_30, this_ptr, ZEND_STRL("code"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_GT_LONG(&_30, 0)) {
		zephir_read_property(&_31$$13, this_ptr, ZEND_STRL("code"), PH_NOISY_CC | PH_READONLY);
		code = zephir_get_numberval(&_31$$13);
	}
	ZVAL_LONG(&_32, code);
	ZEPHIR_CALL_PARENT(NULL, phalconplus_base_exception_ce, getThis(), "__construct", NULL, 0, &showMessage, &_32);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_Exception, getLevel) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "level");

}

PHP_METHOD(PhalconPlus_Base_Exception, setLevel) {

	zval *level, level_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &level);



	zephir_update_property_zval(this_ptr, ZEND_STRL("level"), level);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_Base_Exception, getInfo) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "info");

}

