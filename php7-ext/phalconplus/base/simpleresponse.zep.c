
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_SimpleResponse) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, SimpleResponse, phalconplus, base_simpleresponse, phalconplus_base_response_ce, phalconplus_base_simpleresponse_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalconplus_base_simpleresponse_ce, SL("result"), ZEND_ACC_PRIVATE TSRMLS_CC);

	phalconplus_base_simpleresponse_ce->create_object = zephir_init_properties_PhalconPlus_Base_SimpleResponse;
	return SUCCESS;

}

/**
 * @deprecated
 */
PHP_METHOD(PhalconPlus_Base_SimpleResponse, getResult) {

	zval _1;
	zval _0;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("result"), PH_NOISY_CC);
	zephir_get_arrval(&_1, &_0);
	RETURN_CTOR(_1);

}

PHP_METHOD(PhalconPlus_Base_SimpleResponse, setResult) {

	zval *result_param = NULL;
	zval result;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&result);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &result_param);

	if (!result_param) {
		ZEPHIR_INIT_VAR(&result);
		array_init(&result);
	} else {
		zephir_get_arrval(&result, result_param);
	}


	zephir_update_property_zval(this_ptr, SL("result"), &result);
	RETURN_THIS();

}

/**
 * @deprecated
 */
PHP_METHOD(PhalconPlus_Base_SimpleResponse, pushItem) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *val, val_sub, *key = NULL, key_sub, __$null, _0$$4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&val_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &val, &key);

	if (!key) {
		key = &key_sub;
		key = &__$null;
	}


	if (!(Z_TYPE_P(key) == IS_NULL)) {
		zephir_update_property_array(this_ptr, SL("result"), key, val TSRMLS_CC);
	} else {
		zephir_read_property(&_0$$4, this_ptr, SL("result"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_MAKE_REF(&_0$$4);
		ZEPHIR_CALL_FUNCTION(NULL, "array_push", NULL, 35, &_0$$4, val);
		ZEPHIR_UNREF(&_0$$4);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_SimpleResponse, setItem) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *val, val_sub, *key = NULL, key_sub, __$null, _0$$4;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&val_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &val, &key);

	if (!key) {
		key = &key_sub;
		key = &__$null;
	}


	if (!(Z_TYPE_P(key) == IS_NULL)) {
		zephir_update_property_array(this_ptr, SL("result"), key, val TSRMLS_CC);
	} else {
		zephir_read_property(&_0$$4, this_ptr, SL("result"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_MAKE_REF(&_0$$4);
		ZEPHIR_CALL_FUNCTION(NULL, "array_push", NULL, 35, &_0$$4, val);
		ZEPHIR_UNREF(&_0$$4);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_SimpleResponse, getItem) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key = NULL, key_sub, __$null, val$$3, _0$$3, _1$$5;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&key_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&val$$3);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &key);

	if (!key) {
		key = &key_sub;
		key = &__$null;
	}


	if (!(Z_TYPE_P(key) == IS_NULL)) {
		ZEPHIR_OBS_VAR(&val$$3);
		zephir_read_property(&_0$$3, this_ptr, SL("result"), PH_NOISY_CC | PH_READONLY);
		if (zephir_array_isset_fetch(&val$$3, &_0$$3, key, 0 TSRMLS_CC)) {
			RETURN_CCTOR(val$$3);
		}
	} else {
		zephir_read_property(&_1$$5, this_ptr, SL("result"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_MAKE_REF(&_1$$5);
		ZEPHIR_RETURN_CALL_FUNCTION("reset", NULL, 38, &_1$$5);
		ZEPHIR_UNREF(&_1$$5);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_MM_RESTORE();

}

zend_object *zephir_init_properties_PhalconPlus_Base_SimpleResponse(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("result"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("result"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

