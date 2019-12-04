
extern zend_class_entry *phalconplus_curl_response_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Curl_Response);

PHP_METHOD(PhalconPlus_Curl_Response, getBody);
PHP_METHOD(PhalconPlus_Curl_Response, getStatusText);
PHP_METHOD(PhalconPlus_Curl_Response, getStatusCode);
PHP_METHOD(PhalconPlus_Curl_Response, __construct);
PHP_METHOD(PhalconPlus_Curl_Response, parseHeader);
PHP_METHOD(PhalconPlus_Curl_Response, parseHeaders);
PHP_METHOD(PhalconPlus_Curl_Response, getHeader);
PHP_METHOD(PhalconPlus_Curl_Response, getHeaders);
PHP_METHOD(PhalconPlus_Curl_Response, toArray);
PHP_METHOD(PhalconPlus_Curl_Response, toJson);
PHP_METHOD(PhalconPlus_Curl_Response, jsonSerialize);
PHP_METHOD(PhalconPlus_Curl_Response, __toString);
zend_object *zephir_init_properties_PhalconPlus_Curl_Response(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_curl_response_getbody, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_curl_response_getbody, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_curl_response_getstatustext, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_curl_response_getstatustext, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_curl_response_getstatuscode, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_curl_response_getstatuscode, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_response___construct, 0, 0, 2)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, body, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, body)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, headers, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, headers)
#endif
	ZEND_ARG_INFO(0, info)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_response_parseheader, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, header, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, header)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_response_parseheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_response_getheader, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_curl_response_method_entry) {
	PHP_ME(PhalconPlus_Curl_Response, getBody, arginfo_phalconplus_curl_response_getbody, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Response, getStatusText, arginfo_phalconplus_curl_response_getstatustext, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Response, getStatusCode, arginfo_phalconplus_curl_response_getstatuscode, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Response, __construct, arginfo_phalconplus_curl_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Curl_Response, parseHeader, arginfo_phalconplus_curl_response_parseheader, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Curl_Response, parseHeaders, arginfo_phalconplus_curl_response_parseheaders, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Curl_Response, getHeader, arginfo_phalconplus_curl_response_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Response, getHeaders, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Response, toArray, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Response, toJson, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Response, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Response, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
