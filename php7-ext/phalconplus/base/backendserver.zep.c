
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_BackendServer) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, BackendServer, phalconplus, base_backendserver, phalconplus_rpc_server_abstractserver_ce, phalconplus_base_backendserver_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_BackendServer, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di, di_sub, _0, _1, _2, _3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &di);



	zephir_update_property_zval(this_ptr, SL("di"), di);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "config");
	ZEPHIR_CALL_METHOD(&_0, di, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("config"), &_0);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "eventsManager");
	ZEPHIR_CALL_METHOD(&_2, di, "getshared", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("eventsManager"), &_2);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "serviceListener");
	ZEPHIR_CALL_METHOD(&_3, di, "has", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZEPHIR_INIT_VAR(&_4$$3);
		ZVAL_STRING(&_4$$3, "serviceListener");
		ZEPHIR_CALL_METHOD(NULL, di, "get", NULL, 0, &_4$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

