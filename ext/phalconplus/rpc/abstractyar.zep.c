
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


ZEPHIR_INIT_CLASS(PhalconPlus_Rpc_AbstractYar)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Rpc, AbstractYar, phalconplus, rpc_abstractyar, zephir_get_internal_ce(SL("phalcon\\application\\abstractapplication")), phalconplus_rpc_abstractyar_method_entry, 0);

	zephir_declare_class_constant_string(phalconplus_rpc_abstractyar_ce, SL("NAME"), "backendSrv");

	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Rpc_AbstractYar, getServer)
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

PHP_METHOD(PhalconPlus_Rpc_AbstractYar, setServer)
{
}

PHP_METHOD(PhalconPlus_Rpc_AbstractYar, handle)
{
}

