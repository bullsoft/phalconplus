
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
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
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

	zend_declare_property_null(phalconplus_app_app_ce, SL("bootstrap"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_app_app_ce, SL("config"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_app_app_ce, SL("driver"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalconplus_app_app_ce, SL("autoHandle"), 1, ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_App_App, getBootstrap) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "bootstrap");

}

PHP_METHOD(PhalconPlus_App_App, getConfig) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "config");

}

PHP_METHOD(PhalconPlus_App_App, getDriver) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "driver");

}

PHP_METHOD(PhalconPlus_App_App, setDriver) {

	zval *driver, driver_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&driver_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &driver);



	zephir_update_property_zval(this_ptr, SL("driver"), driver);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_App_App, setAutoHandle) {

	zval *autoHandle, autoHandle_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&autoHandle_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &autoHandle);



	zephir_update_property_zval(this_ptr, SL("autoHandle"), autoHandle);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_App_App, getAutoHandle) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "autoHandle");

}

PHP_METHOD(PhalconPlus_App_App, __construct) {

	zval *boot, boot_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&boot_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &boot);



	zephir_update_property_zval(this_ptr, SL("bootstrap"), boot);

}

PHP_METHOD(PhalconPlus_App_App, boot) {

	zend_bool _6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL, *_14 = NULL, *_17 = NULL, *_19 = NULL, *_22 = NULL, *_24 = NULL, *_26 = NULL, *_35 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval env;
	zval *config, config_sub, *env_param = NULL, __$false, __$true, sysEnv$$3, _0$$3, _1$$3, _2, _3, _4, _5, _7, _9, _12, _13, _15, _16, _18, _20, _21, _23, _25, primaryModuleDef, _27, _28, _29, _30, _31, _32, _33, _34, _10$$6, _11$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&sysEnv$$3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&primaryModuleDef);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&env);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &config, &env_param);

	if (!env_param) {
		ZEPHIR_INIT_VAR(&env);
		ZVAL_STRING(&env, "");
	} else {
		zephir_get_strval(&env, env_param);
	}


	if (EXPECTED(ZEPHIR_IS_EMPTY(&env))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "phalconplus.env");
		ZEPHIR_CALL_FUNCTION(&_1$$3, "get_cfg_var", NULL, 28, &_0$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&sysEnv$$3);
		zephir_fast_trim(&sysEnv$$3, &_1$$3, NULL , ZEPHIR_TRIM_BOTH);
		if (!(ZEPHIR_IS_EMPTY(&sysEnv$$3))) {
			zephir_update_property_zval(this_ptr, SL("env"), &sysEnv$$3);
		}
	} else {
		zephir_update_property_zval(this_ptr, SL("env"), &env);
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_GET_CONSTANT(&_2, "PHP_SAPI");
	ZVAL_LONG(&_3, 0);
	ZVAL_LONG(&_4, 3);
	ZEPHIR_INIT_VAR(&_5);
	zephir_substr(&_5, &_2, 0 , 3 , 0);
	_6 = !ZEPHIR_IS_STRING(&_5, "cli");
	if (_6) {
		zephir_read_property(&_9, this_ptr, SL("env"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_CE_STATIC(&_7, phalconplus_enum_runenv_ce, "isinprod", &_8, 0, &_9);
		zephir_check_call_status();
		_6 = !zephir_is_true(&_7);
	}
	if (_6) {
		ZEPHIR_INIT_VAR(&_10$$6);
		object_init_ex(&_10$$6, zephir_get_internal_ce(SL("phalcon\\debug")));
		if (zephir_has_constructor(&_10$$6)) {
			ZEPHIR_CALL_METHOD(NULL, &_10$$6, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, SL("debug"), &_10$$6);
		zephir_read_property(&_11$$6, this_ptr, SL("debug"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_11$$6, "listen", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("config"), config);
	zephir_read_property(&_12, this_ptr, SL("env"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "APP_ENV");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 29, &_13, &_12, &__$false);
	zephir_check_call_status();
	zephir_read_property(&_15, this_ptr, SL("env"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "APP_RUN_ENV");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 29, &_13, &_15, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_16, phalconplus_enum_sys_ce, "getrootdir", &_17, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "APP_ROOT_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 29, &_13, &_16, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_18, phalconplus_enum_sys_ce, "getprimarymoduledir", &_19, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "APP_MODULE_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 29, &_13, &_18, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_20, phalconplus_enum_sys_ce, "getprimarymoduledir", &_19, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "APP_PRI_MODULE_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 29, &_13, &_20, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_21, phalconplus_enum_sys_ce, "getcommondir", &_22, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "APP_ROOT_COMMON_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 29, &_13, &_21, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_23, phalconplus_enum_sys_ce, "getgloballoaddir", &_24, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 29, &_13, &_23, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_25, phalconplus_enum_sys_ce, "getglobalconfigdir", &_26, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "APP_ROOT_COMMON_CONF_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 29, &_13, &_25, &__$false);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&primaryModuleDef);
	object_init_ex(&primaryModuleDef, phalconplus_app_module_moduledef_ce);
	ZEPHIR_CALL_CE_STATIC(&_27, phalconplus_enum_sys_ce, "getprimarymoduledir", &_19, 0);
	zephir_check_call_status();
	ZVAL_BOOL(&_28, 1);
	ZEPHIR_CALL_METHOD(NULL, &primaryModuleDef, "__construct", NULL, 30, this_ptr, &_27, &_28);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_29, &primaryModuleDef, "getrunmode", NULL, 31);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_30, &_29, "newdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setdi", NULL, 0, &_30);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_31, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_28, this_ptr, SL("bootstrap"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "bootstrap");
	ZEPHIR_CALL_METHOD(NULL, &_31, "setshared", NULL, 0, &_13, &_28);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_32, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "superapp");
	ZEPHIR_CALL_METHOD(NULL, &_32, "setshared", NULL, 0, &_13, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_33, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_34, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "config");
	ZEPHIR_CALL_METHOD(NULL, &_33, "setshared", NULL, 0, &_13, &_34);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "\\Ph\\");
	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_enum_facade_ce, "register", &_35, 0, this_ptr, &_13);
	zephir_check_call_status();
	if (1) {
		zephir_update_property_zval(this_ptr, SL("booted"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("booted"), &__$false);
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registermodule", NULL, 32, &primaryModuleDef);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_App_App, registerModule) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *moduleDef, moduleDef_sub, __$false, _0, _1, _5, _10, _14, module, _23, _24, _25, _2$$3, _3$$3, _4$$3, _6$$4, _7$$4, _8$$4, _11$$5, _12$$5, _13$$5, _15$$6, _16$$6, moduleConf$$6, _19$$6, _20$$6, _21$$6, _22$$6, _17$$7, _18$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleDef_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
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
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$6);
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
		zephir_array_fetch(&_3$$3, &_2$$3, &_4$$3, PH_NOISY | PH_READONLY, "phalconplus/App/App.zep", 100);
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
		zephir_throw_exception_debug(&_6$$4, "phalconplus/App/App.zep", 103);
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
		zephir_throw_exception_debug(&_11$$5, "phalconplus/App/App.zep", 106);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_14, moduleDef, "isprimary", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_14)) {
		ZEPHIR_INIT_VAR(&_15$$6);
		ZVAL_STRING(&_15$$6, "APP_RUN_MODE");
		ZEPHIR_CALL_FUNCTION(&_16$$6, "defined", NULL, 33, &_15$$6);
		zephir_check_call_status();
		if (!(zephir_is_true(&_16$$6))) {
			ZEPHIR_CALL_METHOD(&_17$$7, moduleDef, "getmode", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_18$$7);
			ZVAL_STRING(&_18$$7, "APP_RUN_MODE");
			ZEPHIR_CALL_FUNCTION(NULL, "define", NULL, 29, &_18$$7, &_17$$7, &__$false);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(&moduleConf$$6, moduleDef, "getconfig", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_19$$6, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_19$$6, "merge", NULL, 0, &moduleConf$$6);
		zephir_check_call_status();
		zephir_read_property(&_20$$6, this_ptr, SL("bootstrap"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_21$$6, moduleDef, "getrunmode", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_22$$6, &_21$$6, "getscriptpath", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_20$$6, "load", NULL, 0, &_22$$6);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_23, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&module, moduleDef, "impl", NULL, 0, &_23);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_24, moduleDef, "isprimary", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_24)) {
		zephir_update_property_zval(this_ptr, SL("_defaultModule"), &module);
	}
	ZEPHIR_CALL_METHOD(NULL, &module, "registerautoloaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &module, "registerservices", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &module, "registerevents", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_25, moduleDef, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("_modules"), &_25, &module);
	RETURN_CCTOR(&module);

}

PHP_METHOD(PhalconPlus_App_App, dependModule) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *moduleName_param = NULL, module, moduleDef, moduleDir, moduleConf, _1, _2, _3, _4;
	zval moduleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&moduleDef);
	ZVAL_UNDEF(&moduleDir);
	ZVAL_UNDEF(&moduleConf);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

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
	ZEPHIR_CALL_METHOD(NULL, &moduleDef, "__construct", NULL, 30, this_ptr, &moduleDir);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&module, this_ptr, "registermodule", NULL, 32, &moduleDef);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&moduleConf);
	object_init_ex(&moduleConf, zephir_get_internal_ce(SL("phalcon\\config")));
	zephir_read_property(&_1, this_ptr, SL("bootstrap"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, &moduleDef, "getconfigpath", NULL, 34);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_1, "load", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &moduleConf, "__construct", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &moduleConf, "merge", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setconfig", NULL, 35, &moduleConf);
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

	zval _12, _3$$3;
	zend_class_entry *_8;
	zval driverClass, eventsManager, driverName, _0, params, _1, _6, _7, _13, _14, _2$$3, _4$$3, _5$$3, _9$$4, _10$$4, _11$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&driverClass);
	ZVAL_UNDEF(&eventsManager);
	ZVAL_UNDEF(&driverName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_defaultModule"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&driverName, &_0, "getmapclassname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&driverClass);
	ZEPHIR_CONCAT_SV(&driverClass, "\\PhalconPlus\\App\\Driver\\", &driverName);
	ZEPHIR_INIT_VAR(&params);
	zephir_get_args(&params);
	zephir_read_property(&_1, this_ptr, SL("_eventsManager"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&eventsManager, &_1);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		ZEPHIR_INIT_VAR(&_3$$3);
		zephir_create_array(&_3$$3, 3, 0);
		zephir_array_fast_append(&_3$$3, &driverClass);
		zephir_array_fast_append(&_3$$3, &params);
		ZEPHIR_OBS_VAR(&_4$$3);
		zephir_read_property(&_4$$3, this_ptr, SL("autoHandle"), PH_NOISY_CC);
		zephir_array_fast_append(&_3$$3, &_4$$3);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZVAL_STRING(&_5$$3, "superapp:beforeStartDriver");
		ZEPHIR_CALL_METHOD(&_2$$3, &eventsManager, "fire", NULL, 0, &_5$$3, this_ptr, &_3$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_2$$3)) {
		}
	}
	ZEPHIR_INIT_VAR(&_6);
	zephir_fetch_safe_class(&_7, &driverClass);
	_8 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_7), Z_STRLEN_P(&_7), ZEND_FETCH_CLASS_AUTO);
	if(!_8) {
		RETURN_MM_NULL();
	}
	object_init_ex(&_6, _8);
	if (zephir_has_constructor(&_6)) {
		zephir_read_property(&_1, this_ptr, SL("autoHandle"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", NULL, 0, this_ptr, &_1);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("driver"), &_6);
	if (Z_TYPE_P(&eventsManager) == IS_OBJECT) {
		zephir_read_property(&_10$$4, this_ptr, SL("driver"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_11$$4);
		ZVAL_STRING(&_11$$4, "superapp:afterStartDriver");
		ZEPHIR_CALL_METHOD(&_9$$4, &eventsManager, "fire", NULL, 0, &_11$$4, this_ptr, &_10$$4);
		zephir_check_call_status();
		if (ZEPHIR_IS_FALSE_IDENTICAL(&_9$$4)) {
		}
	}
	ZEPHIR_INIT_VAR(&_12);
	zephir_create_array(&_12, 2, 0);
	ZEPHIR_OBS_VAR(&_13);
	zephir_read_property(&_13, this_ptr, SL("driver"), PH_NOISY_CC);
	zephir_array_fast_append(&_12, &_13);
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "exec");
	zephir_array_fast_append(&_12, &_14);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_12, &params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_App, terminate) {

	zend_class_entry *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$null, __$true, __$false, _0;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("_modules"), &_0);
	zephir_update_property_zval(this_ptr, SL("_defaultModule"), &__$null);
	zephir_update_property_zval(this_ptr, SL("config"), &__$null);
	if (0) {
		zephir_update_property_zval(this_ptr, SL("booted"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("booted"), &__$false);
	}
	zephir_update_property_zval(this_ptr, SL("driver"), &__$null);
	zephir_update_property_zval(this_ptr, SL("bootstrap"), &__$null);
	zephir_update_property_zval(this_ptr, SL("_dependencyInjector"), &__$null);
	_1 = zephir_fetch_class_str_ex(SL("Phalcon\\Di"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_CALL_CE_STATIC(NULL, _1, "reset", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_App_App, getDefaultModuleDef) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("_defaultModule"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getdef", NULL, 0);
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
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getdef", NULL, 0);
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
		zephir_throw_exception_debug(&_2$$3, "phalconplus/App/App.zep", 252);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("_modules"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, &name, PH_NOISY | PH_READONLY, "phalconplus/App/App.zep", 254);
	RETURN_CTOR(&_5);

}

PHP_METHOD(PhalconPlus_App_App, getModule) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _3, _4, _1$$3;
	zval name, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

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


	zephir_read_property(&_0, this_ptr, SL("_modules"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Module not exists: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 2, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/App/App.zep", 260);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("_modules"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &name, PH_NOISY | PH_READONLY, "phalconplus/App/App.zep", 262);
	RETURN_CTOR(&_4);

}

PHP_METHOD(PhalconPlus_App_App, getModuleDef) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, _0, _3, _4, _1$$3;
	zval name, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &name_param);

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


	zephir_read_property(&_0, this_ptr, SL("_modules"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Module not exists: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 2, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/App/App.zep", 268);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("_modules"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &name, PH_NOISY | PH_READONLY, "phalconplus/App/App.zep", 270);
	ZEPHIR_RETURN_CALL_METHOD(&_4, "getdef", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

