
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

	zend_declare_property_null(phalconplus_assert_invalidargumentexception_ce, SL("propertyPath"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phalconplus_assert_invalidargumentexception_ce, SL("value"), ZEND_ACC_PRIVATE);

	zend_declare_property_null(phalconplus_assert_invalidargumentexception_ce, SL("constraints"), ZEND_ACC_PRIVATE);

	zend_class_implements(phalconplus_assert_invalidargumentexception_ce, 1, phalconplus_assert_assertionfailedexception_ce);
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Assert_InvalidArgumentException, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval constraints;
	zval *message, message_sub, *code, code_sub, *propertyPath = NULL, propertyPath_sub, *value, value_sub, *constraints_param = NULL, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&code_sub);
	ZVAL_UNDEF(&propertyPath_sub);
	ZVAL_UNDEF(&value_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&constraints);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 2, &message, &code, &propertyPath, &value, &constraints_param);

	if (!propertyPath) {
		propertyPath = &propertyPath_sub;
		propertyPath = &__$null;
	}
	if (!constraints_param) {
		ZEPHIR_INIT_VAR(&constraints);
		array_init(&constraints);
	} else {
		zephir_get_arrval(&constraints, constraints_param);
	}


	ZEPHIR_CALL_PARENT(NULL, phalconplus_assert_invalidargumentexception_ce, getThis(), "__construct", NULL, 0, message, code);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("propertyPath"), propertyPath);
	zephir_update_property_zval(this_ptr, ZEND_STRL("value"), value);
	zephir_update_property_zval(this_ptr, ZEND_STRL("constraints"), &constraints);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Assert_InvalidArgumentException, getPropertyPath) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "propertyPath");

}

PHP_METHOD(PhalconPlus_Assert_InvalidArgumentException, getValue) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "value");

}

PHP_METHOD(PhalconPlus_Assert_InvalidArgumentException, getConstraints) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "constraints");

}

