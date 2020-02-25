
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Db_UnitOfWork) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Db, UnitOfWork, phalconplus, db_unitofwork, phalconplus_db_unitofwork_method_entry, 0);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("dbServiceName"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("objects"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("inserted"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("updated"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("deleted"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("exception"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("failed"), ZEND_ACC_PROTECTED);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dbServiceName, dbServiceName_sub, _0, _1, _2, _3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dbServiceName_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dbServiceName);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("splobjectstorage")));
	if (zephir_has_constructor(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("objects"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, zephir_get_internal_ce(SL("splobjectstorage")));
	if (zephir_has_constructor(&_1)) {
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("deleted"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, zephir_get_internal_ce(SL("splobjectstorage")));
	if (zephir_has_constructor(&_2)) {
		ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("inserted"), &_2);
	ZEPHIR_INIT_VAR(&_3);
	object_init_ex(&_3, zephir_get_internal_ce(SL("splobjectstorage")));
	if (zephir_has_constructor(&_3)) {
		ZEPHIR_CALL_METHOD(NULL, &_3, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("updated"), &_3);
	zephir_update_property_zval(this_ptr, SL("dbServiceName"), dbServiceName);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, save) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval initial_data;
	zval *name, name_sub, *model, model_sub, *initial_data_param = NULL, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&initial_data);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name, &model, &initial_data_param);

	if (!initial_data_param) {
		ZEPHIR_INIT_VAR(&initial_data);
		array_init(&initial_data);
	} else {
		zephir_get_arrval(&initial_data, initial_data_param);
	}


	if (!(ZEPHIR_IS_EMPTY(&initial_data))) {
		ZEPHIR_CALL_METHOD(NULL, model, "assign", NULL, 0, &initial_data);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_0, model, "exists", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "insert", NULL, 0, name, model, &initial_data);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "update", NULL, 0, name, model, &initial_data);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, insert) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval initial_data, _0;
	zval *name, name_sub, *model, model_sub, *initial_data_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&initial_data);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name, &model, &initial_data_param);

	if (!initial_data_param) {
		ZEPHIR_INIT_VAR(&initial_data);
		array_init(&initial_data);
	} else {
		zephir_get_arrval(&initial_data, initial_data_param);
	}


	ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0, model);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
	add_assoc_stringl_ex(&_0, SL("method"), SL("insert"));
	zephir_array_update_string(&_0, SL("name"), name, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("initial_data"), &initial_data, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, model, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * @param \Phalcon\Mvc\Model | \Phalcon\Mvc\Model\Resultset model
 */
PHP_METHOD(PhalconPlus_Db_UnitOfWork, update) {

	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval initial_data, _1$$3;
	zval *name, name_sub, *model, model_sub, *initial_data_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&initial_data);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name, &model, &initial_data_param);

	if (!initial_data_param) {
		ZEPHIR_INIT_VAR(&initial_data);
		array_init(&initial_data);
	} else {
		zephir_get_arrval(&initial_data, initial_data_param);
	}


	_0 = (zephir_instance_of_ev(model, zephir_get_internal_ce(SL("phalcon\\mvc\\model"))));
	if (!(_0)) {
		_0 = (zephir_instance_of_ev(model, zephir_get_internal_ce(SL("phalcon\\mvc\\model\\resultset"))));
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0, model);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 3, 0);
		add_assoc_stringl_ex(&_1$$3, SL("method"), SL("update"));
		zephir_array_update_string(&_1$$3, SL("name"), name, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_1$$3, SL("initial_data"), &initial_data, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, model, &_1$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "UnitOfWork: Accept <Model> & <Resultset> only", "phalconplus/Db/UnitOfWork.zep", 72);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * @param \Phalcon\Mvc\Model | \Phalcon\Mvc\Model\Resultset model
 */
