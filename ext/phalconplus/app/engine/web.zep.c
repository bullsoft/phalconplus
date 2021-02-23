
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
#include "kernel/exception.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PhalconPlus_App_Engine_Web) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\App\\Engine, Web, phalconplus, app_engine_web, zephir_get_internal_ce(SL("phalcon\\di\\injectable")), phalconplus_app_engine_web_method_entry, 0);

	zend_declare_property_null(phalconplus_app_engine_web_ce, SL("appModule"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_app_engine_web_ce, SL("handler"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalconplus_app_engine_web_ce, 1, phalconplus_app_engine_appengine_ce);
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_App_Engine_Web, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *appModule, appModule_sub, *handler = NULL, handler_sub, __$null, di, _1, _2, _3, _4, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&appModule_sub);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &appModule, &handler);

	if (!handler) {
		handler = &handler_sub;
		handler = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("appModule"), appModule);
	ZEPHIR_CALL_METHOD(&di, appModule, "di", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, &di);
	zephir_check_call_status();
	if (Z_TYPE_P(handler) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, zephir_get_internal_ce(SL("phalcon\\mvc\\application")));
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), &_0$$3);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), handler);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_1, "setdi", NULL, 0, &di);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "eventsManager");
	ZEPHIR_CALL_METHOD(&_3, &di, "get", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_2, "seteventsmanager", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @request a uri string (for \Phalcon\Mvc\Application) or Psr\Http\Message\Request
 */
PHP_METHOD(PhalconPlus_App_Engine_Web, exec) {

	zend_class_entry *_3$$5;
	zval className$$5;
	zend_bool _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, uri_sub, __$null, _0, _1, request$$3, _4$$3, _5$$6, _6$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&request$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&className$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = &uri_sub;
		uri = &__$null;
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC);
	if (zephir_instance_of_ev(&_0, phalconplus_mvc_psrapplication_ce)) {
		_2$$3 = Z_TYPE_P(uri) == IS_OBJECT;
		if (_2$$3) {
			_2$$3 = zephir_is_instance_of(uri, SL("Psr\\Http\\Message\\ServerRequestInterface"));
		}
		if (_2$$3) {
			ZEPHIR_CPY_WRT(&request$$3, uri);
		} else {
			ZEPHIR_INIT_VAR(&className$$5);
			ZVAL_STRING(&className$$5, "GuzzleHttp\\Psr7\\ServerRequest");
			_3$$5 = zephir_fetch_class(&className$$5);
			ZEPHIR_CALL_CE_STATIC(&request$$3, _3$$5, "fromglobals", NULL, 0);
			zephir_check_call_status();
		}
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_4$$3, "handle", NULL, 0, &request$$3);
		zephir_check_call_status();
		RETURN_MM();
	} else if (zephir_instance_of_ev(&_1, zephir_get_internal_ce(SL("phalcon\\mvc\\application")))) {
		zephir_read_property(&_5$$6, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_6$$6, "strval", NULL, 27, uri);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&_5$$6, "handle", NULL, 0, &_6$$6);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Handler for Web-Engine must be PsrHandler or MvcHandler", "phalconplus/App/Engine/Web.zep", 56);
	return;

}

PHP_METHOD(PhalconPlus_App_Engine_Web, setHandler) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &handler);



	if (EXPECTED(zephir_instance_of_ev(handler, zephir_get_internal_ce(SL("phalcon\\application\\abstractapplication"))))) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), handler);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalconplus_base_exception_ce, "Application must be instance of phalcon\\application", "phalconplus/App/Engine/Web.zep", 64);
		return;
	}
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_App_Engine_Web, handler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "handler");

}

PHP_METHOD(PhalconPlus_App_Engine_Web, getHandler) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Sorry, empty web handler", "phalconplus/App/Engine/Web.zep", 78);
		return;
	}
	RETURN_MM_MEMBER(getThis(), "handler");

}

