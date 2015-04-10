
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
#include "kernel/variables.h"


ZEPHIR_INIT_CLASS(PhalconPlus_RPC_Server_AbstractServer) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\RPC\\Server, AbstractServer, phalconplus, rpc_server_abstractserver, phalconplus_rpc_server_abstractserver_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalconplus_rpc_server_abstractserver_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_rpc_server_abstractserver_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalconplus_rpc_server_abstractserver_ce, SL("phpOnly"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_RPC_Server_AbstractServer, __construct) {

}

PHP_METHOD(PhalconPlus_RPC_Server_AbstractServer, requestCheck) {

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL;
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
	ZEPHIR_CALL_METHOD(NULL, serviceReflection, "__construct", &_0, service);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&methodReflection, serviceReflection, "getmethod", &_1, method);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_RPC_Server_AbstractServer, callByParams) {

	zend_class_entry *_9, *_14;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_2 = NULL, *_16, *_17;
	zval *service_param = NULL, *method_param = NULL, *request = NULL, *serviceClass = NULL, *_0 = NULL, *_1, *tmp = NULL, *param, *paramClass = NULL, *_3 = NULL, *_5 = NULL, *_7 = NULL, *_8 = NULL, *_10 = NULL, *_11 = NULL, *serviceObj, *response = NULL, *e = NULL, *_13 = NULL, *_15, *_18;
	zval *service = NULL, *method = NULL, *_19;

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
	if (zephir_instance_of_ev(request, phalconplus_base_protobuffer_ce TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("phpOnly"), (1) ? ZEPHIR_GLOBAL(global_true) : ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	} else if (Z_TYPE_P(request) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(tmp, request);
		ZEPHIR_INIT_VAR(param);
		object_init_ex(param, zephir_get_internal_ce(SS("reflectionparameter") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_2);
		zephir_create_array(_2, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_2, serviceClass);
		zephir_array_fast_append(_2, method);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_CALL_METHOD(NULL, param, "__construct", &_4, _2, _3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5, param, "getclass", &_6);
		zephir_check_call_status();
		if (zephir_is_true(_5)) {
			ZEPHIR_CALL_METHOD(&_7, param, "getclass", &_6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&paramClass, _7, "getname", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(request);
			zephir_fetch_safe_class(_8, paramClass);
			_9 = zend_fetch_class(Z_STRVAL_P(_8), Z_STRLEN_P(_8), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(request, _9);
			if (zephir_has_constructor(request TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, request, "__construct", NULL);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(NULL, request, "softclone", NULL, tmp);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_VAR(_10);
			zephir_json_encode(_10, &(_10), request, 0  TSRMLS_CC);
			ZEPHIR_INIT_VAR(_11);
			ZEPHIR_CONCAT_SVSVSV(_11, "Service class:method definition is invalid. Detail: ", service, " : ", method, ". Request: ", _10);
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_12, _11);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "phalconplus/RPC/Server/AbstractServer.zep", 36 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_NVAR(_10);
		zephir_json_encode(_10, &(_10), request, 0  TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_11);
		ZEPHIR_CONCAT_SV(_11, "Your input is not allowed. Request: ", _10);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_12, _11);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "phalconplus/RPC/Server/AbstractServer.zep", 39 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "requestcheck", NULL, serviceClass, method, request);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(serviceObj);
	zephir_fetch_safe_class(_13, serviceClass);
	_14 = zend_fetch_class(Z_STRVAL_P(_13), Z_STRLEN_P(_13), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(serviceObj, _14);
	if (zephir_has_constructor(serviceObj TSRMLS_CC)) {
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, serviceObj, "__construct", NULL, _15);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(_2);
	zephir_create_array(_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_2, serviceObj);
	zephir_array_fast_append(_2, method);
	if (zephir_is_callable(_2 TSRMLS_CC)) {

		/* try_start_1: */

			ZEPHIR_INIT_NVAR(_3);
			ZEPHIR_INIT_VAR(_16);
			zephir_create_array(_16, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(_16, serviceObj);
			zephir_array_fast_append(_16, method);
			ZEPHIR_INIT_VAR(_17);
			zephir_create_array(_17, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(_17, request);
			ZEPHIR_CALL_USER_FUNC_ARRAY(_3, _16, _17);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CPY_WRT(response, _3);

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
		ZEPHIR_INIT_NVAR(_3);
		_18 = zephir_fetch_nproperty_this(this_ptr, SL("phpOnly"), PH_NOISY_CC);
		if (ZEPHIR_IS_TRUE(_18)) {
			ZEPHIR_CPY_WRT(_3, response);
		} else {
			ZEPHIR_CALL_METHOD(&_3, response, "toarray", NULL);
			zephir_check_call_status();
		}
		RETURN_CCTOR(_3);
	} else {
		object_init_ex(_3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_19);
		ZEPHIR_CONCAT_SVSV(_19, "Service:method not found. Detail: ", service, " : ", method);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_12, _19);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "phalconplus/RPC/Server/AbstractServer.zep", 55 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

}

/**
 *
 * @param array rawData
 * <code> 
 *     rawData = ["service":"Demo", "method":"demo", "args": <ProtoBuffer>]
 * </code>
 * @return <ProtoBuffer>
 * @throw \Exception
 *
 */
PHP_METHOD(PhalconPlus_RPC_Server_AbstractServer, callByObject) {

	zend_bool _6;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL;
	zval *rawData_param = NULL, *service = NULL, *method = NULL, *request, *_0, *_1, *_3 = NULL, *_4 = NULL, _7;
	zval *rawData = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rawData_param);

	zephir_get_arrval(rawData, rawData_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_var_export_ex(_0, &(rawData) TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SV(_1, "Remote callByObject: ", _0);
	ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_2, _1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(service);
	if (!(zephir_array_isset_string_fetch(&service, rawData, SS("service"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SVS(_4, "service ", service, " not exists");
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "phalconplus/RPC/Server/AbstractServer.zep", 76 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(method);
	if (!(zephir_array_isset_string_fetch(&method, rawData, SS("method"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SVS(_4, "method ", method, " not exists");
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_5, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "phalconplus/RPC/Server/AbstractServer.zep", 80 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(request);
	if (!(zephir_array_isset_string_fetch(&request, rawData, SS("args"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "args not exists", "phalconplus/RPC/Server/AbstractServer.zep", 84);
		return;
	}
	ZEPHIR_INIT_NVAR(_3);
	zephir_fast_trim(_3, service, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(service, _3);
	ZEPHIR_INIT_NVAR(_3);
	zephir_fast_trim(_3, method, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(method, _3);
	_6 = ZEPHIR_IS_EMPTY(service);
	if (!(_6)) {
		_6 = ZEPHIR_IS_EMPTY(method);
	}
	if (_6) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "service:method(args) must exists. All of them!!!", "phalconplus/RPC/Server/AbstractServer.zep", 91);
		return;
	}
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "Invoke callByParams", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_2, &_7);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callbyparams", NULL, service, method, request);
	zephir_check_call_status();
	RETURN_MM();

}

