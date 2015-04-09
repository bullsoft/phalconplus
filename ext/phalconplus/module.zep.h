
extern zend_class_entry *phalconplus_module_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Module);

PHP_METHOD(PhalconPlus_Module, __construct);
PHP_METHOD(PhalconPlus_Module, registerAutoloaders);
PHP_METHOD(PhalconPlus_Module, registerServices);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_module___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DI, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_module_method_entry) {
	PHP_ME(PhalconPlus_Module, __construct, arginfo_phalconplus_module___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Module, registerAutoloaders, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Module, registerServices, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
  PHP_FE_END
};