PHP_METHOD(PhalconPlus_Db_UnitOfWork, delete) {

	zval _1$$3;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *model, model_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_1$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &model);



	_0 = (zephir_instance_of_ev(model, zephir_get_internal_ce(SL("phalcon\\mvc\\model"))));
	if (!(_0)) {
		_0 = (zephir_instance_of_ev(model, zephir_get_internal_ce(SL("phalcon\\mvc\\model\\resultset"))));
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0, model);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_1$$3);
		zephir_create_array(&_1$$3, 2, 0);
		add_assoc_stringl_ex(&_1$$3, SL("method"), SL("delete"));
		zephir_array_update_string(&_1$$3, SL("name"), name, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, model, &_1$$3);
		zephir_check_call_status();
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalconplus_base_exception_ce, "UnitOfWork: Accept <Model> & <Resultset> only", "phalconplus/Db/UnitOfWork.zep", 88);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, attach) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, *info, info_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&info_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &info);



	zephir_read_property(&_0, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "attach", NULL, 0, model, info);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, detach) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	zephir_read_property(&_0, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "detach", NULL, 0, model);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, exec) {

	zval _7$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_4 = NULL, *_5 = NULL, *_8 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$null, txManager, transaction, e, _0, objects, obj, info, newMethod, _1, _15, _17, _2$$3, method$$4, name$$4, _9$$4, _10$$4, _6$$6, _11$$7, _12$$7, _13$$7, _16$$8;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&txManager);
	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&objects);
	ZVAL_UNDEF(&obj);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&newMethod);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&method$$4);
	ZVAL_UNDEF(&name$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_7$$6);

	ZEPHIR_MM_GROW();

	zephir_update_property_zval(this_ptr, SL("exception"), &__$null);
	zephir_update_property_zval(this_ptr, SL("failed"), &__$null);
	ZEPHIR_INIT_VAR(&txManager);
	object_init_ex(&txManager, zephir_get_internal_ce(SL("phalcon\\mvc\\model\\transaction\\manager")));
	ZEPHIR_CALL_METHOD(NULL, &txManager, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, SL("dbServiceName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &txManager, "setdbservice", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&transaction, &txManager, "get", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&objects);
	object_init_ex(&objects, zephir_get_internal_ce(SL("splobjectstorage")));
	if (zephir_has_constructor(&objects)) {
		ZEPHIR_CALL_METHOD(NULL, &objects, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_read_property(&_1, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &objects, "addall", NULL, 100, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &objects, "rewind", NULL, 101);
	zephir_check_call_status();

	/* try_start_1: */

		while (1) {
			ZEPHIR_CALL_METHOD(&_2$$3, &objects, "valid", &_3, 102);
			zephir_check_call_status_or_jump(try_end_1);
			if (!(zephir_is_true(&_2$$3))) {
				break;
			}
			ZEPHIR_CALL_METHOD(&obj, &objects, "current", &_4, 103);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(&info, &objects, "getinfo", &_5, 104);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_OBS_NVAR(&method$$4);
			zephir_array_fetch_string(&method$$4, &info, SL("method"), PH_NOISY, "phalconplus/Db/UnitOfWork.zep", 122);
			zephir_array_unset_string(&info, SL("method"), PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&name$$4);
			zephir_array_fetch_string(&name$$4, &info, SL("name"), PH_NOISY, "phalconplus/Db/UnitOfWork.zep", 123);
			zephir_array_unset_string(&info, SL("name"), PH_SEPARATE);
			if (zephir_instance_of_ev(&obj, zephir_get_internal_ce(SL("phalcon\\mvc\\model")))) {
				ZEPHIR_CALL_METHOD(NULL, &obj, "settransaction", NULL, 0, &transaction);
				zephir_check_call_status_or_jump(try_end_1);
			} else if (zephir_instance_of_ev(&obj, zephir_get_internal_ce(SL("phalcon\\mvc\\model\\resultset")))) {
				ZEPHIR_INIT_NVAR(&_6$$6);
				ZEPHIR_INIT_NVAR(&_6$$6);
				zephir_create_closure_ex(&_6$$6, NULL, phalconplus_2__closure_ce, SL("__invoke"));
				ZEPHIR_INIT_NVAR(&_7$$6);
				zephir_create_array(&_7$$6, 2, 0);
				zephir_array_fast_append(&_7$$6, &obj);
				zephir_array_fast_append(&_7$$6, &transaction);
				ZEPHIR_CALL_FUNCTION(NULL, "iterator_apply", &_8, 105, &obj, &_6$$6, &_7$$6);
				zephir_check_call_status_or_jump(try_end_1);
			}
			ZEPHIR_INIT_NVAR(&_9$$4);
			zephir_ucfirst(&_9$$4, &method$$4);
			ZEPHIR_INIT_NVAR(&newMethod);
			ZEPHIR_CONCAT_SV(&newMethod, "exec", &_9$$4);
			ZEPHIR_CALL_METHOD_ZVAL(&_10$$4, this_ptr, &newMethod, NULL, 0, &obj, &info);
			zephir_check_call_status_or_jump(try_end_1);
			if (ZEPHIR_IS_FALSE(&_10$$4)) {
				ZEPHIR_INIT_NVAR(&_11$$7);
				ZEPHIR_CALL_METHOD(&_12$$7, &obj, "getmessages", NULL, 0);
				zephir_check_call_status_or_jump(try_end_1);
				zephir_json_encode(&_11$$7, &_12$$7, 0 );
				ZEPHIR_INIT_NVAR(&_13$$7);
				ZEPHIR_CONCAT_SVSVSV(&_13$$7, "Model exec failed: ", &name$$4, ":", &newMethod, ". Model Exception: ", &_11$$7);
				ZEPHIR_CALL_METHOD(NULL, &transaction, "rollback", NULL, 0, &_13$$7);
				zephir_check_call_status_or_jump(try_end_1);
			}
			ZEPHIR_CALL_METHOD(NULL, &objects, "next", &_14, 106);
			zephir_check_call_status_or_jump(try_end_1);
		}
		ZEPHIR_CALL_METHOD(NULL, &transaction, "commit", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_15);
		ZVAL_OBJ(&_15, EG(exception));
		Z_ADDREF_P(&_15);
		if (zephir_instance_of_ev(&_15, zephir_get_internal_ce(SL("phalcon\\mvc\\model\\transaction\\failed")))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_15);
			zephir_update_property_zval(this_ptr, SL("failed"), &obj);
			zephir_update_property_zval(this_ptr, SL("exception"), &e);
			zephir_read_property(&_16$$8, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &objects, "removeall", NULL, 107, &_16$$8);
			zephir_check_call_status();
			RETURN_MM_BOOL(0);
		}
	}
	zephir_read_property(&_17, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &objects, "removeall", NULL, 107, &_17);
	zephir_check_call_status();
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, execInsert) {

	zend_bool _4$$4, _9$$8;
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_8 = NULL, *_11 = NULL, *_13 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval info, _16$$13;
	zval *model, model_sub, *info_param = NULL, initial_data, result, last_insert_id, col$$3, val$$3, *_0$$3, _1$$3, _5$$6, _7$$7, _10$$10, _12$$11, _14$$13, _15$$13;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&initial_data);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&last_insert_id);
	ZVAL_UNDEF(&col$$3);
	ZVAL_UNDEF(&val$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&_16$$13);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &info_param);

	zephir_get_arrval(&info, info_param);


	ZEPHIR_OBS_VAR(&initial_data);
	zephir_array_fetch_string(&initial_data, &info, SL("initial_data"), PH_NOISY, "phalconplus/Db/UnitOfWork.zep", 154);
	if (!(ZEPHIR_IS_EMPTY(&initial_data))) {
		zephir_is_iterable(&initial_data, 1, "phalconplus/Db/UnitOfWork.zep", 167);
		if (Z_TYPE_P(&initial_data) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&initial_data), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&col$$3);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&col$$3, _3$$3);
				} else {
					ZVAL_LONG(&col$$3, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&val$$3);
				ZVAL_COPY(&val$$3, _0$$3);
				_4$$4 = Z_TYPE_P(&val$$3) == IS_OBJECT;
				if (_4$$4) {
					_4$$4 = zephir_instance_of_ev(&val$$3, phalconplus_db_unitofwork_abstractvalue_ce);
				}
				if (_4$$4) {
					if (zephir_instance_of_ev(&val$$3, phalconplus_db_unitofwork_lastinsertid_ce)) {
						ZEPHIR_CALL_METHOD(&_5$$6, &val$$3, "getvalue", &_6, 0, this_ptr);
						zephir_check_call_status();
						zephir_array_update_zval(&initial_data, &col$$3, &_5$$6, PH_COPY | PH_SEPARATE);
					} else if (zephir_instance_of_ev(&val$$3, phalconplus_db_unitofwork_field_ce)) {
						ZEPHIR_CALL_METHOD(&_7$$7, &val$$3, "getfield", &_8, 0, this_ptr);
						zephir_check_call_status();
						zephir_array_update_zval(&initial_data, &col$$3, &_7$$7, PH_COPY | PH_SEPARATE);
					}
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &initial_data, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &initial_data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&col$$3, &initial_data, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&val$$3, &initial_data, "current", NULL, 0);
				zephir_check_call_status();
					_9$$8 = Z_TYPE_P(&val$$3) == IS_OBJECT;
					if (_9$$8) {
						_9$$8 = zephir_instance_of_ev(&val$$3, phalconplus_db_unitofwork_abstractvalue_ce);
					}
					if (_9$$8) {
						if (zephir_instance_of_ev(&val$$3, phalconplus_db_unitofwork_lastinsertid_ce)) {
							ZEPHIR_CALL_METHOD(&_10$$10, &val$$3, "getvalue", &_11, 0, this_ptr);
							zephir_check_call_status();
							zephir_array_update_zval(&initial_data, &col$$3, &_10$$10, PH_COPY | PH_SEPARATE);
						} else if (zephir_instance_of_ev(&val$$3, phalconplus_db_unitofwork_field_ce)) {
							ZEPHIR_CALL_METHOD(&_12$$11, &val$$3, "getfield", &_13, 0, this_ptr);
							zephir_check_call_status();
							zephir_array_update_zval(&initial_data, &col$$3, &_12$$11, PH_COPY | PH_SEPARATE);
						}
					}
				ZEPHIR_CALL_METHOD(NULL, &initial_data, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&val$$3);
		ZEPHIR_INIT_NVAR(&col$$3);
		ZEPHIR_CALL_METHOD(&result, model, "create", NULL, 0, &initial_data);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&result, model, "create", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE(&result)) {
		ZEPHIR_CALL_METHOD(&_14$$13, model, "getwriteconnection", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&last_insert_id, &_14$$13, "lastinsertid", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_15$$13, this_ptr, SL("inserted"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_16$$13);
		zephir_create_array(&_16$$13, 1, 0);
		zephir_array_update_string(&_16$$13, SL("last_insert_id"), &last_insert_id, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_15$$13, "attach", NULL, 0, model, &_16$$13);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, execUpdate) {

	zend_bool _4$$4, _7$$6;
	zend_string *_3$$3;
	zend_ulong _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval info, _11$$9;
	zval *model, model_sub, *info_param = NULL, result, initial_data, col$$3, val$$3, *_0$$3, _1$$3, _5$$5, _8$$7, _10$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&initial_data);
	ZVAL_UNDEF(&col$$3);
	ZVAL_UNDEF(&val$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_10$$9);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&_11$$9);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &model, &info_param);

	if (!info_param) {
		ZEPHIR_INIT_VAR(&info);
		array_init(&info);
	} else {
		zephir_get_arrval(&info, info_param);
	}


	ZEPHIR_OBS_VAR(&initial_data);
	zephir_array_fetch_string(&initial_data, &info, SL("initial_data"), PH_NOISY, "phalconplus/Db/UnitOfWork.zep", 184);
	if (!(ZEPHIR_IS_EMPTY(&initial_data))) {
		zephir_is_iterable(&initial_data, 1, "phalconplus/Db/UnitOfWork.zep", 192);
		if (Z_TYPE_P(&initial_data) == IS_ARRAY) {
			ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&initial_data), _2$$3, _3$$3, _0$$3)
			{
				ZEPHIR_INIT_NVAR(&col$$3);
				if (_3$$3 != NULL) { 
					ZVAL_STR_COPY(&col$$3, _3$$3);
				} else {
					ZVAL_LONG(&col$$3, _2$$3);
				}
				ZEPHIR_INIT_NVAR(&val$$3);
				ZVAL_COPY(&val$$3, _0$$3);
				_4$$4 = Z_TYPE_P(&val$$3) == IS_OBJECT;
				if (_4$$4) {
					_4$$4 = zephir_instance_of_ev(&val$$3, phalconplus_db_unitofwork_abstractvalue_ce);
				}
				if (_4$$4) {
					ZEPHIR_CALL_METHOD(&_5$$5, &val$$3, "getvalue", &_6, 0, this_ptr);
					zephir_check_call_status();
					zephir_array_update_zval(&initial_data, &col$$3, &_5$$5, PH_COPY | PH_SEPARATE);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &initial_data, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_1$$3, &initial_data, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_1$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&col$$3, &initial_data, "key", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&val$$3, &initial_data, "current", NULL, 0);
				zephir_check_call_status();
					_7$$6 = Z_TYPE_P(&val$$3) == IS_OBJECT;
					if (_7$$6) {
						_7$$6 = zephir_instance_of_ev(&val$$3, phalconplus_db_unitofwork_abstractvalue_ce);
					}
					if (_7$$6) {
						ZEPHIR_CALL_METHOD(&_8$$7, &val$$3, "getvalue", &_9, 0, this_ptr);
						zephir_check_call_status();
						zephir_array_update_zval(&initial_data, &col$$3, &_8$$7, PH_COPY | PH_SEPARATE);
					}
				ZEPHIR_CALL_METHOD(NULL, &initial_data, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&val$$3);
		ZEPHIR_INIT_NVAR(&col$$3);
		ZEPHIR_CALL_METHOD(&result, model, "update", NULL, 0, &initial_data);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&result, model, "update", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE(&result)) {
		zephir_read_property(&_10$$9, this_ptr, SL("updated"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_11$$9);
		zephir_create_array(&_11$$9, 1, 0);
		zephir_array_update_string(&_11$$9, SL("updated_data"), &initial_data, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_10$$9, "attach", NULL, 0, model, &_11$$9);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, execDelete) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval info;
	zval *model, model_sub, *info_param = NULL, result, _0$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&info);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &model, &info_param);

	if (!info_param) {
		ZEPHIR_INIT_VAR(&info);
		array_init(&info);
	} else {
		zephir_get_arrval(&info, info_param);
	}


	ZEPHIR_CALL_METHOD(&result, model, "delete", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_TRUE(&result)) {
		zephir_read_property(&_0$$3, this_ptr, SL("deleted"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "attach", NULL, 0, model);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, getObjects) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
	if (zephir_clone(return_value, &_0) == FAILURE) {
		return;
	}
	return;

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, getInserted) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("inserted"), PH_NOISY_CC | PH_READONLY);
	if (zephir_clone(return_value, &_0) == FAILURE) {
		return;
	}
	return;

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, getUpdated) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("updated"), PH_NOISY_CC | PH_READONLY);
	if (zephir_clone(return_value, &_0) == FAILURE) {
		return;
	}
	return;

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, getDeleted) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("deleted"), PH_NOISY_CC | PH_READONLY);
	if (zephir_clone(return_value, &_0) == FAILURE) {
		return;
	}
	return;

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, getException) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "exception");

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, getFailed) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "failed");

}

