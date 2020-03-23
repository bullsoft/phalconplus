
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(PhalconPlus_App_Engine_Srv) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\App\\Engine, Srv, phalconplus, app_engine_srv, zephir_get_internal_ce(SL("phalcon\\di\\injectable")), phalconplus_app_engine_srv_method_entry, 0);

	zend_declare_property_null(phalconplus_app_engine_srv_ce, SL("appModule"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_app_engine_srv_ce, SL("handler"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalconplus_app_engine_srv_ce, 1, phalconplus_app_engine_appengine_ce);
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_App_Engine_Srv, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *appModule, appModule_sub, *handler = NULL, handler_sub, __$null, di, backendSrv, _0, _1, moduleConf, _4, _5, _2$$3, _3$$5, _6$$6, _7$$7, _8$$7, _9$$7, _10$$7, _11$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&appModule_sub);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&backendSrv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&moduleConf);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &appModule, &handler);

	if (!handler) {
		handler = &handler_sub;
		handler = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("appModule"), appModule);
	ZEPHIR_CALL_METHOD(&di, appModule, "di", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, &di);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&backendSrv);
	ZVAL_NULL(&backendSrv);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "backendSrv");
	ZEPHIR_CALL_METHOD(&_0, &di, "has", NULL, 0, &_1);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZVAL_STRING(&_2$$3, "backendSrv");
		ZEPHIR_CALL_METHOD(&backendSrv, &di, "get", NULL, 0, &_2$$3);
		zephir_check_call_status();
		if (!(zephir_instance_of_ev(&backendSrv, phalconplus_rpc_server_abstractserver_ce))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Service object(DI[\"backendSrv\"]) must be type of \\PhalconPlus\\Rpc\\Server\\AbstractServer", "phalconplus/App/Engine/Srv.zep", 33);
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&backendSrv);
		object_init_ex(&backendSrv, phalconplus_rpc_server_simpleserver_ce);
		ZEPHIR_CALL_METHOD(NULL, &backendSrv, "__construct", NULL, 46, &di);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$5);
		ZVAL_STRING(&_3$$5, "backendSrv");
		ZEPHIR_CALL_METHOD(NULL, &di, "setshared", NULL, 0, &_3$$5, &backendSrv);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&moduleConf, appModule, "config", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_4, &moduleConf, SL("application"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, &_4, SL("handler"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING(&_5, "yar")) {
		ZEPHIR_INIT_VAR(&_6$$6);
		object_init_ex(&_6$$6, zephir_get_internal_ce(SL("yar_server")));
		ZEPHIR_CALL_METHOD(NULL, &_6$$6, "__construct", NULL, 0, &backendSrv);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("handler"), &_6$$6);
	} else {
		ZEPHIR_INIT_VAR(&_7$$7);
		object_init_ex(&_7$$7, phalconplus_rpc_yar_ce);
		ZEPHIR_CALL_METHOD(NULL, &_7$$7, "__construct", NULL, 47, &di);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("handler"), &_7$$7);
		zephir_read_property(&_8$$7, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_8$$7, "setserver", NULL, 0, &backendSrv);
		zephir_check_call_status();
		zephir_read_property(&_9$$7, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_11$$7);
		ZVAL_STRING(&_11$$7, "eventsManager");
		ZEPHIR_CALL_METHOD(&_10$$7, &di, "get", NULL, 0, &_11$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_9$$7, "seteventsmanager", NULL, 0, &_10$$7);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_App_Engine_Srv, exec) {

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

	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 48);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "handle", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&content, "ob_get_clean", NULL, 49);
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

PHP_METHOD(PhalconPlus_App_Engine_Srv, setHandler) {

	zend_bool _0;
	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &handler);



	_0 = (zephir_is_instance_of(handler, SL("PhalconPlus\\App\\Engine\\BaseApplication")));
	if (!(_0)) {
		_0 = (zephir_instance_of_ev(handler, zephir_get_internal_ce(SL("yar_server"))));
	}
	if (EXPECTED(_0)) {
		zephir_update_property_zval(this_ptr, SL("handler"), handler);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalconplus_base_exception_ce, "Application must be instance of phalcon\\appliction or yar_server", "phalconplus/App/Engine/Srv.zep", 69);
		return;
	}
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_App_Engine_Srv, handler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "handler");

}

PHP_METHOD(PhalconPlus_App_Engine_Srv, getHandler) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Sorry, empty handler", "phalconplus/App/Engine/Srv.zep", 83);
		return;
	}
	RETURN_MM_MEMBER(getThis(), "handler");

}

