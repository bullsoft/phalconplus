
extern zend_class_entry *phalconplus_base_service_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_Service);

PHP_METHOD(PhalconPlus_Base_Service, __construct);
PHP_METHOD(PhalconPlus_Base_Service, getDI);
PHP_METHOD(PhalconPlus_Base_Service, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_service___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DI, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_service___get, 0, 0, 1)
	ZEND_ARG_INFO(0, key)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_service_method_entry) {
	PHP_ME(PhalconPlus_Base_Service, __construct, arginfo_phalconplus_base_service___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Base_Service, getDI, NULL, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Base_Service, __get, arginfo_phalconplus_base_service___get, ZEND_ACC_PROTECTED)
  PHP_FE_END
};
