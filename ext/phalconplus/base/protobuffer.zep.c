
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
#include "ext/json/php_json.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/concat.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/array.h"
#include "ext/spl/spl_exceptions.h"
#include "ext/spl/spl_array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_ProtoBuffer)
{
	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Base, ProtoBuffer, phalconplus, base_protobuffer, phalconplus_base_protobuffer_method_entry, 0);

	zend_class_implements(phalconplus_base_protobuffer_ce, 1, php_json_serializable_ce);
	zend_class_implements(phalconplus_base_protobuffer_ce, 1, zend_ce_arrayaccess);
	zend_class_implements(phalconplus_base_protobuffer_ce, 1, zend_ce_countable);
	zend_class_implements(phalconplus_base_protobuffer_ce, 1, zend_ce_aggregate);
	zend_class_implements(phalconplus_base_protobuffer_ce, 1, phalconplus_contracts_emptyornot_ce);
	zend_class_implements(phalconplus_base_protobuffer_ce, 1, phalconplus_contracts_arrayof_ce);
	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *data = NULL, data_sub, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&_1$$3);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL(data)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &data);
	if (!data) {
		data = &data_sub;
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	}


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "isarray", &_0, 0, data);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(data))) {
		ZVAL_BOOL(&_1$$3, 1);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "softclone", NULL, 0, data, &_1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, softClone)
{
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool deep;
	zval *data_param = NULL, *deep_param = NULL, key, val, *_0, _1, _5$$5, _7$$9;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_7$$9);
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


	zephir_is_iterable(&data, 0, "phalconplus/Base/ProtoBuffer.zep", 33);
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
			if (deep == 1) {
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", &_4, 0, &key, &val);
				zephir_check_call_status();
			} else {
				ZEPHIR_CALL_FUNCTION(&_5$$5, "property_exists", &_6, 3, this_ptr, &key);
				zephir_check_call_status();
				if (zephir_is_true(&_5$$5)) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", &_4, 0, &key, &val);
					zephir_check_call_status();
				}
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
				if (deep == 1) {
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", &_4, 0, &key, &val);
					zephir_check_call_status();
				} else {
					ZEPHIR_CALL_FUNCTION(&_7$$9, "property_exists", &_6, 3, this_ptr, &key);
					zephir_check_call_status();
					if (zephir_is_true(&_7$$9)) {
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", &_4, 0, &key, &val);
						zephir_check_call_status();
					}
				}
			ZEPHIR_CALL_METHOD(NULL, &data, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_THIS();
}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __set)
{
	zval _6$$3, _13$$3;
	zend_bool _16, _17, _18, _19;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *val = NULL, val_sub, method, methodRef, param, paramClass, paramClassRef, paramObj, _0, _1, _14, _15, _2$$3, _7$$3, _8$$3, _3$$4, _4$$4, _9$$5, _10$$5, _11$$5, _12$$6, _20$$10, _21$$10;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val_sub);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&methodRef);
	ZVAL_UNDEF(&param);
	ZVAL_UNDEF(&paramClass);
	ZVAL_UNDEF(&paramClassRef);
	ZVAL_UNDEF(&paramObj);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_20$$10);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_13$$3);
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
	ZEPHIR_SEPARATE_PARAM(val);


	ZEPHIR_INIT_VAR(&_1);
	zephir_ucfirst(&_1, &key);
	ZEPHIR_INIT_VAR(&method);
	ZEPHIR_CONCAT_SV(&method, "set", &_1);

	/* try_start_1: */

		ZEPHIR_INIT_VAR(&methodRef);
		object_init_ex(&methodRef, zephir_get_internal_ce(SL("reflectionmethod")));
		ZEPHIR_CALL_METHOD(NULL, &methodRef, "__construct", NULL, 4, this_ptr, &method);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_2$$3, &methodRef, "getnumberofparameters", NULL, 5);
		zephir_check_call_status_or_jump(try_end_1);
		if (ZEPHIR_LT_LONG(&_2$$3, 1)) {
			ZEPHIR_INIT_VAR(&_3$$4);
			object_init_ex(&_3$$4, phalconplus_base_exception_ce);
			ZEPHIR_INIT_VAR(&_4$$4);
			ZEPHIR_CONCAT_SSVS(&_4$$4, "PhalconPlus\\Base\\ProtoBuffer", "::", &method, "() need at least 1 parameter");
			ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", &_5, 2, &_4$$4);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_throw_exception_debug(&_3$$4, "phalconplus/Base/ProtoBuffer.zep", 46);
			goto try_end_1;

		}
		ZEPHIR_INIT_VAR(&param);
		object_init_ex(&param, zephir_get_internal_ce(SL("reflectionparameter")));
		ZEPHIR_INIT_VAR(&_6$$3);
		zephir_create_array(&_6$$3, 2, 0);
		zephir_array_fast_append(&_6$$3, this_ptr);
		zephir_array_fast_append(&_6$$3, &method);
		ZVAL_LONG(&_7$$3, 0);
		ZEPHIR_CALL_METHOD(NULL, &param, "__construct", NULL, 6, &_6$$3, &_7$$3);
		zephir_check_call_status_or_jump(try_end_1);
		ZEPHIR_CALL_METHOD(&_8$$3, &param, "getclass", NULL, 7);
		zephir_check_call_status_or_jump(try_end_1);
		if (zephir_is_true(&_8$$3)) {
			ZEPHIR_CALL_METHOD(&_9$$5, &param, "getclass", NULL, 7);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(&paramClass, &_9$$5, "getname", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_INIT_VAR(&paramClassRef);
			object_init_ex(&paramClassRef, zephir_get_internal_ce(SL("reflectionclass")));
			ZEPHIR_CALL_METHOD(NULL, &paramClassRef, "__construct", NULL, 8, &paramClass);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_INIT_VAR(&_11$$5);
			ZVAL_STRING(&_11$$5, "PhalconPlus\\Base\\ProtoBuffer");
			ZEPHIR_CALL_METHOD(&_10$$5, &paramClassRef, "issubclassof", NULL, 9, &_11$$5);
			zephir_check_call_status_or_jump(try_end_1);
			if (zephir_is_true(&_10$$5)) {
				ZEPHIR_CALL_METHOD(&_12$$6, &paramClassRef, "newinstance", NULL, 10);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CALL_METHOD(&paramObj, &_12$$6, "softclone", NULL, 0, val);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CPY_WRT(val, &paramObj);
			} else {
				ZEPHIR_CALL_METHOD(&paramObj, &paramClassRef, "newinstance", NULL, 10, val);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CPY_WRT(val, &paramObj);
			}
		}
		ZEPHIR_INIT_VAR(&_13$$3);
		zephir_create_array(&_13$$3, 1, 0);
		zephir_array_fast_append(&_13$$3, val);
		ZEPHIR_RETURN_CALL_METHOD(&methodRef, "invokeargs", NULL, 11, this_ptr, &_13$$3);
		zephir_check_call_status_or_jump(try_end_1);
		RETURN_MM();

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_14);
		ZVAL_OBJ(&_14, EG(exception));
		Z_ADDREF_P(&_14);
		ZEPHIR_INIT_VAR(&_15);
		if (zephir_is_instance_of(&_14, SL("Exception"))) {
			zend_clear_exception();
			ZEPHIR_CPY_WRT(&_15, &_14);
		}
	}
	_16 = zephir_is_scalar(val);
	if (!(_16)) {
		_16 = Z_TYPE_P(val) == IS_NULL;
	}
	_17 = _16;
	if (!(_17)) {
		_17 = Z_TYPE_P(val) == IS_ARRAY;
	}
	_18 = _17;
	if (!(_18)) {
		_19 = Z_TYPE_P(val) == IS_OBJECT;
		if (_19) {
			_19 = zephir_instance_of_ev(val, phalconplus_base_protobuffer_ce);
		}
		_18 = _19;
	}
	if (_18) {
		zephir_update_property_zval_zval(this_ptr, &key, val);
	} else {
		ZEPHIR_INIT_VAR(&_20$$10);
		object_init_ex(&_20$$10, phalconplus_base_exception_ce);
		ZEPHIR_INIT_VAR(&_21$$10);
		ZEPHIR_CONCAT_SVS(&_21$$10, "Please add ", &method, " in your class, complex-type vars are not allowed to assign directly");
		ZEPHIR_CALL_METHOD(NULL, &_20$$10, "__construct", &_5, 2, &_21$$10);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_20$$10, "phalconplus/Base/ProtoBuffer.zep", 74);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __isset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, method, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
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


	ZEPHIR_INIT_VAR(&_1);
	zephir_ucfirst(&_1, &key);
	ZEPHIR_INIT_VAR(&method);
	ZEPHIR_CONCAT_SV(&method, "get", &_1);
	if ((zephir_method_exists(this_ptr, &method)  == SUCCESS)) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_FUNCTION(&_2, "property_exists", NULL, 3, this_ptr, &key);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);
}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __get)
{
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

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, __unset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, method, _0, _1, _2;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&method);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
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


	ZEPHIR_INIT_VAR(&_1);
	zephir_ucfirst(&_1, &key);
	ZEPHIR_INIT_VAR(&method);
	ZEPHIR_CONCAT_SV(&method, "unset", &_1);
	if ((zephir_method_exists(this_ptr, &method)  == SUCCESS)) {
		ZEPHIR_CALL_METHOD_ZVAL(NULL, this_ptr, &method, NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_FUNCTION(&_2, "property_exists", NULL, 3, this_ptr, &key);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		
                zephir_unset_property(this_ptr, Z_STRVAL(key));
            
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, isSetGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
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


	ZEPHIR_CALL_METHOD(&_0, this_ptr, "__isset", NULL, 0, &key);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "__get", NULL, 0, &key);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_RETURN_CALL_CE_STATIC(phalconplus_helper_variable_ce, "softnull", &_1, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, getSelfVars)
{
	zval objRef, vars, pros, pro, *_0, _1, _2$$3, _3$$3, _4$$3, _5$$4, _6$$4, _7$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&objRef);
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

	ZEPHIR_INIT_VAR(&objRef);
	ZVAL_NULL(&objRef);
	ZEPHIR_INIT_VAR(&vars);
	array_init(&vars);
	ZEPHIR_INIT_VAR(&pros);
	array_init(&pros);
	ZEPHIR_INIT_VAR(&pro);
	ZVAL_NULL(&pro);
	ZEPHIR_INIT_NVAR(&objRef);
	object_init_ex(&objRef, zephir_get_internal_ce(SL("reflectionobject")));
	ZEPHIR_CALL_METHOD(NULL, &objRef, "__construct", NULL, 12, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&pros, &objRef, "getproperties", NULL, 13);
	zephir_check_call_status();
	zephir_is_iterable(&pros, 0, "phalconplus/Base/ProtoBuffer.zep", 146);
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

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, jsonSerialize)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();



	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, toArray)
{
	zend_bool _4$$3, _5$$3, _6$$3, _11$$8, _12$$8, _13$$8;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *inputPros_param = NULL, newPros, currPros, key, val, *_0, _1, _7$$4, _9$$5, _10$$6, _14$$9, _15$$10, _16$$11;
	zval inputPros;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&inputPros);
	ZVAL_UNDEF(&newPros);
	ZVAL_UNDEF(&currPros);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$11);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY(inputPros)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &inputPros_param);
	if (!inputPros_param) {
		ZEPHIR_INIT_VAR(&inputPros);
		array_init(&inputPros);
	} else {
		zephir_get_arrval(&inputPros, inputPros_param);
	}


	ZEPHIR_INIT_VAR(&newPros);
	array_init(&newPros);
	ZEPHIR_INIT_VAR(&currPros);
	array_init(&currPros);
	if (ZEPHIR_IS_EMPTY(&inputPros)) {
		ZEPHIR_CALL_METHOD(&currPros, this_ptr, "getselfvars", NULL, 0);
		zephir_check_call_status();
	} else {
		ZEPHIR_CPY_WRT(&currPros, &inputPros);
	}
	zephir_is_iterable(&currPros, 0, "phalconplus/Base/ProtoBuffer.zep", 173);
	if (Z_TYPE_P(&currPros) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&currPros), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _0);
			_4$$3 = Z_TYPE_P(&val) == IS_ARRAY;
			if (_4$$3) {
				_4$$3 = !(ZEPHIR_IS_EMPTY(&val));
			}
			_5$$3 = Z_TYPE_P(&val) == IS_OBJECT;
			if (_5$$3) {
				_5$$3 = (zephir_method_exists_ex(&val, ZEND_STRL("toarray")) == SUCCESS);
			}
			_6$$3 = Z_TYPE_P(&val) == IS_OBJECT;
			if (_6$$3) {
				_6$$3 = (zephir_method_exists_ex(&val, ZEND_STRL("__tostring")) == SUCCESS);
			}
			if (_4$$3) {
				ZEPHIR_CALL_METHOD(&_7$$4, this_ptr, "toarray", &_8, 14, &val);
				zephir_check_call_status();
				zephir_array_update_zval(&newPros, &key, &_7$$4, PH_COPY | PH_SEPARATE);
			} else if (_5$$3) {
				ZEPHIR_CALL_METHOD(&_9$$5, &val, "toarray", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&newPros, &key, &_9$$5, PH_COPY | PH_SEPARATE);
			} else if (_6$$3) {
				ZEPHIR_CALL_METHOD(&_10$$6, &val, "__tostring", NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&newPros, &key, &_10$$6, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_zval(&newPros, &key, &val, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &currPros, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &currPros, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &currPros, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&val, &currPros, "current", NULL, 0);
			zephir_check_call_status();
				_11$$8 = Z_TYPE_P(&val) == IS_ARRAY;
				if (_11$$8) {
					_11$$8 = !(ZEPHIR_IS_EMPTY(&val));
				}
				_12$$8 = Z_TYPE_P(&val) == IS_OBJECT;
				if (_12$$8) {
					_12$$8 = (zephir_method_exists_ex(&val, ZEND_STRL("toarray")) == SUCCESS);
				}
				_13$$8 = Z_TYPE_P(&val) == IS_OBJECT;
				if (_13$$8) {
					_13$$8 = (zephir_method_exists_ex(&val, ZEND_STRL("__tostring")) == SUCCESS);
				}
				if (_11$$8) {
					ZEPHIR_CALL_METHOD(&_14$$9, this_ptr, "toarray", &_8, 14, &val);
					zephir_check_call_status();
					zephir_array_update_zval(&newPros, &key, &_14$$9, PH_COPY | PH_SEPARATE);
				} else if (_12$$8) {
					ZEPHIR_CALL_METHOD(&_15$$10, &val, "toarray", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&newPros, &key, &_15$$10, PH_COPY | PH_SEPARATE);
				} else if (_13$$8) {
					ZEPHIR_CALL_METHOD(&_16$$11, &val, "__tostring", NULL, 0);
					zephir_check_call_status();
					zephir_array_update_zval(&newPros, &key, &_16$$11, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_zval(&newPros, &key, &val, PH_COPY | PH_SEPARATE);
				}
			ZEPHIR_CALL_METHOD(NULL, &currPros, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	RETURN_CCTOR(&newPros);
}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, offsetSet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *offset, offset_sub, *value, value_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
	ZVAL_UNDEF(&value_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(offset)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &offset, &value);


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "isstring", &_0, 0, offset);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "__set", NULL, 0, offset, value);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, offsetExists)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *offset, offset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "isstring", &_0, 0, offset);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "__isset", NULL, 0, offset);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, offsetUnset)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *offset, offset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "isstring", &_0, 0, offset);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "__unset", NULL, 0, offset);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, offsetGet)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *offset, offset_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&offset_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(offset)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &offset);


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "isstring", &_0, 0, offset);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "__get", NULL, 0, offset);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, count)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getselfvars", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_LONG(zephir_fast_count_int(&_0));
}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, isEmpty)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getselfvars", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_IS_EMPTY(&_0));
}

PHP_METHOD(PhalconPlus_Base_ProtoBuffer, getIterator)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	ZEPHIR_MM_GROW();

	object_init_ex(return_value, spl_ce_RecursiveArrayIterator);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getselfvars", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 15, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

