
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Volt_Extension_PhpFunction) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Volt\\Extension, PhpFunction, phalconplus, volt_extension_phpfunction, phalconplus_volt_extension_phpfunction_method_entry, 0);

	zend_declare_property_string(phalconplus_volt_extension_phpfunction_ce, SL("ns"), "", ZEND_ACC_PRIVATE);

	zend_declare_property_string(phalconplus_volt_extension_phpfunction_ce, SL("func"), "__invoke__", ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Volt_Extension_PhpFunction, setCustNamespace) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *ns_param = NULL;
	zval ns;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ns);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &ns_param);

	if (UNEXPECTED(Z_TYPE_P(ns_param) != IS_STRING && Z_TYPE_P(ns_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'ns' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(ns_param) == IS_STRING)) {
		zephir_get_strval(&ns, ns_param);
	} else {
		ZEPHIR_INIT_VAR(&ns);
		ZVAL_EMPTY_STRING(&ns);
	}


	zephir_update_property_zval(this_ptr, SL("ns"), &ns);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Volt_Extension_PhpFunction, setCustFuncName) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *func_param = NULL;
	zval func;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&func);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &func_param);

	if (UNEXPECTED(Z_TYPE_P(func_param) != IS_STRING && Z_TYPE_P(func_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'func' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(func_param) == IS_STRING)) {
		zephir_get_strval(&func, func_param);
	} else {
		ZEPHIR_INIT_VAR(&func);
		ZVAL_EMPTY_STRING(&func);
	}


	if (!(ZEPHIR_IS_EMPTY(&func))) {
		zephir_update_property_zval(this_ptr, SL("func"), &func);
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Volt_Extension_PhpFunction, compileFunction) {

	zval params, name, args, code, _0, pos$$3, _1$$3, _8$$3, _2$$4, _3$$5, _4$$5, _5$$5, _6$$5, _7$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&args);
	ZVAL_UNDEF(&code);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&pos$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&params);
	array_init(&params);
	ZEPHIR_INIT_NVAR(&params);
	zephir_get_args(&params);
	ZEPHIR_MAKE_REF(&params);
	ZEPHIR_CALL_FUNCTION(&name, "array_shift", NULL, 94, &params);
	ZEPHIR_UNREF(&params);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(&params);
	ZEPHIR_CALL_FUNCTION(NULL, "array_pop", NULL, 126, &params);
	ZEPHIR_UNREF(&params);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&args);
	zephir_fast_join_str(&args, SL(","), &params);
	zephir_read_property(&_0, this_ptr, SL("func"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EQUAL(&name, &_0)) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, ",");
		ZEPHIR_INIT_VAR(&pos$$3);
		zephir_fast_strpos(&pos$$3, &args, &_1$$3, 0 );
		if (ZEPHIR_IS_FALSE_IDENTICAL(&pos$$3)) {
			ZEPHIR_INIT_VAR(&_2$$4);
			ZVAL_STRING(&_2$$4, "'\"");
			ZEPHIR_INIT_NVAR(&name);
			zephir_fast_trim(&name, &args, &_2$$4, ZEPHIR_TRIM_BOTH);
			ZEPHIR_INIT_NVAR(&args);
			ZVAL_STRING(&args, "");
		} else {
			ZVAL_LONG(&_3$$5, 0);
			ZEPHIR_INIT_VAR(&_4$$5);
			zephir_substr(&_4$$5, &args, 0 , zephir_get_intval(&pos$$3), 0);
			ZEPHIR_INIT_VAR(&_5$$5);
			ZVAL_STRING(&_5$$5, "'\"");
			ZEPHIR_INIT_NVAR(&name);
			zephir_fast_trim(&name, &_4$$5, &_5$$5, ZEPHIR_TRIM_BOTH);
			ZVAL_LONG(&_6$$5, (zephir_get_numberval(&pos$$3) + 1));
			ZEPHIR_INIT_VAR(&_7$$5);
			zephir_substr(&_7$$5, &args, zephir_get_intval(&_6$$5), 0, ZEPHIR_SUBSTR_NO_LENGTH);
			ZEPHIR_CPY_WRT(&args, &_7$$5);
		}
		zephir_read_property(&_8$$3, this_ptr, SL("ns"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&code);
		ZEPHIR_CONCAT_VVSVS(&code, &_8$$3, &name, "(", &args, ")");
		RETURN_CCTOR(&code);
	}
	if ((zephir_function_exists(&name)  == SUCCESS)) {
		ZEPHIR_INIT_NVAR(&code);
		ZEPHIR_CONCAT_VSVS(&code, &name, "(", &args, ")");
		RETURN_CCTOR(&code);
	}
	ZEPHIR_MM_RESTORE();

}

