
extern zend_class_entry *phalconplus_event_servicedispatchlistener_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Event_ServiceDispatchListener);

PHP_METHOD(PhalconPlus_Event_ServiceDispatchListener, beforeDispatch);
PHP_METHOD(PhalconPlus_Event_ServiceDispatchListener, afterDispatch);
PHP_METHOD(PhalconPlus_Event_ServiceDispatchListener, beforeExecute);
PHP_METHOD(PhalconPlus_Event_ServiceDispatchListener, afterExecute);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_event_servicedispatchlistener_beforedispatch, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, component)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_event_servicedispatchlistener_afterdispatch, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, component)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_event_servicedispatchlistener_beforeexecute, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, component)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_event_servicedispatchlistener_afterexecute, 0, 0, 2)
	ZEND_ARG_INFO(0, event)
	ZEND_ARG_INFO(0, component)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_event_servicedispatchlistener_method_entry) {
	PHP_ME(PhalconPlus_Event_ServiceDispatchListener, beforeDispatch, arginfo_phalconplus_event_servicedispatchlistener_beforedispatch, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Event_ServiceDispatchListener, afterDispatch, arginfo_phalconplus_event_servicedispatchlistener_afterdispatch, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Event_ServiceDispatchListener, beforeExecute, arginfo_phalconplus_event_servicedispatchlistener_beforeexecute, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Event_ServiceDispatchListener, afterExecute, arginfo_phalconplus_event_servicedispatchlistener_afterexecute, ZEND_ACC_PUBLIC)
  PHP_FE_END
};
