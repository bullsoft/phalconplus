
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Enum_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Enum, Exception, phalconplus, enum_exception, phalconplus_enum_abstractenum_ce, phalconplus_enum_exception_method_entry, 0);

	zend_declare_property_null(phalconplus_enum_exception_ce, SL("details"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Enum_Exception, has) {

	int ZEPHIR_LAST_CALL_STATUS;
	zend_class_entry *_1;
	zval *eCode, *code = NULL, *details, *className, *val, *_0 = NULL, *_2 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eCode);

	ZEPHIR_INIT_VAR(code);
	ZVAL_NULL(code);
	ZEPHIR_INIT_VAR(details);
	array_init(details);


	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	ZEPHIR_INIT_NVAR(code);
	zephir_fetch_safe_class(_0, className);
	_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(code, _1);
	if (zephir_has_constructor(code TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, code, "__construct", NULL, eCode);
		zephir_check_call_status();
	}
	
            zephir_read_static_property(&details, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("details") TSRMLS_CC);
        
	ZEPHIR_CALL_METHOD(&_2, code, "__tostring", NULL);
	zephir_check_call_status();
	if (zephir_array_isset_fetch(&val, details, _2, 1 TSRMLS_CC)) {
		RETURN_CTOR(val);
	} else {
		array_init(return_value);
		RETURN_MM();
	}

}

PHP_METHOD(PhalconPlus_Enum_Exception, getByCode) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *eCode, *detail = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eCode);

	ZEPHIR_INIT_VAR(detail);
	array_init(detail);


	ZEPHIR_CALL_STATIC(&detail, "has", NULL, eCode);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(detail))) {
		zephir_array_update_string(&detail, SL("code"), &eCode, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(detail);

}

PHP_METHOD(PhalconPlus_Enum_Exception, newException) {

	zend_class_entry *_3, *_7, *_9;
	zephir_nts_static zephir_fcall_cache_entry *_2 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *eCode, *logger = NULL, *code, *eName = NULL, *map2Name = NULL, *className, *_0 = NULL, *_1, *_4, *eClassName, *exception, *_5 = NULL, *_6 = NULL, *_8 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &eCode, &logger);

	if (!logger) {
		logger = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_STATIC(&_0, "validvalues", NULL, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&map2Name, "array_flip", &_2, _0);
	zephir_check_call_status();
	_3 = zend_fetch_class(SL("Phalcon\\Text"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	zephir_array_fetch(&_4, map2Name, eCode, PH_NOISY | PH_READONLY, "phalconplus/Enum/Exception.zep", 41 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&eName, _3, "camelize", NULL, _4);
	zephir_check_call_status();
	ZEPHIR_CALL_STATIC(&_5, "exceptionclassprefix", NULL);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(eClassName);
	ZEPHIR_CONCAT_VV(eClassName, _5, eName);
	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	ZEPHIR_INIT_VAR(code);
	zephir_fetch_safe_class(_6, className);
	_7 = zend_fetch_class(Z_STRVAL_P(_6), Z_STRLEN_P(_6), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(code, _7);
	if (zephir_has_constructor(code TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, code, "__construct", NULL, eCode);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(exception);
	zephir_fetch_safe_class(_8, eClassName);
	_9 = zend_fetch_class(Z_STRVAL_P(_8), Z_STRLEN_P(_8), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(exception, _9);
	if (zephir_has_constructor(exception TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_10, code, "getmessage", NULL);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, exception, "__construct", NULL, _10, logger);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_11, code, "getcode", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, exception, "setcode", NULL, _11);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_12, code, "getlevel", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, exception, "setlevel", NULL, _12);
	zephir_check_call_status();
	RETURN_CCTOR(exception);

}

PHP_METHOD(PhalconPlus_Enum_Exception, exceptionClassPrefix) {


	ZEPHIR_CONCAT_SS(return_value, "PhalconPlus\\Enum", "\\Exception\\");
	return;

}

PHP_METHOD(PhalconPlus_Enum_Exception, getMessage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *detail = NULL, *val, *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getvalue", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_STATIC(&detail, "getbycode", NULL, _0);
	zephir_check_call_status();
	if (zephir_array_isset_string_fetch(&val, detail, SS("message"), 1 TSRMLS_CC)) {
		RETURN_CTOR(val);
	} else {
		RETURN_MM_STRING("", 1);
	}

}

PHP_METHOD(PhalconPlus_Enum_Exception, getLevel) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *detail = NULL, *val, *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getvalue", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_STATIC(&detail, "getbycode", NULL, _0);
	zephir_check_call_status();
	if (zephir_array_isset_string_fetch(&val, detail, SS("level"), 1 TSRMLS_CC)) {
		RETURN_CTOR(val);
	} else {
		RETURN_MM_LONG(7);
	}

}

PHP_METHOD(PhalconPlus_Enum_Exception, getCode) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getvalue", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

