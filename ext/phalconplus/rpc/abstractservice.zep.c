
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_AbstractService)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Rpc, AbstractService, phalconplus, rpc_abstractservice, zephir_get_internal_ce(SL("phalcon\\application\\abstractapplication")), phalconplus_rpc_abstractservice_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Rpc_AbstractService, getServer)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "backendSrv");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getmodule", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(PhalconPlus_Rpc_AbstractService, setServer)
{
}

PHP_METHOD(PhalconPlus_Rpc_AbstractService, handle)
{
}

