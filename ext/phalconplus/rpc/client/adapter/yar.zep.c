
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
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/concat.h"
#include "kernel/variables.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_Client_Adapter_Yar)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Rpc\\Client\\Adapter, Yar, phalconplus, rpc_client_adapter_yar, phalconplus_rpc_client_abstractclient_ce, phalconplus_rpc_client_adapter_yar_method_entry, 0);

	zend_declare_property_string(phalconplus_rpc_client_adapter_yar_ce, SL("remoteServerUrl"), "", ZEND_ACC_PRIVATE);
	zend_declare_property_null(phalconplus_rpc_client_adapter_yar_ce, SL("client"), ZEND_ACC_PRIVATE);
	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Yar, __construct)
{
	zend_string *_6$$4;
	zend_ulong _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *remoteServerUrl_param = NULL, *opts_param = NULL, key, _0, _1, _2, optKey$$4, optVal$$4, *_3$$4, _4$$4, _7$$5, _8$$6;
	zval remoteServerUrl, opts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&remoteServerUrl);
	ZVAL_UNDEF(&opts);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&optKey$$4);
	ZVAL_UNDEF(&optVal$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(remoteServerUrl)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(opts)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &remoteServerUrl_param, &opts_param);
	zephir_get_arrval(&remoteServerUrl, remoteServerUrl_param);
	if (!opts_param) {
		ZEPHIR_INIT_VAR(&opts);
		array_init(&opts);
	} else {
		zephir_get_arrval(&opts, opts_param);
	}


	if (ZEPHIR_IS_EMPTY(&remoteServerUrl)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "server url can not be empty", "phalconplus/Rpc/Client/Adapter/Yar.zep", 14);
		return;
	}
	ZEPHIR_CALL_FUNCTION(&key, "array_rand", NULL, 155, &remoteServerUrl);
	zephir_check_call_status();
	zephir_array_fetch(&_0, &remoteServerUrl, &key, PH_NOISY | PH_READONLY, "phalconplus/Rpc/Client/Adapter/Yar.zep", 17);
	zephir_update_property_zval(this_ptr, ZEND_STRL("remoteServerUrl"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, zephir_get_internal_ce(SL("yar_client")));
	zephir_read_property(&_2, this_ptr, ZEND_STRL("remoteServerUrl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("client"), &_1);
	if (!(ZEPHIR_IS_EMPTY(&opts))) {
		zephir_is_iterable(&opts, 0, "phalconplus/Rpc/Client/Adapter/Yar.zep", 25);
		if (Z_TYPE_P(&opts) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&opts), _5$$4, _6$$4, _3$$4)
			{
				ZEPHIR_INIT_NVAR(&optKey$$4);
				if (_6$$4 != NULL) { 
					ZVAL_STR_COPY(&optKey$$4, _6$$4);
				} else {
					ZVAL_LONG(&optKey$$4, _5$$4);
				}
				ZEPHIR_INIT_NVAR(&optVal$$4);
				ZVAL_COPY(&optVal$$4, _3$$4);
				zephir_read_property(&_7$$5, this_ptr, ZEND_STRL("client"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(NULL, &_7$$5, "setopt", NULL, 0, &optKey$$4, &optVal$$4);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &opts, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$4, &opts, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&optKey$$4, &opts, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&optVal$$4, &opts, "current", NULL, 0);
				zephir_check_call_status();
					zephir_read_property(&_8$$6, this_ptr, ZEND_STRL("client"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_CALL_METHOD(NULL, &_8$$6, "setopt", NULL, 0, &optKey$$4, &optVal$$4);
					zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &opts, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&optVal$$4);
		ZEPHIR_INIT_NVAR(&optKey$$4);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Yar, callByObject)
{
	zend_bool _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rawData_param = NULL, __$null, _0, _1, _2, message, rsp, e, _4, _5, _6, _11, _12, _13, _7$$3, _8$$3, _9$$3, _10$$3, _14$$4, _15$$4, _16$$4, _17$$4, _18$$5, _19$$5, _20$$5, _21$$5, _22$$5;
	zval rawData;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawData);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&rsp);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$4);
	ZVAL_UNDEF(&_16$$4);
	ZVAL_UNDEF(&_17$$4);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_20$$5);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(rawData)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &rawData_param);
	zephir_get_arrval(&rawData, rawData_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("namePrefix"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &rawData, SL("service"), PH_NOISY | PH_READONLY, "phalconplus/Rpc/Client/Adapter/Yar.zep", 30);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VV(&_2, &_0, &_1);
	zephir_array_update_string(&rawData, SL("service"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&message);
	ZVAL_STRING(&message, "");
	ZEPHIR_INIT_VAR(&rsp);
	ZVAL_NULL(&rsp);
	ZEPHIR_INIT_VAR(&e);
	ZVAL_NULL(&e);
	_3 = zephir_isset_property(this_ptr, SL("di"));
	if (_3) {
		zephir_read_property(&_4, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_6);
		ZVAL_STRING(&_6, "logger");
		ZEPHIR_CALL_METHOD(&_5, &_4, "has", NULL, 0, &_6);
		zephir_check_call_status();
		_3 = zephir_is_true(&_5);
	}
	if (_3) {
		ZEPHIR_INIT_VAR(&_7$$3);
		ZEPHIR_INIT_NVAR(&_7$$3);
		zephir_var_export_ex(&_7$$3, &rawData);
		ZEPHIR_INIT_NVAR(&message);
		ZEPHIR_CONCAT_SV(&message, "RemoteRpc> callByObject: ", &_7$$3);
		zephir_read_property(&_8$$3, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_10$$3);
		ZVAL_STRING(&_10$$3, "logger");
		ZEPHIR_CALL_METHOD(&_9$$3, &_8$$3, "get", NULL, 0, &_10$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_9$$3, "debug", NULL, 0, &message);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&rsp);
	object_init_ex(&rsp, phalconplus_base_protobuffer_ce);
	ZEPHIR_CALL_METHOD(NULL, &rsp, "__construct", NULL, 76);
	zephir_check_call_status();
	zephir_read_property(&_11, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_6);
	ZVAL_STRING(&_6, "logger");
	ZEPHIR_CALL_METHOD(&_12, &_11, "get", NULL, 0, &_6);
	zephir_check_call_status();
	zephir_read_property(&_13, &_12, ZEND_STRL("logId"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(&rsp, ZEND_STRL("logId"), &_13);

	/* try_start_1: */

		zephir_read_property(&_14$$4, this_ptr, ZEND_STRL("client"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_15$$4, &_14$$4, "callbyobject", NULL, 0, &rawData);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_update_property_zval(&rsp, ZEND_STRL("results"), &_15$$4);
		ZEPHIR_INIT_VAR(&_16$$4);
		ZEPHIR_INIT_NVAR(&_16$$4);
		ZVAL_STRING(&_16$$4, "success");
		zephir_update_property_zval(&rsp, ZEND_STRL("status"), &_16$$4);
		ZEPHIR_INIT_ZVAL_NREF(_17$$4);
		ZVAL_LONG(&_17$$4, 0);
		zephir_update_property_zval(&rsp, ZEND_STRL("code"), &_17$$4);
		ZEPHIR_INIT_NVAR(&_16$$4);
		ZVAL_STRING(&_16$$4, "");
		zephir_update_property_zval(&rsp, ZEND_STRL("message"), &_16$$4);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_NVAR(&_6);
		ZVAL_OBJ(&_6, EG(exception));
		Z_ADDREF_P(&_6);
		if (zephir_is_instance_of(&_6, SL("Exception"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_6);
			zephir_update_property_zval(&rsp, ZEND_STRL("results"), &__$null);
			ZEPHIR_INIT_VAR(&_18$$5);
			ZEPHIR_INIT_NVAR(&_18$$5);
			ZVAL_STRING(&_18$$5, "fail");
			zephir_update_property_zval(&rsp, ZEND_STRL("status"), &_18$$5);
			ZEPHIR_CALL_METHOD(&_19$$5, &e, "getcode", NULL, 0);
			zephir_check_call_status();
			ZVAL_LONG(&_20$$5, 1);
			ZEPHIR_CALL_FUNCTION(&_21$$5, "max", NULL, 154, &_19$$5, &_20$$5);
			zephir_check_call_status();
			zephir_update_property_zval(&rsp, ZEND_STRL("code"), &_21$$5);
			ZEPHIR_CALL_METHOD(&_22$$5, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_zval(&rsp, ZEND_STRL("message"), &_22$$5);
		}
	}
	RETURN_CCTOR(&rsp);
}

PHP_METHOD(PhalconPlus_Rpc_Client_Adapter_Yar, __call)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args, _1$$3;
	zval *method_param = NULL, *args_param = NULL, _0, _2$$3, _3$$4;
	zval method, _4$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(method)
		Z_PARAM_ARRAY(args)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &args_param);
	if (UNEXPECTED(Z_TYPE_P(method_param) != IS_STRING && Z_TYPE_P(method_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'method' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(method_param) == IS_STRING)) {
		zephir_get_strval(&method, method_param);
	} else {
		ZEPHIR_INIT_VAR(&method);
	}
	zephir_get_arrval(&args, args_param);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("client"), PH_NOISY_CC | PH_READONLY);
	if ((zephir_method_exists(&_0, &method)  == SUCCESS)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0);
		ZEPHIR_OBS_VAR(&_2$$3);
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("client"), PH_NOISY_CC);
		zephir_array_fast_append(&_1$$3, &_2$$3);
		zephir_array_fast_append(&_1$$3, &method);
		ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_1$$3, &args);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZEPHIR_CONCAT_SVS(&_4$$4, "Yar_Client: method(", &method, ") not exists");
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", NULL, 2, &_4$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "phalconplus/Rpc/Client/Adapter/Yar.zep", 57);
		ZEPHIR_MM_RESTORE();
		return;
	}
}
