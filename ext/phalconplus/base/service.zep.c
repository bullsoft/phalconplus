
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_Service) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Base, Service, phalconplus, base_service, phalconplus_base_service_method_entry, 0);

	/**
	 * @var <\Phalcon\DI>
	 */
	zend_declare_property_null(phalconplus_base_service_ce, SL("di"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_Service, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *di, di_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&di_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &di);



	zephir_update_property_zval(this_ptr, ZEND_STRL("di"), di);
	ZEPHIR_CALL_FUNCTION(NULL, "ob_start", NULL, 49);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "onconstruct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "ob_end_clean", NULL, 79);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_Service, onConstruct) {

	zval *this_ptr = getThis();



}

PHP_METHOD(PhalconPlus_Base_Service, getDI) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "di");

}

PHP_METHOD(PhalconPlus_Base_Service, __get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0, _1$$3, _2$$4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
		ZVAL_EMPTY_STRING(&key);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "property_exists", NULL, 3, this_ptr, &key);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_OBS_VAR(&_1$$3);
		zephir_read_property_zval(&_1$$3, this_ptr, &key, PH_NOISY_CC);
		RETURN_CCTOR(&_1$$3);
	} else {
		zephir_read_property(&_2$$4, this_ptr, ZEND_STRL("di"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_RETURN_CALL_METHOD(&_2$$4, "get", NULL, 0, &key);
		zephir_check_call_status();
		RETURN_MM();
	}

}

