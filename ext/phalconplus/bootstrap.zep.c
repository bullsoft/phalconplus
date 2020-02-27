
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/main.h"
#include "kernel/require.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Bootstrap) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus, Bootstrap, phalconplus, bootstrap, phalconplus_bootstrap_method_entry, ZEND_ACC_FINAL_CLASS);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("app"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_bootstrap_ce, SL("loadedFiles"), ZEND_ACC_PROTECTED);

	phalconplus_bootstrap_ce->create_object = zephir_init_properties_PhalconPlus_Bootstrap;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Bootstrap, getApp) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "app");

}

PHP_METHOD(PhalconPlus_Bootstrap, getLoadedFiles) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "loadedFiles");

}

PHP_METHOD(PhalconPlus_Bootstrap, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *moduleDir_param = NULL, *env_param = NULL, _1, _2, _3;
	zval moduleDir, env;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&moduleDir);
	ZVAL_UNDEF(&env);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &moduleDir_param, &env_param);

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
	if (!env_param) {
		ZEPHIR_INIT_VAR(&env);
		ZVAL_STRING(&env, "");
	} else {
		zephir_get_strval(&env, env_param);
	}


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_enum_sys_ce, "init", &_0, 0, &moduleDir);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalconplus_app_app_ce);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 68, this_ptr);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("app"), &_1);
	zephir_read_property(&_2, this_ptr, SL("app"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "initconf", NULL, 69);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_2, "boot", NULL, 0, &_3, &env);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, initConf) {

	zval globalConf, globalConfPath, _1, _2$$3, _3$$3, _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_4 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&globalConf);
	ZVAL_UNDEF(&globalConfPath);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&globalConfPath, phalconplus_enum_sys_ce, "getglobalconfigpath", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "is_file", NULL, 43, &globalConfPath);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&globalConf);
	if (UNEXPECTED(!zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		ZEPHIR_CONCAT_SV(&_2$$3, "PHP Notice:  PhalconPlus\\Bootstrap Global config file not exists: ", &globalConfPath);
		ZEPHIR_CALL_FUNCTION(NULL, "error_log", NULL, 1, &_2$$3);
		zephir_check_call_status();
		object_init_ex(&globalConf, zephir_get_internal_ce(SL("phalcon\\config")));
		ZEPHIR_INIT_VAR(&_3$$3);
		array_init(&_3$$3);
		ZEPHIR_CALL_METHOD(NULL, &globalConf, "__construct", &_4, 0, &_3$$3);
		zephir_check_call_status();
	} else {
		object_init_ex(&globalConf, zephir_get_internal_ce(SL("phalcon\\config")));
		ZEPHIR_CALL_METHOD(&_5$$4, this_ptr, "load", NULL, 70, &globalConfPath);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &globalConf, "__construct", &_4, 0, &_5$$4);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&globalConf);

}

