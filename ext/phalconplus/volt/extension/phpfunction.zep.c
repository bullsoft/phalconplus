
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Volt_Extension_PhpFunction) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Volt\\Extension, PhpFunction, phalconplus, volt_extension_phpfunction, phalconplus_volt_extension_phpfunction_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Volt_Extension_PhpFunction, compileFunction) {

	zval *params = NULL, *name = NULL, *_0$$3;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(params);
	array_init(params);
	ZEPHIR_CALL_FUNCTION(&params, "func_get_args", NULL, 42);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(params);
	ZEPHIR_CALL_FUNCTION(&name, "array_shift", NULL, 52, params);
	ZEPHIR_UNREF(params);
	zephir_check_call_status();
	ZEPHIR_MAKE_REF(params);
	ZEPHIR_CALL_FUNCTION(NULL, "array_pop", NULL, 57, params);
	ZEPHIR_UNREF(params);
	zephir_check_call_status();
	if ((zephir_function_exists(name TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_fast_join_str(_0$$3, SL(","), params TSRMLS_CC);
		ZEPHIR_CONCAT_VSVS(return_value, name, "(", _0$$3, ")");
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

