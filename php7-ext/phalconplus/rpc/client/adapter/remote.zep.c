
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

	zend_string *_5$$4;
	zend_ulong _4$$4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *remoteServerUrl_param = NULL, *opts_param = NULL, key, _0, _1, _2, optKey$$4, optVal$$4, *_3$$4, _6$$5;
	zval remoteServerUrl, opts;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&remoteServerUrl);
	ZVAL_UNDEF(&opts);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&optKey$$4);
	ZVAL_UNDEF(&optVal$$4);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &remoteServerUrl_param, &opts_param);

	zephir_get_arrval(&remoteServerUrl, remoteServerUrl_param);
	if (!opts_param) {
		ZEPHIR_INIT_VAR(&opts);
		array_init(&opts);
	} else {
		zephir_get_arrval(&opts, opts_param);
	}


	if (ZEPHIR_IS_EMPTY(&remoteServerUrl)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "server url can not be empty", "phalconplus/RPC/Client/Adapter/Remote.zep", 12);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&key, "array_rand", NULL, 60, &remoteServerUrl);
	zephir_check_call_status();
	zephir_array_fetch(&_0, &remoteServerUrl, &key, PH_NOISY | PH_READONLY, "phalconplus/RPC/Client/Adapter/Remote.zep", 16 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("remoteServerUrl"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, zephir_get_internal_ce(SL("yar_client")));
	zephir_read_property(&_2, this_ptr, SL("remoteServerUrl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("client"), &_1);
	if (!(ZEPHIR_IS_EMPTY(&opts))) {
		zephir_is_iterable(&opts, 0, "phalconplus/RPC/Client/Adapter/Remote.zep", 24);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&opts), _4$$4, _5$$4, _3$$4)
		{
			ZEPHIR_INIT_NVAR(&optKey$$4);
			if (_5$$4 != NULL) { 
				ZVAL_STR_COPY(&optKey$$4, _5$$4);
			} else {
				ZVAL_LONG(&optKey$$4, _4$$4);
			}
			ZEPHIR_INIT_NVAR(&optVal$$4);
			ZVAL_COPY(&optVal$$4, _3$$4);
			zephir_read_property(&_6$$5, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_6$$5, "setopt", NULL, 0, &optKey$$4, &optVal$$4);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&optVal$$4);
		ZEPHIR_INIT_NVAR(&optKey$$4);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_RPC_Client_Adapter_Remote, callByObject) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *rawData_param = NULL, _0;
	zval rawData;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&rawData);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rawData_param);

	zephir_get_arrval(&rawData, rawData_param);


	zephir_read_property(&_0, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "callbyobject", NULL, 0, &rawData);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_RPC_Client_Adapter_Remote, __call) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval args, _1$$3;
	zval *method_param = NULL, *args_param = NULL, _0, _2$$3;
	zval method;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);

	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_EMPTY_STRING(&method);
	}
	zephir_get_arrval(&args, args_param);


	zephir_read_property(&_0, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	if ((zephir_method_exists(&_0, &method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&_2$$3);
		zephir_read_property(&_2$$3, this_ptr, SL("client"), PH_NOISY_CC);
		zephir_array_fast_append(&_1$$3, &_2$$3);
		zephir_array_fast_append(&_1$$3, &method);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_1$$3, &args);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "method not exists", "phalconplus/RPC/Client/Adapter/Remote.zep", 38);
		return;
	}

}

