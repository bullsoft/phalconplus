
extern zend_class_entry *phalconplus_curl_curl_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Curl_Curl);

PHP_METHOD(PhalconPlus_Curl_Curl, __construct);
PHP_METHOD(PhalconPlus_Curl_Curl, getAllowedMethods);
PHP_METHOD(PhalconPlus_Curl_Curl, setDefaultHeaders);
PHP_METHOD(PhalconPlus_Curl_Curl, getDefaultHeaders);
PHP_METHOD(PhalconPlus_Curl_Curl, setDefaultOptions);
PHP_METHOD(PhalconPlus_Curl_Curl, getDefaultOptions);
PHP_METHOD(PhalconPlus_Curl_Curl, buildUrl);
PHP_METHOD(PhalconPlus_Curl_Curl, newRequest);
PHP_METHOD(PhalconPlus_Curl_Curl, newJsonRequest);
PHP_METHOD(PhalconPlus_Curl_Curl, newRawRequest);
PHP_METHOD(PhalconPlus_Curl_Curl, prepareRequest);
PHP_METHOD(PhalconPlus_Curl_Curl, sendRequest);
PHP_METHOD(PhalconPlus_Curl_Curl, createResponseObject);
PHP_METHOD(PhalconPlus_Curl_Curl, __call);
zend_object *zephir_init_properties_PhalconPlus_Curl_Curl(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_curl___construct, 0, 0, 0)
	ZEND_ARG_ARRAY_INFO(0, opts, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_curl_setdefaultheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_curl_setdefaultoptions, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, options, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_curl_buildurl, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, url)
#endif
	ZEND_ARG_ARRAY_INFO(0, query, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_curl_newrequest, 0, 0, 3)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, url)
#endif
	ZEND_ARG_INFO(0, data)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, encoding, IS_LONG, 0)
#else
	ZEND_ARG_INFO(0, encoding)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_curl_newjsonrequest, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, url)
#endif
	ZEND_ARG_ARRAY_INFO(0, data, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_curl_newrawrequest, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, url, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, url)
#endif
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_curl_preparerequest, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, PhalconPlus\\Curl\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_curl_sendrequest, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, PhalconPlus\\Curl\\Request, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_curl_createresponseobject, 0, 0, 1)
	ZEND_ARG_INFO(0, response)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_curl___call, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, func, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, func)
#endif
	ZEND_ARG_ARRAY_INFO(0, args, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_curl_curl_method_entry) {
	PHP_ME(PhalconPlus_Curl_Curl, __construct, arginfo_phalconplus_curl_curl___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Curl_Curl, getAllowedMethods, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Curl, setDefaultHeaders, arginfo_phalconplus_curl_curl_setdefaultheaders, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Curl, getDefaultHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Curl, setDefaultOptions, arginfo_phalconplus_curl_curl_setdefaultoptions, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Curl, getDefaultOptions, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Curl, buildUrl, arginfo_phalconplus_curl_curl_buildurl, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Curl, newRequest, arginfo_phalconplus_curl_curl_newrequest, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Curl, newJsonRequest, arginfo_phalconplus_curl_curl_newjsonrequest, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Curl, newRawRequest, arginfo_phalconplus_curl_curl_newrawrequest, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Curl, prepareRequest, arginfo_phalconplus_curl_curl_preparerequest, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Curl, sendRequest, arginfo_phalconplus_curl_curl_sendrequest, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Curl, createResponseObject, arginfo_phalconplus_curl_curl_createresponseobject, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Curl_Curl, __call, arginfo_phalconplus_curl_curl___call, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
