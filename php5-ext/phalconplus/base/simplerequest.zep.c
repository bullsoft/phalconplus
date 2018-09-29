
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_SimpleRequest) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, SimpleRequest, phalconplus, base_simplerequest, phalconplus_base_abstractrequest_ce, phalconplus_base_simplerequest_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalconplus_base_simplerequest_ce, SL("params"), ZEND_ACC_PRIVATE TSRMLS_CC);

	phalconplus_base_simplerequest_ce->create_object = zephir_init_properties_PhalconPlus_Base_SimpleRequest;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, softClone) {

	HashTable *_1;
	HashPosition _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	zval *data_param = NULL, *key = NULL, *val = NULL, **_2, *_3$$3 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(data, data_param);


	zephir_is_iterable(data, &_1, &_0, 0, 0, "phalconplus/Base/SimpleRequest.zep", 20);
	for (
	  ; zend_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zend_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(val, _2);
		ZEPHIR_CALL_FUNCTION(&_3$$3, "property_exists", &_4, 1, this_ptr, key);
		zephir_check_call_status();
		if (zephir_is_true(_3$$3)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", &_5, 0, key, val);
			zephir_check_call_status();
		} else {
			zephir_update_property_array(this_ptr, SL("params"), key, val TSRMLS_CC);
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, getParam) {

	zval *idx, *val = NULL, *_0;

	zephir_fetch_params(0, 1, 0, &idx);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
	if (zephir_array_isset_fetch(&val, _0, idx, 1 TSRMLS_CC)) {
		RETURN_CTORW(val);
	}

}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, setParams) {

	zval *params_param = NULL;
	zval *params = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	zephir_get_arrval(params, params_param);


	zephir_update_property_this(getThis(), SL("params"), params TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, setParam) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *val, *key = NULL, *_0$$4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &val, &key);

	if (!key) {
		key = ZEPHIR_GLOBAL(global_null);
	}


	if (!(Z_TYPE_P(key) == IS_NULL)) {
		zephir_update_property_array(this_ptr, SL("params"), key, val TSRMLS_CC);
	} else {
		_0$$4 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
		ZEPHIR_MAKE_REF(_0$$4);
		ZEPHIR_CALL_FUNCTION(NULL, "array_push", NULL, 45, _0$$4, val);
		ZEPHIR_UNREF(_0$$4);
		zephir_check_call_status();
	}
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, getParams) {

	

	RETURN_MEMBER(getThis(), "params");

}

zend_object_value zephir_init_properties_PhalconPlus_Base_SimpleRequest(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval zthis       = zval_used_for_init;
		zval *this_ptr   = &zthis;
		zend_object* obj = ecalloc(1, sizeof(zend_object));
		zend_object_value retval;

		zend_object_std_init(obj, class_type TSRMLS_CC);
		object_properties_init(obj, class_type);
		retval.handle   = zend_objects_store_put(obj, (zend_objects_store_dtor_t)zend_objects_destroy_object, zephir_free_object_storage, NULL TSRMLS_CC);
		retval.handlers = zend_get_std_object_handlers();

		Z_TYPE(zthis)   = IS_OBJECT;
		Z_OBJVAL(zthis) = retval;

		_0 = zephir_fetch_nproperty_this(this_ptr, SL("params"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(getThis(), SL("params"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return retval;
	}

}

