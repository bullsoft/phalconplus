
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

	zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *val = NULL, *reflection, *defaultVal = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4, _5, *_6 = NULL;

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
	ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", NULL, 18, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "__default", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, reflection, "hasconstant", NULL, 40, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		ZEPHIR_INIT_NVAR(_2);
		ZVAL_STRING(_2, "__default", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&defaultVal, reflection, "getconstant", NULL, 41, _2);
		zephir_check_temp_parameter(_2);
		zephir_check_call_status();
		ZEPHIR_CALL_STATIC(&_3, "isvalid", NULL, 0, defaultVal);
		zephir_check_call_status();
		if (!(zephir_is_true(_3))) {
			ZEPHIR_INIT_NVAR(_2);
			object_init_ex(_2, spl_ce_OutOfRangeException);
			ZEPHIR_INIT_VAR(_4);
			zephir_get_class(_4, this_ptr, 0 TSRMLS_CC);
			ZEPHIR_SINIT_VAR(_5);
			ZVAL_STRING(&_5, "Invalid __default enumeration %s for Enum %s", 0);
			ZEPHIR_CALL_FUNCTION(&_6, "sprintf", NULL, 42, &_5, defaultVal, _4);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, _2, "__construct", NULL, 43, _6);
			zephir_check_call_status();
			zephir_throw_exception_debug(_2, "phalconplus/Enum/AbstractEnum.zep", 15 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	if (ZEPHIR_IS_STRING(val, "__PhalconPlus_AbstractEnum_DefaultValue__")) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvalue", &_7, 0, defaultVal);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setvalue", &_7, 0, val);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Enum_AbstractEnum, setValue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *val, *_0 = NULL, *_1, *_2, _3, *_4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &val);



	ZEPHIR_CALL_STATIC(&_0, "isvalid", NULL, 0, val);
	zephir_check_call_status();
	if (!(zephir_is_true(_0))) {
		ZEPHIR_INIT_VAR(_1);
		object_init_ex(_1, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(_2);
		zephir_get_class(_2, this_ptr, 0 TSRMLS_CC);
		ZEPHIR_SINIT_VAR(_3);
		ZVAL_STRING(&_3, "Invalid enumeration %s for Enum %s", 0);
		ZEPHIR_CALL_FUNCTION(&_4, "sprintf", NULL, 42, &_3, val, _2);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, _1, "__construct", NULL, 44, _4);
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

	int ZEPHIR_LAST_CALL_STATUS;
	zval *val, *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &val);



	ZEPHIR_CALL_STATIC(&_0, "validvalues", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "in_array", NULL, 45, val, _0, ZEPHIR_GLOBAL(global_true));
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Enum_AbstractEnum, validValues) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *assoc_param = NULL, *reflection, *consts = NULL, *_0;
	zend_bool assoc;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &assoc_param);

	if (!assoc_param) {
		assoc = 0;
	} else {
		assoc = zephir_get_boolval(assoc_param);
	}


	ZEPHIR_INIT_VAR(reflection);
	object_init_ex(reflection, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_0);
	zephir_get_called_class(_0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, reflection, "__construct", NULL, 18, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&consts, reflection, "getconstants", NULL, 46);
	zephir_check_call_status();
	zephir_array_unset_string(&consts, SS("__default"), PH_SEPARATE);
	if (assoc == 1) {
		RETURN_CCTOR(consts);
	} else {
		ZEPHIR_RETURN_CALL_FUNCTION("array_values", NULL, 47, consts);
		zephir_check_call_status();
		RETURN_MM();
	}

}

PHP_METHOD(PhalconPlus_Enum_AbstractEnum, jsonSerialize) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Enum_AbstractEnum, __toString) {

	zval *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	zephir_get_strval(_1, _0);
	RETURN_CTOR(_1);

}

