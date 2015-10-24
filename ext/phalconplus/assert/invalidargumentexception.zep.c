
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Assert_InvalidArgumentException) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Assert, InvalidArgumentException, phalconplus, assert_invalidargumentexception, spl_ce_InvalidArgumentException, phalconplus_assert_invalidargumentexception_method_entry, 0);

	zend_declare_property_null(phalconplus_assert_invalidargumentexception_ce, SL("propertyPath"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_assert_invalidargumentexception_ce, SL("value"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_assert_invalidargumentexception_ce, SL("constraints"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_class_implements(phalconplus_assert_invalidargumentexception_ce TSRMLS_CC, 1, phalconplus_assert_assertionfailedexception_ce);
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Assert_InvalidArgumentException, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *constraints = NULL;
	zval *message, *code, *propertyPath = NULL, *value, *constraints_param = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &message, &code, &propertyPath, &value, &constraints_param);

	if (!propertyPath) {
		propertyPath = ZEPHIR_GLOBAL(global_null);
	}
	if (!constraints_param) {
		ZEPHIR_INIT_VAR(constraints);
		array_init(constraints);
	} else {
		zephir_get_arrval(constraints, constraints_param);
	}


	ZEPHIR_CALL_PARENT(NULL, phalconplus_assert_invalidargumentexception_ce, this_ptr, "__construct", NULL, 0, message, code);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("propertyPath"), propertyPath TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("value"), value TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("constraints"), constraints TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Assert_InvalidArgumentException, getPropertyPath) {

	

	RETURN_MEMBER(this_ptr, "propertyPath");

}

PHP_METHOD(PhalconPlus_Assert_InvalidArgumentException, getValue) {

	

	RETURN_MEMBER(this_ptr, "value");

}

PHP_METHOD(PhalconPlus_Assert_InvalidArgumentException, getConstraints) {

	

	RETURN_MEMBER(this_ptr, "constraints");

}

