
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Bootstrap)
{
	ZEPHIR_REGISTER_CLASS(PhalconPlus, Bootstrap, phalconplus, bootstrap, phalconplus_bootstrap_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("app"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Bootstrap, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL, *_3 = NULL;
	zval *moduleDir_param = NULL, *env_param = NULL, *runMode_param = NULL, _2$$3, _4, _5, config, _6, _7;
	zval moduleDir, env, runMode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleDir);
	ZVAL_UNDEF(&env);
	ZVAL_UNDEF(&runMode);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(moduleDir)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(env)
		Z_PARAM_STR(runMode)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &moduleDir_param, &env_param, &runMode_param);
	if (UNEXPECTED(Z_TYPE_P(moduleDir_param) != IS_STRING && Z_TYPE_P(moduleDir_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleDir' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(moduleDir_param) == IS_STRING)) {
		zephir_get_strval(&moduleDir, moduleDir_param);
	} else {
		ZEPHIR_INIT_VAR(&moduleDir);
	}
	if (!env_param) {
		ZEPHIR_INIT_VAR(&env);
		ZVAL_STRING(&env, "");
	} else {
		zephir_get_strval(&env, env_param);
	}
	if (!runMode_param) {
		ZEPHIR_INIT_VAR(&runMode);
		ZVAL_STRING(&runMode, "");
	} else {
		zephir_get_strval(&runMode, runMode_param);
	}


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_enum_sys_ce, "init", &_0, 0, &moduleDir);
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_CALL_CE_STATIC(&_2$$3, phalconplus_enum_sys_ce, "getcomposerautoloadpath", &_3, 0);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_enum_sys_ce, "load", &_1, 0, &_2$$3);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_4);
		ZVAL_OBJ(&_4, EG(exception));
		Z_ADDREF_P(&_4);
		ZEPHIR_INIT_VAR(&_5);
		if (zephir_is_instance_of(&_4, SL("Exception"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&_5, &_4);
		}
	}
	ZEPHIR_CALL_METHOD(&config, this_ptr, "initconf", NULL, 85);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	object_init_ex(&_6, phalconplus_app_app_ce);
	ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", NULL, 86, &config);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, &_6, "boot", NULL, 87, &env, &runMode);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("app"), &_7);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(PhalconPlus_Bootstrap, initConf)
{
	zval globalConf, e, globalConfPath, _3, _1$$3, _4$$4, _5$$4, _6$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&globalConf);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&globalConfPath);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&globalConfPath, phalconplus_enum_sys_ce, "getglobalconfigpath", &_0, 0);
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&globalConf);
		object_init_ex(&globalConf, zephir_get_internal_ce(SL("phalcon\\config\\config")));
		ZEPHIR_CALL_CE_STATIC(&_1$$3, phalconplus_enum_sys_ce, "load", &_2, 0, &globalConfPath);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(NULL, &globalConf, "__construct", NULL, 0, &_1$$3);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_3);
		ZVAL_OBJ(&_3, EG(exception));
		Z_ADDREF_P(&_3);
		if (zephir_is_instance_of(&_3, SL("Exception"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&e, &_3);
			ZEPHIR_INIT_NVAR(&globalConf);
			object_init_ex(&globalConf, zephir_get_internal_ce(SL("phalcon\\config\\config")));
			ZEPHIR_INIT_VAR(&_4$$4);
			array_init(&_4$$4);
			ZEPHIR_CALL_METHOD(NULL, &globalConf, "__construct", NULL, 0, &_4$$4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_5$$4, &e, "getmessage", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_6$$4);
			ZEPHIR_CONCAT_SV(&_6$$4, "Global config file not exists: ", &_5$$4);
			ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 1, &_6$$4);
			zephir_check_call_status();
		}
	}
	RETURN_CCTOR(&globalConf);
}

PHP_METHOD(PhalconPlus_Bootstrap, getApp)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "app");
}

PHP_METHOD(PhalconPlus_Bootstrap, app)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "app");
}

PHP_METHOD(PhalconPlus_Bootstrap, terminate)
{
	zval __$null;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);



	zephir_update_property_zval(this_ptr, ZEND_STRL("app"), &__$null);
}

