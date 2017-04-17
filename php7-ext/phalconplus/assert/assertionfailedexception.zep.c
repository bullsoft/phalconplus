
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Assert_AssertionFailedException) {

	ZEPHIR_REGISTER_INTERFACE(PhalconPlus\\Assert, AssertionFailedException, phalconplus, assert_assertionfailedexception, phalconplus_assert_assertionfailedexception_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(PhalconPlus_Assert_AssertionFailedException, __construct);

ZEPHIR_DOC_METHOD(PhalconPlus_Assert_AssertionFailedException, getPropertyPath);

ZEPHIR_DOC_METHOD(PhalconPlus_Assert_AssertionFailedException, getValue);

ZEPHIR_DOC_METHOD(PhalconPlus_Assert_AssertionFailedException, getConstraints);

