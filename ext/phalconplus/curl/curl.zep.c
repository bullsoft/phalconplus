
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
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * @ref https://github.com/anlutro/php-curl
 */
ZEPHIR_INIT_CLASS(PhalconPlus_Curl_Curl) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Curl, Curl, phalconplus, curl_curl, phalconplus_curl_curl_method_entry, 0);

	/**
	 * The cURL resource.
	 */
	zend_declare_property_null(phalconplus_curl_curl_ce, SL("ch"), ZEND_ACC_PROTECTED);

	/**
	 * The default headers.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalconplus_curl_curl_ce, SL("defaultHeaders"), ZEND_ACC_PROTECTED);

	/**
	 * The default curl options.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalconplus_curl_curl_ce, SL("defaultOptions"), ZEND_ACC_PROTECTED);

	phalconplus_curl_curl_ce->create_object = zephir_init_properties_PhalconPlus_Curl_Curl;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Curl_Curl, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *opts_param = NULL;
	zval opts;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&opts);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &opts_param);

	if (!opts_param) {
		ZEPHIR_INIT_VAR(&opts);
		array_init(&opts);
	} else {
		zephir_get_arrval(&opts, opts_param);
	}


	zephir_update_property_zval(this_ptr, SL("defaultOptions"), &opts);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get allowed methods.
 *
 * @return array
 */
PHP_METHOD(PhalconPlus_Curl_Curl, getAllowedMethods) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_static_property_ce(&_0, phalconplus_curl_request_ce, SL("methods"), PH_NOISY_CC | PH_READONLY);
	RETURN_CTORW(&_0);

}

/**
 * Set the default headers for every request.
 *
 * @param array $headers
 */
PHP_METHOD(PhalconPlus_Curl_Curl, setDefaultHeaders) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *headers_param = NULL;
	zval headers;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&headers);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &headers_param);

	zephir_get_arrval(&headers, headers_param);


	zephir_update_property_zval(this_ptr, SL("defaultHeaders"), &headers);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the default headers.
 *
 * @return array
 */
PHP_METHOD(PhalconPlus_Curl_Curl, getDefaultHeaders) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "defaultHeaders");

}

/**
 * Set the default curl options for every request.
 *
 * @param array $options
 */
PHP_METHOD(PhalconPlus_Curl_Curl, setDefaultOptions) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *options_param = NULL, _0, _1;
	zval options;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &options_param);

	zephir_get_arrval(&options, options_param);


	zephir_read_property(&_0, this_ptr, SL("defaultOptions"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	zephir_add_function(&_1, &options, &_0);
	zephir_update_property_zval(this_ptr, SL("defaultOptions"), &_1);
	ZEPHIR_MM_RESTORE();

}

/**
 * Get the default options.
 *
 * @return array
 */
PHP_METHOD(PhalconPlus_Curl_Curl, getDefaultOptions) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "defaultOptions");

}

/**
 * Build an URL with an optional query string.
 *
 * @param  string $url   the base URL without any query string
 * @param  array  $query array of GET parameters
 *
 * @return string
 */
