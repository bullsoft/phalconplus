
extern zend_class_entry *phalconplus_curl_request_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Curl_Request);

PHP_METHOD(PhalconPlus_Curl_Request, __construct);
PHP_METHOD(PhalconPlus_Curl_Request, setMethod);
PHP_METHOD(PhalconPlus_Curl_Request, getMethod);
PHP_METHOD(PhalconPlus_Curl_Request, setUrl);
PHP_METHOD(PhalconPlus_Curl_Request, getUrl);
PHP_METHOD(PhalconPlus_Curl_Request, setHeader);
PHP_METHOD(PhalconPlus_Curl_Request, setHeaders);
PHP_METHOD(PhalconPlus_Curl_Request, getHeader);
PHP_METHOD(PhalconPlus_Curl_Request, getHeaders);
PHP_METHOD(PhalconPlus_Curl_Request, setCookie);
PHP_METHOD(PhalconPlus_Curl_Request, setCookies);
PHP_METHOD(PhalconPlus_Curl_Request, updateCookieHeader);
PHP_METHOD(PhalconPlus_Curl_Request, getCookie);
PHP_METHOD(PhalconPlus_Curl_Request, getCookies);
PHP_METHOD(PhalconPlus_Curl_Request, formatHeaders);
PHP_METHOD(PhalconPlus_Curl_Request, setData);
PHP_METHOD(PhalconPlus_Curl_Request, hasData);
PHP_METHOD(PhalconPlus_Curl_Request, getData);
PHP_METHOD(PhalconPlus_Curl_Request, setEncoding);
PHP_METHOD(PhalconPlus_Curl_Request, getEncoding);
PHP_METHOD(PhalconPlus_Curl_Request, encodeData);
PHP_METHOD(PhalconPlus_Curl_Request, setOption);
PHP_METHOD(PhalconPlus_Curl_Request, setOptions);
PHP_METHOD(PhalconPlus_Curl_Request, getOption);
PHP_METHOD(PhalconPlus_Curl_Request, getOptions);
PHP_METHOD(PhalconPlus_Curl_Request, auth);
PHP_METHOD(PhalconPlus_Curl_Request, setUser);
PHP_METHOD(PhalconPlus_Curl_Request, setPass);
PHP_METHOD(PhalconPlus_Curl_Request, getUserAndPass);
PHP_METHOD(PhalconPlus_Curl_Request, isJson);
PHP_METHOD(PhalconPlus_Curl_Request, send);
void zephir_init_static_properties_PhalconPlus_Curl_Request();
zend_object *zephir_init_properties_PhalconPlus_Curl_Request(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, curl, PhalconPlus\\Curl\\Curl, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_setmethod, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_getmethod, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_seturl, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_geturl, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_setheader, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
	ZEND_ARG_TYPE_INFO(0, preserveCase, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_setheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_getheader, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_getheaders, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_setcookie, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_setcookies, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, cookies, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_updatecookieheader, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_getcookie, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_getcookies, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_formatheaders, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_setdata, 0, 0, 1)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_hasdata, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_getdata, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_setencoding, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, encoding, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_getencoding, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_encodedata, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_setoption, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_setoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_getoption, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_getoptions, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_auth, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, user, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, pass, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_setuser, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, user, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_setpass, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, pass, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_getuserandpass, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_isjson, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_send, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_zephir_init_static_properties_phalconplus_curl_request, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_request_zephir_init_properties_phalconplus_curl_request, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_curl_request_method_entry) {
	PHP_ME(PhalconPlus_Curl_Request, __construct, arginfo_phalconplus_curl_request___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Curl_Request, setMethod, arginfo_phalconplus_curl_request_setmethod, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Curl_Request, getMethod, arginfo_phalconplus_curl_request_getmethod, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Curl_Request, getMethod, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(PhalconPlus_Curl_Request, setUrl, arginfo_phalconplus_curl_request_seturl, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Curl_Request, getUrl, arginfo_phalconplus_curl_request_geturl, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Curl_Request, getUrl, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(PhalconPlus_Curl_Request, setHeader, arginfo_phalconplus_curl_request_setheader, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Request, setHeaders, arginfo_phalconplus_curl_request_setheaders, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Request, getHeader, arginfo_phalconplus_curl_request_getheader, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Curl_Request, getHeaders, arginfo_phalconplus_curl_request_getheaders, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Curl_Request, getHeaders, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(PhalconPlus_Curl_Request, setCookie, arginfo_phalconplus_curl_request_setcookie, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Request, setCookies, arginfo_phalconplus_curl_request_setcookies, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Curl_Request, updateCookieHeader, arginfo_phalconplus_curl_request_updatecookieheader, ZEND_ACC_PRIVATE)
#else
	PHP_ME(PhalconPlus_Curl_Request, updateCookieHeader, NULL, ZEND_ACC_PRIVATE)
#endif
	PHP_ME(PhalconPlus_Curl_Request, getCookie, arginfo_phalconplus_curl_request_getcookie, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Curl_Request, getCookies, arginfo_phalconplus_curl_request_getcookies, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Curl_Request, getCookies, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Curl_Request, formatHeaders, arginfo_phalconplus_curl_request_formatheaders, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Curl_Request, formatHeaders, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(PhalconPlus_Curl_Request, setData, arginfo_phalconplus_curl_request_setdata, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Curl_Request, hasData, arginfo_phalconplus_curl_request_hasdata, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Curl_Request, hasData, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Curl_Request, getData, arginfo_phalconplus_curl_request_getdata, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Curl_Request, getData, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(PhalconPlus_Curl_Request, setEncoding, arginfo_phalconplus_curl_request_setencoding, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Curl_Request, getEncoding, arginfo_phalconplus_curl_request_getencoding, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Curl_Request, getEncoding, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Curl_Request, encodeData, arginfo_phalconplus_curl_request_encodedata, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Curl_Request, encodeData, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(PhalconPlus_Curl_Request, setOption, arginfo_phalconplus_curl_request_setoption, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Request, setOptions, arginfo_phalconplus_curl_request_setoptions, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Request, getOption, arginfo_phalconplus_curl_request_getoption, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Curl_Request, getOptions, arginfo_phalconplus_curl_request_getoptions, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Curl_Request, getOptions, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(PhalconPlus_Curl_Request, auth, arginfo_phalconplus_curl_request_auth, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Request, setUser, arginfo_phalconplus_curl_request_setuser, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Request, setPass, arginfo_phalconplus_curl_request_setpass, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Curl_Request, getUserAndPass, arginfo_phalconplus_curl_request_getuserandpass, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Curl_Request, getUserAndPass, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Curl_Request, isJson, arginfo_phalconplus_curl_request_isjson, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Curl_Request, isJson, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Curl_Request, send, arginfo_phalconplus_curl_request_send, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Curl_Request, send, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
