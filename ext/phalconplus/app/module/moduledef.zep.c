
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

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
#include "kernel/array.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(PhalconPlus_App_Module_ModuleDef) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\App\\Module, ModuleDef, phalconplus, app_module_moduledef, phalconplus_app_module_moduledef_method_entry, 0);

	zend_declare_property_string(phalconplus_app_module_moduledef_ce, SL("classPath"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalconplus_app_module_moduledef_ce, SL("className"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalconplus_app_module_moduledef_ce, SL("name"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalconplus_app_module_moduledef_ce, SL("configPath"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalconplus_app_module_moduledef_ce, SL("dir"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_app_module_moduledef_ce, SL("loadedClasses"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);

	zend_declare_property_null(phalconplus_app_module_moduledef_ce, SL("config"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_app_module_moduledef_ce, SL("runMode"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_app_module_moduledef_ce, SL("bootstrap"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalconplus_app_module_moduledef_ce, SL("isPrimary"), 0, ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_22 = NULL, *_29 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool isPrimary;
	zval moduleDir, _2$$3;
	zval *app, app_sub, *moduleDir_param = NULL, *isPrimary_param = NULL, __$true, __$false, _0, _3, _4, _6, _7, _8, _9, _10, appConfig, _11, _12, _13, _14, _15, _16, _17, _18, _19, _20, _21, _23, _24, _25, _1$$3, _26$$5, _27$$5, _28$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&appConfig);
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
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&_27$$5);
	ZVAL_UNDEF(&_28$$5);
	ZVAL_UNDEF(&moduleDir);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &app, &moduleDir_param, &isPrimary_param);

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
	if (!isPrimary_param) {
		isPrimary = 0;
	} else {
		isPrimary = zephir_get_boolval(isPrimary_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 40, &moduleDir);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Module directory not exists or not a dir, file positon: ", &moduleDir);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 20, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/App/Module/ModuleDef.zep", 49);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&_3, app, "getbootstrap", NULL, 41);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("bootstrap"), &_3);
	zephir_update_property_zval(this_ptr, SL("dir"), &moduleDir);
	ZEPHIR_CALL_CE_STATIC(&_4, phalconplus_enum_sys_ce, "getmoduleconfigpath", &_5, 0, &moduleDir);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("configPath"), &_4);
	ZEPHIR_INIT_VAR(&_6);
	object_init_ex(&_6, zephir_get_internal_ce(SL("phalcon\\config")));
	zephir_read_property(&_7, this_ptr, SL("bootstrap"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_9, this_ptr, SL("configPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_8, &_7, "load", NULL, 0, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", NULL, 0, &_8);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("config"), &_6);
	zephir_read_property(&_10, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string(&_10, SL("application")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Config Path: /application must exists", "phalconplus/App/Module/ModuleDef.zep", 59);
		return;
	}
	zephir_read_property(&_11, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&appConfig);
	zephir_read_property(&appConfig, &_11, SL("application"), PH_NOISY_CC);
	zephir_read_property(&_12, &appConfig, SL("name"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("name"), &_12);
	ZEPHIR_INIT_VAR(&_13);
	object_init_ex(&_13, phalconplus_enum_runmode_ce);
	ZEPHIR_INIT_VAR(&_14);
	ZEPHIR_INIT_VAR(&_15);
	zephir_read_property(&_16, &appConfig, SL("mode"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_strtolower(&_15, &_16);
	zephir_ucfirst(&_14, &_15);
	ZEPHIR_CALL_METHOD(NULL, &_13, "__construct", NULL, 42, &_14);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("runMode"), &_13);
	zephir_read_property(&_17, &appConfig, SL("ns"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_18, this_ptr, SL("runMode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_19, &_18, "getmapclassname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_20);
	ZEPHIR_CONCAT_VV(&_20, &_17, &_19);
	zephir_update_property_zval(this_ptr, SL("className"), &_20);
	zephir_read_property(&_23, this_ptr, SL("runMode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_21, phalconplus_enum_sys_ce, "getmoduleclasspath", &_22, 0, &moduleDir, &_23);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("classPath"), &_21);
	zephir_read_property(&_24, this_ptr, SL("classPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_25, "is_file", NULL, 43, &_24);
	zephir_check_call_status();
	if (!(zephir_is_true(&_25))) {
		ZEPHIR_INIT_VAR(&_26$$5);
		object_init_ex(&_26$$5, phalconplus_base_exception_ce);
		zephir_read_property(&_27$$5, this_ptr, SL("classPath"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_28$$5);
		ZEPHIR_CONCAT_SV(&_28$$5, "Module class file not exists: ", &_27$$5);
		ZEPHIR_CALL_METHOD(NULL, &_26$$5, "__construct", &_29, 2, &_28$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_26$$5, "phalconplus/App/Module/ModuleDef.zep", 70);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (isPrimary) {
		zephir_update_property_zval(this_ptr, SL("isPrimary"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("isPrimary"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, impl) {

	zend_class_entry *_11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di, di_sub, _0, _1, _3, _7, _8, className, _9, _10, _2$$3, _4$$4, _5$$4, _6$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &di);



	zephir_read_static_property_ce(&_0, phalconplus_app_module_moduledef_ce, SL("loadedClasses"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("className"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &_1))) {
		zephir_read_property(&_2$$3, this_ptr, SL("classPath"), PH_NOISY_CC | PH_READONLY);
		if (zephir_require_zval(&_2$$3) == FAILURE) {
			RETURN_MM_NULL();
		}
	}
	zephir_read_property(&_3, this_ptr, SL("className"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_class_exists(&_3, 1))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, phalconplus_base_exception_ce);
		zephir_read_property(&_5$$4, this_ptr, SL("className"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_6$$4);
		ZEPHIR_CONCAT_SV(&_6$$4, "Module class not exists: ", &_5$$4);
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 2, &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalconplus/App/Module/ModuleDef.zep", 81);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_LONG(&_7, 1);
	ZEPHIR_OBS_VAR(&_8);
	zephir_read_property(&_8, this_ptr, SL("className"), PH_NOISY_CC);
	zephir_update_static_property_array_multi_ce(phalconplus_app_module_moduledef_ce, SL("loadedClasses"), &_7, SL("z"), 1, &_8);
	zephir_read_property(&_9, this_ptr, SL("className"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&className, &_9);
	zephir_fetch_safe_class(&_10, &className);
	_11 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_10), Z_STRLEN_P(&_10), ZEND_FETCH_CLASS_AUTO);
	if(!_11) {
		RETURN_MM_NULL();
	}
	object_init_ex(return_value, _11);
	if (zephir_has_constructor(return_value)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, di, this_ptr);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, isDefault) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("isPrimary"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_IS_TRUE_IDENTICAL(&_0));

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, isPrimary) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("isPrimary"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_IS_TRUE_IDENTICAL(&_0));

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getIsPrimary) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "isPrimary");

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getClassPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "classPath");

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getBootstrap) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "bootstrap");

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getClassName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "className");

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getRunMode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "runMode");

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getMapClassName) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("runMode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getmapclassname", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getMode) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("runMode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getvalue", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getConfigPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "configPath");

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getConfig) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "config");

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, getDir) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "dir");

}

void zephir_init_static_properties_PhalconPlus_App_Module_ModuleDef(TSRMLS_D) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(phalconplus_app_module_moduledef_ce, ZEND_STRL("loadedClasses"), &_0);
	ZEPHIR_MM_RESTORE();

}

