
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


ZEPHIR_INIT_CLASS(PhalconPlus_App_App) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\App, App, phalconplus, app_app, zephir_get_internal_ce(SL("phalcon\\application")), phalconplus_app_app_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalconplus_app_app_ce, SL("debug"), ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalconplus_app_app_ce, SL("env"), "dev", ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalconplus_app_app_ce, SL("booted"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_app_app_ce, SL("config"), ZEND_ACC_PROTECTED);

	zend_declare_property_long(phalconplus_app_app_ce, SL("requestNumber"), 0, ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_App_App, getConfig) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "config");

}

PHP_METHOD(PhalconPlus_App_App, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *config, config_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	zephir_update_property_zval(this_ptr, SL("config"), config);
	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_enum_sys_ce, "initapp", &_0, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_App_App, boot) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_7 = NULL, *_9 = NULL, *_12 = NULL, *_14 = NULL, *_16 = NULL, *_17 = NULL;
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
		ZEPHIR_CALL_FUNCTION(&_1$$3, "get_cfg_var", NULL, 32, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&sysEnv$$3);
		zephir_fast_trim(&sysEnv$$3, &_1$$3, NULL , ZEPHIR_TRIM_BOTH);
		if (!(ZEPHIR_IS_EMPTY(&sysEnv$$3))) {
			zephir_update_property_zval(this_ptr, SL("env"), &sysEnv$$3);
		}
	} else {
		zephir_update_property_zval(this_ptr, SL("env"), &env);
	}
	zephir_read_property(&_2, this_ptr, SL("env"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "APP_ENV");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_4, 33, &_3, &_2, &__$false);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("env"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "APP_RUN_ENV");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_4, 33, &_3, &_5, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_6, phalconplus_enum_sys_ce, "getrootdir", &_7, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "APP_ROOT_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_4, 33, &_3, &_6, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_8, phalconplus_enum_sys_ce, "getprimarymoduledir", &_9, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "APP_MODULE_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_4, 33, &_3, &_8, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_10, phalconplus_enum_sys_ce, "getprimarymoduledir", &_9, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "APP_PRI_MODULE_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_4, 33, &_3, &_10, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_11, phalconplus_enum_sys_ce, "getcommondir", &_12, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "APP_ROOT_COMMON_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_4, 33, &_3, &_11, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_13, phalconplus_enum_sys_ce, "getgloballoaddir", &_14, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_4, 33, &_3, &_13, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_15, phalconplus_enum_sys_ce, "getglobalconfigdir", &_16, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "APP_ROOT_COMMON_CONF_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_4, 33, &_3, &_15, &__$false);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "\\Ph\\");
	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_enum_facade_ce, "register", &_17, 0, this_ptr, &_3);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "bootprimarymodule", NULL, 34, &runMode);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_App, bootPrimaryModule) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL, *_12 = NULL;
	zval *runMode_param = NULL, __$true, __$false, primaryModuleDef, _0, _2, module, _10, _3$$3, _4$$3, _5$$3, _6$$3, _7$$3, _8$$3, _9$$3, _11$$4, _13$$4, _14$$5, _15$$5;
	zval runMode;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&runMode);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&primaryModuleDef);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);

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
	ZEPHIR_CALL_METHOD(NULL, &primaryModuleDef, "__construct", NULL, 35, this_ptr, &_0, &_2, &runMode);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_2) == IS_NULL) {
		ZEPHIR_CALL_METHOD(&_3$$3, &primaryModuleDef, "newdi", NULL, 36);
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
		zephir_read_property(&_7$$3, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "config");
		ZEPHIR_CALL_METHOD(NULL, &_6$$3, "setshared", NULL, 0, &_5$$3, &_7$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_8$$3, this_ptr, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_5$$3);
		object_init_ex(&_5$$3, zephir_get_internal_ce(SL("phalcon\\loader")));
		if (zephir_has_constructor(&_5$$3)) {
			ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_INIT_VAR(&_9$$3);
		ZVAL_STRING(&_9$$3, "loader");
		ZEPHIR_CALL_METHOD(NULL, &_8$$3, "setshared", NULL, 0, &_9$$3, &_5$$3);
		zephir_check_call_status();
	}
	if (1) {
		zephir_update_property_zval(this_ptr, SL("booted"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("booted"), &__$false);
	}
	ZEPHIR_CALL_METHOD(&module, this_ptr, "registermodule", NULL, 37, &primaryModuleDef);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, &module, "isweb", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_10)) {
		zephir_read_property(&_13$$4, this_ptr, SL("env"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_CE_STATIC(&_11$$4, phalconplus_enum_runenv_ce, "isinprod", &_12, 0, &_13$$4);
		zephir_check_call_status();
		if (!(zephir_is_true(&_11$$4))) {
			ZEPHIR_INIT_VAR(&_14$$5);
			object_init_ex(&_14$$5, zephir_get_internal_ce(SL("phalcon\\debug")));
			if (zephir_has_constructor(&_14$$5)) {
				ZEPHIR_CALL_METHOD(NULL, &_14$$5, "__construct", NULL, 0);
				zephir_check_call_status();
			}
			zephir_update_property_zval(this_ptr, SL("debug"), &_14$$5);
			zephir_read_property(&_15$$5, this_ptr, SL("debug"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_15$$5, "listen", NULL, 0);
			zephir_check_call_status();
		}
	}
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_App_App, registerModule) {

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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleDef);



	zephir_read_property(&_0, this_ptr, SL("_modules"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, moduleDef, "getname", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_array_isset(&_0, &_1))) {
		zephir_read_property(&_2$$3, this_ptr, SL("_modules"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$3, moduleDef, "getname", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch(&_3$$3, &_2$$3, &_4$$3, PH_NOISY | PH_READONLY, "phalconplus/App/App.zep", 91);
		RETURN_CTOR(&_3$$3);
	}
	zephir_read_property(&_5, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(Z_TYPE_P(&_5) == IS_NULL)) {
		ZEPHIR_INIT_VAR(&_6$$4);
		object_init_ex(&_6$$4, phalconplus_base_exception_ce);
		ZEPHIR_CALL_METHOD(&_7$$4, moduleDef, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$4);
		ZEPHIR_CONCAT_SV(&_8$$4, "DI doesn't load yet, failed to register module ", &_7$$4);
		ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", &_9, 2, &_8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$4, "phalconplus/App/App.zep", 94);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_10, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(Z_TYPE_P(&_10) == IS_NULL)) {
		ZEPHIR_INIT_VAR(&_11$$5);
		object_init_ex(&_11$$5, phalconplus_base_exception_ce);
		ZEPHIR_CALL_METHOD(&_12$$5, moduleDef, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_13$$5);
		ZEPHIR_CONCAT_SV(&_13$$5, "Config doesn't initial yet, failed to register module ", &_12$$5);
		ZEPHIR_CALL_METHOD(NULL, &_11$$5, "__construct", &_9, 2, &_13$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$5, "phalconplus/App/App.zep", 97);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_14, moduleDef, "isprimary", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_14)) {
		ZEPHIR_INIT_VAR(&_15$$6);
		ZVAL_STRING(&_15$$6, "APP_RUN_MODE");
		ZEPHIR_CALL_FUNCTION(&_16$$6, "defined", NULL, 38, &_15$$6);
		zephir_check_call_status();
		if (!(zephir_is_true(&_16$$6))) {
			ZEPHIR_CALL_METHOD(&_17$$7, moduleDef, "getmode", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_18$$7);
			ZVAL_STRING(&_18$$7, "APP_RUN_MODE");
			ZEPHIR_CALL_FUNCTION(NULL, "define", NULL, 33, &_18$$7, &_17$$7, &__$false);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&moduleConf$$6, moduleDef, "getconfig", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_19$$6, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_19$$6, "merge", NULL, 0, &moduleConf$$6);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&module, moduleDef, "checkout", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_20, &module, "isprimary", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_20)) {
		zephir_update_property_zval(this_ptr, SL("_defaultModule"), &module);
	}
	ZEPHIR_CALL_METHOD(&_21, moduleDef, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_modules"), &_21, &module);
	RETURN_CCTOR(&module);

}

PHP_METHOD(PhalconPlus_App_App, dependModule) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL;
	zval *moduleName_param = NULL, module, moduleDef, moduleDir, moduleConf, tmp, _2, _3;
	zval moduleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&moduleDef);
	ZVAL_UNDEF(&moduleDir);
	ZVAL_UNDEF(&moduleConf);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

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
		ZVAL_EMPTY_STRING(&moduleName);
	}


	ZEPHIR_CALL_CE_STATIC(&moduleDir, phalconplus_enum_sys_ce, "getmoduledirbyname", &_0, 0, &moduleName);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&moduleDef);
	object_init_ex(&moduleDef, phalconplus_app_module_moduledef_ce);
	ZEPHIR_CALL_METHOD(NULL, &moduleDef, "__construct", NULL, 35, this_ptr, &moduleDir);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&module, this_ptr, "registermodule", NULL, 37, &moduleDef);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &moduleDef, "getconfigpath", NULL, 39);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&tmp, phalconplus_enum_sys_ce, "load", &_1, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&moduleConf);
	object_init_ex(&moduleConf, zephir_get_internal_ce(SL("phalcon\\config")));
	ZEPHIR_CALL_METHOD(NULL, &moduleConf, "__construct", NULL, 0, &tmp);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &moduleConf, "merge", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setconfig", NULL, 40, &moduleConf);
	zephir_check_call_status();
	RETURN_CCTOR(&module);

}

