
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/main.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Bootstrap) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus, Bootstrap, phalconplus, bootstrap, phalconplus_bootstrap_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("application"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("modeMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalconplus_bootstrap_ce, SL("env"), "dev", ZEND_ACC_PROTECTED TSRMLS_CC);

	phalconplus_bootstrap_ce->create_object = zephir_init_properties_PhalconPlus_Bootstrap;
	zephir_declare_class_constant_string(phalconplus_bootstrap_ce, SL("COMMON_DIR_NAME"), "common");

	zephir_declare_class_constant_string(phalconplus_bootstrap_ce, SL("COMMON_CONF_DIR_NAME"), "config");

	zephir_declare_class_constant_string(phalconplus_bootstrap_ce, SL("COMMON_LOAD_DIR_NAME"), "load");

	zephir_declare_class_constant_string(phalconplus_bootstrap_ce, SL("ROOT_PUB_DIR_NAME"), "public");

	zephir_declare_class_constant_string(phalconplus_bootstrap_ce, SL("MODULE_APP_DIR_NAME"), "app");

	zephir_declare_class_constant_string(phalconplus_bootstrap_ce, SL("DS"), "/");

	zephir_declare_class_constant_string(phalconplus_bootstrap_ce, SL("PHP_EXT"), ".php");

	zephir_declare_class_constant_string(phalconplus_bootstrap_ce, SL("ENV_NAME"), "phalconplus.env");

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Bootstrap, __construct) {

	zend_bool _7;
	zephir_fcall_cache_entry *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modulePath_param = NULL, __$true, _0, env, _3, _4, _5, _6, _8, _9, _10, _11, _12, _13, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _1$$3, debug$$5;
	zval modulePath, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&modulePath);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&env);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&debug$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modulePath_param);

	if (UNEXPECTED(Z_TYPE_P(modulePath_param) != IS_STRING && Z_TYPE_P(modulePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modulePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modulePath_param) == IS_STRING)) {
		zephir_get_strval(&modulePath, modulePath_param);
	} else {
		ZEPHIR_INIT_VAR(&modulePath);
		ZVAL_EMPTY_STRING(&modulePath);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 37, &modulePath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Module directory not exists or not a dir, file positon: ", &modulePath);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 7, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Bootstrap.zep", 49 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "phalconplus.env");
	ZEPHIR_CALL_FUNCTION(&env, "get_cfg_var", NULL, 38, &_3);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&env))) {
		zephir_update_property_zval(this_ptr, SL("env"), &env);
	}
	ZEPHIR_INIT_NVAR(&_3);
	ZEPHIR_GET_CONSTANT(&_3, "PHP_SAPI");
	ZVAL_LONG(&_4, 0);
	ZVAL_LONG(&_5, 3);
	ZEPHIR_INIT_VAR(&_6);
	zephir_substr(&_6, &_3, 0 , 3 , 0);
	_7 = !ZEPHIR_IS_STRING(&_6, "cli");
	if (_7) {
		zephir_read_property(&_8, this_ptr, SL("env"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_9, 0);
		ZVAL_LONG(&_10, 7);
		ZEPHIR_INIT_VAR(&_11);
		zephir_substr(&_11, &_8, 0 , 7 , 0);
		_7 = !ZEPHIR_IS_STRING(&_11, "product");
	}
	if (_7) {
		ZEPHIR_INIT_VAR(&debug$$5);
		object_init_ex(&debug$$5, zephir_get_internal_ce(SL("phalcon\\debug")));
		if (zephir_has_constructor(&debug$$5 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, &debug$$5, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, &debug$$5, "listen", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_12, this_ptr, SL("env"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "APP_ENV");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 39, &_13, &_12, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_13);
	ZEPHIR_INIT_VAR(&_15);
	ZVAL_STRING(&_15, "/");
	zephir_fast_trim(&_13, &modulePath, &_15, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_16);
	ZEPHIR_CONCAT_VS(&_16, &_13, "/");
	ZEPHIR_INIT_VAR(&_17);
	ZVAL_STRING(&_17, "APP_MODULE_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 39, &_17, &_16, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_17);
	ZEPHIR_CALL_FUNCTION(&_18, "dirname", NULL, 40, &modulePath);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_19);
	ZVAL_STRING(&_19, "/");
	zephir_fast_trim(&_17, &_18, &_19, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_20);
	ZEPHIR_CONCAT_VS(&_20, &_17, "/");
	ZEPHIR_INIT_VAR(&_21);
	ZVAL_STRING(&_21, "APP_ROOT_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 39, &_21, &_20, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_21);
	ZEPHIR_GET_CONSTANT(&_21, "APP_ROOT_DIR");
	ZEPHIR_INIT_VAR(&_22);
	ZEPHIR_CONCAT_VSS(&_22, &_21, "common", "/");
	ZEPHIR_INIT_VAR(&_23);
	ZVAL_STRING(&_23, "APP_ROOT_COMMON_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 39, &_23, &_22, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_23);
	ZEPHIR_GET_CONSTANT(&_23, "APP_ROOT_COMMON_DIR");
	ZEPHIR_INIT_VAR(&_24);
	ZEPHIR_CONCAT_VSS(&_24, &_23, "config", "/");
	ZEPHIR_INIT_VAR(&_25);
	ZVAL_STRING(&_25, "APP_ROOT_COMMON_CONF_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 39, &_25, &_24, &__$true);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_25);
	ZEPHIR_GET_CONSTANT(&_25, "APP_ROOT_COMMON_DIR");
	ZEPHIR_INIT_VAR(&_26);
	ZEPHIR_CONCAT_VSS(&_26, &_25, "load", "/");
	ZEPHIR_INIT_VAR(&_27);
	ZVAL_STRING(&_27, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 39, &_27, &_26, &__$true);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, setModule) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *module_param = NULL, diff, _0, _1$$3, _2$$3, _3$$3;
	zval module;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&diff);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module_param);

	zephir_get_arrval(&module, module_param);


	ZEPHIR_INIT_VAR(&diff);
	array_init(&diff);
	zephir_read_property(&_0, this_ptr, SL("module"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&diff, "array_diff_key", NULL, 41, &_0, &module);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&diff))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_json_encode(&_2$$3, &module, 0 );
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SV(&_3$$3, "Module is not a legal module, details: ", &_2$$3);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 7, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Bootstrap.zep", 79 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, SL("module"), &module);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, initConf) {

	zval __$true, globalConfPath, moduleConfPath, moduleConf, _0, _1, _6, _7, _10, _11, _12, _17, module, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _34, _35, _3$$3, _4$$3, _13$$4, _14$$4, _15$$5, _16$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL, *_8 = NULL, *_9 = NULL;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&globalConfPath);
	ZVAL_UNDEF(&moduleConfPath);
	ZVAL_UNDEF(&moduleConf);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_13$$4);
	ZVAL_UNDEF(&_14$$4);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "APP_ROOT_COMMON_CONF_DIR");
	ZEPHIR_INIT_VAR(&globalConfPath);
	ZEPHIR_CONCAT_VSS(&globalConfPath, &_0, "config", ".php");
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", &_2, 42, &globalConfPath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, zephir_get_internal_ce(SL("phalcon\\config\\exception")));
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SV(&_4$$3, "Global config file not exist, file position: ", &globalConfPath);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", &_5, 0, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalconplus/Bootstrap.zep", 92 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_6);
	object_init_ex(&_6, zephir_get_internal_ce(SL("phalcon\\config")));
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "load", &_8, 43, &globalConfPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", &_9, 0, &_7);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("config"), &_6);
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_GET_CONSTANT(&_10, "APP_MODULE_DIR");
	ZEPHIR_INIT_VAR(&_11);
	ZEPHIR_GET_CONSTANT(&_11, "APP_ENV");
	ZEPHIR_INIT_VAR(&moduleConfPath);
	ZEPHIR_CONCAT_VSVS(&moduleConfPath, &_10, "app/config/", &_11, ".php");
	ZEPHIR_CALL_FUNCTION(&_12, "is_file", &_2, 42, &moduleConfPath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_12))) {
		ZEPHIR_INIT_VAR(&_13$$4);
		ZEPHIR_GET_CONSTANT(&_13$$4, "APP_MODULE_DIR");
		ZEPHIR_INIT_NVAR(&moduleConfPath);
		ZEPHIR_CONCAT_VSS(&moduleConfPath, &_13$$4, "app/config/config", ".php");
		ZEPHIR_CALL_FUNCTION(&_14$$4, "is_file", &_2, 42, &moduleConfPath);
		zephir_check_call_status();
		if (!(zephir_is_true(&_14$$4))) {
			ZEPHIR_INIT_VAR(&_15$$5);
			object_init_ex(&_15$$5, zephir_get_internal_ce(SL("phalcon\\config\\exception")));
			ZEPHIR_INIT_VAR(&_16$$5);
			ZEPHIR_CONCAT_SV(&_16$$5, "Module config file not exist, file position: ", &moduleConfPath);
			ZEPHIR_CALL_METHOD(NULL, &_15$$5, "__construct", &_5, 0, &_16$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_15$$5, "phalconplus/Bootstrap.zep", 101 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&moduleConf);
	object_init_ex(&moduleConf, zephir_get_internal_ce(SL("phalcon\\config")));
	ZEPHIR_CALL_METHOD(&_17, this_ptr, "load", &_8, 43, &moduleConfPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &moduleConf, "__construct", &_9, 0, &_17);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&module);
	array_init(&module);
	ZEPHIR_INIT_VAR(&_18);
	ZEPHIR_INIT_VAR(&_19);
	zephir_read_property(&_20, &moduleConf, SL("application"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_21, &_20, SL("mode"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_strtolower(&_19, &_21);
	zephir_ucfirst(&_18, &_19);
	zephir_array_update_string(&module, SL("mode"), &_18, PH_COPY | PH_SEPARATE);
	zephir_read_property(&_22, &moduleConf, SL("application"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_23, &_22, SL("ns"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_24, this_ptr, SL("modeMap"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_26);
	zephir_array_fetch_string(&_26, &module, SL("mode"), PH_NOISY, "phalconplus/Bootstrap.zep", 110 TSRMLS_CC);
	zephir_array_fetch(&_25, &_24, &_26, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 110 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_27);
	ZEPHIR_CONCAT_VV(&_27, &_23, &_25);
	zephir_array_update_string(&module, SL("className"), &_27, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_28);
	ZEPHIR_GET_CONSTANT(&_28, "APP_MODULE_DIR");
	zephir_read_property(&_29, this_ptr, SL("modeMap"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_31);
	zephir_array_fetch_string(&_31, &module, SL("mode"), PH_NOISY, "phalconplus/Bootstrap.zep", 111 TSRMLS_CC);
	zephir_array_fetch(&_30, &_29, &_31, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 111 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_32);
	ZEPHIR_CONCAT_VSVS(&_32, &_28, "app/", &_30, ".php");
	zephir_array_update_string(&module, SL("classPath"), &_32, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_33, &module, SL("mode"), PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 114 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_34);
	ZVAL_STRING(&_34, "APP_RUN_MODE");
	ZEPHIR_CALL_FUNCTION(NULL, "define", NULL, 39, &_34, &_33, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmodule", NULL, 44, &module);
	zephir_check_call_status();
	zephir_read_property(&_35, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_35, "merge", NULL, 0, &moduleConf);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, exec) {

	zval _3;
	zval handleMethod, _0, _1, _2, params;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&handleMethod);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 45);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("modeMap"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_GET_CONSTANT(&_2, "APP_RUN_MODE");
	zephir_array_fetch(&_1, &_0, &_2, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 126 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&handleMethod);
	ZEPHIR_CONCAT_SV(&handleMethod, "exec", &_1);
	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	ZEPHIR_INIT_NVAR(&params);
	zephir_get_args(&params);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_3, this_ptr);
	zephir_array_fast_append(&_3, &handleMethod);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_3, &params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Bootstrap, execModule) {

	zend_class_entry *_12;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool needHandle;
	zval *uri = NULL, uri_sub, *needHandle_param = NULL, __$null, moduleClass, module, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _13, _17, _14$$5, _15$$5, _16$$5, router$$6, newUri$$6, _18$$6, _19$$6, _20$$6, _21$$6, _22$$6, _23$$6, _24$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&moduleClass);
	ZVAL_UNDEF(&module);
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
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&router$$6);
	ZVAL_UNDEF(&newUri$$6);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_24$$6);

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


	if (!(needHandle)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 45);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("phalcon\\di\\factorydefault")));
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("di"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, zephir_get_internal_ce(SL("phalcon\\mvc\\application")));
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("application"), &_1);
	zephir_read_property(&_2, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_2, "setdi", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_GET_CONSTANT(&_4, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_INIT_VAR(&_5);
	ZEPHIR_CONCAT_VS(&_5, &_4, "default-web.php");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 43, &_5);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "bootstrap");
	ZEPHIR_CALL_METHOD(NULL, &_6, "setshared", NULL, 0, &_7, this_ptr);
	zephir_check_call_status();
	zephir_read_property(&_8, this_ptr, SL("module"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_9, &_8, SL("classPath"), PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 150 TSRMLS_CC);
	if (zephir_require_zval(&_9 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_10, this_ptr, SL("module"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&moduleClass);
	zephir_array_fetch_string(&moduleClass, &_10, SL("className"), PH_NOISY, "phalconplus/Bootstrap.zep", 152 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&module);
	zephir_fetch_safe_class(&_11, &moduleClass);
	_12 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_11), Z_STRLEN_P(&_11), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&module, _12);
	if (zephir_has_constructor(&module TSRMLS_CC)) {
		zephir_read_property(&_13, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &module, "__construct", NULL, 0, &_13);
		zephir_check_call_status();
	}
	if (!(needHandle)) {
		RETURN_MM_BOOL(1);
	}

	/* try_start_1: */

		zephir_read_property(&_14$$5, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_15$$5, &_14$$5, "handle", NULL, 0, uri);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_16$$5, &_15$$5, "getcontent", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		zend_print_zval(&_16$$5, 0);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_OBJ(&_7, EG(exception));
		Z_ADDREF_P(&_7);
		ZEPHIR_INIT_VAR(&_17);
		if (zephir_instance_of_ev(&_7, zephir_get_internal_ce(SL("phalcon\\mvc\\application\\exception")) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&_17, &_7);
			zephir_read_property(&_18$$6, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_INIT_VAR(&_19$$6);
			ZVAL_STRING(&_19$$6, "router");
			ZEPHIR_CALL_METHOD(&router$$6, &_18$$6, "get", NULL, 0, &_19$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_20$$6, &router$$6, "getdefaultmodule", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_21$$6, &router$$6, "getrewriteuri", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&newUri$$6);
			ZEPHIR_CONCAT_SVV(&newUri$$6, "/", &_20$$6, &_21$$6);
			zephir_read_property(&_22$$6, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_23$$6, &_22$$6, "handle", NULL, 0, &newUri$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_24$$6, &_23$$6, "getcontent", NULL, 0);
			zephir_check_call_status();
			zend_print_zval(&_24$$6, 0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, execSrv) {

	zend_class_entry *_8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *needHandle_param = NULL, backendSrv, moduleClass, moduleObj, _0, _1, _2, _3, _4, _5, _6, _7, _9, _10, _11, _12;
	zend_bool needHandle;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&backendSrv);
	ZVAL_UNDEF(&moduleClass);
	ZVAL_UNDEF(&moduleObj);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &needHandle_param);

	if (!needHandle_param) {
		needHandle = 1;
	} else {
		needHandle = zephir_get_boolval(needHandle_param);
	}


	ZEPHIR_INIT_VAR(&backendSrv);
	ZVAL_NULL(&backendSrv);
	if (!(needHandle)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 45);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("phalcon\\di\\factorydefault")));
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("di"), &_0);
	zephir_read_property(&_1, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "bootstrap");
	ZEPHIR_CALL_METHOD(NULL, &_1, "setshared", NULL, 0, &_2, this_ptr);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_2);
	ZEPHIR_GET_CONSTANT(&_2, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_VS(&_3, &_2, "default-web.php");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 43, &_3);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, SL("module"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_5, &_4, SL("classPath"), PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 186 TSRMLS_CC);
	if (zephir_require_zval(&_5 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_6, this_ptr, SL("module"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&moduleClass);
	zephir_array_fetch_string(&moduleClass, &_6, SL("className"), PH_NOISY, "phalconplus/Bootstrap.zep", 187 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&moduleObj);
	zephir_fetch_safe_class(&_7, &moduleClass);
	_8 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_7), Z_STRLEN_P(&_7), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&moduleObj, _8);
	if (zephir_has_constructor(&moduleObj TSRMLS_CC)) {
		zephir_read_property(&_9, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &moduleObj, "__construct", NULL, 0, &_9);
		zephir_check_call_status();
	}
	if (!(needHandle)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(&backendSrv);
	object_init_ex(&backendSrv, phalconplus_base_backendserver_ce);
	zephir_read_property(&_10, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &backendSrv, "__construct", NULL, 46, &_10);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_11);
	object_init_ex(&_11, zephir_get_internal_ce(SL("yar_server")));
	ZEPHIR_CALL_METHOD(NULL, &_11, "__construct", NULL, 0, &backendSrv);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("application"), &_11);
	zephir_read_property(&_12, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_12, "handle", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, execTask) {

	zend_class_entry *_13;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *argv_param = NULL, *di = NULL, di_sub, *needHandle = NULL, needHandle_sub, __$null, __$true, moduleClass, module, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _14, _15, _1$$3;
	zval argv;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&argv);
	ZVAL_UNDEF(&di_sub);
	ZVAL_UNDEF(&needHandle_sub);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&moduleClass);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_1$$3);

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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 45);
	zephir_check_call_status();
	_0 = Z_TYPE_P(di) == IS_NULL;
	if (!(_0)) {
		_0 = !((zephir_instance_of_ev(di, zephir_get_internal_ce(SL("phalcon\\di\\factorydefault\\cli")) TSRMLS_CC)));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zephir_get_internal_ce(SL("phalcon\\di\\factorydefault\\cli")));
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("di"), &_1$$3);
	} else {
		zephir_update_property_zval(this_ptr, SL("di"), di);
	}
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, zephir_get_internal_ce(SL("phalcon\\cli\\console")));
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
	ZEPHIR_CONCAT_VS(&_6, &_5, "default-cli.php");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 43, &_6);
	zephir_check_call_status();
	zephir_read_property(&_7, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "bootstrap");
	ZEPHIR_CALL_METHOD(NULL, &_7, "setshared", NULL, 0, &_8, this_ptr);
	zephir_check_call_status();
	zephir_read_property(&_9, this_ptr, SL("module"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_10, &_9, SL("classPath"), PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 222 TSRMLS_CC);
	if (zephir_require_zval(&_10 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_11, this_ptr, SL("module"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&moduleClass);
	zephir_array_fetch_string(&moduleClass, &_11, SL("className"), PH_NOISY, "phalconplus/Bootstrap.zep", 223 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&module);
	zephir_fetch_safe_class(&_12, &moduleClass);
	_13 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_12), Z_STRLEN_P(&_12), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&module, _13);
	if (zephir_has_constructor(&module TSRMLS_CC)) {
		zephir_read_property(&_14, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &module, "__construct", NULL, 0, &_14);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(needHandle))) {
		RETURN_MM_BOOL(1);
	}
	zephir_read_property(&_15, this_ptr, SL("application"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_15, "handle", NULL, 0, &argv);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Bootstrap, dependModule) {

	zend_class_entry *_27;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_9 = NULL, *_10 = NULL;
	zval *moduleName_param = NULL, moduleConfPath, moduleConf, moduleClassName, moduleClassPath, moduleRunMode, _0, _1, _2, reservedModuleConf, _8, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _23, _24, _25, _26, _28, _4$$3, _5$$3, _6$$4, _7$$4, _21$$5, _22$$5;
	zval moduleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&moduleConfPath);
	ZVAL_UNDEF(&moduleConf);
	ZVAL_UNDEF(&moduleClassName);
	ZVAL_UNDEF(&moduleClassPath);
	ZVAL_UNDEF(&moduleRunMode);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&reservedModuleConf);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_21$$5);
	ZVAL_UNDEF(&_22$$5);

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


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "APP_ROOT_DIR");
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_GET_CONSTANT(&_1, "APP_ENV");
	ZEPHIR_INIT_VAR(&moduleConfPath);
	ZEPHIR_CONCAT_VVSVS(&moduleConfPath, &_0, &moduleName, "/app/config/", &_1, ".php");
	ZEPHIR_CALL_FUNCTION(&_2, "is_file", &_3, 42, &moduleConfPath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_GET_CONSTANT(&_4$$3, "APP_ROOT_DIR");
		ZEPHIR_INIT_NVAR(&moduleConfPath);
		ZEPHIR_CONCAT_VVSS(&moduleConfPath, &_4$$3, &moduleName, "/app/config/config", ".php");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "is_file", &_3, 42, &moduleConfPath);
		zephir_check_call_status();
		if (!(zephir_is_true(&_5$$3))) {
			ZEPHIR_INIT_VAR(&_6$$4);
			object_init_ex(&_6$$4, zephir_get_internal_ce(SL("phalcon\\config\\exception")));
			ZEPHIR_INIT_VAR(&_7$$4);
			ZEPHIR_CONCAT_SV(&_7$$4, "Module config file not exist, file position: ", &moduleConfPath);
			ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", NULL, 0, &_7$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$4, "phalconplus/Bootstrap.zep", 240 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&moduleConf);
	object_init_ex(&moduleConf, zephir_get_internal_ce(SL("phalcon\\config")));
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "load", &_9, 43, &moduleConfPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &moduleConf, "__construct", &_10, 0, &_8);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&reservedModuleConf);
	object_init_ex(&reservedModuleConf, zephir_get_internal_ce(SL("phalcon\\config")));
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "load", &_9, 43, &moduleConfPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &reservedModuleConf, "__construct", &_10, 0, &_11);
	zephir_check_call_status();
	zephir_read_property(&_12, &moduleConf, SL("application"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&moduleRunMode);
	zephir_read_property(&moduleRunMode, &_12, SL("mode"), PH_NOISY_CC);
	zephir_read_property(&_13, &moduleConf, SL("application"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_14, &_13, SL("ns"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_15, this_ptr, SL("modeMap"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_16, &_15, &moduleRunMode, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 250 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&moduleClassName);
	ZEPHIR_CONCAT_VV(&moduleClassName, &_14, &_16);
	ZEPHIR_INIT_VAR(&_17);
	ZEPHIR_GET_CONSTANT(&_17, "APP_ROOT_DIR");
	zephir_read_property(&_18, this_ptr, SL("modeMap"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch(&_19, &_18, &moduleRunMode, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 251 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&moduleClassPath);
	ZEPHIR_CONCAT_VVSVS(&moduleClassPath, &_17, &moduleName, "/app/", &_19, ".php");
	ZEPHIR_CALL_FUNCTION(&_20, "is_file", &_3, 42, &moduleClassPath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_20))) {
		ZEPHIR_INIT_VAR(&_21$$5);
		object_init_ex(&_21$$5, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_22$$5);
		ZEPHIR_CONCAT_SV(&_22$$5, "Module init file not exists, file position: ", &moduleClassPath);
		ZEPHIR_CALL_METHOD(NULL, &_21$$5, "__construct", NULL, 7, &_22$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_21$$5, "phalconplus/Bootstrap.zep", 253 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_23, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_24);
	ZVAL_STRING(&_24, "moduleConfig");
	ZEPHIR_CALL_METHOD(NULL, &_23, "set", NULL, 0, &_24, &reservedModuleConf);
	zephir_check_call_status();
	zephir_read_property(&_25, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &moduleConf, "merge", NULL, 0, &_25);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setconfig", NULL, 47, &moduleConf);
	zephir_check_call_status();
	if (zephir_require_zval(&moduleClassPath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	zephir_fetch_safe_class(&_26, &moduleClassName);
	_27 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_26), Z_STRLEN_P(&_26), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(return_value, _27);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		zephir_read_property(&_28, this_ptr, SL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_28);
		zephir_check_call_status();
	}
	RETURN_MM();

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

	zval _3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filePath, filePath_sub, _0, _4, _5, _6, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath);



	ZEPHIR_CALL_FUNCTION(&_0, "is_file", NULL, 42, filePath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "The file you try to load is not exists. file position: ", filePath);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 7, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Bootstrap.zep", 299 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 6, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_GET_CONSTANT(&_4, "APP_ROOT_DIR");
	zephir_array_update_string(&_3, SL("rootPath"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_4);
	object_init_ex(&_4, zephir_get_internal_ce(SL("phalcon\\loader")));
	if (zephir_has_constructor(&_4 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_4, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_array_update_string(&_3, SL("loader"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(&_5);
	zephir_read_property(&_5, this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("config"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_5);
	zephir_read_property(&_5, this_ptr, SL("application"), PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("application"), &_5, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_3, SL("bootstrap"), this_ptr, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_5);
	zephir_read_property(&_5, this_ptr, SL("di"), PH_NOISY_CC);
	zephir_array_update_string(&_3, SL("di"), &_5, PH_COPY | PH_SEPARATE);
	ZEPHIR_MAKE_REF(&_3);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", NULL, 48, &_3);
	ZEPHIR_UNREF(&_3);
	zephir_check_call_status();
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_6);
	if (zephir_require_zval_ret(&_6, filePath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(_6);

}

zend_object *zephir_init_properties_PhalconPlus_Bootstrap(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3, _3$$4;
	zval _0, _2;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("modeMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_1$$3, SL("Web"), SL("Module"));
			add_assoc_stringl_ex(&_1$$3, SL("Cli"), SL("Task"));
			add_assoc_stringl_ex(&_1$$3, SL("Srv"), SL("Srv"));
			add_assoc_stringl_ex(&_1$$3, SL("Micro"), SL("Micro"));
			zephir_update_property_zval(this_ptr, SL("modeMap"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("module"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_3$$4, SL("classPath"), SL(""));
			add_assoc_stringl_ex(&_3$$4, SL("className"), SL(""));
			add_assoc_stringl_ex(&_3$$4, SL("mode"), SL(""));
			zephir_update_property_zval(this_ptr, SL("module"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

