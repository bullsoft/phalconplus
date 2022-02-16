
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/main.h"


ZEPHIR_INIT_CLASS(PhalconPlus_App_App)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\App, App, phalconplus, app_app, zephir_get_internal_ce(SL("phalcon\\application\\abstractapplication")), phalconplus_app_app_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_string(phalconplus_app_app_ce, SL("env"), "dev", ZEND_ACC_PROTECTED);
	zend_declare_property_bool(phalconplus_app_app_ce, SL("booted"), 0, ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalconplus_app_app_ce, SL("config"), ZEND_ACC_PROTECTED);
	zend_declare_property_long(phalconplus_app_app_ce, SL("requestNumber"), 0, ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalconplus_app_app_ce, SL("finalizers"), ZEND_ACC_PROTECTED);
	phalconplus_app_app_ce->create_object = zephir_init_properties_PhalconPlus_App_App;

	return SUCCESS;
}

PHP_METHOD(PhalconPlus_App_App, getConfig)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "config");
}

PHP_METHOD(PhalconPlus_App_App, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *config, config_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(config, zephir_get_internal_ce(SL("phalcon\\config\\config")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);


	zephir_update_property_zval(this_ptr, ZEND_STRL("config"), config);
	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_enum_sys_ce, "initapp", &_0, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(PhalconPlus_App_App, boot)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_9 = NULL, *_12 = NULL, *_14 = NULL, *_16 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *env_param = NULL, *runMode_param = NULL, __$false, sysEnv$$3, _0$$3, _1$$3, _2, _3, _5, _6, _8, _10, _11, _13, _15;
	zval env, runMode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&env);
	ZVAL_UNDEF(&runMode);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&sysEnv$$3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(env)
		Z_PARAM_STR(runMode)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &env_param, &runMode_param);
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


	if (EXPECTED(ZEPHIR_IS_EMPTY(&env))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "phalconplus.env");
		ZEPHIR_CALL_FUNCTION(&_1$$3, "get_cfg_var", NULL, 31, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&sysEnv$$3);
		zephir_fast_trim(&sysEnv$$3, &_1$$3, NULL , ZEPHIR_TRIM_BOTH);
		if (!(ZEPHIR_IS_EMPTY(&sysEnv$$3))) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("env"), &sysEnv$$3);
		}
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("env"), &env);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("env"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "APP_ENV");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_4, 32, &_3, &_2, &__$false);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, ZEND_STRL("env"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "APP_RUN_ENV");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_4, 32, &_3, &_5, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_6, phalconplus_enum_sys_ce, "getrootdir", &_7, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "APP_ROOT_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_4, 32, &_3, &_6, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_8, phalconplus_enum_sys_ce, "getprimarymoduledir", &_9, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "APP_MODULE_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_4, 32, &_3, &_8, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_10, phalconplus_enum_sys_ce, "getprimarymoduledir", &_9, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "APP_PRI_MODULE_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_4, 32, &_3, &_10, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_11, phalconplus_enum_sys_ce, "getcommondir", &_12, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "APP_ROOT_COMMON_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_4, 32, &_3, &_11, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_13, phalconplus_enum_sys_ce, "getgloballoaddir", &_14, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_4, 32, &_3, &_13, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_15, phalconplus_enum_sys_ce, "getglobalconfigdir", &_16, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "APP_ROOT_COMMON_CONF_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_4, 32, &_3, &_15, &__$false);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "bootprimarymodule", NULL, 33, &runMode);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(PhalconPlus_App_App, bootPrimaryModule)
{
	zend_class_entry *_9$$3 = NULL;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *runMode_param = NULL, __$true, __$false, primaryModuleDef, _0, _2, module, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _10$$3;
	zval runMode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&runMode);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&primaryModuleDef);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(runMode)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &runMode_param);
	if (!runMode_param) {
		ZEPHIR_INIT_VAR(&runMode);
		ZVAL_STRING(&runMode, "");
	} else {
		zephir_get_strval(&runMode, runMode_param);
	}


	ZEPHIR_INIT_VAR(&primaryModuleDef);
	object_init_ex(&primaryModuleDef, phalconplus_app_module_moduledef_ce);
	ZEPHIR_CALL_CE_STATIC(&_0, phalconplus_enum_sys_ce, "getprimarymoduledir", &_1, 0);
	zephir_check_call_status();
	ZVAL_BOOL(&_2, 1);
	ZEPHIR_CALL_METHOD(NULL, &primaryModuleDef, "__construct", NULL, 34, this_ptr, &_0, &_2, &runMode);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_2) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_3$$3, &primaryModuleDef, "newdi", NULL, 35);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, this_ptr, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "superApp");
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "setshared", NULL, 0, &_5$$3, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6$$3, this_ptr, "getdi", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_7$$3, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "config");
		ZEPHIR_CALL_METHOD(NULL, &_6$$3, "setshared", NULL, 0, &_5$$3, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_8$$3, this_ptr, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_5$$3);
		if (!_9$$3) {
		_9$$3 = zephir_fetch_class_str_ex(SL("Phalcon\\Loader"), ZEND_FETCH_CLASS_AUTO);
		}
		object_init_ex(&_5$$3, _9$$3);
		if (zephir_has_constructor(&_5$$3)) {
			ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZEPHIR_INIT_VAR(&_10$$3);
		ZVAL_STRING(&_10$$3, "loader");
		ZEPHIR_CALL_METHOD(NULL, &_8$$3, "setshared", NULL, 0, &_10$$3, &_5$$3);
		zephir_check_call_status();
	}
	if (1) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("booted"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("booted"), &__$false);
	}
	ZEPHIR_CALL_METHOD(&module, this_ptr, "registermodule", NULL, 36, &primaryModuleDef);
	zephir_check_call_status();
	RETURN_THIS();
}

