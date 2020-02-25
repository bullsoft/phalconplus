
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
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Curl_Request) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Curl, Request, phalconplus, curl_request, phalconplus_curl_request_method_entry, 0);

	/**
	 * Allowed methods => allows postdata
	 *
	 * @var array
	 */
	zend_declare_property_null(phalconplus_curl_request_ce, SL("methods"), ZEND_ACC_PUBLIC|ZEND_ACC_STATIC);

	/**
	 * The URL the request is sent to.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalconplus_curl_request_ce, SL("url"), "", ZEND_ACC_PRIVATE);

	/**
	 * The headers sent with the request.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalconplus_curl_request_ce, SL("headers"), ZEND_ACC_PRIVATE);

	/**
	 * The cookies sent with the request.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalconplus_curl_request_ce, SL("cookies"), ZEND_ACC_PRIVATE);

	/**
	 * POST data sent with the request.
	 *
	 * @var mixed
	 */
	zend_declare_property_null(phalconplus_curl_request_ce, SL("data"), ZEND_ACC_PRIVATE);

	/**
	 * Optional cURL options.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalconplus_curl_request_ce, SL("options"), ZEND_ACC_PRIVATE);

	/**
	 * Username to authenticate the request of cURL.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalconplus_curl_request_ce, SL("user"), "", ZEND_ACC_PRIVATE);

	/**
	 * Password to authenticate the request of cURL.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalconplus_curl_request_ce, SL("pass"), "", ZEND_ACC_PRIVATE);

	/**
	 * The type of processing to perform to encode the POST data
	 *
	 * @var int
	 */
	zend_declare_property_long(phalconplus_curl_request_ce, SL("encoding"), 0, ZEND_ACC_PRIVATE);

	zend_declare_property_string(phalconplus_curl_request_ce, SL("method"), "", ZEND_ACC_PRIVATE);

	/**
	 * Curl client
	 *
	 * @var <Curl>    
	 */
	zend_declare_property_null(phalconplus_curl_request_ce, SL("curl"), ZEND_ACC_PRIVATE);

	phalconplus_curl_request_ce->create_object = zephir_init_properties_PhalconPlus_Curl_Request;
	/**
	 * ENCODING_* constants, 
	 * used for specifying encoding options
	 */
	zephir_declare_class_constant_long(phalconplus_curl_request_ce, SL("ENCODING_QUERY"), 0);

	zephir_declare_class_constant_long(phalconplus_curl_request_ce, SL("ENCODING_JSON"), 1);

	zephir_declare_class_constant_long(phalconplus_curl_request_ce, SL("ENCODING_RAW"), 2);

	return SUCCESS;

}

/**
 * Constructor
 *
 */
PHP_METHOD(PhalconPlus_Curl_Request, __construct) {

	zval *curl, curl_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&curl_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &curl);



	zephir_update_property_zval(this_ptr, SL("curl"), curl);

}

/**
 * Set the HTTP method of the request.
 *
 */
PHP_METHOD(PhalconPlus_Curl_Request, setMethod) {

	zend_bool _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, _0, _1, _4, _6, _7, _2$$3;
	zval method, _3$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_2$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &method_param);

	zephir_get_strval(&method, method_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &method);
	zephir_get_strval(&method, &_0);
	zephir_read_static_property_ce(&_1, phalconplus_curl_request_ce, SL("methods"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&_1, &method))) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZEPHIR_CONCAT_SVS(&_3$$3, "Method [", &method, " not a valid HTTP method.");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 17, &_3$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalconplus/Curl/Request.zep", 107);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	_5 = zephir_is_true(&_4);
	if (_5) {
		zephir_read_static_property_ce(&_6, phalconplus_curl_request_ce, SL("methods"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_7, &_6, &method, PH_NOISY | PH_READONLY, "phalconplus/Curl/Request.zep", 109);
		_5 = !zephir_is_true(&_7);
	}
	if (_5) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(spl_ce_LogicException, "Request has POST data, but tried changing HTTP method to one that does not allow POST data", "phalconplus/Curl/Request.zep", 110);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("method"), &method);
	RETURN_THIS();

}

