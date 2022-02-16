
extern zend_class_entry *phalconplus_http_psrresponsefactory_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Http_PsrResponseFactory);

PHP_METHOD(PhalconPlus_Http_PsrResponseFactory, create);
PHP_METHOD(PhalconPlus_Http_PsrResponseFactory, mapHeaders);

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_http_psrresponsefactory_create, 0, 1, Psr\\Http\\Message\\ResponseInterface, 0)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\Response, 0)
	ZEND_ARG_INFO(0, protocol)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_http_psrresponsefactory_mapheaders, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\Response, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_http_psrresponsefactory_method_entry) {
	PHP_ME(PhalconPlus_Http_PsrResponseFactory, create, arginfo_phalconplus_http_psrresponsefactory_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Http_PsrResponseFactory, mapHeaders, arginfo_phalconplus_http_psrresponsefactory_mapheaders, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC)
	PHP_FE_END
};
