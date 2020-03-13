
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
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Enum_Sys) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Enum, Sys, phalconplus, enum_sys, phalconplus_enum_abstractenum_ce, phalconplus_enum_sys_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_string(phalconplus_enum_sys_ce, SL("rootDir"), "", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zend_declare_property_string(phalconplus_enum_sys_ce, SL("primaryModuleDir"), "", ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zend_declare_property_null(phalconplus_enum_sys_ce, SL("requiredFiles"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zend_declare_property_null(phalconplus_enum_sys_ce, SL("app"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);

	zephir_declare_class_constant_string(phalconplus_enum_sys_ce, SL("COMMON_NAME"), "common");

	zephir_declare_class_constant_string(phalconplus_enum_sys_ce, SL("CONF_NAME"), "config");

	zephir_declare_class_constant_string(phalconplus_enum_sys_ce, SL("LOAD_NAME"), "load");

	zephir_declare_class_constant_string(phalconplus_enum_sys_ce, SL("PUB_NAME"), "public");

	zephir_declare_class_constant_string(phalconplus_enum_sys_ce, SL("APP_NAME"), "app");

	zephir_declare_class_constant_string(phalconplus_enum_sys_ce, SL("DS"), "/");

	zephir_declare_class_constant_string(phalconplus_enum_sys_ce, SL("EXT"), ".php");

	zephir_declare_class_constant_string(phalconplus_enum_sys_ce, SL("ENV_NAME"), "phalconplus.env");

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Enum_Sys, init) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *moduleDir_param = NULL, _0, _1, _2, _3, _6, _7, _8, _4$$4;
	zval moduleDir, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleDir);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_4$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleDir_param);

	if (UNEXPECTED(Z_TYPE_P(moduleDir_param) != IS_STRING && Z_TYPE_P(moduleDir_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'moduleDir' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(moduleDir_param) == IS_STRING)) {
		zephir_get_strval(&moduleDir, moduleDir_param);
	} else {
		ZEPHIR_INIT_VAR(&moduleDir);
		ZVAL_EMPTY_STRING(&moduleDir);
	}


	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, phalconplus_enum_sys_ce, SL("primaryModuleDir"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(&_0))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_trim(&_1, &moduleDir, &_2, ZEPHIR_TRIM_RIGHT);
	zephir_get_strval(&moduleDir, &_1);
	ZEPHIR_CALL_FUNCTION(&_3, "is_dir", NULL, 49, &moduleDir);
	zephir_check_call_status();
	if (!(zephir_is_true(&_3))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SV(&_5$$4, "Module directory not exists or not a dir, file positon: ", &moduleDir);
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 2, &_5$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalconplus/Enum/Sys.zep", 32);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_static_property_ce(phalconplus_enum_sys_ce, ZEND_STRL("primaryModuleDir"), &moduleDir);
	ZEPHIR_CALL_FUNCTION(&_6, "dirname", NULL, 115, &moduleDir);
	zephir_check_call_status();
	zephir_update_static_property_ce(phalconplus_enum_sys_ce, ZEND_STRL("rootDir"), &_6);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "PhalconPlus\\Enum\\Sys");
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "Ph\\Sys");
	ZEPHIR_CALL_SELF(NULL, "classalias", NULL, 0, &_7, &_8);
	zephir_check_call_status();
	RETURN_MM_NULL();

}

PHP_METHOD(PhalconPlus_Enum_Sys, initApp) {

	zval *app, app_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &app);



	zephir_read_static_property_ce(&_0, phalconplus_enum_sys_ce, SL("app"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_0) == IS_NULL) {
		zephir_update_static_property_ce(phalconplus_enum_sys_ce, ZEND_STRL("app"), app);
	}

}

PHP_METHOD(PhalconPlus_Enum_Sys, app) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_static_property_ce(&_0, phalconplus_enum_sys_ce, SL("app"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);

}

