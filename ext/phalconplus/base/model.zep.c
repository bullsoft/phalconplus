
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_Model) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, Model, phalconplus, base_model, zephir_get_internal_ce(SS("phalcon\\mvc\\model") TSRMLS_CC), phalconplus_base_model_method_entry, 0);

	zend_declare_property_null(phalconplus_base_model_ce, SL("ctime"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_model_ce, SL("mtime"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_model_ce, SL("__p_UK"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalconplus_base_model_ce->create_object = zephir_init_properties_PhalconPlus_Base_Model;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_Model, initialize) {

	zval *_1 = NULL;
	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("notNullValidations"), &ZEPHIR_GLOBAL(global_false), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("castOnHydrate"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("forceCasting"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_SELF(NULL, "setup", NULL, 0, _0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "usedynamicupdate", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_1);
	ZVAL_BOOL(_1, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "keepsnapshots", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_Model, getMessage) {

	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getfirstmessage", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_Model, getFirstMessage) {

	zval *_5$$3 = NULL;
	zval *_0 = NULL, *_1, *_2$$3 = NULL, *_3$$3, *_4$$3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmessages", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_fast_count_int(_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_STRING(_3$$3, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getmessages", NULL, 0, _3$$3);
		zephir_check_temp_parameter(_3$$3);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(_2$$3);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "current", NULL, 24, _2$$3);
		ZEPHIR_UNREF(_2$$3);
		zephir_check_call_status();
		zephir_get_strval(_5$$3, _4$$3);
		RETURN_CTOR(_5$$3);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Base_Model, getLastMessage) {

	zval *_5$$3 = NULL;
	zval *_0 = NULL, *_1, *_2$$3 = NULL, *_3$$3, *_4$$3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_1);
	ZVAL_STRING(_1, "", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmessages", NULL, 0, _1);
	zephir_check_temp_parameter(_1);
	zephir_check_call_status();
	if (zephir_fast_count_int(_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(_3$$3);
		ZVAL_STRING(_3$$3, "", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getmessages", NULL, 0, _3$$3);
		zephir_check_temp_parameter(_3$$3);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(_2$$3);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "end", NULL, 25, _2$$3);
		ZEPHIR_UNREF(_2$$3);
		zephir_check_call_status();
		zephir_get_strval(_5$$3, _4$$3);
		RETURN_CTOR(_5$$3);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Base_Model, createBuilder) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *alias_param = NULL, *source = NULL, *_1 = NULL, *_2 = NULL, *_0$$3;
	zval *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &alias_param);

	if (!alias_param) {
		ZEPHIR_INIT_VAR(alias);
		ZVAL_STRING(alias, "", 1);
	} else {
	if (unlikely(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(alias);
		ZVAL_EMPTY_STRING(alias);
	}
	}


	if (!(ZEPHIR_IS_EMPTY(alias))) {
		ZEPHIR_INIT_VAR(source);
		zephir_create_array(source, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_0$$3);
		zephir_get_called_class(_0$$3 TSRMLS_CC);
		zephir_array_update_zval(&source, alias, &_0$$3, PH_COPY);
	} else {
		ZEPHIR_INIT_NVAR(source);
		zephir_get_called_class(source TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, _1, "createbuilder", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(_2, "from", NULL, 0, source);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_Model, getInstance) {

	zend_class_entry *_1;
	zval *className = NULL, *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	zephir_fetch_safe_class(_0, className);
		_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_Model, batchInsert) {

	HashTable *_4$$3, *_8$$7;
	HashPosition _3$$3, _7$$7;
	zend_class_entry *_1;
	zephir_fcall_cache_entry *_11 = NULL, *_12 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *columns_param = NULL, *rows_param = NULL, *model = NULL, *conn = NULL, *e = NULL, *row = NULL, *columnMap = NULL, *newColumns = NULL, *className = NULL, *_0 = NULL, *_2$$3 = NULL, *val$$3 = NULL, **_5$$3, *_6$$5, **_9$$7, *_10$$8 = NULL;
	zval *columns = NULL, *rows = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &columns_param, &rows_param);

	zephir_get_arrval(columns, columns_param);
	zephir_get_arrval(rows, rows_param);


	ZEPHIR_INIT_VAR(columnMap);
	array_init(columnMap);
	ZEPHIR_INIT_VAR(newColumns);
	array_init(newColumns);
	ZEPHIR_INIT_VAR(className);
	zephir_get_called_class(className TSRMLS_CC);
	ZEPHIR_INIT_VAR(model);
	zephir_fetch_safe_class(_0, className);
		_1 = zend_fetch_class(Z_STRVAL_P(_0), Z_STRLEN_P(_0), ZEND_FETCH_CLASS_AUTO TSRMLS_CC);
	object_init_ex(model, _1);
	if (zephir_has_constructor(model TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, model, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(model, SS("columnmap") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&_2$$3, model, "columnmap", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&columnMap, "array_flip", NULL, 26, _2$$3);
		zephir_check_call_status();
		zephir_is_iterable(columns, &_4$$3, &_3$$3, 0, 0, "phalconplus/Base/Model.zep", 89);
		for (
		  ; zephir_hash_get_current_data_ex(_4$$3, (void**) &_5$$3, &_3$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_4$$3, &_3$$3)
		) {
			ZEPHIR_GET_HVALUE(val$$3, _5$$3);
			if (zephir_array_isset(columnMap, val$$3)) {
				zephir_array_fetch(&_6$$5, columnMap, val$$3, PH_NOISY | PH_READONLY, "phalconplus/Base/Model.zep", 86 TSRMLS_CC);
				zephir_array_append(&newColumns, _6$$5, PH_SEPARATE, "phalconplus/Base/Model.zep", 86);
			}
		}
	} else {
		ZEPHIR_CPY_WRT(newColumns, columns);
	}
	ZEPHIR_CALL_METHOD(&conn, model, "getwriteconnection", NULL, 0);
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_CALL_METHOD(NULL, conn, "begin", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_is_iterable(rows, &_8$$7, &_7$$7, 0, 0, "phalconplus/Base/Model.zep", 98);
		for (
		  ; zephir_hash_get_current_data_ex(_8$$7, (void**) &_9$$7, &_7$$7) == SUCCESS
		  ; zephir_hash_move_forward_ex(_8$$7, &_7$$7)
		) {
			ZEPHIR_GET_HVALUE(row, _9$$7);
			ZEPHIR_CALL_METHOD(&_10$$8, model, "getsource", &_11, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(NULL, conn, "insert", &_12, 0, _10$$8, row, newColumns);
			zephir_check_call_status_or_jump(try_end_1);
		}
		ZEPHIR_CALL_METHOD(NULL, conn, "commit", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_CPY_WRT(e, EG(exception));
		if (zephir_instance_of_ev(e, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CALL_METHOD(NULL, conn, "rollback", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(e, "phalconplus/Base/Model.zep", 101 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Base_Model, beforeValidationOnCreate) {

	zval _0, *_1 = NULL, *_2;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "Y-m-d H:i:s", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 27, &_0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("ctime"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("ctime"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("mtime"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_Model, afterFetch) {

	


}

PHP_METHOD(PhalconPlus_Base_Model, beforeCreate) {

	zval _0, *_1 = NULL, *_2;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "Y-m-d H:i:s", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 27, &_0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("ctime"), _1 TSRMLS_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("ctime"), PH_NOISY_CC);
	zephir_update_property_this(this_ptr, SL("mtime"), _2 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_Model, beforeSave) {

	zval _0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_SINIT_VAR(_0);
	ZVAL_STRING(&_0, "Y-m-d H:i:s", 0);
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 27, &_0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("mtime"), _1 TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

/**
 * find with paginator
 * @var array params
 *    - params["columns"]
 *    - params["conditions"]
 *    - params["bind"]
 *    - params["hydration"]: \Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS | HYDRATE_ARRAYS | HYDRATE_RECORDS
 *
 */
PHP_METHOD(PhalconPlus_Base_Model, findByPagable) {

	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *params = NULL, *_6;
	zval *pagable, *params_param = NULL, *builder = NULL, *val = NULL, *orderBys = NULL, *_2 = NULL, _3, *bind = NULL, *queryBuilder = NULL, *page = NULL, *_7 = NULL, *_8, *_10, *_11, *_4$$3, *_5$$5, *hydration$$10 = NULL, *_9$$11;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pagable, &params_param);

	if (!params_param) {
		ZEPHIR_INIT_VAR(params);
		array_init(params);
	} else {
		zephir_get_arrval(params, params_param);
	}


	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SSSS(_1, "PhalconPlus\\Base\\Model", "::", "Model:findByPagable", ": Pagable can not be null");
	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "notnull", &_0, 28, pagable, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&builder, this_ptr, "createbuilder", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(orderBys);
	array_init(orderBys);
	ZEPHIR_CALL_METHOD(&_2, pagable, "getorderbys", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "strval", 0);
	ZEPHIR_CALL_FUNCTION(&orderBys, "array_map", NULL, 29, &_3, _2);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(orderBys))) {
		ZEPHIR_INIT_VAR(_4$$3);
		zephir_fast_join_str(_4$$3, SL(", "), orderBys TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, builder, "orderby", NULL, 0, _4$$3);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(val);
	if (zephir_array_isset_string_fetch(&val, params, SS("columns"), 0 TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, builder, "columns", NULL, 0, val);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(_5$$5);
		ZVAL_STRING(_5$$5, "*", ZEPHIR_TEMP_PARAM_COPY);
		ZEPHIR_CALL_METHOD(NULL, builder, "columns", NULL, 0, _5$$5);
		zephir_check_temp_parameter(_5$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(bind);
	array_init(bind);
	ZEPHIR_OBS_NVAR(val);
	if (zephir_array_isset_string_fetch(&val, params, SS("bind"), 0 TSRMLS_CC)) {
		ZEPHIR_CPY_WRT(bind, val);
	}
	ZEPHIR_OBS_NVAR(val);
	if (zephir_array_isset_string_fetch(&val, params, SS("conditions"), 0 TSRMLS_CC)) {
		if (ZEPHIR_IS_EMPTY(bind)) {
			ZEPHIR_CALL_METHOD(NULL, builder, "where", NULL, 0, val);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(NULL, builder, "where", NULL, 0, val, bind);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(queryBuilder);
	object_init_ex(queryBuilder, zephir_get_internal_ce(SS("phalcon\\paginator\\adapter\\querybuilder") TSRMLS_CC));
	ZEPHIR_INIT_VAR(_6);
	zephir_create_array(_6, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_6, SL("builder"), &builder, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_7, pagable, "getpagesize", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_6, SL("limit"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_7, pagable, "getpageno", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_6, SL("page"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, queryBuilder, "__construct", NULL, 0, _6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&page, queryBuilder, "getpaginate", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(_8);
	zephir_read_property(&_8, page, SL("items"), PH_NOISY_CC);
	if (Z_TYPE_P(_8) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(hydration$$10);
		if (zephir_array_isset_string_fetch(&hydration$$10, params, SS("hydration"), 0 TSRMLS_CC)) {
			ZEPHIR_OBS_VAR(_9$$11);
			zephir_read_property(&_9$$11, page, SL("items"), PH_NOISY_CC);
			ZEPHIR_CALL_METHOD(NULL, _9$$11, "sethydratemode", NULL, 0, hydration$$10);
			zephir_check_call_status();
		}
	}
	object_init_ex(return_value, phalconplus_base_page_ce);
	ZEPHIR_OBS_VAR(_10);
	zephir_read_property(&_10, page, SL("total_items"), PH_NOISY_CC);
	ZEPHIR_OBS_VAR(_11);
	zephir_read_property(&_11, page, SL("items"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 30, pagable, _10, _11);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if a reord is already exists?
 */
PHP_METHOD(PhalconPlus_Base_Model, exists) {

	zval *metaData = NULL, *readConnection = NULL, *schema = NULL, *source = NULL, *table = NULL, *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(schema)) {
		ZEPHIR_INIT_VAR(table);
		zephir_create_array(table, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(table, schema);
		zephir_array_fast_append(table, source);
	} else {
		ZEPHIR_CPY_WRT(table, source);
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("__p_UK"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_p_buildukcond", NULL, 0, metaData, readConnection);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_exists", NULL, 0, metaData, readConnection, table);
	zephir_check_call_status();
	if (zephir_is_true(_1)) {
		RETURN_MM_BOOL(1);
	} else {
		RETURN_MM_BOOL(0);
	}

}

/**
 * columnMap field
 */
PHP_METHOD(PhalconPlus_Base_Model, setUqKeys) {

	HashTable *_1;
	HashPosition _0;
	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *whereUk_param = NULL, *field = NULL, *attributeField = NULL, *type = NULL, *metaData = NULL, *columnMap = NULL, *bindDataTypes = NULL, **_2, *tmp$$4 = NULL, *_4$$5 = NULL, *_5$$5 = NULL, *_7$$7 = NULL, *_8$$7 = NULL;
	zval *whereUk = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &whereUk_param);

	if (!whereUk_param) {
		ZEPHIR_INIT_VAR(whereUk);
		array_init(whereUk);
	} else {
		zephir_get_arrval(whereUk, whereUk_param);
	}


	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, metaData, "getcolumnmap", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, metaData, "getbindtypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(whereUk, &_1, &_0, 0, 0, "phalconplus/Base/Model.zep", 254);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HVALUE(attributeField, _2);
		if (Z_TYPE_P(columnMap) == IS_ARRAY) {
			ZEPHIR_CALL_FUNCTION(&tmp$$4, "array_flip", &_3, 26, columnMap);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(field);
			if (!(zephir_array_isset_fetch(&field, tmp$$4, attributeField, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(_4$$5);
				object_init_ex(_4$$5, zend_exception_get_default(TSRMLS_C));
				ZEPHIR_INIT_LNVAR(_5$$5);
				ZEPHIR_CONCAT_SVS(_5$$5, "Model::setUpKeys: Column '", attributeField, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, _4$$5, "__construct", &_6, 7, _5$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(_4$$5, "phalconplus/Base/Model.zep", 241 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(field, attributeField);
		}
		zephir_update_property_array_multi(this_ptr, SL("__p_UK"), &field TSRMLS_CC, SL("zs"), 3, attributeField, SL("field"));
		ZEPHIR_OBS_NVAR(type);
		if (!(zephir_array_isset_fetch(&type, bindDataTypes, field, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(_7$$7);
			object_init_ex(_7$$7, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_LNVAR(_8$$7);
			ZEPHIR_CONCAT_SVS(_8$$7, "Model::setUpKeys: Column '", field, "' isn't part of the table columns");
			ZEPHIR_CALL_METHOD(NULL, _7$$7, "__construct", &_6, 7, _8$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(_7$$7, "phalconplus/Base/Model.zep", 250 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_array_multi(this_ptr, SL("__p_UK"), &type TSRMLS_CC, SL("zs"), 3, attributeField, SL("type"));
	}
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_Model, _p_buildUkCond) {

	HashTable *_2;
	HashPosition _1;
	zephir_fcall_cache_entry *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, *connection, *value = NULL, *type = NULL, *info = NULL, *field = NULL, *whereUk = NULL, *uniqueParams = NULL, *uniqueTypes = NULL, *attributeField = NULL, *_0, **_3, _7, *_8 = NULL, *_9, *_4$$3 = NULL, *_6$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &metaData, &connection);



	ZEPHIR_INIT_VAR(whereUk);
	array_init(whereUk);
	ZEPHIR_INIT_VAR(uniqueParams);
	array_init(uniqueParams);
	ZEPHIR_INIT_VAR(uniqueTypes);
	array_init(uniqueTypes);
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("__p_UK"), PH_NOISY_CC);
	zephir_is_iterable(_0, &_2, &_1, 0, 0, "phalconplus/Base/Model.zep", 278);
	for (
	  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
	  ; zephir_hash_move_forward_ex(_2, &_1)
	) {
		ZEPHIR_GET_HMKEY(attributeField, _2, _1);
		ZEPHIR_GET_HVALUE(info, _3);
		ZEPHIR_OBS_NVAR(type);
		zephir_array_fetch_string(&type, info, SL("type"), PH_NOISY, "phalconplus/Base/Model.zep", 266 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(field);
		zephir_array_fetch_string(&field, info, SL("field"), PH_NOISY, "phalconplus/Base/Model.zep", 267 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(value);
		ZVAL_NULL(value);
		ZEPHIR_OBS_NVAR(value);
		if (zephir_fetch_property_zval(&value, this_ptr, attributeField, PH_SILENT_CC)) {
			zephir_array_append(&uniqueParams, value, PH_SEPARATE, "phalconplus/Base/Model.zep", 270);
		} else {
			zephir_array_append(&uniqueParams, ZEPHIR_GLOBAL(global_null), PH_SEPARATE, "phalconplus/Base/Model.zep", 272);
		}
		zephir_array_append(&uniqueTypes, type, PH_SEPARATE, "phalconplus/Base/Model.zep", 274);
		ZEPHIR_CALL_METHOD(&_4$$3, connection, "escapeidentifier", &_5, 0, field);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_6$$3);
		ZEPHIR_CONCAT_VS(_6$$3, _4$$3, " = ?");
		zephir_array_append(&whereUk, _6$$3, PH_SEPARATE, "phalconplus/Base/Model.zep", 275);
	}
	ZEPHIR_SINIT_VAR(_7);
	ZVAL_STRING(&_7, "isset", 0);
	ZEPHIR_CALL_FUNCTION(&_8, "array_filter", NULL, 31, uniqueParams, &_7);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(_8)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(_9);
	zephir_fast_join_str(_9, SL(" AND "), whereUk TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_uniqueKey"), _9 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_uniqueParams"), uniqueParams TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("_uniqueTypes"), uniqueTypes TSRMLS_CC);
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Base_Model, toProtoBuffer) {

	HashTable *_1, *_6;
	HashPosition _0, _5;
	zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *columns = NULL, *proto = NULL, *toArray = NULL, *key = NULL, *val = NULL, **_2, *modelName = NULL, *manager = NULL, *relations = NULL, *referenceModel = NULL, *referencedEntity = NULL, *options = NULL, *alias = NULL, *lowerAlias = NULL, **_7, *_3$$3 = NULL, *method$$4 = NULL, *property$$4 = NULL, *_9$$4 = NULL, *_10$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &columns);

	if (!columns) {
		columns = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_CALL_METHOD(&toArray, this_ptr, "toarray", NULL, 0, columns);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(proto);
	object_init_ex(proto, phalconplus_base_protobuffer_ce);
	if (zephir_has_constructor(proto TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, proto, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_is_iterable(toArray, &_1, &_0, 0, 0, "phalconplus/Base/Model.zep", 296);
	for (
	  ; zephir_hash_get_current_data_ex(_1, (void**) &_2, &_0) == SUCCESS
	  ; zephir_hash_move_forward_ex(_1, &_0)
	) {
		ZEPHIR_GET_HMKEY(key, _1, _0);
		ZEPHIR_GET_HVALUE(val, _2);
		ZEPHIR_INIT_LNVAR(_3$$3);
		if (zephir_is_scalar(val)) {
			ZEPHIR_CPY_WRT(_3$$3, val);
		} else {
			ZEPHIR_CALL_FUNCTION(&_3$$3, "strval", &_4, 21, val);
			zephir_check_call_status();
		}
		zephir_update_property_zval_zval(proto, key, _3$$3 TSRMLS_CC);
	}
	ZEPHIR_INIT_VAR(modelName);
	zephir_get_class(modelName, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&relations, manager, "getrelations", NULL, 0, modelName);
	zephir_check_call_status();
	zephir_is_iterable(relations, &_6, &_5, 0, 0, "phalconplus/Base/Model.zep", 317);
	for (
	  ; zephir_hash_get_current_data_ex(_6, (void**) &_7, &_5) == SUCCESS
	  ; zephir_hash_move_forward_ex(_6, &_5)
	) {
		ZEPHIR_GET_HVALUE(val, _7);
		ZEPHIR_CALL_METHOD(&referenceModel, val, "getreferencedmodel", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(referencedEntity);
		zephir_fast_strtolower(referencedEntity, referenceModel);
		ZEPHIR_CALL_METHOD(&options, val, "getoptions", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(alias);
		if (zephir_array_isset_string_fetch(&alias, options, SS("alias"), 0 TSRMLS_CC)) {
			if (Z_TYPE_P(alias) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Relation alias must be a string", "phalconplus/Base/Model.zep", 306);
				return;
			}
			ZEPHIR_INIT_NVAR(lowerAlias);
			zephir_fast_strtolower(lowerAlias, alias);
		} else {
			ZEPHIR_CPY_WRT(lowerAlias, referencedEntity);
		}
		ZEPHIR_INIT_NVAR(method$$4);
		ZEPHIR_CONCAT_SV(method$$4, "get", alias);
		ZEPHIR_CALL_FUNCTION(&property$$4, "lcfirst", &_8, 32, alias);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_ZVAL(&_9$$4, this_ptr, method$$4, NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_10$$4, _9$$4, "toarray", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval_zval(proto, property$$4, _10$$4 TSRMLS_CC);
	}
	RETURN_CCTOR(proto);

}

/**
 *
 * Once in a transaction, a read-sql should always use the write connection for the data consistency.
 * But, if you do not like this, you can rewrite this method Or use <\PhalconPlus\Db\UnitOfWork>
 *
 */
PHP_METHOD(PhalconPlus_Base_Model, selectReadConnection) {

	zval *txm = NULL, *transaction = NULL, *_0 = NULL, *_1 = NULL, *_2 = NULL, *_3 = NULL, *_4 = NULL, *_5 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_2);
	ZVAL_STRING(_2, "txm", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&_1, _0, "has", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (!(zephir_is_true(_1))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getreadconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_STRING(_2, "txm", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(&txm, _3, "get", NULL, 0, _2);
	zephir_check_temp_parameter(_2);
	zephir_check_call_status();
	if (!(zephir_instance_of_ev(txm, zephir_get_internal_ce(SS("phalcon\\mvc\\model\\transaction\\manager") TSRMLS_CC) TSRMLS_CC))) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getreadconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "getwriteconnectionservice", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, txm, "setdbservice", NULL, 0, _4);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(_2);
	ZVAL_BOOL(_2, 0);
	ZEPHIR_CALL_METHOD(&transaction, txm, "get", NULL, 0, _2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_5, transaction, "isvalid", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_5)) {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getwriteconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	} else {
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getreadconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}

}

zend_object_value zephir_init_properties_PhalconPlus_Base_Model(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("__p_UK"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("__p_UK"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

