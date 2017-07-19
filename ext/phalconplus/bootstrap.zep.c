
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
	zend_declare_class_constant_string(phalconplus_bootstrap_ce, SL("COMMON_DIR_NAME"), "common" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_bootstrap_ce, SL("COMMON_CONF_DIR_NAME"), "config" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_bootstrap_ce, SL("COMMON_LOAD_DIR_NAME"), "load" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_bootstrap_ce, SL("ROOT_PUB_DIR_NAME"), "public" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_bootstrap_ce, SL("MODULE_APP_DIR_NAME"), "app" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_bootstrap_ce, SL("DS"), "/" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_bootstrap_ce, SL("PHP_EXT"), ".php" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_bootstrap_ce, SL("ENV_NAME"), "phalconplus.env" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Bootstrap, __construct) {

	zend_bool _7;
	zephir_fcall_cache_entry *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *modulePath_param = NULL, *_0 = NULL, *env = NULL, _3 = zval_used_for_init, *_4, _5, *_6, *_8, _9, _10, *_11, *_12, _13 = zval_used_for_init, *_15, *_16, _17 = zval_used_for_init, *_18, *_19 = NULL, *_20, _21 = zval_used_for_init, *_22, *_23, *_24, *_25, *_26, *_27, *_1$$3, *debug$$5 = NULL;
	zval *modulePath = NULL, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &modulePath_param);

	if (UNEXPECTED(Z_TYPE_P(modulePath_param) != IS_STRING && Z_TYPE_P(modulePath_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'modulePath' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(modulePath_param) == IS_STRING)) {
		zephir_get_strval(modulePath, modulePath_param);
	} else {
		ZEPHIR_INIT_VAR(modulePath);
		ZVAL_EMPTY_STRING(modulePath);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 41, modulePath);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SV(_2$$3, "Module directory not exists or not a dir, file positon: ", modulePath);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 7, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalconplus/Bootstrap.zep", 49 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "phalconplus.env", 0);
	ZEPHIR_CALL_FUNCTION(&env, "get_cfg_var", NULL, 42, &_3);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(env))) {
		zephir_update_property_this(getThis(), SL("env"), env TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_GET_CONSTANT(_4, "PHP_SAPI");
	ZEPHIR_SINIT_NVAR(_3);
	ZVAL_LONG(&_3, 0);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 3);
	ZEPHIR_INIT_VAR(_6);
	zephir_substr(_6, _4, 0 , 3 , 0);
	_7 = !ZEPHIR_IS_STRING(_6, "cli");
	if (_7) {
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
		ZEPHIR_SINIT_VAR(_9);
		ZVAL_LONG(&_9, 0);
		ZEPHIR_SINIT_VAR(_10);
		ZVAL_LONG(&_10, 7);
		ZEPHIR_INIT_VAR(_11);
		zephir_substr(_11, _8, 0 , 7 , 0);
		_7 = !ZEPHIR_IS_STRING(_11, "product");
	}
	if (_7) {
		ZEPHIR_INIT_VAR(debug$$5);
		object_init_ex(debug$$5, zephir_get_internal_ce(SS("phalcon\\debug") TSRMLS_CC));
		if (zephir_has_constructor(debug$$5 TSRMLS_CC)) {
			ZEPHIR_CALL_METHOD(NULL, debug$$5, "__construct", NULL, 0);
			zephir_check_call_status();
		}
		ZEPHIR_CALL_METHOD(NULL, debug$$5, "listen", NULL, 0);
		zephir_check_call_status();
	}
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("env"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_13);
	ZVAL_STRING(&_13, "APP_ENV", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 43, &_13, _12, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_15);
	ZEPHIR_SINIT_NVAR(_13);
	ZVAL_STRING(&_13, "/", 0);
	zephir_fast_trim(_15, modulePath, &_13, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_16);
	ZEPHIR_CONCAT_VS(_16, _15, "/");
	ZEPHIR_SINIT_VAR(_17);
	ZVAL_STRING(&_17, "APP_MODULE_DIR", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 43, &_17, _16, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_18);
	ZEPHIR_CALL_FUNCTION(&_19, "dirname", NULL, 44, modulePath);
	zephir_check_call_status();
	ZEPHIR_SINIT_NVAR(_17);
	ZVAL_STRING(&_17, "/", 0);
	zephir_fast_trim(_18, _19, &_17, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	ZEPHIR_INIT_VAR(_20);
	ZEPHIR_CONCAT_VS(_20, _18, "/");
	ZEPHIR_SINIT_VAR(_21);
	ZVAL_STRING(&_21, "APP_ROOT_DIR", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 43, &_21, _20, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_22);
	ZEPHIR_GET_CONSTANT(_22, "APP_ROOT_DIR");
	ZEPHIR_INIT_VAR(_23);
	ZEPHIR_CONCAT_VSS(_23, _22, "common", "/");
	ZEPHIR_SINIT_NVAR(_21);
	ZVAL_STRING(&_21, "APP_ROOT_COMMON_DIR", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 43, &_21, _23, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_24);
	ZEPHIR_GET_CONSTANT(_24, "APP_ROOT_COMMON_DIR");
	ZEPHIR_INIT_VAR(_25);
	ZEPHIR_CONCAT_VSS(_25, _24, "config", "/");
	ZEPHIR_SINIT_NVAR(_21);
	ZVAL_STRING(&_21, "APP_ROOT_COMMON_CONF_DIR", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 43, &_21, _25, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_26);
	ZEPHIR_GET_CONSTANT(_26, "APP_ROOT_COMMON_DIR");
	ZEPHIR_INIT_VAR(_27);
	ZEPHIR_CONCAT_VSS(_27, _26, "load", "/");
	ZEPHIR_SINIT_NVAR(_21);
	ZVAL_STRING(&_21, "APP_ROOT_COMMON_LOAD_DIR", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", &_14, 43, &_21, _27, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, setModule) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *module_param = NULL, *diff = NULL, *_0, *_1$$3, *_2$$3, *_3$$3;
	zval *module = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &module_param);

	zephir_get_arrval(module, module_param);


	ZEPHIR_INIT_VAR(diff);
	array_init(diff);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&diff, "array_diff_key", NULL, 45, _0, module);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(diff))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_json_encode(_2$$3, &(_2$$3), module, 0  TSRMLS_CC);
		ZEPHIR_INIT_VAR(_3$$3);
		ZEPHIR_CONCAT_SV(_3$$3, "Module is not a legal module, details: ", _2$$3);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 7, _3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalconplus/Bootstrap.zep", 79 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(getThis(), SL("module"), module TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, initConf) {

	zval *globalConfPath = NULL, *moduleConfPath = NULL, *moduleConf = NULL, *_0, *_1 = NULL, *_6, *_7 = NULL, *_10, *_11, *_12 = NULL, *_17 = NULL, *module = NULL, *_18, *_19, *_20, *_21, *_22, *_23, *_24, *_25, *_26, *_27, *_28, *_29, *_30, *_31, *_32, *_33, _34, *_35, *_3$$3, *_4$$3, *_13$$4, *_14$$4 = NULL, *_15$$5, *_16$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL, *_8 = NULL, *_9 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	ZEPHIR_GET_CONSTANT(_0, "APP_ROOT_COMMON_CONF_DIR");
	ZEPHIR_INIT_VAR(globalConfPath);
	ZEPHIR_CONCAT_VSS(globalConfPath, _0, "config", ".php");
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", &_2, 46, globalConfPath);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_INIT_VAR(_3$$3);
		object_init_ex(_3$$3, zephir_get_internal_ce(SS("phalcon\\config\\exception") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_CONCAT_SV(_4$$3, "Global config file not exist, file position: ", globalConfPath);
		ZEPHIR_CALL_METHOD(NULL, _3$$3, "__construct", &_5, 0, _4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3$$3, "phalconplus/Bootstrap.zep", 92 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_6);
	object_init_ex(_6, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(&_7, this_ptr, "load", &_8, 47, globalConfPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _6, "__construct", &_9, 0, _7);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("config"), _6 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_10);
	ZEPHIR_GET_CONSTANT(_10, "APP_MODULE_DIR");
	ZEPHIR_INIT_VAR(_11);
	ZEPHIR_GET_CONSTANT(_11, "APP_ENV");
	ZEPHIR_INIT_VAR(moduleConfPath);
	ZEPHIR_CONCAT_VSVS(moduleConfPath, _10, "app/config/", _11, ".php");
	ZEPHIR_CALL_FUNCTION(&_12, "is_file", &_2, 46, moduleConfPath);
	zephir_check_call_status();
	if (!(zephir_is_true(_12))) {
		ZEPHIR_INIT_VAR(_13$$4);
		ZEPHIR_GET_CONSTANT(_13$$4, "APP_MODULE_DIR");
		ZEPHIR_INIT_NVAR(moduleConfPath);
		ZEPHIR_CONCAT_VSS(moduleConfPath, _13$$4, "app/config/config", ".php");
		ZEPHIR_CALL_FUNCTION(&_14$$4, "is_file", &_2, 46, moduleConfPath);
		zephir_check_call_status();
		if (!(zephir_is_true(_14$$4))) {
			ZEPHIR_INIT_VAR(_15$$5);
			object_init_ex(_15$$5, zephir_get_internal_ce(SS("phalcon\\config\\exception") TSRMLS_CC));
			ZEPHIR_INIT_VAR(_16$$5);
			ZEPHIR_CONCAT_SV(_16$$5, "Module config file not exist, file position: ", moduleConfPath);
			ZEPHIR_CALL_METHOD(NULL, _15$$5, "__construct", &_5, 0, _16$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(_15$$5, "phalconplus/Bootstrap.zep", 101 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(moduleConf);
	object_init_ex(moduleConf, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(&_17, this_ptr, "load", &_8, 47, moduleConfPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, moduleConf, "__construct", &_9, 0, _17);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(module);
	array_init(module);
	ZEPHIR_INIT_VAR(_18);
	ZEPHIR_INIT_VAR(_19);
	ZEPHIR_OBS_VAR(_20);
	zephir_read_property(&_20, moduleConf, SL("application"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_21);
	zephir_read_property(&_21, _20, SL("mode"), PH_NOISY_CC);
	zephir_fast_strtolower(_19, _21);
	zephir_ucfirst(_18, _19);
	zephir_array_update_string(&module, SL("mode"), &_18, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_VAR(_22);
	zephir_read_property(&_22, moduleConf, SL("application"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_23);
	zephir_read_property(&_23, _22, SL("ns"), PH_NOISY_CC);
	_24 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_26);
	zephir_array_fetch_string(&_26, module, SL("mode"), PH_NOISY, "phalconplus/Bootstrap.zep", 110 TSRMLS_CC);
	zephir_array_fetch(&_25, _24, _26, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 110 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_27);
	ZEPHIR_CONCAT_VV(_27, _23, _25);
	zephir_array_update_string(&module, SL("className"), &_27, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(_28);
	ZEPHIR_GET_CONSTANT(_28, "APP_MODULE_DIR");
	_29 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_31);
	zephir_array_fetch_string(&_31, module, SL("mode"), PH_NOISY, "phalconplus/Bootstrap.zep", 111 TSRMLS_CC);
	zephir_array_fetch(&_30, _29, _31, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 111 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_32);
	ZEPHIR_CONCAT_VSVS(_32, _28, "app/", _30, ".php");
	zephir_array_update_string(&module, SL("classPath"), &_32, PH_COPY | PH_SEPARATE);
	zephir_array_fetch_string(&_33, module, SL("mode"), PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 114 TSRMLS_CC);
	ZEPHIR_SINIT_VAR(_34);
	ZVAL_STRING(&_34, "APP_RUN_MODE", 0);
	ZEPHIR_CALL_FUNCTION(NULL, "define", NULL, 43, &_34, _33, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setmodule", NULL, 48, module);
	zephir_check_call_status();
	_35 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _35, "merge", NULL, 0, moduleConf);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, exec) {

	zval *_3;
	zval *handleMethod = NULL, *_0, *_1, *_2, *params = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 49);
	zephir_check_call_status();
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZEPHIR_GET_CONSTANT(_2, "APP_RUN_MODE");
	zephir_array_fetch(&_1, _0, _2, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 126 TSRMLS_CC);
	ZEPHIR_INIT_VAR(handleMethod);
	ZEPHIR_CONCAT_SV(handleMethod, "exec", _1);
	ZEPHIR_INIT_VAR(params);
	array_init(params);
	ZEPHIR_INIT_NVAR(params);
	zephir_get_args(params TSRMLS_CC);
	ZEPHIR_INIT_VAR(_3);
	zephir_create_array(_3, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(_3, this_ptr);
	zephir_array_fast_append(_3, handleMethod);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, _3, params);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Bootstrap, execModule) {

	zend_class_entry *_12;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool needHandle;
	zval *uri = NULL, *needHandle_param = NULL, *moduleClass = NULL, *module = NULL, *_0, *_1, *_2, *_3, *_4, *_5, *_6, *_7 = NULL, *_8, *_9, *_10, *_11 = NULL, *_13, *_17 = NULL, *_14$$5, *_15$$5 = NULL, *_16$$5 = NULL, *router$$6 = NULL, *newUri$$6 = NULL, *_18$$6, *_19$$6, *_20$$6 = NULL, *_21$$6 = NULL, *_22$$6, *_23$$6 = NULL, *_24$$6 = NULL;

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
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 49);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("di"), _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	object_init_ex(_1, zephir_get_internal_ce(SS("phalcon\\mvc\\application") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("application"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _2, "setdi", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_4);
	ZEPHIR_GET_CONSTANT(_4, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_CONCAT_VS(_5, _4, "default-web.php");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 47, _5);
	zephir_check_call_status();
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_7);
	ZVAL_STRING(_7, "bootstrap", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _6, "setshared", NULL, 0, _7, this_ptr);
	zephir_check_temp_parameter(_7);
	zephir_check_call_status();
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	zephir_array_fetch_string(&_9, _8, SL("classPath"), PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 150 TSRMLS_CC);
	if (zephir_require_zval(_9 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(moduleClass);
	zephir_array_fetch_string(&moduleClass, _10, SL("className"), PH_NOISY, "phalconplus/Bootstrap.zep", 152 TSRMLS_CC);
	ZEPHIR_INIT_VAR(module);
	zephir_fetch_safe_class(_11, moduleClass);
		_12 = zend_fetch_class(Z_STRVAL_P(_11), Z_STRLEN_P(_11), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(module, _12);
	if (zephir_has_constructor(module TSRMLS_CC)) {
		_13 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, module, "__construct", NULL, 0, _13);
		zephir_check_call_status();
	}
	if (!(needHandle)) {
		RETURN_MM_BOOL(1);
	}

	/* try_start_1: */

		_14$$5 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_15$$5, _14$$5, "handle", NULL, 0, uri);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_16$$5, _15$$5, "getcontent", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		zend_print_zval(_16$$5, 0);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_NVAR(_7);
		ZEPHIR_CPY_WRT(_7, EG(exception));
		ZEPHIR_INIT_VAR(_17);
		if (zephir_instance_of_ev(_7, zephir_get_internal_ce(SS("phalcon\\mvc\\application\\exception") TSRMLS_CC) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(_17, _7);
			_18$$6 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
			ZEPHIR_INIT_VAR(_19$$6);
			ZVAL_STRING(_19$$6, "router", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&router$$6, _18$$6, "get", NULL, 0, _19$$6);
			zephir_check_temp_parameter(_19$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_20$$6, router$$6, "getdefaultmodule", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_21$$6, router$$6, "getrewriteuri", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(newUri$$6);
			ZEPHIR_CONCAT_SVV(newUri$$6, "/", _20$$6, _21$$6);
			_22$$6 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(&_23$$6, _22$$6, "handle", NULL, 0, newUri$$6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_24$$6, _23$$6, "getcontent", NULL, 0);
			zephir_check_call_status();
			zend_print_zval(_24$$6, 0);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, execSrv) {

	zend_class_entry *_8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *needHandle_param = NULL, *backendSrv = NULL, *moduleClass = NULL, *moduleObj = NULL, *_0, *_1, *_2 = NULL, *_3, *_4, *_5, *_6, *_7 = NULL, *_9, *_10, *_11, *_12;
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
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 49);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(_0);
	object_init_ex(_0, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _0, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("di"), _0 TSRMLS_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "bootstrap", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _1, "setshared", NULL, 0, _2, this_ptr);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZEPHIR_GET_CONSTANT(_2, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_VS(_3, _2, "default-web.php");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 47, _3);
	zephir_check_call_status();
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	zephir_array_fetch_string(&_5, _4, SL("classPath"), PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 186 TSRMLS_CC);
	if (zephir_require_zval(_5 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(moduleClass);
	zephir_array_fetch_string(&moduleClass, _6, SL("className"), PH_NOISY, "phalconplus/Bootstrap.zep", 187 TSRMLS_CC);
	ZEPHIR_INIT_VAR(moduleObj);
	zephir_fetch_safe_class(_7, moduleClass);
		_8 = zend_fetch_class(Z_STRVAL_P(_7), Z_STRLEN_P(_7), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(moduleObj, _8);
	if (zephir_has_constructor(moduleObj TSRMLS_CC)) {
		_9 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, moduleObj, "__construct", NULL, 0, _9);
		zephir_check_call_status();
	}
	if (!(needHandle)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_INIT_NVAR(backendSrv);
	object_init_ex(backendSrv, phalconplus_base_backendserver_ce);
	_10 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, backendSrv, "__construct", NULL, 50, _10);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_11);
	object_init_ex(_11, zephir_get_internal_ce(SS("yar_server") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _11, "__construct", NULL, 0, backendSrv);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("application"), _11 TSRMLS_CC);
	_12 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _12, "handle", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, execTask) {

	zend_class_entry *_13;
	zend_bool _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *argv_param = NULL, *di = NULL, *needHandle = NULL, *moduleClass = NULL, *module = NULL, *_2, *_3, *_4, *_5, *_6, *_7, *_8, *_9, *_10, *_11, *_12 = NULL, *_14, *_15, *_1$$3;
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


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "initconf", NULL, 49);
	zephir_check_call_status();
	_0 = Z_TYPE_P(di) == IS_NULL;
	if (!(_0)) {
		_0 = !((zephir_instance_of_ev(di, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault\\cli") TSRMLS_CC) TSRMLS_CC)));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, zephir_get_internal_ce(SS("phalcon\\di\\factorydefault\\cli") TSRMLS_CC));
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_this(getThis(), SL("di"), _1$$3 TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("di"), di TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, zephir_get_internal_ce(SS("phalcon\\cli\\console") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("application"), _2 TSRMLS_CC);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, _3, "setdi", NULL, 0, _4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_5);
	ZEPHIR_GET_CONSTANT(_5, "APP_ROOT_COMMON_LOAD_DIR");
	ZEPHIR_INIT_VAR(_6);
	ZEPHIR_CONCAT_VS(_6, _5, "default-cli.php");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "load", NULL, 47, _6);
	zephir_check_call_status();
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_8);
	ZVAL_STRING(_8, "bootstrap", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _7, "setshared", NULL, 0, _8, this_ptr);
	zephir_check_temp_parameter(_8);
	zephir_check_call_status();
	_9 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	zephir_array_fetch_string(&_10, _9, SL("classPath"), PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 222 TSRMLS_CC);
	if (zephir_require_zval(_10 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	_11 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(moduleClass);
	zephir_array_fetch_string(&moduleClass, _11, SL("className"), PH_NOISY, "phalconplus/Bootstrap.zep", 223 TSRMLS_CC);
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

	zend_class_entry *_27;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL, *_9 = NULL, *_10 = NULL;
	zval *moduleName_param = NULL, *moduleConfPath = NULL, *moduleConf = NULL, *moduleClassName = NULL, *moduleClassPath = NULL, *moduleRunMode = NULL, *_0, *_1, *_2 = NULL, *reservedModuleConf = NULL, *_8 = NULL, *_11 = NULL, *_12, *_13, *_14, *_15, *_16, *_17, *_18, *_19, *_20 = NULL, *_23, *_24, *_25, *_26 = NULL, *_28, *_4$$3, *_5$$3 = NULL, *_6$$4, *_7$$4, *_21$$5, *_22$$5;
	zval *moduleName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	if (UNEXPECTED(Z_TYPE_P(moduleName_param) != IS_STRING && Z_TYPE_P(moduleName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(moduleName_param) == IS_STRING)) {
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
	ZEPHIR_CONCAT_VVSVS(moduleConfPath, _0, moduleName, "/app/config/", _1, ".php");
	ZEPHIR_CALL_FUNCTION(&_2, "is_file", &_3, 46, moduleConfPath);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_GET_CONSTANT(_4$$3, "APP_ROOT_DIR");
		ZEPHIR_INIT_NVAR(moduleConfPath);
		ZEPHIR_CONCAT_VVSS(moduleConfPath, _4$$3, moduleName, "/app/config/config", ".php");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "is_file", &_3, 46, moduleConfPath);
		zephir_check_call_status();
		if (!(zephir_is_true(_5$$3))) {
			ZEPHIR_INIT_VAR(_6$$4);
			object_init_ex(_6$$4, zephir_get_internal_ce(SS("phalcon\\config\\exception") TSRMLS_CC));
			ZEPHIR_INIT_VAR(_7$$4);
			ZEPHIR_CONCAT_SV(_7$$4, "Module config file not exist, file position: ", moduleConfPath);
			ZEPHIR_CALL_METHOD(NULL, _6$$4, "__construct", NULL, 0, _7$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(_6$$4, "phalconplus/Bootstrap.zep", 240 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(moduleConf);
	object_init_ex(moduleConf, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(&_8, this_ptr, "load", &_9, 47, moduleConfPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, moduleConf, "__construct", &_10, 0, _8);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(reservedModuleConf);
	object_init_ex(reservedModuleConf, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(&_11, this_ptr, "load", &_9, 47, moduleConfPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, reservedModuleConf, "__construct", &_10, 0, _11);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_12);
	zephir_read_property(&_12, moduleConf, SL("application"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(moduleRunMode);
	zephir_read_property(&moduleRunMode, _12, SL("mode"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_13);
	zephir_read_property(&_13, moduleConf, SL("application"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_14);
	zephir_read_property(&_14, _13, SL("ns"), PH_NOISY_CC);
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
	zephir_array_fetch(&_16, _15, moduleRunMode, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 250 TSRMLS_CC);
	ZEPHIR_INIT_VAR(moduleClassName);
	ZEPHIR_CONCAT_VV(moduleClassName, _14, _16);
	ZEPHIR_INIT_VAR(_17);
	ZEPHIR_GET_CONSTANT(_17, "APP_ROOT_DIR");
	_18 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
	zephir_array_fetch(&_19, _18, moduleRunMode, PH_NOISY | PH_READONLY, "phalconplus/Bootstrap.zep", 251 TSRMLS_CC);
	ZEPHIR_INIT_VAR(moduleClassPath);
	ZEPHIR_CONCAT_VVSVS(moduleClassPath, _17, moduleName, "/app/", _19, ".php");
	ZEPHIR_CALL_FUNCTION(&_20, "is_file", &_3, 46, moduleClassPath);
	zephir_check_call_status();
	if (!(zephir_is_true(_20))) {
		ZEPHIR_INIT_VAR(_21$$5);
		object_init_ex(_21$$5, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_22$$5);
		ZEPHIR_CONCAT_SV(_22$$5, "Module init file not exists, file position: ", moduleClassPath);
		ZEPHIR_CALL_METHOD(NULL, _21$$5, "__construct", NULL, 7, _22$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(_21$$5, "phalconplus/Bootstrap.zep", 253 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_23 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_24);
	ZVAL_STRING(_24, "moduleConfig", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _23, "set", NULL, 0, _24, reservedModuleConf);
	zephir_check_temp_parameter(_24);
	zephir_check_call_status();
	_25 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, moduleConf, "merge", NULL, 0, _25);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setconfig", NULL, 51, moduleConf);
	zephir_check_call_status();
	if (zephir_require_zval(moduleClassPath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	zephir_fetch_safe_class(_26, moduleClassName);
		_27 = zend_fetch_class(Z_STRVAL_P(_26), Z_STRLEN_P(_26), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _27);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		_28 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, _28);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Bootstrap, getEnv) {

	

	RETURN_MEMBER(getThis(), "env");

}

PHP_METHOD(PhalconPlus_Bootstrap, getConfig) {

	

	RETURN_MEMBER(getThis(), "config");

}

PHP_METHOD(PhalconPlus_Bootstrap, setConfig) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config, *globalConf = NULL, *_0, *_1 = NULL, *_2 = NULL, *_4, *_5, *_3$$4;

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
		_3$$4 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&globalConf, _3$$4, "getconfig", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, globalConf, "merge", NULL, 0, config);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("config"), globalConf TSRMLS_CC);
	_4 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "config", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _4, "set", NULL, 0, _2, _5);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Bootstrap, getDI) {

	

	RETURN_MEMBER(getThis(), "di");

}

PHP_METHOD(PhalconPlus_Bootstrap, load) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filePath, *_0 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL, *_6, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_1$$3, *_2$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath);



	ZEPHIR_CALL_FUNCTION(&_0, "is_file", NULL, 46, filePath);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SV(_2$$3, "The file you try to load is not exists. file position: ", filePath);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 7, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalconplus/Bootstrap.zep", 299 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_GET_CONSTANT(_3, "APP_ROOT_DIR");
	ZEPHIR_CPY_WRT(_4, _3);
	if (zephir_set_symbol_str(SS("rootPath"), _4 TSRMLS_CC) == FAILURE) {
	  return;
	}
	ZEPHIR_INIT_NVAR(_3);
	object_init_ex(_3, zephir_get_internal_ce(SS("phalcon\\loader") TSRMLS_CC));
	if (zephir_has_constructor(_3 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CPY_WRT(_5, _3);
	if (zephir_set_symbol_str(SS("loader"), _5 TSRMLS_CC) == FAILURE) {
	  return;
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(_7, _6);
	if (zephir_set_symbol_str(SS("config"), _7 TSRMLS_CC) == FAILURE) {
	  return;
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("application"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(_8, _6);
	if (zephir_set_symbol_str(SS("application"), _8 TSRMLS_CC) == FAILURE) {
	  return;
	}
	ZEPHIR_CPY_WRT(_9, this_ptr);
	if (zephir_set_symbol_str(SS("bootstrap"), _9 TSRMLS_CC) == FAILURE) {
	  return;
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("di"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(_10, _6);
	if (zephir_set_symbol_str(SS("di"), _10 TSRMLS_CC) == FAILURE) {
	  return;
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_11);
	if (zephir_require_zval_ret(&_11, filePath TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(_11);

}

zend_object_value zephir_init_properties_PhalconPlus_Bootstrap(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3, *_3$$4;
	zval *_0, *_2;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("modeMap"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_1$$3, SS("Web"), SL("Module"), 1);
			add_assoc_stringl_ex(_1$$3, SS("Cli"), SL("Task"), 1);
			add_assoc_stringl_ex(_1$$3, SS("Srv"), SL("Srv"), 1);
			add_assoc_stringl_ex(_1$$3, SS("Micro"), SL("Micro"), 1);
			zephir_update_property_this(getThis(), SL("modeMap"), _1$$3 TSRMLS_CC);
		}
		_2 = zephir_fetch_nproperty_this(this_ptr, SL("module"), PH_NOISY_CC);
		if (Z_TYPE_P(_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(_3$$4);
			zephir_create_array(_3$$4, 3, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_3$$4, SS("classPath"), SL(""), 1);
			add_assoc_stringl_ex(_3$$4, SS("className"), SL(""), 1);
			add_assoc_stringl_ex(_3$$4, SS("mode"), SL(""), 1);
			zephir_update_property_this(getThis(), SL("module"), _3$$4 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