PHP_METHOD(PhalconPlus_Bootstrap, exec) {

	zval _1, _2;
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("app"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "handle");
	zephir_array_fast_append(&_0, &_2);
	ZEPHIR_INIT_NVAR(&_2);
	zephir_get_args(&_2);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_0, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Bootstrap, load) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *filePath, filePath_sub, _0, loader, config, superapp, di, bootstrap, rootPath, fileRet, _3, _4, _6, _7, _8, _9, _10, _17, _1$$4, _2$$4, _11$$6, _12$$6, _13$$6, _14$$6, _15$$6, _16$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filePath_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&loader);
	ZVAL_UNDEF(&config);
	ZVAL_UNDEF(&superapp);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&bootstrap);
	ZVAL_UNDEF(&rootPath);
	ZVAL_UNDEF(&fileRet);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &filePath);



	if (UNEXPECTED(!(Z_TYPE_P(filePath) == IS_STRING))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_FUNCTION(&_0, "is_file", NULL, 43, filePath);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_2$$4);
		ZEPHIR_CONCAT_SV(&_2$$4, "The file you try to load is not exists. file position: ", filePath);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 2, &_2$$4);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalconplus/Bootstrap.zep", 57);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&fileRet);
	zephir_read_property(&_3, this_ptr, SL("loadedFiles"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&fileRet, &_3, filePath, 0)) {
		RETURN_CCTOR(&fileRet);
	}
	ZEPHIR_INIT_VAR(&rootPath);
	ZVAL_STRING(&rootPath, "rootPath");
	ZEPHIR_INIT_VAR(&loader);
	ZVAL_STRING(&loader, "loader");
	ZEPHIR_INIT_VAR(&config);
	ZVAL_STRING(&config, "config");
	ZEPHIR_INIT_VAR(&superapp);
	ZVAL_STRING(&superapp, "superapp");
	ZEPHIR_INIT_VAR(&bootstrap);
	ZVAL_STRING(&bootstrap, "bootstrap");
	ZEPHIR_INIT_VAR(&di);
	ZVAL_STRING(&di, "di");
	ZEPHIR_CALL_CE_STATIC(&_4, phalconplus_enum_sys_ce, "getrootdir", &_5, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&_6, &_4);
	if (zephir_set_symbol(&rootPath, &_6) == FAILURE) {
		return;
	}
	ZEPHIR_INIT_VAR(&_7);
	object_init_ex(&_7, zephir_get_internal_ce(SL("phalcon\\loader")));
	if (zephir_has_constructor(&_7)) {
		ZEPHIR_CALL_METHOD(NULL, &_7, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CPY_WRT(&_8, &_7);
	if (zephir_set_symbol(&loader, &_8) == FAILURE) {
		return;
	}
	ZEPHIR_CPY_WRT(&_9, this_ptr);
	if (zephir_set_symbol(&bootstrap, &_9) == FAILURE) {
		return;
	}
	zephir_read_property(&_10, this_ptr, SL("app"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, &_10, "isbooted", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_4)) {
		zephir_read_property(&_11$$6, this_ptr, SL("app"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&_12$$6, &_11$$6);
		if (zephir_set_symbol(&superapp, &_12$$6) == FAILURE) {
			return;
		}
		zephir_read_property(&_11$$6, this_ptr, SL("app"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_13$$6, &_11$$6, "getconfig", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&_14$$6, &_13$$6);
		if (zephir_set_symbol(&config, &_14$$6) == FAILURE) {
			return;
		}
		zephir_read_property(&_15$$6, this_ptr, SL("app"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_13$$6, &_15$$6, "getdi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&_16$$6, &_13$$6);
		if (zephir_set_symbol(&di, &_16$$6) == FAILURE) {
			return;
		}
	}
	ZEPHIR_OBSERVE_OR_NULLIFY_PPZV(&_17);
	if (zephir_require_zval_ret(&_17, filePath) == FAILURE) {
		RETURN_MM_NULL();
	}
	ZEPHIR_CPY_WRT(&fileRet, &_17);
	zephir_update_property_array(this_ptr, SL("loadedFiles"), filePath, &fileRet);
	RETURN_CCTOR(&fileRet);

}

PHP_METHOD(PhalconPlus_Bootstrap, terminate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval _SESSION, _POST, _GET, _SERVER, _REQUEST, _COOKIE, _FILES, __$null, _0, _1, _3, _4, _2$$4;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_SESSION);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_REQUEST);
	ZVAL_UNDEF(&_COOKIE);
	ZVAL_UNDEF(&_FILES);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_get_global(&_REQUEST, SL("_REQUEST"));
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_get_global(&_GET, SL("_GET"));
	zephir_get_global(&_POST, SL("_POST"));
	zephir_get_global(&_SESSION, SL("_SESSION"));

	ZEPHIR_CALL_FUNCTION(&_0, "session_status", NULL, 71);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_0, 2)) {
		ZEPHIR_CALL_FUNCTION(NULL, "session_write_close", NULL, 72);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&_1, "headers_sent", NULL, 73);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_INIT_VAR(&_2$$4);
		ZVAL_STRING(&_2$$4, "");
		ZEPHIR_CALL_FUNCTION(NULL, "session_id", NULL, 74, &_2$$4);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(NULL, "session_unset", NULL, 75);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_SESSION);
	array_init(&_SESSION);
	ZEPHIR_INIT_NVAR(&_POST);
	array_init(&_POST);
	ZEPHIR_INIT_NVAR(&_GET);
	array_init(&_GET);
	ZEPHIR_INIT_NVAR(&_SERVER);
	array_init(&_SERVER);
	ZEPHIR_INIT_NVAR(&_REQUEST);
	array_init(&_REQUEST);
	ZEPHIR_INIT_NVAR(&_COOKIE);
	array_init(&_COOKIE);
	ZEPHIR_INIT_NVAR(&_FILES);
	array_init(&_FILES);
	zephir_read_property(&_3, this_ptr, SL("app"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_3, "terminate", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("app"), &__$null);
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	zephir_update_property_zval(this_ptr, SL("loadedFiles"), &_4);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Bootstrap, __destruct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "terminate", NULL, 76);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_PhalconPlus_Bootstrap(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("loadedFiles"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("loadedFiles"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

