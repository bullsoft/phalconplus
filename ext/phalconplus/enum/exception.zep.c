
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

	zend_class_entry *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eCode, eCode_sub, code, details, className, val, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eCode_sub);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&details);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eCode);



	ZEPHIR_INIT_VAR(&code);
	ZVAL_NULL(&code);
	ZEPHIR_INIT_VAR(&details);
	array_init(&details);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_called_class(&className TSRMLS_CC);
	ZEPHIR_INIT_NVAR(&code);
	zephir_fetch_safe_class(&_0, &className);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&code, _1);
	if (zephir_has_constructor(&code TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &code, "__construct", NULL, 0, eCode);
		zephir_check_call_status();
	}
	
        #if PHP_VERSION_ID >= 70000
        zephir_read_static_property_ce(&details, _1, SL("details") TSRMLS_CC, 0);
        #else
        zephir_read_static_property_ce(&details, _1, SL("details") TSRMLS_CC);
        #endif
        
	ZEPHIR_CALL_METHOD(&_2, &code, "__tostring", NULL, 0);
	zephir_check_call_status();
	if (zephir_array_isset_fetch(&val, &details, &_2, 1 TSRMLS_CC)) {
		RETURN_CTOR(&val);
	} else {
		array_init(return_value);
		RETURN_MM();
	}

}

PHP_METHOD(PhalconPlus_Enum_Exception, getByCode) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eCode, eCode_sub, detail;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eCode_sub);
	ZVAL_UNDEF(&detail);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eCode);



	ZEPHIR_INIT_VAR(&detail);
	array_init(&detail);
	ZEPHIR_CALL_STATIC(&detail, "has", NULL, 0, eCode);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&detail))) {
		zephir_array_update_string(&detail, SL("code"), eCode, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&detail);

}

PHP_METHOD(PhalconPlus_Enum_Exception, newException) {

	zend_class_entry *_2, *_6, *_8;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *e, e_sub, *logger = NULL, logger_sub, __$null, code, eCode, eName, map2Name, className, _0, _1, _3, eClassName, exception, _4, _5, _7, _9, _10, _11, _12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&e_sub);
	ZVAL_UNDEF(&logger_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&eCode);
	ZVAL_UNDEF(&eName);
	ZVAL_UNDEF(&map2Name);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&eClassName);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &e, &logger);

	if (!logger) {
		logger = &logger_sub;
		logger = &__$null;
	}


	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_STATIC(&_0, "validvalues", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&map2Name, "array_flip", NULL, 29, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&eCode, e, "getcode", NULL, 0);
	zephir_check_call_status();
	_2 = zephir_fetch_class_str_ex(SL("Phalcon\\Text"), ZEND_FETCH_CLASS_AUTO);
	zephir_array_fetch(&_3, &map2Name, &eCode, PH_NOISY | PH_READONLY, "phalconplus/Enum/Exception.zep", 44 TSRMLS_CC);
	ZEPHIR_CALL_CE_STATIC(&eName, _2, "camelize", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_STATIC(&_4, "exceptionclassprefix", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&eClassName);
	ZEPHIR_CONCAT_VV(&eClassName, &_4, &eName);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_called_class(&className TSRMLS_CC);
	ZEPHIR_INIT_VAR(&code);
	zephir_fetch_safe_class(&_5, &className);
	_6 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_5), Z_STRLEN_P(&_5), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&code, _6);
	if (zephir_has_constructor(&code TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &code, "__construct", NULL, 0, &eCode);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&exception);
	zephir_fetch_safe_class(&_7, &eClassName);
	_8 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_7), Z_STRLEN_P(&_7), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&exception, _8);
	if (zephir_has_constructor(&exception TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(&_9, &code, "getmessage", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &exception, "__construct", NULL, 0, &_9, logger);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_10, &code, "getcode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &exception, "setcode", NULL, 0, &_10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_11, &code, "getlevel", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &exception, "setlevel", NULL, 0, &_11);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_12, e, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &exception, "setmessage", NULL, 0, &_12);
	zephir_check_call_status();
	RETURN_CCTOR(&exception);

}

PHP_METHOD(PhalconPlus_Enum_Exception, exceptionClassPrefix) {

	zval *this_ptr = getThis();


	ZEPHIR_CONCAT_SS(return_value, "PhalconPlus\\Enum", "\\Exception\\");
	return;

}

PHP_METHOD(PhalconPlus_Enum_Exception, getMessage) {

	zval detail, val, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&detail);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_STATIC(&detail, "getbycode", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_array_isset_string_fetch(&val, &detail, SL("message"), 1)) {
		RETURN_CTOR(&val);
	} else {
		RETURN_MM_STRING("");
	}

}

PHP_METHOD(PhalconPlus_Enum_Exception, getLevel) {

	zval detail, val, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&detail);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_STATIC(&detail, "getbycode", NULL, 0, &_0);
	zephir_check_call_status();
	if (zephir_array_isset_string_fetch(&val, &detail, SL("level"), 1)) {
		RETURN_CTOR(&val);
	} else {
		RETURN_MM_LONG(7);
	}

}

PHP_METHOD(PhalconPlus_Enum_Exception, getCode) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

