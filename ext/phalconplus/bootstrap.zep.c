
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
#include "kernel/string.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/main.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Bootstrap) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus, Bootstrap, phalconplus, bootstrap, phalconplus_bootstrap_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("application"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("primaryModuleDef"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("activeModules"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("debug"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalconplus_bootstrap_ce, SL("env"), "dev", ZEND_ACC_PROTECTED TSRMLS_CC);

	phalconplus_bootstrap_ce->create_object = zephir_init_properties_PhalconPlus_Bootstrap;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Bootstrap, __construct) {

	zend_bool _6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_8 = NULL, *_14 = NULL, *_17 = NULL, *_19 = NULL, *_22 = NULL, *_24 = NULL, *_26 = NULL;
	zval *moduleDir_param = NULL, __$true, env, _1, _2, _3, _4, _5, _7, _9, _12, _13, _15, _16, _18, _20, _21, _23, _25, _10$$4, _11$$4;
	zval moduleDir;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleDir);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&env);
	ZVAL_UNDEF(&_1);
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
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleDir_param);

	if (UNEXPECTED(Z_TYPE_P(moduleDir_param) != IS_STRING && Z_TYPE_P(moduleDir_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleDir' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(moduleDir_param) == IS_STRING)) {
		zephir_get_strval(&moduleDir, moduleDir_param);
	} else {
		ZEPHIR_INIT_VAR(&moduleDir);
		ZVAL_EMPTY_STRING(&moduleDir);
	}


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_enum_sys_ce, "init", &_0, 0, &moduleDir);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "phalconplus.env");
	ZEPHIR_CALL_FUNCTION(&_2, "get_cfg_var", NULL, 43, &_1);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&env);
	zephir_fast_trim(&env, &_2, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(&env))) {
		zephir_update_property_zval(this_ptr, SL("env"), &env);
	}
	ZEPHIR_INIT_NVAR(&_1);
	ZEPHIR_GET_CONSTANT(&_1, "PHP_SAPI");
	ZVAL_LONG(&_3, 0);
	ZVAL_LONG(&_4, 3);
	ZEPHIR_INIT_VAR(&_5);
	zephir_substr(&_5, &_1, 0 , 3 , 0);
	_6 = !ZEPHIR_IS_STRING(&_5, "cli");
	if (_6) {
		zephir_read_property(&_9, this_ptr, SL("env"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_CE_STATIC(&_7, phalconplus_enum_runenv_ce, "isinprod", &_8, 0, &_9);
		zephir_check_call_status();
		_6 = !zephir_is_true(&_7);
	}
	if (_6) {
		ZEPHIR_INIT_VAR(&_10$$4);
		object_init_ex(&_10$$4, zephir_get_internal_ce(SL("phalcon\\debug")));
		if (zephir_has_constructor(&_10$$4 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &_10$$4, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		zephir_update_property_zval(this_ptr, SL("debug"), &_10$$4);
		zephir_read_property(&_11$$4, this_ptr, SL("debug"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_11$$4, "listen", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_12, this_ptr, SL("env"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "APP_ENV");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 44, &_13, &_12, &__$true);
	zephir_check_call_status();
	zephir_read_property(&_15, this_ptr, SL("env"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "APP_RUN_ENV");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 44, &_13, &_15, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_16, phalconplus_enum_sys_ce, "getrootdir", &_17, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "APP_ROOT_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 44, &_13, &_16, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_18, phalconplus_enum_sys_ce, "getprimarymoduledir", &_19, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "APP_MODULE_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 44, &_13, &_18, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_20, phalconplus_enum_sys_ce, "getprimarymoduledir", &_19, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "APP_PRI_MODULE_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 44, &_13, &_20, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_21, phalconplus_enum_sys_ce, "getcommondir", &_22, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "APP_ROOT_COMMON_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 44, &_13, &_21, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_23, phalconplus_enum_sys_ce, "getgloballoaddir", &_24, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 44, &_13, &_23, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_25, phalconplus_enum_sys_ce, "getglobalconfigdir", &_26, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZVAL_STRING(&_13, "APP_ROOT_COMMON_CONF_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 44, &_13, &_25, &__$true);
	zephir_check_call_status();
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
	if (zephir_array_isset(&_0, &_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_CALL_METHOD(&_3$$3, moduleDef, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SV(&_4$$3, "Module already loaded: ", &_3$$3);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 7, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalconplus/Bootstrap.zep", 57 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_5, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_5) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_6$$4);
		object_init_ex(&_6$$4, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_CALL_METHOD(&_7$$4, moduleDef, "getname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_8$$4);
		ZEPHIR_CONCAT_SV(&_8$$4, "DI doesn't load yet, failed to register module ", &_7$$4);
		ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", NULL, 7, &_8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$4, "phalconplus/Bootstrap.zep", 60 TSRMLS_CC);
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
	zephir_update_property_array(this_ptr, SL("activeModules"), &_10, &module TSRMLS_CC);
	RETURN_CCTOR(&module);

}

PHP_METHOD(PhalconPlus_Bootstrap, initConf) {

	zval __$true, globalConfPath, moduleConf, _1, _4, _5, _6, _7, _8, _9, _10, _11, _12, _2$$3, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&globalConfPath);
	ZVAL_UNDEF(&moduleConf);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&globalConfPath);
	ZVAL_STRING(&globalConfPath, "");
	ZEPHIR_INIT_VAR(&moduleConf);
	ZVAL_NULL(&moduleConf);
	ZEPHIR_CALL_CE_STATIC(&globalConfPath, phalconplus_enum_sys_ce, "getglobalconfigpath", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", NULL, 38, &globalConfPath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, zephir_get_internal_ce(SL("phalcon\\config\\exception")));
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "Global config file not exist, file position: ", &globalConfPath);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 0, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalconplus/Bootstrap.zep", 81 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_4);
	object_init_ex(&_4, zephir_get_internal_ce(SL("phalcon\\config")));
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "load", NULL, 36, &globalConfPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 0, &_5);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("config"), &_4);
	ZEPHIR_INIT_VAR(&_6);
	object_init_ex(&_6, phalconplus_base_moduledef_ce);
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_GET_CONSTANT(&_7, "APP_MODULE_DIR");
	ZVAL_BOOL(&_8, 1);
	ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", NULL, 45, this_ptr, &_7, &_8);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("primaryModuleDef"), &_6);
	zephir_read_property(&_8, this_ptr, SL("primaryModuleDef"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_9, &_8, "getmode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "APP_RUN_MODE");
	ZEPHIR_CALL_FUNCTION(NULL, "define", NULL, 44, &_10, &_9, &__$true);
	zephir_check_call_status();
	zephir_read_property(&_11, this_ptr, SL("primaryModuleDef"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&moduleConf, &_11, "getconfig", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_12, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_12, "merge", NULL, 0, &moduleConf);
	zephir_check_call_status();
	RETURN_THIS();

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

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 46);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("primaryModuleDef"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getmapclassname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&handleMethod);
	ZEPHIR_CONCAT_SV(&handleMethod, "exec", &_1);
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

PHP_METHOD(PhalconPlus_Bootstrap, execModule) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool needHandle;
	zval *uri = NULL, uri_sub, *needHandle_param = NULL, __$null, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _13, _10$$5, _11$$5, _12$$5, router$$6, newUri$$6, _14$$6, _15$$6, _16$$6, _17$$6, _18$$6, _19$$6, _20$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&router$$6);
	ZVAL_UNDEF(&newUri$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &uri, &needHandle_param);

	if (!uri) {
		uri = &uri_sub;
		uri = &__$null;
	}
	if (!needHandle_param) {
		needHandle = 1;
	} else {
		needHandle = zephir_get_boolval(needHandle_param);
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("config"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 46);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, zephir_get_internal_ce(SL("phalcon\\di\\factorydefault")));
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("di"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, zephir_get_internal_ce(SL("phalcon\\mvc\\application")));
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("application"), &_2);
	zephir_read_property(&_3, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "setdi", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_GET_CONSTANT(&_5, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_CONCAT_VS(&_6, &_5, "default-web.php");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 36, &_6);
	zephir_check_call_status();
	zephir_read_property(&_7, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "bootstrap");
	ZEPHIR_CALL_METHOD(NULL, &_7, "setshared", NULL, 0, &_8, this_ptr);
	zephir_check_call_status();
	zephir_read_property(&_9, this_ptr, SL("primaryModuleDef"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registermodule", NULL, 47, &_9);
	zephir_check_call_status();
	if (!(needHandle)) {
		RETURN_MM_BOOL(1);
	}

	/* try_start_1: */

		zephir_read_property(&_10$$5, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_11$$5, &_10$$5, "handle", NULL, 0, uri);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_12$$5, &_11$$5, "getcontent", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		zend_print_zval(&_12$$5, 0);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_NVAR(&_8);
		ZVAL_OBJ(&_8, EG(exception));
		Z_ADDREF_P(&_8);
		ZEPHIR_INIT_VAR(&_13);
		if (zephir_instance_of_ev(&_8, zephir_get_internal_ce(SL("phalcon\\mvc\\application\\exception")) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&_13, &_8);
			zephir_read_property(&_14$$6, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_15$$6);
			ZVAL_STRING(&_15$$6, "router");
			ZEPHIR_CALL_METHOD(&router$$6, &_14$$6, "get", NULL, 0, &_15$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_16$$6, &router$$6, "getdefaultmodule", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_17$$6, &router$$6, "getrewriteuri", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&newUri$$6);
			ZEPHIR_CONCAT_SVV(&newUri$$6, "/", &_16$$6, &_17$$6);
			zephir_read_property(&_18$$6, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_19$$6, &_18$$6, "handle", NULL, 0, &newUri$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_20$$6, &_19$$6, "getcontent", NULL, 0);
			zephir_check_call_status();
			zend_print_zval(&_20$$6, 0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, execSrv) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *needHandle_param = NULL, backendSrv, _0, _1, _2, _3, _4, _5, _6, _7, _8;
	zend_bool needHandle;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&backendSrv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &needHandle_param);

	if (!needHandle_param) {
		needHandle = 1;
	} else {
		needHandle = zephir_get_boolval(needHandle_param);
	}


	ZEPHIR_INIT_VAR(&backendSrv);
	ZVAL_NULL(&backendSrv);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("config"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 46);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, zephir_get_internal_ce(SL("phalcon\\di\\factorydefault")));
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("di"), &_1);
	zephir_read_property(&_2, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "bootstrap");
	ZEPHIR_CALL_METHOD(NULL, &_2, "setshared", NULL, 0, &_3, this_ptr);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZEPHIR_GET_CONSTANT(&_3, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_VS(&_4, &_3, "default-web.php");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 36, &_4);
	zephir_check_call_status();
	zephir_read_property(&_5, this_ptr, SL("primaryModuleDef"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registermodule", NULL, 47, &_5);
	zephir_check_call_status();
	if (!(needHandle)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&backendSrv);
	object_init_ex(&backendSrv, phalconplus_base_backendserver_ce);
	zephir_read_property(&_6, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &backendSrv, "__construct", NULL, 48, &_6);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_7);
	object_init_ex(&_7, zephir_get_internal_ce(SL("yar_server")));
	ZEPHIR_CALL_METHOD(NULL, &_7, "__construct", NULL, 0, &backendSrv);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("application"), &_7);
	zephir_read_property(&_8, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_8, "handle", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, execTask) {

	zend_bool _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *argv_param = NULL, *di = NULL, di_sub, *needHandle = NULL, needHandle_sub, __$null, __$true, _0, _3, _4, _5, _6, _7, _8, _9, _10, _11, _2$$4;
	zval argv;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&argv);
	ZVAL_UNDEF(&di_sub);
	ZVAL_UNDEF(&needHandle_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &argv_param, &di, &needHandle);

	zephir_get_arrval(&argv, argv_param);
	if (!di) {
		di = &di_sub;
		di = &__$null;
	}
	if (!needHandle) {
		needHandle = &needHandle_sub;
		needHandle = &__$true;
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("config"), PH_NOISY_CC);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 46);
		zephir_check_call_status();
	}
	_1 = Z_TYPE_P(di) == IS_NULL;
	if (!(_1)) {
		_1 = !((zephir_instance_of_ev(di, zephir_get_internal_ce(SL("phalcon\\di\\factorydefault\\cli")) TSRMLS_CC)));
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_2$$4);
		object_init_ex(&_2$$4, zephir_get_internal_ce(SL("phalcon\\di\\factorydefault\\cli")));
		ZEPHIR_CALL_METHOD(NULL, &_2$$4, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("di"), &_2$$4);
	} else {
		zephir_update_property_zval(this_ptr, SL("di"), di);
	}
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, zephir_get_internal_ce(SL("phalcon\\cli\\console")));
	ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("application"), &_3);
	zephir_read_property(&_4, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_4, "setdi", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_6);
	ZEPHIR_GET_CONSTANT(&_6, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_VS(&_7, &_6, "default-cli.php");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 36, &_7);
	zephir_check_call_status();
	zephir_read_property(&_8, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "bootstrap");
	ZEPHIR_CALL_METHOD(NULL, &_8, "setshared", NULL, 0, &_9, this_ptr);
	zephir_check_call_status();
	zephir_read_property(&_10, this_ptr, SL("primaryModuleDef"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "registermodule", NULL, 47, &_10);
	zephir_check_call_status();
	if (!(zephir_is_true(needHandle))) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property(&_11, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_11, "handle", NULL, 0, &argv);
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
		object_init_ex(&_2$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "Module not exists: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 7, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalconplus/Bootstrap.zep", 199 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("activeModules"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_5, &_4, &name, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 201 TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
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
		object_init_ex(&_1$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Module not exists: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 7, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Bootstrap.zep", 207 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("activeModules"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &name, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 209 TSRMLS_CC);
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
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
		object_init_ex(&_1$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Module not exists: ", &name);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 7, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Bootstrap.zep", 215 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("activeModules"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_4, &_3, &name, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 217 TSRMLS_CC);
	ZEPHIR_RETURN_CALL_METHOD(&_4, "getdef", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Bootstrap, dependModule) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *moduleName_param = NULL, module, moduleDef, moduleDir, moduleConf, _1, _2, _3, _4, _5, _6;
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	if (UNEXPECTED(Z_TYPE_P(moduleName_param) != IS_STRING && Z_TYPE_P(moduleName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleName' must be a string") TSRMLS_CC);
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
	ZEPHIR_CALL_METHOD(NULL, &moduleDef, "__construct", NULL, 45, this_ptr, &moduleDir);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&module, this_ptr, "registermodule", NULL, 47, &moduleDef);
	zephir_check_call_status();
	zephir_read_property(&_1, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &moduleDef, "getconfig", NULL, 49);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "moduleConfig");
	ZEPHIR_CALL_METHOD(NULL, &_1, "set", NULL, 0, &_3, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&moduleConf);
	object_init_ex(&moduleConf, zephir_get_internal_ce(SL("phalcon\\config")));
	ZEPHIR_CALL_METHOD(&_5, &moduleDef, "getconfigpath", NULL, 50);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "load", NULL, 36, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &moduleConf, "__construct", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &moduleConf, "merge", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setconfig", NULL, 51, &moduleConf);
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
	zval *filePath, filePath_sub, _0, rootPath, loader, config, application, bootstrap, di, _3, _4, _5, _6, _7, _8, _9, _10, _11, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&rootPath);
	ZVAL_UNDEF(&loader);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&application);
	ZVAL_UNDEF(&bootstrap);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath);



	ZEPHIR_CALL_FUNCTION(&_0, "is_file", NULL, 38, filePath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "The file you try to load is not exists. file position: ", filePath);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 7, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Bootstrap.zep", 283 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
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
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_GET_CONSTANT(&_3, "APP_ROOT_DIR");
	ZEPHIR_CPY_WRT(&_4, &_3);
	if (zephir_set_symbol(&rootPath, &_4 TSRMLS_CC) == FAILURE) {
		return;
	}
	ZEPHIR_INIT_NVAR(&_3);
	object_init_ex(&_3, zephir_get_internal_ce(SL("phalcon\\loader")));
	if (zephir_has_constructor(&_3 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CPY_WRT(&_5, &_3);
	if (zephir_set_symbol(&loader, &_5 TSRMLS_CC) == FAILURE) {
		return;
	}
	zephir_read_property(&_6, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&_7, &_6);
	if (zephir_set_symbol(&config, &_7 TSRMLS_CC) == FAILURE) {
		return;
	}
	zephir_read_property(&_6, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&_8, &_6);
	if (zephir_set_symbol(&application, &_8 TSRMLS_CC) == FAILURE) {
		return;
	}
	ZEPHIR_CPY_WRT(&_9, this_ptr);
	if (zephir_set_symbol(&bootstrap, &_9 TSRMLS_CC) == FAILURE) {
		return;
	}
	zephir_read_property(&_6, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&_10, &_6);
	if (zephir_set_symbol(&di, &_10 TSRMLS_CC) == FAILURE) {
		return;
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_11);
	if (zephir_require_zval_ret(&_11, filePath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&_11);

}

zend_object *zephir_init_properties_PhalconPlus_Bootstrap(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("activeModules"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("activeModules"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

