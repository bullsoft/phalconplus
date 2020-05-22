
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
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Client_AbstractClient) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Rpc\\Client, AbstractClient, phalconplus, rpc_client_abstractclient, phalconplus_rpc_client_abstractclient_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_string(phalconplus_rpc_client_abstractclient_ce, SL("namePrefix"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_rpc_client_abstractclient_ce, SL("di"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Rpc_Client_AbstractClient, setNamePrefix) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *prefix_param = NULL, _0;
	zval prefix;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &prefix_param);

	zephir_get_strval(&prefix, prefix_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_trim(&_0, &prefix, NULL , ZEPHIR_TRIM_BOTH);
	zephir_update_property_zval(this_ptr, ZEND_STRL("namePrefix"), &_0);
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Rpc_Client_AbstractClient, setDI) {

	zval *di, di_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &di);



	zephir_update_property_zval(this_ptr, ZEND_STRL("di"), di);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_Rpc_Client_AbstractClient, callByObject) {

}

