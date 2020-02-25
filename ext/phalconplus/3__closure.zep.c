
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
#include "kernel/fcall.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(phalconplus_3__closure) {

	ZEPHIR_REGISTER_CLASS(phalconplus, 3__closure, phalconplus, 3__closure, phalconplus_3__closure_method_entry, ZEND_ACC_FINAL_CLASS);

	return SUCCESS;

}

PHP_METHOD(phalconplus_3__closure, __invoke) {

	zval acl, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&acl);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&acl);
	object_init_ex(&acl, zephir_get_internal_ce(SL("phalcon\\acl\\adapter\\memory")));
	ZEPHIR_CALL_METHOD(NULL, &acl, "__construct", NULL, 0);
	zephir_check_call_status();
	ZVAL_LONG(&_0, 0);
	ZEPHIR_CALL_METHOD(NULL, &acl, "setdefaultaction", NULL, 0, &_0);
	zephir_check_call_status();
	RETURN_CCTOR(&acl);

}

