
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/string.h"
#include "kernel/require.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/main.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Bootstrap) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus, Bootstrap, phalconplus, bootstrap, phalconplus_bootstrap_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("application"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("primaryModuleDef"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("activeModules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("debug"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalconplus_bootstrap_ce, SL("env"), "dev", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalconplus_bootstrap_ce, SL("autoHandle"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("loadedFiles"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalconplus_bootstrap_ce->create_object = zephir_init_properties_PhalconPlus_Bootstrap;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Bootstrap, setAutoHandle) {

	zval *autoHandle, autoHandle_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&autoHandle_sub);

	zephir_fetch_params(0, 1, 0, &autoHandle);



	zephir_update_property_zval(this_ptr, SL("autoHandle"), autoHandle);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_Bootstrap, getAutoHandle) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "autoHandle");

}

PHP_METHOD(PhalconPlus_Bootstrap, getLoadedFiles) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "loadedFiles");

}

PHP_METHOD(PhalconPlus_Bootstrap, __construct) {

	zend_bool _7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_9 = NULL, *_15 = NULL, *_18 = NULL, *_20 = NULL, *_23 = NULL, *_25 = NULL, *_27 = NULL, *_29 = NULL;
	zval *moduleDir_param = NULL, *env_param = NULL, __$false, sysEnv$$3, _1$$3, _2$$3, _3, _4, _5, _6, _8, _10, _13, _14, _16, _17, _19, _21, _22, _24, _26, _28, _30, _11$$6, _12$$6, _31$$7;
	zval moduleDir, env;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleDir);
	ZVAL_UNDEF(&env);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&sysEnv$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_31$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &moduleDir_param, &env_param);

	if (UNEXPECTED(Z_TYPE_P(moduleDir_param) != IS_STRING && Z_TYPE_P(moduleDir_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleDir' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(moduleDir_param) == IS_STRING)) {
		zephir_get_strval(&moduleDir, moduleDir_param);
	} else {
		ZEPHIR_INIT_VAR(&moduleDir);
		ZVAL_EMPTY_STRING(&moduleDir);
	}
	if (!env_param) {
		ZEPHIR_INIT_VAR(&env);
		ZVAL_STRING(&env, "");
	} else {
		zephir_get_strval(&env, env_param);
	}


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_enum_sys_ce, "init", &_0, 0, &moduleDir);
	zephir_check_call_status();
	if (EXPECTED(ZEPHIR_IS_EMPTY(&env))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "phalconplus.env");
		ZEPHIR_CALL_FUNCTION(&_2$$3, "get_cfg_var", NULL, 48, &_1$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&sysEnv$$3);
		zephir_fast_trim(&sysEnv$$3, &_2$$3, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
		if (!(ZEPHIR_IS_EMPTY(&sysEnv$$3))) {
			zephir_update_property_zval(this_ptr, SL("env"), &sysEnv$$3);
		}
	} else {
		zephir_update_property_zval(this_ptr, SL("env"), &env);
	}
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_GET_CONSTANT(&_3, "PHP_SAPI");
	ZVAL_LONG(&_4, 0);
	ZVAL_LONG(&_5, 3);
	ZEPHIR_INIT_VAR(&_6);
	zephir_substr(&_6, &_3, 0 , 3 , 0);
	_7 = !ZEPHIR_IS_STRING(&_6, "cli");
	if (_7) {
		zephir_read_property(&_10, this_ptr, SL("env"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_CE_STATIC(&_8, phalconplus_enum_runenv_ce, "isinprod", &_9, 0, &_10);
		zephir_check_call_status();
		_7 = !zephir_is_true(&_8);
	}
	if (_7) {
		ZEPHIR_INIT_VAR(&_11$$6);
		object_init_ex(&_11$$6, zephir_get_internal_ce(SL("phalcon\\debug")));
		if (zephir_has_constructor(&_11$$6 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_11$$6, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, SL("debug"), &_11$$6);
		zephir_read_property(&_12$$6, this_ptr, SL("debug"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_12$$6, "listen", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_13, this_ptr, SL("env"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "APP_ENV");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_15, 49, &_14, &_13, &__$false);
	zephir_check_call_status();
	zephir_read_property(&_16, this_ptr, SL("env"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_14);
	ZVAL_STRING(&_14, "APP_RUN_ENV");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_15, 49, &_14, &_16, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_17, phalconplus_enum_sys_ce, "getrootdir", &_18, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_14);
	ZVAL_STRING(&_14, "APP_ROOT_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_15, 49, &_14, &_17, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_19, phalconplus_enum_sys_ce, "getprimarymoduledir", &_20, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_14);
	ZVAL_STRING(&_14, "APP_MODULE_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_15, 49, &_14, &_19, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_21, phalconplus_enum_sys_ce, "getprimarymoduledir", &_20, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_14);
	ZVAL_STRING(&_14, "APP_PRI_MODULE_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_15, 49, &_14, &_21, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_22, phalconplus_enum_sys_ce, "getcommondir", &_23, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_14);
	ZVAL_STRING(&_14, "APP_ROOT_COMMON_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_15, 49, &_14, &_22, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_24, phalconplus_enum_sys_ce, "getgloballoaddir", &_25, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_14);
	ZVAL_STRING(&_14, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_15, 49, &_14, &_24, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_26, phalconplus_enum_sys_ce, "getglobalconfigdir", &_27, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_14);
	ZVAL_STRING(&_14, "APP_ROOT_COMMON_CONF_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_15, 49, &_14, &_26, &__$false);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_28, phalconplus_enum_sys_ce, "getcomposerautoloadpath", &_29, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_30, "is_file", NULL, 41, &_28);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&_30))) {
		ZEPHIR_CALL_CE_STATIC(&_31$$7, phalconplus_enum_sys_ce, "getcomposerautoloadpath", &_29, 0);
		zephir_check_call_status();
		if (zephir_require_zval(&_31$$7 TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, registerModule) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *moduleDef, moduleDef_sub, _0, _1, _5, module, _9, _10, _2$$3, _3$$3, _4$$3, _6$$4, _7$$4, _8$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleDef_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleDef);



	zephir_read_property(&_0, this_ptr, SL("activeModules"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, moduleDef, "getname", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_array_isset(&_0, &_1))) {
		zephir_read_property(&_2$$3, this_ptr, SL("activeModules"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$3, moduleDef, "getname", NULL, 0);
		zephir_check_call_status();
		zephir_array_fetch(&_3$$3, &_2$$3, &_4$$3, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 74 TSRMLS_CC);
		RETURN_CTOR(&_3$$3);
	}
	zephir_read_property(&_5, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(Z_TYPE_P(&_5) == IS_NULL)) {
		ZEPHIR_INIT_VAR(&_6$$4);
		object_init_ex(&_6$$4, phalconplus_base_exception_ce);
		ZEPHIR_CALL_METHOD(&_7$$4, moduleDef, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$4);
		ZEPHIR_CONCAT_SV(&_8$$4, "DI doesn't load yet, failed to register module ", &_7$$4);
		ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", NULL, 22, &_8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$4, "phalconplus/Bootstrap.zep", 78 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_9, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&module, moduleDef, "impl", NULL, 0, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &module, "registerautoloaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &module, "registerservices", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, moduleDef, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_array(this_ptr, SL("activeModules"), &_10, &module);
	RETURN_CCTOR(&module);

}

PHP_METHOD(PhalconPlus_Bootstrap, initConf) {

	zval __$false, moduleConf, globalConfPath, _1, _8, _14, _15, _2$$3, _3$$3, _4$$3, _6$$4, _7$$4, _9$$5, _10$$5, _11$$5, _12$$5, _13$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_5 = NULL;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&moduleConf);
	ZVAL_UNDEF(&globalConfPath);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&moduleConf);
	ZVAL_NULL(&moduleConf);
	ZEPHIR_CALL_CE_STATIC(&globalConfPath, phalconplus_enum_sys_ce, "getglobalconfigpath", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", NULL, 41, &globalConfPath);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "PHP Notice:  PhalconPlus\\Bootstrap Global config file not exists: ", &globalConfPath);
		ZEPHIR_CALL_FUNCTION(NULL, "error_log", NULL, 50, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, zephir_get_internal_ce(SL("phalcon\\config")));
		ZEPHIR_INIT_VAR(&_4$$3);
		array_init(&_4$$3);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", &_5, 0, &_4$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("config"), &_3$$3);
	} else {
		ZEPHIR_INIT_VAR(&_6$$4);
		object_init_ex(&_6$$4, zephir_get_internal_ce(SL("phalcon\\config")));
		ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "load", NULL, 39, &globalConfPath);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", &_5, 0, &_7$$4);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("config"), &_6$$4);
	}
	zephir_read_property(&_8, this_ptr, SL("primaryModuleDef"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_8)) {
		ZEPHIR_INIT_VAR(&_9$$5);
		object_init_ex(&_9$$5, phalconplus_base_moduledef_ce);
		ZEPHIR_INIT_VAR(&_10$$5);
		ZEPHIR_GET_CONSTANT(&_10$$5, "APP_MODULE_DIR");
		ZVAL_BOOL(&_11$$5, 1);
		ZEPHIR_CALL_METHOD(NULL, &_9$$5, "__construct", NULL, 51, this_ptr, &_10$$5, &_11$$5);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("primaryModuleDef"), &_9$$5);
		zephir_read_property(&_11$$5, this_ptr, SL("primaryModuleDef"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_12$$5, &_11$$5, "getmode", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_13$$5);
		ZVAL_STRING(&_13$$5, "APP_RUN_MODE");
		ZEPHIR_CALL_FUNCTION(NULL, "define", NULL, 49, &_13$$5, &_12$$5, &__$false);
		zephir_check_call_status();
	}
	zephir_read_property(&_14, this_ptr, SL("primaryModuleDef"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&moduleConf, &_14, "getconfig", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_15, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_15, "merge", NULL, 0, &moduleConf);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Bootstrap, setApp) {

	zend_bool autoHandle, _1$$3;
	zval *app, app_sub, *autoHandle_param = NULL, __$true, __$false, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &app, &autoHandle_param);

	if (!autoHandle_param) {
		autoHandle = 0;
	} else {
		autoHandle = zephir_get_boolval(autoHandle_param);
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("application"), PH_NOISY_CC);
	if (EXPECTED(ZEPHIR_IS_EMPTY(&_0))) {
		_1$$3 = (zephir_instance_of_ev(app, zephir_get_internal_ce(SL("phalcon\\application")) TSRMLS_CC));
		if (!(_1$$3)) {
			_1$$3 = (zephir_instance_of_ev(app, zephir_get_internal_ce(SL("yar_server")) TSRMLS_CC));
		}
		if (EXPECTED(_1$$3)) {
			zephir_update_property_zval(this_ptr, SL("application"), app);
			if (autoHandle) {
				zephir_update_property_zval(this_ptr, SL("autoHandle"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("autoHandle"), &__$false);
			}
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Application must be instance of phalcon\\appliction or yar_server", "phalconplus/Bootstrap.zep", 129);
			return;
		}
	}
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Bootstrap, getApp) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("application"), PH_NOISY_CC);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&_0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Sorry, empty application in bootstrap", "phalconplus/Bootstrap.zep", 139);
		return;
	}
	RETURN_MM_MEMBER(getThis(), "application");

}

PHP_METHOD(PhalconPlus_Bootstrap, exec) {

	zval _2;
	zval handleMethod, _0, _1, _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handleMethod);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 52);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&handleMethod);
	ZVAL_STRING(&handleMethod, "exec");
	zephir_read_property(&_0, this_ptr, SL("primaryModuleDef"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getmapclassname", NULL, 0);
	zephir_check_call_status();
	zephir_concat_self(&handleMethod, &_1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	zephir_create_array(&_2, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_2, this_ptr);
	zephir_array_fast_append(&_2, &handleMethod);
	ZEPHIR_INIT_VAR(&_3);
	zephir_get_args(&_3);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_2, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @request a uri string (for \Phalcon\Mvc\Application) or Psr\Http\Message\Request
 */
PHP_METHOD(PhalconPlus_Bootstrap, execModule) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request = NULL, request_sub, __$null, _0, _1, _5, _7, _8, _9, _10, _11, _12, _13, _14, _2$$4, _3$$4, _4$$4, _6$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &request);

	if (!request) {
		request = &request_sub;
		request = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 52);
		zephir_check_call_status();
	}
	zephir_read_property(&_1, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, zephir_get_internal_ce(SL("phalcon\\di\\factorydefault")));
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("di"), &_2$$4);
		zephir_read_property(&_3$$4, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "bootstrap");
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "setshared", NULL, 0, &_4$$4, this_ptr);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&_5);
	zephir_read_property(&_5, this_ptr, SL("application"), PH_NOISY_CC);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&_5))) {
		ZEPHIR_INIT_VAR(&_6$$5);
		object_init_ex(&_6$$5, zephir_get_internal_ce(SL("phalcon\\mvc\\application")));
		ZEPHIR_CALL_METHOD(NULL, &_6$$5, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("application"), &_6$$5);
	}
	zephir_read_property(&_7, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_8, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_7, "setdi", NULL, 0, &_8);
	zephir_check_call_status();
	zephir_read_property(&_9, this_ptr, SL("primaryModuleDef"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_10, &_9, "getrunmode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_11, &_10, "getscriptpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 39, &_11);
	zephir_check_call_status();
	zephir_read_property(&_12, this_ptr, SL("primaryModuleDef"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registermodule", NULL, 53, &_12);
	zephir_check_call_status();
	zephir_read_property(&_13, this_ptr, SL("autoHandle"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_13))) {
		RETURN_THIS();
	}
	zephir_read_property(&_14, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_14, "handle", NULL, 0, request);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Bootstrap, execSrv) {

	zval _0, _1, _5, _6, _7, _8, backendSrv, _9, _10, _11, _17, _19, _20, _2$$4, _3$$4, _4$$4, _12$$5, _13$$5, _14$$7, _15$$7, _16$$7, _18$$8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&backendSrv);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_18$$8);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 52);
		zephir_check_call_status();
	}
	zephir_read_property(&_1, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_1)) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, zephir_get_internal_ce(SL("phalcon\\di\\factorydefault")));
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("di"), &_2$$4);
		zephir_read_property(&_3$$4, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_4$$4);
		ZVAL_STRING(&_4$$4, "bootstrap");
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "setshared", NULL, 0, &_4$$4, this_ptr);
		zephir_check_call_status();
	}
	zephir_read_property(&_5, this_ptr, SL("primaryModuleDef"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_6, &_5, "getrunmode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, &_6, "getscriptpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 39, &_7);
	zephir_check_call_status();
	zephir_read_property(&_8, this_ptr, SL("primaryModuleDef"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registermodule", NULL, 53, &_8);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&backendSrv);
	ZVAL_NULL(&backendSrv);
	zephir_read_property(&_9, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "backendSrv");
	ZEPHIR_CALL_METHOD(&_10, &_9, "has", NULL, 0, &_11);
	zephir_check_call_status();
	if (UNEXPECTED(zephir_is_true(&_10))) {
		zephir_read_property(&_12$$5, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_13$$5);
		ZVAL_STRING(&_13$$5, "backendSrv");
		ZEPHIR_CALL_METHOD(&backendSrv, &_12$$5, "get", NULL, 0, &_13$$5);
		zephir_check_call_status();
		if (!(zephir_instance_of_ev(&backendSrv, phalconplus_rpc_server_abstractserver_ce TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Service object(DI[\"backendSrv\"]) must be type of \\PhalconPlus\\RPC\\Server\\AbstractServer", "phalconplus/Bootstrap.zep", 211);
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&backendSrv);
		object_init_ex(&backendSrv, phalconplus_base_simpleserver_ce);
		zephir_read_property(&_14$$7, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &backendSrv, "__construct", NULL, 54, &_14$$7);
		zephir_check_call_status();
		zephir_read_property(&_15$$7, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_16$$7);
		ZVAL_STRING(&_16$$7, "backendSrv");
		ZEPHIR_CALL_METHOD(NULL, &_15$$7, "set", NULL, 0, &_16$$7, &backendSrv);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&_17);
	zephir_read_property(&_17, this_ptr, SL("application"), PH_NOISY_CC);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&_17))) {
		ZEPHIR_INIT_VAR(&_18$$8);
		object_init_ex(&_18$$8, zephir_get_internal_ce(SL("yar_server")));
		ZEPHIR_CALL_METHOD(NULL, &_18$$8, "__construct", NULL, 0, &backendSrv);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("application"), &_18$$8);
	}
	zephir_read_property(&_19, this_ptr, SL("autoHandle"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_19))) {
		RETURN_THIS();
	}
	zephir_read_property(&_20, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_20, "handle", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Bootstrap, execTask) {

	zend_bool _2$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *argv_param = NULL, *di = NULL, di_sub, __$null, _0, _1, _6, _8, _9, _10, _11, _12, _13, _14, _15, _4$$4, _5$$4, _3$$5, _7$$7;
	zval argv;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&argv);
	ZVAL_UNDEF(&di_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_7$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &argv_param, &di);

	zephir_get_arrval(&argv, argv_param);
	if (!di) {
		di = &di_sub;
		di = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 52);
		zephir_check_call_status();
	}
	zephir_read_property(&_1, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_1)) {
		_2$$4 = Z_TYPE_P(di) == IS_NULL;
		if (!(_2$$4)) {
			_2$$4 = !((zephir_instance_of_ev(di, zephir_get_internal_ce(SL("phalcon\\di\\factorydefault\\cli")) TSRMLS_CC)));
		}
		if (EXPECTED(_2$$4)) {
			ZEPHIR_INIT_VAR(&_3$$5);
			object_init_ex(&_3$$5, zephir_get_internal_ce(SL("phalcon\\di\\factorydefault\\cli")));
			ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("di"), &_3$$5);
		} else {
			zephir_update_property_zval(this_ptr, SL("di"), di);
		}
		zephir_read_property(&_4$$4, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZVAL_STRING(&_5$$4, "bootstrap");
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "setshared", NULL, 0, &_5$$4, this_ptr);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&_6);
	zephir_read_property(&_6, this_ptr, SL("application"), PH_NOISY_CC);
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&_6))) {
		ZEPHIR_INIT_VAR(&_7$$7);
		object_init_ex(&_7$$7, zephir_get_internal_ce(SL("phalcon\\cli\\console")));
		ZEPHIR_CALL_METHOD(NULL, &_7$$7, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("application"), &_7$$7);
	}
	zephir_read_property(&_8, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_9, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_8, "setdi", NULL, 0, &_9);
	zephir_check_call_status();
	zephir_read_property(&_10, this_ptr, SL("primaryModuleDef"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_11, &_10, "getrunmode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_12, &_11, "getscriptpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 39, &_12);
	zephir_check_call_status();
	zephir_read_property(&_13, this_ptr, SL("primaryModuleDef"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registermodule", NULL, 53, &_13);
	zephir_check_call_status();
	zephir_read_property(&_14, this_ptr, SL("autoHandle"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_is_true(&_14))) {
		RETURN_THIS();
	}
	zephir_read_property(&_15, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_15, "handle", NULL, 0, &argv);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Bootstrap, getPrimaryModuleDef) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "primaryModuleDef");

}

