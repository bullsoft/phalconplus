
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
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Formatter_LinePlus) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Logger\\Formatter, LinePlus, phalconplus, logger_formatter_lineplus, zephir_get_internal_ce(SL("phalcon\\logger\\formatter")), phalconplus_logger_formatter_lineplus_method_entry, 0);

	zend_declare_property_null(phalconplus_logger_formatter_lineplus_ce, SL("processors"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_string(phalconplus_logger_formatter_lineplus_ce, SL("formatString"), "[%date%][%type%] %message%", ZEND_ACC_PRIVATE TSRMLS_CC);

	phalconplus_logger_formatter_lineplus_ce->create_object = zephir_init_properties_PhalconPlus_Logger_Formatter_LinePlus;

	zend_class_implements(phalconplus_logger_formatter_lineplus_ce TSRMLS_CC, 1, zephir_get_internal_ce(SL("phalcon\\logger\\formatterinterface")));
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Logger_Formatter_LinePlus, __construct) {

	zval *formatString_param = NULL;
	zval formatString;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&formatString);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &formatString_param);

	if (UNEXPECTED(Z_TYPE_P(formatString_param) != IS_STRING && Z_TYPE_P(formatString_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'formatString' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(formatString_param) == IS_STRING)) {
		zephir_get_strval(&formatString, formatString_param);
	} else {
		ZEPHIR_INIT_VAR(&formatString);
		ZVAL_EMPTY_STRING(&formatString);
	}


	if (!(ZEPHIR_IS_EMPTY(&formatString))) {
		zephir_update_property_zval(this_ptr, SL("formatString"), &formatString);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Formatter_LinePlus, format) {

	zephir_fcall_cache_entry *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, *type, type_sub, *date, date_sub, *context = NULL, context_sub, _0, _1, _2, _3, matches, result, _4, _5, replace0, replace1, val1, val2, processors, *_9, logStr, _14, _15, _6$$3, _7$$3, _8$$3, _10$$4, _11$$5, _13$$6;
	zval message;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&type_sub);
	ZVAL_UNDEF(&date_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&replace0);
	ZVAL_UNDEF(&replace1);
	ZVAL_UNDEF(&val1);
	ZVAL_UNDEF(&val2);
	ZVAL_UNDEF(&processors);
	ZVAL_UNDEF(&logStr);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &message_param, &type, &date, &context);

	if (UNEXPECTED(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}
	if (!context) {
		context = &context_sub;
		ZEPHIR_INIT_VAR(context);
		array_init(context);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "message");
	zephir_update_property_array(this_ptr, SL("processors"), &_0, &message TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Y-m-d H:i:s");
	ZEPHIR_CALL_FUNCTION(&_2, "date", NULL, 30, &_1, date);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "date");
	zephir_update_property_array(this_ptr, SL("processors"), &_1, &_2 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "gettypestring", NULL, 0, type);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "type");
	zephir_update_property_array(this_ptr, SL("processors"), &_3, &_2 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&matches);
	array_init(&matches);
	zephir_read_property(&_4, this_ptr, SL("formatString"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "/%(\\w+)%/");
	ZEPHIR_INIT_VAR(&result);
	zephir_preg_match(&result, &_5, &_4, &matches, 1, 0 , 0  TSRMLS_CC);
	if (ZEPHIR_IS_FALSE(&result)) {
		ZEPHIR_INIT_VAR(&_6$$3);
		object_init_ex(&_6$$3, spl_ce_InvalidArgumentException);
		zephir_read_property(&_7$$3, this_ptr, SL("formatString"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_8$$3);
		ZEPHIR_CONCAT_SV(&_8$$3, "Logger format is not valid: ", &_7$$3);
		ZEPHIR_CALL_METHOD(NULL, &_6$$3, "__construct", NULL, 15, &_8$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$3, "phalconplus/Logger/Formatter/LinePlus.zep", 29 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MAKE_REF(&matches);
	ZEPHIR_CALL_FUNCTION(&replace0, "reset", NULL, 38, &matches);
	ZEPHIR_UNREF(&matches);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&matches);
	ZEPHIR_CALL_FUNCTION(&replace1, "end", NULL, 28, &matches);
	ZEPHIR_UNREF(&matches);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&processors);
	array_init(&processors);
	zephir_is_iterable(&replace1, 0, "phalconplus/Logger/Formatter/LinePlus.zep", 46);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&replace1), _9)
	{
		ZEPHIR_INIT_NVAR(&val1);
		ZVAL_COPY(&val1, _9);
		ZEPHIR_OBS_NVAR(&val2);
		zephir_read_property(&_10$$4, this_ptr, SL("processors"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_fetch(&val2, &_10$$4, &val1, 0 TSRMLS_CC)) {
			ZEPHIR_CALL_FUNCTION(&_11$$5, "strval", &_12, 24, &val2);
			zephir_check_call_status();
			zephir_array_update_zval(&processors, &val1, &_11$$5, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_NVAR(&_13$$6);
			ZVAL_STRING(&_13$$6, "undefined");
			zephir_array_update_zval(&processors, &val1, &_13$$6, PH_COPY | PH_SEPARATE);
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&val1);
	ZEPHIR_CALL_FUNCTION(&_2, "array_values", NULL, 21, &processors);
	zephir_check_call_status();
	zephir_read_property(&_14, this_ptr, SL("formatString"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&logStr);
	zephir_fast_str_replace(&logStr, &replace0, &_2, &_14 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_GET_CONSTANT(&_15, "PHP_EOL");
	ZEPHIR_CONCAT_VV(return_value, &logStr, &_15);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Logger_Formatter_LinePlus, addProcessor) {

	zval *name_param = NULL, *processor, processor_sub;
	zval name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&processor_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &processor);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_update_property_array(this_ptr, SL("processors"), &name, processor TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Formatter_LinePlus, __get) {

	zval *key_param = NULL, _0, _1;
	zval key, _2;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	zephir_read_property(&_0, this_ptr, SL("processors"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_1);
	zephir_array_fetch(&_1, &_0, &key, PH_NOISY, "phalconplus/Logger/Formatter/LinePlus.zep", 58 TSRMLS_CC);
	zephir_get_strval(&_2, &_1);
	RETURN_CTOR(_2);

}

zend_object *zephir_init_properties_PhalconPlus_Logger_Formatter_LinePlus(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("processors"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("processors"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