PHP_METHOD(PhalconPlus_Enum_Sys, getPrimaryModuleDir) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, phalconplus_enum_sys_ce, SL("primaryModuleDir"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VS(return_value, &_0, "/");
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getRootDir) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_static_property_ce(&_0, phalconplus_enum_sys_ce, SL("rootDir"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VS(return_value, &_0, "/");
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getCommonDir) {

	zval _1, _2;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_static_property_ce(&_1, phalconplus_enum_sys_ce, SL("rootDir"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "common");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_join(return_value, &_2, &_0);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getGlobalConfigDir) {

	zval _3;
	zval _1, _2;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_static_property_ce(&_1, phalconplus_enum_sys_ce, SL("rootDir"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "common");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SS(&_3, "config", ".php");
	zephir_array_fast_append(&_0, &_3);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_join(return_value, &_2, &_0);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getGlobalConfigPath) {

	zval _3;
	zval _1, _2;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_static_property_ce(&_1, phalconplus_enum_sys_ce, SL("rootDir"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "common");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "config");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_CONCAT_SS(&_3, "config", ".php");
	zephir_array_fast_append(&_0, &_3);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_join(return_value, &_2, &_0);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getGlobalLoadDir) {

	zval _1, _2;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_static_property_ce(&_1, phalconplus_enum_sys_ce, SL("rootDir"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "common");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "load");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_join(return_value, &_2, &_0);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getModuleDirByName) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *moduleName_param = NULL, _1, _2;
	zval moduleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleName);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleName_param);

	zephir_get_strval(&moduleName, moduleName_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_static_property_ce(&_1, phalconplus_enum_sys_ce, SL("rootDir"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, &moduleName);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_join(return_value, &_2, &_0);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getModuleNameByDir) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *moduleDir_param = NULL, _0;
	zval moduleDir;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleDir);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleDir_param);

	zephir_get_strval(&moduleDir, moduleDir_param);


	ZVAL_LONG(&_0, 8);
	ZEPHIR_RETURN_CALL_FUNCTION("pathinfo", NULL, 116, &moduleDir, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getModuleClassPath) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *moduleDir_param = NULL, *modeName_param = NULL, _1;
	zval moduleDir, modeName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleDir);
	ZVAL_UNDEF(&modeName);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &moduleDir_param, &modeName_param);

	zephir_get_strval(&moduleDir, moduleDir_param);
	zephir_get_strval(&modeName, modeName_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 5, 0);
	zephir_array_fast_append(&_0, &moduleDir);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "app");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, &modeName);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, ".php");
	zephir_array_fast_append(&_0, &_1);
	zephir_fast_join_str(return_value, SL(""), &_0);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, getModuleConfigPath) {

	zval _0, _3, _7$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_6 = NULL;
	zval *moduleDir_param = NULL, confPrefix, confPath, _1, _2, _4, _5, _9, _8$$3, _10$$4, _11$$4, _12$$4;
	zval moduleDir;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleDir);
	ZVAL_UNDEF(&confPrefix);
	ZVAL_UNDEF(&confPath);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &moduleDir_param);

	zephir_get_strval(&moduleDir, moduleDir_param);


	ZEPHIR_INIT_VAR(&confPrefix);
	ZVAL_STRING(&confPrefix, "");
	ZEPHIR_INIT_VAR(&confPath);
	ZVAL_STRING(&confPath, "");
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 4, 0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_trim(&_1, &moduleDir, &_2, ZEPHIR_TRIM_RIGHT);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "app");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "config");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "");
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "/");
	ZEPHIR_INIT_NVAR(&confPrefix);
	zephir_fast_join(&confPrefix, &_1, &_0);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 3, 0);
	zephir_array_fast_append(&_3, &confPrefix);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_GET_CONSTANT(&_4, "APP_RUN_ENV");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, ".php");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&confPath);
	zephir_fast_join_str(&confPath, SL(""), &_3);
	ZEPHIR_CALL_FUNCTION(&_5, "is_file", &_6, 51, &confPath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_5))) {
		ZEPHIR_INIT_VAR(&_7$$3);
		zephir_create_array(&_7$$3, 3, 0);
		zephir_array_fast_append(&_7$$3, &confPrefix);
		ZEPHIR_INIT_VAR(&_8$$3);
		ZVAL_STRING(&_8$$3, "config");
		zephir_array_fast_append(&_7$$3, &_8$$3);
		ZEPHIR_INIT_NVAR(&_8$$3);
		ZVAL_STRING(&_8$$3, ".php");
		zephir_array_fast_append(&_7$$3, &_8$$3);
		ZEPHIR_INIT_NVAR(&confPath);
		zephir_fast_join_str(&confPath, SL(""), &_7$$3);
	}
	ZEPHIR_CALL_FUNCTION(&_9, "is_file", &_6, 51, &confPath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_9))) {
		ZEPHIR_INIT_VAR(&_10$$4);
		object_init_ex(&_10$$4, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_11$$4);
		ZEPHIR_GET_CONSTANT(&_11$$4, "APP_RUN_ENV");
		ZEPHIR_INIT_VAR(&_12$$4);
		ZEPHIR_CONCAT_SVSVS(&_12$$4, "Module Config file not exists: ", &confPath, " & ", &_11$$4, ".php");
		ZEPHIR_CALL_METHOD(NULL, &_10$$4, "__construct", NULL, 2, &_12$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_10$$4, "phalconplus/Enum/Sys.zep", 163);
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&confPath);

}

