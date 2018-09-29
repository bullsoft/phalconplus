
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
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_Model) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, Model, phalconplus, base_model, zephir_get_internal_ce(SL("phalcon\\mvc\\model")), phalconplus_base_model_method_entry, 0);

	zend_declare_property_null(phalconplus_base_model_ce, SL("ctime"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_model_ce, SL("mtime"), ZEND_ACC_PUBLIC TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_model_ce, SL("__p_UK"), ZEND_ACC_PROTECTED TSRMLS_CC);

	phalconplus_base_model_ce->create_object = zephir_init_properties_PhalconPlus_Base_Model;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_Model, initialize) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$false, __$true, _1;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("notNullValidations"), &__$false, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("castOnHydrate"), &__$true, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("forceCasting"), &__$true, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_SELF(NULL, "setup", NULL, 0, &_0);
	zephir_check_call_status();
	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "usedynamicupdate", NULL, 0, &_1);
	zephir_check_call_status();
	ZVAL_BOOL(&_1, 1);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "keepsnapshots", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_Model, getMessage) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getfirstmessage", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_Model, getFirstMessage) {

	zval _5$$3;
	zval _0, _1, _2$$3, _3$$3, _4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmessages", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_fast_count_int(&_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "");
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getmessages", NULL, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_4$$3, "current", NULL, 30, &_2$$3);
		zephir_check_call_status();
		zephir_get_strval(&_5$$3, &_4$$3);
		RETURN_CTOR(&_5$$3);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Base_Model, getLastMessage) {

	zval _5$$3;
	zval _0, _1, _2$$3, _3$$3, _4$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmessages", NULL, 0, &_1);
	zephir_check_call_status();
	if (zephir_fast_count_int(&_0 TSRMLS_CC)) {
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "");
		ZEPHIR_CALL_METHOD(&_2$$3, this_ptr, "getmessages", NULL, 0, &_3$$3);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(&_2$$3);
		ZEPHIR_CALL_FUNCTION(&_4$$3, "end", NULL, 31, &_2$$3);
		ZEPHIR_UNREF(&_2$$3);
		zephir_check_call_status();
		zephir_get_strval(&_5$$3, &_4$$3);
		RETURN_CTOR(&_5$$3);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Base_Model, createBuilder) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *alias_param = NULL, source, _1, _2, _0$$3;
	zval alias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &alias_param);

	if (!alias_param) {
		ZEPHIR_INIT_VAR(&alias);
		ZVAL_STRING(&alias, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(&alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(&alias);
		ZVAL_EMPTY_STRING(&alias);
	}
	}


	if (!(ZEPHIR_IS_EMPTY(&alias))) {
		ZEPHIR_INIT_VAR(&source);
		zephir_create_array(&source, 1, 0 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_called_class(&_0$$3 TSRMLS_CC);
		zephir_array_update_zval(&source, &alias, &_0$$3, PH_COPY);
	} else {
		ZEPHIR_INIT_NVAR(&source);
		zephir_get_called_class(&source TSRMLS_CC);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_1, "createbuilder", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_2, "from", NULL, 0, &source);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * @deprecated 非单例，不建议用此方法名称，将在以后移除
 */
PHP_METHOD(PhalconPlus_Base_Model, getInstance) {

	zend_class_entry *_1;
	zval className, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&className);
	zephir_get_called_class(&className TSRMLS_CC);
	zephir_fetch_safe_class(&_0, &className);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_Model, newInstance) {

	zend_class_entry *_1;
	zval className, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&className);
	zephir_get_called_class(&className TSRMLS_CC);
	zephir_fetch_safe_class(&_0, &className);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_Model, batchInsert) {

	zend_class_entry *_1;
	zephir_fcall_cache_entry *_7 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columns_param = NULL, *rows_param = NULL, model, conn, e, row, columnMap, newColumns, className, _0, _9, _2$$3, val$$3, *_3$$3, _4$$5, *_5$$7, _6$$8;
	zval columns, rows;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&rows);
	ZVAL_UNDEF(&model);
	ZVAL_UNDEF(&conn);
	ZVAL_UNDEF(&e);
	ZVAL_UNDEF(&row);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&newColumns);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&val$$3);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &columns_param, &rows_param);

	zephir_get_arrval(&columns, columns_param);
	zephir_get_arrval(&rows, rows_param);


	ZEPHIR_INIT_VAR(&columnMap);
	array_init(&columnMap);
	ZEPHIR_INIT_VAR(&newColumns);
	array_init(&newColumns);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_called_class(&className TSRMLS_CC);
	ZEPHIR_INIT_VAR(&model);
	zephir_fetch_safe_class(&_0, &className);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	object_init_ex(&model, _1);
	if (zephir_has_constructor(&model TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &model, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(&model, SL("columnmap") TSRMLS_CC) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&_2$$3, &model, "columnmap", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&columnMap, "array_flip", NULL, 32, &_2$$3);
		zephir_check_call_status();
		zephir_is_iterable(&columns, 0, "phalconplus/Base/Model.zep", 100);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&columns), _3$$3)
		{
			ZEPHIR_INIT_NVAR(&val$$3);
			ZVAL_COPY(&val$$3, _3$$3);
			if (zephir_array_isset(&columnMap, &val$$3)) {
				zephir_array_fetch(&_4$$5, &columnMap, &val$$3, PH_NOISY | PH_READONLY, "phalconplus/Base/Model.zep", 97 TSRMLS_CC);
				zephir_array_append(&newColumns, &_4$$5, PH_SEPARATE, "phalconplus/Base/Model.zep", 97);
			}
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&val$$3);
	} else {
		ZEPHIR_CPY_WRT(&newColumns, &columns);
	}
	ZEPHIR_CALL_METHOD(&conn, &model, "getwriteconnection", NULL, 0);
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_CALL_METHOD(NULL, &conn, "begin", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_is_iterable(&rows, 0, "phalconplus/Base/Model.zep", 109);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rows), _5$$7)
		{
			ZEPHIR_INIT_NVAR(&row);
			ZVAL_COPY(&row, _5$$7);
			ZEPHIR_CALL_METHOD(&_6$$8, &model, "getsource", &_7, 0);
			zephir_check_call_status_or_jump(try_end_1);
			ZEPHIR_CALL_METHOD(NULL, &conn, "insert", &_8, 0, &_6$$8, &row, &newColumns);
			zephir_check_call_status_or_jump(try_end_1);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&row);
		ZEPHIR_CALL_METHOD(NULL, &conn, "commit", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_9);
		ZVAL_OBJ(&_9, EG(exception));
		Z_ADDREF_P(&_9);
		if (zephir_instance_of_ev(&_9, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_9);
			ZEPHIR_CALL_METHOD(NULL, &conn, "rollback", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&e, "phalconplus/Base/Model.zep", 112 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Base_Model, beforeValidationOnCreate) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Y-m-d H:i:s");
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 33, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("ctime"), &_1);
	zephir_read_property(&_2, this_ptr, SL("ctime"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("mtime"), &_2);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_Model, afterFetch) {

	zval *this_ptr = getThis();



}

