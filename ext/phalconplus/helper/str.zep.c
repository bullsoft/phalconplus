
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
#include "ext/spl/spl_array.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Helper_Str) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Helper, Str, phalconplus, helper_str, phalconplus_helper_str_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Helper_Str, decodeJson) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *inputStr_param = NULL, obj, e, _0, _1, _5, _3$$3, _4$$3, _6$$4, _7$$4;
	zval inputStr;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputStr);
	ZVAL_UNDEF(&obj);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &inputStr_param);

	zephir_get_strval(&inputStr, inputStr_param);


	ZEPHIR_INIT_VAR(&obj);
	object_init_ex(&obj, spl_ce_ArrayObject);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_METHOD(NULL, &obj, "__construct", NULL, 78, &_0, &_1);
	zephir_check_call_status();

	/* try_start_1: */

		ZVAL_NULL(&_3$$3);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "/");
		ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "isjsonstring", &_2, 0, &inputStr, &_3$$3, &_4$$3, &obj);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_5);
		ZVAL_OBJ(&_5, EG(exception));
		Z_ADDREF_P(&_5);
		if (zephir_instance_of_ev(&_5, zend_exception_get_default(TSRMLS_C))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_5);
			ZEPHIR_INIT_VAR(&_6$$4);
			object_init_ex(&_6$$4, phalconplus_helper_exception_ce);
			ZEPHIR_CALL_METHOD(&_7$$4, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", NULL, 2, &_7$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$4, "phalconplus/Helper/Str.zep", 13);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(&obj);

}

