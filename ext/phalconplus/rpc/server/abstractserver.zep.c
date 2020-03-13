
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
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
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

	zend_bool _3$$3, _30$$9, _35$$9;
	zval _20, _4$$5, _22$$9, _28$$9, _25$$10, _26$$10;
	zend_class_entry *_18, *_9$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *service_param = NULL, *method_param = NULL, *request = NULL, request_sub, __$true, __$false, serviceClass, methodReflection, _0, _1, _2, serviceObj, response, e, _17, _19, tmp$$5, param$$5, paramClass$$5, _5$$5, _6$$5, _7$$6, _8$$6, _10$$7, _11$$7, _12$$7, _14$$8, _15$$8, _16$$8, _21$$9, _23$$9, _27$$9, _29$$9, _34$$9, _24$$10, _31$$12, _32$$12, _33$$12, _36$$15;
	zval service, method, _37$$15;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_37$$15);
	ZVAL_UNDEF(&request_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&serviceClass);
	ZVAL_UNDEF(&methodReflection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&serviceObj);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&tmp$$5);
	ZVAL_UNDEF(&param$$5);
	ZVAL_UNDEF(&paramClass$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_29$$9);
	ZVAL_UNDEF(&_34$$9);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_32$$12);
	ZVAL_UNDEF(&_33$$12);
	ZVAL_UNDEF(&_36$$15);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_25$$10);
	ZVAL_UNDEF(&_26$$10);

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


	ZEPHIR_INIT_VAR(&serviceClass);
	ZVAL_STRING(&serviceClass, "");
	ZEPHIR_INIT_VAR(&_1);
	zephir_ucfirst(&_1, &service);
	ZEPHIR_INIT_NVAR(&serviceClass);
	ZEPHIR_CONCAT_VS(&serviceClass, &_1, "Service");
	ZEPHIR_INIT_VAR(&methodReflection);
	object_init_ex(&methodReflection, zephir_get_internal_ce(SL("reflectionmethod")));
	ZEPHIR_CALL_METHOD(NULL, &methodReflection, "__construct", NULL, 28, &serviceClass, &method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &methodReflection, "getnumberofparameters", NULL, 29);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(&_2, 0)) {
		_3$$3 = Z_TYPE_P(request) == IS_OBJECT;
		if (_3$$3) {
			_3$$3 = zephir_instance_of_ev(request, phalconplus_base_protobuffer_ce);
		}
		if (_3$$3) {
			if (1) {
				zephir_update_property_zval(this_ptr, SL("phpOnly"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("phpOnly"), &__$false);
			}
		} else if (Z_TYPE_P(request) == IS_ARRAY) {
			ZEPHIR_INIT_VAR(&tmp$$5);
			array_init(&tmp$$5);
			ZEPHIR_CPY_WRT(&tmp$$5, request);
			ZEPHIR_INIT_VAR(&param$$5);
			object_init_ex(&param$$5, zephir_get_internal_ce(SL("reflectionparameter")));
			ZEPHIR_INIT_VAR(&_4$$5);
			zephir_create_array(&_4$$5, 2, 0);
			zephir_array_fast_append(&_4$$5, &serviceClass);
			zephir_array_fast_append(&_4$$5, &method);
			ZVAL_LONG(&_5$$5, 0);
			ZEPHIR_CALL_METHOD(NULL, &param$$5, "__construct", NULL, 16, &_4$$5, &_5$$5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_6$$5, &param$$5, "getclass", NULL, 17);
			zephir_check_call_status();
			if (zephir_is_true(&_6$$5)) {
				ZEPHIR_CALL_METHOD(&_7$$6, &param$$5, "getclass", NULL, 17);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&paramClass$$5, &_7$$6, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(request);
				zephir_fetch_safe_class(&_8$$6, &paramClass$$5);
				_9$$6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_8$$6), Z_STRLEN_P(&_8$$6), ZEND_FETCH_CLASS_AUTO);
				if(!_9$$6) {
					RETURN_MM_NULL();
				}
				object_init_ex(request, _9$$6);
				if (zephir_has_constructor(request)) {
					ZEPHIR_CALL_METHOD(NULL, request, "__construct", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(NULL, request, "softclone", NULL, 0, &tmp$$5);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(&_10$$7);
				object_init_ex(&_10$$7, phalconplus_base_exception_ce);
				ZEPHIR_INIT_VAR(&_11$$7);
				zephir_json_encode(&_11$$7, request, 0 );
				ZEPHIR_INIT_VAR(&_12$$7);
				ZEPHIR_CONCAT_SVSVSV(&_12$$7, "Service class:method definition is invalid. Detail: ", &service, " : ", &method, ". Request: ", &_11$$7);
				ZEPHIR_CALL_METHOD(NULL, &_10$$7, "__construct", &_13, 2, &_12$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_10$$7, "phalconplus/Rpc/Server/AbstractServer.zep", 41);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_INIT_VAR(&_14$$8);
			object_init_ex(&_14$$8, phalconplus_base_exception_ce);
			ZEPHIR_INIT_VAR(&_15$$8);
			zephir_json_encode(&_15$$8, request, 0 );
			ZEPHIR_INIT_VAR(&_16$$8);
			ZEPHIR_CONCAT_SV(&_16$$8, "Your args is not allowed. Request: ", &_15$$8);
			ZEPHIR_CALL_METHOD(NULL, &_14$$8, "__construct", &_13, 2, &_16$$8);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_14$$8, "phalconplus/Rpc/Server/AbstractServer.zep", 44);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&serviceObj);
	zephir_fetch_safe_class(&_17, &serviceClass);
	_18 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_17), Z_STRLEN_P(&_17), ZEND_FETCH_CLASS_AUTO);
	if(!_18) {
		RETURN_MM_NULL();
	}
	object_init_ex(&serviceObj, _18);
	if (zephir_has_constructor(&serviceObj)) {
		zephir_read_property(&_19, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &serviceObj, "__construct", NULL, 0, &_19);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_20);
	zephir_create_array(&_20, 2, 0);
	zephir_array_fast_append(&_20, &serviceObj);
	zephir_array_fast_append(&_20, &method);
	if (zephir_is_callable(&_20)) {
		zephir_read_property(&_21$$9, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_22$$9);
		zephir_create_array(&_22$$9, 3, 0);
		zephir_array_fast_append(&_22$$9, &service);
		zephir_array_fast_append(&_22$$9, &method);
		zephir_array_fast_append(&_22$$9, request);
		ZEPHIR_INIT_VAR(&_23$$9);
		ZVAL_STRING(&_23$$9, "backend-server:beforeExecute");
		ZEPHIR_CALL_METHOD(NULL, &_21$$9, "fire", NULL, 0, &_23$$9, this_ptr, &_22$$9);
		zephir_check_call_status();

		/* try_start_1: */

			ZEPHIR_INIT_VAR(&_24$$10);
			ZEPHIR_INIT_VAR(&_25$$10);
			zephir_create_array(&_25$$10, 2, 0);
			zephir_array_fast_append(&_25$$10, &serviceObj);
			zephir_array_fast_append(&_25$$10, &method);
			ZEPHIR_INIT_VAR(&_26$$10);
			zephir_create_array(&_26$$10, 1, 0);
			zephir_array_fast_append(&_26$$10, request);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_24$$10, &_25$$10, &_26$$10);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CPY_WRT(&response, &_24$$10);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_23$$9);
			ZVAL_OBJ(&_23$$9, EG(exception));
			Z_ADDREF_P(&_23$$9);
			if (zephir_instance_of_ev(&_23$$9, zend_exception_get_default(TSRMLS_C))) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_23$$9);
				zephir_throw_exception_debug(&e, "phalconplus/Rpc/Server/AbstractServer.zep", 61);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_read_property(&_27$$9, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_28$$9);
		zephir_create_array(&_28$$9, 3, 0);
		zephir_array_fast_append(&_28$$9, &service);
		zephir_array_fast_append(&_28$$9, &method);
		zephir_array_fast_append(&_28$$9, request);
		ZEPHIR_INIT_VAR(&_29$$9);
		ZVAL_STRING(&_29$$9, "backend-server:afterExecute");
		ZEPHIR_CALL_METHOD(NULL, &_27$$9, "fire", NULL, 0, &_29$$9, this_ptr, &_28$$9);
		zephir_check_call_status();
		_30$$9 = Z_TYPE_P(&response) == IS_OBJECT;
		if (_30$$9) {
			_30$$9 = !((zephir_instance_of_ev(&response, phalconplus_base_protobuffer_ce)));
		}
		if (_30$$9) {
			ZEPHIR_INIT_VAR(&_31$$12);
			object_init_ex(&_31$$12, phalconplus_base_exception_ce);
			ZEPHIR_INIT_VAR(&_32$$12);
			zephir_get_class(&_32$$12, &response, 0);
			ZEPHIR_INIT_VAR(&_33$$12);
			ZEPHIR_CONCAT_SVS(&_33$$12, "Your output is not allowed. Response: ", &_32$$12, ". We expect scalar type or <ProtoBuffer>");
			ZEPHIR_CALL_METHOD(NULL, &_31$$12, "__construct", &_13, 2, &_33$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_31$$12, "phalconplus/Rpc/Server/AbstractServer.zep", 68);
			ZEPHIR_MM_RESTORE();
			return;
		} else if (Z_TYPE_P(&response) == IS_RESOURCE) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Your output is not allowed. Response: #Resource.", "phalconplus/Rpc/Server/AbstractServer.zep", 70);
			return;
		}
		zephir_read_property(&_34$$9, this_ptr, SL("phpOnly"), PH_NOISY_CC | PH_READONLY);
		_35$$9 = ZEPHIR_IS_FALSE(&_34$$9);
		if (_35$$9) {
			_35$$9 = Z_TYPE_P(&response) == IS_OBJECT;
		}
		if (_35$$9) {
			ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_CCTOR(&response);
	} else {
		ZEPHIR_INIT_VAR(&_36$$15);
		object_init_ex(&_36$$15, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_37$$15);
		ZEPHIR_CONCAT_SVSV(&_37$$15, "Service:method not found. Detail: ", &service, " : ", &method);
		ZEPHIR_CALL_METHOD(NULL, &_36$$15, "__construct", &_13, 2, &_37$$15);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_36$$15, "phalconplus/Rpc/Server/AbstractServer.zep", 81);
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
		zephir_throw_exception_debug(&_0$$3, "phalconplus/Rpc/Server/AbstractServer.zep", 100);
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
		zephir_throw_exception_debug(&_3$$4, "phalconplus/Rpc/Server/AbstractServer.zep", 104);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&request);
	if (!(zephir_array_isset_string_fetch(&request, &rawData, SL("args"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "args not exists", "phalconplus/Rpc/Server/AbstractServer.zep", 108);
		return;
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "service:method(args) must exists. All of them!!!", "phalconplus/Rpc/Server/AbstractServer.zep", 117);
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

