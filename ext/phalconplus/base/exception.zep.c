
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
 * throw new Exception(["error message", ["foo", "bar"]]);
 *
 */
ZEPHIR_INIT_CLASS(PhalconPlus_Base_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, Exception, phalconplus, base_exception, zend_exception_get_default(TSRMLS_C), phalconplus_base_exception_method_entry, 0);

	zend_declare_property_string(phalconplus_base_exception_ce, SL("message"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalconplus_base_exception_ce, SL("level"), 7, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalconplus_base_exception_ce, SL("code"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_Exception, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *info = NULL, info_sub, *logger = NULL, logger_sub, __$null, message, args, _0, _12, cnt, argsCnt, _13, _14, _1$$4, _2$$4, _3$$4, _4$$5, _5$$5, _6$$5, _7$$6, _8$$7, _9$$7, _10$$7, _11$$7, _15$$9, _16$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&info_sub);
	ZVAL_UNDEF(&logger_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&cnt);
	ZVAL_UNDEF(&argsCnt);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &info, &logger);

	if (!info) {
		info = &info_sub;
		ZEPHIR_INIT_VAR(info);
		ZVAL_STRING(info, "");
	}
	if (!logger) {
		logger = &logger_sub;
		logger = &__$null;
	}


	ZEPHIR_INIT_VAR(&message);
	ZVAL_STRING(&message, "");
	ZEPHIR_INIT_VAR(&args);
	array_init(&args);
	ZEPHIR_INIT_VAR(&_0);
	zephir_get_called_class(&_0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&message);
	ZEPHIR_CONCAT_SV(&message, "An exception created: ", &_0);
	if (ZEPHIR_IS_EMPTY(info)) {
	} else {
		if (Z_TYPE_P(info) == IS_ARRAY) {
			zephir_array_fetch_long(&_1$$4, info, 0, PH_NOISY | PH_READONLY, "phalconplus/Base/Exception.zep", 22 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_2$$4, "strval", NULL, 27, &_1$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_3$$4);
			ZEPHIR_CONCAT_VSV(&_3$$4, &message, ", message: ", &_2$$4);
			ZEPHIR_CPY_WRT(&message, &_3$$4);
			ZEPHIR_OBS_NVAR(&args);
			if (zephir_array_isset_long_fetch(&args, info, 1, 0 TSRMLS_CC)) {
				zephir_array_fetch_long(&_4$$5, info, 1, PH_NOISY | PH_READONLY, "phalconplus/Base/Exception.zep", 24 TSRMLS_CC);
				if (Z_TYPE_P(&_4$$5) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&args);
					zephir_array_fetch_long(&args, info, 1, PH_NOISY, "phalconplus/Base/Exception.zep", 24 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_NVAR(&args);
					zephir_create_array(&args, 1, 0 TSRMLS_CC);
					zephir_array_fetch_long(&_5$$5, info, 1, PH_NOISY | PH_READONLY, "phalconplus/Base/Exception.zep", 24 TSRMLS_CC);
					ZEPHIR_CALL_FUNCTION(&_6$$5, "strval", NULL, 27, &_5$$5);
					zephir_check_call_status();
					zephir_array_fast_append(&args, &_6$$5);
				}
			}
		} else if (Z_TYPE_P(info) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_7$$6);
			ZEPHIR_CONCAT_VSV(&_7$$6, &message, ", message: ", info);
			ZEPHIR_CPY_WRT(&message, &_7$$6);
		}
	}
	if (!(Z_TYPE_P(logger) == IS_NULL)) {
		ZEPHIR_INIT_VAR(&_8$$7);
		ZVAL_LONG(&_9$$7, 256);
		zephir_json_encode(&_8$$7, &args, zephir_get_intval(&_9$$7) );
		ZEPHIR_INIT_VAR(&_10$$7);
		ZEPHIR_CONCAT_VSV(&_10$$7, &message, ", args: ", &_8$$7);
		ZEPHIR_CALL_METHOD(&_11$$7, this_ptr, "getlevel", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, logger, "log", NULL, 0, &_10$$7, &_11$$7);
		zephir_check_call_status();
	}
	zephir_read_property(&_12, this_ptr, SL("message"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_12)) {
		zephir_update_property_zval(this_ptr, SL("message"), &message);
	}
	zephir_read_property(&_13, this_ptr, SL("message"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "%s");
	ZEPHIR_CALL_FUNCTION(&cnt, "substr_count", NULL, 28, &_13, &_14);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&argsCnt);
	ZVAL_LONG(&argsCnt, zephir_fast_count_int(&args TSRMLS_CC));
	if (ZEPHIR_GE(&argsCnt, &cnt)) {
		zephir_read_property(&_15$$9, this_ptr, SL("message"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_16$$9, "vsprintf", NULL, 29, &_15$$9, &args);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("message"), &_16$$9);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_Exception, getLevel) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "level");

}

PHP_METHOD(PhalconPlus_Base_Exception, setCode) {

	zval *code, code_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&code_sub);

	zephir_fetch_params(0, 1, 0, &code);



	zephir_update_property_zval(this_ptr, SL("code"), code);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_Base_Exception, setLevel) {

	zval *level, level_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level_sub);

	zephir_fetch_params(0, 1, 0, &level);



	zephir_update_property_zval(this_ptr, SL("level"), level);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_Base_Exception, setMessage) {

	zval *msg, msg_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&msg_sub);

	zephir_fetch_params(0, 1, 0, &msg);



	zephir_update_property_zval(this_ptr, SL("message"), msg);
	RETURN_THISW();

}