PHP_METHOD(PhalconPlus_App_App, registerModule)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *moduleDef, moduleDef_sub, __$false, _0, _1, _5, _10, _14, module, _20, _21, _2$$3, _3$$3, _4$$3, _6$$4, _7$$4, _8$$4, _11$$5, _12$$5, _13$$5, _15$$6, _16$$6, moduleConf$$6, _19$$6, _17$$7, _18$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleDef_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&moduleConf$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(moduleDef, phalconplus_app_module_moduledef_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleDef);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, moduleDef, "getname", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_array_isset(&_0, &_1))) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$3, moduleDef, "getname", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch(&_3$$3, &_2$$3, &_4$$3, PH_NOISY | PH_READONLY, "phalconplus/App/App.zep", 81);
		RETURN_CTOR(&_3$$3);
	}
	zephir_read_property(&_5, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(Z_TYPE_P(&_5) == IS_NULL)) {
		ZEPHIR_INIT_VAR(&_6$$4);
		object_init_ex(&_6$$4, phalconplus_base_exception_ce);
		ZEPHIR_CALL_METHOD(&_7$$4, moduleDef, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$4);
		ZEPHIR_CONCAT_SV(&_8$$4, "DI doesn't load yet, failed to register module ", &_7$$4);
		ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", &_9, 2, &_8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$4, "phalconplus/App/App.zep", 84);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_10, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(Z_TYPE_P(&_10) == IS_NULL)) {
		ZEPHIR_INIT_VAR(&_11$$5);
		object_init_ex(&_11$$5, phalconplus_base_exception_ce);
		ZEPHIR_CALL_METHOD(&_12$$5, moduleDef, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_13$$5);
		ZEPHIR_CONCAT_SV(&_13$$5, "Config doesn't initial yet, failed to register module ", &_12$$5);
		ZEPHIR_CALL_METHOD(NULL, &_11$$5, "__construct", &_9, 2, &_13$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$5, "phalconplus/App/App.zep", 87);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_14, moduleDef, "isprimary", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_14)) {
		ZEPHIR_INIT_VAR(&_15$$6);
		ZVAL_STRING(&_15$$6, "APP_RUN_MODE");
		ZEPHIR_CALL_FUNCTION(&_16$$6, "defined", NULL, 37, &_15$$6);
		zephir_check_call_status();
		if (!(zephir_is_true(&_16$$6))) {
			ZEPHIR_CALL_METHOD(&_17$$7, moduleDef, "getmode", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_18$$7);
			ZVAL_STRING(&_18$$7, "APP_RUN_MODE");
			ZEPHIR_CALL_FUNCTION(NULL, "define", NULL, 32, &_18$$7, &_17$$7, &__$false);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&moduleConf$$6, moduleDef, "getconfig", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_19$$6, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_19$$6, "merge", NULL, 0, &moduleConf$$6);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&module, moduleDef, "checkout", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_20, &module, "isprimary", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_20)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultModule"), &module);
	}
	ZEPHIR_CALL_METHOD(&_21, moduleDef, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("modules"), &_21, &module);
	RETURN_CCTOR(&module);
}

