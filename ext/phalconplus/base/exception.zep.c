
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
#include "kernel/concat.h"
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

	zend_declare_property_string(phalconplus_base_exception_ce, SL("message"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_long(phalconplus_base_exception_ce, SL("level"), 7, ZEND_ACC_PROTECTED);

	zend_declare_property_long(phalconplus_base_exception_ce, SL("code"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_base_exception_ce, SL("info"), ZEND_ACC_PROTECTED);

	phalconplus_base_exception_ce->create_object = zephir_init_properties_PhalconPlus_Base_Exception;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_Exception, getInfo) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "info");

}

PHP_METHOD(PhalconPlus_Base_Exception, __construct) {

	zval _10$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *info = NULL, info_sub, *logger = NULL, logger_sub, __$null, message, args, _0, _15, cnt, argsCnt, _16, _17, _1$$4, _2$$4, _3$$4, _4$$5, _5$$5, _6$$5, _7$$5, _8$$6, _11$$7, _12$$7, _13$$7, _14$$7, _18$$9, _19$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&info_sub);
	ZVAL_UNDEF(&logger_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&cnt);
	ZVAL_UNDEF(&argsCnt);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_10$$7);

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
	zephir_get_called_class(&_0);
	ZEPHIR_INIT_NVAR(&message);
	ZEPHIR_CONCAT_SV(&message, "An exception created: ", &_0);
	if (ZEPHIR_IS_EMPTY(info)) {
	} else {
		if (Z_TYPE_P(info) == IS_ARRAY) {
			zephir_update_property_zval(this_ptr, SL("info"), info);
			zephir_array_fetch_long(&_1$$4, info, 0, PH_NOISY | PH_READONLY, "phalconplus/Base/Exception.zep", 25);
			ZEPHIR_CALL_FUNCTION(&_2$$4, "strval", NULL, 22, &_1$$4);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_3$$4);
			ZEPHIR_CONCAT_VSV(&_3$$4, &message, ", message: ", &_2$$4);
			ZEPHIR_CPY_WRT(&message, &_3$$4);
			ZEPHIR_OBS_NVAR(&args);
			if (zephir_array_isset_long_fetch(&args, info, 1, 0)) {
				zephir_array_fetch_long(&_4$$5, info, 1, PH_NOISY | PH_READONLY, "phalconplus/Base/Exception.zep", 27);
				if (Z_TYPE_P(&_4$$5) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&args);
					zephir_array_fetch_long(&args, info, 1, PH_NOISY, "phalconplus/Base/Exception.zep", 27);
				} else {
					ZEPHIR_INIT_VAR(&_5$$5);
					zephir_create_array(&_5$$5, 1, 0);
					zephir_array_fetch_long(&_6$$5, info, 1, PH_NOISY | PH_READONLY, "phalconplus/Base/Exception.zep", 27);
					ZEPHIR_CALL_FUNCTION(&_7$$5, "strval", NULL, 22, &_6$$5);
					zephir_check_call_status();
					zephir_array_fast_append(&_5$$5, &_7$$5);
					ZEPHIR_CPY_WRT(&args, &_5$$5);
				}
			}
		} else if (Z_TYPE_P(info) == IS_STRING) {
			ZEPHIR_INIT_VAR(&_8$$6);
			ZEPHIR_CONCAT_VSV(&_8$$6, &message, ", message: ", info);
			ZEPHIR_CPY_WRT(&message, &_8$$6);
		}
	}
	if (!(Z_TYPE_P(logger) == IS_NULL)) {
		ZEPHIR_INIT_VAR(&_10$$7);
		zephir_create_array(&_10$$7, 2, 0);
		ZEPHIR_INIT_VAR(&_11$$7);
		ZVAL_STRING(&_11$$7, "\\Phalcon\\Logger\\Adapter");
		zephir_array_fast_append(&_10$$7, &_11$$7);
		ZEPHIR_INIT_NVAR(&_11$$7);
		ZVAL_STRING(&_11$$7, "\\Phalcon\\Logger\\Multiple");
		zephir_array_fast_append(&_10$$7, &_11$$7);
		ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "isinstanceof", &_9, 0, logger, &_10$$7);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_11$$7);
		ZVAL_LONG(&_12$$7, 256);
		zephir_json_encode(&_11$$7, &args, zephir_get_intval(&_12$$7) );
		ZEPHIR_INIT_VAR(&_13$$7);
		ZEPHIR_CONCAT_VSV(&_13$$7, &message, ", args: ", &_11$$7);
		ZEPHIR_CALL_METHOD(&_14$$7, this_ptr, "getlevel", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, logger, "log", NULL, 0, &_13$$7, &_14$$7);
		zephir_check_call_status();
	}
	zephir_read_property(&_15, this_ptr, SL("message"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_15)) {
		zephir_update_property_zval(this_ptr, SL("message"), &message);
	}
	zephir_read_property(&_16, this_ptr, SL("message"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_17);
	ZVAL_STRING(&_17, "%s");
	ZEPHIR_CALL_FUNCTION(&cnt, "substr_count", NULL, 23, &_16, &_17);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&argsCnt);
	ZVAL_LONG(&argsCnt, zephir_fast_count_int(&args));
	if (ZEPHIR_GE(&argsCnt, &cnt)) {
		zephir_read_property(&_18$$9, this_ptr, SL("message"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_19$$9, "vsprintf", NULL, 24, &_18$$9, &args);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("message"), &_19$$9);
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

	zephir_fetch_params_without_memory_grow(1, 0, &code);



	zephir_update_property_zval(this_ptr, SL("code"), code);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_Base_Exception, setLevel) {

	zval *level, level_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&level_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &level);



	zephir_update_property_zval(this_ptr, SL("level"), level);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_Base_Exception, setMessage) {

	zval *msg, msg_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&msg_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &msg);



	zephir_update_property_zval(this_ptr, SL("message"), msg);
	RETURN_THISW();

}

zend_object *zephir_init_properties_PhalconPlus_Base_Exception(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("info"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("info"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

