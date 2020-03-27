
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Server_AbstractServer) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Rpc\\Server, AbstractServer, phalconplus, rpc_server_abstractserver, phalconplus_rpc_server_abstractserver_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalconplus_rpc_server_abstractserver_ce, SL("di"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalconplus_rpc_server_abstractserver_ce, SL("phpOnly"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_rpc_server_abstractserver_ce, SL("eventsManager"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Rpc_Server_AbstractServer, getDi) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "di");

}

PHP_METHOD(PhalconPlus_Rpc_Server_AbstractServer, getPhpOnly) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "phpOnly");

}

PHP_METHOD(PhalconPlus_Rpc_Server_AbstractServer, __construct) {

}

PHP_METHOD(PhalconPlus_Rpc_Server_AbstractServer, callByParams) {

	zval _29, _35, _13$$8, _31$$12;
	zend_class_entry *_26, *_18$$9;
	zend_bool _7, _37, _42, _12$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *service_param = NULL, *method_param = NULL, *request = NULL, request_sub, __$true, __$false, __$null, serviceClass, methodReflection, serviceObj, response, e, _0, _1, _2, _8, _11, _25, _27, _28, _30, _34, _36, _41, _3$$4, _4$$4, _5$$4, _9$$5, tmp$$8, param$$8, paramClass$$8, _14$$8, _15$$8, _16$$9, _17$$9, _19$$10, _20$$10, _21$$10, _22$$11, _23$$11, _24$$11, _32$$13, _33$$13, _38$$14, _39$$14, _40$$14;
	zval service, method, _10$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&request_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&serviceClass);
	ZVAL_UNDEF(&methodReflection);
	ZVAL_UNDEF(&serviceObj);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&tmp$$8);
	ZVAL_UNDEF(&param$$8);
	ZVAL_UNDEF(&paramClass$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_38$$14);
	ZVAL_UNDEF(&_39$$14);
	ZVAL_UNDEF(&_40$$14);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_31$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &service_param, &method_param, &request);

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
	if (!request) {
		request = &request_sub;
		request = &__$null;
	}


	ZEPHIR_INIT_VAR(&serviceClass);
	ZVAL_STRING(&serviceClass, "");
	ZEPHIR_INIT_VAR(&_1);
	zephir_ucfirst(&_1, &service);
	ZEPHIR_INIT_NVAR(&serviceClass);
	ZEPHIR_CONCAT_VS(&serviceClass, &_1, "Service");

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&methodReflection);
		object_init_ex(&methodReflection, zephir_get_internal_ce(SL("reflectionmethod")));
		ZEPHIR_CALL_METHOD(NULL, &methodReflection, "__construct", NULL, 16, &serviceClass, &method);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_2);
		ZVAL_OBJ(&_2, EG(exception));
		Z_ADDREF_P(&_2);
		if (zephir_instance_of_ev(&_2, zephir_get_internal_ce(SL("reflectionexception")))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_2);
			ZEPHIR_INIT_VAR(&_3$$4);
			object_init_ex(&_3$$4, phalconplus_base_exception_ce);
			ZEPHIR_CALL_METHOD(&_4$$4, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_5$$4);
			ZEPHIR_CONCAT_SVSVSV(&_5$$4, "Service:method not found. Detail: ", &serviceClass, " : ", &method, ". RawException: ", &_4$$4);
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", &_6, 2, &_5$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$4, "phalconplus/Rpc/Server/AbstractServer.zep", 23);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_7 = Z_TYPE_P(request) == IS_NULL;
	if (_7) {
		ZEPHIR_CALL_METHOD(&_8, &methodReflection, "getnumberofrequiredparameters", NULL, 31);
		zephir_check_call_status();
		_7 = ZEPHIR_GT_LONG(&_8, 0);
	}
	if (_7) {
		ZEPHIR_INIT_VAR(&_9$$5);
		object_init_ex(&_9$$5, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_10$$5);
		ZEPHIR_CONCAT_VSVS(&_10$$5, &service, "::", &method, " need required params");
		ZEPHIR_CALL_METHOD(NULL, &_9$$5, "__construct", &_6, 2, &_10$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_9$$5, "phalconplus/Rpc/Server/AbstractServer.zep", 26);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_11, &methodReflection, "getnumberofparameters", NULL, 17);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(&_11, 0)) {
		_12$$6 = Z_TYPE_P(request) == IS_OBJECT;
		if (_12$$6) {
			_12$$6 = zephir_instance_of_ev(request, phalconplus_base_protobuffer_ce);
		}
		if (_12$$6) {
			if (1) {
				zephir_update_property_zval(this_ptr, SL("phpOnly"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("phpOnly"), &__$false);
			}
		} else if (Z_TYPE_P(request) == IS_ARRAY) {
			ZEPHIR_CPY_WRT(&tmp$$8, request);
			ZEPHIR_INIT_VAR(&param$$8);
			object_init_ex(&param$$8, zephir_get_internal_ce(SL("reflectionparameter")));
			ZEPHIR_INIT_VAR(&_13$$8);
			zephir_create_array(&_13$$8, 2, 0);
			zephir_array_fast_append(&_13$$8, &serviceClass);
			zephir_array_fast_append(&_13$$8, &method);
			ZVAL_LONG(&_14$$8, 0);
			ZEPHIR_CALL_METHOD(NULL, &param$$8, "__construct", NULL, 18, &_13$$8, &_14$$8);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_15$$8, &param$$8, "getclass", NULL, 19);
			zephir_check_call_status();
			if (zephir_is_true(&_15$$8)) {
				ZEPHIR_CALL_METHOD(&_16$$9, &param$$8, "getclass", NULL, 19);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&paramClass$$8, &_16$$9, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(request);
				zephir_fetch_safe_class(&_17$$9, &paramClass$$8);
				_18$$9 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_17$$9), Z_STRLEN_P(&_17$$9), ZEND_FETCH_CLASS_AUTO);
				if(!_18$$9) {
					RETURN_MM_NULL();
				}
				object_init_ex(request, _18$$9);
				if (zephir_has_constructor(request)) {
					ZEPHIR_CALL_METHOD(NULL, request, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(NULL, request, "softclone", NULL, 0, &tmp$$8);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(&_19$$10);
				object_init_ex(&_19$$10, phalconplus_base_exception_ce);
				ZEPHIR_INIT_VAR(&_20$$10);
				zephir_json_encode(&_20$$10, request, 0 );
				ZEPHIR_INIT_VAR(&_21$$10);
				ZEPHIR_CONCAT_SVSVSV(&_21$$10, "Service class:method definition is invalid. Detail: ", &service, " : ", &method, ". Request: ", &_20$$10);
				ZEPHIR_CALL_METHOD(NULL, &_19$$10, "__construct", &_6, 2, &_21$$10);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_19$$10, "phalconplus/Rpc/Server/AbstractServer.zep", 42);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_INIT_VAR(&_22$$11);
			object_init_ex(&_22$$11, phalconplus_base_exception_ce);
			ZEPHIR_INIT_VAR(&_23$$11);
			zephir_json_encode(&_23$$11, request, 0 );
			ZEPHIR_INIT_VAR(&_24$$11);
			ZEPHIR_CONCAT_SV(&_24$$11, "Your args is not allowed. Request: ", &_23$$11);
			ZEPHIR_CALL_METHOD(NULL, &_22$$11, "__construct", &_6, 2, &_24$$11);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_22$$11, "phalconplus/Rpc/Server/AbstractServer.zep", 47);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&serviceObj);
	zephir_fetch_safe_class(&_25, &serviceClass);
	_26 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_25), Z_STRLEN_P(&_25), ZEND_FETCH_CLASS_AUTO);
	if(!_26) {
		RETURN_MM_NULL();
	}
	object_init_ex(&serviceObj, _26);
	if (zephir_has_constructor(&serviceObj)) {
		zephir_read_property(&_27, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &serviceObj, "__construct", NULL, 0, &_27);
		zephir_check_call_status();
	}
	zephir_read_property(&_28, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_29);
	zephir_create_array(&_29, 3, 0);
	zephir_array_fast_append(&_29, &service);
	zephir_array_fast_append(&_29, &method);
	zephir_array_fast_append(&_29, request);
	ZEPHIR_INIT_VAR(&_30);
	ZVAL_STRING(&_30, "backend-server:beforeExecute");
	ZEPHIR_CALL_METHOD(NULL, &_28, "fire", NULL, 0, &_30, this_ptr, &_29);
	zephir_check_call_status();

	/* try_start_2: */

		ZEPHIR_INIT_VAR(&_31$$12);
		zephir_create_array(&_31$$12, 1, 0);
		zephir_array_fast_append(&_31$$12, request);
		ZEPHIR_CALL_METHOD(&response, &methodReflection, "invokeargs", NULL, 22, &serviceObj, &_31$$12);
		zephir_check_call_status_or_jump(try_end_2);

	try_end_2:

	if (EG(exception)) {
		ZEPHIR_INIT_NVAR(&_30);
		ZVAL_OBJ(&_30, EG(exception));
		Z_ADDREF_P(&_30);
		if (zephir_instance_of_ev(&_30, zend_exception_get_default(TSRMLS_C))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_30);
			ZEPHIR_INIT_VAR(&_32$$13);
			object_init_ex(&_32$$13, phalconplus_base_exception_ce);
			ZEPHIR_CALL_METHOD(&_33$$13, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_32$$13, "__construct", &_6, 2, &_33$$13);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_32$$13, "phalconplus/Rpc/Server/AbstractServer.zep", 60);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property(&_34, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_35);
	zephir_create_array(&_35, 3, 0);
	zephir_array_fast_append(&_35, &service);
	zephir_array_fast_append(&_35, &method);
	zephir_array_fast_append(&_35, request);
	ZEPHIR_INIT_VAR(&_36);
	ZVAL_STRING(&_36, "backend-server:afterExecute");
	ZEPHIR_CALL_METHOD(NULL, &_34, "fire", NULL, 0, &_36, this_ptr, &_35);
	zephir_check_call_status();
	_37 = Z_TYPE_P(&response) == IS_OBJECT;
	if (_37) {
		_37 = !((zephir_instance_of_ev(&response, phalconplus_base_protobuffer_ce)));
	}
	if (_37) {
		ZEPHIR_INIT_VAR(&_38$$14);
		object_init_ex(&_38$$14, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_39$$14);
		zephir_get_class(&_39$$14, &response, 0);
		ZEPHIR_INIT_VAR(&_40$$14);
		ZEPHIR_CONCAT_SVS(&_40$$14, "Your output is not allowed. Response: ", &_39$$14, ". We expect scalar type or <ProtoBuffer>");
		ZEPHIR_CALL_METHOD(NULL, &_38$$14, "__construct", &_6, 2, &_40$$14);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_38$$14, "phalconplus/Rpc/Server/AbstractServer.zep", 67);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (Z_TYPE_P(&response) == IS_RESOURCE) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Your output is not allowed. Response: #Resource.", "phalconplus/Rpc/Server/AbstractServer.zep", 69);
		return;
	}
	zephir_read_property(&_41, this_ptr, SL("phpOnly"), PH_NOISY_CC | PH_READONLY);
	_42 = ZEPHIR_IS_FALSE(&_41);
	if (_42) {
		_42 = Z_TYPE_P(&response) == IS_OBJECT;
	}
	if (_42) {
		ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_CCTOR(&response);

}

