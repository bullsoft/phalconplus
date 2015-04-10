
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
#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
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

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_8 = NULL, *_11 = NULL, *_16 = NULL;
	zval *_0, *_1;
	zval *modulePath_param = NULL, *_2 = NULL, *_4 = NULL, *env = NULL, _7 = zval_used_for_init, *_9, *debug, *_10, *_12, _13 = zval_used_for_init, *_14, *_15 = NULL, *_17, _18 = zval_used_for_init, *_19, *_20, *_21, *_22, *_23, *_24, *_25, *_26;
	zval *modulePath = NULL, *_5;

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
	ZEPHIR_CALL_FUNCTION(&_2, "is_dir", &_3, modulePath);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		ZEPHIR_INIT_VAR(_4);
		object_init_ex(_4, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CONCAT_SV(_5, "Module directory not exists or not a dir, file positon: ", modulePath);
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", &_6, _5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4, "phalconplus/Bootstrap.zep", 40 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "phalconplus.env", 0);
	ZEPHIR_CALL_FUNCTION(&env, "get_cfg_var", &_8, &_7);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(env))) {
		zephir_update_property_this(this_ptr, SL("env"), env TSRMLS_CC);
	}
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
	if (!ZEPHIR_IS_STRING(_9, "product")) {
		ZEPHIR_INIT_VAR(debug);
		object_init_ex(debug, zephir_get_internal_ce(SS("phalcon\\debug") TSRMLS_CC));
		if (zephir_has_constructor(debug TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, debug, "__construct", NULL);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, debug, "listen", NULL);
		zephir_check_call_status();
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
	ZEPHIR_SINIT_NVAR(_7);
	ZVAL_STRING(&_7, "APP_ENV", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_11, &_7, _10, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_4);
	ZEPHIR_SINIT_NVAR(_7);
	ZVAL_STRING(&_7, "/", 0);
	zephir_fast_trim(_4, modulePath, &_7, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_12);
	ZEPHIR_CONCAT_VS(_12, _4, "/");
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_STRING(&_13, "APP_MODULE_DIR", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_11, &_13, _12, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_14);
	ZEPHIR_CALL_FUNCTION(&_15, "dirname", &_16, modulePath);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_13);
	ZVAL_STRING(&_13, "/", 0);
	zephir_fast_trim(_14, _15, &_13, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_17);
	ZEPHIR_CONCAT_VS(_17, _14, "/");
	ZEPHIR_SINIT_VAR(_18);
	ZVAL_STRING(&_18, "APP_ROOT_DIR", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_11, &_18, _17, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_19);
	ZEPHIR_GET_CONSTANT(_19, "APP_ROOT_DIR");
	ZEPHIR_INIT_VAR(_20);
	ZEPHIR_CONCAT_VSS(_20, _19, "public", "/");
	ZEPHIR_SINIT_NVAR(_18);
	ZVAL_STRING(&_18, "APP_ROOT_PUB_DIR", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_11, &_18, _20, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_21);
	ZEPHIR_GET_CONSTANT(_21, "APP_ROOT_DIR");
	ZEPHIR_INIT_VAR(_22);
	ZEPHIR_CONCAT_VSS(_22, _21, "common", "/");
	ZEPHIR_SINIT_NVAR(_18);
	ZVAL_STRING(&_18, "APP_ROOT_COMMON_DIR", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_11, &_18, _22, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_23);
	ZEPHIR_GET_CONSTANT(_23, "APP_ROOT_COMMON_DIR");
	ZEPHIR_INIT_VAR(_24);
	ZEPHIR_CONCAT_VSS(_24, _23, "config", "/");
	ZEPHIR_SINIT_NVAR(_18);
	ZVAL_STRING(&_18, "APP_ROOT_COMMON_CONF_DIR", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_11, &_18, _24, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_25);
	ZEPHIR_GET_CONSTANT(_25, "APP_ROOT_COMMON_DIR");
	ZEPHIR_INIT_VAR(_26);
	ZEPHIR_CONCAT_VSS(_26, _25, "load", "/");
	ZEPHIR_SINIT_NVAR(_18);
	ZVAL_STRING(&_18, "APP_ROOT_COMMON_LOAD_DIR", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_11, &_18, _26, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, setModule) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *module_param = NULL, *diff = NULL, *_0;
	zval *module = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module_param);

	zephir_get_arrval(module, module_param);
	ZEPHIR_INIT_VAR(diff);
	array_init(diff);


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&diff, "array_diff_key", &_1, _0, module);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(diff))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Module is is not a legal module", "phalconplus/Bootstrap.zep", 72);
		return;
	}
	zephir_update_property_this(this_ptr, SL("module"), module TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, initConf) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL, *_6 = NULL, *_26 = NULL, *_27 = NULL;
	zval *globalConfPath, *moduleConfPath, *moduleConf, *_0, *_1 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_7, *_8, *_9 = NULL, *_10 = NULL, *_11 = NULL, *module, *_12, *_13, *_14, *_15, *_16, *_17, *_18, *_19, *_20, *_21, *_22, *_23, *_24, _25, *_28;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(module);
	array_init(module);

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "APP_ROOT_COMMON_CONF_DIR");
	ZEPHIR_INIT_VAR(globalConfPath);
	ZEPHIR_CONCAT_VS(globalConfPath, _0, "config.php");
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", &_2, globalConfPath);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, zephir_get_internal_ce(SS("phalcon\\config\\exception") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_4);
		ZEPHIR_CONCAT_SV(_4, "Global config file not exist, file position: ", globalConfPath);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "phalconplus/Bootstrap.zep", 85 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_NVAR(_3);
	object_init_ex(_3, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "load", &_6, globalConfPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, _5);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("config"), _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_GET_CONSTANT(_7, "APP_MODULE_DIR");
	ZEPHIR_INIT_VAR(_8);
	ZEPHIR_GET_CONSTANT(_8, "APP_ENV");
	ZEPHIR_INIT_VAR(moduleConfPath);
	ZEPHIR_CONCAT_VSVS(moduleConfPath, _7, "/app/config/", _8, ".php");
	ZEPHIR_CALL_FUNCTION(&_9, "is_file", &_2, moduleConfPath);
	zephir_check_call_status();
	if (!(zephir_is_true(_9))) {
		ZEPHIR_INIT_VAR(_10);
		object_init_ex(_10, zephir_get_internal_ce(SS("phalcon\\config\\exception") TSRMLS_CC));
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_SV(_4, "Module config file not exist, file position: ", moduleConfPath);
		ZEPHIR_CALL_METHOD(NULL, _10, "__construct", NULL, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_10, "phalconplus/Bootstrap.zep", 92 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(moduleConf);
	object_init_ex(moduleConf, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "load", &_6, moduleConfPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, moduleConf, "__construct", NULL, _11);
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
	zephir_array_fetch_string(&_18, module, SL("mode"), PH_NOISY, "phalconplus/Bootstrap.zep", 99 TSRMLS_CC);
	zephir_array_fetch(&_17, _16, _18, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 99 TSRMLS_CC);
	ZEPHIR_INIT_LNVAR(_4);
	ZEPHIR_CONCAT_VV(_4, _15, _17);
	zephir_array_update_string(&module, SL("className"), &_4, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_19);
	ZEPHIR_GET_CONSTANT(_19, "APP_MODULE_DIR");
	_20 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_22);
	zephir_array_fetch_string(&_22, module, SL("mode"), PH_NOISY, "phalconplus/Bootstrap.zep", 100 TSRMLS_CC);
	zephir_array_fetch(&_21, _20, _22, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 100 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_23);
	ZEPHIR_CONCAT_VSVS(_23, _19, "app/", _21, ".php");
	zephir_array_update_string(&module, SL("classPath"), &_23, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_24, module, SL("mode"), PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 103 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_25);
	ZVAL_STRING(&_25, "APP_RUN_MODE", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_26, &_25, _24, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmodule", &_27, module);
	zephir_check_call_status();
	_28 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _28, "merge", NULL, moduleConf);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, exec) {

	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *argv = NULL, *handleMethod, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &argv);

	if (!argv) {
		argv = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", &_0);
	zephir_check_call_status();
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_GET_CONSTANT(_3, "APP_RUN_MODE");
	zephir_array_fetch(&_2, _1, _3, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 115 TSRMLS_CC);
	ZEPHIR_INIT_VAR(handleMethod);
	ZEPHIR_CONCAT_SV(handleMethod, "exec", _2);
	ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, handleMethod, NULL, argv);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, execModule) {

	zend_class_entry *_14;
	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *uri = NULL, *moduleClass, *module, *_0, *_1, *_2, *_3, *_4, *_5, *_6, *_8, *_9 = NULL, *_10, *_11, *_12, *_13 = NULL, *_15, *_16, *_17 = NULL, *_18 = NULL, *router = NULL, *newUri, *_19, *_20, *_21 = NULL, *_22 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri);

	if (!uri) {
		uri = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("phalcon\\loader") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("loader"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), _1 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, zephir_get_internal_ce(SS("phalcon\\mvc\\application") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("application"), _2 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _3, "setdi", NULL, _4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_GET_CONSTANT(_5, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_VS(_6, _5, "default-web.php");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", &_7, _6);
	zephir_check_call_status();
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_9);
	ZVAL_STRING(_9, "bootstrap", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _8, "setshared", NULL, _9, this_ptr);
	zephir_check_temp_parameter(_9);
	zephir_check_call_status();
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	zephir_array_fetch_string(&_11, _10, SL("classPath"), PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 133 TSRMLS_CC);
	if (zephir_require_zval(_11 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(moduleClass);
	zephir_array_fetch_string(&moduleClass, _12, SL("className"), PH_NOISY, "phalconplus/Bootstrap.zep", 135 TSRMLS_CC);
	ZEPHIR_INIT_VAR(module);
	zephir_fetch_safe_class(_13, moduleClass);
	_14 = zend_fetch_class(Z_STRVAL_P(_13), Z_STRLEN_P(_13), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(module, _14);
	if (zephir_has_constructor(module TSRMLS_CC)) {
		_15 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, module, "__construct", NULL, _15);
		zephir_check_call_status();
	}

	/* try_start_1: */

		_16 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_17, _16, "handle", NULL, uri);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_18, _17, "getcontent", NULL);
		zephir_check_call_status_or_jump(try_end_1);
		zend_print_zval(_18, 0);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_NVAR(_9);
		ZEPHIR_CPY_WRT(_9, EG(exception));
		if (zephir_instance_of_ev(_9, zephir_get_internal_ce(SS("phalcon\\mvc\\application\\exception") TSRMLS_CC) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			_16 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_19);
			ZVAL_STRING(_19, "router", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&router, _16, "get", NULL, _19);
			zephir_check_temp_parameter(_19);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_17, router, "getdefaultmodule", NULL);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_18, router, "getrewriteuri", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(newUri);
			ZEPHIR_CONCAT_SVV(newUri, "/", _17, _18);
			_20 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_21, _20, "handle", NULL, newUri);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_22, _21, "getcontent", NULL);
			zephir_check_call_status();
			zend_print_zval(_22, 0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, execSrv) {

	zend_class_entry *_10;
	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_13 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *backendSrv = NULL, *moduleClass, *moduleObj, *_0, *_1, *_2, *_3 = NULL, *_4, *_6, *_7, *_8, *_9 = NULL, *_11, *_12, *_14, *_15;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(backendSrv);
	ZVAL_NULL(backendSrv);

	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("phalcon\\loader") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("loader"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("di"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "bootstrap", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "setshared", NULL, _3, this_ptr);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_3);
	ZEPHIR_GET_CONSTANT(_3, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_CONCAT_VS(_4, _3, "default-web.php");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", &_5, _4);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	zephir_array_fetch_string(&_7, _6, SL("classPath"), PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 161 TSRMLS_CC);
	if (zephir_require_zval(_7 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(moduleClass);
	zephir_array_fetch_string(&moduleClass, _8, SL("className"), PH_NOISY, "phalconplus/Bootstrap.zep", 162 TSRMLS_CC);
	ZEPHIR_INIT_VAR(moduleObj);
	zephir_fetch_safe_class(_9, moduleClass);
	_10 = zend_fetch_class(Z_STRVAL_P(_9), Z_STRLEN_P(_9), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(moduleObj, _10);
	if (zephir_has_constructor(moduleObj TSRMLS_CC)) {
		_11 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, moduleObj, "__construct", NULL, _11);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(backendSrv);
	object_init_ex(backendSrv, phalconplus_base_backendserver_ce);
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, backendSrv, "__construct", &_13, _12);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_14);
	object_init_ex(_14, zephir_get_internal_ce(SS("yar_server") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _14, "__construct", NULL, backendSrv);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("application"), _14 TSRMLS_CC);
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _15, "handle", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, execTask) {

	zend_class_entry *_15;
	zend_bool _2;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *argv_param = NULL, *di = NULL, *moduleClass, *module, *_1, *_3 = NULL, *_4, *_5, *_6, *_7, *_9, *_10, *_11, *_12, *_13, *_14 = NULL, *_16, *_17;
	zval *argv = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &argv_param, &di);

	zephir_get_arrval(argv, argv_param);
	if (!di) {
		di = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zephir_get_internal_ce(SS("phalcon\\loader") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("loader"), _1 TSRMLS_CC);
	_2 = Z_TYPE_P(di) == IS_NULL;
	if (!(_2)) {
		_2 = !((zephir_instance_of_ev(di, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault\\cli") TSRMLS_CC) TSRMLS_CC)));
	}
	if (_2) {
		ZEPHIR_INIT_VAR(_3);
		object_init_ex(_3, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault\\cli") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL);
		zephir_check_call_status();
		zephir_update_property_this(this_ptr, SL("di"), _3 TSRMLS_CC);
	} else {
		zephir_update_property_this(this_ptr, SL("di"), di TSRMLS_CC);
	}
	ZEPHIR_INIT_NVAR(_3);
	object_init_ex(_3, zephir_get_internal_ce(SS("phalcon\\cli\\console") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("application"), _3 TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _4, "setdi", NULL, _5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_GET_CONSTANT(_6, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_INIT_VAR(_7);
	ZEPHIR_CONCAT_VS(_7, _6, "default-cli.php");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", &_8, _7);
	zephir_check_call_status();
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_10);
	ZVAL_STRING(_10, "bootstrap", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _9, "setshared", NULL, _10, this_ptr);
	zephir_check_temp_parameter(_10);
	zephir_check_call_status();
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	zephir_array_fetch_string(&_12, _11, SL("classPath"), PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 191 TSRMLS_CC);
	if (zephir_require_zval(_12 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(moduleClass);
	zephir_array_fetch_string(&moduleClass, _13, SL("className"), PH_NOISY, "phalconplus/Bootstrap.zep", 192 TSRMLS_CC);
	ZEPHIR_INIT_VAR(module);
	zephir_fetch_safe_class(_14, moduleClass);
	_15 = zend_fetch_class(Z_STRVAL_P(_14), Z_STRLEN_P(_14), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(module, _15);
	if (zephir_has_constructor(module TSRMLS_CC)) {
		_16 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, module, "__construct", NULL, _16);
		zephir_check_call_status();
	}
	_17 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _17, "handle", NULL, argv);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, dependModule) {

	zend_class_entry *_18;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL, *_7 = NULL, *_16 = NULL;
	zval *moduleName_param = NULL, *moduleConfPath, *moduleConf, *moduleClassName, *moduleClassPath, *moduleRunMode, *_0, *_1, *_2 = NULL, *_4 = NULL, *_5, *_6 = NULL, *_8, *_9, *_10, *_11, *_12, *_13, *_14, *_15, *_17 = NULL, *_19;
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
	ZEPHIR_CALL_FUNCTION(&_2, "is_file", &_3, moduleConfPath);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		ZEPHIR_INIT_VAR(_4);
		object_init_ex(_4, zephir_get_internal_ce(SS("phalcon\\config\\exception") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_5);
		ZEPHIR_CONCAT_SV(_5, "Module config file not exist, file position: ", moduleConfPath);
		ZEPHIR_CALL_METHOD(NULL, _4, "__construct", NULL, _5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4, "phalconplus/Bootstrap.zep", 203 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(moduleConf);
	object_init_ex(moduleConf, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(&_6, this_ptr, "load", &_7, moduleConfPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, moduleConf, "__construct", NULL, _6);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_8);
	zephir_read_property(&_8, moduleConf, SL("application"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(moduleRunMode);
	zephir_read_property(&moduleRunMode, _8, SL("mode"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_9);
	zephir_read_property(&_9, moduleConf, SL("application"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_10);
	zephir_read_property(&_10, _9, SL("ns"), PH_NOISY_CC);
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
	zephir_array_fetch(&_12, _11, moduleRunMode, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 209 TSRMLS_CC);
	ZEPHIR_INIT_VAR(moduleClassName);
	ZEPHIR_CONCAT_VV(moduleClassName, _10, _12);
	ZEPHIR_INIT_NVAR(_4);
	ZEPHIR_GET_CONSTANT(_4, "APP_ROOT_DIR");
	_13 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
	zephir_array_fetch(&_14, _13, moduleRunMode, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 210 TSRMLS_CC);
	ZEPHIR_INIT_VAR(moduleClassPath);
	ZEPHIR_CONCAT_VVSVS(moduleClassPath, _4, moduleName, "/app/", _14, ".php");
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, moduleConf, "merge", NULL, _15);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setconfig", &_16, moduleConf);
	zephir_check_call_status();
	if (zephir_require_zval(moduleClassPath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	zephir_fetch_safe_class(_17, moduleClassName);
	_18 = zend_fetch_class(Z_STRVAL_P(_17), Z_STRLEN_P(_17), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _18);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		_19 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _19);
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
	ZEPHIR_CALL_METHOD(&_1, _0, "has", NULL, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_INIT_VAR(globalConf);
		object_init_ex(globalConf, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, globalConf, "__construct", NULL);
		zephir_check_call_status();
	} else {
		_3 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&globalConf, _3, "getconfig", NULL);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, globalConf, "merge", NULL, config);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("config"), globalConf TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _3, "set", NULL, _2, _4);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Bootstrap, getDI) {


	RETURN_MEMBER(this_ptr, "di");

}

PHP_METHOD(PhalconPlus_Bootstrap, load) {

	zval *filePath, *_0, *_1 = NULL, *_2, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6 = NULL, *_7 = NULL, *_8 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath);



	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "APP_ROOT_DIR");
	ZEPHIR_CPY_WRT(_1, _0);
	if (zephir_set_symbol_str(SS("rootPath"), _1 TSRMLS_CC) == FAILURE){
	  return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("loader"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(_3, _2);
	if (zephir_set_symbol_str(SS("loader"), _3 TSRMLS_CC) == FAILURE){
	  return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(_4, _2);
	if (zephir_set_symbol_str(SS("config"), _4 TSRMLS_CC) == FAILURE){
	  return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(_5, _2);
	if (zephir_set_symbol_str(SS("application"), _5 TSRMLS_CC) == FAILURE){
	  return;
	}
	ZEPHIR_CPY_WRT(_6, this_ptr);
	if (zephir_set_symbol_str(SS("bootstrap"), _6 TSRMLS_CC) == FAILURE){
	  return;
	}
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(_7, _2);
	if (zephir_set_symbol_str(SS("di"), _7 TSRMLS_CC) == FAILURE){
	  return;
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_8);
	if (zephir_require_zval_ret(&_8, filePath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(_8);

}

