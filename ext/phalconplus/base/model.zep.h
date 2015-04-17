
extern zend_class_entry *phalconplus_base_model_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_Model);

PHP_METHOD(PhalconPlus_Base_Model, initialize);
PHP_METHOD(PhalconPlus_Base_Model, getMessage);
PHP_METHOD(PhalconPlus_Base_Model, getFirstMessage);
PHP_METHOD(PhalconPlus_Base_Model, getLastMessage);
PHP_METHOD(PhalconPlus_Base_Model, createBuilder);
PHP_METHOD(PhalconPlus_Base_Model, getInstance);
PHP_METHOD(PhalconPlus_Base_Model, beforeValidationOnCreate);
PHP_METHOD(PhalconPlus_Base_Model, afterFetch);
PHP_METHOD(PhalconPlus_Base_Model, beforeSave);
PHP_METHOD(PhalconPlus_Base_Model, findByPagable);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_createbuilder, 0, 0, 0)
	ZEND_ARG_INFO(0, alias)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_model_findbypagable, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, pagable, PhalconPlus\\Base\\Pagable, 0)
	ZEND_ARG_ARRAY_INFO(0, params, 1)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_model_method_entry) {
	PHP_ME(PhalconPlus_Base_Model, initialize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, getMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, getFirstMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, getLastMessage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, createBuilder, arginfo_phalconplus_base_model_createbuilder, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, getInstance, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Base_Model, beforeValidationOnCreate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, afterFetch, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, beforeSave, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Model, findByPagable, arginfo_phalconplus_base_model_findbypagable, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
