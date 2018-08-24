
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(PhalconPlus_RPC_Client_Adapter_Remote) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\RPC\\Client\\Adapter, Remote, phalconplus, rpc_client_adapter_remote, phalconplus_rpc_client_abstractclient_ce, phalconplus_rpc_client_adapter_remote_method_entry, 0);

	zend_declare_property_null(phalconplus_rpc_client_adapter_remote_ce, SL("remoteServerUrl"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_rpc_client_adapter_remote_ce, SL("client"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_RPC_Client_Adapter_Remote, __construct) {

	HashTable *_4$$4;
	HashPosition _3$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *remoteServerUrl_param = NULL, *opts_param = NULL, *key = NULL, *_0, *_1, *_2, *optKey$$4 = NULL, *optVal$$4 = NULL, **_5$$4, *_6$$5;
	zval *remoteServerUrl = NULL, *opts = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &remoteServerUrl_param, &opts_param);

	zephir_get_arrval(remoteServerUrl, remoteServerUrl_param);
	if (!opts_param) {
		ZEPHIR_INIT_VAR(opts);
		array_init(opts);
	} else {
		zephir_get_arrval(opts, opts_param);
	}


	if (ZEPHIR_IS_EMPTY(remoteServerUrl)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "server url can not be empty", "phalconplus/RPC/Client/Adapter/Remote.zep", 12);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&key, "array_rand", NULL, 76, remoteServerUrl);
	zephir_check_call_status();
	zephir_array_fetch(&_0, remoteServerUrl, key, PH_NOISY | PH_READONLY, "phalconplus/RPC/Client/Adapter/Remote.zep", 16 TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("remoteServerUrl"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zephir_get_internal_ce(SS("yar_client") TSRMLS_CC));
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("remoteServerUrl"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0, _2);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("client"), _1 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(opts))) {
		zephir_is_iterable(opts, &_4$$4, &_3$$4, 0, 0, "phalconplus/RPC/Client/Adapter/Remote.zep", 24);
		for (
		  ; zend_hash_get_current_data_ex(_4$$4, (void**) &_5$$4, &_3$$4) == SUCCESS
		  ; zend_hash_move_forward_ex(_4$$4, &_3$$4)
		) {
			ZEPHIR_GET_HMKEY(optKey$$4, _4$$4, _3$$4);
			ZEPHIR_GET_HVALUE(optVal$$4, _5$$4);
			_6$$5 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _6$$5, "setopt", NULL, 0, optKey$$4, optVal$$4);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_RPC_Client_Adapter_Remote, callByObject) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rawData_param = NULL, *_0;
	zval *rawData = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rawData_param);

	zephir_get_arrval(rawData, rawData_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "callbyobject", NULL, 0, rawData);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_RPC_Client_Adapter_Remote, __call) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *args = NULL, *_1$$3;
	zval *method_param = NULL, *args_param = NULL, *_0, *_2$$3;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	zephir_get_arrval(args, args_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	if ((zephir_method_exists(_0, method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_INIT_VAR(_1$$3);
		zephir_create_array(_1$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_2$$3);
		zephir_read_property_this(&_2$$3, this_ptr, SL("client"), PH_NOISY_CC);
		zephir_array_fast_append(_1$$3, _2$$3);
		zephir_array_fast_append(_1$$3, method);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _1$$3, args);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "method not exists", "phalconplus/RPC/Client/Adapter/Remote.zep", 38);
		return;
	}

}

