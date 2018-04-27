
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
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_ModuleDef) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Base, ModuleDef, phalconplus, base_moduledef, phalconplus_base_moduledef_method_entry, 0);

	zend_declare_property_string(phalconplus_base_moduledef_ce, SL("classPath"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalconplus_base_moduledef_ce, SL("className"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalconplus_base_moduledef_ce, SL("name"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalconplus_base_moduledef_ce, SL("configPath"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_moduledef_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_moduledef_ce, SL("runMode"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, __construct) {

	zval _3, _7$$4;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval modulePath, _2$$3;
	zval *boot, boot_sub, *modulePath_param = NULL, _0, confPath, confPrefix, _4, _5, _12, _13, appConfig, _14, _15, _16, _17, _18, _19, _20, _21, _22, _23, _24, _25, _26, _27, _28, _1$$3, _8$$4, _9$$4, _10$$5, _11$$5, _29$$6, _30$$6, _31$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&boot_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&confPath);
	ZVAL_UNDEF(&confPrefix);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&appConfig);
	ZVAL_UNDEF(&_14);
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
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_29$$6);
	ZVAL_UNDEF(&_30$$6);
	ZVAL_UNDEF(&_31$$6);
	ZVAL_UNDEF(&modulePath);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &boot, &modulePath_param);

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


	ZEPHIR_CALL_FUNCTION(&_0, "is_dir", NULL, 35, &modulePath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "Module directory not exists or not a dir, file positon: ", &modulePath);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", NULL, 7, &_2$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalconplus/Base/ModuleDef.zep", 37 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 3, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "app");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "config");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZEPHIR_GET_CONSTANT(&_4, "APP_ENV");
	zephir_array_fast_append(&_3, &_4);
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "/");
	ZEPHIR_INIT_VAR(&confPrefix);
	zephir_fast_join(&confPrefix, &_4, &_3 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&confPath);
	ZEPHIR_CONCAT_VVS(&confPath, &modulePath, &confPrefix, ".php");
	ZEPHIR_CALL_FUNCTION(&_5, "is_file", &_6, 36, &confPath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_5))) {
		ZEPHIR_INIT_VAR(&_7$$4);
		zephir_create_array(&_7$$4, 3, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "app");
		zephir_array_fast_append(&_7$$4, &_8$$4);
		ZEPHIR_INIT_NVAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "config");
		zephir_array_fast_append(&_7$$4, &_8$$4);
		ZEPHIR_INIT_NVAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "config");
		zephir_array_fast_append(&_7$$4, &_8$$4);
		ZEPHIR_INIT_NVAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "/");
		ZEPHIR_INIT_NVAR(&confPrefix);
		zephir_fast_join(&confPrefix, &_8$$4, &_7$$4 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&confPath);
		ZEPHIR_CONCAT_VVS(&confPath, &modulePath, &confPrefix, ".php");
		ZEPHIR_CALL_FUNCTION(&_9$$4, "is_file", &_6, 36, &confPath);
		zephir_check_call_status();
		if (!(zephir_is_true(&_9$$4))) {
			ZEPHIR_INIT_VAR(&_10$$5);
			object_init_ex(&_10$$5, zephir_get_internal_ce(SL("phalcon\\config\\exception")));
			ZEPHIR_INIT_VAR(&_11$$5);
			ZEPHIR_CONCAT_SV(&_11$$5, "Module config file not exist, file position: ", &confPath);
			ZEPHIR_CALL_METHOD(NULL, &_10$$5, "__construct", NULL, 0, &_11$$5);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_10$$5, "phalconplus/Base/ModuleDef.zep", 57 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	zephir_update_property_zval(this_ptr, SL("configPath"), &confPath);
	ZEPHIR_INIT_VAR(&_12);
	object_init_ex(&_12, zephir_get_internal_ce(SL("phalcon\\config")));
	ZEPHIR_CALL_METHOD(&_13, boot, "load", NULL, 37, &confPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_12, "__construct", NULL, 0, &_13);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("config"), &_12);
	zephir_read_property(&_14, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&appConfig);
	zephir_read_property(&appConfig, &_14, SL("application"), PH_NOISY_CC);
	zephir_read_property(&_15, &appConfig, SL("name"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("name"), &_15);
	ZEPHIR_INIT_VAR(&_16);
	object_init_ex(&_16, phalconplus_enum_runmode_ce);
	ZEPHIR_INIT_VAR(&_17);
	ZEPHIR_INIT_VAR(&_18);
	zephir_read_property(&_19, &appConfig, SL("mode"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_strtolower(&_18, &_19);
	zephir_ucfirst(&_17, &_18);
	ZEPHIR_CALL_METHOD(NULL, &_16, "__construct", NULL, 38, &_17);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("runMode"), &_16);
	zephir_read_property(&_20, &appConfig, SL("ns"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_21, this_ptr, SL("runMode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_22, &_21, "getmapclassname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_23);
	ZEPHIR_CONCAT_VV(&_23, &_20, &_22);
	zephir_update_property_zval(this_ptr, SL("className"), &_23);
	zephir_read_property(&_24, this_ptr, SL("runMode"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_25, &_24, "getmapclassname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_26);
	ZEPHIR_CONCAT_VSSVS(&_26, &modulePath, "app", "/", &_25, ".php");
	zephir_update_property_zval(this_ptr, SL("classPath"), &_26);
	zephir_read_property(&_27, this_ptr, SL("classPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_28, "is_file", &_6, 36, &_27);
	zephir_check_call_status();
	if (!(zephir_is_true(&_28))) {
		ZEPHIR_INIT_VAR(&_29$$6);
		object_init_ex(&_29$$6, zend_exception_get_default(TSRMLS_C));
		zephir_read_property(&_30$$6, this_ptr, SL("classPath"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_31$$6);
		ZEPHIR_CONCAT_SV(&_31$$6, "Module class file not exists: ", &_30$$6);
		ZEPHIR_CALL_METHOD(NULL, &_29$$6, "__construct", NULL, 7, &_31$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_29$$6, "phalconplus/Base/ModuleDef.zep", 74 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, mount) {

	zend_class_entry *_7;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di, di_sub, _0, _1, className, _5, _6, _2$$3, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &di);



	zephir_read_property(&_0, this_ptr, SL("classPath"), PH_NOISY_CC | PH_READONLY);
	if (zephir_require_zval(&_0 TSRMLS_CC) == FAILURE) {
		RETURN_MM_NULL();
	}
	zephir_read_property(&_1, this_ptr, SL("className"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_class_exists(&_1, 1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, zend_exception_get_default(TSRMLS_C));
		zephir_read_property(&_3$$3, this_ptr, SL("className"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SV(&_4$$3, "Module class not exists: ", &_3$$3);
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 7, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalconplus/Base/ModuleDef.zep", 82 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_5, this_ptr, SL("className"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&className, &_5);
	zephir_fetch_safe_class(&_6, &className);
	_7 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_6), Z_STRLEN_P(&_6), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(return_value, _7);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, di);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getClassPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "classPath");

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

