
extern zend_class_entry *phalconplus_contracts_auth_access_dispatchevent_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_Auth_Access_DispatchEvent);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_contracts_auth_access_dispatchevent_beforeexecuteroute, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, dispatcher, Phalcon\\Mvc\\DispatcherInterface, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_contracts_auth_access_dispatchevent_method_entry) {
	PHP_ABSTRACT_ME(PhalconPlus_Contracts_Auth_Access_DispatchEvent, beforeExecuteRoute, arginfo_phalconplus_contracts_auth_access_dispatchevent_beforeexecuteroute)
	PHP_FE_END
};
