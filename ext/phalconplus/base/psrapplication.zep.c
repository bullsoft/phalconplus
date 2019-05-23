
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_PsrApplication) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, PsrApplication, phalconplus, base_psrapplication, zephir_get_internal_ce(SL("phalcon\\mvc\\application")), phalconplus_base_psrapplication_method_entry, 0);

	zend_declare_property_null(phalconplus_base_psrapplication_ce, SL("request"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_PsrApplication, setRequest) {

	zval *request, request_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);

	zephir_fetch_params(0, 1, 0, &request);



	zephir_update_property_zval(this_ptr, SL("request"), request);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_Base_PsrApplication, getRequest) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "request");

}

PHP_METHOD(PhalconPlus_Base_PsrApplication, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dependencyInjector = NULL, dependencyInjector_sub, *request = NULL, request_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_UNDEF(&request_sub);
	ZVAL_NULL(&__$null);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &dependencyInjector, &request);

	if (!dependencyInjector) {
		dependencyInjector = &dependencyInjector_sub;
		dependencyInjector = &__$null;
	}
	if (!request) {
		request = &request_sub;
		request = &__$null;
	}


	ZEPHIR_CALL_PARENT(NULL, phalconplus_base_psrapplication_ce, getThis(), "__construct", NULL, 0, dependencyInjector);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("request"), request);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_PsrApplication, handle) {

	zend_class_entry *_8 = NULL;
	zval _6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request = NULL, request_sub, __$null, _0$$3, _1$$4, _2, response, _3, _4, _5, content, _7, headers, status, reason, _9, _10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&reason);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &request);

	if (!request) {
		request = &request_sub;
		ZEPHIR_CPY_WRT(request, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(request);
	}


	if (UNEXPECTED(!((zephir_is_instance_of(request, SL("Psr\\Http\\Message\\ServerRequestInterface") TSRMLS_CC))))) {
		zephir_read_property(&_0$$3, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
		if (!(ZEPHIR_IS_EMPTY(&_0$$3))) {
			zephir_read_property(&_1$$4, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(request, &_1$$4);
		} else {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "request in PsrApplication must instance of \\Psr\\Http\\Message\\ServerRequestInterface", "phalconplus/Base/PsrApplication.zep", 26);
			return;
		}
	}
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "\\GuzzleHttp\\Psr7\\Response");
	if (!(zephir_class_exists(&_2, 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "PsrApplication depends on GuzzleHttp\\Psr7\\Response", "phalconplus/Base/PsrApplication.zep", 31);
		return;
	}
	ZEPHIR_CALL_METHOD(&_4, request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, &_4, "getpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(&_3, phalconplus_base_psrapplication_ce, getThis(), "handle", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&response, &_3);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_6, &response);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "getContent");
	zephir_array_fast_append(&_6, &_7);
	ZEPHIR_INIT_VAR(&content);
	ZEPHIR_CALL_USER_FUNC(&content, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, &response, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&headers, &_3, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &response, "getstatuscode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&reason, &response, "getreasonphrase", NULL, 0);
	zephir_check_call_status();
	if (!_8) {
	_8 = zephir_fetch_class_str_ex(SL("GuzzleHttp\\Psr7\\Response"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _8);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_9);
		if (zephir_is_true(&status)) {
			ZEPHIR_CPY_WRT(&_9, &status);
		} else {
			ZEPHIR_INIT_NVAR(&_9);
			ZVAL_LONG(&_9, 200);
		}
		ZEPHIR_INIT_VAR(&_10);
		if (zephir_is_true(&reason)) {
			ZEPHIR_CPY_WRT(&_10, &reason);
		} else {
			ZEPHIR_INIT_NVAR(&_10);
			ZVAL_STRING(&_10, "OK");
		}
		ZEPHIR_INIT_NVAR(&_7);
		ZVAL_STRING(&_7, "1.1");
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_9, &headers, &content, &_7, &_10);
		zephir_check_call_status();
	}
	RETURN_MM();

}

