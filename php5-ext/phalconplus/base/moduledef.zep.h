
extern zend_class_entry *phalconplus_base_moduledef_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_ModuleDef);

PHP_METHOD(PhalconPlus_Base_ModuleDef, __construct);
PHP_METHOD(PhalconPlus_Base_ModuleDef, impl);
PHP_METHOD(PhalconPlus_Base_ModuleDef, getIsPrimary);
PHP_METHOD(PhalconPlus_Base_ModuleDef, getClassPath);
PHP_METHOD(PhalconPlus_Base_ModuleDef, getClassName);
PHP_METHOD(PhalconPlus_Base_ModuleDef, getRunMode);
PHP_METHOD(PhalconPlus_Base_ModuleDef, getMapClassName);
PHP_METHOD(PhalconPlus_Base_ModuleDef, getMode);
PHP_METHOD(PhalconPlus_Base_ModuleDef, getName);
PHP_METHOD(PhalconPlus_Base_ModuleDef, getConfigPath);
PHP_METHOD(PhalconPlus_Base_ModuleDef, getConfig);
PHP_METHOD(PhalconPlus_Base_ModuleDef, getDir);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_moduledef___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, boot, PhalconPlus\\Bootstrap, 0)
	ZEND_ARG_INFO(0, moduleDir)
	ZEND_ARG_INFO(0, isPrimary)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_moduledef_impl, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\Di, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_moduledef_method_entry) {
	PHP_ME(PhalconPlus_Base_ModuleDef, __construct, arginfo_phalconplus_base_moduledef___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Base_ModuleDef, impl, arginfo_phalconplus_base_moduledef_impl, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ModuleDef, getIsPrimary, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ModuleDef, getClassPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ModuleDef, getClassName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ModuleDef, getRunMode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ModuleDef, getMapClassName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ModuleDef, getMode, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ModuleDef, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ModuleDef, getConfigPath, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ModuleDef, getConfig, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ModuleDef, getDir, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
