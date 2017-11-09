
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Event_ServiceDispatchListener) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Event, ServiceDispatchListener, phalconplus, event_servicedispatchlistener, phalconplus_event_servicedispatchlistener_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Event_ServiceDispatchListener, beforeDispatch) {

	zval *event, *component;

	zephir_fetch_params(0, 2, 0, &event, &component);




}

PHP_METHOD(PhalconPlus_Event_ServiceDispatchListener, afterDispatch) {

	zval *event, *component;

	zephir_fetch_params(0, 2, 0, &event, &component);




}

PHP_METHOD(PhalconPlus_Event_ServiceDispatchListener, beforeExecute) {

	zval *event, *component;

	zephir_fetch_params(0, 2, 0, &event, &component);




}

PHP_METHOD(PhalconPlus_Event_ServiceDispatchListener, afterExecute) {

	zval *event, *component;

	zephir_fetch_params(0, 2, 0, &event, &component);




}

