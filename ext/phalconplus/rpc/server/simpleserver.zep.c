
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


ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Server_SimpleServer) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Rpc\\Server, SimpleServer, phalconplus, rpc_server_simpleserver, phalconplus_rpc_server_abstractserver_ce, phalconplus_rpc_server_simpleserver_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Rpc_Server_SimpleServer, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di, di_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &di);



	zephir_update_property_zval(this_ptr, SL("di"), di);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "config");
	ZEPHIR_CALL_METHOD(&_0, di, "getshared", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("config"), &_0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "eventsManager");
	ZEPHIR_CALL_METHOD(&_2, di, "getshared", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("eventsManager"), &_2);
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 47);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 48);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Rpc_Server_SimpleServer, onConstruct) {

	zval *this_ptr = getThis();



}

