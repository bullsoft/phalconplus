
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(PhalconPlus_App_Engine_Web)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\App\\Engine, Web, phalconplus, app_engine_web, phalconplus_app_engine_abstractengine_ce, phalconplus_app_engine_web_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(PhalconPlus_App_Engine_Web, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *appModule, appModule_sub, *handler = NULL, handler_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&appModule_sub);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_NULL(&__$null);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(appModule, zephir_get_internal_ce(SL("phalconplus\\app\\module\\abstractmodule")))
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


	if (Z_TYPE_P(handler) == IS_NULL) {
		ZEPHIR_INIT_NVAR(handler);
		object_init_ex(handler, zephir_get_internal_ce(SL("phalcon\\mvc\\application")));
		ZEPHIR_CALL_METHOD(NULL, handler, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_PARENT(NULL, phalconplus_app_engine_web_ce, getThis(), "__construct", &_0, 0, appModule, handler);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * @request (for \Phalcon\Mvc\Application) or Psr\Http\Message\Request
 */
PHP_METHOD(PhalconPlus_App_Engine_Web, exec)
{
	zend_class_entry *_3$$4;
	zval className$$4;
	zend_bool _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request = NULL, request_sub, __$null, _0, _1, _4$$3, _5$$5, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&className$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(request)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &request);
	if (!request) {
		request = &request_sub;
		ZEPHIR_CPY_WRT(request, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(request);
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC);
	if (zephir_instance_of_ev(&_0, phalconplus_mvc_psrapplication_ce)) {
		_2$$3 = Z_TYPE_P(request) == IS_OBJECT;
		if (_2$$3) {
			_2$$3 = zephir_is_instance_of(request, SL("Psr\\Http\\Message\\ServerRequestInterface"));
		}
		if (_2$$3) {
		} else {
			ZEPHIR_INIT_VAR(&className$$4);
			ZVAL_STRING(&className$$4, "GuzzleHttp\\Psr7\\ServerRequest");
			_3$$4 = zephir_fetch_class(&className$$4);
			ZEPHIR_CALL_CE_STATIC(request, _3$$4, "fromglobals", NULL, 0);
			zephir_check_call_status();
		}
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_4$$3, "handle", NULL, 0, request);
		zephir_check_call_status();
		RETURN_MM();
	} else if (zephir_is_instance_of(&_1, SL("Phalcon\\Mvc\\Application"))) {
		zephir_read_property(&_5$$5, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_6$$5, "strval", NULL, 27, request);
		zephir_check_call_status();
		ZEPHIR_RETURN_CALL_METHOD(&_5$$5, "handle", NULL, 0, &_6$$5);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Handler for Web-Engine must be PsrHandler or MvcHandler", "phalconplus/App/Engine/Web.zep", 40);
	return;
}

