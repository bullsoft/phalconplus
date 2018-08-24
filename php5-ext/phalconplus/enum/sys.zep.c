
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Enum_Sys) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Enum, Sys, phalconplus, enum_sys, phalconplus_enum_abstractenum_ce, phalconplus_enum_sys_method_entry, 0);

	zend_declare_property_string(phalconplus_enum_sys_ce, SL("rootDir"), "", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_string(phalconplus_enum_sys_ce, SL("primaryModuleDir"), "", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_sys_ce, SL("COMMON_NAME"), "common" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_sys_ce, SL("CONF_NAME"), "config" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_sys_ce, SL("LOAD_NAME"), "load" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_sys_ce, SL("PUB_NAME"), "public" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_sys_ce, SL("APP_NAME"), "app" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_sys_ce, SL("DS"), "/" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_sys_ce, SL("EXT"), ".php" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_sys_ce, SL("ENV_NAME"), "phalconplus.env" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Enum_Sys, init) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *moduleDir_param = NULL, *_0, *_1, _2, *_3 = NULL, *_6 = NULL, *_4$$4;
	zval *moduleDir = NULL, *_5$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleDir_param);

	if (UNEXPECTED(Z_TYPE_P(moduleDir_param) != IS_STRING && Z_TYPE_P(moduleDir_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleDir' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(moduleDir_param) == IS_STRING)) {
		zephir_get_strval(moduleDir, moduleDir_param);
	} else {
		ZEPHIR_INIT_VAR(moduleDir);
		ZVAL_EMPTY_STRING(moduleDir);
	}


	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, phalconplus_enum_sys_ce, SL("primaryModuleDir") TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(_0))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "/", 0);
	zephir_fast_trim(_1, moduleDir, &_2, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	zephir_get_strval(moduleDir, _1);
	ZEPHIR_CALL_FUNCTION(&_3, "is_dir", NULL, 36, moduleDir);
	zephir_check_call_status();
	if (!(zephir_is_true(_3))) {
		ZEPHIR_INIT_VAR(_4$$4);
		object_init_ex(_4$$4, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_5$$4);
		ZEPHIR_CONCAT_SV(_5$$4, "Module directory not exists or not a dir, file positon: ", moduleDir);
		ZEPHIR_CALL_METHOD(NULL, _4$$4, "__construct", NULL, 7, _5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_4$$4, "phalconplus/Enum/Sys.zep", 28 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_static_property_ce(phalconplus_enum_sys_ce, SL("primaryModuleDir"), &moduleDir TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_6, "dirname", NULL, 67, moduleDir);
	zephir_check_call_status();
	zephir_update_static_property_ce(phalconplus_enum_sys_ce, SL("rootDir"), &_6 TSRMLS_CC);
	RETURN_MM_NULL();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getPrimaryModuleDir) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, phalconplus_enum_sys_ce, SL("primaryModuleDir") TSRMLS_CC);
	ZEPHIR_CONCAT_VS(return_value, _0, "/");
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getRootDir) {

	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(_0);
	zephir_read_static_property_ce(&_0, phalconplus_enum_sys_ce, SL("rootDir") TSRMLS_CC);
	ZEPHIR_CONCAT_VS(return_value, _0, "/");
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getCommonDir) {

	zval *_1, *_2 = NULL, _3;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 3, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_static_property_ce(&_1, phalconplus_enum_sys_ce, SL("rootDir") TSRMLS_CC);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "common", 1);
	zephir_array_fast_append(_0, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "", 1);
	zephir_array_fast_append(_0, _2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "/", 0);
	zephir_fast_join(return_value, &_3, _0 TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getGlobalConfigDir) {

	zval *_3;
	zval *_1, *_2, _4;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 3, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_static_property_ce(&_1, phalconplus_enum_sys_ce, SL("rootDir") TSRMLS_CC);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "common", 1);
	zephir_array_fast_append(_0, _2);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SS(_3, "config", ".php");
	zephir_array_fast_append(_0, _3);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "/", 0);
	zephir_fast_join(return_value, &_4, _0 TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getGlobalConfigPath) {

	zval *_3;
	zval *_1, *_2 = NULL, _4;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_static_property_ce(&_1, phalconplus_enum_sys_ce, SL("rootDir") TSRMLS_CC);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "common", 1);
	zephir_array_fast_append(_0, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "config", 1);
	zephir_array_fast_append(_0, _2);
	ZEPHIR_INIT_VAR(_3);
	ZEPHIR_CONCAT_SS(_3, "config", ".php");
	zephir_array_fast_append(_0, _3);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_STRING(&_4, "/", 0);
	zephir_fast_join(return_value, &_4, _0 TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getGlobalLoadDir) {

	zval *_1, *_2 = NULL, _3;
	zval *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_static_property_ce(&_1, phalconplus_enum_sys_ce, SL("rootDir") TSRMLS_CC);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "common", 1);
	zephir_array_fast_append(_0, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "load", 1);
	zephir_array_fast_append(_0, _2);
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "", 1);
	zephir_array_fast_append(_0, _2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "/", 0);
	zephir_fast_join(return_value, &_3, _0 TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getModuleDirByName) {

	zval *_0;
	zval *moduleName_param = NULL, *_1, *_2, _3;
	zval *moduleName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	zephir_get_strval(moduleName, moduleName_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 3, 0 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_1);
	zephir_read_static_property_ce(&_1, phalconplus_enum_sys_ce, SL("rootDir") TSRMLS_CC);
	zephir_array_fast_append(_0, _1);
	zephir_array_fast_append(_0, moduleName);
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "", 1);
	zephir_array_fast_append(_0, _2);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "/", 0);
	zephir_fast_join(return_value, &_3, _0 TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getModuleNameByDir) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *moduleDir_param = NULL, _0;
	zval *moduleDir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleDir_param);

	zephir_get_strval(moduleDir, moduleDir_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 8);
	ZEPHIR_RETURN_CALL_FUNCTION("pathinfo", NULL, 68, moduleDir, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getModuleClassPath) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *moduleDir_param = NULL, *runMode, *_1 = NULL, *_2 = NULL;
	zval *moduleDir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &moduleDir_param, &runMode);

	zephir_get_strval(moduleDir, moduleDir_param);


	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 5, 0 TSRMLS_CC);
	zephir_array_fast_append(_0, moduleDir);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "app", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "/", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_CALL_METHOD(&_2, runMode, "getmapclassname", NULL, 0);
	zephir_check_call_status();
	zephir_array_fast_append(_0, _2);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, ".php", 1);
	zephir_array_fast_append(_0, _1);
	zephir_fast_join_str(return_value, SL(""), _0 TSRMLS_CC);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getModuleConfigPath) {

	zval *_0, *_4, *_7$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL;
	zval *moduleDir_param = NULL, *confPrefix = NULL, *confPath = NULL, *_1 = NULL, _2, _3, *_5 = NULL, *_9 = NULL, *_8$$3 = NULL, *_10$$4, *_11$$4, *_12$$4;
	zval *moduleDir = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleDir_param);

	zephir_get_strval(moduleDir, moduleDir_param);


	ZEPHIR_INIT_VAR(confPrefix);
	ZVAL_STRING(confPrefix, "", 1);
	ZEPHIR_INIT_VAR(confPath);
	ZVAL_STRING(confPath, "", 1);
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 4, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_SINIT_VAR(_2);
	ZVAL_STRING(&_2, "/", 0);
	zephir_fast_trim(_1, moduleDir, &_2, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "app", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "config", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, "", 1);
	zephir_array_fast_append(_0, _1);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "/", 0);
	ZEPHIR_INIT_NVAR(confPrefix);
	zephir_fast_join(confPrefix, &_3, _0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_4);
	zephir_create_array(_4, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(_4, confPrefix);
	ZEPHIR_INIT_NVAR(_1);
	ZEPHIR_GET_CONSTANT(_1, "APP_RUN_ENV");
	zephir_array_fast_append(_4, _1);
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_STRING(_1, ".php", 1);
	zephir_array_fast_append(_4, _1);
	ZEPHIR_INIT_NVAR(confPath);
	zephir_fast_join_str(confPath, SL(""), _4 TSRMLS_CC);
	ZEPHIR_CALL_FUNCTION(&_5, "is_file", &_6, 41, confPath);
	zephir_check_call_status();
	if (!(zephir_is_true(_5))) {
		ZEPHIR_INIT_VAR(_7$$3);
		zephir_create_array(_7$$3, 3, 0 TSRMLS_CC);
		zephir_array_fast_append(_7$$3, confPrefix);
		ZEPHIR_INIT_VAR(_8$$3);
		ZVAL_STRING(_8$$3, "config", 1);
		zephir_array_fast_append(_7$$3, _8$$3);
		ZEPHIR_INIT_NVAR(_8$$3);
		ZVAL_STRING(_8$$3, ".php", 1);
		zephir_array_fast_append(_7$$3, _8$$3);
		ZEPHIR_INIT_NVAR(confPath);
		zephir_fast_join_str(confPath, SL(""), _7$$3 TSRMLS_CC);
	}
	ZEPHIR_CALL_FUNCTION(&_9, "is_file", &_6, 41, confPath);
	zephir_check_call_status();
	if (!(zephir_is_true(_9))) {
		ZEPHIR_INIT_VAR(_10$$4);
		object_init_ex(_10$$4, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_11$$4);
		ZEPHIR_GET_CONSTANT(_11$$4, "APP_RUN_ENV");
		ZEPHIR_INIT_VAR(_12$$4);
		ZEPHIR_CONCAT_SVSVS(_12$$4, "Module Config file not exists: ", confPath, " & ", _11$$4, ".php");
		ZEPHIR_CALL_METHOD(NULL, _10$$4, "__construct", NULL, 7, _12$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_10$$4, "phalconplus/Enum/Sys.zep", 143 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(confPath);

}

