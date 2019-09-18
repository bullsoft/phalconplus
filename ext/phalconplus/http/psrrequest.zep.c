
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


ZEPHIR_INIT_CLASS(PhalconPlus_Http_PsrRequest) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Http, PsrRequest, phalconplus, http_psrrequest, zephir_get_internal_ce(SL("phalcon\\http\\request")), phalconplus_http_psrrequest_method_entry, 0);

	zend_declare_property_null(phalconplus_http_psrrequest_ce, SL("attributes"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_http_psrrequest_ce, SL("cookies"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_http_psrrequest_ce, SL("headers"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_http_psrrequest_ce, SL("files"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_http_psrrequest_ce, SL("psrRequest"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalconplus_http_psrrequest_ce->create_object = zephir_init_properties_PhalconPlus_Http_PsrRequest;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Http_PsrRequest, getAttributes) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "attributes");

}

PHP_METHOD(PhalconPlus_Http_PsrRequest, getCookies) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cookies");

}

PHP_METHOD(PhalconPlus_Http_PsrRequest, getFiles) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "files");

}

PHP_METHOD(PhalconPlus_Http_PsrRequest, getPsrRequest) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "psrRequest");

}

PHP_METHOD(PhalconPlus_Http_PsrRequest, __construct) {

	zend_string *_16, *_20, *_27, *_32, *_45;
	zend_ulong _15, _19, _26, _31, _44;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, _SERVER, _POST, _GET, _COOKIE, _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, posts, gets, cookies, _10, _11, _12, k, v, *_13, _14, *_17, _18, _21, _22, _23, *_24, _25, _28, *_29, _30, _41, *_42, _43, _46, _52, _33$$21, _34$$21, _35$$21, _36$$21, _37$$22, _38$$22, _39$$22, _40$$22, _47$$25, _48$$25, _49$$26, _50$$26, _51$$26;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_SERVER);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_COOKIE);
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
	zephir_is_iterable(&posts, 0, "phalconplus/Http/PsrRequest.zep", 52);
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
	zephir_is_iterable(&gets, 0, "phalconplus/Http/PsrRequest.zep", 55);
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
	zephir_is_iterable(&_23, 0, "phalconplus/Http/PsrRequest.zep", 60);
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
	zephir_is_iterable(&_28, 0, "phalconplus/Http/PsrRequest.zep", 64);
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
			zephir_fast_str_replace(&_33$$21, &_34$$21, &_35$$21, &k TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&k);
			zephir_fast_strtoupper(&k, &_33$$21);
			ZEPHIR_INIT_LNVAR(_36$$21);
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
				zephir_fast_str_replace(&_37$$22, &_38$$22, &_39$$22, &k TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&k);
				zephir_fast_strtoupper(&k, &_37$$22);
				ZEPHIR_INIT_LNVAR(_40$$22);
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
	zephir_is_iterable(&cookies, 0, "phalconplus/Http/PsrRequest.zep", 70);
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
		ZEPHIR_CALL_FUNCTION(&_48$$25, "session_name", NULL, 80);
		zephir_check_call_status();
		if (zephir_array_isset(&_47$$25, &_48$$25)) {
			zephir_read_property(&_49$$26, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_51$$26, "session_name", NULL, 80);
			zephir_check_call_status();
			zephir_array_fetch(&_50$$26, &_49$$26, &_51$$26, PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 72 TSRMLS_CC);
			ZEPHIR_CALL_FUNCTION(NULL, "session_id", NULL, 60, &_50$$26);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(&_52, request, "getuploadedfiles", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mapfiles", NULL, 81, &_52);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("psrRequest"), request);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Http_PsrRequest, getRequestTarget) {

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
		zephir_concat_self(&target, &_5$$4 TSRMLS_CC);
	}
	RETURN_CCTOR(&target);

}

