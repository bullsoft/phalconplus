
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


ZEPHIR_INIT_CLASS(PhalconPlus_Base_SimpleServer) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, SimpleServer, phalconplus, base_simpleserver, phalconplus_rpc_server_abstractserver_ce, phalconplus_base_simpleserver_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_SimpleServer, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di, *_0 = NULL, *_1 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &di);



	zephir_update_property_this(getThis(), SL("di"), di TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, di, "getshared", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("config"), _0 TSRMLS_CC);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "eventsManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, di, "getshared", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("eventsManager"), _2 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 49);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 50);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_SimpleServer, onConstruct) {

	


}

