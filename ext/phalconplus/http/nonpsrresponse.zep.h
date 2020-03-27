
extern zend_class_entry *phalconplus_http_nonpsrresponse_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Http_NonPsrResponse);

PHP_METHOD(PhalconPlus_Http_NonPsrResponse, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_http_nonpsrresponse___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, psrResponse, Psr\\Http\\Message\\ResponseInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_http_nonpsrresponse_method_entry) {
	PHP_ME(PhalconPlus_Http_NonPsrResponse, __construct, arginfo_phalconplus_http_nonpsrresponse___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
