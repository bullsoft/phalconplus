
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Curl_Response) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Curl, Response, phalconplus, curl_response, phalconplus_curl_response_method_entry, 0);

	/**
	 * The response headers.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalconplus_curl_response_ce, SL("headers"), ZEND_ACC_PUBLIC);

	/**
	 * The response body.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalconplus_curl_response_ce, SL("body"), "", ZEND_ACC_PUBLIC);

	/**
	 * The results of curl_getinfo on the response request.
	 *
	 * @var array|false
	 */
	zend_declare_property_null(phalconplus_curl_response_ce, SL("info"), ZEND_ACC_PUBLIC);

	/**
	 * The response code including text, e.g. '200 OK'.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalconplus_curl_response_ce, SL("statusText"), "", ZEND_ACC_PUBLIC);

	/**
	 * The response code.
	 *
	 * @var int
	 */
	zend_declare_property_null(phalconplus_curl_response_ce, SL("statusCode"), ZEND_ACC_PUBLIC);

	phalconplus_curl_response_ce->create_object = zephir_init_properties_PhalconPlus_Curl_Response;
	return SUCCESS;

}

/**
 * The response body.
 */
PHP_METHOD(PhalconPlus_Curl_Response, getBody) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "body");

}

/**
 * The response code including text, e.g. '200 OK'.
 */
PHP_METHOD(PhalconPlus_Curl_Response, getStatusText) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "statusText");

}

/**
 * The response code.
 */
PHP_METHOD(PhalconPlus_Curl_Response, getStatusCode) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "statusCode");

}

/**
 * @param string $body
 * @param string $headers
 * @param mixed  $info
 */
PHP_METHOD(PhalconPlus_Curl_Response, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *body_param = NULL, *headers_param = NULL, *info = NULL, info_sub;
	zval body, headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&body);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&info_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &body_param, &headers_param, &info);

	zephir_get_strval(&body, body_param);
	zephir_get_strval(&headers, headers_param);
	if (!info) {
		info = &info_sub;
		ZEPHIR_INIT_VAR(info);
		array_init(info);
	}


	zephir_update_property_zval(this_ptr, SL("body"), &body);
	zephir_update_property_zval(this_ptr, SL("info"), info);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "parseheader", NULL, 0, &headers);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Parse a header string.
 *
 * @param  string $header
 *
 * @return void
 */
PHP_METHOD(PhalconPlus_Curl_Response, parseHeader) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *header_param = NULL, headers, _0;
	zval header;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &header_param);

	zephir_get_strval(&header, header_param);


	ZEPHIR_INIT_VAR(&headers);
	array_init(&headers);
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_trim(&_0, &header, NULL , ZEPHIR_TRIM_BOTH);
	ZEPHIR_INIT_NVAR(&headers);
	zephir_fast_explode_str(&headers, SL("\r\n"), &_0, LONG_MAX);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "parseheaders", NULL, 0, &headers);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Parse an array of headers.
 *
 * @param  array  $headers
 *
 * @return void
 */
