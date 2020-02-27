
extern zend_class_entry *phalconplus_app_module_abstractmodule_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_App_Module_AbstractModule);

PHP_METHOD(PhalconPlus_App_Module_AbstractModule, __construct);
PHP_METHOD(PhalconPlus_App_Module_AbstractModule, getConfig);
PHP_METHOD(PhalconPlus_App_Module_AbstractModule, getDef);
PHP_METHOD(PhalconPlus_App_Module_AbstractModule, getDI);
PHP_METHOD(PhalconPlus_App_Module_AbstractModule, isPrimary);
PHP_METHOD(PhalconPlus_App_Module_AbstractModule, getName);
PHP_METHOD(PhalconPlus_App_Module_AbstractModule, getBootstrap);
PHP_METHOD(PhalconPlus_App_Module_AbstractModule, __call);
PHP_METHOD(PhalconPlus_App_Module_AbstractModule, registerAutoloaders);
PHP_METHOD(PhalconPlus_App_Module_AbstractModule, registerServices);
PHP_METHOD(PhalconPlus_App_Module_AbstractModule, registerEvents);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_app_module_abstractmodule___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DI, 0)
	ZEND_ARG_OBJ_INFO(0, def, PhalconPlus\\App\\Module\\ModuleDef, 1)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_module_abstractmodule_getdef, 0, 0, PhalconPlus\\Base\\ModuleDef, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_abstractmodule_getdef, 0, 0, IS_OBJECT, "PhalconPlus\\Base\\ModuleDef", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_app_module_abstractmodule_getdi, 0, 0, Phalcon\\Di, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_app_module_abstractmodule_getdi, 0, 0, IS_OBJECT, "Phalcon\\Di", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_app_module_abstractmodule___call, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, method, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, method)
#endif
	ZEND_ARG_ARRAY_INFO(0, params, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_app_module_abstractmodule_method_entry) {
	PHP_ME(PhalconPlus_App_Module_AbstractModule, __construct, arginfo_phalconplus_app_module_abstractmodule___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_App_Module_AbstractModule, getConfig, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_AbstractModule, getDef, arginfo_phalconplus_app_module_abstractmodule_getdef, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_AbstractModule, getDI, arginfo_phalconplus_app_module_abstractmodule_getdi, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_AbstractModule, isPrimary, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_AbstractModule, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_AbstractModule, getBootstrap, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_AbstractModule, __call, arginfo_phalconplus_app_module_abstractmodule___call, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_AbstractModule, registerAutoloaders, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_AbstractModule, registerServices, NULL, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_App_Module_AbstractModule, registerEvents, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
