
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
	zend_declare_class_constant_string(phalconplus_enum_runmode_ce, SL("WEB"), "Web" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_runmode_ce, SL("CLI"), "Cli" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_runmode_ce, SL("SRV"), "Srv" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_runmode_ce, SL("MICRO"), "Micro" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_runmode_ce, SL("__default"), "Cli" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Enum_RunMode, getMapClassName) {

	zval *_0, *_1, *_2;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("map"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_2);
	zephir_read_property_this(&_2, this_ptr, SL("val"), PH_NOISY_CC);
	zephir_array_fetch(&_1, _0, _2, PH_NOISY | PH_READONLY, "phalconplus/Enum/RunMode.zep", 25 TSRMLS_CC);
	RETURN_CTOR(_1);

}

zend_object_value zephir_init_properties_PhalconPlus_Enum_RunMode(zend_class_entry *class_type TSRMLS_DC) {

		zval *_1$$3;
	zval *_0;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("map"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			zephir_create_array(_1$$3, 4, 0 TSRMLS_CC);
			add_assoc_stringl_ex(_1$$3, SS("Web"), SL("Module"), 1);
			add_assoc_stringl_ex(_1$$3, SS("Cli"), SL("Task"), 1);
			add_assoc_stringl_ex(_1$$3, SS("Srv"), SL("Srv"), 1);
			add_assoc_stringl_ex(_1$$3, SS("Micro"), SL("Micro"), 1);
			zephir_update_property_this(getThis(), SL("map"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