PHP_METHOD(PhalconPlus_Curl_Curl, buildUrl) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval query;
	zval *url_param = NULL, *query_param = NULL, retUrl, parts, queryString, _1, _8, _9, _2$$4, _3$$4, _5$$4, _6$$5, _7$$5, _10$$6, _11$$6, _12$$7, _13$$7, _14$$8;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&retUrl);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&queryString);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&query);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &url_param, &query_param);

	zephir_get_strval(&url, url_param);
	zephir_get_arrval(&query, query_param);


	if (ZEPHIR_IS_EMPTY(&query)) {
		RETURN_CTOR(&url);
	}
	ZEPHIR_CALL_FUNCTION(&parts, "parse_url", NULL, 72, &url);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&queryString);
	ZVAL_STRING(&queryString, "");
	_0 = zephir_array_isset_string(&parts, SL("query"));
	if (_0) {
		zephir_array_fetch_string(&_1, &parts, SL("query"), PH_NOISY | PH_READONLY, "phalconplus/Curl/Curl.zep", 95);
		_0 = zephir_is_true(&_1);
	}
	ZEPHIR_INIT_NVAR(&queryString);
	if (_0) {
		zephir_array_fetch_string(&_2$$4, &parts, SL("query"), PH_NOISY | PH_READONLY, "phalconplus/Curl/Curl.zep", 96);
		ZEPHIR_CALL_FUNCTION(&_3$$4, "http_build_query", &_4, 73, &query);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_5$$4);
		ZEPHIR_CONCAT_VVSV(&_5$$4, &queryString, &_2$$4, "&", &_3$$4);
		ZEPHIR_CPY_WRT(&queryString, &_5$$4);
	} else {
		ZEPHIR_CALL_FUNCTION(&_6$$5, "http_build_query", &_4, 73, &query);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_7$$5);
		ZEPHIR_CONCAT_VV(&_7$$5, &queryString, &_6$$5);
		ZEPHIR_CPY_WRT(&queryString, &_7$$5);
	}
	zephir_array_fetch_string(&_8, &parts, SL("scheme"), PH_NOISY | PH_READONLY, "phalconplus/Curl/Curl.zep", 101);
	zephir_array_fetch_string(&_9, &parts, SL("host"), PH_NOISY | PH_READONLY, "phalconplus/Curl/Curl.zep", 101);
	ZEPHIR_INIT_VAR(&retUrl);
	ZEPHIR_CONCAT_VSV(&retUrl, &_8, "://", &_9);
	if (zephir_array_isset_string(&parts, SL("port"))) {
		zephir_array_fetch_string(&_10$$6, &parts, SL("port"), PH_NOISY | PH_READONLY, "phalconplus/Curl/Curl.zep", 103);
		ZEPHIR_INIT_VAR(&_11$$6);
		ZEPHIR_CONCAT_VSV(&_11$$6, &retUrl, ":", &_10$$6);
		ZEPHIR_CPY_WRT(&retUrl, &_11$$6);
	}
	if (zephir_array_isset_string(&parts, SL("path"))) {
		zephir_array_fetch_string(&_12$$7, &parts, SL("path"), PH_NOISY | PH_READONLY, "phalconplus/Curl/Curl.zep", 106);
		ZEPHIR_INIT_VAR(&_13$$7);
		ZEPHIR_CONCAT_VV(&_13$$7, &retUrl, &_12$$7);
		ZEPHIR_CPY_WRT(&retUrl, &_13$$7);
	}
	if (zephir_is_true(&queryString)) {
		ZEPHIR_INIT_VAR(&_14$$8);
		ZEPHIR_CONCAT_VSV(&_14$$8, &retUrl, "?", &queryString);
		ZEPHIR_CPY_WRT(&retUrl, &_14$$8);
	}
	RETURN_CCTOR(&retUrl);

}

/**
 * Create a new response object and set its values.
 *
 * @param  string  $method    get, post, etc
 * @param  string  $url
 * @param  mixed   $data      POST data
 * @param  int     $encoding  Request::ENCODING_* constant specifying how to process the POST data
 *
 * @return Request
 */
