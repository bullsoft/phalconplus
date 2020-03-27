
extern zend_class_entry *phalconplus_contracts_auth_policy_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_Auth_Policy);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_policy_list, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_policy_list, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, user, PhalconPlus\\Contracts\\Auth\\UserProvider, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_policy_view, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_policy_view, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, user, PhalconPlus\\Contracts\\Auth\\UserProvider, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_policy_delete, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_policy_delete, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, user, PhalconPlus\\Contracts\\Auth\\UserProvider, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_policy_create, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_policy_create, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, user, PhalconPlus\\Contracts\\Auth\\UserProvider, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_policy_update, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_policy_update, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, user, PhalconPlus\\Contracts\\Auth\\UserProvider, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_contracts_auth_policy_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Auth_Policy, list, arginfo_phalconplus_contracts_auth_policy_list)
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Auth_Policy, view, arginfo_phalconplus_contracts_auth_policy_view)
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Auth_Policy, delete, arginfo_phalconplus_contracts_auth_policy_delete)
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Auth_Policy, create, arginfo_phalconplus_contracts_auth_policy_create)
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Auth_Policy, update, arginfo_phalconplus_contracts_auth_policy_update)
	PHP_FE_END
};
