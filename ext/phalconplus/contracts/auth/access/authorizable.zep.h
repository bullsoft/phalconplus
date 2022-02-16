
extern zend_class_entry *phalconplus_contracts_auth_access_authorizable_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_Auth_Access_Authorizable);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_access_authorizable_can, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, ability, IS_STRING, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_contracts_auth_access_authorizable_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Auth_Access_Authorizable, can, arginfo_phalconplus_contracts_auth_access_authorizable_can)
	PHP_FE_END
};
