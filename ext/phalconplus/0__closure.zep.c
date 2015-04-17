
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
#include "kernel/exception.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(phalconplus_0__closure) {

	ZEPHIR_REGISTER_CLASS(phalconplus, 0__closure, phalconplus, 0__closure, phalconplus_0__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phalconplus_0__closure, __invoke) {

	zval *file, *line, *code, *desc;

	zephir_fetch_params(0, 4, 0, &file, &line, &code, &desc);



	ZEPHIR_THROW_EXCEPTION_DEBUG_STRW(zend_exception_get_default(TSRMLS_C), "fdfadf", "phalconplus/Assertion.zep", 20);
	return;

}

