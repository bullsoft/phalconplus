
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
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/array.h"
#include "kernel/string.h"
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

	/**
	 * The base url
	 *
	 * @var string
	 */
	zend_declare_property_string(phalconplus_curl_curl_ce, SL("baseUrl"), "", ZEND_ACC_PROTECTED);

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
	RETURN_THIS();

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
	RETURN_THIS();

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
 * Get the default options.
 *
 * @return array
 */
PHP_METHOD(PhalconPlus_Curl_Curl, setBaseUrl) {

	zend_bool _3;
	zend_class_entry *_1, *_5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *baseUrl_param = NULL, _0, _2, _4;
	zval baseUrl;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&baseUrl);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &baseUrl_param);

	zephir_get_strval(&baseUrl, baseUrl_param);


	_1 = zephir_fetch_class_str_ex(SL("Phalcon\\Text"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "http://");
	ZEPHIR_CALL_CE_STATIC(&_0, _1, "startswith", NULL, 0, &baseUrl, &_2);
	zephir_check_call_status();
	_3 = zephir_is_true(&_0);
	if (!(_3)) {
		_5 = zephir_fetch_class_str_ex(SL("Phalcon\\Text"), ZEND_FETCH_CLASS_AUTO);
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_STRING(&_2, "https://");
		ZEPHIR_CALL_CE_STATIC(&_4, _5, "startswith", NULL, 0, &baseUrl, &_2);
		zephir_check_call_status();
		_3 = zephir_is_true(&_4);
	}
	if (_3) {
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_curl_exception_ce, "Base Url should start with http:// or https://", "phalconplus/Curl/Curl.zep", 100);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("baseUrl"), &baseUrl);
	RETURN_THIS();

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

	zend_bool _3, _8;
	zend_class_entry *_1, *_5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_12 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval query;
	zval *url_param = NULL, *query_param = NULL, _0, _2, _4, retUrl, parts, queryString, _9, _16, _17, _6$$3, _7$$3, _10$$5, _11$$5, _13$$5, _14$$6, _15$$6, _18$$7, _19$$7, _20$$8, _21$$8, _22$$9;
	zval url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&retUrl);
	ZVAL_UNDEF(&parts);
	ZVAL_UNDEF(&queryString);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$7);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&query);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &url_param, &query_param);

	zephir_get_strval(&url, url_param);
	zephir_get_arrval(&query, query_param);


	_1 = zephir_fetch_class_str_ex(SL("Phalcon\\Text"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "http://");
	ZEPHIR_CALL_CE_STATIC(&_0, _1, "startswith", NULL, 0, &url, &_2);
	zephir_check_call_status();
	_3 = zephir_is_true(&_0);
	if (!(_3)) {
		_5 = zephir_fetch_class_str_ex(SL("Phalcon\\Text"), ZEND_FETCH_CLASS_AUTO);
		ZEPHIR_INIT_NVAR(&_2);
		ZVAL_STRING(&_2, "https://");
		ZEPHIR_CALL_CE_STATIC(&_4, _5, "startswith", NULL, 0, &url, &_2);
		zephir_check_call_status();
		_3 = zephir_is_true(&_4);
	}
	if (_3) {
	} else {
		zephir_read_property(&_6$$3, this_ptr, SL("baseUrl"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_7$$3);
		ZEPHIR_CONCAT_VV(&_7$$3, &_6$$3, &url);
		zephir_get_strval(&url, &_7$$3);
	}
	if (ZEPHIR_IS_EMPTY(&query)) {
		RETURN_CTOR(&url);
	}
	ZEPHIR_CALL_FUNCTION(&parts, "parse_url", NULL, 84, &url);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&queryString);
	ZVAL_STRING(&queryString, "");
	_8 = zephir_array_isset_string(&parts, SL("query"));
	if (_8) {
		zephir_array_fetch_string(&_9, &parts, SL("query"), PH_NOISY | PH_READONLY, "phalconplus/Curl/Curl.zep", 128);
		_8 = zephir_is_true(&_9);
	}
	ZEPHIR_INIT_NVAR(&queryString);
	if (_8) {
		zephir_array_fetch_string(&_10$$5, &parts, SL("query"), PH_NOISY | PH_READONLY, "phalconplus/Curl/Curl.zep", 129);
		ZEPHIR_CALL_FUNCTION(&_11$$5, "http_build_query", &_12, 85, &query);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_13$$5);
		ZEPHIR_CONCAT_VVSV(&_13$$5, &queryString, &_10$$5, "&", &_11$$5);
		ZEPHIR_CPY_WRT(&queryString, &_13$$5);
	} else {
		ZEPHIR_CALL_FUNCTION(&_14$$6, "http_build_query", &_12, 85, &query);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_15$$6);
		ZEPHIR_CONCAT_VV(&_15$$6, &queryString, &_14$$6);
		ZEPHIR_CPY_WRT(&queryString, &_15$$6);
	}
	zephir_array_fetch_string(&_16, &parts, SL("scheme"), PH_NOISY | PH_READONLY, "phalconplus/Curl/Curl.zep", 134);
	zephir_array_fetch_string(&_17, &parts, SL("host"), PH_NOISY | PH_READONLY, "phalconplus/Curl/Curl.zep", 134);
	ZEPHIR_INIT_VAR(&retUrl);
	ZEPHIR_CONCAT_VSV(&retUrl, &_16, "://", &_17);
	if (zephir_array_isset_string(&parts, SL("port"))) {
		zephir_array_fetch_string(&_18$$7, &parts, SL("port"), PH_NOISY | PH_READONLY, "phalconplus/Curl/Curl.zep", 136);
		ZEPHIR_INIT_VAR(&_19$$7);
		ZEPHIR_CONCAT_VSV(&_19$$7, &retUrl, ":", &_18$$7);
		ZEPHIR_CPY_WRT(&retUrl, &_19$$7);
	}
	if (zephir_array_isset_string(&parts, SL("path"))) {
		zephir_array_fetch_string(&_20$$8, &parts, SL("path"), PH_NOISY | PH_READONLY, "phalconplus/Curl/Curl.zep", 139);
		ZEPHIR_INIT_VAR(&_21$$8);
		ZEPHIR_CONCAT_VV(&_21$$8, &retUrl, &_20$$8);
		ZEPHIR_CPY_WRT(&retUrl, &_21$$8);
	}
	if (zephir_is_true(&queryString)) {
		ZEPHIR_INIT_VAR(&_22$$9);
		ZEPHIR_CONCAT_VSV(&_22$$9, &retUrl, "?", &queryString);
		ZEPHIR_CPY_WRT(&retUrl, &_22$$9);
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

	zend_bool _7;
	zend_class_entry *_5, *_9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long encoding, ZEPHIR_LAST_CALL_STATUS;
	zval *method_param = NULL, *url_param = NULL, *data, data_sub, *encoding_param = NULL, request, _0, _2, _4, _6, _8, _12, _1$$3, _3$$4, _10$$5, _11$$5;
	zval method, url;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&url);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&request);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);

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
	ZEPHIR_CALL_METHOD(NULL, &request, "__construct", NULL, 86, this_ptr);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("defaultHeaders"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_0)) {
		zephir_read_property(&_1$$3, this_ptr, SL("defaultHeaders"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &request, "setheaders", NULL, 87, &_1$$3);
		zephir_check_call_status();
	}
	zephir_read_property(&_2, this_ptr, SL("defaultOptions"), PH_NOISY_CC | PH_READONLY);
	if (zephir_is_true(&_2)) {
		zephir_read_property(&_3$$4, this_ptr, SL("defaultOptions"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &request, "setoptions", NULL, 88, &_3$$4);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, &request, "setmethod", NULL, 89, &method);
	zephir_check_call_status();
	_5 = zephir_fetch_class_str_ex(SL("Phalcon\\Text"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_INIT_VAR(&_6);
	ZVAL_STRING(&_6, "http://");
	ZEPHIR_CALL_CE_STATIC(&_4, _5, "startswith", NULL, 0, &url, &_6);
	zephir_check_call_status();
	_7 = zephir_is_true(&_4);
	if (!(_7)) {
		_9 = zephir_fetch_class_str_ex(SL("Phalcon\\Text"), ZEND_FETCH_CLASS_AUTO);
		ZEPHIR_INIT_NVAR(&_6);
		ZVAL_STRING(&_6, "https://");
		ZEPHIR_CALL_CE_STATIC(&_8, _9, "startswith", NULL, 0, &url, &_6);
		zephir_check_call_status();
		_7 = zephir_is_true(&_8);
	}
	if (_7) {
	} else {
		zephir_read_property(&_10$$5, this_ptr, SL("baseUrl"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_11$$5);
		ZEPHIR_CONCAT_VV(&_11$$5, &_10$$5, &url);
		zephir_get_strval(&url, &_11$$5);
	}
	ZEPHIR_CALL_METHOD(NULL, &request, "seturl", NULL, 90, &url);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &request, "setdata", NULL, 91, data);
	zephir_check_call_status();
	ZVAL_LONG(&_12, encoding);
	ZEPHIR_CALL_METHOD(NULL, &request, "setencoding", NULL, 92, &_12);
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
 * @return Curl
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



	ZEPHIR_CALL_FUNCTION(&_0, "curl_init", NULL, 93);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("ch"), &_0);
	zephir_read_property(&_1, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_2, 19913);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 94, &_1, &_2, &__$true);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_4, 42);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 94, &_2, &_4, &__$true);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&auth, request, "getuserandpass", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&auth)) {
		zephir_read_property(&_5$$3, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_6$$3, 10005);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 94, &_5$$3, &_6$$3, &auth);
		zephir_check_call_status();
	}
	zephir_read_property(&_4, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_7, request, "geturl", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_8, 10002);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 94, &_4, &_8, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&options, request, "getoptions", NULL, 0);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&options))) {
		zephir_read_property(&_9$$4, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt_array", NULL, 95, &_9$$4, &options);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&method, request, "getmethod", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_8, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_10);
	zephir_fast_strtoupper(&_10, &method);
	ZVAL_LONG(&_11, 10036);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 94, &_8, &_11, &_10);
	zephir_check_call_status();
	zephir_read_property(&_11, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_12, request, "formatheaders", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_13, 10023);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 94, &_11, &_13, &_12);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_14, request, "hasdata", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_14)) {
		zephir_read_property(&_15$$5, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_16$$5, request, "encodedata", NULL, 0);
		zephir_check_call_status();
		ZVAL_LONG(&_17$$5, 10015);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 94, &_15$$5, &_17$$5, &_16$$5);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&method, "head")) {
		zephir_read_property(&_18$$6, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_19$$6, 44);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_setopt", &_3, 94, &_18$$6, &_19$$6, &__$true);
		zephir_check_call_status();
	}
	RETURN_THIS();

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
	ZEPHIR_CALL_FUNCTION(&result, "curl_exec", NULL, 96, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&result)) {
		zephir_read_property(&_1$$3, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&errno$$3, "curl_errno", NULL, 97, &_1$$3);
		zephir_check_call_status();
		zephir_read_property(&_2$$3, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(&errmsg$$3, "curl_error", NULL, 98, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&msg$$3);
		ZEPHIR_CONCAT_SVSV(&msg$$3, "Curl request failed with error [", &errno$$3, ":", &errmsg$$3);
		zephir_read_property(&_3$$3, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_FUNCTION(NULL, "curl_close", &_4, 99, &_3$$3);
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
		ZEPHIR_CALL_METHOD(NULL, &ex$$3, "__construct", NULL, 2, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7$$3, &ex$$3, "setcode", NULL, 100, &errno$$3);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_7$$3, "phalconplus/Curl/Curl.zep", 255);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD(&response, this_ptr, "createresponseobject", NULL, 0, &result);
	zephir_check_call_status();
	zephir_read_property(&_8, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(NULL, "curl_close", &_4, 99, &_8);
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
	ZEPHIR_CALL_FUNCTION(&info, "curl_getinfo", &_1, 101, &_0);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, SL("ch"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_3, 2097163);
	ZEPHIR_CALL_FUNCTION(&headerSize, "curl_getinfo", &_1, 101, &_2, &_3);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 0);
	ZEPHIR_INIT_VAR(&headers);
	zephir_substr(&headers, response, 0 , zephir_get_intval(&headerSize), 0);
	ZEPHIR_INIT_VAR(&body);
	zephir_substr(&body, response, zephir_get_intval(&headerSize), 0, ZEPHIR_SUBSTR_NO_LENGTH);
	object_init_ex(return_value, phalconplus_curl_response_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 102, &body, &headers, &info);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Handle dynamic calls to the class.
 *
 * @param  string $func
 * @param  array  $args
 *
 * @return Response
 */
PHP_METHOD(PhalconPlus_Curl_Curl, __call) {

	zend_string *_20$$10;
	zend_ulong _19$$10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval args;
	zval *func_param = NULL, *args_param = NULL, request, method, encoding, url, data, msg, _0, _1, _2, _3, _4, _5, _10, _6$$3, _7$$3, _8$$4, _9$$4, _11$$5, _12$$6, _13$$8, _14$$8, _15$$9, k$$10, v$$10, _16$$10, *_17$$10, _18$$10, _21$$11, _22$$12;
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
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&k$$10);
	ZVAL_UNDEF(&v$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_21$$11);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&args);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &func_param, &args_param);

	zephir_get_strval(&func, func_param);
	zephir_get_arrval(&args, args_param);


	ZEPHIR_INIT_VAR(&data);
	ZVAL_NULL(&data);
	ZEPHIR_INIT_VAR(&msg);
	ZVAL_STRING(&msg, "");
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
		ZEPHIR_INIT_NVAR(&msg);
		ZEPHIR_CONCAT_SVS(&msg, "Method [", &method, "] not a valid HTTP method.");
		ZEPHIR_INIT_VAR(&_11$$5);
		object_init_ex(&_11$$5, spl_ce_BadMethodCallException);
		ZEPHIR_CALL_METHOD(NULL, &_11$$5, "__construct", NULL, 103, &msg);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$5, "phalconplus/Curl/Curl.zep", 300);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(zephir_array_isset_long(&args, 0))) {
		ZEPHIR_INIT_NVAR(&msg);
		ZEPHIR_CONCAT_SVSSSV(&msg, "Missing argument 1 (", &url, ") for ", "PhalconPlus\\Curl\\Curl", "::", &func);
		ZEPHIR_INIT_VAR(&_12$$6);
		object_init_ex(&_12$$6, spl_ce_BadMethodCallException);
		ZEPHIR_CALL_METHOD(NULL, &_12$$6, "__construct", NULL, 103, &msg);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_12$$6, "phalconplus/Curl/Curl.zep", 304);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_OBS_VAR(&url);
	zephir_array_fetch_long(&url, &args, 0, PH_NOISY, "phalconplus/Curl/Curl.zep", 306);
	if (zephir_array_isset_long(&args, 1)) {
		ZEPHIR_OBS_NVAR(&data);
		zephir_array_fetch_long(&data, &args, 1, PH_NOISY, "phalconplus/Curl/Curl.zep", 308);
	}
	ZEPHIR_CALL_METHOD(&request, this_ptr, "newrequest", NULL, 0, &method, &url, &data, &encoding);
	zephir_check_call_status();
	if (zephir_array_isset_long(&args, 2)) {
		ZEPHIR_OBS_VAR(&_13$$8);
		zephir_array_fetch_long(&_13$$8, &args, 2, PH_NOISY, "phalconplus/Curl/Curl.zep", 315);
		ZEPHIR_OBS_VAR(&_14$$8);
		zephir_array_fetch_long(&_14$$8, &args, 2, PH_NOISY, "phalconplus/Curl/Curl.zep", 317);
		if (Z_TYPE_P(&_13$$8) == IS_STRING) {
			zephir_array_fetch_long(&_15$$9, &args, 2, PH_NOISY | PH_READONLY, "phalconplus/Curl/Curl.zep", 316);
			ZEPHIR_CALL_METHOD(NULL, &request, "setheader", NULL, 0, &_15$$9);
			zephir_check_call_status();
		} else if (Z_TYPE_P(&_14$$8) == IS_ARRAY) {
			zephir_array_fetch_long(&_16$$10, &args, 2, PH_NOISY | PH_READONLY, "phalconplus/Curl/Curl.zep", 319);
			zephir_is_iterable(&_16$$10, 0, "phalconplus/Curl/Curl.zep", 322);
			if (Z_TYPE_P(&_16$$10) == IS_ARRAY) {
				ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_16$$10), _19$$10, _20$$10, _17$$10)
				{
					ZEPHIR_INIT_NVAR(&k$$10);
					if (_20$$10 != NULL) { 
						ZVAL_STR_COPY(&k$$10, _20$$10);
					} else {
						ZVAL_LONG(&k$$10, _19$$10);
					}
					ZEPHIR_INIT_NVAR(&v$$10);
					ZVAL_COPY(&v$$10, _17$$10);
					ZVAL_BOOL(&_21$$11, 1);
					ZEPHIR_CALL_METHOD(NULL, &request, "setheader", NULL, 0, &k$$10, &v$$10, &_21$$11);
					zephir_check_call_status();
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_16$$10, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_18$$10, &_16$$10, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_18$$10)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&k$$10, &_16$$10, "key", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&v$$10, &_16$$10, "current", NULL, 0);
					zephir_check_call_status();
						ZVAL_BOOL(&_22$$12, 1);
						ZEPHIR_CALL_METHOD(NULL, &request, "setheader", NULL, 0, &k$$10, &v$$10, &_22$$12);
						zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_16$$10, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&v$$10);
			ZEPHIR_INIT_NVAR(&k$$10);
		}
	}
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

