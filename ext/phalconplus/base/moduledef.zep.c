
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_ModuleDef) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Base, ModuleDef, phalconplus, base_moduledef, phalconplus_base_moduledef_method_entry, 0);

	zend_declare_property_string(phalconplus_base_moduledef_ce, SL("classPath"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalconplus_base_moduledef_ce, SL("className"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalconplus_base_moduledef_ce, SL("mode"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_moduledef_ce, SL("config"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_moduledef_ce, SL("modeMap"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalconplus_base_moduledef_ce->create_object = zephir_init_properties_PhalconPlus_Base_ModuleDef;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *boot, boot_sub, confPath, _0, _1, _2, _8, _9, _10, _11, _12, _13, _14, _15, _16, _20, _21, _22, _23, _24, _25, _26, _27, _28, _29, _30, _31, _32, _33, _37, _38, _4$$3, _5$$3, _6$$4, _7$$4, _17$$5, _18$$5, _19$$5, _34$$6, _35$$6, _36$$6, _39$$7, _40$$7, _41$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&boot_sub);
	ZVAL_UNDEF(&confPath);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_20);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_33);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$5);
	ZVAL_UNDEF(&_19$$5);
	ZVAL_UNDEF(&_34$$6);
	ZVAL_UNDEF(&_35$$6);
	ZVAL_UNDEF(&_36$$6);
	ZVAL_UNDEF(&_39$$7);
	ZVAL_UNDEF(&_40$$7);
	ZVAL_UNDEF(&_41$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &boot);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_GET_CONSTANT(&_0, "APP_MODULE_DIR");
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_GET_CONSTANT(&_1, "APP_ENV");
	ZEPHIR_INIT_VAR(&confPath);
	ZEPHIR_CONCAT_VSSSSVS(&confPath, &_0, "app", "/", "config", "/", &_1, ".php");
	ZEPHIR_CALL_FUNCTION(&_2, "is_file", &_3, 35, &confPath);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_GET_CONSTANT(&_4$$3, "APP_MODULE_DIR");
		ZEPHIR_INIT_NVAR(&confPath);
		ZEPHIR_CONCAT_VSSSSSS(&confPath, &_4$$3, "app", "/", "config", "/", "config", ".php");
		ZEPHIR_CALL_FUNCTION(&_5$$3, "is_file", &_3, 35, &confPath);
		zephir_check_call_status();
		if (!(zephir_is_true(&_5$$3))) {
			ZEPHIR_INIT_VAR(&_6$$4);
			object_init_ex(&_6$$4, zephir_get_internal_ce(SL("phalcon\\config\\exception")));
			ZEPHIR_INIT_VAR(&_7$$4);
			ZEPHIR_CONCAT_SV(&_7$$4, "Module config file not exist, file position: ", &confPath);
			ZEPHIR_CALL_METHOD(NULL, &_6$$4, "__construct", NULL, 0, &_7$$4);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_6$$4, "phalconplus/Base/ModuleDef.zep", 48 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_8);
	object_init_ex(&_8, zephir_get_internal_ce(SL("phalcon\\config")));
	ZEPHIR_CALL_METHOD(&_9, boot, "load", NULL, 36, &confPath);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_8, "__construct", NULL, 0, &_9);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("config"), &_8);
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_INIT_VAR(&_11);
	zephir_read_property(&_12, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_13, &_12, SL("application"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_14, &_13, SL("mode"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_strtolower(&_11, &_14);
	zephir_ucfirst(&_10, &_11);
	zephir_update_property_zval(this_ptr, SL("mode"), &_10);
	zephir_read_property(&_15, this_ptr, SL("mode"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_16, this_ptr, SL("modeMap"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&_16, &_15 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_17$$5);
		object_init_ex(&_17$$5, zend_exception_get_default(TSRMLS_C));
		zephir_read_property(&_18$$5, this_ptr, SL("mode"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_19$$5);
		ZEPHIR_CONCAT_SV(&_19$$5, "Module mode not exists: ", &_18$$5);
		ZEPHIR_CALL_METHOD(NULL, &_17$$5, "__construct", NULL, 7, &_19$$5);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_17$$5, "phalconplus/Base/ModuleDef.zep", 56 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_20, this_ptr, SL("config"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_21, &_20, SL("application"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_22, &_21, SL("ns"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_23, this_ptr, SL("modeMap"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_25);
	zephir_read_property(&_25, this_ptr, SL("mode"), PH_NOISY_CC);
	zephir_array_fetch(&_24, &_23, &_25, PH_NOISY | PH_READONLY, "phalconplus/Base/ModuleDef.zep", 59 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_26);
	ZEPHIR_CONCAT_VV(&_26, &_22, &_24);
	zephir_update_property_zval(this_ptr, SL("className"), &_26);
	ZEPHIR_INIT_VAR(&_27);
	ZEPHIR_GET_CONSTANT(&_27, "APP_MODULE_DIR");
	zephir_read_property(&_28, this_ptr, SL("modeMap"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_30);
	zephir_read_property(&_30, this_ptr, SL("mode"), PH_NOISY_CC);
	zephir_array_fetch(&_29, &_28, &_30, PH_NOISY | PH_READONLY, "phalconplus/Base/ModuleDef.zep", 60 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_31);
	ZEPHIR_CONCAT_VSSVS(&_31, &_27, "app", "/", &_29, ".php");
	zephir_update_property_zval(this_ptr, SL("classPath"), &_31);
	zephir_read_property(&_32, this_ptr, SL("classPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_33, "is_file", &_3, 35, &_32);
	zephir_check_call_status();
	if (!(zephir_is_true(&_33))) {
		ZEPHIR_INIT_VAR(&_34$$6);
		object_init_ex(&_34$$6, zend_exception_get_default(TSRMLS_C));
		zephir_read_property(&_35$$6, this_ptr, SL("classPath"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_36$$6);
		ZEPHIR_CONCAT_SV(&_36$$6, "Module class file not exists: ", &_35$$6);
		ZEPHIR_CALL_METHOD(NULL, &_34$$6, "__construct", NULL, 7, &_36$$6);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_34$$6, "phalconplus/Base/ModuleDef.zep", 63 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_37, this_ptr, SL("classPath"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "require_once", NULL, 0, &_37);
	zephir_check_call_status();
	zephir_read_property(&_38, this_ptr, SL("className"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_class_exists(&_38, 1 TSRMLS_CC))) {
		ZEPHIR_INIT_VAR(&_39$$7);
		object_init_ex(&_39$$7, zend_exception_get_default(TSRMLS_C));
		zephir_read_property(&_40$$7, this_ptr, SL("className"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_41$$7);
		ZEPHIR_CONCAT_SV(&_41$$7, "Module class not exists: ", &_40$$7);
		ZEPHIR_CALL_METHOD(NULL, &_39$$7, "__construct", NULL, 7, &_41$$7);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_39$$7, "phalconplus/Base/ModuleDef.zep", 67 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getClassPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "classPath");

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getClassName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "className");

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getMode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "mode");

}

PHP_METHOD(PhalconPlus_Base_ModuleDef, getConfig) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "config");

}

zend_object *zephir_init_properties_PhalconPlus_Base_ModuleDef(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("modeMap"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_1$$3, SL("Web"), SL("Module"));
			add_assoc_stringl_ex(&_1$$3, SL("Cli"), SL("Task"));
			add_assoc_stringl_ex(&_1$$3, SL("Srv"), SL("Srv"));
			add_assoc_stringl_ex(&_1$$3, SL("Micro"), SL("Micro"));
			zephir_update_property_zval(this_ptr, SL("modeMap"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

