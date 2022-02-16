
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Server_AbstractServer)
{
	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Rpc\\Server, AbstractServer, phalconplus, rpc_server_abstractserver, phalconplus_rpc_server_abstractserver_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalconplus_rpc_server_abstractserver_ce, SL("di"), ZEND_ACC_PROTECTED);
	zend_declare_property_bool(phalconplus_rpc_server_abstractserver_ce, SL("phpOnly"), 0, ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalconplus_rpc_server_abstractserver_ce, SL("eventsManager"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Rpc_Server_AbstractServer, getDi)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "di");
}

PHP_METHOD(PhalconPlus_Rpc_Server_AbstractServer, getPhpOnly)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "phpOnly");
}

PHP_METHOD(PhalconPlus_Rpc_Server_AbstractServer, __construct)
{
}

PHP_METHOD(PhalconPlus_Rpc_Server_AbstractServer, callByParams)
{
	zval _31, _37, _18$$9, _33$$13;
	zend_bool _12, _39, _44, _17$$7;
	zend_class_entry *_6, *_23$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *service_param = NULL, *method_param = NULL, *request = NULL, request_sub, __$true, __$false, __$null, serviceClass, methodReflection, serviceObj, response, e, _0, _1, _5, _7, _8, _13, _16, _30, _32, _36, _38, _43, _2$$3, _3$$3, _9$$5, _10$$5, _11$$5, _14$$6, tmp$$9, param$$9, paramClass$$9, _19$$9, _20$$9, _21$$10, _22$$10, _24$$11, _25$$11, _26$$11, _27$$12, _28$$12, _29$$12, _34$$14, _35$$14, _40$$15, _41$$15, _42$$15;
	zval service, method, _15$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_15$$6);
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&tmp$$9);
	ZVAL_UNDEF(&param$$9);
	ZVAL_UNDEF(&paramClass$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_27$$12);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_34$$14);
	ZVAL_UNDEF(&_35$$14);
	ZVAL_UNDEF(&_40$$15);
	ZVAL_UNDEF(&_41$$15);
	ZVAL_UNDEF(&_42$$15);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_33$$13);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(service)
		Z_PARAM_STR(method)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(request)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	}
	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
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
	if (!(zephir_class_exists(&serviceClass, 1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "Service class not exists: ", &serviceClass);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", &_4, 2, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalconplus/Rpc/Server/AbstractServer.zep", 22);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&serviceObj);
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

		ZEPHIR_INIT_VAR(&methodReflection);
		object_init_ex(&methodReflection, zephir_get_internal_ce(SL("reflectionmethod")));
		ZEPHIR_CALL_METHOD(NULL, &methodReflection, "__construct", NULL, 4, &serviceObj, &method);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_8);
		ZVAL_OBJ(&_8, EG(exception));
		Z_ADDREF_P(&_8);
		if (zephir_is_instance_of(&_8, SL("ReflectionException"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_8);
			ZEPHIR_INIT_VAR(&_9$$5);
			object_init_ex(&_9$$5, phalconplus_base_exception_ce);
			ZEPHIR_CALL_METHOD(&_10$$5, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_11$$5);
			ZEPHIR_CONCAT_SVSVSV(&_11$$5, "Service:method not found. Detail: ", &serviceClass, " : ", &method, ". RawException: ", &_10$$5);
			ZEPHIR_CALL_METHOD(NULL, &_9$$5, "__construct", &_4, 2, &_11$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_9$$5, "phalconplus/Rpc/Server/AbstractServer.zep", 29);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	_12 = Z_TYPE_P(request) == IS_NULL;
	if (_12) {
		ZEPHIR_CALL_METHOD(&_13, &methodReflection, "getnumberofrequiredparameters", NULL, 30);
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
		zephir_throw_exception_debug(&_14$$6, "phalconplus/Rpc/Server/AbstractServer.zep", 32);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_16, &methodReflection, "getnumberofparameters", NULL, 5);
	zephir_check_call_status();
	if (ZEPHIR_GT_LONG(&_16, 0)) {
		_17$$7 = Z_TYPE_P(request) == IS_OBJECT;
		if (_17$$7) {
			_17$$7 = zephir_instance_of_ev(request, phalconplus_base_protobuffer_ce);
		}
		if (_17$$7) {
			if (1) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("phpOnly"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("phpOnly"), &__$false);
			}
		} else if (Z_TYPE_P(request) == IS_ARRAY) {
			ZEPHIR_CPY_WRT(&tmp$$9, request);
			ZEPHIR_INIT_VAR(&param$$9);
			object_init_ex(&param$$9, zephir_get_internal_ce(SL("reflectionparameter")));
			ZEPHIR_INIT_VAR(&_18$$9);
			zephir_create_array(&_18$$9, 2, 0);
			zephir_array_fast_append(&_18$$9, &serviceClass);
			zephir_array_fast_append(&_18$$9, &method);
			ZVAL_LONG(&_19$$9, 0);
			ZEPHIR_CALL_METHOD(NULL, &param$$9, "__construct", NULL, 6, &_18$$9, &_19$$9);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_20$$9, &param$$9, "getclass", NULL, 7);
			zephir_check_call_status();
			if (zephir_is_true(&_20$$9)) {
				ZEPHIR_CALL_METHOD(&_21$$10, &param$$9, "getclass", NULL, 7);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&paramClass$$9, &_21$$10, "getname", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(request);
				zephir_fetch_safe_class(&_22$$10, &paramClass$$9);
				_23$$10 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_22$$10), Z_STRLEN_P(&_22$$10), ZEND_FETCH_CLASS_AUTO);
				if(!_23$$10) {
					RETURN_MM_NULL();
				}
				object_init_ex(request, _23$$10);
				if (zephir_has_constructor(request)) {
					ZEPHIR_CALL_METHOD(NULL, request, "__construct", NULL, 0);
					zephir_check_call_status();
				}

				ZEPHIR_CALL_METHOD(NULL, request, "softclone", NULL, 0, &tmp$$9);
				zephir_check_call_status();
			} else {
				ZEPHIR_INIT_VAR(&_24$$11);
				object_init_ex(&_24$$11, phalconplus_base_exception_ce);
				ZEPHIR_INIT_VAR(&_25$$11);
				zephir_json_encode(&_25$$11, request, 0 );
				ZEPHIR_INIT_VAR(&_26$$11);
				ZEPHIR_CONCAT_SVSVSV(&_26$$11, "Service class:method definition is invalid. Detail: ", &service, " : ", &method, ". Request: ", &_25$$11);
				ZEPHIR_CALL_METHOD(NULL, &_24$$11, "__construct", &_4, 2, &_26$$11);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_24$$11, "phalconplus/Rpc/Server/AbstractServer.zep", 48);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_INIT_VAR(&_27$$12);
			object_init_ex(&_27$$12, phalconplus_base_exception_ce);
			ZEPHIR_INIT_VAR(&_28$$12);
			zephir_json_encode(&_28$$12, request, 0 );
			ZEPHIR_INIT_VAR(&_29$$12);
			ZEPHIR_CONCAT_SV(&_29$$12, "Your args is not allowed. Request: ", &_28$$12);
			ZEPHIR_CALL_METHOD(NULL, &_27$$12, "__construct", &_4, 2, &_29$$12);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_27$$12, "phalconplus/Rpc/Server/AbstractServer.zep", 53);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property(&_30, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_31);
	zephir_create_array(&_31, 3, 0);
	zephir_array_fast_append(&_31, &service);
	zephir_array_fast_append(&_31, &method);
	zephir_array_fast_append(&_31, request);
	ZEPHIR_INIT_VAR(&_32);
	ZVAL_STRING(&_32, "backend-server:beforeExecute");
	ZEPHIR_CALL_METHOD(NULL, &_30, "fire", NULL, 0, &_32, this_ptr, &_31);
	zephir_check_call_status();

	/* try_start_2: */

		ZEPHIR_INIT_VAR(&_33$$13);
		zephir_create_array(&_33$$13, 1, 0);
		zephir_array_fast_append(&_33$$13, request);
		ZEPHIR_CALL_METHOD(&response, &methodReflection, "invokeargs", NULL, 11, &serviceObj, &_33$$13);
		zephir_check_call_status_or_jump(try_end_2);

	try_end_2:

	if (EG(exception)) {
		ZEPHIR_INIT_NVAR(&_32);
		ZVAL_OBJ(&_32, EG(exception));
		Z_ADDREF_P(&_32);
		if (zephir_is_instance_of(&_32, SL("Exception"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_32);
			ZEPHIR_INIT_VAR(&_34$$14);
			object_init_ex(&_34$$14, phalconplus_base_exception_ce);
			ZEPHIR_CALL_METHOD(&_35$$14, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_34$$14, "__construct", &_4, 2, &_35$$14);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_34$$14, "phalconplus/Rpc/Server/AbstractServer.zep", 64);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_read_property(&_36, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_37);
	zephir_create_array(&_37, 3, 0);
	zephir_array_fast_append(&_37, &service);
	zephir_array_fast_append(&_37, &method);
	zephir_array_fast_append(&_37, request);
	ZEPHIR_INIT_VAR(&_38);
	ZVAL_STRING(&_38, "backend-server:afterExecute");
	ZEPHIR_CALL_METHOD(NULL, &_36, "fire", NULL, 0, &_38, this_ptr, &_37);
	zephir_check_call_status();
	_39 = Z_TYPE_P(&response) == IS_OBJECT;
	if (_39) {
		_39 = !((zephir_instance_of_ev(&response, phalconplus_base_protobuffer_ce)));
	}
	if (_39) {
		ZEPHIR_INIT_VAR(&_40$$15);
		object_init_ex(&_40$$15, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_41$$15);
		zephir_get_class(&_41$$15, &response, 0);
		ZEPHIR_INIT_VAR(&_42$$15);
		ZEPHIR_CONCAT_SVS(&_42$$15, "Your output is not allowed. Response: ", &_41$$15, ". We expect scalar type or <ProtoBuffer>");
		ZEPHIR_CALL_METHOD(NULL, &_40$$15, "__construct", &_4, 2, &_42$$15);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_40$$15, "phalconplus/Rpc/Server/AbstractServer.zep", 71);
		ZEPHIR_MM_RESTORE();
		return;
	} else if (Z_TYPE_P(&response) == IS_RESOURCE) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Your output is not allowed. Response: #Resource.", "phalconplus/Rpc/Server/AbstractServer.zep", 73);
		return;
	}
	zephir_read_property(&_43, this_ptr, ZEND_STRL("phpOnly"), PH_NOISY_CC | PH_READONLY);
	_44 = ZEPHIR_IS_FALSE(&_43);
	if (_44) {
		_44 = Z_TYPE_P(&response) == IS_OBJECT;
	}
	if (_44) {
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
PHP_METHOD(PhalconPlus_Rpc_Server_AbstractServer, callByObject)
{
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(rawData)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
		zephir_throw_exception_debug(&_0$$3, "phalconplus/Rpc/Server/AbstractServer.zep", 99);
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
		zephir_throw_exception_debug(&_3$$4, "phalconplus/Rpc/Server/AbstractServer.zep", 102);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&request);
	if (!(zephir_array_isset_string_fetch(&request, &rawData, SL("args"), 0))) {
		ZEPHIR_INIT_NVAR(&request);
		ZVAL_NULL(&request);
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "service:method(args) must exists. All of them!!!", "phalconplus/Rpc/Server/AbstractServer.zep", 113);
		return;
	}
	ZEPHIR_OBS_NVAR(&logId);
	if (zephir_array_isset_string_fetch(&logId, &rawData, SL("logId"), 0)) {
		ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_logger_processor_logid_ce, "setid", &_9, 0, &logId);
		zephir_check_call_status();
	}
	zephir_read_property(&_10, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "logger");
	ZEPHIR_CALL_METHOD(&_11, &_10, "has", NULL, 0, &_7);
	zephir_check_call_status();
	if (zephir_is_true(&_11)) {
		ZEPHIR_INIT_VAR(&_12$$8);
		zephir_json_encode(&_12$$8, &request, 0 );
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_SVSVSVSV(&message, "RPC Request - logId: ", &logId, ", invoke: ", &service, "::", &method, ", args: ", &_12$$8);
		zephir_read_property(&_13$$8, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_15$$8);
		ZVAL_STRING(&_15$$8, "logger");
		ZEPHIR_CALL_METHOD(&_14$$8, &_13$$8, "get", NULL, 0, &_15$$8);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_14$$8, "info", NULL, 0, &message);
		zephir_check_call_status();
	}
	zephir_read_property(&_16, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property(&_18, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property(&_20, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_7);
	ZVAL_STRING(&_7, "logger");
	ZEPHIR_CALL_METHOD(&_21, &_20, "has", NULL, 0, &_7);
	zephir_check_call_status();
	if (zephir_is_true(&_21)) {
		ZEPHIR_INIT_VAR(&_22$$9);
		zephir_json_encode(&_22$$9, &response, 0 );
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_SVSVSVSV(&message, "RPC Response - logId: ", &logId, ", invoke: ", &service, "::", &method, ", response: ", &_22$$9);
		zephir_read_property(&_23$$9, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_25$$9);
		ZVAL_STRING(&_25$$9, "logger");
		ZEPHIR_CALL_METHOD(&_24$$9, &_23$$9, "get", NULL, 0, &_25$$9);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_24$$9, "info", NULL, 0, &message);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&response);
}

