
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Enum_RunMode) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Enum, RunMode, phalconplus, enum_runmode, phalconplus_enum_abstractenum_ce, phalconplus_enum_runmode_method_entry, 0);

	zend_declare_property_null(phalconplus_enum_runmode_ce, SL("map"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalconplus_enum_runmode_ce->create_object = zephir_init_properties_PhalconPlus_Enum_RunMode;
	zephir_declare_class_constant_string(phalconplus_enum_runmode_ce, SL("WEB"), "Web");

	zephir_declare_class_constant_string(phalconplus_enum_runmode_ce, SL("CLI"), "Cli");

	zephir_declare_class_constant_string(phalconplus_enum_runmode_ce, SL("SRV"), "Srv");

	zephir_declare_class_constant_string(phalconplus_enum_runmode_ce, SL("MICRO"), "Micro");

	zephir_declare_class_constant_string(phalconplus_enum_runmode_ce, SL("__default"), "Cli");

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Enum_RunMode, getMapClassName) {

	zval _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("map"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("val"), PH_NOISY_CC);
	zephir_array_fetch(&_1, &_0, &_2, PH_NOISY | PH_READONLY, "phalconplus/Enum/RunMode.zep", 25 TSRMLS_CC);
	RETURN_CTOR(&_1);

}

zend_object *zephir_init_properties_PhalconPlus_Enum_RunMode(zend_class_entry *class_type TSRMLS_DC) {

		zval _1$$3;
	zval _0;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("map"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			zephir_create_array(&_1$$3, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(&_1$$3, SL("Web"), SL("Module"));
			add_assoc_stringl_ex(&_1$$3, SL("Cli"), SL("Task"));
			add_assoc_stringl_ex(&_1$$3, SL("Srv"), SL("Srv"));
			add_assoc_stringl_ex(&_1$$3, SL("Micro"), SL("Micro"));
			zephir_update_property_zval(this_ptr, SL("map"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

