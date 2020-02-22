
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Facades_AbstractFacade) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Facades, AbstractFacade, phalconplus, facades_abstractfacade, phalconplus_facades_abstractfacade_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Facades_AbstractFacade, getName) {

}

PHP_METHOD(PhalconPlus_Facades_AbstractFacade, __callStatic) {

	zend_class_entry *_0, *_2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params, _4;
	zval *method_param = NULL, *params_param = NULL, di, name, facade, service, _1, _3;
	zval method;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&di);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&facade);
	ZVAL_UNDEF(&service);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &method_param, &params_param);

	zephir_get_strval(&method, method_param);
	zephir_get_arrval(&params, params_param);


	_0 = zephir_fetch_class_str_ex(SL("Phalcon\\Di"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_CALL_CE_STATIC(&di, _0, "getdefault", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&name);
	zephir_get_called_class(&name);
	ZEPHIR_INIT_VAR(&facade);
	zephir_fetch_safe_class(&_1, &name);
	_2 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_1), Z_STRLEN_P(&_1), ZEND_FETCH_CLASS_AUTO);
	if(!_2) {
		RETURN_MM_NULL();
	}
	object_init_ex(&facade, _2);
	if (zephir_has_constructor(&facade)) {
		ZEPHIR_CALL_METHOD(NULL, &facade, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_3, &facade, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&service, &di, "get", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0);
	zephir_array_fast_append(&_4, &service);
	zephir_array_fast_append(&_4, &method);
	ZEPHIR_CALL_USER_FUNC_ARRAY(return_value, &_4, &params);
	zephir_check_call_status();
	RETURN_MM();

}

