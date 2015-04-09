
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
#include "kernel/concat.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Volt_Extension_PhpFunction) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Volt\\Extension, PhpFunction, phalconplus, volt_extension_phpfunction, phalconplus_volt_extension_phpfunction_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Volt_Extension_PhpFunction, compileFunction) {

	zval *name_param = NULL, *arguments_param = NULL;
	zval *name = NULL, *arguments = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &arguments_param);

	zephir_get_strval(name, name_param);
	zephir_get_strval(arguments, arguments_param);


	if ((zephir_function_exists(name TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_CONCAT_VSVS(return_value, name, "(", arguments, ")");
		RETURN_MM();
	} else {
		RETURN_MM_STRING("", 1);
	}

}

