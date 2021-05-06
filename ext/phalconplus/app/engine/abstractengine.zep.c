
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(PhalconPlus_App_Engine_AbstractEngine)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\App\\Engine, AbstractEngine, phalconplus, app_engine_abstractengine, zephir_get_internal_ce(SL("phalcon\\di\\injectable")), phalconplus_app_engine_abstractengine_method_entry, 0);

	zend_declare_property_null(phalconplus_app_engine_abstractengine_ce, SL("appModule"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalconplus_app_engine_abstractengine_ce, SL("handler"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(PhalconPlus_App_Engine_AbstractEngine, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *appModule, appModule_sub, *handler = NULL, handler_sub, __$null, di, _0$$3, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&appModule_sub);
	ZVAL_UNDEF(&handler_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(appModule, phalconplus_app_module_abstractmodule_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(handler, phalcon_application_abstractapplication_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	if (Z_TYPE_P(handler) != IS_NULL) {
		ZEPHIR_CALL_METHOD(NULL, handler, "setdi", NULL, 0, &di);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "eventsManager");
		ZEPHIR_CALL_METHOD(&_0$$3, &di, "get", NULL, 0, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, handler, "seteventsmanager", NULL, 0, &_0$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), handler);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(PhalconPlus_App_Engine_AbstractEngine, handler)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "handler");
}

PHP_METHOD(PhalconPlus_App_Engine_AbstractEngine, getHandler)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Sorry, empty cli handler", "phalconplus/App/Engine/AbstractEngine.zep", 36);
		return;
	}
	RETURN_MM_MEMBER(getThis(), "handler");
}

PHP_METHOD(PhalconPlus_App_Engine_AbstractEngine, setHandler)
{
	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(handler, phalcon_application_abstractapplication_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &handler);


	zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), handler);
	RETURN_THISW();
}

