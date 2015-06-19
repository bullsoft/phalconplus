
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
		ZEPHIR_CALL_METHOD(NULL, code, "__construct", NULL, 0, eCode);
		zephir_check_call_status();
	}
	
            zephir_read_static_property(&details, Z_STRVAL_P(className), Z_STRLEN_P(className), SL("details") TSRMLS_CC);
        
	ZEPHIR_CALL_METHOD(&_2, code, "__tostring", NULL, 0);
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


	ZEPHIR_CALL_STATIC(&detail, "has", NULL, 0, eCode);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(detail))) {
		zephir_array_update_string(&detail, SL("code"), &eCode, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(detail);

}

PHP_METHOD(PhalconPlus_Enum_Exception, newException) {

	zend_class_entry *_2, *_6, *_8;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *e, *logger = NULL, *code, *eCode = NULL, *eName = NULL, *map2Name = NULL, *className, *_0 = NULL, *_1, *_3, *eClassName, *exception, *_4 = NULL, *_5 = NULL, *_7 = NULL, *_9 = NULL, *_10 = NULL, *_11 = NULL, *_12 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &e, &logger);

	if (!logger) {
		logger = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_STATIC(&_0, "validvalues", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&map2Name, "array_flip", NULL, 9, _0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&eCode, e, "getcode", NULL, 0);
	zephir_check_call_status();
	_2 = zend_fetch_class(SL("Phalcon\\Text"), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	zephir_array_fetch(&_3, map2Name, eCode, PH_NOISY | PH_READONLY, "phalconplus/Enum/Exception.zep", 42 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&eName, _2, "camelize", NULL, 0, _3);
	zephir_check_call_status();
	ZEPHIR_CALL_STATIC(&_4, "exceptionclassprefix", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(eClassName);
	ZEPHIR_CONCAT_VV(eClassName, _4, eName);
	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	ZEPHIR_INIT_VAR(code);
	zephir_fetch_safe_class(_5, className);
	_6 = zend_fetch_class(Z_STRVAL_P(_5), Z_STRLEN_P(_5), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(code, _6);
	if (zephir_has_constructor(code TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, code, "__construct", NULL, 0, eCode);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(exception);
	zephir_fetch_safe_class(_7, eClassName);
	_8 = zend_fetch_class(Z_STRVAL_P(_7), Z_STRLEN_P(_7), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(exception, _8);
	if (zephir_has_constructor(exception TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_9, code, "getmessage", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, exception, "__construct", NULL, 0, _9, logger);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_10, code, "getcode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, exception, "setcode", NULL, 0, _10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_11, code, "getlevel", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, exception, "setlevel", NULL, 0, _11);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_12, e, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, exception, "setmessage", NULL, 0, _12);
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

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_STATIC(&detail, "getbycode", NULL, 0, _0);
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

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_STATIC(&detail, "getbycode", NULL, 0, _0);
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

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

