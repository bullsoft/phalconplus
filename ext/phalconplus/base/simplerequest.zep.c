
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_SimpleRequest) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, SimpleRequest, phalconplus, base_simplerequest, phalconplus_base_abstractrequest_ce, phalconplus_base_simplerequest_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalconplus_base_simplerequest_ce, SL("params"), ZEND_ACC_PRIVATE);

	phalconplus_base_simplerequest_ce->create_object = zephir_init_properties_PhalconPlus_Base_SimpleRequest;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, softClone) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, key, val, *_0, _1, _4$$3, _7$$6;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	zephir_is_iterable(&data, 0, "phalconplus/Base/SimpleRequest.zep", 20);
	if (Z_TYPE_P(&data) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&data), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _0);
			ZEPHIR_CALL_FUNCTION(&_4$$3, "property_exists", &_5, 15, this_ptr, &key);
			zephir_check_call_status();
			if (zephir_is_true(&_4$$3)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", &_6, 0, &key, &val);
				zephir_check_call_status();
			} else {
				zephir_update_property_array(this_ptr, SL("params"), &key, &val);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &data, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &data, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &data, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&val, &data, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_FUNCTION(&_7$$6, "property_exists", &_5, 15, this_ptr, &key);
				zephir_check_call_status();
				if (zephir_is_true(&_7$$6)) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", &_6, 0, &key, &val);
					zephir_check_call_status();
				} else {
					zephir_update_property_array(this_ptr, SL("params"), &key, &val);
				}
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, getParam) {

	zval *idx, idx_sub, *defaultValue = NULL, defaultValue_sub, __$null, val, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&idx_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 1, &idx, &defaultValue);

	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&val, &_0, idx, 1)) {
		RETURN_CTORW(&val);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	return;

}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, hasParam) {

	zval *idx, idx_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&idx_sub);
	ZVAL_UNDEF(&_0);

	zephir_fetch_params_without_memory_grow(1, 0, &idx);



	zephir_read_property(&_0, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, idx)) {
		RETURN_BOOL(1);
	} else {
		RETURN_BOOL(0);
	}

}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, setParams) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *params_param = NULL;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	zephir_get_arrval(&params, params_param);


	zephir_update_property_zval(this_ptr, SL("params"), &params);
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, setParam) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *val, val_sub, *key = NULL, key_sub, __$null, _0$$4;
	zval *this_ptr = getThis();

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
		zephir_update_property_array(this_ptr, SL("params"), key, val);
	} else {
		zephir_read_property(&_0$$4, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_MAKE_REF(&_0$$4);
		ZEPHIR_CALL_FUNCTION(NULL, "array_push", NULL, 61, &_0$$4, val);
		ZEPHIR_UNREF(&_0$$4);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, getParams) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "params");

}

zend_object *zephir_init_properties_PhalconPlus_Base_SimpleRequest(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("params"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

