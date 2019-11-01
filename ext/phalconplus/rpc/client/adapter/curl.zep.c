
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Client_Adapter_Curl) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Rpc\\Client\\Adapter, Curl, phalconplus, rpc_client_adapter_curl, phalconplus_rpc_client_abstractclient_ce, phalconplus_rpc_client_adapter_curl_method_entry, 0);

	zend_declare_property_null(phalconplus_rpc_client_adapter_curl_ce, SL("remoteServerUrl"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phalconplus_rpc_client_adapter_curl_ce, SL("client"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phalconplus_rpc_client_adapter_curl_ce, SL("response"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Curl, getResponse) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "response");

}

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Curl, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *remoteServerUrl_param = NULL, *opts_param = NULL, key, _0, _1, _2$$4;
	zval remoteServerUrl, opts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&remoteServerUrl);
	ZVAL_UNDEF(&opts);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$4);

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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "server url can not be empty", "phalconplus/Rpc/Client/Adapter/Curl.zep", 15);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&key, "array_rand", NULL, 122, &remoteServerUrl);
	zephir_check_call_status();
	zephir_array_fetch(&_0, &remoteServerUrl, &key, PH_NOISY | PH_READONLY, "phalconplus/Rpc/Client/Adapter/Curl.zep", 19);
	zephir_update_property_zval(this_ptr, SL("remoteServerUrl"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalconplus_curl_curl_ce);
	if (zephir_has_constructor(&_1)) {
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("client"), &_1);
	if (!(ZEPHIR_IS_EMPTY(&opts))) {
		zephir_read_property(&_2$$4, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "setdefaultoptions", NULL, 0, &opts);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Curl, callByObject) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rawData_param = NULL, _0, _1, _2, _3, _4, _5$$3, _6$$3, _9$$3, _10$$3, _7$$4, _8$$4;
	zval rawData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rawData_param);

	zephir_get_arrval(&rawData, rawData_param);


	zephir_read_property(&_0, this_ptr, SL("client"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, SL("remoteServerUrl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_3, "msgpack_pack", NULL, 123, &rawData);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "rawpost", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("response"), &_1);
	zephir_read_property(&_4, this_ptr, SL("response"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_4) == IS_OBJECT) {
		zephir_read_property(&_5$$3, this_ptr, SL("response"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_6$$3, &_5$$3, SL("statusCode"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_LONG(&_6$$3, 200)) {
			zephir_read_property(&_7$$4, this_ptr, SL("response"), PH_NOISY_CC | PH_READONLY);
			zephir_read_property(&_8$$4, &_7$$4, SL("body"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_RETURN_CALL_FUNCTION("msgpack_unpack", NULL, 124, &_8$$4);
			zephir_check_call_status();
			RETURN_MM();
		}
		zephir_read_property(&_9$$3, this_ptr, SL("response"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_10$$3);
		zephir_read_property(&_10$$3, &_9$$3, SL("statusText"), PH_NOISY_CC);
		RETURN_CCTOR(&_10$$3);
	}
	ZEPHIR_MM_RESTORE();

}

