
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
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, Exception, phalconplus, base_exception, zend_exception_get_default(TSRMLS_C), phalconplus_base_exception_method_entry, 0);

	zend_declare_property_string(phalconplus_base_exception_ce, SL("message"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalconplus_base_exception_ce, SL("level"), 7, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_long(phalconplus_base_exception_ce, SL("code"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_Exception, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message = NULL, *logger = NULL, *_0, *_1 = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &message, &logger);

	if (!message) {
		ZEPHIR_INIT_VAR(message);
		ZVAL_STRING(message, "", 1);
	} else {
		ZEPHIR_SEPARATE_PARAM(message);
	}
	if (!logger) {
		logger = ZEPHIR_GLOBAL(global_null);
	}


	if (ZEPHIR_IS_EMPTY(message)) {
		ZEPHIR_INIT_VAR(_0);
		zephir_get_called_class(_0 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(message);
		ZEPHIR_CONCAT_SV(message, "An exception created: ", _0);
	}
	if (!(Z_TYPE_P(logger) == IS_NULL)) {
		ZEPHIR_CALL_METHOD(&_1, this_ptr, "getlevel", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, logger, "log", NULL, message, _1);
		zephir_check_call_status();
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("message"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(_2)) {
		zephir_update_property_this(this_ptr, SL("message"), message TSRMLS_CC);
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

