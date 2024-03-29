
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_SimpleRequest)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, SimpleRequest, phalconplus, base_simplerequest, phalconplus_base_abstractrequest_ce, phalconplus_base_simplerequest_method_entry, ZEND_ACC_FINAL_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalconplus_base_simplerequest_ce, SL("params"), ZEND_ACC_PRIVATE);
	phalconplus_base_simplerequest_ce->create_object = zephir_init_properties_PhalconPlus_Base_SimpleRequest;

	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, softClone)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool deep;
	zval *data_param = NULL, *deep_param = NULL, key, val, *_0, _1;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_1);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ARRAY(data)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(deep)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data_param, &deep_param);
	zephir_get_arrval(&data, data_param);
	if (!deep_param) {
		deep = 0;
	} else {
		deep = zephir_get_boolval(deep_param);
	}


	zephir_is_iterable(&data, 0, "phalconplus/Base/SimpleRequest.zep", 17);
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
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", &_4, 83, &key, &val);
			zephir_check_call_status();
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
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", &_4, 83, &key, &val);
				zephir_check_call_status();
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_THIS();
}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, getSelfVars)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "params");
}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, getParam)
{
	zval *idx, idx_sub, *defaultValue = NULL, defaultValue_sub, __$null, val, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&idx_sub);
	ZVAL_UNDEF(&defaultValue_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(idx)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(defaultValue)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 1, &idx, &defaultValue);
	if (!defaultValue) {
		defaultValue = &defaultValue_sub;
		defaultValue = &__$null;
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset_fetch(&val, &_0, idx, 1)) {
		RETURN_CTORW(&val);
	}
	RETVAL_ZVAL(defaultValue, 1, 0);
	return;
}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, hasParam)
{
	zval *idx, idx_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&idx_sub);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(idx)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &idx);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, idx)) {
		RETURN_BOOL(1);
	} else {
		RETURN_BOOL(0);
	}
}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, setParams)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *params_param = NULL;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY(params)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);
	zephir_get_arrval(&params, params_param);


	zephir_update_property_zval(this_ptr, ZEND_STRL("params"), &params);
	RETURN_THIS();
}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, setParam)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *val, val_sub, *key = NULL, key_sub, __$null, _0$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&val_sub);
	ZVAL_UNDEF(&key_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_ZVAL(val)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &val, &key);
	if (!key) {
		key = &key_sub;
		key = &__$null;
	}


	if (!(Z_TYPE_P(key) == IS_NULL)) {
		zephir_update_property_array(this_ptr, SL("params"), key, val);
	} else {
		zephir_read_property(&_0$$4, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_MAKE_REF(&_0$$4);
		ZEPHIR_CALL_FUNCTION(NULL, "array_push", NULL, 78, &_0$$4, val);
		ZEPHIR_UNREF(&_0$$4);
		zephir_check_call_status();
	}
	RETURN_THIS();
}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, getParams)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "params");
}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, __set)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, *val, val_sub;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(key)
		Z_PARAM_ZVAL(val)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &val);
	if (UNEXPECTED(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(&key, key_param);
	} else {
		ZEPHIR_INIT_VAR(&key);
	}


	zephir_update_property_array(this_ptr, SL("params"), &key, val);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, __isset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &key)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);
}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, __get)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _0, _1$$3, _2$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &key)) {
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		zephir_array_fetch(&_2$$3, &_1$$3, &key, PH_NOISY | PH_READONLY, "phalconplus/Base/SimpleRequest.zep", 80);
		RETURN_CTOR(&_2$$3);
	}
	RETURN_MM_NULL();
}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, __unset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *key_param = NULL, _0, _1$$3;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();
#endif


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
	}


	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
	if (zephir_array_isset(&_0, &key)) {
		zephir_unset_property_array(this_ptr, ZEND_STRL("params"), &key);
		zephir_read_property(&_1$$3, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		zephir_array_unset(&_1$$3, &key, PH_SEPARATE);
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(PhalconPlus_Base_SimpleRequest, isEmpty)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC);
	RETURN_MM_BOOL(ZEPHIR_IS_EMPTY(&_0));
}

zend_object *zephir_init_properties_PhalconPlus_Base_SimpleRequest(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("params"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("params"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

