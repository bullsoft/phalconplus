
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/variables.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Client_Adapter_Local) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Rpc\\Client\\Adapter, Local, phalconplus, rpc_client_adapter_local, phalconplus_rpc_client_abstractclient_ce, phalconplus_rpc_client_adapter_local_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Local, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di, di_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &di);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, di);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Local, callByParams) {

	zval _25$$10, _42$$15;
	zend_bool _12, _45, _24$$8;
	zend_class_entry *_6, *_30$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *service_param = NULL, *method_param = NULL, *request = NULL, request_sub, __$true, __$false, serviceObj, methodReflection, serviceClass, message, _0, _1, _5, _7, e, _8, _13, _16, _17, _18, _23, _36, _37, response, _2$$3, _3$$3, _9$$5, _10$$5, _11$$5, _14$$6, _19$$7, _20$$7, _21$$7, _22$$7, tmp$$10, param$$10, paramClass$$10, _26$$10, _27$$10, _28$$11, _29$$11, _31$$12, _32$$12, _33$$12, _34$$13, _35$$13, _38$$14, _39$$14, _40$$14, _41$$14, _43$$16, _44$$16, _46$$17, _47$$17, _48$$17;
	zval service, method, _15$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&request_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&serviceObj);
	ZVAL_UNDEF(&methodReflection);
	ZVAL_UNDEF(&serviceClass);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$7);
	ZVAL_UNDEF(&_21$$7);
	ZVAL_UNDEF(&_22$$7);
	ZVAL_UNDEF(&tmp$$10);
	ZVAL_UNDEF(&param$$10);
	ZVAL_UNDEF(&paramClass$$10);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_27$$10);
	ZVAL_UNDEF(&_28$$11);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_33$$12);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_38$$14);
	ZVAL_UNDEF(&_39$$14);
	ZVAL_UNDEF(&_40$$14);
	ZVAL_UNDEF(&_41$$14);
	ZVAL_UNDEF(&_43$$16);
	ZVAL_UNDEF(&_44$$16);
	ZVAL_UNDEF(&_46$$17);
	ZVAL_UNDEF(&_47$$17);
	ZVAL_UNDEF(&_48$$17);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_42$$15);

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
	ZEPHIR_INIT_VAR(&message);
	ZVAL_STRING(&message, "");
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
		zephir_throw_exception_debug(&_2$$3, "phalconplus/Rpc/Client/Adapter/Local.zep", 22);
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
			zephir_throw_exception_debug(&_9$$5, "phalconplus/Rpc/Client/Adapter/Local.zep", 30);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_12 = Z_TYPE_P(request) == IS_NULL;
	if (_12) {
		ZEPHIR_CALL_METHOD(&_13, &methodReflection, "getnumberofrequiredparameters", NULL, 31);
		zephir_check_call_status();
		_12 = ZEPHIR_GT_LONG(&_13, 0);
	}
	if (_12) {
		ZEPHIR_INIT_VAR(&_14$$6);
		object_init_ex(&_14$$6, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_15$$6);
		ZEPHIR_CONCAT_VSVS(&_15$$6, &service, "::", &method, " need required params");
		ZEPHIR_CALL_METHOD(NULL, &_14$$6, "__construct", &_4, 2, &_15$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_14$$6, "phalconplus/Rpc/Client/Adapter/Local.zep", 34);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_16, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_18);
	ZVAL_STRING(&_18, "logger");
	ZEPHIR_CALL_METHOD(&_17, &_16, "has", NULL, 0, &_18);
	zephir_check_call_status();
	if (zephir_is_true(&_17)) {
		ZEPHIR_INIT_VAR(&_19$$7);
		ZEPHIR_INIT_NVAR(&_19$$7);
		zephir_var_export_ex(&_19$$7, request);
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_SVSVSV(&message, "LocalRpc> dispatch to '", &serviceClass, "::", &method, "(request)' where request is: ", &_19$$7);
		zephir_read_property(&_20$$7, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_22$$7);
		ZVAL_STRING(&_22$$7, "logger");
		ZEPHIR_CALL_METHOD(&_21$$7, &_20$$7, "get", NULL, 0, &_22$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_21$$7, "log", NULL, 0, &message);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_23, &methodReflection, "getnumberofparameters", NULL, 5);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(&_23, 0)) {
		_24$$8 = Z_TYPE_P(request) == IS_OBJECT;
		if (_24$$8) {
			_24$$8 = (zephir_instance_of_ev(request, phalconplus_base_protobuffer_ce));
		}
		if (_24$$8) {
			if (1) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("phpOnly"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("phpOnly"), &__$false);
			}
		} else if (Z_TYPE_P(request) == IS_ARRAY) {
			ZEPHIR_CPY_WRT(&tmp$$10, request);
			ZEPHIR_INIT_VAR(&param$$10);
			ZVAL_NULL(&param$$10);
			ZEPHIR_INIT_VAR(&paramClass$$10);
			ZVAL_STRING(&paramClass$$10, "");
			ZEPHIR_INIT_NVAR(&param$$10);
			object_init_ex(&param$$10, zephir_get_internal_ce(SL("reflectionparameter")));
			ZEPHIR_INIT_VAR(&_25$$10);
			zephir_create_array(&_25$$10, 2, 0);
			zephir_array_fast_append(&_25$$10, &serviceClass);
			zephir_array_fast_append(&_25$$10, &method);
			ZVAL_LONG(&_26$$10, 0);
			ZEPHIR_CALL_METHOD(NULL, &param$$10, "__construct", NULL, 6, &_25$$10, &_26$$10);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_27$$10, &param$$10, "getclass", NULL, 7);
			zephir_check_call_status();
			if (zephir_is_true(&_27$$10)) {
				ZEPHIR_CALL_METHOD(&_28$$11, &param$$10, "getclass", NULL, 7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&paramClass$$10, &_28$$11, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(request);
				zephir_fetch_safe_class(&_29$$11, &paramClass$$10);
				_30$$11 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_29$$11), Z_STRLEN_P(&_29$$11), ZEND_FETCH_CLASS_AUTO);
				if(!_30$$11) {
					RETURN_MM_NULL();
				}
				object_init_ex(request, _30$$11);
				if (zephir_has_constructor(request)) {
					ZEPHIR_CALL_METHOD(NULL, request, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(NULL, request, "softclone", NULL, 0, &tmp$$10);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(&_31$$12);
				object_init_ex(&_31$$12, phalconplus_base_exception_ce);
				ZEPHIR_INIT_VAR(&_32$$12);
				zephir_json_encode(&_32$$12, request, 0 );
				ZEPHIR_INIT_VAR(&_33$$12);
				ZEPHIR_CONCAT_SVSVSV(&_33$$12, "Service class:method definition is invalid. Detail: ", &service, " : ", &method, ". Request: ", &_32$$12);
				ZEPHIR_CALL_METHOD(NULL, &_31$$12, "__construct", &_4, 2, &_33$$12);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_31$$12, "phalconplus/Rpc/Client/Adapter/Local.zep", 56);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_INIT_VAR(&_34$$13);
			object_init_ex(&_34$$13, phalconplus_base_exception_ce);
			ZEPHIR_INIT_VAR(&_35$$13);
			ZEPHIR_CONCAT_SVSV(&_35$$13, "No service found: ", &serviceClass, "::", &method);
			ZEPHIR_CALL_METHOD(NULL, &_34$$13, "__construct", &_4, 2, &_35$$13);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_34$$13, "phalconplus/Rpc/Client/Adapter/Local.zep", 61);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property(&_36, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_18);
	ZVAL_STRING(&_18, "logger");
	ZEPHIR_CALL_METHOD(&_37, &_36, "has", NULL, 0, &_18);
	zephir_check_call_status();
	if (zephir_is_true(&_37)) {
		ZEPHIR_INIT_VAR(&_38$$14);
		ZEPHIR_INIT_NVAR(&_38$$14);
		zephir_var_export_ex(&_38$$14, request);
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_SV(&message, "LocalRpc> finally requst transformed to: ", &_38$$14);
		zephir_read_property(&_39$$14, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_41$$14);
		ZVAL_STRING(&_41$$14, "logger");
		ZEPHIR_CALL_METHOD(&_40$$14, &_39$$14, "get", NULL, 0, &_41$$14);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_40$$14, "log", NULL, 0, &message);
		zephir_check_call_status();
	}

	/* try_start_2: */

		ZEPHIR_INIT_VAR(&_42$$15);
		zephir_create_array(&_42$$15, 1, 0);
		zephir_array_fast_append(&_42$$15, request);
		ZEPHIR_CALL_METHOD(&response, &methodReflection, "invokeargs", NULL, 11, &serviceObj, &_42$$15);
		zephir_check_call_status_or_jump(try_end_2);

	try_end_2:

	if (EG(exception)) {
		ZEPHIR_INIT_NVAR(&_18);
		ZVAL_OBJ(&_18, EG(exception));
		Z_ADDREF_P(&_18);
		if (zephir_instance_of_ev(&_18, zend_exception_get_default(TSRMLS_C))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_18);
			ZEPHIR_INIT_VAR(&_43$$16);
			object_init_ex(&_43$$16, phalconplus_base_exception_ce);
			ZEPHIR_CALL_METHOD(&_44$$16, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_43$$16, "__construct", &_4, 2, &_44$$16);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_43$$16, "phalconplus/Rpc/Client/Adapter/Local.zep", 76);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_45 = Z_TYPE_P(&response) == IS_OBJECT;
	if (_45) {
		_45 = !((zephir_instance_of_ev(&response, phalconplus_base_protobuffer_ce)));
	}
	if (_45) {
		ZEPHIR_INIT_VAR(&_46$$17);
		object_init_ex(&_46$$17, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_47$$17);
		zephir_get_class(&_47$$17, &response, 0);
		ZEPHIR_INIT_VAR(&_48$$17);
		ZEPHIR_CONCAT_SVS(&_48$$17, "Your output is not allowed. Response: ", &_47$$17, ". We expect scalar type or <ProtoBuffer>");
		ZEPHIR_CALL_METHOD(NULL, &_46$$17, "__construct", &_4, 2, &_48$$17);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_46$$17, "phalconplus/Rpc/Client/Adapter/Local.zep", 80);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (Z_TYPE_P(&response) == IS_RESOURCE) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Your output is not allowed. Response: #Resource.", "phalconplus/Rpc/Client/Adapter/Local.zep", 82);
		return;
	}
	RETURN_CCTOR(&response);

}

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Local, callByObject) {

	zend_bool _15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rawData_param = NULL, service, method, request, message, _0, _1, _2, _12, _13, _14, _16, _17, _3$$3, _4$$3, _5$$3, _6$$3, _7$$4, _8$$4, _10$$5, _11$$5, _18$$8, _19$$8, _20$$8;
	zval rawData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawData);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rawData_param);

	zephir_get_arrval(&rawData, rawData_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "logger");
	ZEPHIR_CALL_METHOD(&_1, &_0, "has", NULL, 0, &_2);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_INIT_NVAR(&_3$$3);
		zephir_var_export_ex(&_3$$3, &rawData);
		ZEPHIR_INIT_VAR(&message);
		ZEPHIR_CONCAT_SV(&message, "LocalRpc> callByObject: ", &_3$$3);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZVAL_STRING(&_6$$3, "logger");
		ZEPHIR_CALL_METHOD(&_5$$3, &_4$$3, "get", NULL, 0, &_6$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_5$$3, "log", NULL, 0, &message);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&service);
	if (!(zephir_array_isset_string_fetch(&service, &rawData, SL("service"), 0))) {
		ZEPHIR_INIT_VAR(&_7$$4);
		object_init_ex(&_7$$4, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_8$$4);
		ZEPHIR_CONCAT_SVS(&_8$$4, "service ", &service, " not exists");
		ZEPHIR_CALL_METHOD(NULL, &_7$$4, "__construct", &_9, 2, &_8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$4, "phalconplus/Rpc/Client/Adapter/Local.zep", 97);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&method);
	if (!(zephir_array_isset_string_fetch(&method, &rawData, SL("method"), 0))) {
		ZEPHIR_INIT_VAR(&_10$$5);
		object_init_ex(&_10$$5, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_11$$5);
		ZEPHIR_CONCAT_SVS(&_11$$5, "method ", &method, " not exists");
		ZEPHIR_CALL_METHOD(NULL, &_10$$5, "__construct", &_9, 2, &_11$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$5, "phalconplus/Rpc/Client/Adapter/Local.zep", 100);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&request);
	if (!(zephir_array_isset_string_fetch(&request, &rawData, SL("args"), 0))) {
		ZEPHIR_INIT_NVAR(&request);
		ZVAL_NULL(&request);
	}
	zephir_read_property(&_12, this_ptr, ZEND_STRL("namePrefix"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_fast_trim(&_2, &service, NULL , ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_VAR(&_13);
	ZEPHIR_CONCAT_VV(&_13, &_12, &_2);
	ZEPHIR_CPY_WRT(&service, &_13);
	ZEPHIR_INIT_VAR(&_14);
	zephir_fast_trim(&_14, &method, NULL , ZEPHIR_TRIM_BOTH);
	ZEPHIR_CPY_WRT(&method, &_14);
	_15 = ZEPHIR_IS_EMPTY(&service);
	if (!(_15)) {
		_15 = ZEPHIR_IS_EMPTY(&method);
	}
	if (_15) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "service:method(args) must exists. All of them!!!", "phalconplus/Rpc/Client/Adapter/Local.zep", 111);
		return;
	}
	zephir_read_property(&_16, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_14);
	ZVAL_STRING(&_14, "logger");
	ZEPHIR_CALL_METHOD(&_17, &_16, "has", NULL, 0, &_14);
	zephir_check_call_status();
	if (zephir_is_true(&_17)) {
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_SVSVS(&message, "LocalRpc> callByParams with (", &service, ", ", &method, ")");
		zephir_read_property(&_18$$8, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_20$$8);
		ZVAL_STRING(&_20$$8, "logger");
		ZEPHIR_CALL_METHOD(&_19$$8, &_18$$8, "get", NULL, 0, &_20$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_19$$8, "log", NULL, 0, &message);
		zephir_check_call_status();
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "callbyparams", NULL, 146, &service, &method, &request);
	zephir_check_call_status();
	RETURN_MM();

}

