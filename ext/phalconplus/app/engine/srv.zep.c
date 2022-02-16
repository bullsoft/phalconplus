
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(PhalconPlus_App_Engine_Srv)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\App\\Engine, Srv, phalconplus, app_engine_srv, phalconplus_app_engine_abstractengine_ce, phalconplus_app_engine_srv_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(PhalconPlus_App_Engine_Srv, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *appModule, appModule_sub, *handler = NULL, handler_sub, __$null, di, moduleConf, backendSrv, _0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&appModule_sub);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&moduleConf);
	ZVAL_UNDEF(&backendSrv);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(appModule, phalconplus_app_module_abstractmodule_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(handler, zephir_get_internal_ce(SL("phalcon\\application\\abstractapplication")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &appModule, &handler);
	if (!handler) {
		handler = &handler_sub;
		ZEPHIR_CPY_WRT(handler, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(handler);
	}


	ZEPHIR_CALL_METHOD(&di, appModule, "di", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&moduleConf, appModule, "config", NULL, 0);
	zephir_check_call_status();
	if (Z_TYPE_P(handler) == IS_NULL) {
		zephir_read_property(&_0$$3, &moduleConf, ZEND_STRL("application"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_1$$3, &_0$$3, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
		if (ZEPHIR_IS_STRING(&_1$$3, "yar")) {
			ZEPHIR_INIT_NVAR(handler);
			object_init_ex(handler, phalconplus_rpc_yarserverwrapper_ce);
			ZEPHIR_CALL_METHOD(NULL, handler, "__construct", NULL, 47);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(handler);
			object_init_ex(handler, phalconplus_rpc_yar_ce);
			ZEPHIR_CALL_METHOD(NULL, handler, "__construct", NULL, 48);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(&backendSrv, this_ptr, "newservice", NULL, 49, &di);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, handler, "setserver", NULL, 50, &backendSrv);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalconplus_app_engine_srv_ce, getThis(), "__construct", &_2, 0, appModule, handler);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(PhalconPlus_App_Engine_Srv, newService)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di, di_sub, backendSrv, _0, _1, _2$$3, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
	ZVAL_UNDEF(&backendSrv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(di, zephir_get_internal_ce(SL("phalcon\\di\\diinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &di);


	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "backendSrv");
	ZEPHIR_CALL_METHOD(&_0, di, "has", NULL, 0, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "backendSrv");
		ZEPHIR_CALL_METHOD(&backendSrv, di, "get", NULL, 0, &_2$$3);
		zephir_check_call_status();
		if (!(zephir_instance_of_ev(&backendSrv, phalconplus_rpc_server_abstractserver_ce))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Service object(DI[\"backendSrv\"]) must be type of PhalconPlus\\Rpc\\Server\\AbstractServer", "phalconplus/App/Engine/Srv.zep", 44);
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&backendSrv);
		object_init_ex(&backendSrv, phalconplus_rpc_server_simpleserver_ce);
		ZEPHIR_CALL_METHOD(NULL, &backendSrv, "__construct", NULL, 51, di);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_STRING(&_3$$5, "backendSrv");
		ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, 0, &_3$$5, &backendSrv);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&backendSrv);
}

PHP_METHOD(PhalconPlus_App_Engine_Srv, exec)
{
	zval _0, content, response, _1, _2, _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 52);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "handle", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&content, "ob_get_clean", NULL, 53);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "response");
	ZEPHIR_CALL_METHOD(&response, &_1, "get", NULL, 0, &_2);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 200);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "OK");
	ZEPHIR_CALL_METHOD(NULL, &response, "setstatuscode", NULL, 0, &_3, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &content);
	zephir_check_call_status();
	RETURN_CCTOR(&response);
}

