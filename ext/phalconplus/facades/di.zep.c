
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


ZEPHIR_INIT_CLASS(PhalconPlus_Facades_Di)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Facades, Di, phalconplus, facades_di, phalconplus_facades_abstractfacade_ce, phalconplus_facades_di_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Facades_Di, getName)
{
	zval *this_ptr = getThis();



	RETURN_STRING("di");
}

PHP_METHOD(PhalconPlus_Facades_Di, resolve)
{
	zval *di, di_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(di, zephir_get_internal_ce(SL("phalcon\\di\\di")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &di);


	RETVAL_ZVAL(di, 1, 0);
	return;
}