PHP_METHOD(PhalconPlus_Bootstrap, getPrimaryModule) {

	zval name, _0, _1, _4, _5, _2$$3, _3$$3;
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

	zephir_read_property(&_0, this_ptr, SL("primaryModuleDef"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&name, &_0, "getname", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("activeModules"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_1, &name))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "Module not exists: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 22, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalconplus/Bootstrap.zep", 269 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("activeModules"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, &name, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 271 TSRMLS_CC);
	RETURN_CTOR(&_5);

}

PHP_METHOD(PhalconPlus_Bootstrap, getModule) {

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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("activeModules"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Module not exists: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 22, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Bootstrap.zep", 277 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("activeModules"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &name, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 279 TSRMLS_CC);
	RETURN_CTOR(&_4);

}

PHP_METHOD(PhalconPlus_Bootstrap, getModuleDef) {

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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}


	zephir_read_property(&_0, this_ptr, SL("activeModules"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &name))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Module not exists: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 22, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Bootstrap.zep", 285 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("activeModules"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &name, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 287 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(&_4, "getdef", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Bootstrap, dependModule) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *moduleName_param = NULL, module, moduleDef, moduleDir, moduleConf, _1, _2, _3;
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

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	if (UNEXPECTED(Z_TYPE_P(moduleName_param) != IS_STRING && Z_TYPE_P(moduleName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleName' must be of the type string") TSRMLS_CC);
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
	object_init_ex(&moduleDef, phalconplus_base_moduledef_ce);
	ZEPHIR_CALL_METHOD(NULL, &moduleDef, "__construct", NULL, 51, this_ptr, &moduleDir);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&module, this_ptr, "registermodule", NULL, 53, &moduleDef);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&moduleConf);
	object_init_ex(&moduleConf, zephir_get_internal_ce(SL("phalcon\\config")));
	ZEPHIR_CALL_METHOD(&_2, &moduleDef, "getconfigpath", NULL, 55);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "load", NULL, 39, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &moduleConf, "__construct", NULL, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &moduleConf, "merge", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setconfig", NULL, 56, &moduleConf);
	zephir_check_call_status();
	RETURN_CCTOR(&module);

}

PHP_METHOD(PhalconPlus_Bootstrap, isDebug) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("debug"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(Z_TYPE_P(&_0) != IS_NULL);

}

PHP_METHOD(PhalconPlus_Bootstrap, getDebug) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "debug");

}