/**
 * Get the HTTP method of the request.
 *
 * @return string
 */
PHP_METHOD(PhalconPlus_Curl_Request, getMethod) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "method");

}

/**
 * Set the URL of the request.
 *
 * @param string $url
 */
PHP_METHOD(PhalconPlus_Curl_Request, setUrl) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *url_param = NULL;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &url_param);

	zephir_get_strval(&url, url_param);


	zephir_update_property_zval(this_ptr, SL("url"), &url);
	RETURN_THIS();

}

/**
 * Get the URL of the request.
 *
 * @return string
 */
PHP_METHOD(PhalconPlus_Curl_Request, getUrl) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "url");

}

/**
 * Set a specific header to be sent with the request.
 *
 * @param string $key   Can also be a string in "foo: bar" format
 * @param mixed  $value
 * @param boolean  $preserveCase
 */
PHP_METHOD(PhalconPlus_Curl_Request, setHeader) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool preserveCase;
	zval *key = NULL, key_sub, *value = NULL, value_sub, *preserveCase_param = NULL, __$null, parts$$3, _0$$4, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&parts$$3);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 2, &key, &value, &preserveCase_param);

	ZEPHIR_SEPARATE_PARAM(key);
	if (!value) {
		value = &value_sub;
		ZEPHIR_CPY_WRT(value, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(value);
	}
	if (!preserveCase_param) {
		preserveCase = 0;
	} else {
		preserveCase = zephir_get_boolval(preserveCase_param);
	}


	if (Z_TYPE_P(value) == IS_NULL) {
		ZEPHIR_INIT_VAR(&parts$$3);
		zephir_fast_explode_str(&parts$$3, SL(":"), value, 2 );
		ZEPHIR_OBS_NVAR(key);
		zephir_array_fetch_long(key, &parts$$3, 0, PH_NOISY, "phalconplus/Curl/Request.zep", 154);
		ZEPHIR_OBS_NVAR(value);
		zephir_array_fetch_long(value, &parts$$3, 1, PH_NOISY, "phalconplus/Curl/Request.zep", 155);
	}
	if (!preserveCase) {
		ZEPHIR_INIT_VAR(&_0$$4);
		zephir_fast_strtolower(&_0$$4, key);
		ZEPHIR_CPY_WRT(key, &_0$$4);
	}
	ZEPHIR_INIT_VAR(&_1);
	zephir_fast_trim(&_1, key, NULL , ZEPHIR_TRIM_BOTH);
	ZEPHIR_CPY_WRT(key, &_1);
	ZEPHIR_INIT_NVAR(&_1);
	zephir_fast_trim(&_1, value, NULL , ZEPHIR_TRIM_BOTH);
	zephir_update_property_array(this_ptr, SL("headers"), key, &_1);
	RETURN_THIS();

}

/**
 * Set the headers to be sent with the request.
 *
 * Pass an associative array - e.g. ['Content-Type' => 'application/json']
 * and the correct header formatting - e.g. 'Content-Type: application/json'
 * will be done for you when the request is sent.
 *
 * @param array $headers
 */
PHP_METHOD(PhalconPlus_Curl_Request, setHeaders) {

	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *headers_param = NULL, _0, key, val, *_1, _2;
	zval headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);

	zephir_get_arrval(&headers, headers_param);


	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, SL("headers"), &_0);
	zephir_is_iterable(&headers, 0, "phalconplus/Curl/Request.zep", 181);
	if (Z_TYPE_P(&headers) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&headers), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _1);
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", &_5, 0, &key, &val);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &headers, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &headers, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &headers, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&val, &headers, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", &_5, 0, &key, &val);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &headers, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_THIS();

}

/**
 * Get a specific header from the request.
 *
 * @param  string $key
 *
 * @return mixed
 */
