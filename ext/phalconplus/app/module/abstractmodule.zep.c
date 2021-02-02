
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(PhalconPlus_App_Module_AbstractModule) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\App\\Module, AbstractModule, phalconplus, app_module_abstractmodule, zephir_get_internal_ce(SL("phalcon\\di\\injectable")), phalconplus_app_module_abstractmodule_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalconplus_app_module_abstractmodule_ce, SL("app"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_app_module_abstractmodule_ce, SL("def"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_app_module_abstractmodule_ce, SL("engine"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, getApp) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "app");

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, getDef) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "def");

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, getEngine) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "engine");

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *app, app_sub, *def = NULL, def_sub, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&def_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &app, &def);

	if (!def) {
		def = &def_sub;
		def = &__$null;
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("app"), app);
	zephir_update_property_zval(this_ptr, ZEND_STRL("def"), def);
	ZEPHIR_CALL_METHOD(&_0, app, "di", NULL, 51);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, isPrimary) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("def"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getisprimary", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_TRUE_IDENTICAL(&_1));

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, isCli) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("def"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getrunmode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "iscli", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, isWeb) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("def"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getrunmode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "isweb", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, isSrv) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("def"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getrunmode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "issrv", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, isMicro) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("def"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getrunmode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "ismicro", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, getName) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("def"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getname", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, app) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "app");

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, di) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "container");

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, def) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "def");

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, config) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("def"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "config", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, engine) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "engine");

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, __call) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params, _0;
	zval *method_param = NULL, *params_param = NULL, _1;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &method_param, &params_param);

	zephir_get_strval(&method, method_param);
	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("def"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, &method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, exec) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, _0, _1, eventsManager, engineClass, engineName, _2, _3, _4, _8, _9, _10, _12, _5$$4, _7$$4;
	zval params, _11, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&engineClass);
	ZVAL_UNDEF(&engineName);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &params_param);

	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("def"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "isprimary", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Only primary module can be executed", "phalconplus/App/Module/AbstractModule.zep", 92);
		return;
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("def"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&engineName, &_2, "getmapclassname", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, &_3, "getinternaleventsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&eventsManager, &_4);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_6$$4);
		zephir_create_array(&_6$$4, 2, 0);
		zephir_array_fast_append(&_6$$4, &engineClass);
		zephir_array_fast_append(&_6$$4, &params);
		ZEPHIR_INIT_VAR(&_7$$4);
		ZVAL_STRING(&_7$$4, "module:beforeStartEngine");
		ZEPHIR_CALL_METHOD(&_5$$4, &eventsManager, "fire", NULL, 0, &_7$$4, this_ptr, &_6$$4);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_5$$4)) {
		}
	}
	zephir_read_property(&_8, this_ptr, ZEND_STRL("engine"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_8)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "registerengine", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "di", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_9, this_ptr, ZEND_STRL("engine"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "appEngine");
	ZEPHIR_CALL_METHOD(NULL, &_4, "setshared", NULL, 0, &_10, &_9);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	zephir_create_array(&_11, 2, 0);
	ZEPHIR_OBS_VAR(&_12);
	zephir_read_property(&_12, this_ptr, ZEND_STRL("engine"), PH_NOISY_CC);
	zephir_array_fast_append(&_11, &_12);
	ZEPHIR_INIT_NVAR(&_10);
	ZVAL_STRING(&_10, "exec");
	zephir_array_fast_append(&_11, &_10);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_11, &params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, registerAutoloaders) {

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, registerServices) {

}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, registerEvents) {

	zval *this_ptr = getThis();



}

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, registerEngine) {

	zend_class_entry *_5;
	zval _0, _1, engineClass, engineName, _2, _3, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&engineClass);
	ZVAL_UNDEF(&engineName);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("def"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "isprimary", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		RETURN_THIS();
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("def"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&engineName, &_2, "getmapclassname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&engineClass);
	ZEPHIR_CONCAT_SV(&engineClass, "\\PhalconPlus\\App\\Engine\\", &engineName);
	ZEPHIR_INIT_VAR(&_3);
	zephir_fetch_safe_class(&_4, &engineClass);
	_5 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_4), Z_STRLEN_P(&_4), ZEND_FETCH_CLASS_AUTO);
	if(!_5) {
		RETURN_MM_NULL();
	}
	object_init_ex(&_3, _5);
	if (zephir_has_constructor(&_3)) {
		ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 0, this_ptr);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("engine"), &_3);
	RETURN_THIS();

}

