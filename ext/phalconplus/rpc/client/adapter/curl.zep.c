
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
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Client_Adapter_Curl) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Rpc\\Client\\Adapter, Curl, phalconplus, rpc_client_adapter_curl, phalconplus_rpc_client_abstractclient_ce, phalconplus_rpc_client_adapter_curl_method_entry, 0);

	zend_declare_property_null(phalconplus_rpc_client_adapter_curl_ce, SL("remoteServerUrl"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phalconplus_rpc_client_adapter_curl_ce, SL("client"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phalconplus_rpc_client_adapter_curl_ce, SL("response"), ZEND_ACC_PRIVATE);

	zend_declare_property_string(phalconplus_rpc_client_adapter_curl_ce, SL("formater"), "msgpack", ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Curl, getResponse) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "response");

}

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Curl, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval formater;
	zval *remoteServerUrl_param = NULL, *opts_param = NULL, *formater_param = NULL, key, _0, _1, _3, _2$$4;
	zval remoteServerUrl, opts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&remoteServerUrl);
	ZVAL_UNDEF(&opts);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&formater);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &remoteServerUrl_param, &opts_param, &formater_param);

	zephir_get_arrval(&remoteServerUrl, remoteServerUrl_param);
	if (!opts_param) {
		ZEPHIR_INIT_VAR(&opts);
		array_init(&opts);
	} else {
		zephir_get_arrval(&opts, opts_param);
	}
	if (!formater_param) {
		ZEPHIR_INIT_VAR(&formater);
		ZVAL_STRING(&formater, "json");
	} else {
		zephir_get_strval(&formater, formater_param);
	}


	if (ZEPHIR_IS_EMPTY(&remoteServerUrl)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "server url can not be empty", "phalconplus/Rpc/Client/Adapter/Curl.zep", 16);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&key, "array_rand", NULL, 141, &remoteServerUrl);
	zephir_check_call_status();
	zephir_array_fetch(&_0, &remoteServerUrl, &key, PH_NOISY | PH_READONLY, "phalconplus/Rpc/Client/Adapter/Curl.zep", 19);
	zephir_update_property_zval(this_ptr, ZEND_STRL("remoteServerUrl"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalconplus_curl_curl_ce);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 142);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("client"), &_1);
	if (!(ZEPHIR_IS_EMPTY(&opts))) {
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("client"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "setdefaultoptions", NULL, 0, &opts);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "json");
	if (ZEPHIR_IS_EQUAL(&_3, &formater)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("formater"), &formater);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Curl, callByObject) {

	zval encoder, decoder;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rawData_param = NULL, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10$$4, _11$$4, _19$$4, _20$$4, _12$$5, _13$$5, _14$$6, _15$$6, _16$$6, _17$$7, _18$$7;
	zval rawData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawData);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_19$$4);
	ZVAL_UNDEF(&_20$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&encoder);
	ZVAL_UNDEF(&decoder);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rawData_param);

	zephir_get_arrval(&rawData, rawData_param);


	ZEPHIR_INIT_VAR(&encoder);
	ZVAL_STRING(&encoder, "msgpack_pack");
	ZEPHIR_INIT_VAR(&decoder);
	ZVAL_STRING(&decoder, "msgpack_unpack");
	zephir_read_property(&_0, this_ptr, ZEND_STRL("formater"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "json");
	if (ZEPHIR_IS_EQUAL(&_1, &_0)) {
		ZEPHIR_INIT_NVAR(&encoder);
		ZVAL_STRING(&encoder, "json_encode");
		ZEPHIR_INIT_NVAR(&decoder);
		ZVAL_STRING(&decoder, "json_decode");
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("namePrefix"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_3, &rawData, SL("service"), PH_NOISY | PH_READONLY, "phalconplus/Rpc/Client/Adapter/Curl.zep", 39);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VV(&_4, &_2, &_3);
	zephir_array_update_string(&rawData, SL("service"), &_4, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_5, this_ptr, ZEND_STRL("client"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("remoteServerUrl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_ZVAL_FUNCTION(&_8, &encoder, NULL, 0, &rawData);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_6, &_5, "rawpost", NULL, 0, &_7, &_8);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("response"), &_6);
	zephir_read_property(&_9, this_ptr, ZEND_STRL("response"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_9) == IS_OBJECT) {
		zephir_read_property(&_10$$4, this_ptr, ZEND_STRL("response"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_11$$4, &_10$$4, ZEND_STRL("statusCode"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_LONG(&_11$$4, 200)) {
			zephir_read_property(&_12$$5, this_ptr, ZEND_STRL("formater"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_13$$5);
			ZVAL_STRING(&_13$$5, "json");
			if (ZEPHIR_IS_EQUAL(&_13$$5, &_12$$5)) {
				zephir_read_property(&_14$$6, this_ptr, ZEND_STRL("response"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_15$$6, &_14$$6, ZEND_STRL("body"), PH_NOISY_CC | PH_READONLY);
				ZVAL_BOOL(&_16$$6, 1);
				ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(&decoder, NULL, 0, &_15$$6, &_16$$6);
				zephir_check_call_status();
				RETURN_MM();
			} else {
				zephir_read_property(&_17$$7, this_ptr, ZEND_STRL("response"), PH_NOISY_CC | PH_READONLY);
				zephir_read_property(&_18$$7, &_17$$7, ZEND_STRL("body"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(&decoder, NULL, 0, &_18$$7);
				zephir_check_call_status();
				RETURN_MM();
			}
		}
		zephir_read_property(&_19$$4, this_ptr, ZEND_STRL("response"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_20$$4);
		zephir_read_property(&_20$$4, &_19$$4, ZEND_STRL("statusText"), PH_NOISY_CC);
		RETURN_CCTOR(&_20$$4);
	}
	ZEPHIR_MM_RESTORE();

}