PHP_METHOD(PhalconPlus_App_App, setConfig) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, config_sub, _0, _2, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	zephir_read_property(&_0, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zephir_get_internal_ce(SL("phalcon\\config")));
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("config"), &_1$$3);
	}
	zephir_read_property(&_2, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "merge", NULL, 0, config);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_App_App, isDebug) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("debug"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(Z_TYPE_P(&_0) != IS_NULL);

}

PHP_METHOD(PhalconPlus_App_App, isBooted) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("booted"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_IS_TRUE_IDENTICAL(&_0));

}

PHP_METHOD(PhalconPlus_App_App, getDebug) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "debug");

}

PHP_METHOD(PhalconPlus_App_App, getEnv) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "env");

}

PHP_METHOD(PhalconPlus_App_App, setEnv) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *env_param = NULL;
	zval env;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&env);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &env_param);

	zephir_get_strval(&env, env_param);


	zephir_update_property_zval(this_ptr, SL("env"), &env);
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_App_App, handle) {

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

	zephir_read_property(&_0, this_ptr, SL("requestNumber"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, (zephir_get_numberval(&_0) + 1));
	zephir_update_property_zval(this_ptr, SL("requestNumber"), &_1);
	zephir_read_property(&_1, this_ptr, SL("booted"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_FALSE(&_1)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "bootprimarymodule", NULL, 34);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&params);
	zephir_get_args(&params);
	zephir_read_property(&_2, this_ptr, SL("_eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_2);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_4$$4);
		zephir_create_array(&_4$$4, 2, 0);
		ZEPHIR_OBS_VAR(&_5$$4);
		zephir_read_property(&_5$$4, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
		zephir_array_fast_append(&_4$$4, &_5$$4);
		zephir_array_fast_append(&_4$$4, &params);
		ZEPHIR_INIT_VAR(&_6$$4);
		ZVAL_STRING(&_6$$4, "superapp:beforeExecModule");
		ZEPHIR_CALL_METHOD(&_3$$4, &eventsManager, "fire", NULL, 0, &_6$$4, this_ptr, &_4$$4);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_3$$4)) {
		}
	}
	zephir_read_property(&_2, this_ptr, SL("_defaultModule"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&response, &_2, "exec", NULL, 0, &params);
	zephir_check_call_status();
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_8$$5);
		zephir_create_array(&_8$$5, 2, 0);
		ZEPHIR_OBS_VAR(&_9$$5);
		zephir_read_property(&_9$$5, this_ptr, SL("_defaultModule"), PH_NOISY_CC);
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

PHP_METHOD(PhalconPlus_App_App, terminate) {

	zend_class_entry *_4$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *deep_param = NULL, _SESSION, _POST, _GET, _SERVER, _REQUEST, _COOKIE, _FILES, __$null, __$true, __$false, _0, _1, _3, _2$$4;
	zend_bool deep;
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
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_get_global(&_GET, SL("_GET"));
	zephir_get_global(&_POST, SL("_POST"));
	zephir_get_global(&_SESSION, SL("_SESSION"));
	zephir_fetch_params(1, 0, 1, &deep_param);

	if (!deep_param) {
		deep = 1;
	} else {
		deep = zephir_get_boolval(deep_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "session_status", NULL, 41);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_0, 2)) {
		ZEPHIR_CALL_FUNCTION(NULL, "session_write_close", NULL, 42);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&_1, "headers_sent", NULL, 43);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "");
		ZEPHIR_CALL_FUNCTION(NULL, "session_id", NULL, 44, &_2$$4);
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
	zephir_update_property_zval(this_ptr, SL("_modules"), &_3);
	zephir_update_property_zval(this_ptr, SL("_defaultModule"), &__$null);
	if (0) {
		zephir_update_property_zval(this_ptr, SL("booted"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("booted"), &__$false);
	}
	if (deep == 1) {
		_4$$5 = zephir_fetch_class_str_ex(SL("Phalcon\\Di"), ZEND_FETCH_CLASS_AUTO);
		ZEPHIR_CALL_CE_STATIC(NULL, _4$$5, "reset", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), &__$null);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_App_App, getRequestNumber) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "requestNumber");

}

