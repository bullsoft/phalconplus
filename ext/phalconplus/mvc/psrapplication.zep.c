
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


ZEPHIR_INIT_CLASS(PhalconPlus_Mvc_PsrApplication) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Mvc, PsrApplication, phalconplus, mvc_psrapplication, zephir_get_internal_ce(SL("phalcon\\mvc\\application")), phalconplus_mvc_psrapplication_method_entry, 0);

	zend_declare_property_null(phalconplus_mvc_psrapplication_ce, SL("psrRequest"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_mvc_psrapplication_ce, SL("nativeRequest"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Mvc_PsrApplication, setPsrRequest) {

	zval *psrRequest, psrRequest_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&psrRequest_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &psrRequest);



	zephir_update_property_zval(this_ptr, ZEND_STRL("psrRequest"), psrRequest);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_Mvc_PsrApplication, getPsrRequest) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "psrRequest");

}

PHP_METHOD(PhalconPlus_Mvc_PsrApplication, getNativeRequest) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "nativeRequest");

}

PHP_METHOD(PhalconPlus_Mvc_PsrApplication, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *psrRequest, psrRequest_sub, *dependencyInjector = NULL, dependencyInjector_sub, __$true, __$false, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&psrRequest_sub);
	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &psrRequest, &dependencyInjector);

	if (!dependencyInjector) {
		dependencyInjector = &dependencyInjector_sub;
		dependencyInjector = &__$null;
	}


	ZEPHIR_CALL_PARENT(NULL, phalconplus_mvc_psrapplication_ce, getThis(), "__construct", NULL, 0, dependencyInjector);
	zephir_check_call_status();
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_sendHeaders"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_sendHeaders"), &__$false);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_sendCookies"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("_sendCookies"), &__$false);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("psrRequest"), psrRequest);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalconplus_http_nonpsrrequest_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 143, psrRequest);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("nativeRequest"), &_0);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Mvc_PsrApplication, __destruct) {

	zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("nativeRequest"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("nativeRequest"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "removetmpfiles", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Mvc_PsrApplication, handle) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, _0, _1, _2, _3, response, psrRequest, _4, reqUri, _5, protocol, _6;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&psrRequest);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&reqUri);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&protocol);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_STRING(&uri, "");
	} else {
		zephir_get_strval(&uri, uri_param);
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "there is no di(dependency injector) in PsrAppliction", "phalconplus/Mvc/PsrApplication.zep", 37);
		return;
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_2, this_ptr, ZEND_STRL("nativeRequest"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "request");
	ZEPHIR_CALL_METHOD(NULL, &_1, "setshared", NULL, 0, &_3, &_2);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, ZEND_STRL("psrRequest"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&psrRequest, &_4);
	ZEPHIR_CALL_METHOD(&_5, &psrRequest, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&reqUri, &_5, "getpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&protocol, &psrRequest, "getprotocolversion", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(&_6, phalconplus_mvc_psrapplication_ce, getThis(), "handle", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&response, &_6);
	RETURN_CCTOR(&response);

}

