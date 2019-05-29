
extern zend_class_entry *phalconplus_base_psrrequest_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_PsrRequest);

PHP_METHOD(PhalconPlus_Base_PsrRequest, getAttributes);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getCookies);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getFiles);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getPsrRequest);
PHP_METHOD(PhalconPlus_Base_PsrRequest, __construct);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getRequestTarget);
PHP_METHOD(PhalconPlus_Base_PsrRequest, mapFiles);
PHP_METHOD(PhalconPlus_Base_PsrRequest, removeTmpFiles);
PHP_METHOD(PhalconPlus_Base_PsrRequest, get);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getPost);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getQuery);
PHP_METHOD(PhalconPlus_Base_PsrRequest, has);
PHP_METHOD(PhalconPlus_Base_PsrRequest, hasPost);
PHP_METHOD(PhalconPlus_Base_PsrRequest, hasQuery);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getScheme);
PHP_METHOD(PhalconPlus_Base_PsrRequest, isAjax);
PHP_METHOD(PhalconPlus_Base_PsrRequest, isSoap);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getServerAddress);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getServerName);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getHttpHost);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getPort);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getClientAddress);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getUserAgent);
PHP_METHOD(PhalconPlus_Base_PsrRequest, hasFiles);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getUploadedFiles);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getHeaders);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getHTTPReferer);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getContentType);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getBasicAuth);
PHP_METHOD(PhalconPlus_Base_PsrRequest, getDigestAuth);
zend_object *zephir_init_properties_PhalconPlus_Base_PsrRequest(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_psrrequest___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Psr\\Http\\Message\\ServerRequestInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_psrrequest_getrequesttarget, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, request, Psr\\Http\\Message\\ServerRequestInterface, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_psrrequest_mapfiles, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, uploads, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_psrrequest_get, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, notAllowEmpty)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, noRecursive)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_psrrequest_getpost, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, notAllowEmpty)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, noRecursive)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_psrrequest_getquery, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, name)
#endif
	ZEND_ARG_INFO(0, filters)
	ZEND_ARG_INFO(0, defaultValue)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, notAllowEmpty, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, notAllowEmpty)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, noRecursive, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, noRecursive)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_has, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_has, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_haspost, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_haspost, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_hasquery, 0, 1, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_hasquery, 0, 1, _IS_BOOL, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, name)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getscheme, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getscheme, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_isajax, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_isajax, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_issoap, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_issoap, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getserveraddress, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getserveraddress, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getservername, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getservername, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_gethttphost, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_gethttphost, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getport, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getport, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_psrrequest_getclientaddress, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, trustForwardedHeader, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, trustForwardedHeader)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getuseragent, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getuseragent, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_hasfiles, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_hasfiles, 0, 0, IS_LONG, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, onlySuccessful, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, onlySuccessful)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getuploadedfiles, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getuploadedfiles, 0, 0, IS_ARRAY, NULL, 0)
#endif
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, onlySuccessful, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, onlySuccessful)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getheaders, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getheaders, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_gethttpreferer, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_gethttpreferer, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getcontenttype, 0, 0, IS_STRING, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getcontenttype, 0, 0, IS_STRING, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getbasicauth, 0, 0, IS_ARRAY, 1)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getbasicauth, 0, 0, IS_ARRAY, NULL, 1)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getdigestauth, 0, 0, IS_ARRAY, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_psrrequest_getdigestauth, 0, 0, IS_ARRAY, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_psrrequest_method_entry) {
	PHP_ME(PhalconPlus_Base_PsrRequest, getAttributes, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, getCookies, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, getFiles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, getPsrRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, __construct, arginfo_phalconplus_base_psrrequest___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Base_PsrRequest, getRequestTarget, arginfo_phalconplus_base_psrrequest_getrequesttarget, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, mapFiles, arginfo_phalconplus_base_psrrequest_mapfiles, ZEND_ACC_PRIVATE)
	PHP_ME(PhalconPlus_Base_PsrRequest, removeTmpFiles, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, get, arginfo_phalconplus_base_psrrequest_get, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, getPost, arginfo_phalconplus_base_psrrequest_getpost, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, getQuery, arginfo_phalconplus_base_psrrequest_getquery, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, has, arginfo_phalconplus_base_psrrequest_has, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, hasPost, arginfo_phalconplus_base_psrrequest_haspost, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, hasQuery, arginfo_phalconplus_base_psrrequest_hasquery, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, getScheme, arginfo_phalconplus_base_psrrequest_getscheme, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, isAjax, arginfo_phalconplus_base_psrrequest_isajax, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, isSoap, arginfo_phalconplus_base_psrrequest_issoap, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, getServerAddress, arginfo_phalconplus_base_psrrequest_getserveraddress, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, getServerName, arginfo_phalconplus_base_psrrequest_getservername, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, getHttpHost, arginfo_phalconplus_base_psrrequest_gethttphost, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, getPort, arginfo_phalconplus_base_psrrequest_getport, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, getClientAddress, arginfo_phalconplus_base_psrrequest_getclientaddress, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, getUserAgent, arginfo_phalconplus_base_psrrequest_getuseragent, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, hasFiles, arginfo_phalconplus_base_psrrequest_hasfiles, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, getUploadedFiles, arginfo_phalconplus_base_psrrequest_getuploadedfiles, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, getHeaders, arginfo_phalconplus_base_psrrequest_getheaders, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, getHTTPReferer, arginfo_phalconplus_base_psrrequest_gethttpreferer, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, getContentType, arginfo_phalconplus_base_psrrequest_getcontenttype, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, getBasicAuth, arginfo_phalconplus_base_psrrequest_getbasicauth, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrRequest, getDigestAuth, arginfo_phalconplus_base_psrrequest_getdigestauth, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
