
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
#include "kernel/fcall.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Facades_App) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Facades, App, phalconplus, facades_app, phalconplus_facades_abstractfacade_ce, phalconplus_facades_app_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Facades_App, getName) {

	zval *this_ptr = getThis();


	RETURN_STRING("application");

}

PHP_METHOD(PhalconPlus_Facades_App, resolve) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di, di_sub, boot, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
	ZVAL_UNDEF(&boot);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &di);



	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "bootstrap");
	ZEPHIR_CALL_METHOD(&boot, di, "get", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &boot, "getapp", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM_NULL();

}