/**
 *
 * @param array rawData
 * <code>
 *     rawData = ["service":"Demo", "method":"demo", "args": <ProtoBuffer>, "logId": "234fdfaf3334"]
 * </code>
 * @return <ProtoBuffer>
 * @throw <BaseException>
 *
 */
PHP_METHOD(PhalconPlus_Rpc_Server_AbstractServer, callByObject) {

	zend_bool _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rawData_param = NULL, service, method, request, response, logId, message, _5, _7, _10, _11, _16, _18, _20, _21, _0$$3, _1$$3, _3$$4, _4$$4, _12$$8, _13$$8, _14$$8, _15$$8, _22$$9, _23$$9, _24$$9, _25$$9;
	zval rawData, _6, _17, _19;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawData);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&logId);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rawData_param);

	zephir_get_arrval(&rawData, rawData_param);


	ZEPHIR_INIT_VAR(&logId);
	ZVAL_STRING(&logId, "");
	ZEPHIR_INIT_VAR(&message);
	ZVAL_STRING(&message, "");
	ZEPHIR_OBS_VAR(&service);
	if (!(zephir_array_isset_string_fetch(&service, &rawData, SL("service"), 0))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_1$$3);
		ZEPHIR_CONCAT_SVS(&_1$$3, "service ", &service, " not exists");
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", &_2, 2, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalconplus/Rpc/Server/AbstractServer.zep", 96);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&method);
	if (!(zephir_array_isset_string_fetch(&method, &rawData, SL("method"), 0))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_CONCAT_SVS(&_4$$4, "method ", &method, " not exists");
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", &_2, 2, &_4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "phalconplus/Rpc/Server/AbstractServer.zep", 99);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&request);
	if (!(zephir_array_isset_string_fetch(&request, &rawData, SL("args"), 0))) {
		ZEPHIR_INIT_NVAR(&request);
		ZVAL_NULL(&request);
	}
	zephir_read_property(&_5, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 3, 0);
	zephir_array_fast_append(&_6, &service);
	zephir_array_fast_append(&_6, &method);
	zephir_array_fast_append(&_6, &rawData);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "backend-server:requestCheck");
	ZEPHIR_CALL_METHOD(NULL, &_5, "fire", NULL, 0, &_7, this_ptr, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_7);
	zephir_fast_trim(&_7, &service, NULL , ZEPHIR_TRIM_BOTH);
	ZEPHIR_CPY_WRT(&service, &_7);
	ZEPHIR_INIT_NVAR(&_7);
	zephir_fast_trim(&_7, &method, NULL , ZEPHIR_TRIM_BOTH);
	ZEPHIR_CPY_WRT(&method, &_7);
	_8 = ZEPHIR_IS_EMPTY(&service);
	if (!(_8)) {
		_8 = ZEPHIR_IS_EMPTY(&method);
	}
	if (_8) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "service:method(args) must exists. All of them!!!", "phalconplus/Rpc/Server/AbstractServer.zep", 110);
		return;
	}
	ZEPHIR_OBS_NVAR(&logId);
	if (zephir_array_isset_string_fetch(&logId, &rawData, SL("logId"), 0)) {
		ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_logger_processor_logid_ce, "setid", &_9, 0, &logId);
		zephir_check_call_status();
	}
	zephir_read_property(&_10, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "logger");
	ZEPHIR_CALL_METHOD(&_11, &_10, "has", NULL, 0, &_7);
	zephir_check_call_status();
	if (zephir_is_true(&_11)) {
		ZEPHIR_INIT_VAR(&_12$$8);
		zephir_json_encode(&_12$$8, &request, 0 );
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_SVSVSVSV(&message, "RPC Request - logId: ", &logId, ", invoke: ", &service, "::", &method, ", args: ", &_12$$8);
		zephir_read_property(&_13$$8, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_15$$8);
		ZVAL_STRING(&_15$$8, "logger");
		ZEPHIR_CALL_METHOD(&_14$$8, &_13$$8, "get", NULL, 0, &_15$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_14$$8, "log", NULL, 0, &message);
		zephir_check_call_status();
	}
	zephir_read_property(&_16, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_17);
	zephir_create_array(&_17, 3, 0);
	zephir_array_fast_append(&_17, &service);
	zephir_array_fast_append(&_17, &method);
	zephir_array_fast_append(&_17, &request);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "backend-server:beforeDispatch");
	ZEPHIR_CALL_METHOD(NULL, &_16, "fire", NULL, 0, &_7, this_ptr, &_17);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "callbyparams", NULL, 0, &service, &method, &request);
	zephir_check_call_status();
	zephir_read_property(&_18, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_19);
	zephir_create_array(&_19, 4, 0);
	zephir_array_fast_append(&_19, &service);
	zephir_array_fast_append(&_19, &method);
	zephir_array_fast_append(&_19, &request);
	zephir_array_fast_append(&_19, &response);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "backend-server:afterDispatch");
	ZEPHIR_CALL_METHOD(NULL, &_18, "fire", NULL, 0, &_7, this_ptr, &_19);
	zephir_check_call_status();
	zephir_read_property(&_20, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "logger");
	ZEPHIR_CALL_METHOD(&_21, &_20, "has", NULL, 0, &_7);
	zephir_check_call_status();
	if (zephir_is_true(&_21)) {
		ZEPHIR_INIT_VAR(&_22$$9);
		zephir_json_encode(&_22$$9, &response, 0 );
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_SVSVSVSV(&message, "RPC Response - logId: ", &logId, ", invoke: ", &service, "::", &method, ", response: ", &_22$$9);
		zephir_read_property(&_23$$9, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_25$$9);
		ZVAL_STRING(&_25$$9, "logger");
		ZEPHIR_CALL_METHOD(&_24$$9, &_23$$9, "get", NULL, 0, &_25$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_24$$9, "log", NULL, 0, &message);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&response);

}