PHP_METHOD(PhalconPlus_Http_PsrRequest, mapFiles) {

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


	zephir_is_iterable(&uploads, 0, "phalconplus/Http/PsrRequest.zep", 114);
	if (Z_TYPE_P(&uploads) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&uploads), _0)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _0);
			if (Z_TYPE_P(&file) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "mapfiles", &_2, 81, &file);
				zephir_check_call_status();
			} else if (zephir_is_instance_of(&file, SL("Psr\\Http\\Message\\UploadedFileInterface") TSRMLS_CC)) {
				ZEPHIR_CALL_FUNCTION(&_3$$5, "sys_get_temp_dir", &_4, 82);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZVAL_STRING(&_5$$5, "upload");
				ZEPHIR_CALL_FUNCTION(&tmpname$$5, "tempnam", &_6, 83, &_3$$5, &_5$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_7$$5, &file, "geterror", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&_7$$5, 0)) {
					ZEPHIR_CALL_METHOD(&_8$$6, &file, "getstream", NULL, 0);
					zephir_check_call_status();
					zephir_get_strval(&_9$$6, &_8$$6);
					zephir_file_put_contents(NULL, &tmpname$$5, &_9$$6 TSRMLS_CC);
				}
				ZEPHIR_INIT_NVAR(&_10$$5);
				zephir_create_array(&_10$$5, 5, 0 TSRMLS_CC);
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
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "mapfiles", &_2, 81, &file);
					zephir_check_call_status();
				} else if (zephir_is_instance_of(&file, SL("Psr\\Http\\Message\\UploadedFileInterface") TSRMLS_CC)) {
					ZEPHIR_CALL_FUNCTION(&_12$$9, "sys_get_temp_dir", &_4, 82);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_13$$9);
					ZVAL_STRING(&_13$$9, "upload");
					ZEPHIR_CALL_FUNCTION(&tmpname$$9, "tempnam", &_6, 83, &_12$$9, &_13$$9);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_14$$9, &file, "geterror", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_14$$9, 0)) {
						ZEPHIR_CALL_METHOD(&_15$$10, &file, "getstream", NULL, 0);
						zephir_check_call_status();
						zephir_get_strval(&_16$$10, &_15$$10);
						zephir_file_put_contents(NULL, &tmpname$$9, &_16$$10 TSRMLS_CC);
					}
					ZEPHIR_INIT_NVAR(&_17$$9);
					zephir_create_array(&_17$$9, 5, 0 TSRMLS_CC);
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

