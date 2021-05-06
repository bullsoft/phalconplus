
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
#include "ext/psr/psr_http_message.h"
#include "kernel/file.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Http_NonPsrRequest)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Http, NonPsrRequest, phalconplus, http_nonpsrrequest, zephir_get_internal_ce(SL("phalcon\\http\\request")), phalconplus_http_nonpsrrequest_method_entry, 0);

	zend_declare_property_null(phalconplus_http_nonpsrrequest_ce, SL("attributes"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalconplus_http_nonpsrrequest_ce, SL("cookies"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalconplus_http_nonpsrrequest_ce, SL("files"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalconplus_http_nonpsrrequest_ce, SL("psrRequest"), ZEND_ACC_PROTECTED);
	zend_declare_property_null(phalconplus_http_nonpsrrequest_ce, SL("headers"), ZEND_ACC_PROTECTED);
	phalconplus_http_nonpsrrequest_ce->create_object = zephir_init_properties_PhalconPlus_Http_NonPsrRequest;

	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getAttributes)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "attributes");
}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getCookies)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "cookies");
}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getFiles)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "files");
}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getPsrRequest)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "psrRequest");
}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, __construct)
{
	zend_string *_15, *_19, *_23, *_28, *_45, *_57;
	zend_ulong _14, _18, _22, _27, _44, _56;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_33 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, _POST, _GET, _SERVER, _COOKIE, _FILES, _0, _1, _2, _3, _4, _5, _6, _7, posts, gets, cookies, serverParams, _8, _9, _10, _11, k, v, *_12, _13, *_16, _17, *_20, _21, _24, *_25, _26, _40, _41, *_42, _43, _46, _52, prefix, input, _53, *_54, _55, _29$$23, _30$$23, _31$$23, _32$$23, _34$$23, _35$$24, _36$$24, _37$$24, _38$$24, _39$$24, _47$$27, _48$$27, _49$$28, _50$$28, _51$$28;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&_POST);
	ZVAL_UNDEF(&_GET);
	ZVAL_UNDEF(&_SERVER);
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
	ZVAL_UNDEF(&posts);
	ZVAL_UNDEF(&gets);
	ZVAL_UNDEF(&cookies);
	ZVAL_UNDEF(&serverParams);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&k);
	ZVAL_UNDEF(&v);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_52);
	ZVAL_UNDEF(&prefix);
	ZVAL_UNDEF(&input);
	ZVAL_UNDEF(&_53);
	ZVAL_UNDEF(&_55);
	ZVAL_UNDEF(&_29$$23);
	ZVAL_UNDEF(&_30$$23);
	ZVAL_UNDEF(&_31$$23);
	ZVAL_UNDEF(&_32$$23);
	ZVAL_UNDEF(&_34$$23);
	ZVAL_UNDEF(&_35$$24);
	ZVAL_UNDEF(&_36$$24);
	ZVAL_UNDEF(&_37$$24);
	ZVAL_UNDEF(&_38$$24);
	ZVAL_UNDEF(&_39$$24);
	ZVAL_UNDEF(&_47$$27);
	ZVAL_UNDEF(&_48$$27);
	ZVAL_UNDEF(&_49$$28);
	ZVAL_UNDEF(&_50$$28);
	ZVAL_UNDEF(&_51$$28);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(request, PsrHttpMessageServerRequestInterface_ce_ptr)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_get_global(&_FILES, SL("_FILES"));
	zephir_get_global(&_COOKIE, SL("_COOKIE"));
	zephir_get_global(&_SERVER, SL("_SERVER"));
	zephir_get_global(&_GET, SL("_GET"));
	zephir_get_global(&_POST, SL("_POST"));
	zephir_fetch_params(1, 1, 0, &request);


	zephir_update_property_zval(this_ptr, ZEND_STRL("psrRequest"), request);
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &_0);
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("cookies"), &_2);
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
	zephir_update_property_zval(this_ptr, ZEND_STRL("headers"), &_4);
	ZEPHIR_CALL_METHOD(&_6, request, "getbody", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_7, &_6, "__tostring", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("rawBody"), &_7);
	ZEPHIR_CALL_METHOD(&_8, request, "getparsedbody", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_8))) {
		ZEPHIR_INIT_VAR(&posts);
		array_init(&posts);
	} else {
		ZEPHIR_CALL_METHOD(&posts, request, "getparsedbody", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_9, request, "getqueryparams", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_9))) {
		ZEPHIR_INIT_VAR(&gets);
		array_init(&gets);
	} else {
		ZEPHIR_CALL_METHOD(&gets, request, "getqueryparams", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_10, request, "getcookieparams", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_10))) {
		ZEPHIR_INIT_VAR(&cookies);
		array_init(&cookies);
	} else {
		ZEPHIR_CALL_METHOD(&cookies, request, "getcookieparams", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_11, request, "getserverparams", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_11))) {
		ZEPHIR_INIT_VAR(&serverParams);
		array_init(&serverParams);
	} else {
		ZEPHIR_CALL_METHOD(&serverParams, request, "getserverparams", NULL, 0);
		zephir_check_call_status();
	}
	zephir_is_iterable(&posts, 0, "phalconplus/Http/NonPsrRequest.zep", 45);
	if (Z_TYPE_P(&posts) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&posts), _14, _15, _12)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_15 != NULL) { 
				ZVAL_STR_COPY(&k, _15);
			} else {
				ZVAL_LONG(&k, _14);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _12);
			zephir_array_update_zval(&_POST, &k, &v, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &posts, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_13, &posts, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_13)) {
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
	zephir_is_iterable(&gets, 0, "phalconplus/Http/NonPsrRequest.zep", 49);
	if (Z_TYPE_P(&gets) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&gets), _18, _19, _16)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_19 != NULL) { 
				ZVAL_STR_COPY(&k, _19);
			} else {
				ZVAL_LONG(&k, _18);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _16);
			zephir_array_update_zval(&_GET, &k, &v, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &gets, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_17, &gets, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
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
	zephir_is_iterable(&serverParams, 0, "phalconplus/Http/NonPsrRequest.zep", 52);
	if (Z_TYPE_P(&serverParams) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&serverParams), _22, _23, _20)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_23 != NULL) { 
				ZVAL_STR_COPY(&k, _23);
			} else {
				ZVAL_LONG(&k, _22);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _20);
			zephir_array_update_zval(&_SERVER, &k, &v, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &serverParams, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_21, &serverParams, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_21)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&k, &serverParams, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&v, &serverParams, "current", NULL, 0);
			zephir_check_call_status();
				zephir_array_update_zval(&_SERVER, &k, &v, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &serverParams, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	zephir_read_property(&_24, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_24, 0, "phalconplus/Http/NonPsrRequest.zep", 56);
	if (Z_TYPE_P(&_24) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_24), _27, _28, _25)
		{
			ZEPHIR_INIT_NVAR(&k);
			if (_28 != NULL) { 
				ZVAL_STR_COPY(&k, _28);
			} else {
				ZVAL_LONG(&k, _27);
			}
			ZEPHIR_INIT_NVAR(&v);
			ZVAL_COPY(&v, _25);
			ZEPHIR_INIT_NVAR(&_29$$23);
			ZEPHIR_INIT_NVAR(&_30$$23);
			ZVAL_STRING(&_30$$23, "-");
			ZEPHIR_INIT_NVAR(&_31$$23);
			ZVAL_STRING(&_31$$23, "_");
			zephir_fast_str_replace(&_29$$23, &_30$$23, &_31$$23, &k);
			ZEPHIR_INIT_NVAR(&k);
			zephir_fast_strtoupper(&k, &_29$$23);
			ZEPHIR_INIT_NVAR(&_32$$23);
			if (Z_TYPE_P(&v) == IS_ARRAY) {
				ZEPHIR_MAKE_REF(&v);
				ZEPHIR_CALL_FUNCTION(&_32$$23, "reset", &_33, 70, &v);
				ZEPHIR_UNREF(&v);
				zephir_check_call_status();
			} else {
				ZEPHIR_CPY_WRT(&_32$$23, &v);
			}
			ZEPHIR_INIT_NVAR(&_34$$23);
			ZEPHIR_CONCAT_SV(&_34$$23, "HTTP_", &k);
			zephir_array_update_zval(&_SERVER, &_34$$23, &_32$$23, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_24, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_26, &_24, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_26)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&k, &_24, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&v, &_24, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_35$$24);
				ZEPHIR_INIT_NVAR(&_36$$24);
				ZVAL_STRING(&_36$$24, "-");
				ZEPHIR_INIT_NVAR(&_37$$24);
				ZVAL_STRING(&_37$$24, "_");
				zephir_fast_str_replace(&_35$$24, &_36$$24, &_37$$24, &k);
				ZEPHIR_INIT_NVAR(&k);
				zephir_fast_strtoupper(&k, &_35$$24);
				ZEPHIR_INIT_NVAR(&_38$$24);
				if (Z_TYPE_P(&v) == IS_ARRAY) {
					ZEPHIR_MAKE_REF(&v);
					ZEPHIR_CALL_FUNCTION(&_38$$24, "reset", &_33, 70, &v);
					ZEPHIR_UNREF(&v);
					zephir_check_call_status();
				} else {
					ZEPHIR_CPY_WRT(&_38$$24, &v);
				}
				ZEPHIR_INIT_NVAR(&_39$$24);
				ZEPHIR_CONCAT_SV(&_39$$24, "HTTP_", &k);
				zephir_array_update_zval(&_SERVER, &_39$$24, &_38$$24, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_24, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&v);
	ZEPHIR_INIT_NVAR(&k);
	ZEPHIR_CALL_METHOD(&_40, this_ptr, "getrequesttarget", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_SERVER, SL("REQUEST_URI"), &_40, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_41, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_SERVER, SL("REQUEST_METHOD"), &_41, PH_COPY | PH_SEPARATE);
	zephir_is_iterable(&cookies, 0, "phalconplus/Http/NonPsrRequest.zep", 63);
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
	zephir_read_property(&_46, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_46))) {
		zephir_read_property(&_47$$27, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&_48$$27, "session_name", NULL, 138);
		zephir_check_call_status();
		if (zephir_array_isset(&_47$$27, &_48$$27)) {
			zephir_read_property(&_49$$28, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_FUNCTION(&_51$$28, "session_name", NULL, 138);
			zephir_check_call_status();
			zephir_array_fetch(&_50$$28, &_49$$28, &_51$$28, PH_NOISY | PH_READONLY, "phalconplus/Http/NonPsrRequest.zep", 65);
			ZEPHIR_CALL_FUNCTION(NULL, "session_id", NULL, 45, &_50$$28);
			zephir_check_call_status();
		}
	}
	ZEPHIR_CALL_METHOD(&_52, request, "getuploadedfiles", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "mapfiles", NULL, 139, &_52);
	zephir_check_call_status();
	zephir_read_property(&_53, this_ptr, ZEND_STRL("files"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_53, 0, "phalconplus/Http/NonPsrRequest.zep", 74);
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
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getRequestTarget)
{
	zval request, target, _0, _1, _2, _3$$4, _4$$4, _5$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&target);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&request);
	zephir_read_property(&request, this_ptr, ZEND_STRL("psrRequest"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_0, &request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&target, &_0, "getpath", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_STRING(&target, "")) {
		ZEPHIR_INIT_NVAR(&target);
		ZVAL_STRING(&target, "/");
	}
	ZEPHIR_CALL_METHOD(&_1, &request, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_1, "getquery", NULL, 0);
	zephir_check_call_status();
	if (!ZEPHIR_IS_STRING(&_2, "")) {
		ZEPHIR_CALL_METHOD(&_3$$4, &request, "geturi", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$4, &_3$$4, "getquery", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_SV(&_5$$4, "?", &_4$$4);
		zephir_concat_self(&target, &_5$$4);
	}
	RETURN_CCTOR(&target);
}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, mapFiles)
{
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(uploads)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &uploads_param);
	zephir_get_arrval(&uploads, uploads_param);


	zephir_is_iterable(&uploads, 0, "phalconplus/Http/NonPsrRequest.zep", 113);
	if (Z_TYPE_P(&uploads) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&uploads), _0)
		{
			ZEPHIR_INIT_NVAR(&file);
			ZVAL_COPY(&file, _0);
			if (Z_TYPE_P(&file) == IS_ARRAY) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "mapfiles", &_2, 139, &file);
				zephir_check_call_status();
			} else if (zephir_is_instance_of(&file, SL("Psr\\Http\\Message\\UploadedFileInterface"))) {
				ZEPHIR_CALL_FUNCTION(&_3$$5, "sys_get_temp_dir", &_4, 140);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZVAL_STRING(&_5$$5, "upload");
				ZEPHIR_CALL_FUNCTION(&tmpname$$5, "tempnam", &_6, 141, &_3$$5, &_5$$5);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_7$$5, &file, "geterror", NULL, 0);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&_7$$5, 0)) {
					ZEPHIR_CALL_METHOD(&_8$$6, &file, "getstream", NULL, 0);
					zephir_check_call_status();
					zephir_cast_to_string(&_9$$6, &_8$$6);
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
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "mapfiles", &_2, 139, &file);
					zephir_check_call_status();
				} else if (zephir_is_instance_of(&file, SL("Psr\\Http\\Message\\UploadedFileInterface"))) {
					ZEPHIR_CALL_FUNCTION(&_12$$9, "sys_get_temp_dir", &_4, 140);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&_13$$9);
					ZVAL_STRING(&_13$$9, "upload");
					ZEPHIR_CALL_FUNCTION(&tmpname$$9, "tempnam", &_6, 141, &_12$$9, &_13$$9);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_14$$9, &file, "geterror", NULL, 0);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_14$$9, 0)) {
						ZEPHIR_CALL_METHOD(&_15$$10, &file, "getstream", NULL, 0);
						zephir_check_call_status();
						zephir_cast_to_string(&_16$$10, &_15$$10);
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

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, removeTmpFiles)
{
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

	zephir_read_property(&_0, this_ptr, ZEND_STRL("files"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalconplus/Http/NonPsrRequest.zep", 125);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _1)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _1);
			ZEPHIR_OBS_NVAR(&tmp);
			if (zephir_array_isset_string_fetch(&tmp, &item, SL("tmp_name"), 0)) {
				if ((zephir_file_exists(&tmp) == SUCCESS)) {
					ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_3, 142, &tmp);
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
						ZEPHIR_CALL_FUNCTION(NULL, "unlink", &_3, 142, &tmp);
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

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getScheme)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("psrRequest"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "getscheme", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Checks whether request has been made using ajax
 */
PHP_METHOD(PhalconPlus_Http_NonPsrRequest, isAjax)
{
	zend_bool _1;
	zval _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	_1 = zephir_array_isset_string(&_0, SL("HTTP_X_REQUESTED_WITH"));
	if (_1) {
		zephir_read_property(&_2, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch_string(&_3, &_2, SL("HTTP_X_REQUESTED_WITH"), PH_NOISY | PH_READONLY, "phalconplus/Http/NonPsrRequest.zep", 137);
		_1 = ZEPHIR_IS_STRING_IDENTICAL(&_3, "XMLHttpRequest");
	}
	RETURN_BOOL(_1);
}

/**
 * Checks whether request has been made using SOAP
 */
PHP_METHOD(PhalconPlus_Http_NonPsrRequest, isSoap)
{
	zval contentType, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contentType);
	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_string(&_0, SL("HTTP_SOAPACTION"))) {
		RETURN_MM_BOOL(1);
	} else {
		ZEPHIR_CALL_METHOD(&contentType, this_ptr, "getcontenttype", NULL, 0);
		zephir_check_call_status();
		if (!(ZEPHIR_IS_EMPTY(&contentType))) {
			RETURN_MM_BOOL(zephir_memnstr_str(&contentType, SL("application/soap+xml"), "phalconplus/Http/NonPsrRequest.zep", 151));
		}
	}
	RETURN_MM_BOOL(0);
}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getHttpHost)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("psrRequest"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "gethost", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getPort)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("psrRequest"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "geturi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_1, "getport", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getHeaders)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "headers");
}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getContentType)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("psrRequest"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "Content-Type");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "getheaderline", NULL, 0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, __destruct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(NULL, this_ptr, "removetmpfiles", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

zend_object *zephir_init_properties_PhalconPlus_Http_NonPsrRequest(zend_class_entry *class_type)
{
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("headers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("headers"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("files"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("files"), &_3$$4);
		}
		zephir_read_property_ex(&_4, this_ptr, ZEND_STRL("cookies"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("cookies"), &_5$$5);
		}
		zephir_read_property_ex(&_6, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("attributes"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

