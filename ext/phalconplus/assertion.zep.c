
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Assertion) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus, Assertion, phalconplus, assertion, phalconplus_assertion_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Assertion, setUp) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	zval _0 = zval_used_for_init, _1 = zval_used_for_init;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 1);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "assert_options", &_2, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "assert_options", &_2, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 5);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "assert_options", &_2, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_STRING(&_1, "self::handler", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "assert_options", &_2, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Assertion, equal) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL;
	zval *a, *b, _0 = zval_used_for_init, _1 = zval_used_for_init, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &a, &b);



	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 1);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "assert_options", &_2, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 4);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "assert_options", &_2, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 5);
	ZEPHIR_SINIT_NVAR(_1);
	ZVAL_LONG(&_1, 1);
	ZEPHIR_CALL_FUNCTION(NULL, "assert_options", &_2, &_0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_INIT_NVAR(_3);
	zephir_create_closure_ex(_3, NULL, phalconplus_0__closure_ce, SS("__invoke") TSRMLS_CC);
	ZEPHIR_SINIT_NVAR(_0);
	ZVAL_LONG(&_0, 2);
	ZEPHIR_CALL_FUNCTION(NULL, "assert_options", &_2, &_0, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_SVSVS(_4, "'", a, "==", b, "'");
	ZEPHIR_CALL_FUNCTION(NULL, "assert", &_5, _4);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Assertion, greaterThan) {

	zval *a, *b;

	zephir_fetch_params(0, 2, 0, &a, &b);




}

PHP_METHOD(PhalconPlus_Assertion, lessThan) {

	zval *a, *b;

	zephir_fetch_params(0, 2, 0, &a, &b);




}

PHP_METHOD(PhalconPlus_Assertion, handler) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *file, *line, *code, *desc = NULL, *msg, *_0, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &file, &line, &code, &desc);

	if (!desc) {
		desc = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(msg);
	ZEPHIR_CONCAT_SVSVS(msg, "Assertion failed at ", file, ":", line, ".");
	if (zephir_is_true(desc)) {
		ZEPHIR_INIT_VAR(_0);
		ZEPHIR_CONCAT_SV(_0, " Desc: ", desc);
		zephir_concat_self(&msg, _0 TSRMLS_CC);
	}
	zend_print_zval(msg, 0);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zend_exception_get_default(TSRMLS_C));
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_2, msg);
	zephir_check_call_status();
	zephir_throw_exception_debug(_1, "phalconplus/Assertion.zep", 44 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