PHP_METHOD(PhalconPlus_Http_PsrRequest, removeTmpFiles) {

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
	zephir_is_iterable(&_0, 0, "phalconplus/Http/PsrRequest.zep", 126);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _1);
			ZEPHIR_OBS_NVAR(&tmp);
			if (zephir_array_isset_string_fetch(&tmp, &item, SL("tmp_name"), 0)) {
				if ((zephir_file_exists(&tmp TSRMLS_CC) == SUCCESS)) {
					ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_3, 84, &tmp);
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
					if ((zephir_file_exists(&tmp TSRMLS_CC) == SUCCESS)) {
						ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_3, 84, &tmp);
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

PHP_METHOD(PhalconPlus_Http_PsrRequest, getScheme) {

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
PHP_METHOD(PhalconPlus_Http_PsrRequest, isAjax) {

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
		zephir_array_fetch_string(&_3, &_2, SL("HTTP_X_REQUESTED_WITH"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 138 TSRMLS_CC);
		_1 = ZEPHIR_IS_STRING_IDENTICAL(&_3, "XMLHttpRequest");
	}
	RETURN_BOOL(_1);

}

/**
 * Checks whether request has been made using SOAP
 */
PHP_METHOD(PhalconPlus_Http_PsrRequest, isSoap) {

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
			RETURN_MM_BOOL(zephir_memnstr_str(&contentType, SL("application/soap+xml"), "phalconplus/Http/PsrRequest.zep", 152));
		}
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Http_PsrRequest, getHttpHost) {

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

PHP_METHOD(PhalconPlus_Http_PsrRequest, getPort) {

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

PHP_METHOD(PhalconPlus_Http_PsrRequest, hasFiles) {

	zend_bool _3$$6, _6$$11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, numberFiles;
	zval *onlySuccessful = NULL, onlySuccessful_sub, __$false, files, file, error, _0, *_1, _2, _4$$8, _7$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&onlySuccessful_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&error);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_7$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &onlySuccessful);

	if (!onlySuccessful) {
		onlySuccessful = &onlySuccessful_sub;
		onlySuccessful = &__$false;
	}


	numberFiles = 0;
	zephir_read_property(&_0, this_ptr, SL("files"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&files, &_0);
	if (Z_TYPE_P(&files) != IS_ARRAY) {
		RETURN_MM_LONG(0);
	}
	zephir_is_iterable(&files, 0, "phalconplus/Http/PsrRequest.zep", 195);
	if (Z_TYPE_P(&files) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&files), _1)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _1);
			ZEPHIR_OBS_NVAR(&error);
			if (zephir_array_isset_string_fetch(&error, &file, SL("error"), 0)) {
				if (Z_TYPE_P(&error) != IS_ARRAY) {
					_3$$6 = !zephir_is_true(&error);
					if (!(_3$$6)) {
						_3$$6 = !zephir_is_true(onlySuccessful);
					}
					if (_3$$6) {
						numberFiles++;
					}
				}
				if (Z_TYPE_P(&error) == IS_ARRAY) {
					ZEPHIR_CALL_METHOD(&_4$$8, this_ptr, "hasfilehelper", &_5, 0, &error, onlySuccessful);
					zephir_check_call_status();
					numberFiles += zephir_get_numberval(&_4$$8);
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &files, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &files, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&file, &files, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&error);
				if (zephir_array_isset_string_fetch(&error, &file, SL("error"), 0)) {
					if (Z_TYPE_P(&error) != IS_ARRAY) {
						_6$$11 = !zephir_is_true(&error);
						if (!(_6$$11)) {
							_6$$11 = !zephir_is_true(onlySuccessful);
						}
						if (_6$$11) {
							numberFiles++;
						}
					}
					if (Z_TYPE_P(&error) == IS_ARRAY) {
						ZEPHIR_CALL_METHOD(&_7$$13, this_ptr, "hasfilehelper", &_5, 0, &error, onlySuccessful);
						zephir_check_call_status();
						numberFiles += zephir_get_numberval(&_7$$13);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &files, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&file);
	RETURN_MM_LONG(numberFiles);

}

PHP_METHOD(PhalconPlus_Http_PsrRequest, getUploadedFiles) {

	zend_bool _13$$6, _19$$8, _25$$10, _36$$14, _42$$16, _48$$18;
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_18 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *onlySuccessful = NULL, onlySuccessful_sub, __$false, superFiles, prefix, input, smoothInput, file, dataFile, files, *_0$$3, _1$$3, _4$$4, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, *_11$$5, _12$$5, _14$$6, _15$$7, _16$$7, _17$$7, _20$$8, _21$$9, _22$$9, _23$$9, _24$$9, _26$$10, _27$$11, _28$$12, _29$$13, _30$$13, _31$$13, _32$$13, _33$$13, *_34$$13, _35$$13, _37$$14, _38$$15, _39$$15, _40$$15, _41$$15, _43$$16, _44$$17, _45$$17, _46$$17, _47$$17, _49$$18, _50$$19;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&onlySuccessful_sub);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&superFiles);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&smoothInput);
	ZVAL_UNDEF(&file);
	ZVAL_UNDEF(&dataFile);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_26$$10);
	ZVAL_UNDEF(&_27$$11);
	ZVAL_UNDEF(&_28$$12);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_37$$14);
	ZVAL_UNDEF(&_38$$15);
	ZVAL_UNDEF(&_39$$15);
	ZVAL_UNDEF(&_40$$15);
	ZVAL_UNDEF(&_41$$15);
	ZVAL_UNDEF(&_43$$16);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_45$$17);
	ZVAL_UNDEF(&_46$$17);
	ZVAL_UNDEF(&_47$$17);
	ZVAL_UNDEF(&_49$$18);
	ZVAL_UNDEF(&_50$$19);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &onlySuccessful);

	if (!onlySuccessful) {
		onlySuccessful = &onlySuccessful_sub;
		onlySuccessful = &__$false;
	}


	ZEPHIR_INIT_VAR(&files);
	array_init(&files);
	ZEPHIR_OBS_VAR(&superFiles);
	zephir_read_property(&superFiles, this_ptr, SL("files"), PH_NOISY_CC);
	if (zephir_fast_count_int(&superFiles TSRMLS_CC) > 0) {
		zephir_is_iterable(&superFiles, 0, "phalconplus/Http/PsrRequest.zep", 237);
		if (Z_TYPE_P(&superFiles) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&superFiles), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&prefix);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&prefix, _3$$3);
				} else {
					ZVAL_LONG(&prefix, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&input);
				ZVAL_COPY(&input, _0$$3);
				ZEPHIR_OBS_NVAR(&_4$$4);
				zephir_array_fetch_string(&_4$$4, &input, SL("name"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 208 TSRMLS_CC);
				if (Z_TYPE_P(&_4$$4) == IS_ARRAY) {
					zephir_array_fetch_string(&_5$$5, &input, SL("name"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 210 TSRMLS_CC);
					zephir_array_fetch_string(&_6$$5, &input, SL("type"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 211 TSRMLS_CC);
					zephir_array_fetch_string(&_7$$5, &input, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 212 TSRMLS_CC);
					zephir_array_fetch_string(&_8$$5, &input, SL("size"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 213 TSRMLS_CC);
					zephir_array_fetch_string(&_9$$5, &input, SL("error"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 214 TSRMLS_CC);
					ZEPHIR_CALL_METHOD(&smoothInput, this_ptr, "smoothfiles", &_10, 0, &_5$$5, &_6$$5, &_7$$5, &_8$$5, &_9$$5, &prefix);
					zephir_check_call_status();
					zephir_is_iterable(&smoothInput, 0, "phalconplus/Http/PsrRequest.zep", 231);
					if (Z_TYPE_P(&smoothInput) == IS_ARRAY) {
						ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&smoothInput), _11$$5)
						{
							ZEPHIR_INIT_NVAR(&file);
							ZVAL_COPY(&file, _11$$5);
							_13$$6 = ZEPHIR_IS_FALSE(onlySuccessful);
							if (!(_13$$6)) {
								zephir_array_fetch_string(&_14$$6, &file, SL("error"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 219 TSRMLS_CC);
								_13$$6 = ZEPHIR_IS_LONG(&_14$$6, 0);
							}
							if (_13$$6) {
								ZEPHIR_INIT_NVAR(&dataFile);
								zephir_create_array(&dataFile, 5, 0 TSRMLS_CC);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("name"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 221 TSRMLS_CC);
								zephir_array_update_string(&dataFile, SL("name"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("type"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 222 TSRMLS_CC);
								zephir_array_update_string(&dataFile, SL("type"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("tmp_name"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 223 TSRMLS_CC);
								zephir_array_update_string(&dataFile, SL("tmp_name"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("size"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 224 TSRMLS_CC);
								zephir_array_update_string(&dataFile, SL("size"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_OBS_NVAR(&_15$$7);
								zephir_array_fetch_string(&_15$$7, &file, SL("error"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 226 TSRMLS_CC);
								zephir_array_update_string(&dataFile, SL("error"), &_15$$7, PH_COPY | PH_SEPARATE);
								ZEPHIR_INIT_NVAR(&_16$$7);
								object_init_ex(&_16$$7, zephir_get_internal_ce(SL("phalcon\\http\\request\\file")));
								zephir_array_fetch_string(&_17$$7, &file, SL("key"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 228 TSRMLS_CC);
								ZEPHIR_CALL_METHOD(NULL, &_16$$7, "__construct", &_18, 0, &dataFile, &_17$$7);
								zephir_check_call_status();
								zephir_array_append(&files, &_16$$7, PH_SEPARATE, "phalconplus/Http/PsrRequest.zep", 228);
							}
						} ZEND_HASH_FOREACH_END();
					} else {
						ZEPHIR_CALL_METHOD(NULL, &smoothInput, "rewind", NULL, 0);
						zephir_check_call_status();
						while (1) {
							ZEPHIR_CALL_METHOD(&_12$$5, &smoothInput, "valid", NULL, 0);
							zephir_check_call_status();
							if (!zend_is_true(&_12$$5)) {
								break;
							}
							ZEPHIR_CALL_METHOD(&file, &smoothInput, "current", NULL, 0);
							zephir_check_call_status();
								_19$$8 = ZEPHIR_IS_FALSE(onlySuccessful);
								if (!(_19$$8)) {
									zephir_array_fetch_string(&_20$$8, &file, SL("error"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 219 TSRMLS_CC);
									_19$$8 = ZEPHIR_IS_LONG(&_20$$8, 0);
								}
								if (_19$$8) {
									ZEPHIR_INIT_NVAR(&_21$$9);
									zephir_create_array(&_21$$9, 5, 0 TSRMLS_CC);
									ZEPHIR_OBS_NVAR(&_22$$9);
									zephir_array_fetch_string(&_22$$9, &file, SL("name"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 221 TSRMLS_CC);
									zephir_array_update_string(&_21$$9, SL("name"), &_22$$9, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_22$$9);
									zephir_array_fetch_string(&_22$$9, &file, SL("type"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 222 TSRMLS_CC);
									zephir_array_update_string(&_21$$9, SL("type"), &_22$$9, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_22$$9);
									zephir_array_fetch_string(&_22$$9, &file, SL("tmp_name"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 223 TSRMLS_CC);
									zephir_array_update_string(&_21$$9, SL("tmp_name"), &_22$$9, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_22$$9);
									zephir_array_fetch_string(&_22$$9, &file, SL("size"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 224 TSRMLS_CC);
									zephir_array_update_string(&_21$$9, SL("size"), &_22$$9, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_22$$9);
									zephir_array_fetch_string(&_22$$9, &file, SL("error"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 226 TSRMLS_CC);
									zephir_array_update_string(&_21$$9, SL("error"), &_22$$9, PH_COPY | PH_SEPARATE);
									ZEPHIR_CPY_WRT(&dataFile, &_21$$9);
									ZEPHIR_INIT_NVAR(&_23$$9);
									object_init_ex(&_23$$9, zephir_get_internal_ce(SL("phalcon\\http\\request\\file")));
									zephir_array_fetch_string(&_24$$9, &file, SL("key"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 228 TSRMLS_CC);
									ZEPHIR_CALL_METHOD(NULL, &_23$$9, "__construct", &_18, 0, &dataFile, &_24$$9);
									zephir_check_call_status();
									zephir_array_append(&files, &_23$$9, PH_SEPARATE, "phalconplus/Http/PsrRequest.zep", 228);
								}
							ZEPHIR_CALL_METHOD(NULL, &smoothInput, "next", NULL, 0);
							zephir_check_call_status();
						}
					}
					ZEPHIR_INIT_NVAR(&file);
				} else {
					_25$$10 = ZEPHIR_IS_FALSE(onlySuccessful);
					if (!(_25$$10)) {
						zephir_array_fetch_string(&_26$$10, &input, SL("error"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 232 TSRMLS_CC);
						_25$$10 = ZEPHIR_IS_LONG(&_26$$10, 0);
					}
					if (_25$$10) {
						ZEPHIR_INIT_NVAR(&_27$$11);
						object_init_ex(&_27$$11, zephir_get_internal_ce(SL("phalcon\\http\\request\\file")));
						ZEPHIR_CALL_METHOD(NULL, &_27$$11, "__construct", &_18, 0, &input, &prefix);
						zephir_check_call_status();
						zephir_array_append(&files, &_27$$11, PH_SEPARATE, "phalconplus/Http/PsrRequest.zep", 233);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &superFiles, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &superFiles, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&prefix, &superFiles, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&input, &superFiles, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&_28$$12);
					zephir_array_fetch_string(&_28$$12, &input, SL("name"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 208 TSRMLS_CC);
					if (Z_TYPE_P(&_28$$12) == IS_ARRAY) {
						zephir_array_fetch_string(&_29$$13, &input, SL("name"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 210 TSRMLS_CC);
						zephir_array_fetch_string(&_30$$13, &input, SL("type"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 211 TSRMLS_CC);
						zephir_array_fetch_string(&_31$$13, &input, SL("tmp_name"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 212 TSRMLS_CC);
						zephir_array_fetch_string(&_32$$13, &input, SL("size"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 213 TSRMLS_CC);
						zephir_array_fetch_string(&_33$$13, &input, SL("error"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 214 TSRMLS_CC);
						ZEPHIR_CALL_METHOD(&smoothInput, this_ptr, "smoothfiles", &_10, 0, &_29$$13, &_30$$13, &_31$$13, &_32$$13, &_33$$13, &prefix);
						zephir_check_call_status();
						zephir_is_iterable(&smoothInput, 0, "phalconplus/Http/PsrRequest.zep", 231);
						if (Z_TYPE_P(&smoothInput) == IS_ARRAY) {
							ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&smoothInput), _34$$13)
							{
								ZEPHIR_INIT_NVAR(&file);
								ZVAL_COPY(&file, _34$$13);
								_36$$14 = ZEPHIR_IS_FALSE(onlySuccessful);
								if (!(_36$$14)) {
									zephir_array_fetch_string(&_37$$14, &file, SL("error"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 219 TSRMLS_CC);
									_36$$14 = ZEPHIR_IS_LONG(&_37$$14, 0);
								}
								if (_36$$14) {
									ZEPHIR_INIT_NVAR(&_38$$15);
									zephir_create_array(&_38$$15, 5, 0 TSRMLS_CC);
									ZEPHIR_OBS_NVAR(&_39$$15);
									zephir_array_fetch_string(&_39$$15, &file, SL("name"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 221 TSRMLS_CC);
									zephir_array_update_string(&_38$$15, SL("name"), &_39$$15, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_39$$15);
									zephir_array_fetch_string(&_39$$15, &file, SL("type"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 222 TSRMLS_CC);
									zephir_array_update_string(&_38$$15, SL("type"), &_39$$15, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_39$$15);
									zephir_array_fetch_string(&_39$$15, &file, SL("tmp_name"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 223 TSRMLS_CC);
									zephir_array_update_string(&_38$$15, SL("tmp_name"), &_39$$15, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_39$$15);
									zephir_array_fetch_string(&_39$$15, &file, SL("size"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 224 TSRMLS_CC);
									zephir_array_update_string(&_38$$15, SL("size"), &_39$$15, PH_COPY | PH_SEPARATE);
									ZEPHIR_OBS_NVAR(&_39$$15);
									zephir_array_fetch_string(&_39$$15, &file, SL("error"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 226 TSRMLS_CC);
									zephir_array_update_string(&_38$$15, SL("error"), &_39$$15, PH_COPY | PH_SEPARATE);
									ZEPHIR_CPY_WRT(&dataFile, &_38$$15);
									ZEPHIR_INIT_NVAR(&_40$$15);
									object_init_ex(&_40$$15, zephir_get_internal_ce(SL("phalcon\\http\\request\\file")));
									zephir_array_fetch_string(&_41$$15, &file, SL("key"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 228 TSRMLS_CC);
									ZEPHIR_CALL_METHOD(NULL, &_40$$15, "__construct", &_18, 0, &dataFile, &_41$$15);
									zephir_check_call_status();
									zephir_array_append(&files, &_40$$15, PH_SEPARATE, "phalconplus/Http/PsrRequest.zep", 228);
								}
							} ZEND_HASH_FOREACH_END();
						} else {
							ZEPHIR_CALL_METHOD(NULL, &smoothInput, "rewind", NULL, 0);
							zephir_check_call_status();
							while (1) {
								ZEPHIR_CALL_METHOD(&_35$$13, &smoothInput, "valid", NULL, 0);
								zephir_check_call_status();
								if (!zend_is_true(&_35$$13)) {
									break;
								}
								ZEPHIR_CALL_METHOD(&file, &smoothInput, "current", NULL, 0);
								zephir_check_call_status();
									_42$$16 = ZEPHIR_IS_FALSE(onlySuccessful);
									if (!(_42$$16)) {
										zephir_array_fetch_string(&_43$$16, &file, SL("error"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 219 TSRMLS_CC);
										_42$$16 = ZEPHIR_IS_LONG(&_43$$16, 0);
									}
									if (_42$$16) {
										ZEPHIR_INIT_NVAR(&_44$$17);
										zephir_create_array(&_44$$17, 5, 0 TSRMLS_CC);
										ZEPHIR_OBS_NVAR(&_45$$17);
										zephir_array_fetch_string(&_45$$17, &file, SL("name"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 221 TSRMLS_CC);
										zephir_array_update_string(&_44$$17, SL("name"), &_45$$17, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&_45$$17);
										zephir_array_fetch_string(&_45$$17, &file, SL("type"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 222 TSRMLS_CC);
										zephir_array_update_string(&_44$$17, SL("type"), &_45$$17, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&_45$$17);
										zephir_array_fetch_string(&_45$$17, &file, SL("tmp_name"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 223 TSRMLS_CC);
										zephir_array_update_string(&_44$$17, SL("tmp_name"), &_45$$17, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&_45$$17);
										zephir_array_fetch_string(&_45$$17, &file, SL("size"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 224 TSRMLS_CC);
										zephir_array_update_string(&_44$$17, SL("size"), &_45$$17, PH_COPY | PH_SEPARATE);
										ZEPHIR_OBS_NVAR(&_45$$17);
										zephir_array_fetch_string(&_45$$17, &file, SL("error"), PH_NOISY, "phalconplus/Http/PsrRequest.zep", 226 TSRMLS_CC);
										zephir_array_update_string(&_44$$17, SL("error"), &_45$$17, PH_COPY | PH_SEPARATE);
										ZEPHIR_CPY_WRT(&dataFile, &_44$$17);
										ZEPHIR_INIT_NVAR(&_46$$17);
										object_init_ex(&_46$$17, zephir_get_internal_ce(SL("phalcon\\http\\request\\file")));
										zephir_array_fetch_string(&_47$$17, &file, SL("key"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 228 TSRMLS_CC);
										ZEPHIR_CALL_METHOD(NULL, &_46$$17, "__construct", &_18, 0, &dataFile, &_47$$17);
										zephir_check_call_status();
										zephir_array_append(&files, &_46$$17, PH_SEPARATE, "phalconplus/Http/PsrRequest.zep", 228);
									}
								ZEPHIR_CALL_METHOD(NULL, &smoothInput, "next", NULL, 0);
								zephir_check_call_status();
							}
						}
						ZEPHIR_INIT_NVAR(&file);
					} else {
						_48$$18 = ZEPHIR_IS_FALSE(onlySuccessful);
						if (!(_48$$18)) {
							zephir_array_fetch_string(&_49$$18, &input, SL("error"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrRequest.zep", 232 TSRMLS_CC);
							_48$$18 = ZEPHIR_IS_LONG(&_49$$18, 0);
						}
						if (_48$$18) {
							ZEPHIR_INIT_NVAR(&_50$$19);
							object_init_ex(&_50$$19, zephir_get_internal_ce(SL("phalcon\\http\\request\\file")));
							ZEPHIR_CALL_METHOD(NULL, &_50$$19, "__construct", &_18, 0, &input, &prefix);
							zephir_check_call_status();
							zephir_array_append(&files, &_50$$19, PH_SEPARATE, "phalconplus/Http/PsrRequest.zep", 233);
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &superFiles, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&input);
		ZEPHIR_INIT_NVAR(&prefix);
	}
	RETURN_CCTOR(&files);

}

PHP_METHOD(PhalconPlus_Http_PsrRequest, getHeaders) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "headers");

}

PHP_METHOD(PhalconPlus_Http_PsrRequest, getContentType) {

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

zend_object *zephir_init_properties_PhalconPlus_Http_PsrRequest(zend_class_entry *class_type TSRMLS_DC) {

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

