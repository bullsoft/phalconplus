
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
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Db_UnitOfWork) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Db, UnitOfWork, phalconplus, db_unitofwork, phalconplus_db_unitofwork_method_entry, 0);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("modelLocator"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("dbServiceName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("objects"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("inserted"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("updated"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("deleted"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("exception"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalconplus_db_unitofwork_ce, SL("failed"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalconplus_db_unitofwork_ce->create_object = zephir_init_properties_PhalconPlus_Db_UnitOfWork;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, __construct) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *dbServiceName, dbServiceName_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dbServiceName_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &dbServiceName);



	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("splobjectstorage")));
	if (zephir_has_constructor(&_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("objects"), &_0);
	zephir_update_property_zval(this_ptr, SL("dbServiceName"), dbServiceName);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, save) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval initial_data;
	zval *name, name_sub, *model, model_sub, *initial_data_param = NULL, _0, _1$$4, _2$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
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
		ZVAL_BOOL(&_1$$4, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "insert", NULL, 0, name, model, &initial_data, &_1$$4);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(&_2$$5, 0);
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "update", NULL, 0, name, model, &initial_data, &_2$$5);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, insert) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool assign, _0;
	zval initial_data, _1;
	zval *name, name_sub, *model, model_sub, *initial_data_param = NULL, *assign_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&initial_data);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &name, &model, &initial_data_param, &assign_param);

	if (!initial_data_param) {
		ZEPHIR_INIT_VAR(&initial_data);
		array_init(&initial_data);
	} else {
		zephir_get_arrval(&initial_data, initial_data_param);
	}
	if (!assign_param) {
		assign = 1;
	} else {
		assign = zephir_get_boolval(assign_param);
	}


	_0 = !(ZEPHIR_IS_EMPTY(&initial_data));
	if (_0) {
		_0 = assign == 1;
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(NULL, model, "assign", NULL, 0, &initial_data);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0, model);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_1, SL("method"), SL("insert"));
	zephir_array_update_string(&_1, SL("name"), name, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("initial_data"), &initial_data, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, model, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, update) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool assign, _0;
	zval initial_data, _1;
	zval *name, name_sub, *model, model_sub, *initial_data_param = NULL, *assign_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&initial_data);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 2, &name, &model, &initial_data_param, &assign_param);

	if (!initial_data_param) {
		ZEPHIR_INIT_VAR(&initial_data);
		array_init(&initial_data);
	} else {
		zephir_get_arrval(&initial_data, initial_data_param);
	}
	if (!assign_param) {
		assign = 1;
	} else {
		assign = zephir_get_boolval(assign_param);
	}


	_0 = !(ZEPHIR_IS_EMPTY(&initial_data));
	if (_0) {
		_0 = assign == 1;
	}
	if (_0) {
		ZEPHIR_CALL_METHOD(NULL, model, "assign", NULL, 0, &initial_data);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0, model);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 3, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_1, SL("method"), SL("update"));
	zephir_array_update_string(&_1, SL("name"), name, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_1, SL("initial_data"), &initial_data, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, model, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, delete) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *name, name_sub, *model, model_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name, &model);



	ZEPHIR_CALL_METHOD(NULL, this_ptr, "detach", NULL, 0, model);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0 TSRMLS_CC);
	add_assoc_stringl_ex(&_0, SL("method"), SL("delete"));
	zephir_array_update_string(&_0, SL("name"), name, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "attach", NULL, 0, model, &_0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, attach) {

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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$null, _0, _1, _2, txManager, transaction, e, _3, obj, info, _4, _13, _5$$3, _6$$3, _7$$4, _8$$4, method$$4, name$$4, newMethod$$4, _9$$4, _10$$4, _12$$4, _11$$5;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&txManager);
	ZVAL_UNDEF(&transaction);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&obj);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&method$$4);
	ZVAL_UNDEF(&name$$4);
	ZVAL_UNDEF(&newMethod$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_11$$5);

	ZEPHIR_MM_GROW();

	zephir_update_property_zval(this_ptr, SL("exception"), &__$null);
	zephir_update_property_zval(this_ptr, SL("failed"), &__$null);
	ZEPHIR_INIT_VAR(&_0);
	object_init_ex(&_0, zephir_get_internal_ce(SL("splobjectstorage")));
	if (zephir_has_constructor(&_0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_0, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("deleted"), &_0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, zephir_get_internal_ce(SL("splobjectstorage")));
	if (zephir_has_constructor(&_1 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("inserted"), &_1);
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, zephir_get_internal_ce(SL("splobjectstorage")));
	if (zephir_has_constructor(&_2 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_update_property_zval(this_ptr, SL("updated"), &_2);
	ZEPHIR_INIT_VAR(&txManager);
	object_init_ex(&txManager, zephir_get_internal_ce(SL("phalcon\\mvc\\model\\transaction\\manager")));
	ZEPHIR_CALL_METHOD(NULL, &txManager, "__construct", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("dbServiceName"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &txManager, "setdbservice", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&transaction, &txManager, "get", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_4, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_4, "rewind", NULL, 0);
	zephir_check_call_status();

	/* try_start_1: */

		while (1) {
			zephir_read_property(&_5$$3, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_6$$3, &_5$$3, "valid", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (!(zephir_is_true(&_6$$3))) {
				break;
			}
			zephir_read_property(&_7$$4, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&obj, &_7$$4, "current", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_read_property(&_8$$4, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&info, &_8$$4, "getinfo", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_OBS_NVAR(&method$$4);
			zephir_array_fetch_string(&method$$4, &info, SL("method"), PH_NOISY, "phalconplus/Db/UnitOfWork.zep", 112 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&name$$4);
			zephir_array_fetch_string(&name$$4, &info, SL("name"), PH_NOISY, "phalconplus/Db/UnitOfWork.zep", 113 TSRMLS_CC);
			zephir_array_unset_string(&info, SL("method"), PH_SEPARATE);
			zephir_array_unset_string(&info, SL("name"), PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &obj, "settransaction", NULL, 0, &transaction);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_INIT_NVAR(&_9$$4);
			zephir_ucfirst(&_9$$4, &method$$4);
			ZEPHIR_INIT_NVAR(&newMethod$$4);
			ZEPHIR_CONCAT_SV(&newMethod$$4, "exec", &_9$$4);
			ZEPHIR_CALL_METHOD_ZVAL(&_10$$4, this_ptr, &newMethod$$4, NULL, 0, &obj, &info);
			zephir_check_call_status_or_jump(try_end_1);
			if (ZEPHIR_IS_FALSE(&_10$$4)) {
				ZEPHIR_INIT_LNVAR(_11$$5);
				ZEPHIR_CONCAT_SVSV(&_11$$5, "Model exec failed: ", &name$$4, ":", &method$$4);
				ZEPHIR_CALL_METHOD(NULL, &transaction, "rollback", NULL, 0, &_11$$5);
				zephir_check_call_status_or_jump(try_end_1);
			}
			zephir_read_property(&_12$$4, this_ptr, SL("objects"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_12$$4, "next", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
		}
		ZEPHIR_CALL_METHOD(NULL, &transaction, "commit", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_13);
		ZVAL_OBJ(&_13, EG(exception));
		Z_ADDREF_P(&_13);
		if (zephir_instance_of_ev(&_13, zephir_get_internal_ce(SL("phalcon\\mvc\\model\\transaction\\failed")) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_13);
			zephir_update_property_zval(this_ptr, SL("failed"), &obj);
			zephir_update_property_zval(this_ptr, SL("exception"), &e);
			RETURN_MM_BOOL(0);
		}
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, execInsert) {

	zend_string *_2$$3;
	zend_ulong _1$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval info, _6$$7;
	zval *model, model_sub, *info_param = NULL, initial_data, result, last_insert_id, col$$3, val$$3, *_0$$3, _3$$5, _4$$7, _5$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&initial_data);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&last_insert_id);
	ZVAL_UNDEF(&col$$3);
	ZVAL_UNDEF(&val$$3);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&_6$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &info_param);

	zephir_get_arrval(&info, info_param);


	ZEPHIR_OBS_VAR(&initial_data);
	zephir_array_fetch_string(&initial_data, &info, SL("initial_data"), PH_NOISY, "phalconplus/Db/UnitOfWork.zep", 138 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(&initial_data))) {
		zephir_is_iterable(&initial_data, 1, "phalconplus/Db/UnitOfWork.zep", 146);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&initial_data), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&col$$3);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&col$$3, _2$$3);
			} else {
				ZVAL_LONG(&col$$3, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&val$$3);
			ZVAL_COPY(&val$$3, _0$$3);
			if (zephir_is_callable(&val$$3 TSRMLS_CC)) {
				ZEPHIR_CALL_ZVAL_FUNCTION(&_3$$5, &val$$3, NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&initial_data, &col$$3, &_3$$5, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&val$$3);
		ZEPHIR_INIT_NVAR(&col$$3);
		ZEPHIR_CALL_METHOD(&result, model, "create", NULL, 0, &initial_data);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&result, model, "create", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE(&result)) {
		ZEPHIR_CALL_METHOD(&_4$$7, model, "getwriteconnection", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&last_insert_id, &_4$$7, "lastinsertid", NULL, 0);
		zephir_check_call_status();
		zephir_read_property(&_5$$7, this_ptr, SL("inserted"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_6$$7);
		zephir_create_array(&_6$$7, 1, 0 TSRMLS_CC);
		zephir_array_update_string(&_6$$7, SL("last_insert_id"), &last_insert_id, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_5$$7, "attach", NULL, 0, model, &_6$$7);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, execUpdate) {

	zend_string *_2$$3, *_6$$6;
	zend_ulong _1$$3, _5$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval info;
	zval *model, model_sub, *info_param = NULL, __$null, result, initial_data, metaData, columnMap, whiteList, attrField, field, *_0$$3, _3$$4, col$$6, val$$6, *_4$$6, _7$$8, _8$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&initial_data);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&whiteList);
	ZVAL_UNDEF(&attrField);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&col$$6);
	ZVAL_UNDEF(&val$$6);
	ZVAL_UNDEF(&_7$$8);
	ZVAL_UNDEF(&_8$$11);
	ZVAL_UNDEF(&info);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &model, &info_param);

	if (!info_param) {
		ZEPHIR_INIT_VAR(&info);
		array_init(&info);
	} else {
		zephir_get_arrval(&info, info_param);
	}


	ZEPHIR_INIT_VAR(&whiteList);
	array_init(&whiteList);
	ZEPHIR_CALL_METHOD(&metaData, model, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, model);
	zephir_check_call_status();
	if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
		zephir_is_iterable(&columnMap, 0, "phalconplus/Db/UnitOfWork.zep", 174);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&columnMap), _1$$3, _2$$3, _0$$3)
		{
			ZEPHIR_INIT_NVAR(&field);
			if (_2$$3 != NULL) { 
				ZVAL_STR_COPY(&field, _2$$3);
			} else {
				ZVAL_LONG(&field, _1$$3);
			}
			ZEPHIR_INIT_NVAR(&attrField);
			ZVAL_COPY(&attrField, _0$$3);
			ZEPHIR_OBS_NVAR(&_3$$4);
			zephir_read_property_zval(&_3$$4, this_ptr, &attrField, PH_NOISY_CC);
			if (ZEPHIR_IS_EMPTY(&_3$$4)) {
				zephir_array_update_zval(&whiteList, &attrField, &__$null, PH_COPY | PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&attrField);
		ZEPHIR_INIT_NVAR(&field);
	}
	ZEPHIR_CALL_METHOD(NULL, model, "setsnapshotdata", NULL, 0, &whiteList);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&initial_data);
	zephir_array_fetch_string(&initial_data, &info, SL("initial_data"), PH_NOISY, "phalconplus/Db/UnitOfWork.zep", 177 TSRMLS_CC);
	if (!(ZEPHIR_IS_EMPTY(&initial_data))) {
		zephir_is_iterable(&initial_data, 1, "phalconplus/Db/UnitOfWork.zep", 189);
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&initial_data), _5$$6, _6$$6, _4$$6)
		{
			ZEPHIR_INIT_NVAR(&col$$6);
			if (_6$$6 != NULL) { 
				ZVAL_STR_COPY(&col$$6, _6$$6);
			} else {
				ZVAL_LONG(&col$$6, _5$$6);
			}
			ZEPHIR_INIT_NVAR(&val$$6);
			ZVAL_COPY(&val$$6, _4$$6);
			if (zephir_is_callable(&val$$6 TSRMLS_CC)) {
				ZEPHIR_CALL_ZVAL_FUNCTION(&_7$$8, &val$$6, NULL, 0);
				zephir_check_call_status();
				zephir_array_update_zval(&initial_data, &col$$6, &_7$$8, PH_COPY | PH_SEPARATE);
			}
			if (Z_TYPE_P(&val$$6) == IS_NULL) {
				zephir_array_unset(&initial_data, &col$$6, PH_SEPARATE);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&val$$6);
		ZEPHIR_INIT_NVAR(&col$$6);
		ZEPHIR_CALL_METHOD(&result, model, "update", NULL, 0, &initial_data);
		zephir_check_call_status();
	} else {
		ZEPHIR_CALL_METHOD(&result, model, "update", NULL, 0);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_TRUE(&result)) {
		zephir_read_property(&_8$$11, this_ptr, SL("updated"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_8$$11, "attach", NULL, 0, model);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&result);

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, execDelete) {

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

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "objects");

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, getInserted) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "inserted");

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, getUpdated) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "updated");

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, getDeleted) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "deleted");

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, getException) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "exception");

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork, getFailed) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "failed");

}

zend_object *zephir_init_properties_PhalconPlus_Db_UnitOfWork(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("modelLocator"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("modelLocator"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