PHP_METHOD(PhalconPlus_App_App, getDefaultModuleDef) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_defaultModule"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "def", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_App, getPrimaryModuleDef) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_defaultModule"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "def", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_App, setDefaultModule) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *defaultModule_param = NULL;
	zval defaultModule;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&defaultModule);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &defaultModule_param);

	zephir_get_strval(&defaultModule, defaultModule_param);


	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_App_App, getDefaultModule) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_defaultModule"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getname", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_App, getPrimaryModule) {

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

	zephir_read_property(&_0, this_ptr, SL("_defaultModule"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&name, &_0, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("_modules"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_1, &name))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "Module not exists: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 2, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalconplus/App/App.zep", 255);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("_modules"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, &name, PH_NOISY | PH_READONLY, "phalconplus/App/App.zep", 257);
	RETURN_CTOR(&_5);

}

PHP_METHOD(PhalconPlus_App_App, getModule) {

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
		ZVAL_EMPTY_STRING(&name);
	}
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(&name, "")) {
		RETURN_MM_MEMBER(getThis(), "_defaultModule");
	}
	zephir_read_property(&_0, this_ptr, SL("_modules"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "Module not exists: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 2, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalconplus/App/App.zep", 266);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("_modules"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &name, PH_NOISY | PH_READONLY, "phalconplus/App/App.zep", 268);
	RETURN_CTOR(&_4);

}

