
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
#include "kernel/hash.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_ProtoBuffer) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Base, ProtoBuffer, phalconplus, base_protobuffer, phalconplus_base_protobuffer_method_entry, 0);

	zend_class_implements(phalconplus_base_protobuffer_ce TSRMLS_CC, 1, zephir_get_internal_ce(SS("jsonserializable") TSRMLS_CC));
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, softClone) {

	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_1;
	HashPosition _0;
	zval *data_param = NULL, *key = NULL, *val = NULL, **_2, *_3 = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(data, data_param);


	zephir_is_iterable(data, &_1, &_0, 0, 0, "phalconplus/Base/ProtoBuffer.zep", 14);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(val, _2);
		ZEPHIR_CALL_FUNCTION(&_3, "property_exists", &_4, this_ptr, key);
		zephir_check_call_status();
		if (zephir_is_true(_3)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", &_5, key, val);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __set) {

	zend_class_entry *_9;
	zephir_nts_static zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL, *_10 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *_2;
	zval *key_param = NULL, *val = NULL, *method, *param, *paramClass = NULL, *paramObj, *_0 = NULL, *_1, *_3 = NULL, *_5 = NULL, *_7 = NULL, *_8 = NULL, *_11;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &key_param, &val);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}
	ZEPHIR_SEPARATE_PARAM(val);


	ZEPHIR_INIT_VAR(_1);
	zephir_ucfirst(_1, key);
	ZEPHIR_INIT_VAR(method);
	ZEPHIR_CONCAT_SV(method, "set", _1);
	if ((zephir_method_exists(this_ptr, method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_INIT_VAR(param);
		object_init_ex(param, zephir_get_internal_ce(SS("reflectionparameter") TSRMLS_CC));
		ZEPHIR_INIT_VAR(_2);
		zephir_create_array(_2, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_2, this_ptr);
		zephir_array_fast_append(_2, method);
		ZEPHIR_INIT_VAR(_3);
		ZVAL_LONG(_3, 0);
		ZEPHIR_CALL_METHOD(NULL, param, "__construct", &_4, _2, _3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5, param, "getclass", &_6);
		zephir_check_call_status();
		if (zephir_is_true(_5)) {
			ZEPHIR_CALL_METHOD(&_7, param, "getclass", &_6);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&paramClass, _7, "getname", NULL);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(paramObj);
			zephir_fetch_safe_class(_8, paramClass);
			_9 = zend_fetch_class(Z_STRVAL_P(_8), Z_STRLEN_P(_8), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
			object_init_ex(paramObj, _9);
			if (zephir_has_constructor(paramObj TSRMLS_CC)) {
				ZEPHIR_CALL_METHOD(NULL, paramObj, "__construct", NULL);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(NULL, paramObj, "softclone", NULL, val);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(val, paramObj);
		}
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, method, NULL, val);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_5, "is_scalar", &_10, val);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		zephir_update_property_zval_zval(this_ptr, key, val TSRMLS_CC);
		RETURN_THIS();
	} else {
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_11);
		ZEPHIR_CONCAT_SVS(_11, "Please add ", method, " in your class, complex-type vars are not allowed to assign directly");
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_12, _11);
		zephir_check_call_status();
		zephir_throw_exception_debug(_3, "phalconplus/Base/ProtoBuffer.zep", 38 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_1 = NULL;
	zval *key_param = NULL, *_0 = NULL;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_CALL_FUNCTION(&_0, "property_exists", &_1, this_ptr, key);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __get) {

	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *method, *_0 = NULL, *_1, *_2 = NULL, *_4;
	zval *key = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &key_param);

	if (unlikely(Z_TYPE_P(key_param) != IS_STRING && Z_TYPE_P(key_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'key' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(key_param) == IS_STRING)) {
		zephir_get_strval(key, key_param);
	} else {
		ZEPHIR_INIT_VAR(key);
		ZVAL_EMPTY_STRING(key);
	}


	ZEPHIR_INIT_VAR(_1);
	zephir_ucfirst(_1, key);
	ZEPHIR_INIT_VAR(method);
	ZEPHIR_CONCAT_SV(method, "get", _1);
	if ((zephir_method_exists(this_ptr, method TSRMLS_CC)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, method, NULL);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_2, "property_exists", &_3, this_ptr, key);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZEPHIR_OBS_VAR(_4);
		zephir_read_property_zval(&_4, this_ptr, key, PH_NOISY_CC);
		RETURN_CCTOR(_4);
	}
	RETURN_MM_NULL();

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, getSelfVars) {

	HashTable *_3;
	HashPosition _2;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *objReflection = NULL, *vars, *pros = NULL, *pro = NULL, **_4, *_5 = NULL, *_6 = NULL, *_7 = NULL;

	ZEPHIR_MM_GROW();
	ZEPHIR_INIT_VAR(objReflection);
	ZVAL_NULL(objReflection);
	ZEPHIR_INIT_VAR(vars);
	array_init(vars);
	ZEPHIR_INIT_VAR(pros);
	array_init(pros);
	ZEPHIR_INIT_VAR(pro);
	ZVAL_NULL(pro);

	ZEPHIR_INIT_NVAR(objReflection);
	object_init_ex(objReflection, zephir_get_internal_ce(SS("reflectionobject") TSRMLS_CC));
	ZEPHIR_CALL_METHOD(NULL, objReflection, "__construct", &_0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&pros, objReflection, "getproperties", &_1);
	zephir_check_call_status();
	zephir_is_iterable(pros, &_3, &_2, 0, 0, "phalconplus/Base/ProtoBuffer.zep", 78);
	for (
	  ; zephir_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
	  ; zephir_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(pro, _4);
		ZEPHIR_INIT_NVAR(_5);
		ZVAL_BOOL(_5, 1);
		ZEPHIR_CALL_METHOD(NULL, pro, "setaccessible", NULL, _5);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_6, pro, "getvalue", NULL, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_7, pro, "getname", NULL);
		zephir_check_call_status();
		zephir_array_update_zval(&vars, _7, &_6, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(vars);

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, jsonSerialize) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "toarray", NULL);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, toArray) {

	zephir_nts_static zephir_fcall_cache_entry *_7 = NULL;
	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *isArray_param = NULL, *data_param = NULL, *pros = NULL, *newPros, *key = NULL, *val = NULL, **_2, *_5 = NULL, _6 = zval_used_for_init;
	zend_bool isArray, _3, _4;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &isArray_param, &data_param);

	if (!isArray_param) {
		isArray = 0;
	} else {
		isArray = zephir_get_boolval(isArray_param);
	}
	if (!data_param) {
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	} else {
		zephir_get_arrval(data, data_param);
	}
	ZEPHIR_INIT_VAR(pros);
	array_init(pros);
	ZEPHIR_INIT_VAR(newPros);
	array_init(newPros);


	if (isArray == 0) {
		ZEPHIR_CALL_METHOD(&pros, this_ptr, "getselfvars", NULL);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(pros, data);
	}
	zephir_is_iterable(pros, &_1, &_0, 0, 0, "phalconplus/Base/ProtoBuffer.zep", 110);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(val, _2);
		_3 = Z_TYPE_P(val) == IS_OBJECT;
		if (_3) {
			_3 = (zephir_method_exists_ex(val, SS("toarray") TSRMLS_CC) == SUCCESS);
		}
		_4 = Z_TYPE_P(val) == IS_OBJECT;
		if (_4) {
			_4 = (zephir_method_exists_ex(val, SS("__tostring") TSRMLS_CC) == SUCCESS);
		}
		if (Z_TYPE_P(val) == IS_ARRAY) {
			ZEPHIR_SINIT_NVAR(_6);
			ZVAL_BOOL(&_6, 1);
			ZEPHIR_CALL_METHOD(&_5, this_ptr, "toarray", &_7, &_6, val);
			zephir_check_call_status();
			zephir_array_update_zval(&newPros, key, &_5, PH_COPY | PH_SEPARATE);
		} else if (_3) {
			ZEPHIR_CALL_METHOD(&_5, val, "toarray", NULL);
			zephir_check_call_status();
			zephir_array_update_zval(&newPros, key, &_5, PH_COPY | PH_SEPARATE);
		} else if (_4) {
			ZEPHIR_CALL_METHOD(&_5, val, "__tostring", NULL);
			zephir_check_call_status();
			zephir_array_update_zval(&newPros, key, &_5, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&newPros, key, &val, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(newPros);

}