PHP_METHOD(PhalconPlus_Curl_Request, getHeader) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _0, _1, _2, _3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_strtolower(&_0, &key);
	zephir_get_strval(&key, &_0);
	ZEPHIR_INIT_VAR(&_1);
	zephir_read_property(&_2, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_2, &key)) {
		zephir_read_property(&_3, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_1, &_3, &key, PH_NOISY, "phalconplus/Curl/Request.zep", 193);
	} else {
		ZVAL_NULL(&_1);
	}
	RETURN_CCTOR(&_1);

}

/**
 * Get the headers to be sent with the request.
 *
 * @return array
 */
PHP_METHOD(PhalconPlus_Curl_Request, getHeaders) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "headers");

}

/**
 * Set a cookie.
 *
 * @param string $key
 * @param string $value
 */
PHP_METHOD(PhalconPlus_Curl_Request, setCookie) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value_param = NULL;
	zval key, value;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value_param);

	zephir_get_strval(&key, key_param);
	zephir_get_strval(&value, value_param);


	zephir_update_property_array(this_ptr, SL("cookies"), &key, &value);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "updatecookieheader", NULL, 94);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Replace the request's cookies.
 *
 * @param array $cookies
 */
PHP_METHOD(PhalconPlus_Curl_Request, setCookies) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *cookies_param = NULL;
	zval cookies;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&cookies);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &cookies_param);

	zephir_get_arrval(&cookies, cookies_param);


	zephir_update_property_zval(this_ptr, SL("cookies"), &cookies);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "updatecookieheader", NULL, 94);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Read the request cookies and set the cookie header.
 *
 * @return void
 */
PHP_METHOD(PhalconPlus_Curl_Request, updateCookieHeader) {

	zend_string *_4;
	zend_ulong _3;
	zval strings, key, val, _0, *_1, _2, _7, _8, _5$$3, _6$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&strings);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&strings);
	array_init(&strings);
	zephir_read_property(&_0, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalconplus/Curl/Request.zep", 238);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _1);
			ZEPHIR_INIT_NVAR(&_5$$3);
			ZEPHIR_CONCAT_VSV(&_5$$3, &key, "=", &val);
			zephir_array_append(&strings, &_5$$3, PH_SEPARATE, "phalconplus/Curl/Request.zep", 236);
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
			ZEPHIR_CALL_METHOD(&key, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&val, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_6$$4);
				ZEPHIR_CONCAT_VSV(&_6$$4, &key, "=", &val);
				zephir_array_append(&strings, &_6$$4, PH_SEPARATE, "phalconplus/Curl/Request.zep", 236);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&_7);
	zephir_fast_join_str(&_7, SL("; "), &strings);
	ZEPHIR_INIT_VAR(&_8);
	ZVAL_STRING(&_8, "cookie");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_8, &_7);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Get a specific cookie from the request.
 *
 * @param  string $key
 *
 * @return string|null
 */
PHP_METHOD(PhalconPlus_Curl_Request, getCookie) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &key)) {
		zephir_read_property(&_2, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, &key, PH_NOISY, "phalconplus/Curl/Request.zep", 249);
	} else {
		ZVAL_NULL(&_0);
	}
	RETURN_CCTOR(&_0);

}

/**
 * Get all the request's cookies.
 *
 * @return string[]
 */
PHP_METHOD(PhalconPlus_Curl_Request, getCookies) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "cookies");

}

/**
 * Format the headers to an array of 'key: val' which can be passed to
 * curl_setopt.
 *
 * @return array
 */
