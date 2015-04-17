
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Enum_AbstractEnum) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Enum, AbstractEnum, phalconplus, enum_abstractenum, phalconplus_enum_abstractenum_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalconplus_enum_abstractenum_ce, SL("val"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalconplus_enum_abstractenum_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("jsonserializable") TSRMLS_CC));
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Enum_AbstractEnum, __construct) {

	zephir_fcall_cache_entry *_12 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL, *_5 = NULL, *_10 = NULL, *_11 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *val = NULL, *reflection, *defaultVal = NULL, *_0, *_2 = NULL, *_3 = NULL, *_6 = NULL, *_7, _8, *_9 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &val);

	if (!val) {
		ZEPHIR_INIT_VAR(val);
		ZVAL_STRING(val, "__PhalconPlus_AbstractEnum_DefaultValue__", 1);
	}


	ZEPHIR_INIT_VAR(reflection);
	object_init_ex(reflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_0);
	zephir_get_called_class(_0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", &_1, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "__default", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_2, reflection, "hasconstant", &_4, _3);
	zephir_check_temp_parameter(_3);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_STRING(_3, "__default", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&defaultVal, reflection, "getconstant", &_5, _3);
		zephir_check_temp_parameter(_3);
		zephir_check_call_status();
		ZEPHIR_CALL_STATIC(&_6, "isvalid", NULL, defaultVal);
		zephir_check_call_status();
		if (!(zephir_is_true(_6))) {
			ZEPHIR_INIT_NVAR(_3);
			object_init_ex(_3, spl_ce_OutOfRangeException);
			ZEPHIR_INIT_VAR(_7);
			zephir_get_class(_7, this_ptr, 0 TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_8);
			ZVAL_STRING(&_8, "Invalid __default enumeration %s for Enum %s", 0);
			ZEPHIR_CALL_FUNCTION(&_9, "sprintf", &_10, &_8, defaultVal, _7);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_11, _9);
			zephir_check_call_status();
			zephir_throw_exception_debug(_3, "phalconplus/Enum/AbstractEnum.zep", 15 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (ZEPHIR_IS_STRING(val, "__PhalconPlus_AbstractEnum_DefaultValue__")) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvalue", &_12, defaultVal);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvalue", &_12, val);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Enum_AbstractEnum, setValue) {

	zephir_nts_static zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *val, *_0 = NULL, *_1, *_2, _3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &val);



	ZEPHIR_CALL_STATIC(&_0, "isvalid", NULL, val);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(_2);
		zephir_get_class(_2, this_ptr, 0 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "Invalid enumeration %s for Enum %s", 0);
		ZEPHIR_CALL_FUNCTION(&_4, "sprintf", &_5, &_3, val, _2);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", &_6, _4);
		zephir_check_call_status();
		zephir_throw_exception_debug(_1, "phalconplus/Enum/AbstractEnum.zep", 29 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_this(this_ptr, SL("val"), val TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Enum_AbstractEnum, getValue) {


	RETURN_MEMBER(this_ptr, "val");

}

PHP_METHOD(PhalconPlus_Enum_AbstractEnum, isValid) {

	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *val, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &val);



	ZEPHIR_CALL_STATIC(&_0, "validvalues", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "in_array", &_2, val, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Enum_AbstractEnum, validValues) {

	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL, *_2 = NULL, *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *reflection, *consts = NULL, *_0;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(reflection);
	object_init_ex(reflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_0);
	zephir_get_called_class(_0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", &_1, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&consts, reflection, "getconstants", &_2);
	zephir_check_call_status();
	zephir_array_unset_string(&consts, SS("__default"), PH_SEPARATE);
	ZEPHIR_RETURN_CALL_FUNCTION("array_values", &_3, consts);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_AbstractEnum, jsonSerialize) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getvalue", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_AbstractEnum, __toString) {

	zval *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getvalue", NULL);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	RETURN_CTOR(_1);

}

PHP_METHOD(PhalconPlus_Enum_AbstractEnum, toArray) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getvalue", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

