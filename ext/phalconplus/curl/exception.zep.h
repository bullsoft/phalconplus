
extern zend_class_entry *phalconplus_curl_exception_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Curl_Exception);

PHP_METHOD(PhalconPlus_Curl_Exception, getRequest);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_curl_exception_getrequest, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_curl_exception_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Curl_Exception, getRequest, arginfo_phalconplus_curl_exception_getrequest, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Curl_Exception, getRequest, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
