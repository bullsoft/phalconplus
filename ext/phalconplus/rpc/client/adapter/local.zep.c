
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
#include "kernel/operators.h"
#include "kernel/variables.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Client_Adapter_Local) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Rpc\\Client\\Adapter, Local, phalconplus, rpc_client_adapter_local, phalconplus_rpc_client_abstractclient_ce, phalconplus_rpc_client_adapter_local_method_entry, 0);

	zend_declare_property_null(phalconplus_rpc_client_adapter_local_ce, SL("config"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phalconplus_rpc_client_adapter_local_ce, SL("di"), ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Local, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di, di_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &di);



	zephir_update_property_zval(this_ptr, ZEND_STRL("di"), di);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "config");
	ZEPHIR_CALL_METHOD(&_0, di, "get", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("config"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Local, callByParams) {

	zval _25$$9, _38$$13;
	zend_bool _15, _42, _22$$7;
	zend_class_entry *_6, *_30$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *service_param = NULL, *method_param = NULL, *request = NULL, request_sub, serviceObj, methodReflection, serviceClass, _0, _1, _5, _7, e, _8, _12, _16, _19, _36, _37, response, _39, _2$$3, _3$$3, _9$$5, _10$$5, _11$$5, _17$$6, _20$$7, _21$$7, _23$$8, _24$$8, tmp$$9, param$$9, paramClass$$9, _26$$9, _27$$9, _28$$10, _29$$10, _31$$11, _32$$11, _33$$11, _34$$12, _35$$12, _40$$14, _41$$14, _43$$15, _44$$15, _45$$15;
	zval service, method, _14, _18$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&serviceObj);
	ZVAL_UNDEF(&methodReflection);
	ZVAL_UNDEF(&serviceClass);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_39);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&tmp$$9);
	ZVAL_UNDEF(&param$$9);
	ZVAL_UNDEF(&paramClass$$9);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_29$$10);
	ZVAL_UNDEF(&_31$$11);
	ZVAL_UNDEF(&_32$$11);
	ZVAL_UNDEF(&_33$$11);
	ZVAL_UNDEF(&_34$$12);
	ZVAL_UNDEF(&_35$$12);
	ZVAL_UNDEF(&_40$$14);
	ZVAL_UNDEF(&_41$$14);
	ZVAL_UNDEF(&_43$$15);
	ZVAL_UNDEF(&_44$$15);
	ZVAL_UNDEF(&_45$$15);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_38$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &service_param, &method_param, &request);

	if (UNEXPECTED(Z_TYPE_P(service_param) != IS_STRING && Z_TYPE_P(service_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'service' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(service_param) == IS_STRING)) {
		zephir_get_strval(&service, service_param);
	} else {
		ZEPHIR_INIT_VAR(&service);
		ZVAL_EMPTY_STRING(&service);
	}
	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
		ZVAL_EMPTY_STRING(&method);
	}


	ZEPHIR_INIT_VAR(&serviceObj);
	ZVAL_NULL(&serviceObj);
	ZEPHIR_INIT_VAR(&methodReflection);
	ZVAL_NULL(&methodReflection);
	ZEPHIR_INIT_VAR(&serviceClass);
	ZVAL_STRING(&serviceClass, "");
	ZEPHIR_INIT_VAR(&_1);
	zephir_ucfirst(&_1, &service);
	ZEPHIR_INIT_NVAR(&serviceClass);
	ZEPHIR_CONCAT_VS(&serviceClass, &_1, "Service");
	if (!(zephir_class_exists(&serviceClass, 1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "Service class not exists: ", &serviceClass);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", &_4, 2, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalconplus/Rpc/Client/Adapter/Local.zep", 25);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(&serviceObj);
	zephir_fetch_safe_class(&_5, &serviceClass);
	_6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_5), Z_STRLEN_P(&_5), ZEND_FETCH_CLASS_AUTO);
	if(!_6) {
		RETURN_MM_NULL();
	}
	object_init_ex(&serviceObj, _6);
	if (zephir_has_constructor(&serviceObj)) {
		zephir_read_property(&_7, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &serviceObj, "__construct", NULL, 0, &_7);
		zephir_check_call_status();
	}

	/* try_start_1: */

		ZEPHIR_INIT_NVAR(&methodReflection);
		object_init_ex(&methodReflection, zephir_get_internal_ce(SL("reflectionmethod")));
		ZEPHIR_CALL_METHOD(NULL, &methodReflection, "__construct", NULL, 4, &serviceObj, &method);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_8);
		ZVAL_OBJ(&_8, EG(exception));
		Z_ADDREF_P(&_8);
		if (zephir_instance_of_ev(&_8, zephir_get_internal_ce(SL("reflectionexception")))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_8);
			ZEPHIR_INIT_VAR(&_9$$5);
			object_init_ex(&_9$$5, phalconplus_base_exception_ce);
			ZEPHIR_CALL_METHOD(&_10$$5, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_11$$5);
			ZEPHIR_CONCAT_SVSVSV(&_11$$5, "Service:method not found. Detail: ", &serviceClass, " : ", &method, ". RawException: ", &_10$$5);
			ZEPHIR_CALL_METHOD(NULL, &_9$$5, "__construct", &_4, 2, &_11$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$5, "phalconplus/Rpc/Client/Adapter/Local.zep", 33);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_CONCAT_SV(&_12, "ServerClass: ", &serviceClass);
	ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_13, 110, &_12);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_14);
	ZEPHIR_CONCAT_SV(&_14, "InvokeMethod: ", &method);
	ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_13, 110, &_14);
	zephir_check_call_status();
	_15 = Z_TYPE_P(request) == IS_NULL;
	if (_15) {
		ZEPHIR_CALL_METHOD(&_16, &methodReflection, "getnumberofrequiredparameters", NULL, 31);
		zephir_check_call_status();
		_15 = ZEPHIR_GT_LONG(&_16, 0);
	}
	if (_15) {
		ZEPHIR_INIT_VAR(&_17$$6);
		object_init_ex(&_17$$6, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_18$$6);
		ZEPHIR_CONCAT_VSVS(&_18$$6, &service, "::", &method, " need required params");
		ZEPHIR_CALL_METHOD(NULL, &_17$$6, "__construct", &_4, 2, &_18$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_17$$6, "phalconplus/Rpc/Client/Adapter/Local.zep", 39);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_19, &methodReflection, "getnumberofparameters", NULL, 5);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(&_19, 0)) {
		ZEPHIR_INIT_VAR(&_20$$7);
		ZEPHIR_INIT_NVAR(&_20$$7);
		zephir_var_export_ex(&_20$$7, request);
		ZEPHIR_INIT_VAR(&_21$$7);
		ZEPHIR_CONCAT_SV(&_21$$7, "InputParam: ", &_20$$7);
		ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_13, 110, &_21$$7);
		zephir_check_call_status();
		_22$$7 = Z_TYPE_P(request) == IS_OBJECT;
		if (_22$$7) {
			_22$$7 = (zephir_instance_of_ev(request, phalconplus_base_protobuffer_ce));
		}
		if (_22$$7) {
			ZEPHIR_INIT_VAR(&_23$$8);
			zephir_get_class(&_23$$8, request, 0);
			ZEPHIR_INIT_VAR(&_24$$8);
			ZEPHIR_CONCAT_SV(&_24$$8, "Request is object and instanceof ProtoBuffer: ", &_23$$8);
			ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_13, 110, &_24$$8);
			zephir_check_call_status();
		} else if (Z_TYPE_P(request) == IS_ARRAY) {
			ZEPHIR_CPY_WRT(&tmp$$9, request);
			ZEPHIR_INIT_VAR(&param$$9);
			ZVAL_NULL(&param$$9);
			ZEPHIR_INIT_VAR(&paramClass$$9);
			ZVAL_STRING(&paramClass$$9, "");
			ZEPHIR_INIT_NVAR(&param$$9);
			object_init_ex(&param$$9, zephir_get_internal_ce(SL("reflectionparameter")));
			ZEPHIR_INIT_VAR(&_25$$9);
			zephir_create_array(&_25$$9, 2, 0);
			zephir_array_fast_append(&_25$$9, &serviceClass);
			zephir_array_fast_append(&_25$$9, &method);
			ZVAL_LONG(&_26$$9, 0);
			ZEPHIR_CALL_METHOD(NULL, &param$$9, "__construct", NULL, 6, &_25$$9, &_26$$9);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_27$$9, &param$$9, "getclass", NULL, 7);
			zephir_check_call_status();
			if (zephir_is_true(&_27$$9)) {
				ZEPHIR_CALL_METHOD(&_28$$10, &param$$9, "getclass", NULL, 7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&paramClass$$9, &_28$$10, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(request);
				zephir_fetch_safe_class(&_29$$10, &paramClass$$9);
				_30$$10 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_29$$10), Z_STRLEN_P(&_29$$10), ZEND_FETCH_CLASS_AUTO);
				if(!_30$$10) {
					RETURN_MM_NULL();
				}
				object_init_ex(request, _30$$10);
				if (zephir_has_constructor(request)) {
					ZEPHIR_CALL_METHOD(NULL, request, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(NULL, request, "softclone", NULL, 0, &tmp$$9);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(&_31$$11);
				object_init_ex(&_31$$11, phalconplus_base_exception_ce);
				ZEPHIR_INIT_VAR(&_32$$11);
				zephir_json_encode(&_32$$11, request, 0 );
				ZEPHIR_INIT_VAR(&_33$$11);
				ZEPHIR_CONCAT_SVSVSV(&_33$$11, "Service class:method definition is invalid. Detail: ", &service, " : ", &method, ". Request: ", &_32$$11);
				ZEPHIR_CALL_METHOD(NULL, &_31$$11, "__construct", &_4, 2, &_33$$11);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_31$$11, "phalconplus/Rpc/Client/Adapter/Local.zep", 57);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_INIT_VAR(&_34$$12);
			object_init_ex(&_34$$12, phalconplus_base_exception_ce);
			ZEPHIR_INIT_VAR(&_35$$12);
			ZEPHIR_CONCAT_SVSV(&_35$$12, "No service found: ", &serviceClass, "::", &method);
			ZEPHIR_CALL_METHOD(NULL, &_34$$12, "__construct", &_4, 2, &_35$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_34$$12, "phalconplus/Rpc/Client/Adapter/Local.zep", 62);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_36);
	ZEPHIR_INIT_NVAR(&_36);
	zephir_var_export_ex(&_36, request);
	ZEPHIR_INIT_VAR(&_37);
	ZEPHIR_CONCAT_SV(&_37, "Finally Requst: ", &_36);
	ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_13, 110, &_37);
	zephir_check_call_status();

	/* try_start_2: */

		ZEPHIR_INIT_VAR(&_38$$13);
		zephir_create_array(&_38$$13, 1, 0);
		zephir_array_fast_append(&_38$$13, request);
		ZEPHIR_CALL_METHOD(&response, &methodReflection, "invokeargs", NULL, 11, &serviceObj, &_38$$13);
		zephir_check_call_status_or_jump(try_end_2);

	try_end_2:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_39);
		ZVAL_OBJ(&_39, EG(exception));
		Z_ADDREF_P(&_39);
		if (zephir_instance_of_ev(&_39, zend_exception_get_default(TSRMLS_C))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_39);
			ZEPHIR_INIT_VAR(&_40$$14);
			object_init_ex(&_40$$14, phalconplus_base_exception_ce);
			ZEPHIR_CALL_METHOD(&_41$$14, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_40$$14, "__construct", &_4, 2, &_41$$14);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_40$$14, "phalconplus/Rpc/Client/Adapter/Local.zep", 74);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_42 = Z_TYPE_P(&response) == IS_OBJECT;
	if (_42) {
		_42 = !((zephir_instance_of_ev(&response, phalconplus_base_protobuffer_ce)));
	}
	if (_42) {
		ZEPHIR_INIT_VAR(&_43$$15);
		object_init_ex(&_43$$15, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_44$$15);
		zephir_get_class(&_44$$15, &response, 0);
		ZEPHIR_INIT_VAR(&_45$$15);
		ZEPHIR_CONCAT_SVS(&_45$$15, "Your output is not allowed. Response: ", &_44$$15, ". We expect scalar type or <ProtoBuffer>");
		ZEPHIR_CALL_METHOD(NULL, &_43$$15, "__construct", &_4, 2, &_45$$15);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_43$$15, "phalconplus/Rpc/Client/Adapter/Local.zep", 78);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (Z_TYPE_P(&response) == IS_RESOURCE) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Your output is not allowed. Response: #Resource.", "phalconplus/Rpc/Client/Adapter/Local.zep", 80);
		return;
	}
	RETURN_CCTOR(&response);

}

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Local, callByObject) {

	zend_bool _12;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL;
	zval *rawData_param = NULL, service, method, request, _0, _1, _8, _9, _10, _11, _3$$3, _4$$3, _6$$4, _7$$4;
	zval rawData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawData);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rawData_param);

	zephir_get_arrval(&rawData, rawData_param);


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_var_export_ex(&_0, &rawData);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "Local callByObject: ", &_0);
	ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_2, 110, &_1);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&service);
	if (!(zephir_array_isset_string_fetch(&service, &rawData, SL("service"), 0))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SVS(&_4$$3, "service ", &service, " not exists");
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", &_5, 2, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalconplus/Rpc/Client/Adapter/Local.zep", 92);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&method);
	if (!(zephir_array_isset_string_fetch(&method, &rawData, SL("method"), 0))) {
		ZEPHIR_INIT_VAR(&_6$$4);
		object_init_ex(&_6$$4, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_7$$4);
		ZEPHIR_CONCAT_SVS(&_7$$4, "method ", &method, " not exists");
		ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", &_5, 2, &_7$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$4, "phalconplus/Rpc/Client/Adapter/Local.zep", 95);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&request);
	if (!(zephir_array_isset_string_fetch(&request, &rawData, SL("args"), 0))) {
		ZEPHIR_INIT_NVAR(&request);
		ZVAL_NULL(&request);
	}
	zephir_read_property(&_8, this_ptr, ZEND_STRL("namePrefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_9);
	zephir_fast_trim(&_9, &service, NULL , ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CONCAT_VV(&_10, &_8, &_9);
	ZEPHIR_CPY_WRT(&service, &_10);
	ZEPHIR_INIT_VAR(&_11);
	zephir_fast_trim(&_11, &method, NULL , ZEPHIR_TRIM_BOTH);
	ZEPHIR_CPY_WRT(&method, &_11);
	_12 = ZEPHIR_IS_EMPTY(&service);
	if (!(_12)) {
		_12 = ZEPHIR_IS_EMPTY(&method);
	}
	if (_12) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "service:method(args) must exists. All of them!!!", "phalconplus/Rpc/Client/Adapter/Local.zep", 106);
		return;
	}
	ZEPHIR_INIT_NVAR(&_10);
	ZEPHIR_CONCAT_SVSVS(&_10, "Invoke callByParams with (", &service, ", ", &method, ")");
	ZEPHIR_CALL_FUNCTION(NULL, "error_log", &_2, 110, &_10);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callbyparams", NULL, 146, &service, &method, &request);
	zephir_check_call_status();
	RETURN_MM();

}

