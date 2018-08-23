
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_AbstractModule) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Base, AbstractModule, phalconplus, base_abstractmodule, phalconplus_base_abstractmodule_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalconplus_base_abstractmodule_ce, SL("di"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_abstractmodule_ce, SL("def"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_AbstractModule, __construct) {

	zval *di, di_sub, *def = NULL, def_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);
	ZVAL_UNDEF(&def_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params(0, 1, 1, &di, &def);

	if (!def) {
		def = &def_sub;
		def = &__$null;
	}


	zephir_update_property_zval(this_ptr, SL("di"), di);
	zephir_update_property_zval(this_ptr, SL("def"), def);

}

PHP_METHOD(PhalconPlus_Base_AbstractModule, getDef) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "def");

}

PHP_METHOD(PhalconPlus_Base_AbstractModule, isPrimary) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("def"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getisprimary", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_TRUE(&_1));

}

PHP_METHOD(PhalconPlus_Base_AbstractModule, registerAutoloaders) {

}

PHP_METHOD(PhalconPlus_Base_AbstractModule, registerServices) {

}