PHP_METHOD(PhalconPlus_Base_Model, beforeCreate) {

	zval _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Y-m-d H:i:s");
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 33, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("ctime"), &_1);
	zephir_read_property(&_2, this_ptr, SL("ctime"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("mtime"), &_2);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_Model, beforeSave) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Y-m-d H:i:s");
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 33, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("mtime"), &_1);
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

	zval _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval params, _6;
	zval *pagable, pagable_sub, *params_param = NULL, builder, val, orderBys, _2, _3, bind, queryBuilder, page, _7, _8, _10, _11, _4$$3, _5$$5, hydration$$10, _9$$11;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pagable_sub);
	ZVAL_UNDEF(&builder);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&orderBys);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&bind);
	ZVAL_UNDEF(&queryBuilder);
	ZVAL_UNDEF(&page);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&hydration$$10);
	ZVAL_UNDEF(&_9$$11);
	ZVAL_UNDEF(&params);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pagable, &params_param);

	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SSSS(&_1, "PhalconPlus\\Base\\Model", "::", "Model:findByPagable", ": Pagable can not be null");
	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "notnull", &_0, 0, pagable, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&builder, this_ptr, "createbuilder", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&orderBys);
	array_init(&orderBys);
	ZEPHIR_CALL_METHOD(&_2, pagable, "getorderbys", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "strval");
	ZEPHIR_CALL_FUNCTION(&orderBys, "array_map", NULL, 34, &_3, &_2);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&orderBys))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_fast_join_str(&_4$$3, SL(", "), &orderBys TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &builder, "orderby", NULL, 0, &_4$$3);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&val);
	if (zephir_array_isset_string_fetch(&val, &params, SL("columns"), 0)) {
		ZEPHIR_CALL_METHOD(NULL, &builder, "columns", NULL, 0, &val);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_VAR(&_5$$5);
		ZVAL_STRING(&_5$$5, "*");
		ZEPHIR_CALL_METHOD(NULL, &builder, "columns", NULL, 0, &_5$$5);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&bind);
	array_init(&bind);
	ZEPHIR_OBS_NVAR(&val);
	if (zephir_array_isset_string_fetch(&val, &params, SL("bind"), 0)) {
		ZEPHIR_CPY_WRT(&bind, &val);
	}
	ZEPHIR_OBS_NVAR(&val);
	if (zephir_array_isset_string_fetch(&val, &params, SL("conditions"), 0)) {
		if (ZEPHIR_IS_EMPTY(&bind)) {
			ZEPHIR_CALL_METHOD(NULL, &builder, "where", NULL, 0, &val);
			zephir_check_call_status();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &builder, "where", NULL, 0, &val, &bind);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_VAR(&queryBuilder);
	object_init_ex(&queryBuilder, zephir_get_internal_ce(SL("phalcon\\paginator\\adapter\\querybuilder")));
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 3, 0 TSRMLS_CC);
	zephir_array_update_string(&_6, SL("builder"), &builder, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_7, pagable, "getpagesize", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_6, SL("limit"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_7, pagable, "getpageno", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(&_6, SL("page"), &_7, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, &queryBuilder, "__construct", NULL, 0, &_6);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&page, &queryBuilder, "getpaginate", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_8);
	zephir_read_property(&_8, &page, SL("items"), PH_NOISY_CC);
	if (Z_TYPE_P(&_8) == IS_OBJECT) {
		ZEPHIR_OBS_VAR(&hydration$$10);
		if (zephir_array_isset_string_fetch(&hydration$$10, &params, SL("hydration"), 0)) {
			zephir_read_property(&_9$$11, &page, SL("items"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(NULL, &_9$$11, "sethydratemode", NULL, 0, &hydration$$10);
			zephir_check_call_status();
		}
	}
	object_init_ex(return_value, phalconplus_base_page_ce);
	zephir_read_property(&_10, &page, SL("total_items"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_11, &page, SL("items"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 35, pagable, &_10, &_11);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if a reord is already exists?
 */
PHP_METHOD(PhalconPlus_Base_Model, exists) {

	zval metaData, readConnection, schema, source, table, _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&readConnection);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&readConnection, this_ptr, "getreadconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&schema, this_ptr, "getschema", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&source, this_ptr, "getsource", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&schema)) {
		ZEPHIR_INIT_VAR(&table);
		zephir_create_array(&table, 2, 0 TSRMLS_CC);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	zephir_read_property(&_0, this_ptr, SL("__p_UK"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_0))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "_p_buildukcond", NULL, 0, &metaData, &readConnection);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "_exists", NULL, 0, &metaData, &readConnection, &table);
	zephir_check_call_status();
	if (zephir_is_true(&_1)) {
		RETURN_MM_BOOL(1);
	} else {
		RETURN_MM_BOOL(0);
	}

}

/**
 * 如果想在更新某条记录的时候额外加入其他条件，可以使用此方法
 * where = [
 'id > ?',  // 占位符仅支持?形式，不支持:placeHolder这种形式
 'bind' => [
 14
 ]
 ];
 */
PHP_METHOD(PhalconPlus_Base_Model, setUpdateCond) {

	zephir_fcall_cache_entry *_3 = NULL, *_6 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, __$null, metaData, writeConnection, columnMap, bindDataTypes, primaryKeys, attributeField, pk, value, type, whereUk, uniqueParams, uniqueTypes, *_0, conditions, bind, bindTypes, _10, _15, _16, _17, _18, _19, _21, _22, _24, _1$$5, _2$$5, _4$$7, _5$$7, _7$$3, _9$$3, _11$$11, _12$$12, _13$$13, _14$$13, _20$$15, _23$$17;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&writeConnection);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&primaryKeys);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&pk);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&whereUk);
	ZVAL_UNDEF(&uniqueParams);
	ZVAL_UNDEF(&uniqueTypes);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&bind);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_18);
	ZVAL_UNDEF(&_19);
	ZVAL_UNDEF(&_21);
	ZVAL_UNDEF(&_22);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_11$$11);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$13);
	ZVAL_UNDEF(&_14$$13);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_23$$17);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &params_param);

	zephir_get_arrval(&params, params_param);


	ZEPHIR_INIT_VAR(&whereUk);
	array_init(&whereUk);
	ZEPHIR_INIT_VAR(&uniqueParams);
	array_init(&uniqueParams);
	ZEPHIR_INIT_VAR(&uniqueTypes);
	array_init(&uniqueTypes);
	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&writeConnection, this_ptr, "getwriteconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, &metaData, "getbindtypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&primaryKeys, &metaData, "getprimarykeyattributes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&primaryKeys, 0, "phalconplus/Base/Model.zep", 282);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _0)
	{
		ZEPHIR_INIT_NVAR(&pk);
		ZVAL_COPY(&pk, _0);
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_OBS_NVAR(&attributeField);
			if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &pk, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(&_1$$5);
				object_init_ex(&_1$$5, phalconplus_base_exception_ce);
				ZEPHIR_INIT_LNVAR(_2$$5);
				ZEPHIR_CONCAT_SVS(&_2$$5, "Model::setUpdateCond: Column '", &pk, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", &_3, 36, &_2$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_1$$5, "phalconplus/Base/Model.zep", 259 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&attributeField, &pk);
		}
		ZEPHIR_OBS_NVAR(&type);
		if (!(zephir_array_isset_fetch(&type, &bindDataTypes, &pk, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(&_4$$7);
			object_init_ex(&_4$$7, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_LNVAR(_5$$7);
			ZEPHIR_CONCAT_SVS(&_5$$7, "Model::setupdateCond: Column '", &pk, "' isn't part of the table columns");
			ZEPHIR_CALL_METHOD(NULL, &_4$$7, "__construct", &_6, 7, &_5$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_4$$7, "phalconplus/Base/Model.zep", 266 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&value);
		if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
			zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalconplus/Base/Model.zep", 270);
		} else {
			zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalconplus/Base/Model.zep", 272);
		}
		ZEPHIR_CALL_METHOD(&_7$$3, &writeConnection, "escapeidentifier", &_8, 0, &pk);
		zephir_check_call_status();
		ZEPHIR_INIT_LNVAR(_9$$3);
		ZEPHIR_CONCAT_VS(&_9$$3, &_7$$3, " = ?");
		zephir_array_append(&whereUk, &_9$$3, PH_SEPARATE, "phalconplus/Base/Model.zep", 275);
		zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalconplus/Base/Model.zep", 276);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&pk);
	ZEPHIR_OBS_VAR(&conditions);
	if (zephir_array_isset_long_fetch(&conditions, &params, 0, 0 TSRMLS_CC)) {
	} else {
		ZEPHIR_OBS_NVAR(&conditions);
		if (zephir_array_isset_string_fetch(&conditions, &params, SL("conditions"), 0)) {
		}
	}
	zephir_read_property(&_10, this_ptr, SL("_uniqueKey"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_10))) {
		ZEPHIR_INIT_VAR(&_11$$11);
		zephir_concat_self_str(&_11$$11, " AND ", sizeof(" AND ")-1 TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_uniqueKey"), &_11$$11);
	}
	if (Z_TYPE_P(&conditions) == IS_ARRAY) {
		zephir_merge_append(&whereUk, &conditions);
		ZEPHIR_INIT_VAR(&_12$$12);
		zephir_fast_join_str(&_12$$12, SL(" AND "), &whereUk TSRMLS_CC);
		zephir_update_property_zval(this_ptr, SL("_uniqueKey"), &_12$$12);
	} else if (Z_TYPE_P(&conditions) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_13$$13);
		zephir_fast_join_str(&_13$$13, SL(" AND "), &whereUk TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_14$$13);
		ZEPHIR_CONCAT_VSV(&_14$$13, &_13$$13, " AND ", &conditions);
		ZEPHIR_CPY_WRT(&conditions, &_14$$13);
		zephir_update_property_zval(this_ptr, SL("_uniqueKey"), &conditions);
	}
	ZEPHIR_INIT_VAR(&_15);
	ZEPHIR_CALL_FUNCTION(&_16, "array_values", NULL, 21, &columnMap);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_17);
	zephir_array_keys(&_17, &columnMap TSRMLS_CC);
	zephir_read_property(&_18, this_ptr, SL("_uniqueKey"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_str_replace(&_15, &_16, &_17, &_18 TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_uniqueKey"), &_15);
	ZEPHIR_OBS_VAR(&bind);
	if (zephir_array_isset_string_fetch(&bind, &params, SL("bind"), 0)) {
		zephir_merge_append(&uniqueParams, &bind);
	}
	zephir_read_property(&_19, this_ptr, SL("_uniqueParams"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_19) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_20$$15);
		array_init(&_20$$15);
		zephir_update_property_zval(this_ptr, SL("_uniqueParams"), &_20$$15);
	}
	zephir_read_property(&_21, this_ptr, SL("_uniqueParams"), PH_NOISY_CC | PH_READONLY);
	zephir_merge_append(&_21, &uniqueParams);
	ZEPHIR_OBS_VAR(&bindTypes);
	if (zephir_array_isset_string_fetch(&bindTypes, &params, SL("bindTypes"), 0)) {
		zephir_merge_append(&uniqueTypes, &bindTypes);
	}
	zephir_read_property(&_22, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_22) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_23$$17);
		array_init(&_23$$17);
		zephir_update_property_zval(this_ptr, SL("_uniqueTypes"), &_23$$17);
	}
	zephir_read_property(&_24, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC | PH_READONLY);
	zephir_merge_append(&_24, &uniqueTypes);
	RETURN_MM_BOOL(1);

}

/**
 * @alias setUqKeys
 */
PHP_METHOD(PhalconPlus_Base_Model, setUniqueKeys) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *whereUk_param = NULL;
	zval whereUk;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&whereUk);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &whereUk_param);

	zephir_get_arrval(&whereUk, whereUk_param);


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "setuqkeys", NULL, 0, &whereUk);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * columnMap field
 */
