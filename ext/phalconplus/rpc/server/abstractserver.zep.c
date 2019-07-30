
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
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Server_AbstractServer) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Rpc\\Server, AbstractServer, phalconplus, rpc_server_abstractserver, phalconplus_rpc_server_abstractserver_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalconplus_rpc_server_abstractserver_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_rpc_server_abstractserver_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalconplus_rpc_server_abstractserver_ce, SL("phpOnly"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_rpc_server_abstractserver_ce, SL("eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Rpc_Server_AbstractServer, __construct) {

}

PHP_METHOD(PhalconPlus_Rpc_Server_AbstractServer, callByParams) {

	zval _19, _3$$4, _21$$8, _27$$8, _24$$9, _25$$9;
	zend_class_entry *_17, *_8$$5;
	zend_bool _2, _29$$8, _34$$8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *service_param = NULL, *method_param = NULL, *request = NULL, request_sub, __$true, __$false, serviceClass, _0, _1, serviceObj, response, e, _16, _18, tmp$$4, param$$4, paramClass$$4, _4$$4, _5$$4, _6$$5, _7$$5, _9$$6, _10$$6, _11$$6, _13$$7, _14$$7, _15$$7, _20$$8, _22$$8, _26$$8, _28$$8, _33$$8, _23$$9, _30$$11, _31$$11, _32$$11, _35$$14;
	zval service, method, _36$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_36$$14);
	ZVAL_UNDEF(&request_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&serviceClass);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&serviceObj);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&tmp$$4);
	ZVAL_UNDEF(&param$$4);
	ZVAL_UNDEF(&paramClass$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_26$$8);
	ZVAL_UNDEF(&_28$$8);
	ZVAL_UNDEF(&_33$$8);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_30$$11);
	ZVAL_UNDEF(&_31$$11);
	ZVAL_UNDEF(&_32$$11);
	ZVAL_UNDEF(&_35$$14);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_27$$8);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &service_param, &method_param, &request);

	if (UNEXPECTED(Z_TYPE_P(service_param) != IS_STRING && Z_TYPE_P(service_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'service' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(service_param) == IS_STRING)) {
		zephir_get_strval(&service, service_param);
	} else {
		ZEPHIR_INIT_VAR(&service);
		ZVAL_EMPTY_STRING(&service);
	}
	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be of the type string") TSRMLS_CC);
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
	_2 = Z_TYPE_P(request) == IS_OBJECT;
	if (_2) {
		_2 = zephir_instance_of_ev(request, phalconplus_base_protobuffer_ce TSRMLS_CC);
	}
	if (_2) {
		if (1) {
			zephir_update_property_zval(this_ptr, SL("phpOnly"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, SL("phpOnly"), &__$false);
		}
	} else if (Z_TYPE_P(request) == IS_ARRAY) {
		ZEPHIR_INIT_VAR(&tmp$$4);
		array_init(&tmp$$4);
		ZEPHIR_CPY_WRT(&tmp$$4, request);
		ZEPHIR_INIT_VAR(&param$$4);
		object_init_ex(&param$$4, zephir_get_internal_ce(SL("reflectionparameter")));
		ZEPHIR_INIT_VAR(&_3$$4);
		zephir_create_array(&_3$$4, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&_3$$4, &serviceClass);
		zephir_array_fast_append(&_3$$4, &method);
		ZVAL_LONG(&_4$$4, 0);
		ZEPHIR_CALL_METHOD(NULL, &param$$4, "__construct", NULL, 2, &_3$$4, &_4$$4);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$4, &param$$4, "getclass", NULL, 3);
		zephir_check_call_status();
		if (zephir_is_true(&_5$$4)) {
			ZEPHIR_CALL_METHOD(&_6$$5, &param$$4, "getclass", NULL, 3);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&paramClass$$4, &_6$$5, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(request);
			zephir_fetch_safe_class(&_7$$5, &paramClass$$4);
			_8$$5 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_7$$5), Z_STRLEN_P(&_7$$5), ZEND_FETCH_CLASS_AUTO);
			if(!_8$$5) {
				RETURN_MM_NULL();
			}
			object_init_ex(request, _8$$5);
			if (zephir_has_constructor(request TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, request, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(NULL, request, "softclone", NULL, 0, &tmp$$4);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_VAR(&_9$$6);
			object_init_ex(&_9$$6, phalconplus_base_exception_ce);
			ZEPHIR_INIT_VAR(&_10$$6);
			zephir_json_encode(&_10$$6, request, 0 );
			ZEPHIR_INIT_VAR(&_11$$6);
			ZEPHIR_CONCAT_SVSVSV(&_11$$6, "Service class:method definition is invalid. Detail: ", &service, " : ", &method, ". Request: ", &_10$$6);
			ZEPHIR_CALL_METHOD(NULL, &_9$$6, "__construct", &_12, 22, &_11$$6);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$6, "phalconplus/Rpc/Server/AbstractServer.zep", 29 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_VAR(&_13$$7);
		object_init_ex(&_13$$7, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_14$$7);
		zephir_json_encode(&_14$$7, request, 0 );
		ZEPHIR_INIT_VAR(&_15$$7);
		ZEPHIR_CONCAT_SV(&_15$$7, "Your input is not allowed. Request: ", &_14$$7);
		ZEPHIR_CALL_METHOD(NULL, &_13$$7, "__construct", &_12, 22, &_15$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_13$$7, "phalconplus/Rpc/Server/AbstractServer.zep", 32 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&serviceObj);
	zephir_fetch_safe_class(&_16, &serviceClass);
	_17 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_16), Z_STRLEN_P(&_16), ZEND_FETCH_CLASS_AUTO);
	if(!_17) {
		RETURN_MM_NULL();
	}
	object_init_ex(&serviceObj, _17);
	if (zephir_has_constructor(&serviceObj TSRMLS_CC)) {
		zephir_read_property(&_18, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &serviceObj, "__construct", NULL, 0, &_18);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_19);
	zephir_create_array(&_19, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_19, &serviceObj);
	zephir_array_fast_append(&_19, &method);
	if (zephir_is_callable(&_19 TSRMLS_CC)) {
		zephir_read_property(&_20$$8, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_21$$8);
		zephir_create_array(&_21$$8, 3, 0 TSRMLS_CC);
		zephir_array_fast_append(&_21$$8, &service);
		zephir_array_fast_append(&_21$$8, &method);
		zephir_array_fast_append(&_21$$8, request);
		ZEPHIR_INIT_VAR(&_22$$8);
		ZVAL_STRING(&_22$$8, "backend-server:beforeExecute");
		ZEPHIR_CALL_METHOD(NULL, &_20$$8, "fire", NULL, 0, &_22$$8, this_ptr, &_21$$8);
		zephir_check_call_status();

		/* try_start_1: */

			ZEPHIR_INIT_VAR(&_23$$9);
			ZEPHIR_INIT_VAR(&_24$$9);
			zephir_create_array(&_24$$9, 2, 0 TSRMLS_CC);
			zephir_array_fast_append(&_24$$9, &serviceObj);
			zephir_array_fast_append(&_24$$9, &method);
			ZEPHIR_INIT_VAR(&_25$$9);
			zephir_create_array(&_25$$9, 1, 0 TSRMLS_CC);
			zephir_array_fast_append(&_25$$9, request);
			ZEPHIR_CALL_USER_FUNC_ARRAY(&_23$$9, &_24$$9, &_25$$9);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CPY_WRT(&response, &_23$$9);

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_NVAR(&_22$$8);
			ZVAL_OBJ(&_22$$8, EG(exception));
			Z_ADDREF_P(&_22$$8);
			if (zephir_instance_of_ev(&_22$$8, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&e, &_22$$8);
				zephir_throw_exception_debug(&e, "phalconplus/Rpc/Server/AbstractServer.zep", 43 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
		zephir_read_property(&_26$$8, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_27$$8);
		zephir_create_array(&_27$$8, 3, 0 TSRMLS_CC);
		zephir_array_fast_append(&_27$$8, &service);
		zephir_array_fast_append(&_27$$8, &method);
		zephir_array_fast_append(&_27$$8, request);
		ZEPHIR_INIT_VAR(&_28$$8);
		ZVAL_STRING(&_28$$8, "backend-server:afterExecute");
		ZEPHIR_CALL_METHOD(NULL, &_26$$8, "fire", NULL, 0, &_28$$8, this_ptr, &_27$$8);
		zephir_check_call_status();
		_29$$8 = Z_TYPE_P(&response) == IS_OBJECT;
		if (_29$$8) {
			_29$$8 = !((zephir_instance_of_ev(&response, phalconplus_base_protobuffer_ce TSRMLS_CC)));
		}
		if (_29$$8) {
			ZEPHIR_INIT_VAR(&_30$$11);
			object_init_ex(&_30$$11, phalconplus_base_exception_ce);
			ZEPHIR_INIT_VAR(&_31$$11);
			zephir_get_class(&_31$$11, &response, 0 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_32$$11);
			ZEPHIR_CONCAT_SVS(&_32$$11, "Your output is not allowed. Response: ", &_31$$11, ". We expect scalar type or <ProtoBuffer>");
			ZEPHIR_CALL_METHOD(NULL, &_30$$11, "__construct", &_12, 22, &_32$$11);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_30$$11, "phalconplus/Rpc/Server/AbstractServer.zep", 48 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		} else if (Z_TYPE_P(&response) == IS_RESOURCE) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Your output is not allowed. Response: #Resource.", "phalconplus/Rpc/Server/AbstractServer.zep", 50);
			return;
		}
		zephir_read_property(&_33$$8, this_ptr, SL("phpOnly"), PH_NOISY_CC | PH_READONLY);
		_34$$8 = ZEPHIR_IS_FALSE(&_33$$8);
		if (_34$$8) {
			_34$$8 = Z_TYPE_P(&response) == IS_OBJECT;
		}
		if (_34$$8) {
			ZEPHIR_RETURN_CALL_METHOD(&response, "toarray", NULL, 0);
			zephir_check_call_status();
			RETURN_MM();
		}
		RETURN_CCTOR(&response);
	} else {
		ZEPHIR_INIT_VAR(&_35$$14);
		object_init_ex(&_35$$14, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_36$$14);
		ZEPHIR_CONCAT_SVSV(&_36$$14, "Service:method not found. Detail: ", &service, " : ", &method);
		ZEPHIR_CALL_METHOD(NULL, &_35$$14, "__construct", &_12, 22, &_36$$14);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_35$$14, "phalconplus/Rpc/Server/AbstractServer.zep", 58 TSRMLS_CC);
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
PHP_METHOD(PhalconPlus_Rpc_Server_AbstractServer, callByObject) {

	zend_bool _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rawData_param = NULL, service, method, request, response, logId, message, _5, _7, _9, _10, _15, _17, _19, _20, _0$$3, _1$$3, _3$$4, _4$$4, _11$$7, _12$$7, _13$$7, _14$$7, _21$$8, _22$$8, _23$$8, _24$$8;
	zval rawData, _6, _16, _18;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawData);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&logId);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);

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
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", &_2, 22, &_1$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalconplus/Rpc/Server/AbstractServer.zep", 77 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&method);
	if (!(zephir_array_isset_string_fetch(&method, &rawData, SL("method"), 0))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_CONCAT_SVS(&_4$$4, "method ", &method, " not exists");
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", &_2, 22, &_4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "phalconplus/Rpc/Server/AbstractServer.zep", 81 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&request);
	if (!(zephir_array_isset_string_fetch(&request, &rawData, SL("args"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "args not exists", "phalconplus/Rpc/Server/AbstractServer.zep", 85);
		return;
	}
	zephir_read_property(&_5, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(&_6, &service);
	zephir_array_fast_append(&_6, &method);
	zephir_array_fast_append(&_6, &rawData);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "backend-server:requestCheck");
	ZEPHIR_CALL_METHOD(NULL, &_5, "fire", NULL, 0, &_7, this_ptr, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_7);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "service:method(args) must exists. All of them!!!", "phalconplus/Rpc/Server/AbstractServer.zep", 94);
		return;
	}
	ZEPHIR_OBS_NVAR(&logId);
	if (zephir_array_isset_string_fetch(&logId, &rawData, SL("logId"), 0)) {
	}
	zephir_read_property(&_9, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "logger");
	ZEPHIR_CALL_METHOD(&_10, &_9, "has", NULL, 0, &_7);
	zephir_check_call_status();
	if (zephir_is_true(&_10)) {
		ZEPHIR_INIT_VAR(&_11$$7);
		zephir_json_encode(&_11$$7, &request, 0 );
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_SVSVSVSV(&message, "RPC Request - logId: ", &logId, ", invoke: ", &service, "::", &method, ", args: ", &_11$$7);
		zephir_read_property(&_12$$7, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_14$$7);
		ZVAL_STRING(&_14$$7, "logger");
		ZEPHIR_CALL_METHOD(&_13$$7, &_12$$7, "get", NULL, 0, &_14$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_13$$7, "log", NULL, 0, &message);
		zephir_check_call_status();
	}
	zephir_read_property(&_15, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_16);
	zephir_create_array(&_16, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(&_16, &service);
	zephir_array_fast_append(&_16, &method);
	zephir_array_fast_append(&_16, &request);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "backend-server:beforeDispatch");
	ZEPHIR_CALL_METHOD(NULL, &_15, "fire", NULL, 0, &_7, this_ptr, &_16);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "callbyparams", NULL, 0, &service, &method, &request);
	zephir_check_call_status();
	zephir_read_property(&_17, this_ptr, SL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_18);
	zephir_create_array(&_18, 4, 0 TSRMLS_CC);
	zephir_array_fast_append(&_18, &service);
	zephir_array_fast_append(&_18, &method);
	zephir_array_fast_append(&_18, &request);
	zephir_array_fast_append(&_18, &response);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "backend-server:afterDispatch");
	ZEPHIR_CALL_METHOD(NULL, &_17, "fire", NULL, 0, &_7, this_ptr, &_18);
	zephir_check_call_status();
	zephir_read_property(&_19, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "logger");
	ZEPHIR_CALL_METHOD(&_20, &_19, "has", NULL, 0, &_7);
	zephir_check_call_status();
	if (zephir_is_true(&_20)) {
		ZEPHIR_INIT_VAR(&_21$$8);
		zephir_json_encode(&_21$$8, &response, 0 );
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_SVSVSVSV(&message, "RPC Response - logId: ", &logId, ", invoke: ", &service, "::", &method, ", response: ", &_21$$8);
		zephir_read_property(&_22$$8, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_24$$8);
		ZVAL_STRING(&_24$$8, "logger");
		ZEPHIR_CALL_METHOD(&_23$$8, &_22$$8, "get", NULL, 0, &_24$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_23$$8, "log", NULL, 0, &message);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&response);

}

