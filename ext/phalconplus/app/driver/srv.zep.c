
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


ZEPHIR_INIT_CLASS(PhalconPlus_App_Driver_Srv) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\App\\Driver, Srv, phalconplus, app_driver_srv, zephir_get_internal_ce(SL("phalcon\\di\\injectable")), phalconplus_app_driver_srv_method_entry, 0);

	zend_declare_property_null(phalconplus_app_driver_srv_ce, SL("app"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_app_driver_srv_ce, SL("handler"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalconplus_app_driver_srv_ce, 1, phalconplus_app_driver_appdriver_ce);
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_App_Driver_Srv, __construct) {

	zend_class_entry *_10$$7 = NULL;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *app, app_sub, *handler = NULL, handler_sub, __$null, di, _0, backendSrv, _1, _2, moduleConf, _5, _6, _7, _3$$3, _4$$5, _8$$6, _9$$7, _11$$7, _12$$7, _13$$7, _14$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&backendSrv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&moduleConf);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &app, &handler);

	if (!handler) {
		handler = &handler_sub;
		handler = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("app"), app);
	zephir_read_property(&_0, this_ptr, SL("app"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&di, &_0, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, &di);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&backendSrv);
	ZVAL_NULL(&backendSrv);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "backendSrv");
	ZEPHIR_CALL_METHOD(&_1, &di, "has", NULL, 0, &_2);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "backendSrv");
		ZEPHIR_CALL_METHOD(&backendSrv, &di, "get", NULL, 0, &_3$$3);
		zephir_check_call_status();
		if (!(zephir_instance_of_ev(&backendSrv, phalconplus_rpc_server_abstractserver_ce))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Service object(DI[\"backendSrv\"]) must be type of \\PhalconPlus\\Rpc\\Server\\AbstractServer", "phalconplus/App/Driver/Srv.zep", 28);
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&backendSrv);
		object_init_ex(&backendSrv, phalconplus_rpc_server_simpleserver_ce);
		ZEPHIR_CALL_METHOD(NULL, &backendSrv, "__construct", NULL, 41, &di);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$5);
		ZVAL_STRING(&_4$$5, "backendSrv");
		ZEPHIR_CALL_METHOD(NULL, &di, "setshared", NULL, 0, &_4$$5, &backendSrv);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_5, app, "getmodule", NULL, 42);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&moduleConf, &_5, "config", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_6, &moduleConf, SL("application"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_7, &_6, SL("handler"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_STRING(&_7, "yar")) {
		ZEPHIR_INIT_VAR(&_8$$6);
		object_init_ex(&_8$$6, zephir_get_internal_ce(SL("yar_server")));
		ZEPHIR_CALL_METHOD(NULL, &_8$$6, "__construct", NULL, 0, &backendSrv);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("handler"), &_8$$6);
	} else {
		ZEPHIR_INIT_VAR(&_9$$7);
		if (!_10$$7) {
		_10$$7 = zephir_fetch_class_str_ex(SL("PhalconPlus\\App\\Driver\\YarServerPlus"), ZEND_FETCH_CLASS_AUTO);
		}
		object_init_ex(&_9$$7, _10$$7);
		if (zephir_has_constructor(&_9$$7)) {
			ZEPHIR_CALL_METHOD(NULL, &_9$$7, "__construct", NULL, 0, &di);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, SL("handler"), &_9$$7);
		zephir_read_property(&_11$$7, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_11$$7, "setserver", NULL, 0, &backendSrv);
		zephir_check_call_status();
		zephir_read_property(&_12$$7, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_14$$7);
		ZVAL_STRING(&_14$$7, "eventsManager");
		ZEPHIR_CALL_METHOD(&_13$$7, &di, "get", NULL, 0, &_14$$7);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_12$$7, "seteventsmanager", NULL, 0, &_13$$7);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_App_Driver_Srv, exec) {

	zval _0, _1, _2, content, response, _3, _4, _5, _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("app"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "isauto", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		RETURN_THIS();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 43);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "handle", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&content, "ob_get_clean", NULL, 44);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("app"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, &_3, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "response");
	ZEPHIR_CALL_METHOD(&response, &_4, "get", NULL, 0, &_5);
	zephir_check_call_status();
	ZVAL_LONG(&_6, 200);
	ZEPHIR_INIT_NVAR(&_5);
	ZVAL_STRING(&_5, "OK");
	ZEPHIR_CALL_METHOD(NULL, &response, "setstatuscode", NULL, 0, &_6, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &response, "setcontent", NULL, 0, &content);
	zephir_check_call_status();
	RETURN_CCTOR(&response);

}

PHP_METHOD(PhalconPlus_App_Driver_Srv, setHandler) {

	zend_bool _0;
	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &handler);



	_0 = (zephir_is_instance_of(handler, SL("PhalconPlus\\App\\Driver\\BaseApplication")));
	if (!(_0)) {
		_0 = (zephir_instance_of_ev(handler, zephir_get_internal_ce(SL("yar_server"))));
	}
	if (EXPECTED(_0)) {
		zephir_update_property_zval(this_ptr, SL("handler"), handler);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalconplus_base_exception_ce, "Application must be instance of phalcon\\appliction or yar_server", "phalconplus/App/Driver/Srv.zep", 65);
		return;
	}
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_App_Driver_Srv, getHandler) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("handler"), PH_NOISY_CC);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Sorry, empty handler", "phalconplus/App/Driver/Srv.zep", 74);
		return;
	}
	RETURN_MM_MEMBER(getThis(), "handler");

}

