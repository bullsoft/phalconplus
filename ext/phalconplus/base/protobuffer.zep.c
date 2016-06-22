
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

	HashTable *_1;
	HashPosition _0;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL;
	zval *data_param = NULL, *key = NULL, *val = NULL, **_2, *_3$$3 = NULL;
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
		ZEPHIR_CALL_FUNCTION(&_3$$3, "property_exists", &_4, 1, this_ptr, key);
		zephir_check_call_status();
		if (zephir_is_true(_3$$3)) {
			ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", &_5, 0, key, val);
			zephir_check_call_status();
		}
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __set) {

	zval *_2$$3;
	zend_bool _8;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *val = NULL, *method = NULL, *param = NULL, *paramClass = NULL, *paramClassRef = NULL, *paramObj = NULL, *_0 = NULL, *_1, *_3$$3, *_4$$3 = NULL, *_5$$4 = NULL, *_6$$4 = NULL, *_7$$4, *_9$$8, *_10$$8;
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
		ZEPHIR_INIT_VAR(_2$$3);
		zephir_create_array(_2$$3, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(_2$$3, this_ptr);
		zephir_array_fast_append(_2$$3, method);
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_LONG(_3$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, param, "__construct", NULL, 2, _2$$3, _3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, param, "getclass", NULL, 3);
		zephir_check_call_status();
		if (zephir_is_true(_4$$3)) {
			ZEPHIR_CALL_METHOD(&_5$$4, param, "getclass", NULL, 3);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&paramClass, _5$$4, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(paramClassRef);
			object_init_ex(paramClassRef, zephir_get_internal_ce(SS("reflectionclass") TSRMLS_CC));
			ZEPHIR_CALL_METHOD(NULL, paramClassRef, "__construct", NULL, 4, paramClass);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_7$$4);
			ZVAL_STRING(_7$$4, "\\PhalconPlus\\Base\\ProtoBuffer", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_METHOD(&_6$$4, paramClassRef, "issubclassof", NULL, 5, _7$$4);
			zephir_check_temp_parameter(_7$$4);
			zephir_check_call_status();
			if (zephir_is_true(_6$$4)) {
				ZEPHIR_CALL_METHOD(&paramObj, paramClassRef, "newinstance", NULL, 6);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, paramObj, "softclone", NULL, 0, val);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(val, paramObj);
			} else {
				ZEPHIR_CALL_METHOD(&paramObj, paramClassRef, "newinstance", NULL, 6, val);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(val, paramObj);
			}
		}
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, method, NULL, 0, val);
		zephir_check_call_status();
		RETURN_MM();
	}
	_8 = zephir_is_scalar(val);
	if (!(_8)) {
		_8 = Z_TYPE_P(val) == IS_ARRAY;
	}
	if (_8) {
		zephir_update_property_zval_zval(this_ptr, key, val TSRMLS_CC);
		RETURN_THIS();
	} else {
		ZEPHIR_INIT_VAR(_9$$8);
		object_init_ex(_9$$8, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(_10$$8);
		ZEPHIR_CONCAT_SVS(_10$$8, "Please add ", method, " in your class, complex-type vars are not allowed to assign directly");
		ZEPHIR_CALL_METHOD(NULL, _9$$8, "__construct", NULL, 7, _10$$8);
		zephir_check_call_status();
		zephir_throw_exception_debug(_9$$8, "phalconplus/Base/ProtoBuffer.zep", 46 TSRMLS_CC);
		ZEPHIR_MM_RESTORE();
		return;
	}

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __isset) {

	int ZEPHIR_LAST_CALL_STATUS;
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


	ZEPHIR_CALL_FUNCTION(&_0, "property_exists", NULL, 1, this_ptr, key);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __get) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *method = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3$$4;
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
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_2, "property_exists", NULL, 1, this_ptr, key);
	zephir_check_call_status();
	if (zephir_is_true(_2)) {
		ZEPHIR_OBS_VAR(_3$$4);
		zephir_read_property_zval(&_3$$4, this_ptr, key, PH_NOISY_CC);
		RETURN_CCTOR(_3$$4);
	}
	RETURN_MM_NULL();

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, getSelfVars) {

	HashTable *_1;
	HashPosition _0;
	zval *objReflection = NULL, *vars = NULL, *pros = NULL, *pro = NULL, **_2, *_3$$3 = NULL, *_4$$3 = NULL, *_5$$3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

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
	ZEPHIR_CALL_METHOD(NULL, objReflection, "__construct", NULL, 8, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&pros, objReflection, "getproperties", NULL, 9);
	zephir_check_call_status();
	zephir_is_iterable(pros, &_1, &_0, 0, 0, "phalconplus/Base/ProtoBuffer.zep", 86);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(pro, _2);
		ZEPHIR_INIT_NVAR(_3$$3);
		ZVAL_BOOL(_3$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, pro, "setaccessible", NULL, 0, _3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, pro, "getvalue", NULL, 0, this_ptr);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_5$$3, pro, "getname", NULL, 0);
		zephir_check_call_status();
		zephir_array_update_zval(&vars, _5$$3, &_4$$3, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(vars);

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, jsonSerialize) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, toArray) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_7 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *data = NULL;
	zval *isArray_param = NULL, *data_param = NULL, *pros = NULL, *newPros = NULL, *key = NULL, *val = NULL, **_2, *_5$$6 = NULL, *_6$$6 = NULL, *_8$$7 = NULL, *_9$$8 = NULL;
	zend_bool isArray, _3$$5, _4$$5;

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
		ZEPHIR_CALL_METHOD(&pros, this_ptr, "getselfvars", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(pros, data);
	}
	zephir_is_iterable(pros, &_1, &_0, 0, 0, "phalconplus/Base/ProtoBuffer.zep", 118);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(val, _2);
		_3$$5 = Z_TYPE_P(val) == IS_OBJECT;
		if (_3$$5) {
			_3$$5 = (zephir_method_exists_ex(val, SS("toarray") TSRMLS_CC) == SUCCESS);
		}
		_4$$5 = Z_TYPE_P(val) == IS_OBJECT;
		if (_4$$5) {
			_4$$5 = (zephir_method_exists_ex(val, SS("__tostring") TSRMLS_CC) == SUCCESS);
		}
		if (Z_TYPE_P(val) == IS_ARRAY) {
			ZEPHIR_INIT_NVAR(_6$$6);
			ZVAL_BOOL(_6$$6, 1);
			ZEPHIR_CALL_METHOD(&_5$$6, this_ptr, "toarray", &_7, 10, _6$$6, val);
			zephir_check_call_status();
			zephir_array_update_zval(&newPros, key, &_5$$6, PH_COPY | PH_SEPARATE);
		} else if (_3$$5) {
			ZEPHIR_CALL_METHOD(&_8$$7, val, "toarray", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_zval(&newPros, key, &_8$$7, PH_COPY | PH_SEPARATE);
		} else if (_4$$5) {
			ZEPHIR_CALL_METHOD(&_9$$8, val, "__tostring", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_zval(&newPros, key, &_9$$8, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_zval(&newPros, key, &val, PH_COPY | PH_SEPARATE);
		}
	}
	RETURN_CCTOR(newPros);

}

