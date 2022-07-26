
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
#include "kernel/concat.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Http_NonPsrResponse)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Http, NonPsrResponse, phalconplus, http_nonpsrresponse, zephir_get_internal_ce(SL("phalcon\\http\\response")), phalconplus_http_nonpsrresponse_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Http_NonPsrResponse, __construct)
{
	zend_string *_8;
	zend_ulong _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_11 = NULL, *_17 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *psrResponse, psrResponse_sub, _0, _1, _2, _3, cookies, cookie, values, value, name, _4, newPsrResponse, headers, *_5, _6, *_14, _15, *_9$$3, _10$$3, *_12$$6, _13$$6, _16$$9, _18$$10;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&psrResponse_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&cookies);
	ZVAL_UNDEF(&cookie);
	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&newPsrResponse);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_18$$10);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(psrResponse, zephir_get_internal_ce(SL("psrext\\http\\message\\responseinterface")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &psrResponse);


	ZEPHIR_CALL_METHOD(&_0, psrResponse, "getbody", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, &_0, "__tostring", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, psrResponse, "getstatuscode", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, psrResponse, "getreasonphrase", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_PARENT(NULL, phalconplus_http_nonpsrresponse_ce, getThis(), "__construct", NULL, 0, &_1, &_2, &_3);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "Set-Cookie");
	ZEPHIR_CALL_METHOD(&cookies, psrResponse, "getheader", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Set-Cookie");
	ZEPHIR_CALL_METHOD(&newPsrResponse, psrResponse, "withoutheader", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&headers, &newPsrResponse, "getheaders", NULL, 0);
	zephir_check_call_status();
	zephir_is_iterable(&headers, 0, "phalconplus/Http/NonPsrResponse.zep", 32);
	if (Z_TYPE_P(&headers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&headers), _7, _8, _5)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&name, _8);
			} else {
				ZVAL_LONG(&name, _7);
			}
			ZEPHIR_INIT_NVAR(&values);
			ZVAL_COPY(&values, _5);
			zephir_is_iterable(&values, 0, "phalconplus/Http/NonPsrResponse.zep", 30);
			if (Z_TYPE_P(&values) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _9$$3)
				{
					ZEPHIR_INIT_NVAR(&value);
					ZVAL_COPY(&value, _9$$3);
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", &_11, 0, &name, &value);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_10$$3, &values, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_10$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", &_11, 0, &name, &value);
						zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&value);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &headers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_6, &headers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_6)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &headers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&values, &headers, "current", NULL, 0);
			zephir_check_call_status();
				zephir_is_iterable(&values, 0, "phalconplus/Http/NonPsrResponse.zep", 30);
				if (Z_TYPE_P(&values) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&values), _12$$6)
					{
						ZEPHIR_INIT_NVAR(&value);
						ZVAL_COPY(&value, _12$$6);
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", &_11, 0, &name, &value);
						zephir_check_call_status();
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &values, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_13$$6, &values, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_13$$6)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&value, &values, "current", NULL, 0);
						zephir_check_call_status();
							ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", &_11, 0, &name, &value);
							zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &values, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&value);
			ZEPHIR_CALL_METHOD(NULL, &headers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&values);
	ZEPHIR_INIT_NVAR(&name);
	zephir_is_iterable(&cookies, 0, "phalconplus/Http/NonPsrResponse.zep", 35);
	if (Z_TYPE_P(&cookies) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&cookies), _14)
		{
			ZEPHIR_INIT_NVAR(&cookie);
			ZVAL_COPY(&cookie, _14);
			ZEPHIR_INIT_NVAR(&_16$$9);
			ZEPHIR_CONCAT_SV(&_16$$9, "Set-Cookie: ", &cookie);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrawheader", &_17, 0, &_16$$9);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &cookies, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_15, &cookies, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_15)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&cookie, &cookies, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_18$$10);
				ZEPHIR_CONCAT_SV(&_18$$10, "Set-Cookie: ", &cookie);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "setrawheader", &_17, 0, &_18$$10);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &cookies, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&cookie);
	ZEPHIR_MM_RESTORE();
}