PHP_METHOD(PhalconPlus_Enum_Sys, getComposerAutoloadPath) {

	zval _1, _2;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_static_property_ce(&_1, phalconplus_enum_sys_ce, SL("rootDir"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "vendor");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "autoload.php");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "/");
	zephir_fast_join(return_value, &_2, &_0);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_Sys, classAlias) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *className_param = NULL, *classAlias_param = NULL;
	zval className, classAlias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&classAlias);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &className_param, &classAlias_param);

	zephir_get_strval(&className, className_param);
	zephir_get_strval(&classAlias, classAlias_param);


	
            zend_class_entry *ce;
            ce = zephir_fetch_class(&className TSRMLS_CC);
            zend_register_class_alias_ex(Z_STRVAL(classAlias), Z_STRLEN(classAlias), ce);
        
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Enum_Sys, load) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filePath, filePath_sub, _0, loader, config, superapp, di, rootPath, result, _3, _4, _5, _6, _1$$4, _2$$4, _7$$6, _8$$6, _9$$6, _10$$6, _11$$7, _12$$7, _13$$7, _14$$7, _15$$7, _16$$7, _17$$7, _18$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&loader);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&superapp);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&rootPath);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath);



	if (UNEXPECTED(!(Z_TYPE_P(filePath) == IS_STRING))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_FUNCTION(&_0, "is_file", NULL, 51, filePath);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "The file you try to load is not exists. file position: ", filePath);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 2, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalconplus/Enum/Sys.zep", 196);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&result);
	zephir_read_static_property_ce(&_3, phalconplus_enum_sys_ce, SL("requiredFiles"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&result, &_3, filePath, 0)) {
		RETURN_CCTOR(&result);
	}
	ZEPHIR_INIT_VAR(&rootPath);
	ZVAL_STRING(&rootPath, "rootPath");
	ZEPHIR_INIT_VAR(&di);
	ZVAL_STRING(&di, "di");
	ZEPHIR_INIT_VAR(&loader);
	ZVAL_STRING(&loader, "loader");
	ZEPHIR_INIT_VAR(&config);
	ZVAL_STRING(&config, "config");
	ZEPHIR_INIT_VAR(&superapp);
	ZVAL_STRING(&superapp, "superapp");
	ZEPHIR_CALL_SELF(&_4, "getrootdir", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&_5, &_4);
	if (zephir_set_symbol(&rootPath, &_5) == FAILURE) {
		return;
	}
	ZEPHIR_OBS_VAR(&_6);
	zephir_read_static_property_ce(&_6, phalconplus_enum_sys_ce, SL("app"), PH_NOISY_CC);
	if (Z_TYPE_P(&_6) == IS_OBJECT) {
		zephir_read_static_property_ce(&_7$$6, phalconplus_enum_sys_ce, SL("app"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_8$$6, &_7$$6, "config", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&_9$$6, &_8$$6);
		if (zephir_set_symbol(&config, &_9$$6) == FAILURE) {
			return;
		}
		zephir_read_static_property_ce(&_10$$6, phalconplus_enum_sys_ce, SL("app"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_8$$6, &_10$$6, "isbooted", NULL, 0);
		zephir_check_call_status();
		if (zephir_is_true(&_8$$6)) {
			ZEPHIR_OBS_VAR(&_11$$7);
			zephir_read_static_property_ce(&_11$$7, phalconplus_enum_sys_ce, SL("app"), PH_NOISY_CC);
			ZEPHIR_CPY_WRT(&_12$$7, &_11$$7);
			if (zephir_set_symbol(&superapp, &_12$$7) == FAILURE) {
				return;
			}
			zephir_read_static_property_ce(&_11$$7, phalconplus_enum_sys_ce, SL("app"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_13$$7, &_11$$7, "di", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&_14$$7, &_13$$7);
			if (zephir_set_symbol(&di, &_14$$7) == FAILURE) {
				return;
			}
			zephir_read_static_property_ce(&_15$$7, phalconplus_enum_sys_ce, SL("app"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_13$$7, &_15$$7, "di", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_17$$7);
			ZVAL_STRING(&_17$$7, "loader");
			ZEPHIR_CALL_METHOD(&_16$$7, &_13$$7, "get", NULL, 0, &_17$$7);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&_18$$7, &_16$$7);
			if (zephir_set_symbol(&loader, &_18$$7) == FAILURE) {
				return;
			}
		}
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_4);
	if (zephir_require_zval_ret(&_4, filePath) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(&result, &_4);
	zephir_update_static_property_array_multi_ce(phalconplus_enum_sys_ce, SL("requiredFiles"), &result, SL("z"), 1, filePath);
	RETURN_CCTOR(&result);

}

void zephir_init_static_properties_PhalconPlus_Enum_Sys(TSRMLS_D) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(phalconplus_enum_sys_ce, ZEND_STRL("requiredFiles"), &_0);
	ZEPHIR_MM_RESTORE();

}

