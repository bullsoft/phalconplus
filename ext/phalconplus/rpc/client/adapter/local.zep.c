
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/variables.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PhalconPlus_RPC_Client_Adapter_Local) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\RPC\\Client\\Adapter, Local, phalconplus, rpc_client_adapter_local, phalconplus_rpc_client_abstractclient_ce, phalconplus_rpc_client_adapter_local_method_entry, 0);

	zend_declare_property_null(phalconplus_rpc_client_adapter_local_ce, SL("config"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_rpc_client_adapter_local_ce, SL("di"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_RPC_Client_Adapter_Local, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *di, *_0 = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &di);



	zephir_update_property_this(this_ptr, SL("di"), di TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, di, "get", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("config"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_RPC_Client_Adapter_Local, callByParams) {

	zephir_fcall_cache_entry *_7 = NULL;
	zval *_5, *_11, *_12;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_3;
	zval *service_param = NULL, *method_param = NULL, *request, *serviceClass, *serviceObj, *response, *_0 = NULL, *_1, *_2 = NULL, *_4, *_6, *_9, *_10;
	zval *service = NULL, *method = NULL, *_8;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &service_param, &method_param, &request);

	if (unlikely(Z_TYPE_P(service_param) != IS_STRING && Z_TYPE_P(service_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'service' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(service_param) == IS_STRING)) {
		zephir_get_strval(service, service_param);
	} else {
		ZEPHIR_INIT_VAR(service);
		ZVAL_EMPTY_STRING(service);
	}
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


	ZEPHIR_INIT_VAR(_1);
	zephir_ucfirst(_1, service);
	ZEPHIR_INIT_VAR(serviceClass);
	ZEPHIR_CONCAT_VS(serviceClass, _1, "Service");
	ZEPHIR_INIT_VAR(serviceObj);
	zephir_fetch_safe_class(_2, serviceClass);
	_3 = zend_fetch_class(Z_STRVAL_P(_2), Z_STRLEN_P(_2), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(serviceObj, _3);
	if (zephir_has_constructor(serviceObj TSRMLS_CC)) {
		_4 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, serviceObj, "__construct", NULL, 0, _4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_5);
	zephir_create_array(_5, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_5, serviceObj);
	zephir_array_fast_append(_5, method);
	if (zephir_is_callable(_5 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_6);
		ZEPHIR_CONCAT_SV(_6, "ServerClass: ", serviceClass);
		ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_7, 38, _6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_8);
		ZEPHIR_CONCAT_SV(_8, "InvokeMethod: ", method);
		ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_7, 38, _8);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_9);
		zephir_var_export_ex(_9, &(request) TSRMLS_CC);
		ZEPHIR_INIT_VAR(_10);
		ZEPHIR_CONCAT_SV(_10, "InputParma: ", _9);
		ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_7, 38, _10);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(_11);
		zephir_create_array(_11, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_11, serviceObj);
		zephir_array_fast_append(_11, method);
		ZEPHIR_INIT_VAR(_12);
		zephir_create_array(_12, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(_12, request);
		ZEPHIR_INIT_VAR(response);
		ZEPHIR_CALL_USER_FUNC_ARRAY(response, _11, _12);
		zephir_check_call_status();
		RETURN_CCTOR(response);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "No service is found", "phalconplus/RPC/Client/Adapter/Local.zep", 29);
		return;
	}

}

PHP_METHOD(PhalconPlus_RPC_Client_Adapter_Local, callByObject) {

	zend_bool _5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *rawData_param = NULL, *service = NULL, *method = NULL, *request, *_0, *_1, *_3 = NULL, *_4 = NULL, _6;
	zval *rawData = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rawData_param);

	zephir_get_arrval(rawData, rawData_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_var_export_ex(_0, &(rawData) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "Local callByObject: ", _0);
	ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_2, 38, _1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(service);
	if (!(zephir_array_isset_string_fetch(&service, rawData, SS("service"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SVS(_4, "service ", service, " not exists");
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 21, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "phalconplus/RPC/Client/Adapter/Local.zep", 40 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(method);
	if (!(zephir_array_isset_string_fetch(&method, rawData, SS("method"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SVS(_4, "method ", method, " not exists");
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 21, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "phalconplus/RPC/Client/Adapter/Local.zep", 44 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(request);
	if (!(zephir_array_isset_string_fetch(&request, rawData, SS("args"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "args not exists", "phalconplus/RPC/Client/Adapter/Local.zep", 48);
		return;
	}
	ZEPHIR_INIT_NVAR(_3);
	zephir_fast_trim(_3, service, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(service, _3);
	ZEPHIR_INIT_NVAR(_3);
	zephir_fast_trim(_3, method, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(method, _3);
	_5 = ZEPHIR_IS_EMPTY(service);
	if (!(_5)) {
		_5 = ZEPHIR_IS_EMPTY(method);
	}
	if (_5) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "service:method(args) must exists. All of them!!!", "phalconplus/RPC/Client/Adapter/Local.zep", 55);
		return;
	}
	ZEPHIR_SINIT_VAR(_6);
	ZVAL_STRING(&_6, "Invoke callByParams", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_2, 38, &_6);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callbyparams", NULL, 55, service, method, request);
	zephir_check_call_status();
	RETURN_MM();

}

