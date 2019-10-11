
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


ZEPHIR_INIT_CLASS(PhalconPlus_Base_ModuleDef) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Base, ModuleDef, phalconplus, base_moduledef, phalconplus_base_moduledef_method_entry, 0);

	zend_declare_property_string(phalconplus_base_moduledef_ce, SL("classPath"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalconplus_base_moduledef_ce, SL("className"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalconplus_base_moduledef_ce, SL("name"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalconplus_base_moduledef_ce, SL("configPath"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalconplus_base_moduledef_ce, SL("dir"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_moduledef_ce, SL("loadedClasses"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_moduledef_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_moduledef_ce, SL("runMode"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_moduledef_ce, SL("bootstrap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalconplus_base_moduledef_ce, SL("isPrimary"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_20 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool isPrimary;
	zval moduleDir, _2$$3;
	zval *boot, boot_sub, *moduleDir_param = NULL, *isPrimary_param = NULL, __$true, __$false, _0, _3, _5, _6, _7, _8, appConfig, _9, _10, _11, _12, _13, _14, _15, _16, _17, _18, _19, _21, _22, _23, _1$$3, _24$$5, _25$$5, _26$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&boot_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&appConfig);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_24$$5);
	ZVAL_UNDEF(&_25$$5);
	ZVAL_UNDEF(&_26$$5);
	ZVAL_UNDEF(&moduleDir);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &boot, &moduleDir_param, &isPrimary_param);

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
	if (!isPrimary_param) {
		isPrimary = 0;
	} else {
		isPrimary = zephir_get_boolval(isPrimary_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 41, &moduleDir);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Module directory not exists or not a dir, file positon: ", &moduleDir);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 7, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Base/ModuleDef.zep", 46 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, SL("dir"), &moduleDir);
	ZEPHIR_CALL_CE_STATIC(&_3, phalconplus_enum_sys_ce, "getmoduleconfigpath", &_4, 0, &moduleDir);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("configPath"), &_3);
	ZEPHIR_INIT_VAR(&_5);
	object_init_ex(&_5, zephir_get_internal_ce(SL("phalcon\\config")));
	zephir_read_property(&_7, this_ptr, SL("configPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_6, boot, "load", NULL, 42, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_5, "__construct", NULL, 0, &_6);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("config"), &_5);
	zephir_read_property(&_8, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset_string(&_8, SL("application")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "Config Path: /application must exists", "phalconplus/Base/ModuleDef.zep", 55);
		return;
	}
	zephir_read_property(&_9, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&appConfig);
	zephir_read_property(&appConfig, &_9, SL("application"), PH_NOISY_CC);
	zephir_read_property(&_10, &appConfig, SL("name"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("name"), &_10);
	ZEPHIR_INIT_VAR(&_11);
	object_init_ex(&_11, phalconplus_enum_runmode_ce);
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_INIT_VAR(&_13);
	zephir_read_property(&_14, &appConfig, SL("mode"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_strtolower(&_13, &_14);
	zephir_ucfirst(&_12, &_13);
	ZEPHIR_CALL_METHOD(NULL, &_11, "__construct", NULL, 43, &_12);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("runMode"), &_11);
	zephir_read_property(&_15, &appConfig, SL("ns"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_16, this_ptr, SL("runMode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_17, &_16, "getmapclassname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_18);
	ZEPHIR_CONCAT_VV(&_18, &_15, &_17);
	zephir_update_property_zval(this_ptr, SL("className"), &_18);
	zephir_read_property(&_21, this_ptr, SL("runMode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(&_19, phalconplus_enum_sys_ce, "getmoduleclasspath", &_20, 0, &moduleDir, &_21);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("classPath"), &_19);
	zephir_read_property(&_22, this_ptr, SL("classPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_23, "is_file", NULL, 44, &_22);
	zephir_check_call_status();
	if (!(zephir_is_true(&_23))) {
		ZEPHIR_INIT_VAR(&_24$$5);
		object_init_ex(&_24$$5, zend_exception_get_default(TSRMLS_C));
		zephir_read_property(&_25$$5, this_ptr, SL("classPath"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_26$$5);
		ZEPHIR_CONCAT_SV(&_26$$5, "Module class file not exists: ", &_25$$5);
		ZEPHIR_CALL_METHOD(NULL, &_24$$5, "__construct", NULL, 7, &_26$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_24$$5, "phalconplus/Base/ModuleDef.zep", 67 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, SL("bootstrap"), boot);
	if (isPrimary) {
		zephir_update_property_zval(this_ptr, SL("isPrimary"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("isPrimary"), &__$false);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, impl) {

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



	zephir_read_static_property_ce(&_0, phalconplus_base_moduledef_ce, SL("loadedClasses"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("className"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_isset(&_0, &_1))) {
		zephir_read_property(&_2$$3, this_ptr, SL("classPath"), PH_NOISY_CC | PH_READONLY);
		if (zephir_require_zval(&_2$$3 TSRMLS_CC) == FAILURE) {
			RETURN_MM_NULL();
		}
	}
	zephir_read_property(&_3, this_ptr, SL("className"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_class_exists(&_3, 1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_4$$4);
		object_init_ex(&_4$$4, zend_exception_get_default(TSRMLS_C));
		zephir_read_property(&_5$$4, this_ptr, SL("className"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_6$$4);
		ZEPHIR_CONCAT_SV(&_6$$4, "Module class not exists: ", &_5$$4);
		ZEPHIR_CALL_METHOD(NULL, &_4$$4, "__construct", NULL, 7, &_6$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$4, "phalconplus/Base/ModuleDef.zep", 79 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_LONG(&_7, 1);
	ZEPHIR_OBS_VAR(&_8);
	zephir_read_property(&_8, this_ptr, SL("className"), PH_NOISY_CC);
	zephir_update_static_property_array_multi_ce(phalconplus_base_moduledef_ce, SL("loadedClasses"), &_7 TSRMLS_CC, SL("z"), 1, &_8);
	zephir_read_property(&_9, this_ptr, SL("className"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&className, &_9);
	zephir_fetch_safe_class(&_10, &className);
	_11 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_10), Z_STRLEN_P(&_10), ZEND_FETCH_CLASS_AUTO);
	if(!_11) {
		RETURN_MM_NULL();
	}
	object_init_ex(return_value, _11);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, di, this_ptr);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getIsPrimary) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "isPrimary");

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getClassPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "classPath");

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getBootstrap) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "bootstrap");

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getClassName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "className");

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getRunMode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "runMode");

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getMapClassName) {

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

PHP_METHOD(PhalconPlus_Base_ModuleDef, getMode) {

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

PHP_METHOD(PhalconPlus_Base_ModuleDef, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getConfigPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "configPath");

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getConfig) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "config");

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getDir) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "dir");

}

void zephir_init_static_properties_PhalconPlus_Base_ModuleDef(TSRMLS_D) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(phalconplus_base_moduledef_ce, ZEND_STRL("loadedClasses"), &_0);
	ZEPHIR_MM_RESTORE();

}

