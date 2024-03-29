
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Helper_Ns)
{
	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Helper, Ns, phalconplus, helper_ns, phalconplus_helper_ns_method_entry, 0);

	return SUCCESS;
}

/**
 * PhalconPlus\App\Engine\Web -> PhalconPlus\App\Engine
 */
PHP_METHOD(PhalconPlus_Helper_Ns, super)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long levels, ZEPHIR_LAST_CALL_STATUS;
	zval *ns_param = NULL, *levels_param = NULL, dir, _0, _1, here, _2;
	zval ns;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ns);
	ZVAL_UNDEF(&dir);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&here);
	ZVAL_UNDEF(&_2);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(ns)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(levels)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &ns_param, &levels_param);
	zephir_get_strval(&ns, ns_param);
	if (!levels_param) {
		levels = 1;
	} else {
		levels = zephir_get_intval(levels_param);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "\\");
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	ZEPHIR_CALL_FUNCTION(&dir, "strtr", NULL, 130, &ns, &_0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_2, levels);
	ZEPHIR_CALL_FUNCTION(&here, "dirname", NULL, 124, &dir, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "/");
	ZEPHIR_INIT_NVAR(&_1);
	ZVAL_STRING(&_1, "\\");
	ZEPHIR_RETURN_CALL_FUNCTION("strtr", NULL, 130, &here, &_0, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

