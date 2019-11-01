
extern zend_class_entry *phalconplus_curl_exception_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Curl_Exception);

PHP_METHOD(PhalconPlus_Curl_Exception, getRequest);

ZEPHIR_INIT_FUNCS(phalconplus_curl_exception_method_entry) {
	PHP_ME(PhalconPlus_Curl_Exception, getRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
