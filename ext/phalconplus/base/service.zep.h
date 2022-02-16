
extern zend_class_entry *phalconplus_base_service_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_Service);

PHP_METHOD(PhalconPlus_Base_Service, __construct);
PHP_METHOD(PhalconPlus_Base_Service, onConstruct);
PHP_METHOD(PhalconPlus_Base_Service, getDI);
PHP_METHOD(PhalconPlus_Base_Service, __get);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_service___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\Di\\Di, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_service_onconstruct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_service_getdi, 0, 0, Phalcon\\Di\\Di, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_service___get, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_service_method_entry) {
	PHP_ME(PhalconPlus_Base_Service, __construct, arginfo_phalconplus_base_service___construct, ZEND_ACC_FINAL|ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Service, onConstruct, arginfo_phalconplus_base_service_onconstruct, ZEND_ACC_PROTECTED)
#else
	PHP_ME(PhalconPlus_Base_Service, onConstruct, NULL, ZEND_ACC_PROTECTED)
#endif
	PHP_ME(PhalconPlus_Base_Service, getDI, arginfo_phalconplus_base_service_getdi, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Base_Service, __get, arginfo_phalconplus_base_service___get, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
