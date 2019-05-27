
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
#include "kernel/time.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_PsrApplication) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, PsrApplication, phalconplus, base_psrapplication, zephir_get_internal_ce(SL("phalcon\\mvc\\application")), phalconplus_base_psrapplication_method_entry, 0);

	zend_declare_property_null(phalconplus_base_psrapplication_ce, SL("request"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_psrapplication_ce, SL("post"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_psrapplication_ce, SL("tempFiles"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalconplus_base_psrapplication_ce->create_object = zephir_init_properties_PhalconPlus_Base_PsrApplication;
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

PHP_METHOD(PhalconPlus_Base_PsrApplication, setPost) {

	zval *post, post_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&post_sub);

	zephir_fetch_params(0, 1, 0, &post);



	zephir_update_property_zval(this_ptr, SL("post"), post);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_Base_PsrApplication, getPost) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "post");

}

PHP_METHOD(PhalconPlus_Base_PsrApplication, getTempFiles) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "tempFiles");

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

	zend_class_entry *_35 = NULL;
	zval _10;
	zephir_fcall_cache_entry *_7 = NULL, *_32 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval uri, *uri_param = NULL, request, _0, nativeRequest, _2, _3, cookies, cookie, nativeHeaders, _8, response, _9, content, _11, headers, status, reason, _12, _36, _37, _38, _1$$3, _4$$6, _5$$7, _6$$7, _13$$8, _14$$9, _15$$9, _16$$9, _17$$9, _18$$9, _19$$9, cookieHeader$$9, _20$$9, _21$$9, _22$$9, _25$$9, _28$$9, _23$$10, _24$$10, _26$$11, _27$$11, _29$$12, _30$$12, _31$$12, _33$$12, _34$$12;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&nativeRequest);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&cookies);
	ZVAL_UNDEF(&cookie);
	ZVAL_UNDEF(&nativeHeaders);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&reason);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_38);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&cookieHeader$$9);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_26$$11);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_29$$12);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_31$$12);
	ZVAL_UNDEF(&_33$$12);
	ZVAL_UNDEF(&_34$$12);
	ZVAL_UNDEF(&_10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_STRING(&uri, "");
	} else {
		zephir_get_strval(&uri, uri_param);
	}


	zephir_read_property(&_0, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_0))) {
		zephir_read_property(&_1$$3, this_ptr, SL("request"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&request, &_1$$3);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "request in PsrApplication must instance of \\Psr\\Http\\Message\\ServerRequestInterface", "phalconplus/Base/PsrApplication.zep", 37);
		return;
	}
	ZEPHIR_INIT_VAR(&nativeRequest);
	object_init_ex(&nativeRequest, phalconplus_base_psrrequest_ce);
	ZEPHIR_CALL_METHOD(NULL, &nativeRequest, "__construct", NULL, 45, &request);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "request");
	ZEPHIR_CALL_METHOD(NULL, &_2, "setshared", NULL, 0, &_3, &nativeRequest);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "\\GuzzleHttp\\Psr7\\Response");
	if (!(zephir_class_exists(&_3, 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "PsrApplication depends on GuzzleHttp\\Psr7\\Response", "phalconplus/Base/PsrApplication.zep", 46);
		return;
	}
	ZEPHIR_INIT_VAR(&cookies);
	array_init(&cookies);
	ZEPHIR_CALL_METHOD(&cookies, &nativeRequest, "getcookies", NULL, 46);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&nativeHeaders, &nativeRequest, "getheaders", NULL, 47);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&cookies))) {
		ZEPHIR_CALL_FUNCTION(&_4$$6, "session_name", NULL, 48);
		zephir_check_call_status();
		if (zephir_array_isset(&cookies, &_4$$6)) {
			ZEPHIR_CALL_FUNCTION(&_6$$7, "session_name", NULL, 48);
			zephir_check_call_status();
			zephir_array_fetch(&_5$$7, &cookies, &_6$$7, PH_NOISY | PH_READONLY, "phalconplus/Base/PsrApplication.zep", 56 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(NULL, "session_id", &_7, 49, &_5$$7);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(&_8, &request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&uri, &_8, "getpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(&_9, phalconplus_base_psrapplication_ce, getThis(), "handle", NULL, 0, &uri);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&response, &_9);
	ZEPHIR_INIT_VAR(&_10);
	zephir_create_array(&_10, 2, 0 TSRMLS_CC);
	zephir_array_fast_append(&_10, &response);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "getContent");
	zephir_array_fast_append(&_10, &_11);
	ZEPHIR_INIT_VAR(&content);
	ZEPHIR_CALL_USER_FUNC(&content, &_10);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_9, &response, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&headers, &_9, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &response, "getstatuscode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&reason, &response, "getreasonphrase", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_12, "session_status", NULL, 50);
	zephir_check_call_status();
	if (ZEPHIR_IS_LONG(&_12, 2)) {
		ZEPHIR_CALL_FUNCTION(&_13$$8, "session_name", NULL, 48);
		zephir_check_call_status();
		if (!(zephir_array_isset(&cookies, &_13$$8))) {
			ZEPHIR_INIT_VAR(&cookie);
			object_init_ex(&cookie, zephir_get_internal_ce(SL("phalcon\\http\\cookie")));
			ZEPHIR_CALL_FUNCTION(&_14$$9, "session_name", NULL, 48);
			zephir_check_call_status();
			ZEPHIR_CALL_FUNCTION(&_15$$9, "session_id", &_7, 49);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_16$$9);
			zephir_time(&_16$$9);
			ZEPHIR_CALL_METHOD(&_17$$9, &nativeRequest, "gethttphost", NULL, 51);
			zephir_check_call_status();
			ZVAL_LONG(&_18$$9, (zephir_get_numberval(&_16$$9) + 3600));
			ZEPHIR_INIT_VAR(&_19$$9);
			ZVAL_STRING(&_19$$9, "/");
			ZEPHIR_CALL_METHOD(NULL, &cookie, "__construct", NULL, 0, &_14$$9, &_15$$9, &_18$$9, &_19$$9, &_17$$9);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_20$$9, &cookie, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_21$$9, &cookie, "getvalue", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_19$$9);
			ZVAL_STRING(&_19$$9, "%s=%s");
			ZEPHIR_CALL_FUNCTION(&cookieHeader$$9, "sprintf", NULL, 13, &_19$$9, &_20$$9, &_21$$9);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_22$$9, &cookie, "getpath", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_22$$9)) {
				ZEPHIR_CALL_METHOD(&_23$$10, &cookie, "getpath", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_24$$10);
				ZEPHIR_CONCAT_SV(&_24$$10, "; Path=", &_23$$10);
				zephir_concat_self(&cookieHeader$$9, &_24$$10 TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_25$$9, &cookie, "getdomain", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_25$$9)) {
				ZEPHIR_CALL_METHOD(&_26$$11, &cookie, "getdomain", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_27$$11);
				ZEPHIR_CONCAT_SV(&_27$$11, "; Domain=", &_26$$11);
				zephir_concat_self(&cookieHeader$$9, &_27$$11 TSRMLS_CC);
			}
			ZEPHIR_CALL_METHOD(&_28$$9, &cookie, "getexpiration", NULL, 0);
			zephir_check_call_status();
			if (zephir_is_true(&_28$$9)) {
				ZEPHIR_CALL_METHOD(&_29$$12, &cookie, "getexpiration", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_30$$12);
				ZVAL_STRING(&_30$$12, "Z");
				ZEPHIR_CALL_FUNCTION(&_31$$12, "date", &_32, 34, &_30$$12);
				zephir_check_call_status();
				ZEPHIR_SINIT_VAR(_33$$12);
				zephir_add_function(&_33$$12, &_29$$12, &_31$$12);
				ZEPHIR_INIT_NVAR(&_30$$12);
				ZVAL_STRING(&_30$$12, "D, d-M-Y H:i:s");
				ZEPHIR_CALL_FUNCTION(&_29$$12, "gmdate", NULL, 52, &_30$$12, &_33$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_30$$12);
				ZVAL_STRING(&_30$$12, "T");
				ZEPHIR_CALL_FUNCTION(&_31$$12, "date", &_32, 34, &_30$$12);
				zephir_check_call_status();
				ZEPHIR_INIT_VAR(&_34$$12);
				ZEPHIR_CONCAT_SVSV(&_34$$12, "; Expires=", &_29$$12, " ", &_31$$12);
				zephir_concat_self(&cookieHeader$$9, &_34$$12 TSRMLS_CC);
			}
			zephir_array_update_multi(&headers, &cookieHeader$$9 TSRMLS_CC, SL("sa"), 3, SL("Set-Cookie"));
		}
	}
	if (!_35) {
	_35 = zephir_fetch_class_str_ex(SL("GuzzleHttp\\Psr7\\Response"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(return_value, _35);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_36);
		if (zephir_is_true(&status)) {
			ZEPHIR_CPY_WRT(&_36, &status);
		} else {
			ZEPHIR_INIT_NVAR(&_36);
			ZVAL_LONG(&_36, 200);
		}
		ZEPHIR_CALL_METHOD(&_37, &request, "getprotocolversion", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_38);
		if (zephir_is_true(&reason)) {
			ZEPHIR_CPY_WRT(&_38, &reason);
		} else {
			ZEPHIR_INIT_NVAR(&_38);
			ZVAL_STRING(&_38, "OK");
		}
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_36, &headers, &content, &_37, &_38);
		zephir_check_call_status();
	}
	RETURN_MM();

}

zend_object *zephir_init_properties_PhalconPlus_Base_PsrApplication(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("tempFiles"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("tempFiles"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("post"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("post"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