PHP_METHOD(PhalconPlus_Curl_Curl, newRequest) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long encoding, ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *url_param = NULL, *data, data_sub, *encoding_param = NULL, request, _0, _2, _4, _1$$3, _3$$4;
	zval method, url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &method_param, &url_param, &data, &encoding_param);

	zephir_get_strval(&method, method_param);
	zephir_get_strval(&url, url_param);
	if (!encoding_param) {
		encoding = 0;
	} else {
		encoding = zephir_get_intval(encoding_param);
	}


	ZEPHIR_INIT_VAR(&request);
	object_init_ex(&request, phalconplus_curl_request_ce);
	ZEPHIR_CALL_METHOD(NULL, &request, "__construct", NULL, 74, this_ptr);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("defaultHeaders"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("defaultHeaders"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &request, "setheaders", NULL, 75, &_1$$3);
		zephir_check_call_status();
	}
	zephir_read_property(&_2, this_ptr, SL("defaultOptions"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_2)) {
		zephir_read_property(&_3$$4, this_ptr, SL("defaultOptions"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &request, "setoptions", NULL, 76, &_3$$4);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &request, "setmethod", NULL, 77, &method);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &request, "seturl", NULL, 78, &url);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &request, "setdata", NULL, 79, data);
	zephir_check_call_status();
	ZVAL_LONG(&_4, encoding);
	ZEPHIR_CALL_METHOD(NULL, &request, "setencoding", NULL, 80, &_4);
	zephir_check_call_status();
	RETURN_CCTOR(&request);

}

/**
 * Create a new JSON request and set its values.
 *
 * @param  string $method  get, post etc
 * @param  string $url
 * @param  mixed  $data    POST data
 *
 * @return Request
 */
PHP_METHOD(PhalconPlus_Curl_Curl, newJsonRequest) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval data;
	zval *method_param = NULL, *url_param = NULL, *data_param = NULL, _0;
	zval method, url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &method_param, &url_param, &data_param);

	zephir_get_strval(&method, method_param);
	zephir_get_strval(&url, url_param);
	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	ZVAL_LONG(&_0, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newrequest", NULL, 0, &method, &url, &data, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Create a new raw request and set its values.
 *
 * @param  string $method  get, post etc
 * @param  string $url
 * @param  mixed  $data    request body
 *
 * @return Request
 */
PHP_METHOD(PhalconPlus_Curl_Curl, newRawRequest) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *url_param = NULL, *data = NULL, data_sub, _0;
	zval method, url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &method_param, &url_param, &data);

	zephir_get_strval(&method, method_param);
	zephir_get_strval(&url, url_param);
	if (!data) {
		data = &data_sub;
		ZEPHIR_INIT_VAR(data);
		ZVAL_STRING(data, "");
	}


	ZVAL_LONG(&_0, 2);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newrequest", NULL, 0, &method, &url, data, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Prepare the curl resource for sending a request.
 *
 * @param  Request $request
 *
 * @return void
 */
PHP_METHOD(PhalconPlus_Curl_Curl, prepareRequest) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, __$true, _0, _1, _2, _4, auth, options, method, _7, _8, _10, _11, _12, _13, _14, _5$$3, _6$$3, _9$$4, _15$$5, _16$$5, _17$$5, _18$$6, _19$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&auth);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_15$$5);
	ZVAL_UNDEF(&_16$$5);
	ZVAL_UNDEF(&_17$$5);
	ZVAL_UNDEF(&_18$$6);
	ZVAL_UNDEF(&_19$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	ZEPHIR_CALL_FUNCTION(&_0, "curl_init", NULL, 81);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("ch"), &_0);
	zephir_read_property(&_1, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 19913);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 82, &_1, &_2, &__$true);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_4, 42);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 82, &_2, &_4, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&auth, request, "getuserandpass", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&auth)) {
		zephir_read_property(&_5$$3, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_6$$3, 10005);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 82, &_5$$3, &_6$$3, &auth);
		zephir_check_call_status();
	}
	zephir_read_property(&_4, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_7, request, "geturl", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_8, 10002);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 82, &_4, &_8, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&options, request, "getoptions", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&options))) {
		zephir_read_property(&_9$$4, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt_array", NULL, 83, &_9$$4, &options);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&method, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_8, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_10);
	zephir_fast_strtoupper(&_10, &method);
	ZVAL_LONG(&_11, 10036);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 82, &_8, &_11, &_10);
	zephir_check_call_status();
	zephir_read_property(&_11, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_12, request, "formatheaders", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_13, 10023);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 82, &_11, &_13, &_12);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_14, request, "hasdata", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_14)) {
		zephir_read_property(&_15$$5, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_16$$5, request, "encodedata", NULL, 0);
		zephir_check_call_status();
		ZVAL_LONG(&_17$$5, 10015);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 82, &_15$$5, &_17$$5, &_16$$5);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&method, "head")) {
		zephir_read_property(&_18$$6, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_19$$6, 44);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 82, &_18$$6, &_19$$6, &__$true);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Send a request.
 *
 * @param  Request $request
 *
 * @return Response
 */
