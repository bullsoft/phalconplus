
extern zend_class_entry *phalconplus_base_backendserver_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_BackendServer);

PHP_METHOD(PhalconPlus_Base_BackendServer, __construct);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_backendserver___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DI, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_backendserver_method_entry) {
	PHP_ME(PhalconPlus_Base_BackendServer, __construct, arginfo_phalconplus_base_backendserver___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_FE_END
};
