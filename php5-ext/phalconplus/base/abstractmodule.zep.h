
extern zend_class_entry *phalconplus_base_abstractmodule_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_AbstractModule);

PHP_METHOD(PhalconPlus_Base_AbstractModule, __construct);
PHP_METHOD(PhalconPlus_Base_AbstractModule, getDef);
PHP_METHOD(PhalconPlus_Base_AbstractModule, isPrimary);
PHP_METHOD(PhalconPlus_Base_AbstractModule, registerAutoloaders);
PHP_METHOD(PhalconPlus_Base_AbstractModule, registerServices);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_abstractmodule___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DI, 0)
	ZEND_ARG_OBJ_INFO(0, def, PhalconPlus\\Base\\ModuleDef, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_abstractmodule_method_entry) {
	PHP_ME(PhalconPlus_Base_AbstractModule, __construct, arginfo_phalconplus_base_abstractmodule___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Base_AbstractModule, getDef, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_AbstractModule, isPrimary, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_AbstractModule, registerAutoloaders, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_AbstractModule, registerServices, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
