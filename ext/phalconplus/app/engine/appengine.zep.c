
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(PhalconPlus_App_Engine_AppEngine) {

	ZEPHIR_REGISTER_INTERFACE(PhalconPlus\\App\\Engine, AppEngine, phalconplus, app_engine_appengine, phalconplus_app_engine_appengine_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(PhalconPlus_App_Engine_AppEngine, getHandler);

ZEPHIR_DOC_METHOD(PhalconPlus_App_Engine_AppEngine, setHandler);

