
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
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Http_NonPsrRequest) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Http, NonPsrRequest, phalconplus, http_nonpsrrequest, zephir_get_internal_ce(SL("phalcon\\http\\request")), phalconplus_http_nonpsrrequest_method_entry, 0);

	zend_declare_property_null(phalconplus_http_nonpsrrequest_ce, SL("attributes"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_http_nonpsrrequest_ce, SL("cookies"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_http_nonpsrrequest_ce, SL("headers"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_http_nonpsrrequest_ce, SL("files"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_http_nonpsrrequest_ce, SL("psrRequest"), ZEND_ACC_PROTECTED);

	phalconplus_http_nonpsrrequest_ce->create_object = zephir_init_properties_PhalconPlus_Http_NonPsrRequest;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getAttributes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "attributes");

}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getCookies) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cookies");

}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getFiles) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "files");

}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getPsrRequest) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "psrRequest");

}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, __construct) {

	zend_string *_16, *_20, *_27, *_32, *_45, *_57;
	zend_ulong _15, _19, _26, _31, _44, _56;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, _SERVER, _POST, _GET, _COOKIE, _FILES, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, posts, gets, cookies, _10, _11, _12, k, v, *_13, _14, *_17, _18, _21, _22, _23, *_24, _25, _28, *_29, _30, _41, *_42, _43, _46, _52, prefix, input, _53, *_54, _55, _33$$21, _34$$21, _35$$21, _36$$21, _37$$22, _38$$22, _39$$22, _40$$22, _47$$25, _48$$25, _49$$26, _50$$26, _51$$26;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_COOKIE);
	ZVAL_UNDEF(&_FILES);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&posts);
	ZVAL_UNDEF(&gets);
	ZVAL_UNDEF(&cookies);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_52);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&_53);
	ZVAL_UNDEF(&_55);
	ZVAL_UNDEF(&_33$$21);
	ZVAL_UNDEF(&_34$$21);
	ZVAL_UNDEF(&_35$$21);
	ZVAL_UNDEF(&_36$$21);
	ZVAL_UNDEF(&_37$$22);
	ZVAL_UNDEF(&_38$$22);
	ZVAL_UNDEF(&_39$$22);
	ZVAL_UNDEF(&_40$$22);
	ZVAL_UNDEF(&_47$$25);
	ZVAL_UNDEF(&_48$$25);
	ZVAL_UNDEF(&_49$$26);
	ZVAL_UNDEF(&_50$$26);
	ZVAL_UNDEF(&_51$$26);

	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_get_global(&_GET, SL("_GET"));
	zephir_get_global(&_POST, SL("_POST"));
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_fetch_params(1, 1, 0, &request);



	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CALL_METHOD(&_1, request, "getattributes", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		ZEPHIR_INIT_NVAR(&_0);
		array_init(&_0);
	} else {
		ZEPHIR_CALL_METHOD(&_0, request, "getattributes", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("attributes"), &_0);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CALL_METHOD(&_3, request, "getcookieparams", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_3))) {
		ZEPHIR_INIT_NVAR(&_2);
		array_init(&_2);
	} else {
		ZEPHIR_CALL_METHOD(&_2, request, "getcookieparams", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("cookies"), &_2);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CALL_METHOD(&_5, request, "getheaders", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_5))) {
		ZEPHIR_INIT_NVAR(&_4);
		array_init(&_4);
	} else {
		ZEPHIR_CALL_METHOD(&_4, request, "getheaders", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("headers"), &_4);
	ZEPHIR_CALL_METHOD(&_6, request, "getbody", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, &_6, "__tostring", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_rawBody"), &_7);
	ZEPHIR_CALL_SELF(&_8, "getrequesttarget", NULL, 0, request);
	zephir_check_call_status();
	zephir_array_update_string(&_SERVER, SL("REQUEST_URI"), &_8, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_9, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_SERVER, SL("REQUEST_METHOD"), &_9, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_10, request, "getparsedbody", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_10))) {
		ZEPHIR_INIT_VAR(&posts);
		array_init(&posts);
	} else {
		ZEPHIR_CALL_METHOD(&posts, request, "getparsedbody", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_11, request, "getqueryparams", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_11))) {
		ZEPHIR_INIT_VAR(&gets);
		array_init(&gets);
	} else {
		ZEPHIR_CALL_METHOD(&gets, request, "getqueryparams", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_12, request, "getcookieparams", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_12))) {
		ZEPHIR_INIT_VAR(&cookies);
		array_init(&cookies);
	} else {
		ZEPHIR_CALL_METHOD(&cookies, request, "getcookieparams", NULL, 0);
		zephir_check_call_status();
	}
	zephir_is_iterable(&posts, 0, "phalconplus/Http/NonPsrRequest.zep", 52);
	if (Z_TYPE_P(&posts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&posts), _15, _16, _13)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_16 != NULL) { 
				ZVAL_STR_COPY(&k, _16);
			} else {
				ZVAL_LONG(&k, _15);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _13);
			zephir_array_update_zval(&_POST, &k, &v, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &posts, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_14, &posts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&k, &posts, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&v, &posts, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&_POST, &k, &v, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &posts, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_is_iterable(&gets, 0, "phalconplus/Http/NonPsrRequest.zep", 55);
	if (Z_TYPE_P(&gets) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&gets), _19, _20, _17)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_20 != NULL) { 
				ZVAL_STR_COPY(&k, _20);
			} else {
				ZVAL_LONG(&k, _19);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _17);
			zephir_array_update_zval(&_GET, &k, &v, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &gets, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_18, &gets, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_18)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&k, &gets, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&v, &gets, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&_GET, &k, &v, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &gets, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	ZEPHIR_CALL_METHOD(&_21, request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_22, &_21, "getpath", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_GET, SL("_url"), &_22, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_23, request, "getserverparams", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&_23, 0, "phalconplus/Http/NonPsrRequest.zep", 60);
	if (Z_TYPE_P(&_23) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_23), _26, _27, _24)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_27 != NULL) { 
				ZVAL_STR_COPY(&k, _27);
			} else {
				ZVAL_LONG(&k, _26);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _24);
			zephir_array_update_zval(&_SERVER, &k, &v, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_23, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_25, &_23, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_25)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&k, &_23, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&v, &_23, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&_SERVER, &k, &v, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_23, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_read_property(&_28, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_28, 0, "phalconplus/Http/NonPsrRequest.zep", 64);
	if (Z_TYPE_P(&_28) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_28), _31, _32, _29)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_32 != NULL) { 
				ZVAL_STR_COPY(&k, _32);
			} else {
				ZVAL_LONG(&k, _31);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _29);
			ZEPHIR_INIT_NVAR(&_33$$21);
			ZEPHIR_INIT_NVAR(&_34$$21);
			ZVAL_STRING(&_34$$21, "-");
			ZEPHIR_INIT_NVAR(&_35$$21);
			ZVAL_STRING(&_35$$21, "_");
			zephir_fast_str_replace(&_33$$21, &_34$$21, &_35$$21, &k);
			ZEPHIR_INIT_NVAR(&k);
			zephir_fast_strtoupper(&k, &_33$$21);
			ZEPHIR_INIT_NVAR(&_36$$21);
			ZEPHIR_CONCAT_SV(&_36$$21, "HTTP_", &k);
			zephir_array_update_zval(&_SERVER, &_36$$21, &v, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_28, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_30, &_28, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_30)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&k, &_28, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&v, &_28, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_37$$22);
				ZEPHIR_INIT_NVAR(&_38$$22);
				ZVAL_STRING(&_38$$22, "-");
				ZEPHIR_INIT_NVAR(&_39$$22);
				ZVAL_STRING(&_39$$22, "_");
				zephir_fast_str_replace(&_37$$22, &_38$$22, &_39$$22, &k);
				ZEPHIR_INIT_NVAR(&k);
				zephir_fast_strtoupper(&k, &_37$$22);
				ZEPHIR_INIT_NVAR(&_40$$22);
				ZEPHIR_CONCAT_SV(&_40$$22, "HTTP_", &k);
				zephir_array_update_zval(&_SERVER, &_40$$22, &v, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_28, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	ZEPHIR_CALL_SELF(&_41, "getrequesttarget", NULL, 0, request);
	zephir_check_call_status();
	zephir_array_update_string(&_SERVER, SL("REQUEST_URI"), &_41, PH_COPY | PH_SEPARATE);
	zephir_is_iterable(&cookies, 0, "phalconplus/Http/NonPsrRequest.zep", 70);
	if (Z_TYPE_P(&cookies) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&cookies), _44, _45, _42)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_45 != NULL) { 
				ZVAL_STR_COPY(&k, _45);
			} else {
				ZVAL_LONG(&k, _44);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _42);
			zephir_array_update_zval(&_COOKIE, &k, &v, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &cookies, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_43, &cookies, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_43)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&k, &cookies, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&v, &cookies, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&_COOKIE, &k, &v, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &cookies, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_read_property(&_46, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_46))) {
		zephir_read_property(&_47$$25, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_48$$25, "session_name", NULL, 109);
		zephir_check_call_status();
		if (zephir_array_isset(&_47$$25, &_48$$25)) {
			zephir_read_property(&_49$$26, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_51$$26, "session_name", NULL, 109);
			zephir_check_call_status();
			zephir_array_fetch(&_50$$26, &_49$$26, &_51$$26, PH_NOISY | PH_READONLY, "phalconplus/Http/NonPsrRequest.zep", 72);
			ZEPHIR_CALL_FUNCTION(NULL, "session_id", NULL, 64, &_50$$26);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(&_52, request, "getuploadedfiles", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mapfiles", NULL, 110, &_52);
	zephir_check_call_status();
	zephir_read_property(&_53, this_ptr, SL("files"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_53, 0, "phalconplus/Http/NonPsrRequest.zep", 81);
	if (Z_TYPE_P(&_53) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_53), _56, _57, _54)
		{
			ZEPHIR_INIT_NVAR(&prefix);
			if (_57 != NULL) { 
				ZVAL_STR_COPY(&prefix, _57);
			} else {
				ZVAL_LONG(&prefix, _56);
			}
			ZEPHIR_INIT_NVAR(&input);
			ZVAL_COPY(&input, _54);
			zephir_array_update_zval(&_FILES, &prefix, &input, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_53, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_55, &_53, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_55)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&prefix, &_53, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&input, &_53, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&_FILES, &prefix, &input, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_53, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&input);
	ZEPHIR_INIT_NVAR(&prefix);
	zephir_update_property_zval(this_ptr, SL("psrRequest"), request);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getRequestTarget) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, target, _0, _1, _2, _3$$4, _4$$4, _5$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	ZEPHIR_CALL_METHOD(&_0, request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&target, &_0, "getpath", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&target, "")) {
		ZEPHIR_INIT_NVAR(&target);
		ZVAL_STRING(&target, "/");
	}
	ZEPHIR_CALL_METHOD(&_1, request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_1, "getquery", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(&_2, "")) {
		ZEPHIR_CALL_METHOD(&_3$$4, request, "geturi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$4, &_3$$4, "getquery", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SV(&_5$$4, "?", &_4$$4);
		zephir_concat_self(&target, &_5$$4);
	}
	RETURN_CCTOR(&target);

}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, mapFiles) {

	zval _9$$6, _16$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *uploads_param = NULL, file, *_0, _1, tmpname$$5, _3$$5, _5$$5, _7$$5, _11$$5, _8$$6, tmpname$$9, _12$$9, _13$$9, _14$$9, _18$$9, _15$$10;
	zval uploads, _10$$5, _17$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&uploads);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&tmpname$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&tmpname$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_16$$10);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uploads_param);

	zephir_get_arrval(&uploads, uploads_param);


	zephir_is_iterable(&uploads, 0, "phalconplus/Http/NonPsrRequest.zep", 119);
	if (Z_TYPE_P(&uploads) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&uploads), _0)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _0);
			if (Z_TYPE_P(&file) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "mapfiles", &_2, 110, &file);
				zephir_check_call_status();
			} else if (zephir_is_instance_of(&file, SL("Psr\\Http\\Message\\UploadedFileInterface"))) {
				ZEPHIR_CALL_FUNCTION(&_3$$5, "sys_get_temp_dir", &_4, 111);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZVAL_STRING(&_5$$5, "upload");
				ZEPHIR_CALL_FUNCTION(&tmpname$$5, "tempnam", &_6, 112, &_3$$5, &_5$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_7$$5, &file, "geterror", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&_7$$5, 0)) {
					ZEPHIR_CALL_METHOD(&_8$$6, &file, "getstream", NULL, 0);
					zephir_check_call_status();
					zephir_get_strval(&_9$$6, &_8$$6);
					zephir_file_put_contents(NULL, &tmpname$$5, &_9$$6);
				}
				ZEPHIR_INIT_NVAR(&_10$$5);
				zephir_create_array(&_10$$5, 5, 0);
				ZEPHIR_CALL_METHOD(&_11$$5, &file, "geterror", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_10$$5, SL("error"), &_11$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_11$$5, &file, "getclientfilename", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_10$$5, SL("name"), &_11$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_11$$5, &file, "getsize", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_10$$5, SL("size"), &_11$$5, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_10$$5, SL("tmp_name"), &tmpname$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(&_11$$5, &file, "getclientmediatype", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_string(&_10$$5, SL("type"), &_11$$5, PH_COPY | PH_SEPARATE);
				zephir_update_property_array_append(this_ptr, SL("files"), &_10$$5);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &uploads, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &uploads, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &uploads, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&file) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "mapfiles", &_2, 110, &file);
					zephir_check_call_status();
				} else if (zephir_is_instance_of(&file, SL("Psr\\Http\\Message\\UploadedFileInterface"))) {
					ZEPHIR_CALL_FUNCTION(&_12$$9, "sys_get_temp_dir", &_4, 111);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_13$$9);
					ZVAL_STRING(&_13$$9, "upload");
					ZEPHIR_CALL_FUNCTION(&tmpname$$9, "tempnam", &_6, 112, &_12$$9, &_13$$9);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_14$$9, &file, "geterror", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_14$$9, 0)) {
						ZEPHIR_CALL_METHOD(&_15$$10, &file, "getstream", NULL, 0);
						zephir_check_call_status();
						zephir_get_strval(&_16$$10, &_15$$10);
						zephir_file_put_contents(NULL, &tmpname$$9, &_16$$10);
					}
					ZEPHIR_INIT_NVAR(&_17$$9);
					zephir_create_array(&_17$$9, 5, 0);
					ZEPHIR_CALL_METHOD(&_18$$9, &file, "geterror", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_string(&_17$$9, SL("error"), &_18$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_18$$9, &file, "getclientfilename", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_string(&_17$$9, SL("name"), &_18$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_18$$9, &file, "getsize", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_string(&_17$$9, SL("size"), &_18$$9, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&_17$$9, SL("tmp_name"), &tmpname$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_CALL_METHOD(&_18$$9, &file, "getclientmediatype", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_string(&_17$$9, SL("type"), &_18$$9, PH_COPY | PH_SEPARATE);
					zephir_update_property_array_append(this_ptr, SL("files"), &_17$$9);
				}
			ZEPHIR_CALL_METHOD(NULL, &uploads, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, removeTmpFiles) {

	zval item, tmp, _0, *_1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&tmp);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("files"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalconplus/Http/NonPsrRequest.zep", 131);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _1);
			ZEPHIR_OBS_NVAR(&tmp);
			if (zephir_array_isset_string_fetch(&tmp, &item, SL("tmp_name"), 0)) {
				if ((zephir_file_exists(&tmp) == SUCCESS)) {
					ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_3, 113, &tmp);
					zephir_check_call_status();
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&tmp);
				if (zephir_array_isset_string_fetch(&tmp, &item, SL("tmp_name"), 0)) {
					if ((zephir_file_exists(&tmp) == SUCCESS)) {
						ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_3, 113, &tmp);
						zephir_check_call_status();
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getScheme) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("psrRequest"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "getscheme", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Checks whether request has been made using ajax
 */
PHP_METHOD(PhalconPlus_Http_NonPsrRequest, isAjax) {

	zend_bool _1;
	zval _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);


	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_string(&_0, SL("HTTP_X_REQUESTED_WITH"));
	if (_1) {
		zephir_read_property(&_2, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_3, &_2, SL("HTTP_X_REQUESTED_WITH"), PH_NOISY | PH_READONLY, "phalconplus/Http/NonPsrRequest.zep", 143);
		_1 = ZEPHIR_IS_STRING_IDENTICAL(&_3, "XMLHttpRequest");
	}
	RETURN_BOOL(_1);

}

/**
 * Checks whether request has been made using SOAP
 */
PHP_METHOD(PhalconPlus_Http_NonPsrRequest, isSoap) {

	zval contentType, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contentType);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string(&_0, SL("HTTP_SOAPACTION"))) {
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_CALL_METHOD(&contentType, this_ptr, "getcontenttype", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&contentType))) {
			RETURN_MM_BOOL(zephir_memnstr_str(&contentType, SL("application/soap+xml"), "phalconplus/Http/NonPsrRequest.zep", 157));
		}
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getHttpHost) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("psrRequest"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "gethost", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getPort) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("psrRequest"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "getport", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getHeaders) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "headers");

}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getContentType) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("psrRequest"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Content-Type");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getheaderline", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_PhalconPlus_Http_NonPsrRequest(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _4, _6, _1$$3, _3$$4, _5$$5, _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$6);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("files"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("files"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("headers"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("cookies"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("attributes"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

