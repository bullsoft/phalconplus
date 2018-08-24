
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

	zend_declare_property_null(phalconplus_base_moduledef_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_moduledef_ce, SL("runMode"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_bool(phalconplus_base_moduledef_ce, SL("isPrimary"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, __construct) {

	zephir_fcall_cache_entry *_4 = NULL, *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool isPrimary;
	zval *moduleDir = NULL, *_2$$3;
	zval *boot, *moduleDir_param = NULL, *isPrimary_param = NULL, *_0 = NULL, *_3 = NULL, *_5, *_6 = NULL, *_7, *appConfig = NULL, *_8, *_9, *_10, *_11, *_12, *_13, *_14, *_15, *_16 = NULL, *_17, *_18 = NULL, *_20, *_21, *_22 = NULL, *_1$$3, *_23$$4, *_24$$4, *_25$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &boot, &moduleDir_param, &isPrimary_param);

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
	if (!isPrimary_param) {
		isPrimary = 0;
	} else {
		isPrimary = zephir_get_boolval(isPrimary_param);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 36, moduleDir);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1$$3);
		object_init_ex(_1$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_2$$3);
		ZEPHIR_CONCAT_SV(_2$$3, "Module directory not exists or not a dir, file positon: ", moduleDir);
		ZEPHIR_CALL_METHOD(NULL, _1$$3, "__construct", NULL, 7, _2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1$$3, "phalconplus/Base/ModuleDef.zep", 42 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(getThis(), SL("dir"), moduleDir TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&_3, phalconplus_enum_sys_ce, "getmoduleconfigpath", &_4, 37, moduleDir);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("configPath"), _3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_5);
	object_init_ex(_5, zephir_get_internal_ce(SS("phalcon\\config") TSRMLS_CC));
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("configPath"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_6, boot, "load", NULL, 38, _7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _5, "__construct", NULL, 0, _6);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("config"), _5 TSRMLS_CC);
	_8 = zephir_fetch_nproperty_this(this_ptr, SL("config"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(appConfig);
	zephir_read_property(&appConfig, _8, SL("application"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_9);
	zephir_read_property(&_9, appConfig, SL("name"), PH_NOISY_CC);
	zephir_update_property_this(getThis(), SL("name"), _9 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_10);
	object_init_ex(_10, phalconplus_enum_runmode_ce);
	ZEPHIR_INIT_VAR(_11);
	ZEPHIR_INIT_VAR(_12);
	ZEPHIR_OBS_VAR(_13);
	zephir_read_property(&_13, appConfig, SL("mode"), PH_NOISY_CC);
	zephir_fast_strtolower(_12, _13);
	zephir_ucfirst(_11, _12);
	ZEPHIR_CALL_METHOD(NULL, _10, "__construct", NULL, 39, _11);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("runMode"), _10 TSRMLS_CC);
	ZEPHIR_OBS_VAR(_14);
	zephir_read_property(&_14, appConfig, SL("ns"), PH_NOISY_CC);
	_15 = zephir_fetch_nproperty_this(this_ptr, SL("runMode"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_16, _15, "getmapclassname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_17);
	ZEPHIR_CONCAT_VV(_17, _14, _16);
	zephir_update_property_this(getThis(), SL("className"), _17 TSRMLS_CC);
	_20 = zephir_fetch_nproperty_this(this_ptr, SL("runMode"), PH_NOISY_CC);
	ZEPHIR_CALL_CE_STATIC(&_18, phalconplus_enum_sys_ce, "getmoduleclasspath", &_19, 40, moduleDir, _20);
	zephir_check_call_status();
	zephir_update_property_this(getThis(), SL("classPath"), _18 TSRMLS_CC);
	_21 = zephir_fetch_nproperty_this(this_ptr, SL("classPath"), PH_NOISY_CC);
	ZEPHIR_CALL_FUNCTION(&_22, "is_file", NULL, 41, _21);
	zephir_check_call_status();
	if (!(zephir_is_true(_22))) {
		ZEPHIR_INIT_VAR(_23$$4);
		object_init_ex(_23$$4, zend_exception_get_default(TSRMLS_C));
		_24$$4 = zephir_fetch_nproperty_this(this_ptr, SL("classPath"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_25$$4);
		ZEPHIR_CONCAT_SV(_25$$4, "Module class file not exists: ", _24$$4);
		ZEPHIR_CALL_METHOD(NULL, _23$$4, "__construct", NULL, 7, _25$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_23$$4, "phalconplus/Base/ModuleDef.zep", 61 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (isPrimary) {
		zephir_update_property_this(getThis(), SL("isPrimary"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
	} else {
		zephir_update_property_this(getThis(), SL("isPrimary"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, impl) {

	zend_class_entry *_7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di, *_0, *_1, *className = NULL, *_5, *_6 = NULL, *_2$$3, *_3$$3, *_4$$3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &di);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("classPath"), PH_NOISY_CC);
	if (zephir_require_zval(_0 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("className"), PH_NOISY_CC);
	if (!(zephir_class_exists(_1, 1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(_2$$3);
		object_init_ex(_2$$3, zend_exception_get_default(TSRMLS_C));
		_3$$3 = zephir_fetch_nproperty_this(this_ptr, SL("className"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_4$$3);
		ZEPHIR_CONCAT_SV(_4$$3, "Module class not exists: ", _3$$3);
		ZEPHIR_CALL_METHOD(NULL, _2$$3, "__construct", NULL, 7, _4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(_2$$3, "phalconplus/Base/ModuleDef.zep", 71 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_5 = zephir_fetch_nproperty_this(this_ptr, SL("className"), PH_NOISY_CC);
	ZEPHIR_CPY_WRT(className, _5);
	zephir_fetch_safe_class(_6, className);
		_7 = zend_fetch_class(Z_STRVAL_P(_6), Z_STRLEN_P(_6), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _7);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, di, this_ptr);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getIsPrimary) {

	

	RETURN_MEMBER(getThis(), "isPrimary");

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getClassPath) {

	

	RETURN_MEMBER(getThis(), "classPath");

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getClassName) {

	

	RETURN_MEMBER(getThis(), "className");

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getRunMode) {

	

	RETURN_MEMBER(getThis(), "runMode");

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getMapClassName) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("runMode"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getmapclassname", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getMode) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("runMode"), PH_NOISY_CC);
	ZEPHIR_RETURN_CALL_METHOD(_0, "getvalue", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getName) {

	

	RETURN_MEMBER(getThis(), "name");

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getConfigPath) {

	

	RETURN_MEMBER(getThis(), "configPath");

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getConfig) {

	

	RETURN_MEMBER(getThis(), "config");

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getDir) {

	

	RETURN_MEMBER(getThis(), "dir");

}