PHP_METHOD(PhalconPlus_App_App, import)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *moduleName_param = NULL, _0;
	zval moduleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(moduleName)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);
	if (UNEXPECTED(Z_TYPE_P(moduleName_param) != IS_STRING && Z_TYPE_P(moduleName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(moduleName_param) == IS_STRING)) {
		zephir_get_strval(&moduleName, moduleName_param);
	} else {
		ZEPHIR_INIT_VAR(&moduleName);
	}


	ZVAL_BOOL(&_0, 0);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "dependmodule", NULL, 38, &moduleName, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(PhalconPlus_App_App, dependModule)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL, *_12 = NULL;
	zend_bool force;
	zval *moduleName_param = NULL, *force_param = NULL, _0, _1, moduleDef, _4, moduleConf, arrayConf, _13, module, _14, _2$$3, _3$$3, _6$$4, _7$$4, _8$$4, _9$$4, _10$$5;
	zval moduleName, _11$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&moduleDef);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&moduleConf);
	ZVAL_UNDEF(&arrayConf);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$5);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(moduleName)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(force)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &moduleName_param, &force_param);
	if (UNEXPECTED(Z_TYPE_P(moduleName_param) != IS_STRING && Z_TYPE_P(moduleName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(moduleName_param) == IS_STRING)) {
		zephir_get_strval(&moduleName, moduleName_param);
	} else {
		ZEPHIR_INIT_VAR(&moduleName);
	}
	if (!force_param) {
		force = 1;
	} else {
		force = zephir_get_boolval(force_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_trim(&_0, &moduleName, NULL , ZEPHIR_TRIM_BOTH);
	zephir_get_strval(&moduleName, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(zephir_array_isset(&_1, &moduleName))) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_3$$3, &_2$$3, &moduleName, PH_NOISY | PH_READONLY, "phalconplus/App/App.zep", 118);
		RETURN_CTOR(&_3$$3);
	}
	ZEPHIR_INIT_VAR(&moduleDef);
	object_init_ex(&moduleDef, phalconplus_app_module_moduledef_ce);
	ZEPHIR_CALL_CE_STATIC(&_4, phalconplus_enum_sys_ce, "getmoduledirbyname", &_5, 0, &moduleName);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &moduleDef, "__construct", NULL, 34, this_ptr, &_4);
	zephir_check_call_status();
	if (force == 0) {
		ZEPHIR_CALL_METHOD(&_6$$4, &moduleDef, "config", NULL, 39);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "application.exportable");
		ZVAL_BOOL(&_9$$4, 0);
		ZEPHIR_CALL_METHOD(&_7$$4, &_6$$4, "path", NULL, 0, &_8$$4, &_9$$4);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE(&_7$$4)) {
			ZEPHIR_INIT_VAR(&_10$$5);
			object_init_ex(&_10$$5, phalconplus_base_exception_ce);
			ZEPHIR_INIT_VAR(&_11$$5);
			ZEPHIR_CONCAT_VS(&_11$$5, &moduleName, " can't be imported as external library.");
			ZEPHIR_CALL_METHOD(NULL, &_10$$5, "__construct", NULL, 2, &_11$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_10$$5, "phalconplus/App/App.zep", 124);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&moduleConf);
	ZVAL_NULL(&moduleConf);
	ZEPHIR_CALL_METHOD(&_13, &moduleDef, "getconfigpath", NULL, 40);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&arrayConf, phalconplus_enum_sys_ce, "load", &_12, 0, &_13);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&module, this_ptr, "registermodule", NULL, 36, &moduleDef);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&moduleConf);
	object_init_ex(&moduleConf, zephir_get_internal_ce(SL("phalcon\\config\\config")));
	ZEPHIR_CALL_METHOD(NULL, &moduleConf, "__construct", NULL, 0, &arrayConf);
	zephir_check_call_status();
	zephir_read_property(&_14, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &moduleConf, "merge", NULL, 0, &_14);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setconfig", NULL, 41, &moduleConf);
	zephir_check_call_status();
	RETURN_CCTOR(&module);
}

PHP_METHOD(PhalconPlus_App_App, setConfig)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, config_sub, _0, _2, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(config, zephir_get_internal_ce(SL("phalcon\\config\\config")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zephir_get_internal_ce(SL("phalcon\\config\\config")));
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("config"), &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "merge", NULL, 0, config);
	zephir_check_call_status();
	RETURN_THIS();
}

