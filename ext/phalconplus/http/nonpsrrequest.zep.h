
extern zend_class_entry *phalconplus_http_nonpsrrequest_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Http_NonPsrRequest);

PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getAttributes);
PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getCookies);
PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getFiles);
PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getPsrRequest);
PHP_METHOD(PhalconPlus_Http_NonPsrRequest, __construct);
PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getRequestTarget);
PHP_METHOD(PhalconPlus_Http_NonPsrRequest, mapFiles);
PHP_METHOD(PhalconPlus_Http_NonPsrRequest, removeTmpFiles);
PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getScheme);
PHP_METHOD(PhalconPlus_Http_NonPsrRequest, isAjax);
PHP_METHOD(PhalconPlus_Http_NonPsrRequest, isSoap);
PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getHttpHost);
PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getPort);
PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getHeaders);
PHP_METHOD(PhalconPlus_Http_NonPsrRequest, getContentType);
zend_object *zephir_init_properties_PhalconPlus_Http_NonPsrRequest(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_http_nonpsrrequest___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Psr\\Http\\Message\\ServerRequestInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_http_nonpsrrequest_getrequesttarget, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Psr\\Http\\Message\\ServerRequestInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_http_nonpsrrequest_mapfiles, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, uploads, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_http_nonpsrrequest_getscheme, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_http_nonpsrrequest_getscheme, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_http_nonpsrrequest_isajax, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_http_nonpsrrequest_isajax, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_http_nonpsrrequest_issoap, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_http_nonpsrrequest_issoap, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_http_nonpsrrequest_gethttphost, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_http_nonpsrrequest_gethttphost, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_http_nonpsrrequest_getport, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_http_nonpsrrequest_getport, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_http_nonpsrrequest_getheaders, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_http_nonpsrrequest_getheaders, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_http_nonpsrrequest_getcontenttype, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_http_nonpsrrequest_getcontenttype, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_http_nonpsrrequest_method_entry) {
	PHP_ME(PhalconPlus_Http_NonPsrRequest, getAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Http_NonPsrRequest, getCookies, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Http_NonPsrRequest, getFiles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Http_NonPsrRequest, getPsrRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Http_NonPsrRequest, __construct, arginfo_phalconplus_http_nonpsrrequest___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Http_NonPsrRequest, getRequestTarget, arginfo_phalconplus_http_nonpsrrequest_getrequesttarget, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Http_NonPsrRequest, mapFiles, arginfo_phalconplus_http_nonpsrrequest_mapfiles, ZEND_ACC_PRIVATE)
	PHP_ME(PhalconPlus_Http_NonPsrRequest, removeTmpFiles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Http_NonPsrRequest, getScheme, arginfo_phalconplus_http_nonpsrrequest_getscheme, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Http_NonPsrRequest, isAjax, arginfo_phalconplus_http_nonpsrrequest_isajax, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Http_NonPsrRequest, isSoap, arginfo_phalconplus_http_nonpsrrequest_issoap, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Http_NonPsrRequest, getHttpHost, arginfo_phalconplus_http_nonpsrrequest_gethttphost, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Http_NonPsrRequest, getPort, arginfo_phalconplus_http_nonpsrrequest_getport, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Http_NonPsrRequest, getHeaders, arginfo_phalconplus_http_nonpsrrequest_getheaders, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Http_NonPsrRequest, getContentType, arginfo_phalconplus_http_nonpsrrequest_getcontenttype, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
