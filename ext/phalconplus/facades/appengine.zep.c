
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Facades_AppEngine) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Facades, AppEngine, phalconplus, facades_appengine, phalconplus_facades_abstractfacade_ce, phalconplus_facades_appengine_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Facades_AppEngine, getName) {

	zval *this_ptr = getThis();


	RETURN_STRING("appEngine");

}

PHP_METHOD(PhalconPlus_Facades_AppEngine, request) {

	zend_bool _6$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params, _3;
	zval *controller_param = NULL, *action_param = NULL, *params_param = NULL, *callback = NULL, callback_sub, __$null, di, _0, dispatcher, view, _1, _2, ret, cont, _4, _5, _7$$6;
	zval controller, action;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&controller);
	ZVAL_UNDEF(&action);
	ZVAL_UNDEF(&callback_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&dispatcher);
	ZVAL_UNDEF(&view);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&ret);
	ZVAL_UNDEF(&cont);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &controller_param, &action_param, &params_param, &callback);

	zephir_get_strval(&controller, controller_param);
	zephir_get_strval(&action, action_param);
	zephir_get_arrval(&params, params_param);
	if (!callback) {
		callback = &callback_sub;
		ZEPHIR_CPY_WRT(callback, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(callback);
	}


	ZEPHIR_CALL_SELF(&_0, "app", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&di, &_0, "di", NULL, 51);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&dispatcher);
	ZVAL_NULL(&dispatcher);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "view");
	ZEPHIR_CALL_METHOD(&view, &di, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "dispatcher");
	ZEPHIR_CALL_METHOD(&_2, &di, "get", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&dispatcher);
	if (zephir_clone(&dispatcher, &_2) == FAILURE) {
		RETURN_MM();
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 3, 0);
	zephir_array_update_string(&_3, SL("controller"), &controller, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("action"), &action, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("params"), &params, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "forward", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &dispatcher, "dispatch", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&ret, &dispatcher, "getreturnedvalue", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_callable(callback))) {
		ZEPHIR_INIT_NVAR(callback);
		zephir_create_closure_ex(callback, NULL, phalconplus_3__closure_ce, SL("__invoke"));
	}
	ZEPHIR_CALL_METHOD(&_4, &dispatcher, "getcontrollername", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, &dispatcher, "getactionname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&cont, &view, "getrender", NULL, 0, &_4, &_5, &params, callback);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&cont)) {
		_6$$4 = Z_TYPE_P(&ret) == IS_NULL;
		if (!(_6$$4)) {
			_6$$4 = zephir_is_scalar(&ret);
		}
		if (_6$$4) {
			ZEPHIR_RETURN_CALL_FUNCTION("strval", NULL, 27, &ret);
			zephir_check_call_status();
			RETURN_MM();
		} else {
			ZVAL_LONG(&_7$$6, 256);
			zephir_json_encode(return_value, &ret, zephir_get_intval(&_7$$6) );
			RETURN_MM();
		}
	} else {
		RETURN_CCTOR(&cont);
	}

}

