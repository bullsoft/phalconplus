
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Logger_Processor_Uid) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Logger\\Processor, Uid, phalconplus, logger_processor_uid, phalconplus_logger_processor_abstractprocessor_ce, phalconplus_logger_processor_uid_method_entry, 0);

	zend_declare_property_null(phalconplus_logger_processor_uid_ce, SL("uid"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Logger_Processor_Uid, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *len = NULL, _0 = zval_used_for_init, *_1 = NULL, *_2 = NULL, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &len);

	if (!len) {
		ZEPHIR_INIT_VAR(len);
		ZVAL_LONG(len, 18);
	}


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "uniqid", NULL, 58, &_0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_STRING(&_0, "md5", 0);
	ZEPHIR_CALL_FUNCTION(&_2, "hash", NULL, 59, &_0, _1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_INIT_VAR(_3);
	zephir_substr(_3, _2, 0 , zephir_get_intval(len), 0);
	zephir_update_property_this(this_ptr, SL("uid"), _3 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Logger_Processor_Uid, __toString) {

	

	RETURN_MEMBER(this_ptr, "uid");

}