PHP_METHOD(PhalconPlus_Curl_Request, formatHeaders) {

	zend_string *_4;
	zend_ulong _3;
	zval headers, key, val, _0, *_1, _2, _5$$4, _6$$7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$7);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&headers);
	array_init(&headers);
	zephir_read_property(&_0, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalconplus/Curl/Request.zep", 276);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&key, _4);
			} else {
				ZVAL_LONG(&key, _3);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _1);
			if (Z_TYPE_P(&key) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZEPHIR_CONCAT_VSV(&_5$$4, &key, ": ", &val);
				zephir_array_append(&headers, &_5$$4, PH_SEPARATE, "phalconplus/Curl/Request.zep", 271);
			} else {
				zephir_array_append(&headers, &val, PH_SEPARATE, "phalconplus/Curl/Request.zep", 273);
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
			ZEPHIR_CALL_METHOD(&key, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&val, &_0, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&key) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_6$$7);
					ZEPHIR_CONCAT_VSV(&_6$$7, &key, ": ", &val);
					zephir_array_append(&headers, &_6$$7, PH_SEPARATE, "phalconplus/Curl/Request.zep", 271);
				} else {
					zephir_array_append(&headers, &val, PH_SEPARATE, "phalconplus/Curl/Request.zep", 273);
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&headers);

}

/**
 * Set the POST data to be sent with the request.
 *
 * @param mixed $data
 */
PHP_METHOD(PhalconPlus_Curl_Request, setData) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data, data_sub, _1, _2, _3, _4$$3, _5$$3, _6$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	_0 = zephir_is_true(data);
	if (_0) {
		zephir_read_static_property_ce(&_1, phalconplus_curl_request_ce, SL("methods"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&_3);
		zephir_read_property(&_3, this_ptr, SL("method"), PH_NOISY_CC);
		zephir_array_fetch(&_2, &_1, &_3, PH_NOISY | PH_READONLY, "phalconplus/Curl/Request.zep", 285);
		_0 = !zephir_is_true(&_2);
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_4$$3);
		object_init_ex(&_4$$3, spl_ce_InvalidArgumentException);
		zephir_read_property(&_5$$3, this_ptr, SL("method"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_6$$3);
		ZEPHIR_CONCAT_SVS(&_6$$3, "HTTP method [", &_5$$3, "] does not allow POST data.");
		ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", NULL, 17, &_6$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_4$$3, "phalconplus/Curl/Request.zep", 286);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, SL("data"), data);
	RETURN_THIS();

}

/**
 * Check whether the request has any data.
 *
 * @return boolean
 */
PHP_METHOD(PhalconPlus_Curl_Request, hasData) {

	zend_bool _3;
	zval _0, _1, _2, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();

	zephir_read_static_property_ce(&_0, phalconplus_curl_request_ce, SL("methods"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_OBS_VAR(&_2);
	zephir_read_property(&_2, this_ptr, SL("method"), PH_NOISY_CC);
	zephir_array_fetch(&_1, &_0, &_2, PH_NOISY | PH_READONLY, "phalconplus/Curl/Request.zep", 298);
	_3 = zephir_is_true(&_1);
	if (_3) {
		ZEPHIR_CALL_METHOD(&_4, this_ptr, "encodedata", NULL, 0);
		zephir_check_call_status();
		_3 = zephir_get_boolval(&_4);
	}
	RETURN_MM_BOOL(_3);

}

/**
 * Get the POST data to be sent with the request.
 *
 * @return mixed
 */
PHP_METHOD(PhalconPlus_Curl_Request, getData) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "data");

}

/**
 * Set the encoding to use on the POST data, and (possibly) associated Content-Type headers
 *
 * @param int  $encoding  a Request::ENCODING_* constant
 */
PHP_METHOD(PhalconPlus_Curl_Request, setEncoding) {

	zval _4$$3;
	zend_bool _0, _1, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *encoding_param = NULL, _6, _7, _10, _2$$3, _3$$3, _8$$4, _9$$4;
	zend_long encoding, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_4$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &encoding_param);

	encoding = zephir_get_intval(encoding_param);


	_0 = encoding != 0;
	if (_0) {
		_0 = encoding != 1;
	}
	_1 = _0;
	if (_1) {
		_1 = encoding != 2;
	}
	if (_1) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, spl_ce_InvalidArgumentException);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_LONG(&_3$$3, encoding);
		ZEPHIR_INIT_VAR(&_4$$3);
		ZEPHIR_CONCAT_SVS(&_4$$3, "Encoding [", &_3$$3, "] not a known Request::ENCODING_* constant");
		ZEPHIR_CALL_METHOD(NULL, &_2$$3, "__construct", NULL, 17, &_4$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalconplus/Curl/Request.zep", 321);
		ZEPHIR_MM_RESTORE();
		return;
	}
	_5 = encoding == 1;
	if (_5) {
		ZEPHIR_INIT_VAR(&_7);
		ZVAL_STRING(&_7, "Content-Type");
		ZEPHIR_CALL_METHOD(&_6, this_ptr, "getheader", NULL, 0, &_7);
		zephir_check_call_status();
		_5 = !zephir_is_true(&_6);
	}
	if (_5) {
		ZEPHIR_INIT_VAR(&_8$$4);
		ZVAL_STRING(&_8$$4, "Content-Type");
		ZEPHIR_INIT_VAR(&_9$$4);
		ZVAL_STRING(&_9$$4, "application/json");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setheader", NULL, 0, &_8$$4, &_9$$4);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_ZVAL_NREF(_10);
	ZVAL_LONG(&_10, encoding);
	zephir_update_property_zval(this_ptr, SL("encoding"), &_10);
	RETURN_THIS();

}

