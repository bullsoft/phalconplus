
extern zend_class_entry *phalconplus_contracts_auth_access_modelevent_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_Auth_Access_ModelEvent);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_access_modelevent_beforedelete, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_access_modelevent_beforecreate, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_access_modelevent_beforeupdate, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_access_modelevent_beforevalidation, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_contracts_auth_access_modelevent_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Auth_Access_ModelEvent, beforeDelete, arginfo_phalconplus_contracts_auth_access_modelevent_beforedelete)
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Auth_Access_ModelEvent, beforeCreate, arginfo_phalconplus_contracts_auth_access_modelevent_beforecreate)
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Auth_Access_ModelEvent, beforeUpdate, arginfo_phalconplus_contracts_auth_access_modelevent_beforeupdate)
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Auth_Access_ModelEvent, beforeValidation, arginfo_phalconplus_contracts_auth_access_modelevent_beforevalidation)
	PHP_FE_END
};
