
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
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_RPC_Server_AbstractServer) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\RPC\\Server, AbstractServer, phalconplus, rpc_server_abstractserver, phalconplus_rpc_server_abstractserver_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalconplus_rpc_server_abstractserver_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_rpc_server_abstractserver_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalconplus_rpc_server_abstractserver_ce, SL("phpOnly"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_rpc_server_abstractserver_ce, SL("eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_RPC_Server_AbstractServer, __construct) {

}

PHP_METHOD(PhalconPlus_RPC_Server_AbstractServer, requestCheck) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *service_param = NULL, *method_param = NULL, *request, *serviceReflection, *methodReflection = NULL;
	zval *service = NULL, *method = NULL;

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


	ZEPHIR_INIT_VAR(serviceReflection);
	object_init_ex(serviceReflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, serviceReflection, "__construct", NULL, 18, service);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&methodReflection, serviceReflection, "getmethod", NULL, 57, method);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_RPC_Server_AbstractServer, callByParams) {

	zend_class_entry *_8, *_12;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_3 = NULL, *_15, *_16 = NULL, *_17;
	zend_bool _2;
	zval *service_param = NULL, *method_param = NULL, *request = NULL, *serviceClass = NULL, *_0 = NULL, *_1, *tmp = NULL, *param, *paramClass = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_9 = NULL, *_10 = NULL, *serviceObj, *response = NULL, *e = NULL, *_11 = NULL, *_13, *_14, *_18, *_19;
	zval *service = NULL, *method = NULL, *_20;

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
	ZEPHIR_INIT_VAR(serviceClass);
	ZVAL_STRING(serviceClass, "", 1);
	ZEPHIR_INIT_VAR(tmp);
	array_init(tmp);


	ZEPHIR_INIT_VAR(_1);
	zephir_ucfirst(_1, service);
	ZEPHIR_INIT_NVAR(serviceClass);
	ZEPHIR_CONCAT_VS(serviceClass, _1, "Service");
	_2 = Z_TYPE_P(request) == IS_OBJECT;
	if (_2) {
		_2 = zephir_instance_of_ev(request, phalconplus_base_protobuffer_ce TSRMLS_CC);
	}
	if (_2) {
		zephir_update_property_this(this_ptr, SL("phpOnly"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	} else if (Z_TYPE_P(request) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(tmp, request);
		ZEPHIR_INIT_VAR(param);
		object_init_ex(param, zephir_get_internal_ce(SS("reflectionparameter") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_3);
		zephir_create_array(_3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_3, serviceClass);
		zephir_array_fast_append(_3, method);
		ZEPHIR_INIT_VAR(_4);
		ZVAL_LONG(_4, 0);
		ZEPHIR_CALL_METHOD(NULL, param, "__construct", NULL, 16, _3, _4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5, param, "getclass", NULL, 17);
		zephir_check_call_status();
		if (zephir_is_true(_5)) {
			ZEPHIR_CALL_METHOD(&_6, param, "getclass", NULL, 17);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&paramClass, _6, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(request);
			zephir_fetch_safe_class(_7, paramClass);
			_8 = zend_fetch_class(Z_STRVAL_P(_7), Z_STRLEN_P(_7), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(request, _8);
			if (zephir_has_constructor(request TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, request, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(NULL, request, "softclone", NULL, 0, tmp);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_4);
			object_init_ex(_4, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_VAR(_9);
			zephir_json_encode(_9, &(_9), request, 0  TSRMLS_CC);
			ZEPHIR_INIT_VAR(_10);
			ZEPHIR_CONCAT_SVSVSV(_10, "Service class:method definition is invalid. Detail: ", service, " : ", method, ". Request: ", _9);
			ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 21, _10);
			zephir_check_call_status();
			zephir_throw_exception_debug(_4, "phalconplus/RPC/Server/AbstractServer.zep", 37 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(_4);
		object_init_ex(_4, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_NVAR(_9);
		zephir_json_encode(_9, &(_9), request, 0  TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_10);
		ZEPHIR_CONCAT_SV(_10, "Your input is not allowed. Request: ", _9);
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 21, _10);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4, "phalconplus/RPC/Server/AbstractServer.zep", 40 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(serviceObj);
	zephir_fetch_safe_class(_11, serviceClass);
	_12 = zend_fetch_class(Z_STRVAL_P(_11), Z_STRLEN_P(_11), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(serviceObj, _12);
	if (zephir_has_constructor(serviceObj TSRMLS_CC)) {
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, serviceObj, "__construct", NULL, 0, _13);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_3);
	zephir_create_array(_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_3, serviceObj);
	zephir_array_fast_append(_3, method);
	if (zephir_is_callable(_3 TSRMLS_CC)) {
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("eventsManager"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_15);
		zephir_create_array(_15, 3, 0 TSRMLS_CC);
		zephir_array_fast_append(_15, service);
		zephir_array_fast_append(_15, method);
		zephir_array_fast_append(_15, request);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "backend-server:beforeExecute", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _14, "fire", NULL, 0, _4, this_ptr, _15);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();

		/* try_start_1: */

			ZEPHIR_INIT_NVAR(_4);
			ZEPHIR_INIT_VAR(_16);
			zephir_create_array(_16, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(_16, serviceObj);
			zephir_array_fast_append(_16, method);
			ZEPHIR_INIT_VAR(_17);
			zephir_create_array(_17, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_17, request);
			ZEPHIR_CALL_USER_FUNC_ARRAY(_4, _16, _17);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CPY_WRT(response, _4);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(e, EG(exception));
			if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				zephir_throw_exception_debug(e, "phalconplus/RPC/Server/AbstractServer.zep", 51 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		_18 = zephir_fetch_nproperty_this(this_ptr, SL("eventsManager"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_16);
		zephir_create_array(_16, 3, 0 TSRMLS_CC);
		zephir_array_fast_append(_16, service);
		zephir_array_fast_append(_16, method);
		zephir_array_fast_append(_16, request);
		ZEPHIR_INIT_NVAR(_4);
		ZVAL_STRING(_4, "backend-server:afterExecute", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, _18, "fire", NULL, 0, _4, this_ptr, _16);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_4);
		_19 = zephir_fetch_nproperty_this(this_ptr, SL("phpOnly"), PH_NOISY_CC);
		if (ZEPHIR_IS_TRUE(_19)) {
			ZEPHIR_CPY_WRT(_4, response);
		} else {
			ZEPHIR_CALL_METHOD(&_4, response, "toarray", NULL, 0);
			zephir_check_call_status();
		}
		RETURN_CCTOR(_4);
	} else {
		object_init_ex(_4, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_20);
		ZEPHIR_CONCAT_SVSV(_20, "Service:method not found. Detail: ", service, " : ", method);
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, 21, _20);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4, "phalconplus/RPC/Server/AbstractServer.zep", 56 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

}

/**
 *
 * @param array rawData
 * <code> 
 *     rawData = ["service":"Demo", "method":"demo", "args": <ProtoBuffer>, "logId": "234fdfaf3334"]
 * </code>
 * @return <ProtoBuffer>
 * @throw \Exception
 *
 */
PHP_METHOD(PhalconPlus_RPC_Server_AbstractServer, callByObject) {

	zend_bool _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *rawData_param = NULL, *service = NULL, *method = NULL, *request, *response = NULL, *logId = NULL, *message = NULL, *_0 = NULL, *_1 = NULL, *_2, *_5, *_6 = NULL, *_7, *_8 = NULL, *_9 = NULL, *_11, *_13, *_14, *_15 = NULL;
	zval *rawData = NULL, *_3, *_10, *_12;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rawData_param);

	zephir_get_arrval(rawData, rawData_param);
	ZEPHIR_INIT_VAR(logId);
	ZVAL_STRING(logId, "", 1);
	ZEPHIR_INIT_VAR(message);
	ZVAL_STRING(message, "", 1);


	ZEPHIR_OBS_VAR(service);
	if (!(zephir_array_isset_string_fetch(&service, rawData, SS("service"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_0);
		object_init_ex(_0, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "service ", service, " not exists");
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 21, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalconplus/RPC/Server/AbstractServer.zep", 75 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(method);
	if (!(zephir_array_isset_string_fetch(&method, rawData, SS("method"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(_0);
		object_init_ex(_0, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_LNVAR(_1);
		ZEPHIR_CONCAT_SVS(_1, "method ", method, " not exists");
		ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 21, _1);
		zephir_check_call_status();
		zephir_throw_exception_debug(_0, "phalconplus/RPC/Server/AbstractServer.zep", 79 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(request);
	if (!(zephir_array_isset_string_fetch(&request, rawData, SS("args"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "args not exists", "phalconplus/RPC/Server/AbstractServer.zep", 83);
		return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("eventsManager"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(_3, service);
	zephir_array_fast_append(_3, method);
	zephir_array_fast_append(_3, rawData);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "backend-server:requestCheck", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "fire", NULL, 0, _0, this_ptr, _3);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_0);
	zephir_fast_trim(_0, service, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(service, _0);
	ZEPHIR_INIT_NVAR(_0);
	zephir_fast_trim(_0, method, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(method, _0);
	_4 = ZEPHIR_IS_EMPTY(service);
	if (!(_4)) {
		_4 = ZEPHIR_IS_EMPTY(method);
	}
	if (_4) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "service:method(args) must exists. All of them!!!", "phalconplus/RPC/Server/AbstractServer.zep", 92);
		return;
	}
	ZEPHIR_OBS_NVAR(logId);
	if (zephir_array_isset_string_fetch(&logId, rawData, SS("logId"), 0 TSRMLS_CC)) {
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "logger", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_6, _5, "has", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_is_true(_6)) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_json_encode(_0, &(_0), request, 0  TSRMLS_CC);
		ZEPHIR_INIT_NVAR(message);
		ZEPHIR_CONCAT_SVSVSVSV(message, "RPC Request - logId: ", logId, ", invoke: ", service, "::", method, ", args: ", _0);
		_7 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_9);
		ZVAL_STRING(_9, "logger", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_8, _7, "get", NULL, 0, _9);
		zephir_check_temp_parameter(_9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _8, "log", NULL, 0, message);
		zephir_check_call_status();
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("eventsManager"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_10);
	zephir_create_array(_10, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(_10, service);
	zephir_array_fast_append(_10, method);
	zephir_array_fast_append(_10, request);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "backend-server:beforeDispatch", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _7, "fire", NULL, 0, _0, this_ptr, _10);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "callbyparams", NULL, 0, service, method, request);
	zephir_check_call_status();
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("eventsManager"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_12);
	zephir_create_array(_12, 4, 0 TSRMLS_CC);
	zephir_array_fast_append(_12, service);
	zephir_array_fast_append(_12, method);
	zephir_array_fast_append(_12, request);
	zephir_array_fast_append(_12, response);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "backend-server:afterDispatch", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _11, "fire", NULL, 0, _0, this_ptr, _12);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_0);
	ZVAL_STRING(_0, "logger", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_8, _13, "has", NULL, 0, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	if (zephir_is_true(_8)) {
		ZEPHIR_INIT_NVAR(_0);
		zephir_json_encode(_0, &(_0), response, 0  TSRMLS_CC);
		ZEPHIR_INIT_NVAR(message);
		ZEPHIR_CONCAT_SVSVSVSV(message, "RPC Response - logId: ", logId, ", invoke: ", service, "::", method, ", response: ", _0);
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_INIT_NVAR(_9);
		ZVAL_STRING(_9, "logger", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_15, _14, "get", NULL, 0, _9);
		zephir_check_temp_parameter(_9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _15, "log", NULL, 0, message);
		zephir_check_call_status();
	}
	RETURN_CCTOR(response);

}

