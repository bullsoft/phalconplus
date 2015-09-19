
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
#include "kernel/concat.h"
#include "kernel/memory.h"
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

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *info = NULL, *logger = NULL, *message = NULL, *args = NULL, *_0, *_1, *_2 = NULL, *_4 = NULL, *_5, *_6, *_7 = NULL, *_8, _9 = zval_used_for_init, *_10, *cnt = NULL, *argsCnt, *_11, *_12;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &info, &logger);

	if (!info) {
		ZEPHIR_INIT_VAR(info);
		ZVAL_STRING(info, "", 1);
	}
	if (!logger) {
		logger = ZEPHIR_GLOBAL(global_null);
	}
	ZEPHIR_INIT_VAR(message);
	ZVAL_STRING(message, "", 1);
	ZEPHIR_INIT_VAR(args);
	array_init(args);


	ZEPHIR_INIT_VAR(_0);
	zephir_get_called_class(_0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(message);
	ZEPHIR_CONCAT_SV(message, "An exception created: ", _0);
	if (ZEPHIR_IS_EMPTY(info)) {
	} else {
		if (Z_TYPE_P(info) == IS_ARRAY) {
			zephir_array_fetch_long(&_1, info, 0, PH_NOISY | PH_READONLY, "phalconplus/Base/Exception.zep", 22 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(&_2, "strval", &_3, 23, _1);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_4);
			ZEPHIR_CONCAT_VSV(_4, message, ", message: ", _2);
			ZEPHIR_CPY_WRT(message, _4);
			ZEPHIR_OBS_NVAR(args);
			if (zephir_array_isset_long_fetch(&args, info, 1, 0 TSRMLS_CC)) {
				zephir_array_fetch_long(&_5, info, 1, PH_NOISY | PH_READONLY, "phalconplus/Base/Exception.zep", 24 TSRMLS_CC);
				if (Z_TYPE_P(_5) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(args);
					zephir_array_fetch_long(&args, info, 1, PH_NOISY, "phalconplus/Base/Exception.zep", 24 TSRMLS_CC);
				} else {
					ZEPHIR_INIT_NVAR(args);
					zephir_create_array(args, 1, 0 TSRMLS_CC);
					zephir_array_fetch_long(&_6, info, 1, PH_NOISY | PH_READONLY, "phalconplus/Base/Exception.zep", 24 TSRMLS_CC);
					ZEPHIR_CALL_FUNCTION(&_7, "strval", &_3, 23, _6);
					zephir_check_call_status();
					zephir_array_fast_append(args, _7);
				}
			}
		} else if (Z_TYPE_P(info) == IS_STRING) {
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_VSV(_4, message, ", message: ", info);
			ZEPHIR_CPY_WRT(message, _4);
		}
	}
	if (!(Z_TYPE_P(logger) == IS_NULL)) {
		ZEPHIR_INIT_VAR(_8);
		ZEPHIR_SINIT_VAR(_9);
		ZVAL_LONG(&_9, 256);
		zephir_json_encode(_8, &(_8), args, zephir_get_intval(&_9)  TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_VSV(_4, message, ", args: ", _8);
		ZEPHIR_CALL_METHOD(&_2, this_ptr, "getlevel", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, logger, "log", NULL, 0, _4, _2);
		zephir_check_call_status();
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("message"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_10)) {
		zephir_update_property_this(this_ptr, SL("message"), message TSRMLS_CC);
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("message"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_9);
	ZVAL_STRING(&_9, "%s", 0);
	ZEPHIR_CALL_FUNCTION(&cnt, "substr_count", NULL, 24, _11, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(argsCnt);
	ZVAL_LONG(argsCnt, zephir_fast_count_int(args TSRMLS_CC));
	if (ZEPHIR_GE(argsCnt, cnt)) {
		_12 = zephir_fetch_nproperty_this(this_ptr, SL("message"), PH_NOISY_CC);
		ZEPHIR_CALL_FUNCTION(&_7, "vsprintf", NULL, 25, _12, args);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("message"), _7 TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_Exception, getLevel) {


	RETURN_MEMBER(this_ptr, "level");

}

PHP_METHOD(PhalconPlus_Base_Exception, setCode) {

	zval *code;

	zephir_fetch_params(0, 1, 0, &code);



	zephir_update_property_this(this_ptr, SL("code"), code TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_Base_Exception, setLevel) {

	zval *level;

	zephir_fetch_params(0, 1, 0, &level);



	zephir_update_property_this(this_ptr, SL("level"), level TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_Base_Exception, setMessage) {

	zval *msg;

	zephir_fetch_params(0, 1, 0, &msg);



	zephir_update_property_this(this_ptr, SL("message"), msg TSRMLS_CC);
	RETURN_THISW();

}

