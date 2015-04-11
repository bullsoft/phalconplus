
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
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/variables.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(PhalconPlus_RPC_Client_Adapter_Remote) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\RPC\\Client\\Adapter, Remote, phalconplus, rpc_client_adapter_remote, phalconplus_rpc_client_abstractclient_ce, phalconplus_rpc_client_adapter_remote_method_entry, 0);

	zend_declare_property_null(phalconplus_rpc_client_adapter_remote_ce, SL("remoteServerUrl"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_rpc_client_adapter_remote_ce, SL("client"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_RPC_Client_Adapter_Remote, __construct) {

	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *remoteServerUrl_param = NULL, *opts_param = NULL, *key = NULL, *_1, *_2, *_3, *optKey = NULL, *optVal = NULL, **_6, *_7;
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
	ZEPHIR_CALL_FUNCTION(&key, "array_rand", &_0, remoteServerUrl);
	zephir_check_call_status();
	zephir_array_fetch(&_1, remoteServerUrl, key, PH_NOISY | PH_READONLY, "phalconplus/RPC/Client/Adapter/Remote.zep", 16 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("remoteServerUrl"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, zephir_get_internal_ce(SS("yar_client") TSRMLS_CC));
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("remoteServerUrl"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, _3);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("client"), _2 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(opts))) {
		zephir_is_iterable(opts, &_5, &_4, 0, 0, "phalconplus/RPC/Client/Adapter/Remote.zep", 24);
		for (
		  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
		  ; zephir_hash_move_forward_ex(_5, &_4)
		) {
			ZEPHIR_GET_HMKEY(optKey, _5, _4);
			ZEPHIR_GET_HVALUE(optVal, _6);
			_7 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _7, "setopt", NULL, optKey, optVal);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_RPC_Client_Adapter_Remote, callByObject) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *rawData_param = NULL, *_0;
	zval *rawData = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rawData_param);

	zephir_get_arrval(rawData, rawData_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "callbyobject", NULL, rawData);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_RPC_Client_Adapter_Remote, __call) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zval *args = NULL, *_4;
	zval *method_param = NULL, *args_param = NULL, *_0, *_1, *_2, *_5;
	zval *method = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	if (unlikely(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(method, method_param);
	} else {
		ZEPHIR_INIT_VAR(method);
		ZVAL_EMPTY_STRING(method);
	}
	zephir_get_arrval(args, args_param);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("client"), PH_NOISY_CC);
	if ((zephir_method_exists(_0, method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_INIT_VAR(_1);
		zephir_var_export_ex(_1, &(args) TSRMLS_CC);
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SVSV(_2, "Remote RPC set Opts: ", method, " args: ", _1);
		ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_3, _2);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_4);
		zephir_create_array(_4, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(_5);
		zephir_read_property_this(&_5, this_ptr, SL("client"), PH_NOISY_CC);
		zephir_array_fast_append(_4, _5);
		zephir_array_fast_append(_4, method);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _4, args);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "method not exists", "phalconplus/RPC/Client/Adapter/Remote.zep", 38);
		return;
	}

}

