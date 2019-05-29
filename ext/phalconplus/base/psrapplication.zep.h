
extern zend_class_entry *phalconplus_base_psrapplication_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_PsrApplication);

PHP_METHOD(PhalconPlus_Base_PsrApplication, setRequest);
PHP_METHOD(PhalconPlus_Base_PsrApplication, getRequest);
PHP_METHOD(PhalconPlus_Base_PsrApplication, getNativeRequest);
PHP_METHOD(PhalconPlus_Base_PsrApplication, __construct);
PHP_METHOD(PhalconPlus_Base_PsrApplication, __destruct);
PHP_METHOD(PhalconPlus_Base_PsrApplication, handle);
PHP_METHOD(PhalconPlus_Base_PsrApplication, mapHeaders);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_psrapplication_setrequest, 0, 0, 1)
	ZEND_ARG_INFO(0, request)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_psrapplication___construct, 0, 0, 0)
	ZEND_ARG_OBJ_INFO(0, dependencyInjector, Phalcon\\DiInterface, 1)
	ZEND_ARG_OBJ_INFO(0, request, Psr\\Http\\Message\\ServerRequestInterface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_psrapplication_handle, 0, 0, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 1)
#else
	ZEND_ARG_INFO(0, uri)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_psrapplication_mapheaders, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, response, Phalcon\\Http\\Response, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_psrapplication_method_entry) {
	PHP_ME(PhalconPlus_Base_PsrApplication, setRequest, arginfo_phalconplus_base_psrapplication_setrequest, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrApplication, getRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrApplication, getNativeRequest, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrApplication, __construct, arginfo_phalconplus_base_psrapplication___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Base_PsrApplication, __destruct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_DTOR)
	PHP_ME(PhalconPlus_Base_PsrApplication, handle, arginfo_phalconplus_base_psrapplication_handle, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_PsrApplication, mapHeaders, arginfo_phalconplus_base_psrapplication_mapheaders, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
