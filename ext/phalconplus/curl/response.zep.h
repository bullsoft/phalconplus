
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
zend_object *zephir_init_properties_PhalconPlus_Curl_Response(zend_class_entry *class_type);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_curl_response_getbody, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_curl_response_getstatustext, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_curl_response_getstatuscode, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_response___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, body, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, headers, IS_STRING, 0)
	ZEND_ARG_INFO(0, info)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_response_parseheader, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, header, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_response_parseheaders, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, headers, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_curl_response_getheader, 0, 1, IS_STRING, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_curl_response_getheaders, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_curl_response_toarray, 0, 0, IS_ARRAY, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, columns, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, columns, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_curl_response_tojson, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_response_jsonserialize, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_curl_response___tostring, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_response_zephir_init_properties_phalconplus_curl_response, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_curl_response_method_entry) {
	PHP_ME(PhalconPlus_Curl_Response, getBody, arginfo_phalconplus_curl_response_getbody, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Response, getStatusText, arginfo_phalconplus_curl_response_getstatustext, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Response, getStatusCode, arginfo_phalconplus_curl_response_getstatuscode, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Response, __construct, arginfo_phalconplus_curl_response___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Curl_Response, parseHeader, arginfo_phalconplus_curl_response_parseheader, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Curl_Response, parseHeaders, arginfo_phalconplus_curl_response_parseheaders, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Curl_Response, getHeader, arginfo_phalconplus_curl_response_getheader, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Response, getHeaders, arginfo_phalconplus_curl_response_getheaders, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Response, toArray, arginfo_phalconplus_curl_response_toarray, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Curl_Response, toJson, arginfo_phalconplus_curl_response_tojson, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Curl_Response, jsonSerialize, arginfo_phalconplus_curl_response_jsonserialize, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Curl_Response, jsonSerialize, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(PhalconPlus_Curl_Response, __toString, arginfo_phalconplus_curl_response___tostring, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
