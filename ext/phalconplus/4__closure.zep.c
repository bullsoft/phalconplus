
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
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(phalconplus_4__closure) {

	ZEPHIR_REGISTER_CLASS(phalconplus, 4__closure, phalconplus, 4__closure, phalconplus_4__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phalconplus_4__closure, __invoke) {

	zval *view, view_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&view_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &view);




}

