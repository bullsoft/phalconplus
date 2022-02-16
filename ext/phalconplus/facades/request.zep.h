
extern zend_class_entry *phalconplus_facades_request_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Facades_Request);

PHP_METHOD(PhalconPlus_Facades_Request, getName);
PHP_METHOD(PhalconPlus_Facades_Request, setPost);
PHP_METHOD(PhalconPlus_Facades_Request, setQuery);
PHP_METHOD(PhalconPlus_Facades_Request, setServer);
PHP_METHOD(PhalconPlus_Facades_Request, set);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_facades_request_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_facades_request_setpost, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_facades_request_setquery, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_facades_request_setserver, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_facades_request_set, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, val)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_facades_request_method_entry) {
	PHP_ME(PhalconPlus_Facades_Request, getName, arginfo_phalconplus_facades_request_getname, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Facades_Request, setPost, arginfo_phalconplus_facades_request_setpost, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Facades_Request, setQuery, arginfo_phalconplus_facades_request_setquery, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Facades_Request, setServer, arginfo_phalconplus_facades_request_setserver, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Facades_Request, set, arginfo_phalconplus_facades_request_set, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
