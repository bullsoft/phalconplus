
extern zend_class_entry *phalconplus_contracts_auth_userprovider_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_Auth_UserProvider);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_userprovider_getrole, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_userprovider_getrole, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_userprovider_getname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_userprovider_getname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_userprovider_getidname, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_userprovider_getidname, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_userprovider_getusernamename, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_userprovider_getusernamename, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_contracts_auth_userprovider_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Auth_UserProvider, getRole, arginfo_phalconplus_contracts_auth_userprovider_getrole)
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Auth_UserProvider, getName, arginfo_phalconplus_contracts_auth_userprovider_getname)
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Auth_UserProvider, getIdName, arginfo_phalconplus_contracts_auth_userprovider_getidname)
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Auth_UserProvider, getUsernameName, arginfo_phalconplus_contracts_auth_userprovider_getusernamename)
	PHP_FE_END
};
