
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Facades_Acl)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Facades, Acl, phalconplus, facades_acl, phalconplus_facades_abstractfacade_ce, phalconplus_facades_acl_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Facades_Acl, getName)
{
	zval *this_ptr = getThis();



	RETURN_STRING("acl");
}

PHP_METHOD(PhalconPlus_Facades_Acl, resolve)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di, di_sub, acl, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
	ZVAL_UNDEF(&acl);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(di, phalcon_di_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &di);


	ZEPHIR_INIT_VAR(&acl);
	object_init_ex(&acl, zephir_get_internal_ce(SL("phalcon\\acl\\adapter\\memory")));
	ZEPHIR_CALL_METHOD(NULL, &acl, "__construct", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, &acl, "setdefaultaction", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getname", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, di, "setshared", NULL, 0, &_1, &acl);
	zephir_check_call_status();
	RETURN_MM_NULL();
}

