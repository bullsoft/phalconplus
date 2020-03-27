
extern zend_class_entry *phalconplus_auth_policy_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Auth_Policy);

PHP_METHOD(PhalconPlus_Auth_Policy, __construct);
PHP_METHOD(PhalconPlus_Auth_Policy, list);
PHP_METHOD(PhalconPlus_Auth_Policy, view);
PHP_METHOD(PhalconPlus_Auth_Policy, delete);
PHP_METHOD(PhalconPlus_Auth_Policy, update);
PHP_METHOD(PhalconPlus_Auth_Policy, create);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_policy_list, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_policy_list, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, user, PhalconPlus\\Contracts\\Auth\\UserProvider, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_policy_view, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_policy_view, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, user, PhalconPlus\\Contracts\\Auth\\UserProvider, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_policy_delete, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_policy_delete, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, user, PhalconPlus\\Contracts\\Auth\\UserProvider, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_policy_update, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_policy_update, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, user, PhalconPlus\\Contracts\\Auth\\UserProvider, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_policy_create, 0, 2, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_policy_create, 0, 2, _IS_BOOL, NULL, 0)
#endif
	ZEND_ARG_OBJ_INFO(0, user, PhalconPlus\\Contracts\\Auth\\UserProvider, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_auth_policy_method_entry) {
	PHP_ME(PhalconPlus_Auth_Policy, __construct, NULL, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Auth_Policy, list, arginfo_phalconplus_auth_policy_list, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Auth_Policy, view, arginfo_phalconplus_auth_policy_view, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Auth_Policy, delete, arginfo_phalconplus_auth_policy_delete, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Auth_Policy, update, arginfo_phalconplus_auth_policy_update, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Auth_Policy, create, arginfo_phalconplus_auth_policy_create, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
