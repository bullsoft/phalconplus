
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


ZEPHIR_INIT_CLASS(phalconplus_1__closure) {

	ZEPHIR_REGISTER_CLASS(phalconplus, 1__closure, phalconplus, 1__closure, phalconplus_1__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phalconplus_1__closure, __invoke) {

	zval *elem, elem_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&elem_sub);

	zephir_fetch_params(0, 1, 0, &elem);



	RETURN_BOOL(!(ZEPHIR_IS_EMPTY(elem)));

}

