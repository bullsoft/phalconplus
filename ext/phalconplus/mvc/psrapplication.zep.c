
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
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Mvc_PsrApplication) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Mvc, PsrApplication, phalconplus, mvc_psrapplication, zephir_get_internal_ce(SL("phalcon\\mvc\\application")), phalconplus_mvc_psrapplication_method_entry, 0);

	zend_declare_property_null(phalconplus_mvc_psrapplication_ce, SL("psrRequest"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_mvc_psrapplication_ce, SL("nativeRequest"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Mvc_PsrApplication, setPsrRequest) {

	zval *psrRequest, psrRequest_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&psrRequest_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &psrRequest);



	zephir_update_property_zval(this_ptr, SL("psrRequest"), psrRequest);
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
	zval *dependencyInjector = NULL, dependencyInjector_sub, *psrRequest = NULL, psrRequest_sub, __$true, __$false, __$null, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dependencyInjector_sub);
	ZVAL_UNDEF(&psrRequest_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &dependencyInjector, &psrRequest);

	if (!dependencyInjector) {
		dependencyInjector = &dependencyInjector_sub;
		dependencyInjector = &__$null;
	}
	if (!psrRequest) {
		psrRequest = &psrRequest_sub;
		psrRequest = &__$null;
	}


	ZEPHIR_CALL_PARENT(NULL, phalconplus_mvc_psrapplication_ce, getThis(), "__construct", NULL, 0, dependencyInjector);
	zephir_check_call_status();
	if (0) {
		zephir_update_property_zval(this_ptr, SL("_sendHeaders"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_sendHeaders"), &__$false);
	}
	if (0) {
		zephir_update_property_zval(this_ptr, SL("_sendCookies"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("_sendCookies"), &__$false);
	}
	zephir_update_property_zval(this_ptr, SL("psrRequest"), psrRequest);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, phalconplus_http_psrrequest_ce);
	ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 96, psrRequest);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("nativeRequest"), &_0);
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

	zephir_read_property(&_0, this_ptr, SL("nativeRequest"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("nativeRequest"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "removetmpfiles", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Mvc_PsrApplication, handle) {

	zend_class_entry *_11 = NULL;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uri_param = NULL, psrRequest, _0, _1, _3, _4, _5, _6, reqUri, _7, response, _9, stdout, headers, status, reason, content, psrResponse, _12, _13, _2$$4, _10$$7, _14$$8, _15$$8, _16$$8;
	zval uri;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uri);
	ZVAL_UNDEF(&psrRequest);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&reqUri);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&stdout);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&reason);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&psrResponse);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &uri_param);

	if (!uri_param) {
		ZEPHIR_INIT_VAR(&uri);
		ZVAL_STRING(&uri, "");
	} else {
		zephir_get_strval(&uri, uri_param);
	}


	zephir_read_property(&_0, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "there is no di(dependency injector) in PsrAppliction", "phalconplus/Mvc/PsrApplication.zep", 42);
		return;
	}
	zephir_read_property(&_1, this_ptr, SL("psrRequest"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_1))) {
		zephir_read_property(&_2$$4, this_ptr, SL("psrRequest"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&psrRequest, &_2$$4);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "request in PsrApplication must instance of \\Psr\\Http\\Message\\ServerRequestInterface", "phalconplus/Mvc/PsrApplication.zep", 48);
		return;
	}
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "\\GuzzleHttp\\Psr7\\Response");
	if (!(zephir_class_exists(&_3, 1 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "PsrApplication depends on GuzzleHttp\\Psr7\\Response", "phalconplus/Mvc/PsrApplication.zep", 52);
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("_dependencyInjector"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_5, this_ptr, SL("nativeRequest"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "request");
	ZEPHIR_CALL_METHOD(NULL, &_4, "setshared", NULL, 0, &_6, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, &psrRequest, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&reqUri, &_7, "getpath", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", &_8, 52);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(&_9, phalconplus_mvc_psrapplication_ce, getThis(), "handle", NULL, 0, &reqUri);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(&response, &_9);
	ZEPHIR_CALL_FUNCTION(&stdout, "ob_get_clean", NULL, 69);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&headers, this_ptr, "mapheaders", NULL, 0, &response);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&status, &response, "getstatuscode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&reason, &response, "getreasonphrase", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", &_8, 52);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &response, "send", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&content, "ob_get_clean", NULL, 69);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&stdout))) {
		ZEPHIR_INIT_VAR(&_10$$7);
		ZEPHIR_CONCAT_VV(&_10$$7, &stdout, &content);
		ZEPHIR_CPY_WRT(&content, &_10$$7);
	}
	ZEPHIR_INIT_VAR(&psrResponse);
	if (!_11) {
	_11 = zephir_fetch_class_str_ex(SL("GuzzleHttp\\Psr7\\Response"), ZEND_FETCH_CLASS_AUTO);
	}
	object_init_ex(&psrResponse, _11);
	if (zephir_has_constructor(&psrResponse TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_12);
		if (zephir_is_true(&status)) {
			ZEPHIR_CPY_WRT(&_12, &status);
		} else {
			ZEPHIR_INIT_NVAR(&_12);
			ZVAL_LONG(&_12, 200);
		}
		ZEPHIR_CALL_METHOD(&_9, &psrRequest, "getprotocolversion", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_13);
		if (zephir_is_true(&reason)) {
			ZEPHIR_CPY_WRT(&_13, &reason);
		} else {
			ZEPHIR_INIT_NVAR(&_13);
			ZVAL_STRING(&_13, "OK");
		}
		ZEPHIR_CALL_METHOD(NULL, &psrResponse, "__construct", NULL, 0, &_12, &headers, &content, &_9, &_13);
		zephir_check_call_status();
	}
	if (!(zephir_array_isset_string(&headers, SL("Content-Length")))) {
		ZEPHIR_INIT_VAR(&_15$$8);
		ZVAL_STRING(&_15$$8, "Content-Length");
		ZVAL_LONG(&_16$$8, zephir_fast_strlen_ev(&content));
		ZEPHIR_CALL_METHOD(&_14$$8, &psrResponse, "withaddedheader", NULL, 0, &_15$$8, &_16$$8);
		zephir_check_call_status();
		ZEPHIR_CPY_WRT(&psrResponse, &_14$$8);
	}
	RETURN_CCTOR(&psrResponse);

}