PHP_METHOD(PhalconPlus_App_App, isBooted)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("booted"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_IS_TRUE_IDENTICAL(&_0));
}

PHP_METHOD(PhalconPlus_App_App, getEnv)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "env");
}

PHP_METHOD(PhalconPlus_App_App, setEnv)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *env_param = NULL;
	zval env;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&env);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(env)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &env_param);
	zephir_get_strval(&env, env_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("env"), &env);
	RETURN_THIS();
}

PHP_METHOD(PhalconPlus_App_App, handle)
{
	zval _4$$4, _8$$5;
	zval _0, _1, eventsManager, response, params, _2, _3$$4, _5$$4, _6$$4, _7$$5, _9$$5, _10$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_8$$5);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("requestNumber"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, (zephir_get_numberval(&_0) + 1));
	zephir_update_property_zval(this_ptr, ZEND_STRL("requestNumber"), &_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("booted"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE(&_1)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "bootprimarymodule", NULL, 33);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&eventsManager);
	ZVAL_NULL(&eventsManager);
	ZEPHIR_INIT_VAR(&response);
	ZVAL_NULL(&response);
	ZEPHIR_INIT_VAR(&params);
	zephir_get_args(&params);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_2);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_4$$4);
		zephir_create_array(&_4$$4, 2, 0);
		ZEPHIR_OBS_VAR(&_5$$4);
		zephir_read_property(&_5$$4, this_ptr, ZEND_STRL("defaultModule"), PH_NOISY_CC);
		zephir_array_fast_append(&_4$$4, &_5$$4);
		zephir_array_fast_append(&_4$$4, &params);
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "superapp:beforeExecModule");
		ZEPHIR_CALL_METHOD(&_3$$4, &eventsManager, "fire", NULL, 0, &_6$$4, this_ptr, &_4$$4);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_3$$4)) {
		}
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("defaultModule"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&response, &_2, "exec", NULL, 0, &params);
	zephir_check_call_status();
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_8$$5);
		zephir_create_array(&_8$$5, 2, 0);
		ZEPHIR_OBS_VAR(&_9$$5);
		zephir_read_property(&_9$$5, this_ptr, ZEND_STRL("defaultModule"), PH_NOISY_CC);
		zephir_array_fast_append(&_8$$5, &_9$$5);
		zephir_array_fast_append(&_8$$5, &response);
		ZEPHIR_INIT_VAR(&_10$$5);
		ZVAL_STRING(&_10$$5, "superapp:afterExecModule");
		ZEPHIR_CALL_METHOD(&_7$$5, &eventsManager, "fire", NULL, 0, &_10$$5, this_ptr, &_8$$5);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_7$$5)) {
		}
	}
	RETURN_CCTOR(&response);
}

PHP_METHOD(PhalconPlus_App_App, terminate)
{
	zend_class_entry *_8$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *deeply_param = NULL, _SESSION, _POST, _GET, _SERVER, _REQUEST, _COOKIE, _FILES, __$null, __$true, __$false, _0, _1, _3, finalizer, _4, *_5, _6, _7, _2$$4;
	zend_bool deeply;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SESSION);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_REQUEST);
	ZVAL_UNDEF(&_COOKIE);
	ZVAL_UNDEF(&_FILES);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&finalizer);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(deeply)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_get_global(&_GET, SL("_GET"));
	zephir_get_global(&_POST, SL("_POST"));
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 0, 1, &deeply_param);
	if (!deeply_param) {
		deeply = 1;
	} else {
		deeply = zephir_get_boolval(deeply_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "session_status", NULL, 42);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_0, 2)) {
		ZEPHIR_CALL_FUNCTION(NULL, "session_write_close", NULL, 43);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&_1, "headers_sent", NULL, 44);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "");
		ZEPHIR_CALL_FUNCTION(NULL, "session_id", NULL, 45, &_2$$4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_SESSION);
	array_init(&_SESSION);
	ZEPHIR_INIT_NVAR(&_POST);
	array_init(&_POST);
	ZEPHIR_INIT_NVAR(&_GET);
	array_init(&_GET);
	ZEPHIR_INIT_NVAR(&_SERVER);
	array_init(&_SERVER);
	ZEPHIR_INIT_NVAR(&_REQUEST);
	array_init(&_REQUEST);
	ZEPHIR_INIT_NVAR(&_COOKIE);
	array_init(&_COOKIE);
	ZEPHIR_INIT_NVAR(&_FILES);
	array_init(&_FILES);
	ZEPHIR_INIT_VAR(&_3);
	array_init(&_3);
	zephir_update_property_zval(this_ptr, ZEND_STRL("modules"), &_3);
	zephir_update_property_zval(this_ptr, ZEND_STRL("defaultModule"), &__$null);
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("booted"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("booted"), &__$false);
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("finalizers"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_4, 0, "phalconplus/App/App.zep", 220);
	if (Z_TYPE_P(&_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_4), _5)
		{
			ZEPHIR_INIT_NVAR(&finalizer);
			ZVAL_COPY(&finalizer, _5);
			ZEPHIR_CALL_ZVAL_FUNCTION(NULL, &finalizer, NULL, 0);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_4, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &_4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&finalizer, &_4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_ZVAL_FUNCTION(NULL, &finalizer, NULL, 0);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &_4, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&finalizer);
	ZEPHIR_INIT_VAR(&_7);
	array_init(&_7);
	zephir_update_property_zval(this_ptr, ZEND_STRL("finalizers"), &_7);
	if (deeply == 1) {
		_8$$7 = zephir_fetch_class_str_ex(SL("Phalcon\\Di\\Di"), ZEND_FETCH_CLASS_AUTO);
		ZEPHIR_CALL_CE_STATIC(NULL, _8$$7, "reset", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, ZEND_STRL("container"), &__$null);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(PhalconPlus_App_App, defer)
{
	zval *handler, handler_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handler_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &handler);


	zephir_update_property_array_append(this_ptr, SL("finalizers"), handler);
	RETURN_THISW();
}

