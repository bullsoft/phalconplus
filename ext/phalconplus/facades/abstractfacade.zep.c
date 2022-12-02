
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Facades_AbstractFacade)
{
	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Facades, AbstractFacade, phalconplus, facades_abstractfacade, phalconplus_facades_abstractfacade_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalconplus_facades_abstractfacade_ce, SL("app"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);
	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Facades_AbstractFacade, getName)
{
}

PHP_METHOD(PhalconPlus_Facades_AbstractFacade, resolve)
{
	zval *di, di_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(di, zephir_get_internal_ce(SL("phalcon\\di\\di")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &di);


	RETURN_NULL();
}

PHP_METHOD(PhalconPlus_Facades_AbstractFacade, setApp)
{
	zval *app, app_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(app, zephir_get_internal_ce(SL("phalconplus\\app\\app")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &app);


	zephir_update_static_property_ce(phalconplus_facades_abstractfacade_ce, ZEND_STRL("app"), app);
}

PHP_METHOD(PhalconPlus_Facades_AbstractFacade, app)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_static_property_ce(&_0, phalconplus_facades_abstractfacade_ce, SL("app"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);
}

PHP_METHOD(PhalconPlus_Facades_AbstractFacade, getApp)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_static_property_ce(&_0, phalconplus_facades_abstractfacade_ce, SL("app"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);
}

PHP_METHOD(PhalconPlus_Facades_AbstractFacade, itself)
{
	zend_bool _6$$4;
	zend_class_entry *_2;
	zval di, name, facade, service, _0, _1, _3, _4, _5$$3, _7$$4, _8$$4, _9$$5, _10$$6, _11$$6, _12$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&facade);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);


	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, phalconplus_facades_abstractfacade_ce, SL("app"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&di, &_0, "di", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	zephir_get_called_class(&name);
	ZEPHIR_INIT_VAR(&facade);
	zephir_fetch_safe_class(&_1, &name);
	_2 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_1), Z_STRLEN_P(&_1), ZEND_FETCH_CLASS_AUTO);
	if(!_2) {
		RETURN_MM_NULL();
	}
	object_init_ex(&facade, _2);
	if (zephir_has_constructor(&facade)) {
		ZEPHIR_CALL_METHOD(NULL, &facade, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_CALL_METHOD(&_4, &facade, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, &di, "has", NULL, 0, &_4);
	zephir_check_call_status();
	if (zephir_is_true(&_3)) {
		ZEPHIR_CALL_METHOD(&_5$$3, &facade, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&service, &di, "get", NULL, 0, &_5$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&service, &facade, "resolve", NULL, 0, &di);
		zephir_check_call_status();
		_6$$4 = Z_TYPE_P(&service) == IS_NULL;
		if (_6$$4) {
			ZEPHIR_CALL_METHOD(&_8$$4, &facade, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_7$$4, &di, "has", NULL, 0, &_8$$4);
			zephir_check_call_status();
			_6$$4 = zephir_is_true(&_7$$4);
		}
		if (_6$$4) {
			ZEPHIR_CALL_METHOD(&_9$$5, &facade, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&service, &di, "get", NULL, 0, &_9$$5);
			zephir_check_call_status();
		}
	}
	if (Z_TYPE_P(&service) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_10$$6);
		ZEPHIR_CONCAT_SV(&_10$$6, "Service can not be resovled: ", &name);
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 1, &_10$$6);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_11$$6);
		object_init_ex(&_11$$6, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_12$$6);
		ZEPHIR_CONCAT_SV(&_12$$6, "Service can not be resovled: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_11$$6, "__construct", NULL, 2, &_12$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$6, "phalconplus/Facades/AbstractFacade.zep", 50);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&service);
}

PHP_METHOD(PhalconPlus_Facades_AbstractFacade, __callStatic)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params, _0;
	zval *method_param = NULL, *params_param = NULL, service;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(method)
		Z_PARAM_ARRAY(params)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &params_param);
	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&params, params_param);


	ZEPHIR_CALL_STATIC(&service, "itself", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_array_fast_append(&_0, &service);
	zephir_array_fast_append(&_0, &method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &params);
	zephir_check_call_status();
	RETURN_MM();
}

