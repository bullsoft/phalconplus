
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(PhalconPlus_App_Driver_AppDriver) {

	ZEPHIR_REGISTER_INTERFACE(PhalconPlus\\App\\Driver, AppDriver, phalconplus, app_driver_appdriver, phalconplus_app_driver_appdriver_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(PhalconPlus_App_Driver_AppDriver, getHandler);

ZEPHIR_DOC_METHOD(PhalconPlus_App_Driver_AppDriver, setHandler);

