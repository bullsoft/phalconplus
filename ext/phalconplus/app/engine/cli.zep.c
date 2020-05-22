
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


ZEPHIR_INIT_CLASS(PhalconPlus_App_Engine_Cli) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\App\\Engine, Cli, phalconplus, app_engine_cli, zephir_get_internal_ce(SL("phalcon\\di\\injectable")), phalconplus_app_engine_cli_method_entry, 0);

	zend_declare_property_null(phalconplus_app_engine_cli_ce, SL("appModule"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_app_engine_cli_ce, SL("handler"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalconplus_app_engine_cli_ce, 1, phalconplus_app_engine_appengine_ce);
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_App_Engine_Cli, __construct) {

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
		object_init_ex(&_0$$3, zephir_get_internal_ce(SL("phalcon\\cli\\console")));
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

PHP_METHOD(PhalconPlus_App_Engine_Cli, exec) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *argv_param = NULL, *di = NULL, di_sub, __$null, _0;
	zval argv;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&argv);
	ZVAL_UNDEF(&di_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &argv_param, &di);

	zephir_get_arrval(&argv, argv_param);
	if (!di) {
		di = &di_sub;
		di = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "handle", NULL, 0, &argv);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_Engine_Cli, setHandler) {

	zend_class_entry *_1$$4 = NULL;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *handler, handler_sub, _0$$4, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &handler);



	if (EXPECTED(zephir_is_instance_of(handler, SL("PhalconPlus\\App\\Engine\\BaseApplication")))) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("handler"), handler);
	} else {
		ZEPHIR_INIT_VAR(&_0$$4);
		if (!_1$$4) {
		_1$$4 = zephir_fetch_class_str_ex(SL("PhalconPlus\\App\\Engine\\BaseException"), ZEND_FETCH_CLASS_AUTO);
		}
		object_init_ex(&_0$$4, _1$$4);
		if (zephir_has_constructor(&_0$$4)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "Handler must be instance of phalcon\\application");
			ZEPHIR_CALL_METHOD(NULL, &_0$$4, "__construct", NULL, 0, &_2$$4);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(&_0$$4, "phalconplus/App/Engine/Cli.zep", 40);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_App_Engine_Cli, handler) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "handler");

}

PHP_METHOD(PhalconPlus_App_Engine_Cli, getHandler) {

	zend_class_entry *_2$$3 = NULL;
	zval _0, _1$$3, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("handler"), PH_NOISY_CC);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		if (!_2$$3) {
		_2$$3 = zephir_fetch_class_str_ex(SL("PhalconPlus\\App\\Engine\\BaseException"), ZEND_FETCH_CLASS_AUTO);
		}
		object_init_ex(&_1$$3, _2$$3);
		if (zephir_has_constructor(&_1$$3)) {
			ZEPHIR_INIT_VAR(&_3$$3);
			ZVAL_STRING(&_3$$3, "Sorry, empty cli handler");
			ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0, &_3$$3);
			zephir_check_call_status();
		}
		zephir_throw_exception_debug(&_1$$3, "phalconplus/App/Engine/Cli.zep", 54);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_MM_MEMBER(getThis(), "handler");

}