PHP_METHOD(PhalconPlus_Mvc_PsrApplication, mapHeaders) {

	zval _8$$6, _15$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *response, response_sub, headers, _0, rawHeaders, h, pos, nativeHeaders, *_1, _2, _17, _3$$3, name$$4, _4$$4, value$$4, _5$$4, _6$$4, _7$$5, _9$$6, _10$$8, name$$9, _11$$9, value$$9, _12$$9, _13$$9, _14$$10, _16$$11, _18$$13, _19$$13, _20$$13, _21$$13, _22$$14;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&rawHeaders);
	ZVAL_UNDEF(&h);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&nativeHeaders);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&name$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&value$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&name$$9);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&value$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_15$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response);



	ZEPHIR_CALL_METHOD(&_0, response, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&headers, &_0, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&rawHeaders, "headers_list", NULL, 97);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&nativeHeaders);
	array_init(&nativeHeaders);
	zephir_is_iterable(&rawHeaders, 0, "phalconplus/Mvc/PsrApplication.zep", 111);
	if (Z_TYPE_P(&rawHeaders) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rawHeaders), _1)
		{
			ZEPHIR_INIT_NVAR(&h);
			ZVAL_COPY(&h, _1);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, ":");
			ZEPHIR_INIT_NVAR(&pos);
			zephir_fast_strpos(&pos, &h, &_3$$3, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
				ZVAL_LONG(&_4$$4, 0);
				ZEPHIR_INIT_NVAR(&name$$4);
				zephir_substr(&name$$4, &h, 0 , zephir_get_intval(&pos), 0);
				ZVAL_LONG(&_5$$4, (zephir_get_numberval(&pos) + 1));
				ZEPHIR_INIT_NVAR(&_6$$4);
				zephir_substr(&_6$$4, &h, zephir_get_intval(&_5$$4), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_INIT_NVAR(&value$$4);
				zephir_fast_trim(&value$$4, &_6$$4, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
				if (zephir_array_isset(&nativeHeaders, &name$$4)) {
					zephir_array_fetch(&_7$$5, &nativeHeaders, &name$$4, PH_NOISY | PH_READONLY, "phalconplus/Mvc/PsrApplication.zep", 100 TSRMLS_CC);
					if (!(Z_TYPE_P(&_7$$5) == IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_8$$6);
						zephir_create_array(&_8$$6, 1, 0 TSRMLS_CC);
						ZEPHIR_OBS_NVAR(&_9$$6);
						zephir_array_fetch(&_9$$6, &nativeHeaders, &name$$4, PH_NOISY, "phalconplus/Mvc/PsrApplication.zep", 101 TSRMLS_CC);
						zephir_array_fast_append(&_8$$6, &_9$$6);
						zephir_array_update_zval(&nativeHeaders, &name$$4, &_8$$6, PH_COPY | PH_SEPARATE);
					}
					zephir_array_update_multi(&nativeHeaders, &value$$4 TSRMLS_CC, SL("za"), 2, &name$$4);
				} else {
					zephir_array_update_zval(&nativeHeaders, &name$$4, &value$$4, PH_COPY | PH_SEPARATE);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &rawHeaders, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &rawHeaders, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&h, &rawHeaders, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$8);
				ZVAL_STRING(&_10$$8, ":");
				ZEPHIR_INIT_NVAR(&pos);
				zephir_fast_strpos(&pos, &h, &_10$$8, 0 );
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
					ZVAL_LONG(&_11$$9, 0);
					ZEPHIR_INIT_NVAR(&name$$9);
					zephir_substr(&name$$9, &h, 0 , zephir_get_intval(&pos), 0);
					ZVAL_LONG(&_12$$9, (zephir_get_numberval(&pos) + 1));
					ZEPHIR_INIT_NVAR(&_13$$9);
					zephir_substr(&_13$$9, &h, zephir_get_intval(&_12$$9), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					ZEPHIR_INIT_NVAR(&value$$9);
					zephir_fast_trim(&value$$9, &_13$$9, NULL , ZEPHIR_TRIM_BOTH TSRMLS_CC);
					if (zephir_array_isset(&nativeHeaders, &name$$9)) {
						zephir_array_fetch(&_14$$10, &nativeHeaders, &name$$9, PH_NOISY | PH_READONLY, "phalconplus/Mvc/PsrApplication.zep", 100 TSRMLS_CC);
						if (!(Z_TYPE_P(&_14$$10) == IS_ARRAY)) {
							ZEPHIR_INIT_NVAR(&_15$$11);
							zephir_create_array(&_15$$11, 1, 0 TSRMLS_CC);
							ZEPHIR_OBS_NVAR(&_16$$11);
							zephir_array_fetch(&_16$$11, &nativeHeaders, &name$$9, PH_NOISY, "phalconplus/Mvc/PsrApplication.zep", 101 TSRMLS_CC);
							zephir_array_fast_append(&_15$$11, &_16$$11);
							zephir_array_update_zval(&nativeHeaders, &name$$9, &_15$$11, PH_COPY | PH_SEPARATE);
						}
						zephir_array_update_multi(&nativeHeaders, &value$$9 TSRMLS_CC, SL("za"), 2, &name$$9);
					} else {
						zephir_array_update_zval(&nativeHeaders, &name$$9, &value$$9, PH_COPY | PH_SEPARATE);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &rawHeaders, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&h);
	ZEPHIR_CALL_FUNCTION(NULL, "header_remove", NULL, 98);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_17);
	zephir_fast_array_merge(&_17, &nativeHeaders, &headers TSRMLS_CC);
	ZEPHIR_CPY_WRT(&headers, &_17);
	if (zephir_array_isset_string(&nativeHeaders, SL("Set-Cookie"))) {
		ZEPHIR_INIT_VAR(&_18$$13);
		zephir_array_fetch_string(&_19$$13, &nativeHeaders, SL("Set-Cookie"), PH_NOISY | PH_READONLY, "phalconplus/Mvc/PsrApplication.zep", 115 TSRMLS_CC);
		if (Z_TYPE_P(&_19$$13) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&_18$$13);
			zephir_array_fetch_string(&_18$$13, &nativeHeaders, SL("Set-Cookie"), PH_NOISY, "phalconplus/Mvc/PsrApplication.zep", 115 TSRMLS_CC);
		} else {
			ZEPHIR_INIT_VAR(&_20$$13);
			zephir_create_array(&_20$$13, 1, 0 TSRMLS_CC);
			ZEPHIR_OBS_VAR(&_21$$13);
			zephir_array_fetch_string(&_21$$13, &nativeHeaders, SL("Set-Cookie"), PH_NOISY, "phalconplus/Mvc/PsrApplication.zep", 115 TSRMLS_CC);
			zephir_array_fast_append(&_20$$13, &_21$$13);
			ZEPHIR_CPY_WRT(&_18$$13, &_20$$13);
		}
		zephir_array_update_string(&headers, SL("Set-Cookie"), &_18$$13, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_INIT_VAR(&_22$$14);
		array_init(&_22$$14);
		zephir_array_update_string(&headers, SL("Set-Cookie"), &_22$$14, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&headers);

}