/**
 * Get the current encoding which will be used on the POST data
 *
 * @return int  a Request::ENCODING_* constant
 */
PHP_METHOD(PhalconPlus_Curl_Request, getEncoding) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "encoding");

}

/**
 * Encode the POST data as a string.
 *
 * @return string
 */
PHP_METHOD(PhalconPlus_Curl_Request, encodeData) {

	zval msg, _0, _1$$3, _2$$4, _3$$4, _4$$4, _5$$6, _6$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&msg);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&msg);
	ZVAL_STRING(&msg, "");
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("encoding"), PH_NOISY_CC);
	do {
		if (ZEPHIR_IS_LONG(&_0, 1)) {
			zephir_read_property(&_1$$3, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
			zephir_json_encode(return_value, &_1$$3, 0 );
			RETURN_MM();
		}
		if (ZEPHIR_IS_LONG(&_0, 0)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			zephir_read_property(&_3$$4, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
			if (!(Z_TYPE_P(&_3$$4) == IS_NULL)) {
				zephir_read_property(&_4$$4, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_FUNCTION(&_2$$4, "http_build_query", NULL, 75, &_4$$4);
				zephir_check_call_status();
			} else {
				ZVAL_STRING(&_2$$4, "");
			}
			RETURN_CCTOR(&_2$$4);
		}
		if (ZEPHIR_IS_LONG(&_0, 2)) {
			RETURN_MM_MEMBER(getThis(), "data");
		}
		zephir_read_property(&_5$$6, this_ptr, SL("encoding"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&msg);
		ZEPHIR_CONCAT_SVS(&msg, "Encoding [", &_5$$6, "] not a known Request::ENCODING_* constant");
		ZEPHIR_INIT_VAR(&_6$$6);
		object_init_ex(&_6$$6, spl_ce_UnexpectedValueException);
		ZEPHIR_CALL_METHOD(NULL, &_6$$6, "__construct", NULL, 95, &msg);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_6$$6, "phalconplus/Curl/Request.zep", 355);
		ZEPHIR_MM_RESTORE();
		return;
	} while(0);

	ZEPHIR_MM_RESTORE();

}

/**
 * Set a specific curl option for the request.
 *
 * @param string $key
 * @param mixed  $value
 */
PHP_METHOD(PhalconPlus_Curl_Request, setOption) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *value, value_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &value);

	zephir_get_strval(&key, key_param);


	zephir_update_property_array(this_ptr, SL("options"), &key, value);
	RETURN_THIS();

}

/**
 * Set the cURL options for the request.
 *
 * @param array $options
 */
PHP_METHOD(PhalconPlus_Curl_Request, setOptions) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(&options, options_param);


	zephir_update_property_zval(this_ptr, SL("options"), &options);
	RETURN_THIS();

}

/**
 * Get a specific curl option from the request.
 *
 * @param  string $key
 *
 * @return mixed
 */
