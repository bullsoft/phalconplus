
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Http_PsrResponseFactory)
{
	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Http, PsrResponseFactory, phalconplus, http_psrresponsefactory, phalconplus_http_psrresponsefactory_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Http_PsrResponseFactory, create)
{
	zend_class_entry *_1;
	zval className;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *response, response_sub, *protocol = NULL, protocol_sub, status, reason, content, headers, psrResponse, _0, _2, _3$$3, _4$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&protocol_sub);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&reason);
	ZVAL_UNDEF(&content);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&psrResponse);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&className);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(response, zephir_get_internal_ce(SL("phalcon\\http\\response")))
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(protocol)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &response, &protocol);
	if (!protocol) {
		protocol = &protocol_sub;
		ZEPHIR_INIT_VAR(protocol);
		ZVAL_STRING(protocol, "1.1");
	}


	ZEPHIR_CALL_METHOD(&status, response, "getstatuscode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&reason, response, "getreasonphrase", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&content, response, "getcontent", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_SELF(&headers, "mapheaders", NULL, 0, response);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&className);
	ZVAL_STRING(&className, "GuzzleHttp\\Psr7\\Response");
	ZEPHIR_INIT_VAR(&psrResponse);
	zephir_fetch_safe_class(&_0, &className);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	if(!_1) {
		RETURN_MM_NULL();
	}
	object_init_ex(&psrResponse, _1);
	if (zephir_has_constructor(&psrResponse)) {
		ZEPHIR_INIT_VAR(&_2);
		if (zephir_is_true(&status)) {
			ZEPHIR_CPY_WRT(&_2, &status);
		} else {
			ZEPHIR_INIT_NVAR(&_2);
			ZVAL_LONG(&_2, 200);
		}
		ZEPHIR_CALL_METHOD(NULL, &psrResponse, "__construct", NULL, 0, &_2, &headers, &content, protocol);
		zephir_check_call_status();
	}

	if (!(zephir_array_isset_string(&headers, SL("Content-Length")))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "Content-Length");
		ZVAL_LONG(&_4$$3, zephir_fast_strlen_ev(&content));
		ZEPHIR_CALL_METHOD(NULL, &psrResponse, "withaddedheader", NULL, 0, &_3$$3, &_4$$3);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&psrResponse);
}

