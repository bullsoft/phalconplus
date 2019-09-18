
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
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Processor_Uid) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Logger\\Processor, Uid, phalconplus, logger_processor_uid, phalconplus_logger_processor_abstractprocessor_ce, phalconplus_logger_processor_uid_method_entry, 0);

	zend_declare_property_null(phalconplus_logger_processor_uid_ce, SL("uid"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Logger_Processor_Uid, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *len = NULL, len_sub, __$true, _0$$4, _1$$4, _2$$4, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&len_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &len);

	if (!len) {
		len = &len_sub;
		ZEPHIR_INIT_VAR(len);
		ZVAL_LONG(len, 18);
	}


	if (zephir_fast_strlen_ev(len) > 2) {
		zephir_update_property_zval(this_ptr, SL("uid"), len);
	} else {
		ZEPHIR_INIT_VAR(&_0$$4);
		ZVAL_STRING(&_0$$4, "");
		ZEPHIR_CALL_FUNCTION(&_1$$4, "uniqid", NULL, 89, &_0$$4, &__$true);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_0$$4);
		ZVAL_STRING(&_0$$4, "md5");
		ZEPHIR_CALL_FUNCTION(&_2$$4, "hash", NULL, 90, &_0$$4, &_1$$4);
		zephir_check_call_status();
		ZVAL_LONG(&_3$$4, 0);
		ZEPHIR_INIT_NVAR(&_0$$4);
		zephir_substr(&_0$$4, &_2$$4, 0 , zephir_get_intval(len), 0);
		zephir_update_property_zval(this_ptr, SL("uid"), &_0$$4);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Processor_Uid, __toString) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "uid");

}