PHP_METHOD(PhalconPlus_Curl_Curl, sendRequest) {

	zval _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, result, response, _0, _8, ex$$3, errno$$3, msg$$3, errmsg$$3, _1$$3, _2$$3, _3$$3, _6$$3, _7$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&ex$$3);
	ZVAL_UNDEF(&errno$$3);
	ZVAL_UNDEF(&msg$$3);
	ZVAL_UNDEF(&errmsg$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &request);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "preparerequest", NULL, 0, request);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&result, "curl_exec", NULL, 84, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&result)) {
		zephir_read_property(&_1$$3, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&errno$$3, "curl_errno", NULL, 85, &_1$$3);
		zephir_check_call_status();
		zephir_read_property(&_2$$3, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&errmsg$$3, "curl_error", NULL, 86, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&msg$$3);
		ZEPHIR_CONCAT_SVSV(&msg$$3, "Curl request failed with error [", &errno$$3, ":", &errmsg$$3);
		zephir_read_property(&_3$$3, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_close", &_4, 87, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&ex$$3);
		object_init_ex(&ex$$3, phalconplus_curl_exception_ce);
		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_create_array(&_5$$3, 3, 0);
		zephir_array_fast_append(&_5$$3, &msg$$3);
		ZEPHIR_INIT_VAR(&_6$$3);
		array_init(&_6$$3);
		zephir_array_fast_append(&_5$$3, &_6$$3);
		zephir_array_fast_append(&_5$$3, request);
		ZEPHIR_CALL_METHOD(NULL, &ex$$3, "__construct", NULL, 25, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$3, &ex$$3, "setcode", NULL, 88, &errno$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$3, "phalconplus/Curl/Curl.zep", 216);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&response, this_ptr, "createresponseobject", NULL, 0, &result);
	zephir_check_call_status();
	zephir_read_property(&_8, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", &_4, 87, &_8);
	zephir_check_call_status();
	RETURN_CCTOR(&response);

}

/**
 * Extract the response info, header and body from a cURL response. Saves
 * the data in variables stored on the object.
 *
 * @param  string $response
 *
 * @return Response
 */
PHP_METHOD(PhalconPlus_Curl_Curl, createResponseObject) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_1 = NULL;
	zval *response, response_sub, info, headerSize, headers, body, _0, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&headerSize);
	ZVAL_UNDEF(&headers);
	ZVAL_UNDEF(&body);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &response);



	zephir_read_property(&_0, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&info, "curl_getinfo", &_1, 89, &_0);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, 2097163);
	ZEPHIR_CALL_FUNCTION(&headerSize, "curl_getinfo", &_1, 89, &_2, &_3);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 0);
	ZEPHIR_INIT_VAR(&headers);
	zephir_substr(&headers, response, 0 , zephir_get_intval(&headerSize), 0);
	ZEPHIR_INIT_VAR(&body);
	zephir_substr(&body, response, zephir_get_intval(&headerSize), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	object_init_ex(return_value, phalconplus_curl_response_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 90, &body, &headers, &info);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Handle dynamic calls to the class.
 *
 * @param  string $func
 * @param  array  $args
 *
 * @return mixed
 */
PHP_METHOD(PhalconPlus_Curl_Curl, __call) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *func_param = NULL, *args_param = NULL, request, method, encoding, url, data, msg, _0, _1, _2, _3, _4, _5, _10, _6$$3, _7$$3, _8$$4, _9$$4, _11$$5, _12$$6;
	zval func;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&func);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&encoding);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&msg);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &func_param, &args_param);

	zephir_get_strval(&func, func_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_INIT_VAR(&data);
	ZVAL_NULL(&data);
	ZEPHIR_INIT_VAR(&method);
	zephir_fast_strtolower(&method, &func);
	ZEPHIR_INIT_VAR(&encoding);
	ZVAL_LONG(&encoding, 0);
	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 4);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &method, 0 , 4 , 0);
	ZVAL_LONG(&_3, 0);
	ZVAL_LONG(&_4, 3);
	ZEPHIR_INIT_VAR(&_5);
	zephir_substr(&_5, &method, 0 , 3 , 0);
	if (ZEPHIR_IS_STRING_IDENTICAL(&_2, "json")) {
		ZEPHIR_INIT_NVAR(&encoding);
		ZVAL_LONG(&encoding, 1);
		ZVAL_LONG(&_6$$3, 4);
		ZEPHIR_INIT_VAR(&_7$$3);
		zephir_substr(&_7$$3, &method, 4 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CPY_WRT(&method, &_7$$3);
	} else if (ZEPHIR_IS_STRING_IDENTICAL(&_5, "raw")) {
		ZEPHIR_INIT_NVAR(&encoding);
		ZVAL_LONG(&encoding, 2);
		ZVAL_LONG(&_8$$4, 3);
		ZEPHIR_INIT_VAR(&_9$$4);
		zephir_substr(&_9$$4, &method, 3 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		ZEPHIR_CPY_WRT(&method, &_9$$4);
	}
	zephir_read_static_property_ce(&_10, phalconplus_curl_request_ce, SL("methods"), PH_NOISY_CC | PH_READONLY);
	if (!(zephir_array_key_exists(&_10, &method))) {
		ZEPHIR_INIT_VAR(&msg);
		ZEPHIR_CONCAT_SVS(&msg, "Method [", &method, "] not a valid HTTP method.");
		ZEPHIR_INIT_VAR(&_11$$5);
		object_init_ex(&_11$$5, spl_ce_BadMethodCallException);
		ZEPHIR_CALL_METHOD(NULL, &_11$$5, "__construct", NULL, 91, &msg);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$5, "phalconplus/Curl/Curl.zep", 261);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(zephir_array_isset_long(&args, 0))) {
		ZEPHIR_INIT_NVAR(&msg);
		ZEPHIR_CONCAT_SVSSSV(&msg, "Missing argument 1 (", &url, ") for ", "PhalconPlus\\Curl\\Curl", "::", &func);
		ZEPHIR_INIT_VAR(&_12$$6);
		object_init_ex(&_12$$6, spl_ce_BadMethodCallException);
		ZEPHIR_CALL_METHOD(NULL, &_12$$6, "__construct", NULL, 91, &msg);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_12$$6, "phalconplus/Curl/Curl.zep", 265);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&url);
	zephir_array_fetch_long(&url, &args, 0, PH_NOISY, "phalconplus/Curl/Curl.zep", 267);
	if (zephir_array_isset_long(&args, 1)) {
		ZEPHIR_OBS_NVAR(&data);
		zephir_array_fetch_long(&data, &args, 1, PH_NOISY, "phalconplus/Curl/Curl.zep", 269);
	}
	ZEPHIR_CALL_METHOD(&request, this_ptr, "newrequest", NULL, 0, &method, &url, &data, &encoding);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "sendrequest", NULL, 0, &request);
	zephir_check_call_status();
	RETURN_MM();

}

zend_object *zephir_init_properties_PhalconPlus_Curl_Curl(zend_class_entry *class_type TSRMLS_DC) {

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
		zephir_read_property(&_0, this_ptr, SL("defaultOptions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("defaultOptions"), &_1$$3);
		}
		zephir_read_property(&_2, this_ptr, SL("defaultHeaders"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval(this_ptr, SL("defaultHeaders"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