PHP_METHOD(PhalconPlus_Http_PsrResponseFactory, mapHeaders)
{
	zend_bool _22$$13, _23$$15;
	zval _8$$6, _15$$11;
	zend_string *_21;
	zend_ulong _20;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *response, response_sub, __$null, headers, _0, rawHeaders, line, key, pos, nativeHeaders, *_1, _2, _17, *_18, _19, _24, _3$$3, name$$4, _4$$4, value$$4, _5$$4, _6$$4, _7$$5, _9$$6, _10$$8, name$$9, _11$$9, value$$9, _12$$9, _13$$9, _14$$10, _16$$11, _25$$17, _26$$17, _27$$17, _28$$17;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&rawHeaders);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&pos);
	ZVAL_UNDEF(&nativeHeaders);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_24);
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
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$17);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_15$$11);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(response, zephir_get_internal_ce(SL("phalcon\\http\\response")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response);


	ZEPHIR_CALL_METHOD(&_0, response, "getheaders", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&headers, &_0, "toarray", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&rawHeaders, "headers_list", NULL, 143);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&nativeHeaders);
	array_init(&nativeHeaders);
	zephir_is_iterable(&rawHeaders, 0, "phalconplus/Http/PsrResponseFactory.zep", 63);
	if (Z_TYPE_P(&rawHeaders) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rawHeaders), _1)
		{
			ZEPHIR_INIT_NVAR(&line);
			ZVAL_COPY(&line, _1);
			ZEPHIR_INIT_NVAR(&_3$$3);
			ZVAL_STRING(&_3$$3, ":");
			ZEPHIR_INIT_NVAR(&pos);
			zephir_fast_strpos(&pos, &line, &_3$$3, 0 );
			if (!ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
				ZVAL_LONG(&_4$$4, 0);
				ZEPHIR_INIT_NVAR(&name$$4);
				zephir_substr(&name$$4, &line, 0 , zephir_get_intval(&pos), 0);
				ZVAL_LONG(&_5$$4, (zephir_get_numberval(&pos) + 1));
				ZEPHIR_INIT_NVAR(&_6$$4);
				zephir_substr(&_6$$4, &line, zephir_get_intval(&_5$$4), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_INIT_NVAR(&value$$4);
				zephir_fast_trim(&value$$4, &_6$$4, NULL , ZEPHIR_TRIM_BOTH);
				if (zephir_array_isset(&nativeHeaders, &name$$4)) {
					zephir_array_fetch(&_7$$5, &nativeHeaders, &name$$4, PH_NOISY | PH_READONLY, "phalconplus/Http/PsrResponseFactory.zep", 54);
					if (!(Z_TYPE_P(&_7$$5) == IS_ARRAY)) {
						ZEPHIR_INIT_NVAR(&_8$$6);
						zephir_create_array(&_8$$6, 1, 0);
						ZEPHIR_OBS_NVAR(&_9$$6);
						zephir_array_fetch(&_9$$6, &nativeHeaders, &name$$4, PH_NOISY, "phalconplus/Http/PsrResponseFactory.zep", 55);
						zephir_array_fast_append(&_8$$6, &_9$$6);
						zephir_array_update_zval(&nativeHeaders, &name$$4, &_8$$6, PH_COPY | PH_SEPARATE);
					}
					zephir_array_update_multi(&nativeHeaders, &value$$4, SL("za"), 2, &name$$4);
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
			ZEPHIR_CALL_METHOD(&line, &rawHeaders, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_10$$8);
				ZVAL_STRING(&_10$$8, ":");
				ZEPHIR_INIT_NVAR(&pos);
				zephir_fast_strpos(&pos, &line, &_10$$8, 0 );
				if (!ZEPHIR_IS_FALSE_IDENTICAL(&pos)) {
					ZVAL_LONG(&_11$$9, 0);
					ZEPHIR_INIT_NVAR(&name$$9);
					zephir_substr(&name$$9, &line, 0 , zephir_get_intval(&pos), 0);
					ZVAL_LONG(&_12$$9, (zephir_get_numberval(&pos) + 1));
					ZEPHIR_INIT_NVAR(&_13$$9);
					zephir_substr(&_13$$9, &line, zephir_get_intval(&_12$$9), 0, ZEPHIR_SUBSTR_NO_LENGTH);
					ZEPHIR_INIT_NVAR(&value$$9);
					zephir_fast_trim(&value$$9, &_13$$9, NULL , ZEPHIR_TRIM_BOTH);
					if (zephir_array_isset(&nativeHeaders, &name$$9)) {
						zephir_array_fetch(&_14$$10, &nativeHeaders, &name$$9, PH_NOISY | PH_READONLY, "phalconplus/Http/PsrResponseFactory.zep", 54);
						if (!(Z_TYPE_P(&_14$$10) == IS_ARRAY)) {
							ZEPHIR_INIT_NVAR(&_15$$11);
							zephir_create_array(&_15$$11, 1, 0);
							ZEPHIR_OBS_NVAR(&_16$$11);
							zephir_array_fetch(&_16$$11, &nativeHeaders, &name$$9, PH_NOISY, "phalconplus/Http/PsrResponseFactory.zep", 55);
							zephir_array_fast_append(&_15$$11, &_16$$11);
							zephir_array_update_zval(&nativeHeaders, &name$$9, &_15$$11, PH_COPY | PH_SEPARATE);
						}
						zephir_array_update_multi(&nativeHeaders, &value$$9, SL("za"), 2, &name$$9);
					} else {
						zephir_array_update_zval(&nativeHeaders, &name$$9, &value$$9, PH_COPY | PH_SEPARATE);
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &rawHeaders, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&line);
	ZEPHIR_INIT_VAR(&_17);
	zephir_is_iterable(&headers, 1, "phalconplus/Http/PsrResponseFactory.zep", 70);
	if (Z_TYPE_P(&headers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&headers), _20, _21, _18)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_21 != NULL) { 
				ZVAL_STR_COPY(&key, _21);
			} else {
				ZVAL_LONG(&key, _20);
			}
			ZEPHIR_INIT_NVAR(&_17);
			ZVAL_COPY(&_17, _18);
			_22$$13 = Z_TYPE_P(&key) == IS_STRING;
			if (_22$$13) {
				_22$$13 = zephir_start_with_str(&key, SL("HTTP/"));
			}
			if (_22$$13) {
				zephir_array_unset(&headers, &key, PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &headers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_19, &headers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_19)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &headers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_17, &headers, "current", NULL, 0);
			zephir_check_call_status();
				_23$$15 = Z_TYPE_P(&key) == IS_STRING;
				if (_23$$15) {
					_23$$15 = zephir_start_with_str(&key, SL("HTTP/"));
				}
				if (_23$$15) {
					zephir_array_unset(&headers, &key, PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &headers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&_17);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_CALL_FUNCTION(NULL, "header_remove", NULL, 144);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_24);
	zephir_fast_array_merge(&_24, &nativeHeaders, &headers);
	ZEPHIR_CPY_WRT(&headers, &_24);
	if (zephir_array_isset_string(&nativeHeaders, SL("Set-Cookie"))) {
		ZEPHIR_INIT_VAR(&_25$$17);
		zephir_array_fetch_string(&_26$$17, &nativeHeaders, SL("Set-Cookie"), PH_NOISY | PH_READONLY, "phalconplus/Http/PsrResponseFactory.zep", 74);
		if (Z_TYPE_P(&_26$$17) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&_25$$17);
			zephir_array_fetch_string(&_25$$17, &nativeHeaders, SL("Set-Cookie"), PH_NOISY, "phalconplus/Http/PsrResponseFactory.zep", 74);
		} else {
			ZEPHIR_INIT_VAR(&_27$$17);
			zephir_create_array(&_27$$17, 1, 0);
			ZEPHIR_OBS_VAR(&_28$$17);
			zephir_array_fetch_string(&_28$$17, &nativeHeaders, SL("Set-Cookie"), PH_NOISY, "phalconplus/Http/PsrResponseFactory.zep", 74);
			zephir_array_fast_append(&_27$$17, &_28$$17);
			ZEPHIR_CPY_WRT(&_25$$17, &_27$$17);
		}
		zephir_array_update_string(&headers, SL("Set-Cookie"), &_25$$17, PH_COPY | PH_SEPARATE);
	} else {
		zephir_array_update_string(&headers, SL("Set-Cookie"), &__$null, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(&headers);
}

