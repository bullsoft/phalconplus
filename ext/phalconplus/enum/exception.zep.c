
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
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Enum_Exception)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Enum, Exception, phalconplus, enum_exception, phalconplus_enum_abstractenum_ce, phalconplus_enum_exception_method_entry, 0);

	zend_declare_property_null(phalconplus_enum_exception_ce, SL("details"), ZEND_ACC_PROTECTED|ZEND_ACC_STATIC);
	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Enum_Exception, has)
{
	zend_class_entry *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(eCode)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &eCode);


	ZEPHIR_INIT_VAR(&code);
	ZVAL_NULL(&code);
	ZEPHIR_INIT_VAR(&details);
	array_init(&details);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_called_class(&className);
	ZEPHIR_INIT_NVAR(&code);
	zephir_fetch_safe_class(&_0, &className);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	if(!_1) {
		RETURN_MM_NULL();
	}
	object_init_ex(&code, _1);
	if (zephir_has_constructor(&code)) {
		ZEPHIR_CALL_METHOD(NULL, &code, "__construct", NULL, 0, eCode);
		zephir_check_call_status();
	}

	
        #if PHP_VERSION_ID >= 70000
        zend_class_entry *ce;
        ce = zephir_fetch_class_str_ex(Z_STRVAL_P(&className), Z_STRLEN_P(&className), ZEND_FETCH_CLASS_AUTO);
        zephir_read_static_property_ce(&details, ce, SL("details"), 0);
        #else
        zephir_read_static_property_ce(&details, phalconplus_enum_exception_ce, SL("details"));
        #endif
        
	ZEPHIR_CALL_METHOD(&_2, &code, "__tostring", NULL, 0);
	zephir_check_call_status();
	if (zephir_array_isset_fetch(&val, &details, &_2, 1)) {
		RETURN_CTOR(&val);
	} else {
		array_init(return_value);
		RETURN_MM();
	}
}

PHP_METHOD(PhalconPlus_Enum_Exception, getByCode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *eCode, eCode_sub, detail;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&eCode_sub);
	ZVAL_UNDEF(&detail);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(eCode)
	ZEND_PARSE_PARAMETERS_END();
#endif


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

PHP_METHOD(PhalconPlus_Enum_Exception, newException)
{
	zend_class_entry *_5, *_7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *e, e_sub, *logger = NULL, logger_sub, __$null, code, eCode, eName, map2Name, className, _0, _1, _2, eClassName, exception, _3, _4, _6, _8, _9, _10, _11;
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&eClassName);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(e)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(logger, zephir_get_internal_ce(SL("phalcon\\logger\\loggerinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &e, &logger);
	if (!logger) {
		logger = &logger_sub;
		logger = &__$null;
	}


	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_STATIC(&_0, "validvalues", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&map2Name, "array_flip", NULL, 72, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&eCode, e, "getcode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&eName);
	zephir_array_fetch(&_2, &map2Name, &eCode, PH_NOISY | PH_READONLY, "phalconplus/Enum/Exception.zep", 49);
	zephir_camelize(&eName, &_2, NULL  );
	ZEPHIR_CALL_STATIC(&_3, "exceptionclassprefix", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&eClassName);
	ZEPHIR_CONCAT_VV(&eClassName, &_3, &eName);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_called_class(&className);
	ZEPHIR_INIT_VAR(&code);
	zephir_fetch_safe_class(&_4, &className);
	_5 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_4), Z_STRLEN_P(&_4), ZEND_FETCH_CLASS_AUTO);
	if(!_5) {
		RETURN_MM_NULL();
	}
	object_init_ex(&code, _5);
	if (zephir_has_constructor(&code)) {
		ZEPHIR_CALL_METHOD(NULL, &code, "__construct", NULL, 0, &eCode);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&exception);
	zephir_fetch_safe_class(&_6, &eClassName);
	_7 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_6), Z_STRLEN_P(&_6), ZEND_FETCH_CLASS_AUTO);
	if(!_7) {
		RETURN_MM_NULL();
	}
	object_init_ex(&exception, _7);
	if (zephir_has_constructor(&exception)) {
		ZEPHIR_CALL_METHOD(&_8, &code, "getmessage", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(NULL, &exception, "__construct", NULL, 0, &_8, logger);
		zephir_check_call_status();
	}

	ZEPHIR_CALL_METHOD(&_9, &code, "getcode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &exception, "setcode", NULL, 0, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, &code, "getlevel", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &exception, "setlevel", NULL, 0, &_10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_11, e, "getmessage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &exception, "setmessage", NULL, 0, &_11);
	zephir_check_call_status();
	RETURN_CCTOR(&exception);
}

PHP_METHOD(PhalconPlus_Enum_Exception, exceptionClassPrefix)
{
	zval *this_ptr = getThis();



	ZEPHIR_CONCAT_SS(return_value, "PhalconPlus\\Enum", "\\Exception\\");
	return;
}

PHP_METHOD(PhalconPlus_Enum_Exception, getMessage)
{
	zval detail, val, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

PHP_METHOD(PhalconPlus_Enum_Exception, getLevel)
{
	zval detail, val, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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

PHP_METHOD(PhalconPlus_Enum_Exception, getCode)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getvalue", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

