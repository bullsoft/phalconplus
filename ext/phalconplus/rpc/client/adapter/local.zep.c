
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
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/variables.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(PhalconPlus_RPC_Client_Adapter_Local) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\RPC\\Client\\Adapter, Local, phalconplus, rpc_client_adapter_local, phalconplus_rpc_client_abstractclient_ce, phalconplus_rpc_client_adapter_local_method_entry, 0);

	zend_declare_property_null(phalconplus_rpc_client_adapter_local_ce, SL("config"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_rpc_client_adapter_local_ce, SL("di"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_RPC_Client_Adapter_Local, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di, di_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &di);



	zephir_update_property_zval(this_ptr, SL("di"), di);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "config");
	ZEPHIR_CALL_METHOD(&_0, di, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("config"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_RPC_Client_Adapter_Local, callByParams) {

	zend_bool _13$$4, _17$$4;
	zval _7, _32$$4, _33$$4, _21$$7;
	zend_class_entry *_5, *_26$$8;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *service_param = NULL, *method_param = NULL, *request = NULL, request_sub, serviceClass, serviceObj, response, _0, _1, _4, _6, _2$$3, _3$$3, _8$$4, _11$$4, _12$$4, _30$$4, _31$$4, _14$$5, _15$$5, _16$$5, _18$$6, _19$$6, _20$$6, tmp$$7, param$$7, paramClass$$7, _22$$7, _23$$7, _24$$8, _25$$8, _27$$9, _28$$9, _29$$9, _34$$10, _35$$10;
	zval service, method, _10$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&serviceClass);
	ZVAL_UNDEF(&serviceObj);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_30$$4);
	ZVAL_UNDEF(&_31$$4);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&tmp$$7);
	ZVAL_UNDEF(&param$$7);
	ZVAL_UNDEF(&paramClass$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&_23$$7);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_29$$9);
	ZVAL_UNDEF(&_34$$10);
	ZVAL_UNDEF(&_35$$10);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_32$$4);
	ZVAL_UNDEF(&_33$$4);
	ZVAL_UNDEF(&_21$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &service_param, &method_param, &request);

	if (UNEXPECTED(Z_TYPE_P(service_param) != IS_STRING && Z_TYPE_P(service_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'service' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(service_param) == IS_STRING)) {
		zephir_get_strval(&service, service_param);
	} else {
		ZEPHIR_INIT_VAR(&service);
		ZVAL_EMPTY_STRING(&service);
	}
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


	ZEPHIR_INIT_VAR(&_1);
	zephir_ucfirst(&_1, &service);
	ZEPHIR_INIT_VAR(&serviceClass);
	ZEPHIR_CONCAT_VS(&serviceClass, &_1, "Service");
	if (!(zephir_class_exists(&serviceClass, 1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "Service class not exists: ", &serviceClass);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 7, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalconplus/RPC/Client/Adapter/Local.zep", 22 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&serviceObj);
	zephir_fetch_safe_class(&_4, &serviceClass);
	_5 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_4), Z_STRLEN_P(&_4), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&serviceObj, _5);
	if (zephir_has_constructor(&serviceObj TSRMLS_CC)) {
		zephir_read_property(&_6, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &serviceObj, "__construct", NULL, 0, &_6);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_7, &serviceObj);
	zephir_array_fast_append(&_7, &method);
	if (zephir_is_callable(&_7 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_8$$4);
		ZEPHIR_CONCAT_SV(&_8$$4, "ServerClass: ", &serviceClass);
		ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_9, 50, &_8$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_10$$4);
		ZEPHIR_CONCAT_SV(&_10$$4, "InvokeMethod: ", &method);
		ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_9, 50, &_10$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_11$$4);
		ZEPHIR_INIT_NVAR(&_11$$4);
		zephir_var_export_ex(&_11$$4, request TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_12$$4);
		ZEPHIR_CONCAT_SV(&_12$$4, "InputParam: ", &_11$$4);
		ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_9, 50, &_12$$4);
		zephir_check_call_status();
		_13$$4 = !(Z_TYPE_P(request) == IS_OBJECT);
		if (_13$$4) {
			_13$$4 = !(Z_TYPE_P(request) == IS_ARRAY);
		}
		if (_13$$4) {
			ZEPHIR_INIT_VAR(&_14$$5);
			object_init_ex(&_14$$5, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_VAR(&_15$$5);
			zephir_json_encode(&_15$$5, request, 0 );
			ZEPHIR_INIT_VAR(&_16$$5);
			ZEPHIR_CONCAT_SV(&_16$$5, "Your input is not allowed. Request: ", &_15$$5);
			ZEPHIR_CALL_METHOD(NULL, &_14$$5, "__construct", NULL, 7, &_16$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_14$$5, "phalconplus/RPC/Client/Adapter/Local.zep", 31 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		_17$$4 = Z_TYPE_P(request) == IS_OBJECT;
		if (_17$$4) {
			_17$$4 = !((zephir_instance_of_ev(request, phalconplus_base_protobuffer_ce TSRMLS_CC)));
		}
		if (_17$$4) {
			ZEPHIR_INIT_VAR(&_18$$6);
			object_init_ex(&_18$$6, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_VAR(&_19$$6);
			zephir_get_class(&_19$$6, request, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_20$$6);
			ZEPHIR_CONCAT_SV(&_20$$6, "Your input is not allowed. Request: ", &_19$$6);
			ZEPHIR_CALL_METHOD(NULL, &_18$$6, "__construct", NULL, 7, &_20$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_18$$6, "phalconplus/RPC/Client/Adapter/Local.zep", 35 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} else if (Z_TYPE_P(request) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&tmp$$7);
			array_init(&tmp$$7);
			ZEPHIR_CPY_WRT(&tmp$$7, request);
			ZEPHIR_INIT_VAR(&param$$7);
			object_init_ex(&param$$7, zephir_get_internal_ce(SL("reflectionparameter")));
			ZEPHIR_INIT_VAR(&_21$$7);
			zephir_create_array(&_21$$7, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&_21$$7, &serviceClass);
			zephir_array_fast_append(&_21$$7, &method);
			ZVAL_LONG(&_22$$7, 0);
			ZEPHIR_CALL_METHOD(NULL, &param$$7, "__construct", NULL, 2, &_21$$7, &_22$$7);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_23$$7, &param$$7, "getclass", NULL, 3);
			zephir_check_call_status();
			if (zephir_is_true(&_23$$7)) {
				ZEPHIR_CALL_METHOD(&_24$$8, &param$$7, "getclass", NULL, 3);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&paramClass$$7, &_24$$8, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(request);
				zephir_fetch_safe_class(&_25$$8, &paramClass$$7);
				_26$$8 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_25$$8), Z_STRLEN_P(&_25$$8), ZEND_FETCH_CLASS_AUTO);
				object_init_ex(request, _26$$8);
				if (zephir_has_constructor(request TSRMLS_CC)) {
					ZEPHIR_CALL_METHOD(NULL, request, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(NULL, request, "softclone", NULL, 0, &tmp$$7);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(&_27$$9);
				object_init_ex(&_27$$9, zend_exception_get_default(TSRMLS_C));
				ZEPHIR_INIT_VAR(&_28$$9);
				zephir_json_encode(&_28$$9, request, 0 );
				ZEPHIR_INIT_VAR(&_29$$9);
				ZEPHIR_CONCAT_SVSVSV(&_29$$9, "Service class:method definition is invalid. Detail: ", &service, " : ", &method, ". Request: ", &_28$$9);
				ZEPHIR_CALL_METHOD(NULL, &_27$$9, "__construct", NULL, 7, &_29$$9);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_27$$9, "phalconplus/RPC/Client/Adapter/Local.zep", 45 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		ZEPHIR_INIT_VAR(&_30$$4);
		ZEPHIR_INIT_NVAR(&_30$$4);
		zephir_var_export_ex(&_30$$4, request TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_31$$4);
		ZEPHIR_CONCAT_SV(&_31$$4, "Finally InputParam: ", &_30$$4);
		ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_9, 50, &_31$$4);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_32$$4);
		zephir_create_array(&_32$$4, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_32$$4, &serviceObj);
		zephir_array_fast_append(&_32$$4, &method);
		ZEPHIR_INIT_VAR(&_33$$4);
		zephir_create_array(&_33$$4, 1, 0 TSRMLS_CC);
		zephir_array_fast_append(&_33$$4, request);
		ZEPHIR_INIT_VAR(&response);
		ZEPHIR_CALL_USER_FUNC_ARRAY(&response, &_32$$4, &_33$$4);
		zephir_check_call_status();
		RETURN_CCTOR(&response);
	} else {
		ZEPHIR_INIT_VAR(&_34$$10);
		object_init_ex(&_34$$10, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_35$$10);
		ZEPHIR_CONCAT_SVSV(&_35$$10, "No service found: ", &serviceClass, "::", &method);
		ZEPHIR_CALL_METHOD(NULL, &_34$$10, "__construct", NULL, 7, &_35$$10);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_34$$10, "phalconplus/RPC/Client/Adapter/Local.zep", 52 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

}

PHP_METHOD(PhalconPlus_RPC_Client_Adapter_Local, callByObject) {

	zend_bool _8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *rawData_param = NULL, service, method, request, _0, _1, _7, _9, _3$$3, _4$$3, _5$$4, _6$$4;
	zval rawData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawData);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rawData_param);

	zephir_get_arrval(&rawData, rawData_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_var_export_ex(&_0, &rawData TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "Local callByObject: ", &_0);
	ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_2, 50, &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&service);
	if (!(zephir_array_isset_string_fetch(&service, &rawData, SL("service"), 0))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SVS(&_4$$3, "service ", &service, " not exists");
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 7, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalconplus/RPC/Client/Adapter/Local.zep", 63 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&method);
	if (!(zephir_array_isset_string_fetch(&method, &rawData, SL("method"), 0))) {
		ZEPHIR_INIT_VAR(&_5$$4);
		object_init_ex(&_5$$4, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_6$$4);
		ZEPHIR_CONCAT_SVS(&_6$$4, "method ", &method, " not exists");
		ZEPHIR_CALL_METHOD(NULL, &_5$$4, "__construct", NULL, 7, &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_5$$4, "phalconplus/RPC/Client/Adapter/Local.zep", 67 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&request);
	if (!(zephir_array_isset_string_fetch(&request, &rawData, SL("args"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "args not exists", "phalconplus/RPC/Client/Adapter/Local.zep", 71);
		return;
	}
	ZEPHIR_INIT_VAR(&_7);
	zephir_fast_trim(&_7, &service, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(&service, &_7);
	ZEPHIR_INIT_NVAR(&_7);
	zephir_fast_trim(&_7, &method, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	ZEPHIR_CPY_WRT(&method, &_7);
	_8 = ZEPHIR_IS_EMPTY(&service);
	if (!(_8)) {
		_8 = ZEPHIR_IS_EMPTY(&method);
	}
	if (_8) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "service:method(args) must exists. All of them!!!", "phalconplus/RPC/Client/Adapter/Local.zep", 78);
		return;
	}
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_SVSVS(&_9, "Invoke callByParams with (", &service, ", ", &method, ")");
	ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_2, 50, &_9);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callbyparams", NULL, 66, &service, &method, &request);
	zephir_check_call_status();
	RETURN_MM();

}

