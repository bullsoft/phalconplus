
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
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_ProtoBuffer) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Base, ProtoBuffer, phalconplus, base_protobuffer, phalconplus_base_protobuffer_method_entry, 0);

	zend_class_implements(phalconplus_base_protobuffer_ce, 1, zephir_get_internal_ce(SL("jsonserializable")));
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, softClone) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, key, val, *_0, _1, _4$$3, _7$$5;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_7$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_arrval(&data, data_param);


	zephir_is_iterable(&data, 0, "phalconplus/Base/ProtoBuffer.zep", 14);
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
			ZEPHIR_CALL_FUNCTION(&_4$$3, "property_exists", &_5, 3, this_ptr, &key);
			zephir_check_call_status();
			if (zephir_is_true(&_4$$3)) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", &_6, 0, &key, &val);
				zephir_check_call_status();
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
				ZEPHIR_CALL_FUNCTION(&_7$$5, "property_exists", &_5, 3, this_ptr, &key);
				zephir_check_call_status();
				if (zephir_is_true(&_7$$5)) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", &_6, 0, &key, &val);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __set) {

	zval _2$$3;
	zend_bool _8, _9, _10;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *val = NULL, val_sub, method, param, paramClass, paramClassRef, paramObj, _0, _1, _3$$3, _4$$3, _5$$4, _6$$4, _7$$4, _11$$9, _12$$9;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val_sub);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&paramClass);
	ZVAL_UNDEF(&paramClassRef);
	ZVAL_UNDEF(&paramObj);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_2$$3);

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
		ZVAL_EMPTY_STRING(&key);
	}
	ZEPHIR_SEPARATE_PARAM(val);


	ZEPHIR_INIT_VAR(&_1);
	zephir_ucfirst(&_1, &key);
	ZEPHIR_INIT_VAR(&method);
	ZEPHIR_CONCAT_SV(&method, "set", &_1);
	if ((zephir_method_exists(this_ptr, &method)  == SUCCESS)) {
		ZEPHIR_INIT_VAR(&param);
		object_init_ex(&param, zephir_get_internal_ce(SL("reflectionparameter")));
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 2, 0);
		zephir_array_fast_append(&_2$$3, this_ptr);
		zephir_array_fast_append(&_2$$3, &method);
		ZVAL_LONG(&_3$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &param, "__construct", NULL, 4, &_2$$3, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, &param, "getclass", NULL, 5);
		zephir_check_call_status();
		if (zephir_is_true(&_4$$3)) {
			ZEPHIR_CALL_METHOD(&_5$$4, &param, "getclass", NULL, 5);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&paramClass, &_5$$4, "getname", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&paramClassRef);
			object_init_ex(&paramClassRef, zephir_get_internal_ce(SL("reflectionclass")));
			ZEPHIR_CALL_METHOD(NULL, &paramClassRef, "__construct", NULL, 6, &paramClass);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(&_7$$4);
			ZVAL_STRING(&_7$$4, "\\PhalconPlus\\Base\\ProtoBuffer");
			ZEPHIR_CALL_METHOD(&_6$$4, &paramClassRef, "issubclassof", NULL, 7, &_7$$4);
			zephir_check_call_status();
			if (zephir_is_true(&_6$$4)) {
				ZEPHIR_CALL_METHOD(&paramObj, &paramClassRef, "newinstance", NULL, 8);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &paramObj, "softclone", NULL, 0, val);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(val, &paramObj);
			} else {
				ZEPHIR_CALL_METHOD(&paramObj, &paramClassRef, "newinstance", NULL, 8, val);
				zephir_check_call_status();
				ZEPHIR_CPY_WRT(val, &paramObj);
			}
		}
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &method, NULL, 0, val);
		zephir_check_call_status();
		RETURN_MM();
	}
	_8 = zephir_is_scalar(val);
	if (!(_8)) {
		_8 = Z_TYPE_P(val) == IS_NULL;
	}
	_9 = _8;
	if (!(_9)) {
		_9 = Z_TYPE_P(val) == IS_ARRAY;
	}
	_10 = Z_TYPE_P(val) == IS_OBJECT;
	if (_10) {
		_10 = zephir_instance_of_ev(val, phalconplus_base_protobuffer_ce);
	}
	if (_9) {
		zephir_update_property_zval_zval(this_ptr, &key, val);
		RETURN_THIS();
	} else if (_10) {
		zephir_update_property_zval_zval(this_ptr, &key, val);
		RETURN_THIS();
	} else {
		ZEPHIR_INIT_VAR(&_11$$9);
		object_init_ex(&_11$$9, zend_exception_get_default(TSRMLS_C));
		ZEPHIR_INIT_VAR(&_12$$9);
		ZEPHIR_CONCAT_SVS(&_12$$9, "Please add ", &method, " in your class, complex-type vars are not allowed to assign directly");
		ZEPHIR_CALL_METHOD(NULL, &_11$$9, "__construct", NULL, 9, &_12$$9);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_11$$9, "phalconplus/Base/ProtoBuffer.zep", 49);
		ZEPHIR_MM_RESTORE();
		return;
	}

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __isset) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, _0;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&_0);

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
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __get) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, method, _0, _1, _2, _3$$4;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$4);

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


	ZEPHIR_INIT_VAR(&_1);
	zephir_ucfirst(&_1, &key);
	ZEPHIR_INIT_VAR(&method);
	ZEPHIR_CONCAT_SV(&method, "get", &_1);
	if ((zephir_method_exists(this_ptr, &method)  == SUCCESS)) {
		ZEPHIR_RETURN_CALL_METHOD_ZVAL(this_ptr, &method, NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_FUNCTION(&_2, "property_exists", NULL, 3, this_ptr, &key);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_OBS_VAR(&_3$$4);
		zephir_read_property_zval(&_3$$4, this_ptr, &key, PH_NOISY_CC);
		RETURN_CCTOR(&_3$$4);
	}
	RETURN_MM_NULL();

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, getSelfVars) {

	zval objReflection, vars, pros, pro, *_0, _1, _2$$3, _3$$3, _4$$3, _5$$4, _6$$4, _7$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&objReflection);
	ZVAL_UNDEF(&vars);
	ZVAL_UNDEF(&pros);
	ZVAL_UNDEF(&pro);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&objReflection);
	ZVAL_NULL(&objReflection);
	ZEPHIR_INIT_VAR(&vars);
	array_init(&vars);
	ZEPHIR_INIT_VAR(&pros);
	array_init(&pros);
	ZEPHIR_INIT_VAR(&pro);
	ZVAL_NULL(&pro);
	ZEPHIR_INIT_NVAR(&objReflection);
	object_init_ex(&objReflection, zephir_get_internal_ce(SL("reflectionobject")));
	ZEPHIR_CALL_METHOD(NULL, &objReflection, "__construct", NULL, 10, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&pros, &objReflection, "getproperties", NULL, 11);
	zephir_check_call_status();
	zephir_is_iterable(&pros, 0, "phalconplus/Base/ProtoBuffer.zep", 89);
	if (Z_TYPE_P(&pros) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&pros), _0)
		{
			ZEPHIR_INIT_NVAR(&pro);
			ZVAL_COPY(&pro, _0);
			ZVAL_BOOL(&_2$$3, 1);
			ZEPHIR_CALL_METHOD(NULL, &pro, "setaccessible", NULL, 0, &_2$$3);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_3$$3, &pro, "getvalue", NULL, 0, this_ptr);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_4$$3, &pro, "getname", NULL, 0);
			zephir_check_call_status();
			zephir_array_update_zval(&vars, &_4$$3, &_3$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &pros, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &pros, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&pro, &pros, "current", NULL, 0);
			zephir_check_call_status();
				ZVAL_BOOL(&_5$$4, 1);
				ZEPHIR_CALL_METHOD(NULL, &pro, "setaccessible", NULL, 0, &_5$$4);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_6$$4, &pro, "getvalue", NULL, 0, this_ptr);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_7$$4, &pro, "getname", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&vars, &_7$$4, &_6$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &pros, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&pro);
	RETURN_CCTOR(&vars);

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, jsonSerialize) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, toArray) {

	zend_bool _4$$5, _5$$5, _6$$5, _11$$10, _12$$10, _13$$10;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, pros, newPros, key, val, *_0, _1, _7$$6, _9$$7, _10$$8, _14$$11, _15$$12, _16$$13;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&pros);
	ZVAL_UNDEF(&newPros);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data_param);

	if (!data_param) {
		ZEPHIR_INIT_VAR(&data);
		array_init(&data);
	} else {
		zephir_get_arrval(&data, data_param);
	}


	ZEPHIR_INIT_VAR(&pros);
	array_init(&pros);
	ZEPHIR_INIT_VAR(&newPros);
	array_init(&newPros);
	if (ZEPHIR_IS_EMPTY(&data)) {
		ZEPHIR_CALL_METHOD(&pros, this_ptr, "getselfvars", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&pros, &data);
	}
	zephir_is_iterable(&pros, 0, "phalconplus/Base/ProtoBuffer.zep", 120);
	if (Z_TYPE_P(&pros) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&pros), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _0);
			_4$$5 = Z_TYPE_P(&val) == IS_ARRAY;
			if (_4$$5) {
				_4$$5 = !(ZEPHIR_IS_EMPTY(&val));
			}
			_5$$5 = Z_TYPE_P(&val) == IS_OBJECT;
			if (_5$$5) {
				_5$$5 = (zephir_method_exists_ex(&val, ZEND_STRL("toarray")) == SUCCESS);
			}
			_6$$5 = Z_TYPE_P(&val) == IS_OBJECT;
			if (_6$$5) {
				_6$$5 = (zephir_method_exists_ex(&val, ZEND_STRL("__tostring")) == SUCCESS);
			}
			if (_4$$5) {
				ZEPHIR_CALL_METHOD(&_7$$6, this_ptr, "toarray", &_8, 12, &val);
				zephir_check_call_status();
				zephir_array_update_zval(&newPros, &key, &_7$$6, PH_COPY | PH_SEPARATE);
			} else if (_5$$5) {
				ZEPHIR_CALL_METHOD(&_9$$7, &val, "toarray", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&newPros, &key, &_9$$7, PH_COPY | PH_SEPARATE);
			} else if (_6$$5) {
				ZEPHIR_CALL_METHOD(&_10$$8, &val, "__tostring", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&newPros, &key, &_10$$8, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&newPros, &key, &val, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &pros, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &pros, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &pros, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&val, &pros, "current", NULL, 0);
			zephir_check_call_status();
				_11$$10 = Z_TYPE_P(&val) == IS_ARRAY;
				if (_11$$10) {
					_11$$10 = !(ZEPHIR_IS_EMPTY(&val));
				}
				_12$$10 = Z_TYPE_P(&val) == IS_OBJECT;
				if (_12$$10) {
					_12$$10 = (zephir_method_exists_ex(&val, ZEND_STRL("toarray")) == SUCCESS);
				}
				_13$$10 = Z_TYPE_P(&val) == IS_OBJECT;
				if (_13$$10) {
					_13$$10 = (zephir_method_exists_ex(&val, ZEND_STRL("__tostring")) == SUCCESS);
				}
				if (_11$$10) {
					ZEPHIR_CALL_METHOD(&_14$$11, this_ptr, "toarray", &_8, 12, &val);
					zephir_check_call_status();
					zephir_array_update_zval(&newPros, &key, &_14$$11, PH_COPY | PH_SEPARATE);
				} else if (_12$$10) {
					ZEPHIR_CALL_METHOD(&_15$$12, &val, "toarray", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&newPros, &key, &_15$$12, PH_COPY | PH_SEPARATE);
				} else if (_13$$10) {
					ZEPHIR_CALL_METHOD(&_16$$13, &val, "__tostring", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&newPros, &key, &_16$$13, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&newPros, &key, &val, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &pros, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&newPros);

}

