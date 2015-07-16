
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/hash.h"
#include "kernel/array.h"

ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Formatter_LinePlus) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Logger\\Formatter, LinePlus, phalconplus, logger_formatter_lineplus, zephir_get_internal_ce(SS("phalcon\\logger\\formatter") TSRMLS_CC), phalconplus_logger_formatter_lineplus_method_entry, 0);

	zend_declare_property_null(phalconplus_logger_formatter_lineplus_ce, SL("processors"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(phalconplus_logger_formatter_lineplus_ce, SL("formatString"), "[%date%][%type%] %message%", ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(phalconplus_logger_formatter_lineplus_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("phalcon\\logger\\formatterinterface") TSRMLS_CC));
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Logger_Formatter_LinePlus, __construct) {

	zval *formatString_param = NULL;
	zval *formatString = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &formatString_param);

	if (unlikely(Z_TYPE_P(formatString_param) != IS_STRING && Z_TYPE_P(formatString_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'formatString' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(formatString_param) == IS_STRING)) {
		zephir_get_strval(formatString, formatString_param);
	} else {
		ZEPHIR_INIT_VAR(formatString);
		ZVAL_EMPTY_STRING(formatString);
	}


	if (EG(called_scope) == phalconplus_logger_formatter_lineplus_ce) {
		zephir_init_properties(this_ptr TSRMLS_CC);
	}
	if (!(ZEPHIR_IS_EMPTY(formatString))) {
		zephir_update_property_this(this_ptr, SL("formatString"), formatString TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Formatter_LinePlus, format) {

	zephir_fcall_cache_entry *_12 = NULL;
	HashTable *_10;
	HashPosition _9;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *type, *date, *context = NULL, *_0, _1 = zval_used_for_init, *_2 = NULL, *_3, *_4, *matches, *result, *_5, *_6 = NULL, *_7, *_8, *replace0 = NULL, *replace1 = NULL, *val1 = NULL, *val2 = NULL, *processors, **_11, *logStr, *_13 = NULL;
	zval *message = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &message_param, &type, &date, &context);

	if (unlikely(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(message, message_param);
	} else {
		ZEPHIR_INIT_VAR(message);
		ZVAL_EMPTY_STRING(message);
	}
	if (!context) {
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	}
	ZEPHIR_INIT_VAR(matches);
	array_init(matches);
	ZEPHIR_INIT_VAR(processors);
	array_init(processors);


	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "message", 1);
	zephir_update_property_array(this_ptr, SL("processors"), _0, message TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "Y-m-d H:i:s", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "date", NULL, 10, &_1, date);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "date", 1);
	zephir_update_property_array(this_ptr, SL("processors"), _3, _2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "gettypestring", NULL, 0, type);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "type", 1);
	zephir_update_property_array(this_ptr, SL("processors"), _4, _2 TSRMLS_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("formatString"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "/%(\\w+)%/", 0);
	ZEPHIR_INIT_VAR(result);
	zephir_preg_match(result, &_1, _5, matches, 1, 0 , 0  TSRMLS_CC);
	if (ZEPHIR_IS_FALSE(result)) {
		ZEPHIR_INIT_VAR(_6);
		object_init_ex(_6, spl_ce_InvalidArgumentException);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("formatString"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_8);
		ZEPHIR_CONCAT_SV(_8, "Logger format is not valid: ", _7);
		ZEPHIR_CALL_METHOD(NULL, _6, "__construct", NULL, 45, _8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_6, "phalconplus/Logger/Formatter/LinePlus.zep", 29 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	Z_SET_ISREF_P(matches);
	ZEPHIR_CALL_FUNCTION(&replace0, "reset", NULL, 51, matches);
	Z_UNSET_ISREF_P(matches);
	zephir_check_call_status();
	Z_SET_ISREF_P(matches);
	ZEPHIR_CALL_FUNCTION(&replace1, "end", NULL, 8, matches);
	Z_UNSET_ISREF_P(matches);
	zephir_check_call_status();
	zephir_is_iterable(replace1, &_10, &_9, 0, 0, "phalconplus/Logger/Formatter/LinePlus.zep", 46);
	for (
	  ; zephir_hash_get_current_data_ex(_10, (void**) &_11, &_9) == SUCCESS
	  ; zephir_hash_move_forward_ex(_10, &_9)
	) {
		ZEPHIR_GET_HVALUE(val1, _11);
		ZEPHIR_OBS_NVAR(val2);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("processors"), PH_NOISY_CC);
		if (zephir_array_isset_fetch(&val2, _7, val1, 0 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_2, "strval", &_12, 4, val2);
			zephir_check_call_status();
			zephir_array_update_zval(&processors, val1, &_2, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_NVAR(_6);
			ZVAL_STRING(_6, "undefined", 1);
			zephir_array_update_zval(&processors, val1, &_6, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_FUNCTION(&_13, "array_values", NULL, 48, processors);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("formatString"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(logStr);
	zephir_fast_str_replace(&logStr, replace0, _13, _7 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_6);
	ZEPHIR_GET_CONSTANT(_6, "PHP_EOL");
	ZEPHIR_CONCAT_VV(return_value, logStr, _6);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Logger_Formatter_LinePlus, addProcessor) {

	zval *name_param = NULL, *processor;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &processor);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}


	zephir_update_property_array(this_ptr, SL("processors"), name, processor TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Formatter_LinePlus, __get) {

	zval *key_param = NULL, *_0, *_1;
	zval *key = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("processors"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_array_fetch(&_1, _0, key, PH_NOISY, "phalconplus/Logger/Formatter/LinePlus.zep", 58 TSRMLS_CC);
	zephir_get_strval(_2, _1);
	RETURN_CTOR(_2);

}

static void zephir_init_properties(zval *this_ptr TSRMLS_DC) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	array_init(_0);
	zephir_update_property_this(this_ptr, SL("processors"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

