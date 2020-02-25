
extern zend_class_entry *phalconplus_contracts_auth_access_routerevent_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_Auth_Access_RouterEvent);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_contracts_auth_access_routerevent_matchedroute, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, router, Phalcon\\Mvc\\Router, 0)
	ZEND_ARG_OBJ_INFO(0, route, Phalcon\\Mvc\\Router\\Route, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_contracts_auth_access_routerevent_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Auth_Access_RouterEvent, matchedRoute, arginfo_phalconplus_contracts_auth_access_routerevent_matchedroute)
	PHP_FE_END
};