PHP_METHOD(PhalconPlus_Curl_Response, parseHeaders) {

	zend_string *_9$$4;
	zend_ulong _8$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *headers_param = NULL, _0, firstHeader, _1, _2, _3, _4, code, status, parts, _5, key, header, headerCopy, *_10, _11, *_6$$4, _7$$4, delimiter$$9, _12$$9, key$$9, val$$9, _13$$9, _14$$9, _15$$9, _16$$9, _17$$9, _18$$9, _19$$12, _20$$12, _22$$14, _23$$14, delimiter$$16, _24$$16, key$$16, val$$16, _25$$16, _26$$16, _27$$16, _28$$16, _29$$16, _30$$16, _31$$19, _32$$19, _34$$21, _35$$21;
	zval headers, _21$$14, _33$$21;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_33$$21);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&firstHeader);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&headerCopy);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&delimiter$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&key$$9);
	ZVAL_UNDEF(&val$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&delimiter$$16);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&key$$16);
	ZVAL_UNDEF(&val$$16);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_29$$16);
	ZVAL_UNDEF(&_30$$16);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&_32$$19);
	ZVAL_UNDEF(&_34$$21);
	ZVAL_UNDEF(&_35$$21);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);

	zephir_get_arrval(&headers, headers_param);


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("headers"), &_0);
	ZEPHIR_MAKE_REF(&headers);
	ZEPHIR_CALL_FUNCTION(&firstHeader, "array_shift", NULL, 98, &headers);
	ZEPHIR_UNREF(&headers);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "/^HTTP\\/\\d(\\.\\d)? [0-9]{3}/");
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "/^HTTP\\/\\d(\\.\\d)? [0-9]{3}/");
	zephir_preg_match(&_3, &_4, &firstHeader, &_1, 0, 0 , 0 );
	if (!zephir_is_true(&_3)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_InvalidArgumentException, "Invalid response header", "phalconplus/Curl/Response.zep", 73);
		return;
	}
	ZEPHIR_INIT_VAR(&parts);
	zephir_fast_explode_str(&parts, SL(" "), &firstHeader, 2 );
	ZEPHIR_OBS_VAR(&status);
	zephir_array_fetch_long(&status, &parts, 1, PH_NOISY, "phalconplus/Curl/Response.zep", 78);
	ZEPHIR_INIT_VAR(&code);
	zephir_fast_explode_str(&code, SL(" "), &status, LONG_MAX);
	zephir_array_fetch_long(&_5, &code, 0, PH_NOISY | PH_READONLY, "phalconplus/Curl/Response.zep", 80);
	ZEPHIR_INIT_NVAR(&code);
	ZVAL_LONG(&code, zephir_get_intval(&_5));
	ZEPHIR_CPY_WRT(&headerCopy, &headers);
	if (ZEPHIR_IS_LONG_IDENTICAL(&code, 100)) {
		zephir_is_iterable(&headerCopy, 0, "phalconplus/Curl/Response.zep", 93);
		if (Z_TYPE_P(&headerCopy) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&headerCopy), _8$$4, _9$$4, _6$$4)
			{
				ZEPHIR_INIT_NVAR(&key);
				if (_9$$4 != NULL) { 
					ZVAL_STR_COPY(&key, _9$$4);
				} else {
					ZVAL_LONG(&key, _8$$4);
				}
				ZEPHIR_INIT_NVAR(&header);
				ZVAL_COPY(&header, _6$$4);
				if (zephir_is_true(&header)) {
					break;
				}
				zephir_array_unset(&headers, &key, PH_SEPARATE);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &headerCopy, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_7$$4, &headerCopy, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_7$$4)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&key, &headerCopy, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&header, &headerCopy, "current", NULL, 0);
				zephir_check_call_status();
					if (zephir_is_true(&header)) {
						break;
					}
					zephir_array_unset(&headers, &key, PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &headerCopy, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&header);
		ZEPHIR_INIT_NVAR(&key);
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "parseheaders", NULL, 99, &headers);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_update_property_zval(this_ptr, SL("statusText"), &status);
	zephir_update_property_zval(this_ptr, SL("statusCode"), &code);
	zephir_is_iterable(&headers, 0, "phalconplus/Curl/Response.zep", 120);
	if (Z_TYPE_P(&headers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&headers), _10)
		{
			ZEPHIR_INIT_NVAR(&header);
			ZVAL_COPY(&header, _10);
			if (!zephir_is_true(&header)) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_12$$9);
			ZVAL_STRING(&_12$$9, ":");
			ZEPHIR_INIT_NVAR(&delimiter$$9);
			zephir_fast_strpos(&delimiter$$9, &header, &_12$$9, 0 );
			if (!zephir_is_true(&delimiter$$9)) {
				continue;
			}
			ZEPHIR_INIT_NVAR(&_13$$9);
			ZVAL_LONG(&_14$$9, 0);
			ZEPHIR_INIT_NVAR(&_15$$9);
			zephir_substr(&_15$$9, &header, 0 , zephir_get_intval(&delimiter$$9), 0);
			zephir_fast_strtolower(&_13$$9, &_15$$9);
			ZEPHIR_INIT_NVAR(&key$$9);
			zephir_fast_trim(&key$$9, &_13$$9, NULL , ZEPHIR_TRIM_BOTH);
			ZVAL_LONG(&_16$$9, (zephir_get_numberval(&delimiter$$9) + 1));
			ZEPHIR_INIT_NVAR(&_17$$9);
			zephir_substr(&_17$$9, &header, zephir_get_intval(&_16$$9), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_INIT_NVAR(&val$$9);
			zephir_fast_trim(&val$$9, &_17$$9, NULL , ZEPHIR_TRIM_LEFT);
			zephir_read_property(&_18$$9, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
			if (zephir_array_isset(&_18$$9, &key$$9)) {
				zephir_read_property(&_19$$12, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
				zephir_array_fetch(&_20$$12, &_19$$12, &key$$9, PH_NOISY | PH_READONLY, "phalconplus/Curl/Response.zep", 111);
				if (Z_TYPE_P(&_20$$12) == IS_ARRAY) {
					zephir_update_property_array_multi(this_ptr, SL("headers"), &val$$9, SL("za"), 2, &key$$9);
				} else {
					ZEPHIR_INIT_NVAR(&_21$$14);
					zephir_create_array(&_21$$14, 2, 0);
					zephir_read_property(&_22$$14, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
					ZEPHIR_OBS_NVAR(&_23$$14);
					zephir_array_fetch(&_23$$14, &_22$$14, &key$$9, PH_NOISY, "phalconplus/Curl/Response.zep", 114);
					zephir_array_fast_append(&_21$$14, &_23$$14);
					zephir_array_fast_append(&_21$$14, &val$$9);
					zephir_update_property_array(this_ptr, SL("headers"), &key$$9, &_21$$14);
				}
			} else {
				zephir_update_property_array(this_ptr, SL("headers"), &key$$9, &val$$9);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &headers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_11, &headers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_11)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&header, &headers, "current", NULL, 0);
			zephir_check_call_status();
				if (!zephir_is_true(&header)) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_24$$16);
				ZVAL_STRING(&_24$$16, ":");
				ZEPHIR_INIT_NVAR(&delimiter$$16);
				zephir_fast_strpos(&delimiter$$16, &header, &_24$$16, 0 );
				if (!zephir_is_true(&delimiter$$16)) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_25$$16);
				ZVAL_LONG(&_26$$16, 0);
				ZEPHIR_INIT_NVAR(&_27$$16);
				zephir_substr(&_27$$16, &header, 0 , zephir_get_intval(&delimiter$$16), 0);
				zephir_fast_strtolower(&_25$$16, &_27$$16);
				ZEPHIR_INIT_NVAR(&key$$16);
				zephir_fast_trim(&key$$16, &_25$$16, NULL , ZEPHIR_TRIM_BOTH);
				ZVAL_LONG(&_28$$16, (zephir_get_numberval(&delimiter$$16) + 1));
				ZEPHIR_INIT_NVAR(&_29$$16);
				zephir_substr(&_29$$16, &header, zephir_get_intval(&_28$$16), 0, ZEPHIR_SUBSTR_NO_LENGTH);
				ZEPHIR_INIT_NVAR(&val$$16);
				zephir_fast_trim(&val$$16, &_29$$16, NULL , ZEPHIR_TRIM_LEFT);
				zephir_read_property(&_30$$16, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
				if (zephir_array_isset(&_30$$16, &key$$16)) {
					zephir_read_property(&_31$$19, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
					zephir_array_fetch(&_32$$19, &_31$$19, &key$$16, PH_NOISY | PH_READONLY, "phalconplus/Curl/Response.zep", 111);
					if (Z_TYPE_P(&_32$$19) == IS_ARRAY) {
						zephir_update_property_array_multi(this_ptr, SL("headers"), &val$$16, SL("za"), 2, &key$$16);
					} else {
						ZEPHIR_INIT_NVAR(&_33$$21);
						zephir_create_array(&_33$$21, 2, 0);
						zephir_read_property(&_34$$21, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
						ZEPHIR_OBS_NVAR(&_35$$21);
						zephir_array_fetch(&_35$$21, &_34$$21, &key$$16, PH_NOISY, "phalconplus/Curl/Response.zep", 114);
						zephir_array_fast_append(&_33$$21, &_35$$21);
						zephir_array_fast_append(&_33$$21, &val$$16);
						zephir_update_property_array(this_ptr, SL("headers"), &key$$16, &_33$$21);
					}
				} else {
					zephir_update_property_array(this_ptr, SL("headers"), &key$$16, &val$$16);
				}
			ZEPHIR_CALL_METHOD(NULL, &headers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&header);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get a specific header from the response.
 *
 * @param  string $key
 *
 * @return mixed
 */
PHP_METHOD(PhalconPlus_Curl_Response, getHeader) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key = NULL, key_sub, _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key);

	ZEPHIR_SEPARATE_PARAM(key);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, key);
	ZEPHIR_CPY_WRT(key, &_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, key)) {
		zephir_read_property(&_2, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, key, PH_NOISY, "phalconplus/Curl/Response.zep", 131);
	} else {
		ZVAL_NULL(&_0);
	}
	RETURN_CCTOR(&_0);

}

/**
 * Gets all the headers of the response.
 *
 * @return array
 */
PHP_METHOD(PhalconPlus_Curl_Response, getHeaders) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "headers");

}

/**
 * Convert the response instance to an array.
 *
 * @return array
 */
PHP_METHOD(PhalconPlus_Curl_Response, toArray) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 3, 0);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("headers"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("body"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("body"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("info"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("info"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

/**
 * Convert the response object to a JSON string.
 *
 * @return string
 */
PHP_METHOD(PhalconPlus_Curl_Response, toJson) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	zephir_json_encode(return_value, &_0, 0 );
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Curl_Response, jsonSerialize) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Convert the object to its string representation by returning the body.
 *
 * @return string
 */
PHP_METHOD(PhalconPlus_Curl_Response, __toString) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "body");

}

zend_object *zephir_init_properties_PhalconPlus_Curl_Response(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("info"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("info"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("headers"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

