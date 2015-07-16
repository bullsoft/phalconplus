
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
#include "kernel/require.h"

ZEPHIR_INIT_CLASS(PhalconPlus_Bootstrap) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus, Bootstrap, phalconplus, bootstrap, phalconplus_bootstrap_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("application"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("loader"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("module"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("modeMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalconplus_bootstrap_ce, SL("env"), "dev", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_bootstrap_ce, SL("COMMON_DIR_NAME"), "common" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_bootstrap_ce, SL("COMMON_CONF_DIR_NAME"), "config" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_bootstrap_ce, SL("COMMON_LOAD_DIR_NAME"), "load" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_bootstrap_ce, SL("ROOT_PUB_DIR_NAME"), "public" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_bootstrap_ce, SL("MODULE_APP_DIR_NAME"), "app" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Bootstrap, __construct) {

	zephir_fcall_cache_entry *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *modulePath_param = NULL, *_0 = NULL, *_1 = NULL, *env = NULL, _3 = zval_used_for_init, *_4, *debug, *_5, *_7, _8 = zval_used_for_init, *_9, *_10 = NULL, *_11, _12 = zval_used_for_init, *_13, *_14, *_15, *_16, *_17, *_18, *_19, *_20;
	zval *modulePath = NULL, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modulePath_param);

	if (unlikely(Z_TYPE_P(modulePath_param) != IS_STRING && Z_TYPE_P(modulePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modulePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(modulePath_param) == IS_STRING)) {
		zephir_get_strval(modulePath, modulePath_param);
	} else {
		ZEPHIR_INIT_VAR(modulePath);
		ZVAL_EMPTY_STRING(modulePath);
	}


	if (EG(called_scope) == phalconplus_bootstrap_ce) {
		zephir_init_properties(this_ptr TSRMLS_CC);
	}
	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 26, modulePath);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_2);
		ZEPHIR_CONCAT_SV(_2, "Module directory not exists or not a dir, file positon: ", modulePath);
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 21, _2);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalconplus/Bootstrap.zep", 40 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "phalconplus.env", 0);
	ZEPHIR_CALL_FUNCTION(&env, "get_cfg_var", NULL, 27, &_3);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(env))) {
		zephir_update_property_this(this_ptr, SL("env"), env TSRMLS_CC);
	}
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
	if (!ZEPHIR_IS_STRING(_4, "product")) {
		ZEPHIR_INIT_VAR(debug);
		object_init_ex(debug, zephir_get_internal_ce(SS("phalcon\\debug") TSRMLS_CC));
		if (zephir_has_constructor(debug TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, debug, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, debug, "listen", NULL, 0);
		zephir_check_call_status();
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_STRING(&_3, "APP_ENV", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_6, 28, &_3, _5, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_STRING(&_3, "/", 0);
	zephir_fast_trim(_1, modulePath, &_3, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_VS(_7, _1, "/");
	ZEPHIR_SINIT_VAR(_8);
	ZVAL_STRING(&_8, "APP_MODULE_DIR", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_6, 28, &_8, _7, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_9);
	ZEPHIR_CALL_FUNCTION(&_10, "dirname", NULL, 29, modulePath);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_8);
	ZVAL_STRING(&_8, "/", 0);
	zephir_fast_trim(_9, _10, &_8, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_11);
	ZEPHIR_CONCAT_VS(_11, _9, "/");
	ZEPHIR_SINIT_VAR(_12);
	ZVAL_STRING(&_12, "APP_ROOT_DIR", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_6, 28, &_12, _11, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_13);
	ZEPHIR_GET_CONSTANT(_13, "APP_ROOT_DIR");
	ZEPHIR_INIT_VAR(_14);
	ZEPHIR_CONCAT_VSS(_14, _13, "public", "/");
	ZEPHIR_SINIT_NVAR(_12);
	ZVAL_STRING(&_12, "APP_ROOT_PUB_DIR", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_6, 28, &_12, _14, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_15);
	ZEPHIR_GET_CONSTANT(_15, "APP_ROOT_DIR");
	ZEPHIR_INIT_VAR(_16);
	ZEPHIR_CONCAT_VSS(_16, _15, "common", "/");
	ZEPHIR_SINIT_NVAR(_12);
	ZVAL_STRING(&_12, "APP_ROOT_COMMON_DIR", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_6, 28, &_12, _16, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_17);
	ZEPHIR_GET_CONSTANT(_17, "APP_ROOT_COMMON_DIR");
	ZEPHIR_INIT_VAR(_18);
	ZEPHIR_CONCAT_VSS(_18, _17, "config", "/");
	ZEPHIR_SINIT_NVAR(_12);
	ZVAL_STRING(&_12, "APP_ROOT_COMMON_CONF_DIR", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_6, 28, &_12, _18, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_19);
	ZEPHIR_GET_CONSTANT(_19, "APP_ROOT_COMMON_DIR");
	ZEPHIR_INIT_VAR(_20);
	ZEPHIR_CONCAT_VSS(_20, _19, "load", "/");
	ZEPHIR_SINIT_NVAR(_12);
	ZVAL_STRING(&_12, "APP_ROOT_COMMON_LOAD_DIR", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_6, 28, &_12, _20, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, setModule) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *module_param = NULL, *diff = NULL, *_0;
	zval *module = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module_param);

	zephir_get_arrval(module, module_param);
	ZEPHIR_INIT_VAR(diff);
	array_init(diff);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&diff, "array_diff_key", NULL, 30, _0, module);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(diff))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Module is is not a legal module", "phalconplus/Bootstrap.zep", 71);
		return;
	}
	zephir_update_property_this(this_ptr, SL("module"), module TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, initConf) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_6 = NULL;
	zval *globalConfPath, *moduleConfPath, *moduleConf, *_0, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_7, *_8, *_9 = NULL, *_10 = NULL, *_11 = NULL, *module, *_12, *_13, *_14, *_15, *_16, *_17, *_18, *_19, *_20, *_21, *_22, *_23, *_24, _25, *_26;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(module);
	array_init(module);

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "APP_ROOT_COMMON_CONF_DIR");
	ZEPHIR_INIT_VAR(globalConfPath);
	ZEPHIR_CONCAT_VS(globalConfPath, _0, "config.php");
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", &_2, 31, globalConfPath);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, zephir_get_internal_ce(SS("phalcon\\config\\exception") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SV(_4, "Global config file not exist, file position: ", globalConfPath);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 0, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "phalconplus/Bootstrap.zep", 84 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(_3);
	object_init_ex(_3, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "load", &_6, 32, globalConfPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 0, _5);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("config"), _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_GET_CONSTANT(_7, "APP_MODULE_DIR");
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_GET_CONSTANT(_8, "APP_ENV");
	ZEPHIR_INIT_VAR(moduleConfPath);
	ZEPHIR_CONCAT_VSVS(moduleConfPath, _7, "/app/config/", _8, ".php");
	ZEPHIR_CALL_FUNCTION(&_9, "is_file", &_2, 31, moduleConfPath);
	zephir_check_call_status();
	if (!(zephir_is_true(_9))) {
		ZEPHIR_INIT_VAR(_10);
		object_init_ex(_10, zephir_get_internal_ce(SS("phalcon\\config\\exception") TSRMLS_CC));
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SV(_4, "Module config file not exist, file position: ", moduleConfPath);
		ZEPHIR_CALL_METHOD(NULL, _10, "__construct", NULL, 0, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_10, "phalconplus/Bootstrap.zep", 91 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(moduleConf);
	object_init_ex(moduleConf, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "load", &_6, 32, moduleConfPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, moduleConf, "__construct", NULL, 0, _11);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZEPHIR_INIT_NVAR(_10);
	ZEPHIR_OBS_VAR(_12);
	zephir_read_property(&_12, moduleConf, SL("application"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_13);
	zephir_read_property(&_13, _12, SL("mode"), PH_NOISY_CC);
	zephir_fast_strtolower(_10, _13);
	zephir_ucfirst(_3, _10);
	zephir_array_update_string(&module, SL("mode"), &_3, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(_14);
	zephir_read_property(&_14, moduleConf, SL("application"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_15);
	zephir_read_property(&_15, _14, SL("ns"), PH_NOISY_CC);
	_16 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_18);
	zephir_array_fetch_string(&_18, module, SL("mode"), PH_NOISY, "phalconplus/Bootstrap.zep", 98 TSRMLS_CC);
	zephir_array_fetch(&_17, _16, _18, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 98 TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_4);
	ZEPHIR_CONCAT_VV(_4, _15, _17);
	zephir_array_update_string(&module, SL("className"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_19);
	ZEPHIR_GET_CONSTANT(_19, "APP_MODULE_DIR");
	_20 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_22);
	zephir_array_fetch_string(&_22, module, SL("mode"), PH_NOISY, "phalconplus/Bootstrap.zep", 99 TSRMLS_CC);
	zephir_array_fetch(&_21, _20, _22, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 99 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_23);
	ZEPHIR_CONCAT_VSVS(_23, _19, "app/", _21, ".php");
	zephir_array_update_string(&module, SL("classPath"), &_23, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_24, module, SL("mode"), PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 102 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_25);
	ZVAL_STRING(&_25, "APP_RUN_MODE", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", NULL, 28, &_25, _24, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmodule", NULL, 33, module);
	zephir_check_call_status();
	_26 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _26, "merge", NULL, 0, moduleConf);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, exec) {

	zval *_3;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *handleMethod, *_0, *_1, *_2, *params = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(params);
	array_init(params);

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 34);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_GET_CONSTANT(_2, "APP_RUN_MODE");
	zephir_array_fetch(&_1, _0, _2, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 114 TSRMLS_CC);
	ZEPHIR_INIT_VAR(handleMethod);
	ZEPHIR_CONCAT_SV(handleMethod, "exec", _1);
	ZEPHIR_CALL_FUNCTION(&params, "func_get_args", NULL, 35);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_3, this_ptr);
	zephir_array_fast_append(_3, handleMethod);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _3, params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Bootstrap, execModule) {

	zend_class_entry *_13;
	int ZEPHIR_LAST_CALL_STATUS;
	zend_bool needHandle;
	zval *uri = NULL, *needHandle_param = NULL, *moduleClass, *module, *_0, *_1, *_2, *_3, *_4, *_5, *_6, *_7, *_8 = NULL, *_9, *_10, *_11, *_12 = NULL, *_14, *_15, *_16 = NULL, *_17 = NULL, *router = NULL, *newUri, *_18, *_19, *_20 = NULL, *_21 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &uri, &needHandle_param);

	if (!uri) {
		uri = ZEPHIR_GLOBAL(global_null);
	}
	if (!needHandle_param) {
		needHandle = 1;
	} else {
		needHandle = zephir_get_boolval(needHandle_param);
	}


	if (!(needHandle)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 34);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("phalcon\\loader") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("loader"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, zephir_get_internal_ce(SS("phalcon\\mvc\\application") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("application"), _2 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _3, "setdi", NULL, 0, _4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_GET_CONSTANT(_5, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_VS(_6, _5, "default-web.php");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 32, _6);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_STRING(_8, "bootstrap", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _7, "setshared", NULL, 0, _8, this_ptr);
	zephir_check_temp_parameter(_8);
	zephir_check_call_status();
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	zephir_array_fetch_string(&_10, _9, SL("classPath"), PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 138 TSRMLS_CC);
	if (zephir_require_zval(_10 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(moduleClass);
	zephir_array_fetch_string(&moduleClass, _11, SL("className"), PH_NOISY, "phalconplus/Bootstrap.zep", 140 TSRMLS_CC);
	ZEPHIR_INIT_VAR(module);
	zephir_fetch_safe_class(_12, moduleClass);
	_13 = zend_fetch_class(Z_STRVAL_P(_12), Z_STRLEN_P(_12), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(module, _13);
	if (zephir_has_constructor(module TSRMLS_CC)) {
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, module, "__construct", NULL, 0, _14);
		zephir_check_call_status();
	}
	if (!(needHandle)) {
		RETURN_MM_BOOL(1);
	}

	/* try_start_1: */

		_15 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_16, _15, "handle", NULL, 0, uri);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_17, _16, "getcontent", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		zend_print_zval(_17, 0);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_NVAR(_8);
		ZEPHIR_CPY_WRT(_8, EG(exception));
		if (zephir_instance_of_ev(_8, zephir_get_internal_ce(SS("phalcon\\mvc\\application\\exception") TSRMLS_CC) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			_15 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_18);
			ZVAL_STRING(_18, "router", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&router, _15, "get", NULL, 0, _18);
			zephir_check_temp_parameter(_18);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_16, router, "getdefaultmodule", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_17, router, "getrewriteuri", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(newUri);
			ZEPHIR_CONCAT_SVV(newUri, "/", _16, _17);
			_19 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_20, _19, "handle", NULL, 0, newUri);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_21, _20, "getcontent", NULL, 0);
			zephir_check_call_status();
			zend_print_zval(_21, 0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, execSrv) {

	zend_class_entry *_9;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *needHandle_param = NULL, *backendSrv = NULL, *moduleClass, *moduleObj, *_0, *_1, *_2, *_3 = NULL, *_4, *_5, *_6, *_7, *_8 = NULL, *_10, *_11, *_12, *_13;
	zend_bool needHandle;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &needHandle_param);

	if (!needHandle_param) {
		needHandle = 1;
	} else {
		needHandle = zephir_get_boolval(needHandle_param);
	}
	ZEPHIR_INIT_VAR(backendSrv);
	ZVAL_NULL(backendSrv);


	if (!(needHandle)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 34);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("phalcon\\loader") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("loader"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "bootstrap", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "setshared", NULL, 0, _3, this_ptr);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZEPHIR_GET_CONSTANT(_3, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VS(_4, _3, "default-web.php");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 32, _4);
	zephir_check_call_status();
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	zephir_array_fetch_string(&_6, _5, SL("classPath"), PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 174 TSRMLS_CC);
	if (zephir_require_zval(_6 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(moduleClass);
	zephir_array_fetch_string(&moduleClass, _7, SL("className"), PH_NOISY, "phalconplus/Bootstrap.zep", 175 TSRMLS_CC);
	ZEPHIR_INIT_VAR(moduleObj);
	zephir_fetch_safe_class(_8, moduleClass);
	_9 = zend_fetch_class(Z_STRVAL_P(_8), Z_STRLEN_P(_8), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(moduleObj, _9);
	if (zephir_has_constructor(moduleObj TSRMLS_CC)) {
		_10 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, moduleObj, "__construct", NULL, 0, _10);
		zephir_check_call_status();
	}
	if (!(needHandle)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(backendSrv);
	object_init_ex(backendSrv, phalconplus_base_backendserver_ce);
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, backendSrv, "__construct", NULL, 36, _11);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_12);
	object_init_ex(_12, zephir_get_internal_ce(SS("yar_server") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _12, "__construct", NULL, 0, backendSrv);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("application"), _12 TSRMLS_CC);
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _13, "handle", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, execTask) {

	zend_class_entry *_13;
	zend_bool _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *argv_param = NULL, *di = NULL, *needHandle = NULL, *moduleClass, *module, *_0, *_2 = NULL, *_3, *_4, *_5, *_6, *_7, *_8, *_9, *_10, *_11, *_12 = NULL, *_14, *_15;
	zval *argv = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &argv_param, &di, &needHandle);

	zephir_get_arrval(argv, argv_param);
	if (!di) {
		di = ZEPHIR_GLOBAL(global_null);
	}
	if (!needHandle) {
		needHandle = ZEPHIR_GLOBAL(global_true);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 34);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("phalcon\\loader") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("loader"), _0 TSRMLS_CC);
	_1 = Z_TYPE_P(di) == IS_NULL;
	if (!(_1)) {
		_1 = !((zephir_instance_of_ev(di, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault\\cli") TSRMLS_CC) TSRMLS_CC)));
	}
	if (_1) {
		ZEPHIR_INIT_VAR(_2);
		object_init_ex(_2, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault\\cli") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("di"), _2 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("di"), di TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, zephir_get_internal_ce(SS("phalcon\\cli\\console") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("application"), _2 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _3, "setdi", NULL, 0, _4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_GET_CONSTANT(_5, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_VS(_6, _5, "default-cli.php");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 32, _6);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_STRING(_8, "bootstrap", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _7, "setshared", NULL, 0, _8, this_ptr);
	zephir_check_temp_parameter(_8);
	zephir_check_call_status();
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	zephir_array_fetch_string(&_10, _9, SL("classPath"), PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 209 TSRMLS_CC);
	if (zephir_require_zval(_10 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(moduleClass);
	zephir_array_fetch_string(&moduleClass, _11, SL("className"), PH_NOISY, "phalconplus/Bootstrap.zep", 210 TSRMLS_CC);
	ZEPHIR_INIT_VAR(module);
	zephir_fetch_safe_class(_12, moduleClass);
	_13 = zend_fetch_class(Z_STRVAL_P(_12), Z_STRLEN_P(_12), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(module, _13);
	if (zephir_has_constructor(module TSRMLS_CC)) {
		_14 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, module, "__construct", NULL, 0, _14);
		zephir_check_call_status();
	}
	if (!(zephir_is_true(needHandle))) {
		RETURN_MM_BOOL(1);
	}
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_15, "handle", NULL, 0, argv);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Bootstrap, dependModule) {

	zend_class_entry *_15;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *moduleName_param = NULL, *moduleConfPath, *moduleConf, *moduleClassName, *moduleClassPath, *moduleRunMode, *_0, *_1, *_2 = NULL, *_3 = NULL, *_4, *_5 = NULL, *_6, *_7, *_8, *_9, *_10, *_11, *_12, *_13, *_14 = NULL, *_16;
	zval *moduleName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	if (unlikely(Z_TYPE_P(moduleName_param) != IS_STRING && Z_TYPE_P(moduleName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(moduleName_param) == IS_STRING)) {
		zephir_get_strval(moduleName, moduleName_param);
	} else {
		ZEPHIR_INIT_VAR(moduleName);
		ZVAL_EMPTY_STRING(moduleName);
	}


	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "APP_ROOT_DIR");
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_GET_CONSTANT(_1, "APP_ENV");
	ZEPHIR_INIT_VAR(moduleConfPath);
	ZEPHIR_CONCAT_VSVSVS(moduleConfPath, _0, "/", moduleName, "/app/config/", _1, ".php");
	ZEPHIR_CALL_FUNCTION(&_2, "is_file", NULL, 31, moduleConfPath);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, zephir_get_internal_ce(SS("phalcon\\config\\exception") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SV(_4, "Module config file not exist, file position: ", moduleConfPath);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 0, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "phalconplus/Bootstrap.zep", 225 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(moduleConf);
	object_init_ex(moduleConf, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "load", NULL, 32, moduleConfPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, moduleConf, "__construct", NULL, 0, _5);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_6);
	zephir_read_property(&_6, moduleConf, SL("application"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(moduleRunMode);
	zephir_read_property(&moduleRunMode, _6, SL("mode"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_7);
	zephir_read_property(&_7, moduleConf, SL("application"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_8);
	zephir_read_property(&_8, _7, SL("ns"), PH_NOISY_CC);
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
	zephir_array_fetch(&_10, _9, moduleRunMode, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 231 TSRMLS_CC);
	ZEPHIR_INIT_VAR(moduleClassName);
	ZEPHIR_CONCAT_VV(moduleClassName, _8, _10);
	ZEPHIR_INIT_NVAR(_3);
	ZEPHIR_GET_CONSTANT(_3, "APP_ROOT_DIR");
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
	zephir_array_fetch(&_12, _11, moduleRunMode, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 232 TSRMLS_CC);
	ZEPHIR_INIT_VAR(moduleClassPath);
	ZEPHIR_CONCAT_VVSVS(moduleClassPath, _3, moduleName, "/app/", _12, ".php");
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, moduleConf, "merge", NULL, 0, _13);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setconfig", NULL, 37, moduleConf);
	zephir_check_call_status();
	if (zephir_require_zval(moduleClassPath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	zephir_fetch_safe_class(_14, moduleClassName);
	_15 = zend_fetch_class(Z_STRVAL_P(_14), Z_STRLEN_P(_14), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _15);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		_16 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _16);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Bootstrap, getEnv) {


	RETURN_MEMBER(this_ptr, "env");

}

PHP_METHOD(PhalconPlus_Bootstrap, getConfig) {


	RETURN_MEMBER(this_ptr, "config");

}

PHP_METHOD(PhalconPlus_Bootstrap, setConfig) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *config, *globalConf = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3, *_4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &config);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, _0, "has", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_INIT_VAR(globalConf);
		object_init_ex(globalConf, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, globalConf, "__construct", NULL, 0);
		zephir_check_call_status();
	} else {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&globalConf, _3, "getconfig", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, globalConf, "merge", NULL, 0, config);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("config"), globalConf TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _3, "set", NULL, 0, _2, _4);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Bootstrap, getDI) {


	RETURN_MEMBER(this_ptr, "di");

}

PHP_METHOD(PhalconPlus_Bootstrap, load) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;
	zval *filePath, *_1, *_2 = NULL, *_3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath);



	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 6, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_GET_CONSTANT(_1, "APP_ROOT_DIR");
	zephir_array_update_string(&_0, SL("rootPath"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("loader"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("loader"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("config"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("config"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("application"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("application"), &_2, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("bootstrap"), &this_ptr, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("di"), PH_NOISY_CC);
	zephir_array_update_string(&_0, SL("di"), &_2, PH_COPY | PH_SEPARATE);
	Z_SET_ISREF_P(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "extract", NULL, 38, _0);
	Z_UNSET_ISREF_P(_0);
	zephir_check_call_status();
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_3);
	if (zephir_require_zval_ret(&_3, filePath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(_3);

}

static void zephir_init_properties(zval *this_ptr TSRMLS_DC) {

	zval *_0, *_1;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_0, SS("Web"), SL("Module"), 1);
	add_assoc_stringl_ex(_0, SS("Cli"), SL("Task"), 1);
	add_assoc_stringl_ex(_0, SS("Srv"), SL("Srv"), 1);
	add_assoc_stringl_ex(_0, SS("Micro"), SL("Micro"), 1);
	zephir_update_property_this(this_ptr, SL("modeMap"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(_1, SS("classPath"), SL(""), 1);
	add_assoc_stringl_ex(_1, SS("className"), SL(""), 1);
	add_assoc_stringl_ex(_1, SS("mode"), SL(""), 1);
	zephir_update_property_this(this_ptr, SL("module"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

