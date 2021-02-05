
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

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, uri_sub, __$null, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = &uri_sub;
		ZEPHIR_CPY_WRT(uri, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(uri);
	}


	_0 = !(Z_TYPE_P(uri) == IS_STRING);
	if (!(_0)) {
		_0 = ZEPHIR_IS_EMPTY(uri);
	}
	if (_0) {
		ZEPHIR_INIT_NVAR(uri);
		ZVAL_NULL(uri);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_1, "handle", NULL, 0, uri);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_Engine_Web, setHandler) {

	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &handler);



	if (EXPECTED(zephir_instance_of_ev(handler, zephir_get_internal_ce(SL("phalcon\\application\\abstractapplication"))))) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), handler);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(phalconplus_base_exception_ce, "Application must be instance of phalcon\\application", "phalconplus/App/Engine/Web.zep", 48);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Sorry, empty web handler", "phalconplus/App/Engine/Web.zep", 62);
		return;
	}
	RETURN_MM_MEMBER(getThis(), "handler");

}

