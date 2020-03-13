
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Server_SimpleServer) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Rpc\\Server, SimpleServer, phalconplus, rpc_server_simpleserver, phalconplus_rpc_server_abstractserver_ce, phalconplus_rpc_server_simpleserver_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Rpc_Server_SimpleServer, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di, di_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &di);



	zephir_update_property_zval(this_ptr, SL("di"), di);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "eventsManager");
	ZEPHIR_CALL_METHOD(&_0, di, "getshared", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("eventsManager"), &_0);
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 46);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 74);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Rpc_Server_SimpleServer, onConstruct) {

	zval *this_ptr = getThis();



}

PHP_METHOD(PhalconPlus_Rpc_Server_SimpleServer, __get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *property_param = NULL, _0, _1, _2$$3;
	zval property;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (UNEXPECTED(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(&property, property_param);
	} else {
		ZEPHIR_INIT_VAR(&property);
		ZVAL_EMPTY_STRING(&property);
	}


	zephir_read_property(&_0, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "has", NULL, 0, &property);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		zephir_read_property(&_2$$3, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_2$$3, "get", NULL, 0, &property);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();

}