PHP_METHOD(PhalconPlus_Bootstrap, getEnv) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "env");

}

PHP_METHOD(PhalconPlus_Bootstrap, getConfig) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "config");

}

PHP_METHOD(PhalconPlus_Bootstrap, setConfig) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, config_sub, globalConf, _0, _1, _2, _4, _5, _3$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&globalConf);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	zephir_read_property(&_0, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "config");
	ZEPHIR_CALL_METHOD(&_1, &_0, "has", NULL, 0, &_2);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&globalConf);
		object_init_ex(&globalConf, zephir_get_internal_ce(SL("phalcon\\config")));
		ZEPHIR_CALL_METHOD(NULL, &globalConf, "__construct", NULL, 0);
		zephir_check_call_status();
	} else {
		zephir_read_property(&_3$$4, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&globalConf, &_3$$4, "getconfig", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &globalConf, "merge", NULL, 0, config);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("config"), &globalConf);
	zephir_read_property(&_4, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "config");
	ZEPHIR_CALL_METHOD(NULL, &_4, "set", NULL, 0, &_2, &_5);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Bootstrap, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "di");

}

PHP_METHOD(PhalconPlus_Bootstrap, load) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filePath, filePath_sub, _0, fileRet, _3, rootPath, loader, config, application, bootstrap, di, _4, _5, _6, _7, _8, _9, _10, _11, _12, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&fileRet);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&rootPath);
	ZVAL_UNDEF(&loader);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&application);
	ZVAL_UNDEF(&bootstrap);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath);



	ZEPHIR_CALL_FUNCTION(&_0, "is_file", NULL, 41, filePath);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "The file you try to load is not exists. file position: ", filePath);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 22, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Bootstrap.zep", 353 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&fileRet);
	zephir_read_property(&_3, this_ptr, SL("loadedFiles"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&fileRet, &_3, filePath, 0 TSRMLS_CC)) {
		RETURN_CCTOR(&fileRet);
	}
	ZEPHIR_INIT_VAR(&rootPath);
	ZVAL_STRING(&rootPath, "rootPath");
	ZEPHIR_INIT_VAR(&loader);
	ZVAL_STRING(&loader, "loader");
	ZEPHIR_INIT_VAR(&config);
	ZVAL_STRING(&config, "config");
	ZEPHIR_INIT_VAR(&application);
	ZVAL_STRING(&application, "application");
	ZEPHIR_INIT_VAR(&bootstrap);
	ZVAL_STRING(&bootstrap, "bootstrap");
	ZEPHIR_INIT_VAR(&di);
	ZVAL_STRING(&di, "di");
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_GET_CONSTANT(&_4, "APP_ROOT_DIR");
	ZEPHIR_CPY_WRT(&_5, &_4);
	if (zephir_set_symbol(&rootPath, &_5 TSRMLS_CC) == FAILURE) {
		return;
	}
	ZEPHIR_INIT_NVAR(&_4);
	object_init_ex(&_4, zephir_get_internal_ce(SL("phalcon\\loader")));
	if (zephir_has_constructor(&_4 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CPY_WRT(&_6, &_4);
	if (zephir_set_symbol(&loader, &_6 TSRMLS_CC) == FAILURE) {
		return;
	}
	zephir_read_property(&_7, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&_8, &_7);
	if (zephir_set_symbol(&config, &_8 TSRMLS_CC) == FAILURE) {
		return;
	}
	zephir_read_property(&_7, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&_9, &_7);
	if (zephir_set_symbol(&application, &_9 TSRMLS_CC) == FAILURE) {
		return;
	}
	ZEPHIR_CPY_WRT(&_10, this_ptr);
	if (zephir_set_symbol(&bootstrap, &_10 TSRMLS_CC) == FAILURE) {
		return;
	}
	zephir_read_property(&_7, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&_11, &_7);
	if (zephir_set_symbol(&di, &_11 TSRMLS_CC) == FAILURE) {
		return;
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_12);
	if (zephir_require_zval_ret(&_12, filePath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(&fileRet, &_12);
	zephir_update_property_array(this_ptr, SL("loadedFiles"), filePath, &fileRet);
	RETURN_CCTOR(&fileRet);

}

zend_object *zephir_init_properties_PhalconPlus_Bootstrap(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("loadedFiles"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("loadedFiles"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("activeModules"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("activeModules"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