PHP_METHOD(PhalconPlus_App_App, getModuleDef) {

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
		ZVAL_EMPTY_STRING(&name);
	}
	}


	if (ZEPHIR_IS_STRING_IDENTICAL(&name, "")) {
		zephir_read_property(&_0$$3, this_ptr, SL("_defaultModule"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_0$$3, "def", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_read_property(&_1, this_ptr, SL("_modules"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_1, &name))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$4);
		ZEPHIR_CONCAT_SV(&_3$$4, "Module not exists: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 2, &_3$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$4, "phalconplus/App/App.zep", 277);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("_modules"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, &name, PH_NOISY | PH_READONLY, "phalconplus/App/App.zep", 279);
	ZEPHIR_RETURN_CALL_METHOD(&_5, "def", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_App, config) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "config");

}

PHP_METHOD(PhalconPlus_App_App, di) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_dependencyInjector");

}

PHP_METHOD(PhalconPlus_App_App, __call) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval *method_param = NULL, *params_param = NULL, dependencyInjector, service, _0, _1, _2;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&dependencyInjector);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &params_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&params, params_param);


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isbooted", NULL, 45);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&dependencyInjector, &_1);
	ZEPHIR_CALL_METHOD(&_2, &dependencyInjector, "has", NULL, 0, &method);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_CALL_METHOD(&service, &dependencyInjector, "get", NULL, 0, &method, &params);
		zephir_check_call_status();
		RETURN_CCTOR(&service);
	}
	RETURN_MM_NULL();

}

