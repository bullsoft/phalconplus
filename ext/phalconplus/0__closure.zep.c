
#ifdef HAVE_CONFIG_H
#include "../ext_config.h"
#endif

#include <php.h>
#include "../php_ext.h"
#include "../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(phalconplus_0__closure)
{
	ZEPHIR_REGISTER_CLASS(phalconplus, 0__closure, phalconplus, 0__closure, phalconplus_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;
}

PHP_METHOD(phalconplus_0__closure, __invoke)
{
	zval *freq, freq_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&freq_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(freq)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &freq);


	RETURN_BOOL(ZEPHIR_GT_LONG(freq, 1));
}

