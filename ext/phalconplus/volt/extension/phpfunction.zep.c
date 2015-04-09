
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Volt_Extension_PhpFunction) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Volt\\Extension, PhpFunction, phalconplus, volt_extension_phpfunction, phalconplus_volt_extension_phpfunction_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Volt_Extension_PhpFunction, compileFunction) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL, *_2 = NULL;
	zval *params = NULL, *name = NULL, *_3 = NULL, *_4;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(params);
	array_init(params);

	ZEPHIR_CALL_FUNCTION(&params, "func_get_args", &_0);
	zephir_check_call_status();
	Z_SET_ISREF_P(params);
	ZEPHIR_CALL_FUNCTION(&name, "array_shift", &_1, params);
	Z_UNSET_ISREF_P(params);
	zephir_check_call_status();
	Z_SET_ISREF_P(params);
	ZEPHIR_CALL_FUNCTION(NULL, "array_pop", &_2, params);
	Z_UNSET_ISREF_P(params);
	zephir_check_call_status();
	if ((zephir_function_exists(name TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_INIT_VAR(_4);
		ZVAL_STRING(_4, ",", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_3, params, "join", NULL, _4);
		zephir_check_temp_parameter(_4);
		zephir_check_call_status();
		ZEPHIR_CONCAT_VSVS(return_value, name, "(", _3, ")");
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