PHP_METHOD(PhalconPlus_App_App, getRequestNumber)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "requestNumber");
}

PHP_METHOD(PhalconPlus_App_App, getDefaultModuleDef)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultModule"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "def", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(PhalconPlus_App_App, getPrimaryModuleDef)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultModule"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "def", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(PhalconPlus_App_App, setDefaultModule)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *defaultModule_param = NULL;
	zval defaultModule;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultModule);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(defaultModule)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaultModule_param);
	zephir_get_strval(&defaultModule, defaultModule_param);


	RETURN_THIS();
}

PHP_METHOD(PhalconPlus_App_App, getDefaultModule)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultModule"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getname", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(PhalconPlus_App_App, getPrimaryModule)
{
	zval name, _0, _1, _4, _5, _2$$3, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("defaultModule"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&name, &_0, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_1, &name))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "Module not exists: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 2, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalconplus/App/App.zep", 264);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, &name, PH_NOISY | PH_READONLY, "phalconplus/App/App.zep", 266);
	RETURN_CTOR(&_5);
}

PHP_METHOD(PhalconPlus_App_App, getModule)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _3, _4, _1$$4;
	zval name, _2$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(&name, "")) {
		RETURN_MM_MEMBER(getThis(), "defaultModule");
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "Module not exists: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 2, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalconplus/App/App.zep", 275);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &name, PH_NOISY | PH_READONLY, "phalconplus/App/App.zep", 277);
	RETURN_CTOR(&_4);
}

PHP_METHOD(PhalconPlus_App_App, getModuleDef)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0$$3, _1, _4, _5, _2$$4;
	zval name, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_2$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &name_param);
	if (!name_param) {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_STRING(&name, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(&name, "")) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("defaultModule"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_0$$3, "def", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_1, &name))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CONCAT_SV(&_3$$4, "Module not exists: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 2, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalconplus/App/App.zep", 286);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("modules"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, &name, PH_NOISY | PH_READONLY, "phalconplus/App/App.zep", 288);
	ZEPHIR_RETURN_CALL_METHOD(&_5, "def", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(PhalconPlus_App_App, config)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "config");
}

PHP_METHOD(PhalconPlus_App_App, di)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "container");
}

PHP_METHOD(PhalconPlus_App_App, __call)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval *method_param = NULL, *params_param = NULL, dependencyInjector, _0, _1, _2;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&params);
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


	ZEPHIR_INIT_VAR(&dependencyInjector);
	ZVAL_NULL(&dependencyInjector);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isbooted", NULL, 46);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("container"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dependencyInjector, &_1);
	ZEPHIR_CALL_METHOD(&_2, &dependencyInjector, "has", NULL, 0, &method);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_RETURN_CALL_METHOD(&dependencyInjector, "get", NULL, 0, &method, &params);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_NULL();
}

zend_object *zephir_init_properties_PhalconPlus_App_App(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("finalizers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("finalizers"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