PHP_METHOD(PhalconPlus_Base_Model, setUqKeys) {

	zephir_fcall_cache_entry *_1 = NULL, *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *whereUk_param = NULL, field, attributeField, type, metaData, columnMap, bindDataTypes, *_0, tmp$$4, _2$$5, _3$$5, _5$$7, _6$$7, _7$$3;
	zval whereUk;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&whereUk);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&tmp$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &whereUk_param);

	zephir_get_arrval(&whereUk, whereUk_param);


	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, &metaData, "getbindtypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&whereUk, 0, "phalconplus/Base/Model.zep", 368);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&whereUk), _0)
	{
		ZEPHIR_INIT_NVAR(&attributeField);
		ZVAL_COPY(&attributeField, _0);
		if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
			ZEPHIR_CALL_FUNCTION(&tmp$$4, "array_flip", &_1, 32, &columnMap);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&field);
			if (!(zephir_array_isset_fetch(&field, &tmp$$4, &attributeField, 0 TSRMLS_CC))) {
				ZEPHIR_INIT_NVAR(&_2$$5);
				object_init_ex(&_2$$5, zend_exception_get_default(TSRMLS_C));
				ZEPHIR_INIT_LNVAR(_3$$5);
				ZEPHIR_CONCAT_SVS(&_3$$5, "Model::setUqKeys: Column '", &attributeField, "' isn't part of the column map");
				ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", &_4, 7, &_3$$5);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_2$$5, "phalconplus/Base/Model.zep", 354 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		} else {
			ZEPHIR_CPY_WRT(&field, &attributeField);
		}
		zephir_update_property_array_multi(this_ptr, SL("__p_UK"), &field TSRMLS_CC, SL("zs"), 3, &attributeField, SL("field"));
		ZEPHIR_OBS_NVAR(&type);
		if (!(zephir_array_isset_fetch(&type, &bindDataTypes, &field, 0 TSRMLS_CC))) {
			ZEPHIR_INIT_NVAR(&_5$$7);
			object_init_ex(&_5$$7, zend_exception_get_default(TSRMLS_C));
			ZEPHIR_INIT_LNVAR(_6$$7);
			ZEPHIR_CONCAT_SVS(&_6$$7, "Model::setUqKeys: Column '", &field, "' isn't part of the table columns");
			ZEPHIR_CALL_METHOD(NULL, &_5$$7, "__construct", &_4, 7, &_6$$7);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_5$$7, "phalconplus/Base/Model.zep", 363 TSRMLS_CC);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_update_property_array_multi(this_ptr, SL("__p_UK"), &type TSRMLS_CC, SL("zs"), 3, &attributeField, SL("type"));
		ZEPHIR_INIT_NVAR(&_7$$3);
		ZVAL_STRING(&_7$$3, "=");
		zephir_update_property_array_multi(this_ptr, SL("__p_UK"), &_7$$3 TSRMLS_CC, SL("zs"), 3, &attributeField, SL("op"));
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&attributeField);
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_Model, _p_buildUkCond) {

	zend_string *_3;
	zend_ulong _2;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, __$null, value, type, info, field, whereUk, uniqueParams, uniqueTypes, attributeField, _0, *_1, usefuleParams, _8, _9, selfVal$$4, _4$$3, _6$$3, _7$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData_sub);
	ZVAL_UNDEF(&connection_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&info);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&whereUk);
	ZVAL_UNDEF(&uniqueParams);
	ZVAL_UNDEF(&uniqueTypes);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&usefuleParams);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&selfVal$$4);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &metaData, &connection);



	ZEPHIR_INIT_VAR(&whereUk);
	array_init(&whereUk);
	ZEPHIR_INIT_VAR(&uniqueParams);
	array_init(&uniqueParams);
	ZEPHIR_INIT_VAR(&uniqueTypes);
	array_init(&uniqueTypes);
	zephir_read_property(&_0, this_ptr, SL("__p_UK"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalconplus/Base/Model.zep", 398);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _2, _3, _1)
	{
		ZEPHIR_INIT_NVAR(&attributeField);
		if (_3 != NULL) { 
			ZVAL_STR_COPY(&attributeField, _3);
		} else {
			ZVAL_LONG(&attributeField, _2);
		}
		ZEPHIR_INIT_NVAR(&info);
		ZVAL_COPY(&info, _1);
		ZEPHIR_OBS_NVAR(&type);
		zephir_array_fetch_string(&type, &info, SL("type"), PH_NOISY, "phalconplus/Base/Model.zep", 381 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&field);
		zephir_array_fetch_string(&field, &info, SL("field"), PH_NOISY, "phalconplus/Base/Model.zep", 382 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&value);
		ZVAL_NULL(&value);
		ZEPHIR_OBS_NVAR(&value);
		if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
			ZEPHIR_OBS_NVAR(&selfVal$$4);
			if (zephir_array_isset_string_fetch(&selfVal$$4, &info, SL("value"), 0)) {
				zephir_array_append(&uniqueParams, &selfVal$$4, PH_SEPARATE, "phalconplus/Base/Model.zep", 387);
			} else {
				zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalconplus/Base/Model.zep", 389);
			}
		} else {
			zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalconplus/Base/Model.zep", 392);
		}
		zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalconplus/Base/Model.zep", 394);
		ZEPHIR_CALL_METHOD(&_4$$3, connection, "escapeidentifier", &_5, 0, &field);
		zephir_check_call_status();
		zephir_array_fetch_string(&_6$$3, &info, SL("op"), PH_NOISY | PH_READONLY, "phalconplus/Base/Model.zep", 395 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_7$$3);
		ZEPHIR_CONCAT_VSVS(&_7$$3, &_4$$3, " ", &_6$$3, " ?");
		zephir_array_append(&whereUk, &_7$$3, PH_SEPARATE, "phalconplus/Base/Model.zep", 395);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&info);
	ZEPHIR_INIT_NVAR(&attributeField);
	ZEPHIR_INIT_VAR(&usefuleParams);
	array_init(&usefuleParams);
	ZEPHIR_INIT_VAR(&_8);
	ZEPHIR_INIT_NVAR(&_8);
	zephir_create_closure_ex(&_8, NULL, phalconplus_1__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_FUNCTION(&usefuleParams, "array_filter", NULL, 19, &uniqueParams, &_8);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&usefuleParams)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_INIT_VAR(&_9);
	zephir_fast_join_str(&_9, SL(" AND "), &whereUk TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_uniqueKey"), &_9);
	zephir_update_property_zval(this_ptr, SL("_uniqueParams"), &uniqueParams);
	zephir_update_property_zval(this_ptr, SL("_uniqueTypes"), &uniqueTypes);
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Base_Model, toProtoBuffer) {

	zend_string *_2;
	zend_ulong _1;
	zephir_fcall_cache_entry *_4 = NULL, *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columns = NULL, columns_sub, __$null, proto, toArray, key, val, *_0, modelName, manager, relations, referenceModel, referencedEntity, options, alias, lowerAlias, *_5, _3$$3, method$$4, property$$4, _7$$4, _8$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&proto);
	ZVAL_UNDEF(&toArray);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&referenceModel);
	ZVAL_UNDEF(&referencedEntity);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&lowerAlias);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&method$$4);
	ZVAL_UNDEF(&property$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &columns);

	if (!columns) {
		columns = &columns_sub;
		columns = &__$null;
	}


	ZEPHIR_CALL_METHOD(&toArray, this_ptr, "toarray", NULL, 0, columns);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&proto);
	object_init_ex(&proto, phalconplus_base_protobuffer_ce);
	if (zephir_has_constructor(&proto TSRMLS_CC)) {
		ZEPHIR_CALL_METHOD(NULL, &proto, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_is_iterable(&toArray, 0, "phalconplus/Base/Model.zep", 421);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&toArray), _1, _2, _0)
	{
		ZEPHIR_INIT_NVAR(&key);
		if (_2 != NULL) { 
			ZVAL_STR_COPY(&key, _2);
		} else {
			ZVAL_LONG(&key, _1);
		}
		ZEPHIR_INIT_NVAR(&val);
		ZVAL_COPY(&val, _0);
		ZEPHIR_INIT_LNVAR(_3$$3);
		if (zephir_is_scalar(&val)) {
			ZEPHIR_CPY_WRT(&_3$$3, &val);
		} else {
			ZEPHIR_CALL_FUNCTION(&_3$$3, "strval", &_4, 27, &val);
			zephir_check_call_status();
		}
		zephir_update_property_zval_zval(&proto, &key, &_3$$3 TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_class(&modelName, this_ptr, 0 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&relations, &manager, "getrelations", NULL, 0, &modelName);
	zephir_check_call_status();
	zephir_is_iterable(&relations, 0, "phalconplus/Base/Model.zep", 442);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relations), _5)
	{
		ZEPHIR_INIT_NVAR(&val);
		ZVAL_COPY(&val, _5);
		ZEPHIR_CALL_METHOD(&referenceModel, &val, "getreferencedmodel", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&referencedEntity);
		zephir_fast_strtolower(&referencedEntity, &referenceModel);
		ZEPHIR_CALL_METHOD(&options, &val, "getoptions", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_NVAR(&alias);
		if (zephir_array_isset_string_fetch(&alias, &options, SL("alias"), 0)) {
			if (Z_TYPE_P(&alias) != IS_STRING) {
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Relation alias must be a string", "phalconplus/Base/Model.zep", 431);
				return;
			}
			ZEPHIR_INIT_NVAR(&lowerAlias);
			zephir_fast_strtolower(&lowerAlias, &alias);
		} else {
			ZEPHIR_CPY_WRT(&lowerAlias, &referencedEntity);
		}
		ZEPHIR_INIT_NVAR(&method$$4);
		ZEPHIR_CONCAT_SV(&method$$4, "get", &alias);
		ZEPHIR_CALL_FUNCTION(&property$$4, "lcfirst", &_6, 37, &alias);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD_ZVAL(&_7$$4, this_ptr, &method$$4, NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_8$$4, &_7$$4, "toarray", NULL, 0);
		zephir_check_call_status();
		zephir_update_property_zval_zval(&proto, &property$$4, &_8$$4 TSRMLS_CC);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&val);
	RETURN_CCTOR(&proto);

}

/**
 * Gets the connection used to read data for the model
 *
 * Check transaction in writeConnection before `_transaction`
 */
PHP_METHOD(PhalconPlus_Base_Model, getReadConnection) {

	zval dbConn, _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&dbConn);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&dbConn, this_ptr, "getwriteconnection", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_0, &dbConn, "isundertransaction", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_CCTOR(&dbConn);
	} else {
		ZEPHIR_RETURN_CALL_PARENT(phalconplus_base_model_ce, getThis(), "getreadconnection", NULL, 0);
		zephir_check_call_status();
		RETURN_MM();
	}

}

zend_object *zephir_init_properties_PhalconPlus_Base_Model(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("__p_UK"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("__p_UK"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

