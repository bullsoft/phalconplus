
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


ZEPHIR_INIT_CLASS(PhalconPlus_App_Module_ModuleDef) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\App\\Module, ModuleDef, phalconplus, app_module_moduledef, phalconplus_app_module_moduledef_method_entry, 0);

	zend_declare_property_string(phalconplus_app_module_moduledef_ce, SL("classPath"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalconplus_app_module_moduledef_ce, SL("className"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalconplus_app_module_moduledef_ce, SL("name"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalconplus_app_module_moduledef_ce, SL("configPath"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalconplus_app_module_moduledef_ce, SL("dir"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_app_module_moduledef_ce, SL("config"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_app_module_moduledef_ce, SL("runMode"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_app_module_moduledef_ce, SL("app"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalconplus_app_module_moduledef_ce, SL("isPrimary"), 0, ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, __construct) {

	zval _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL, *_8 = NULL, *_20 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool isPrimary;
	zval moduleDir, runMode, _2$$3;
	zval *app, app_sub, *moduleDir_param = NULL, *isPrimary_param = NULL, *runMode_param = NULL, __$true, __$false, _0, _4, _6, _7, _9, _11, appConfig, _12, _13, _19, _21, _22, _23, _24, _1$$3, _14$$5, _15$$5, _16$$5, _17$$5, _18$$6, _25$$7, _26$$7, _27$$7, _28$$7, _29$$8, _30$$8, _31$$8, _32$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&app_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&appConfig);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_25$$7);
	ZVAL_UNDEF(&_26$$7);
	ZVAL_UNDEF(&_27$$7);
	ZVAL_UNDEF(&_28$$7);
	ZVAL_UNDEF(&_29$$8);
	ZVAL_UNDEF(&_30$$8);
	ZVAL_UNDEF(&_31$$8);
	ZVAL_UNDEF(&_32$$8);
	ZVAL_UNDEF(&moduleDir);
	ZVAL_UNDEF(&runMode);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &app, &moduleDir_param, &isPrimary_param, &runMode_param);

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
	if (!runMode_param) {
		ZEPHIR_INIT_VAR(&runMode);
		ZVAL_STRING(&runMode, "");
	} else {
		zephir_get_strval(&runMode, runMode_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 51, &moduleDir);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Module directory not exists or not a dir, file positon: ", &moduleDir);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", &_3, 2, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/App/Module/ModuleDef.zep", 49);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, SL("app"), app);
	if (isPrimary) {
		zephir_update_property_zval(this_ptr, SL("isPrimary"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("isPrimary"), &__$false);
	}
	zephir_update_property_zval(this_ptr, SL("dir"), &moduleDir);
	ZEPHIR_CALL_CE_STATIC(&_4, phalconplus_enum_sys_ce, "getmoduleconfigpath", &_5, 0, &moduleDir);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("configPath"), &_4);
	ZEPHIR_INIT_VAR(&_6);
	object_init_ex(&_6, zephir_get_internal_ce(SL("phalcon\\config")));
	zephir_read_property(&_9, this_ptr, SL("configPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_10);
	zephir_create_array(&_10, 2, 0);
	zephir_array_update_string(&_10, SL("def"), this_ptr, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_10, SL("app"), app, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_CE_STATIC(&_7, phalconplus_enum_sys_ce, "load", &_8, 0, &_9, &_10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", NULL, 0, &_7);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("config"), &_6);
	zephir_read_property(&_11, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string(&_11, SL("application")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Config Path: /application must exists", "phalconplus/App/Module/ModuleDef.zep", 64);
		return;
	}
	zephir_read_property(&_12, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&appConfig);
	zephir_read_property(&appConfig, &_12, SL("application"), PH_NOISY_CC);
	zephir_read_property(&_13, &appConfig, SL("name"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("name"), &_13);
	if (ZEPHIR_IS_EMPTY(&runMode)) {
		ZEPHIR_INIT_VAR(&_14$$5);
		object_init_ex(&_14$$5, phalconplus_enum_runmode_ce);
		ZEPHIR_INIT_VAR(&_15$$5);
		ZEPHIR_INIT_VAR(&_16$$5);
		zephir_read_property(&_17$$5, &appConfig, SL("mode"), PH_NOISY_CC | PH_READONLY);
		zephir_fast_strtolower(&_16$$5, &_17$$5);
		zephir_ucfirst(&_15$$5, &_16$$5);
		ZEPHIR_CALL_METHOD(NULL, &_14$$5, "__construct", NULL, 52, &_15$$5);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("runMode"), &_14$$5);
	} else {
		ZEPHIR_INIT_VAR(&_18$$6);
		object_init_ex(&_18$$6, phalconplus_enum_runmode_ce);
		ZEPHIR_CALL_METHOD(NULL, &_18$$6, "__construct", NULL, 52, &runMode);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("runMode"), &_18$$6);
	}
	zephir_read_property(&_21, this_ptr, SL("runMode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_22, &_21, "getmapclassname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_19, phalconplus_enum_sys_ce, "getmoduleclasspath", &_20, 0, &moduleDir, &_22);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("classPath"), &_19);
	zephir_read_property(&_23, this_ptr, SL("classPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_24, "is_file", NULL, 53, &_23);
	zephir_check_call_status();
	if (zephir_is_true(&_24)) {
		zephir_read_property(&_25$$7, &appConfig, SL("ns"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_26$$7, this_ptr, SL("runMode"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_27$$7, &_26$$7, "getmapclassname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_28$$7);
		ZEPHIR_CONCAT_VV(&_28$$7, &_25$$7, &_27$$7);
		zephir_update_property_zval(this_ptr, SL("className"), &_28$$7);
	} else {
		ZEPHIR_INIT_VAR(&_30$$8);
		ZVAL_STRING(&_30$$8, "Module");
		ZEPHIR_CALL_CE_STATIC(&_29$$8, phalconplus_enum_sys_ce, "getmoduleclasspath", &_20, 0, &moduleDir, &_30$$8);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("classPath"), &_29$$8);
		zephir_read_property(&_31$$8, &appConfig, SL("ns"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_32$$8);
		ZEPHIR_CONCAT_VS(&_32$$8, &_31$$8, "Module");
		zephir_update_property_zval(this_ptr, SL("className"), &_32$$8);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, newDI) {

	zval mode, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&mode);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("runMode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&mode, &_0, "getvalue", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&mode, "Cli")) {
		object_init_ex(return_value, zephir_get_internal_ce(SL("phalcon\\di\\factorydefault\\cli")));
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		object_init_ex(return_value, zephir_get_internal_ce(SL("phalcon\\di\\factorydefault")));
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, checkout) {

	zval _8$$4, _10$$4;
	zend_class_entry *_14;
	zval _0, _5, _6, module, className, _12, _13, _15, _3$$3, _4$$3, _7$$4, _9$$4, _11$$4, _16$$5, _17$$5, _18$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&module);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_10$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isprimary", &_1, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_3$$3, this_ptr, SL("runMode"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_4$$3, &_3$$3, "getscriptpath", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_enum_sys_ce, "load", &_2, 0, &_4$$3);
		zephir_check_call_status();
	}
	zephir_read_property(&_5, this_ptr, SL("classPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_enum_sys_ce, "load", &_2, 0, &_5);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, SL("className"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_class_exists(&_6, 1))) {
		ZEPHIR_INIT_VAR(&_7$$4);
		object_init_ex(&_7$$4, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_8$$4);
		zephir_create_array(&_8$$4, 2, 0);
		ZEPHIR_INIT_VAR(&_9$$4);
		ZVAL_STRING(&_9$$4, "Module class (%s) not exists, ClassPath: %s ");
		zephir_array_fast_append(&_8$$4, &_9$$4);
		ZEPHIR_INIT_VAR(&_10$$4);
		zephir_create_array(&_10$$4, 2, 0);
		ZEPHIR_OBS_VAR(&_11$$4);
		zephir_read_property(&_11$$4, this_ptr, SL("className"), PH_NOISY_CC);
		zephir_array_fast_append(&_10$$4, &_11$$4);
		ZEPHIR_OBS_NVAR(&_11$$4);
		zephir_read_property(&_11$$4, this_ptr, SL("classPath"), PH_NOISY_CC);
		zephir_array_fast_append(&_10$$4, &_11$$4);
		zephir_array_fast_append(&_8$$4, &_10$$4);
		ZEPHIR_CALL_METHOD(NULL, &_7$$4, "__construct", NULL, 2, &_8$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$4, "phalconplus/App/Module/ModuleDef.zep", 116);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_12, this_ptr, SL("className"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&className, &_12);
	ZEPHIR_INIT_VAR(&module);
	zephir_fetch_safe_class(&_13, &className);
	_14 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_13), Z_STRLEN_P(&_13), ZEND_FETCH_CLASS_AUTO);
	if(!_14) {
		RETURN_MM_NULL();
	}
	object_init_ex(&module, _14);
	if (zephir_has_constructor(&module)) {
		zephir_read_property(&_12, this_ptr, SL("app"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &module, "__construct", NULL, 0, &_12, this_ptr);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_15, this_ptr, "isprimary", &_1, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_15)) {
		zephir_read_property(&_16$$5, this_ptr, SL("app"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_17$$5, &_16$$5, "di", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_18$$5);
		ZVAL_STRING(&_18$$5, "appModule");
		ZEPHIR_CALL_METHOD(NULL, &_17$$5, "setshared", NULL, 0, &_18$$5, &module);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &module, "registerautoloaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &module, "registerservices", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &module, "registerevents", NULL, 0);
	zephir_check_call_status();
	RETURN_CCTOR(&module);

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

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, config) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "config");

}

PHP_METHOD(PhalconPlus_App_Module_ModuleDef, app) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "app");

}

