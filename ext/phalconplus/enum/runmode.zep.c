
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
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Enum_RunMode) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Enum, RunMode, phalconplus, enum_runmode, phalconplus_enum_abstractenum_ce, phalconplus_enum_runmode_method_entry, 0);

	zend_declare_property_null(phalconplus_enum_runmode_ce, SL("mapClasses"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_enum_runmode_ce, SL("scripts"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalconplus_enum_runmode_ce->create_object = zephir_init_properties_PhalconPlus_Enum_RunMode;
	zephir_declare_class_constant_string(phalconplus_enum_runmode_ce, SL("WEB"), "Web");

	zephir_declare_class_constant_string(phalconplus_enum_runmode_ce, SL("CLI"), "Cli");

	zephir_declare_class_constant_string(phalconplus_enum_runmode_ce, SL("SRV"), "Srv");

	zephir_declare_class_constant_string(phalconplus_enum_runmode_ce, SL("MICRO"), "Micro");

	zephir_declare_class_constant_string(phalconplus_enum_runmode_ce, SL("__default"), "Cli");

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Enum_RunMode, getScriptPath) {

	zval script, _0, _2, _3, _4, _5, _6$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&script);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_CE_STATIC(&_0, phalconplus_enum_sys_ce, "getgloballoaddir", &_1, 0);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("scripts"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_4);
	zephir_read_property(&_4, this_ptr, SL("val"), PH_NOISY_CC);
	zephir_array_fetch(&_3, &_2, &_4, PH_NOISY | PH_READONLY, "phalconplus/Enum/RunMode.zep", 35 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&script);
	ZEPHIR_CONCAT_VV(&script, &_0, &_3);
	ZEPHIR_CALL_FUNCTION(&_5, "is_file", NULL, 41, &script);
	zephir_check_call_status();
	if (!(zephir_is_true(&_5))) {
		ZEPHIR_INIT_VAR(&_6$$3);
		ZEPHIR_CONCAT_SV(&_6$$3, "PHP Notice:  PhalconPlus\\Bootstrap Global load file not exists: ", &script);
		ZEPHIR_CALL_FUNCTION(NULL, "error_log", NULL, 63, &_6$$3);
		zephir_check_call_status();
		RETURN_MM_NULL();
	}
	RETURN_CCTOR(&script);

}

PHP_METHOD(PhalconPlus_Enum_RunMode, getMapClassName) {

	zval _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("mapClasses"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("val"), PH_NOISY_CC);
	zephir_array_fetch(&_1, &_0, &_2, PH_NOISY | PH_READONLY, "phalconplus/Enum/RunMode.zep", 45 TSRMLS_CC);
	RETURN_CTOR(&_1);

}

zend_object *zephir_init_properties_PhalconPlus_Enum_RunMode(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3, _3$$4;
	zval _0, _2;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("scripts"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_1$$3, SL("Web"), SL("default-web.php"));
			add_assoc_stringl_ex(&_1$$3, SL("Cli"), SL("default-cli.php"));
			add_assoc_stringl_ex(&_1$$3, SL("Srv"), SL("default-web.php"));
			add_assoc_stringl_ex(&_1$$3, SL("Micro"), SL("default-micro.php"));
			zephir_update_property_zval(this_ptr, SL("scripts"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("mapClasses"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			zephir_create_array(&_3$$4, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_3$$4, SL("Web"), SL("Module"));
			add_assoc_stringl_ex(&_3$$4, SL("Cli"), SL("Task"));
			add_assoc_stringl_ex(&_3$$4, SL("Srv"), SL("Srv"));
			add_assoc_stringl_ex(&_3$$4, SL("Micro"), SL("Micro"));
			zephir_update_property_zval(this_ptr, SL("mapClasses"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