PHP_METHOD(PhalconPlus_Curl_Request, getOption) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	zephir_get_strval(&key, key_param);


	ZEPHIR_INIT_VAR(&_0);
	zephir_read_property(&_1, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_1, &key)) {
		zephir_read_property(&_2, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_0, &_2, &key, PH_NOISY, "phalconplus/Curl/Request.zep", 388);
	} else {
		ZVAL_NULL(&_0);
	}
	RETURN_CCTOR(&_0);

}

/**
 * Get the cURL options for the request.
 *
 * @return array
 */
PHP_METHOD(PhalconPlus_Curl_Request, getOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "options");

}

/**
 * Set the HTTP basic username and password.
 *
 * @param  string $user
 * @param  string $pass
 *
 * @return string
 */
PHP_METHOD(PhalconPlus_Curl_Request, auth) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *user_param = NULL, *pass_param = NULL;
	zval user, pass;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user);
	ZVAL_UNDEF(&pass);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &user_param, &pass_param);

	zephir_get_strval(&user, user_param);
	zephir_get_strval(&pass, pass_param);


	zephir_update_property_zval(this_ptr, SL("user"), &user);
	zephir_update_property_zval(this_ptr, SL("pass"), &pass);
	RETURN_THIS();

}

/**
 * Set an username to authenticate the request of curl.
 *
 * @param  string $user
 *
 * @return static
 */
PHP_METHOD(PhalconPlus_Curl_Request, setUser) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *user_param = NULL;
	zval user;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &user_param);

	zephir_get_strval(&user, user_param);


	zephir_update_property_zval(this_ptr, SL("user"), &user);
	RETURN_THIS();

}

/**
 * Set a password to authenticate the request of curl.
 *
 * @param  string $pass
 *
 * @return static
 */
PHP_METHOD(PhalconPlus_Curl_Request, setPass) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *pass_param = NULL;
	zval pass;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pass);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &pass_param);

	zephir_get_strval(&pass, pass_param);


	zephir_update_property_zval(this_ptr, SL("pass"), &pass);
	RETURN_THIS();

}

/**
 * If username and password is set, returns a string of 'username:password'.
 * If not, returns null.
 *
 * @return string|null
 */
PHP_METHOD(PhalconPlus_Curl_Request, getUserAndPass) {

	zval _0, _1$$3, _2$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);


	zephir_read_property(&_0, this_ptr, SL("user"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("user"), PH_NOISY_CC | PH_READONLY);
		zephir_read_property(&_2$$3, this_ptr, SL("pass"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CONCAT_VSV(return_value, &_1$$3, ":", &_2$$3);
		return;
	}
	RETURN_NULL();

}

/**
 * Whether the request is JSON or not.
 *
 * @return boolean
 */
PHP_METHOD(PhalconPlus_Curl_Request, isJson) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("encoding"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_IS_LONG_IDENTICAL(&_0, 1));

}

/**
 * Send the request.
 *
 * @return Response
 */
PHP_METHOD(PhalconPlus_Curl_Request, send) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("curl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "sendrequest", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();

}

void zephir_init_static_properties_PhalconPlus_Curl_Request(TSRMLS_D) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$false, __$true;
		ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 7, 0);
	zephir_array_update_string(&_0, SL("get"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("head"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("post"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("put"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("patch"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("delete"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("options"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_update_static_property_ce(phalconplus_curl_request_ce, ZEND_STRL("methods"), &_0);
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_PhalconPlus_Curl_Request(zend_class_entry *class_type TSRMLS_DC) {

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
		zephir_read_property(&_0, this_ptr, SL("options"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("options"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("data"), &_3$$4);
		}
		zephir_read_property(&_4, this_ptr, SL("cookies"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_4) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_5$$5);
			array_init(&_5$$5);
			zephir_update_property_zval(this_ptr, SL("cookies"), &_5$$5);
		}
		zephir_read_property(&_6, this_ptr, SL("headers"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_6) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_7$$6);
			array_init(&_7$$6);
			zephir_update_property_zval(this_ptr, SL("headers"), &_7$$6);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

