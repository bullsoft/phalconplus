
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_Model) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, Model, phalconplus, base_model, zephir_get_internal_ce(SL("phalcon\\mvc\\model")), phalconplus_base_model_method_entry, 0);

	zend_declare_property_null(phalconplus_base_model_ce, SL("ctime"), ZEND_ACC_PUBLIC);

	zend_declare_property_null(phalconplus_base_model_ce, SL("mtime"), ZEND_ACC_PUBLIC);

	zend_declare_property_null(phalconplus_base_model_ce, SL("__uniqueKeys"), ZEND_ACC_PROTECTED);

	zend_declare_property_bool(phalconplus_base_model_ce, SL("optimisticLock"), 0, ZEND_ACC_PROTECTED);

	phalconplus_base_model_ce->create_object = zephir_init_properties_PhalconPlus_Base_Model;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_Model, initialize) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval __$false, __$true, _1;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$false, 0);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 3, 0);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();


	ZEPHIR_MM_GROW();

	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getfirstmessage", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_Model, getFirstMessage) {

	zval _3$$3;
	zval _0, _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmessages", NULL, 0);
	zephir_check_call_status();
	if (zephir_fast_count_int(&_0)) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "getmessages", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&_2$$3, "current", NULL, 36, &_1$$3);
		zephir_check_call_status();
		zephir_get_strval(&_3$$3, &_2$$3);
		RETURN_CTOR(&_3$$3);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Base_Model, getLastMessage) {

	zval _3$$3;
	zval _0, _1$$3, _2$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getmessages", NULL, 0);
	zephir_check_call_status();
	if (zephir_fast_count_int(&_0)) {
		ZEPHIR_CALL_METHOD(&_1$$3, this_ptr, "getmessages", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_MAKE_REF(&_1$$3);
		ZEPHIR_CALL_FUNCTION(&_2$$3, "end", NULL, 37, &_1$$3);
		ZEPHIR_UNREF(&_1$$3);
		zephir_check_call_status();
		zephir_get_strval(&_3$$3, &_2$$3);
		RETURN_CTOR(&_3$$3);
	}
	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Base_Model, createBuilder) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be of the type string"));
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
		zephir_create_array(&source, 1, 0);
		ZEPHIR_INIT_VAR(&_0$$3);
		zephir_get_called_class(&_0$$3);
		zephir_array_update_zval(&source, &alias, &_0$$3, PH_COPY);
	} else {
		ZEPHIR_INIT_NVAR(&source);
		zephir_get_called_class(&source);
	}
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &_1, "createbuilder", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_2, "from", NULL, 0, &source);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_Model, newInstance) {

	zend_class_entry *_1;
	zval className, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&className);
	zephir_get_called_class(&className);
	zephir_fetch_safe_class(&_0, &className);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	if(!_1) {
		RETURN_MM_NULL();
	}
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_Model, batchInsert) {

	zend_class_entry *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_10 = NULL, *_11 = NULL, *_13 = NULL, *_14 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columns_param = NULL, *rows_param = NULL, model, conn, e, row, columnMap, newColumns, className, _0, _15, _2$$3, val$$3, *_3$$3, _4$$3, _5$$5, _6$$7, *_7$$9, _8$$9, _9$$10, _12$$11;
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
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&val$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_12$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &columns_param, &rows_param);

	zephir_get_arrval(&columns, columns_param);
	zephir_get_arrval(&rows, rows_param);


	ZEPHIR_INIT_VAR(&columnMap);
	array_init(&columnMap);
	ZEPHIR_INIT_VAR(&newColumns);
	array_init(&newColumns);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_called_class(&className);
	ZEPHIR_INIT_VAR(&model);
	zephir_fetch_safe_class(&_0, &className);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	if(!_1) {
		RETURN_MM_NULL();
	}
	object_init_ex(&model, _1);
	if (zephir_has_constructor(&model)) {
		ZEPHIR_CALL_METHOD(NULL, &model, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	if ((zephir_method_exists_ex(&model, ZEND_STRL("columnmap")) == SUCCESS)) {
		ZEPHIR_CALL_METHOD(&_2$$3, &model, "columnmap", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&columnMap, "array_flip", NULL, 38, &_2$$3);
		zephir_check_call_status();
		zephir_is_iterable(&columns, 0, "phalconplus/Base/Model.zep", 92);
		if (Z_TYPE_P(&columns) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&columns), _3$$3)
			{
				ZEPHIR_INIT_NVAR(&val$$3);
				ZVAL_COPY(&val$$3, _3$$3);
				if (zephir_array_isset(&columnMap, &val$$3)) {
					zephir_array_fetch(&_5$$5, &columnMap, &val$$3, PH_NOISY | PH_READONLY, "phalconplus/Base/Model.zep", 89);
					zephir_array_append(&newColumns, &_5$$5, PH_SEPARATE, "phalconplus/Base/Model.zep", 89);
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &columns, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_4$$3, &columns, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_4$$3)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&val$$3, &columns, "current", NULL, 0);
				zephir_check_call_status();
					if (zephir_array_isset(&columnMap, &val$$3)) {
						zephir_array_fetch(&_6$$7, &columnMap, &val$$3, PH_NOISY | PH_READONLY, "phalconplus/Base/Model.zep", 89);
						zephir_array_append(&newColumns, &_6$$7, PH_SEPARATE, "phalconplus/Base/Model.zep", 89);
					}
				ZEPHIR_CALL_METHOD(NULL, &columns, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&val$$3);
	} else {
		ZEPHIR_CPY_WRT(&newColumns, &columns);
	}
	ZEPHIR_CALL_METHOD(&conn, &model, "getwriteconnection", NULL, 0);
	zephir_check_call_status();

	/* try_start_1: */

		ZEPHIR_CALL_METHOD(NULL, &conn, "begin", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);
		zephir_is_iterable(&rows, 0, "phalconplus/Base/Model.zep", 101);
		if (Z_TYPE_P(&rows) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&rows), _7$$9)
			{
				ZEPHIR_INIT_NVAR(&row);
				ZVAL_COPY(&row, _7$$9);
				ZEPHIR_CALL_METHOD(&_9$$10, &model, "getsource", &_10, 0);
				zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CALL_METHOD(NULL, &conn, "insert", &_11, 0, &_9$$10, &row, &newColumns);
				zephir_check_call_status_or_jump(try_end_1);
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &rows, "rewind", NULL, 0);
			zephir_check_call_status();
			while (1) {
				ZEPHIR_CALL_METHOD(&_8$$9, &rows, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_8$$9)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&row, &rows, "current", NULL, 0);
				zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_12$$11, &model, "getsource", &_13, 0);
					zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CALL_METHOD(NULL, &conn, "insert", &_14, 0, &_12$$11, &row, &newColumns);
					zephir_check_call_status_or_jump(try_end_1);
				ZEPHIR_CALL_METHOD(NULL, &rows, "next", NULL, 0);
				zephir_check_call_status();
			}
		}
		ZEPHIR_INIT_NVAR(&row);
		ZEPHIR_CALL_METHOD(NULL, &conn, "commit", NULL, 0);
		zephir_check_call_status_or_jump(try_end_1);

	try_end_1:

	if (EG(exception)) {
		ZEPHIR_INIT_VAR(&_15);
		ZVAL_OBJ(&_15, EG(exception));
		Z_ADDREF_P(&_15);
		if (zephir_instance_of_ev(&_15, zend_exception_get_default(TSRMLS_C))) {
			zend_clear_exception(TSRMLS_C);
			ZEPHIR_CPY_WRT(&e, &_15);
			ZEPHIR_CALL_METHOD(NULL, &conn, "rollback", NULL, 0);
			zephir_check_call_status();
			zephir_throw_exception_debug(&e, "phalconplus/Base/Model.zep", 104);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Base_Model, beforeValidationOnCreate) {

	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Y-m-d H:i:s");
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 39, &_0);
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Y-m-d H:i:s");
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 39, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("ctime"), &_1);
	zephir_read_property(&_2, this_ptr, SL("ctime"), PH_NOISY_CC | PH_READONLY);
	zephir_update_property_zval(this_ptr, SL("mtime"), &_2);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_Model, beforeSave) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "Y-m-d H:i:s");
	ZEPHIR_CALL_FUNCTION(&_1, "date", NULL, 39, &_0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("mtime"), &_1);
	RETURN_MM_BOOL(1);

}

PHP_METHOD(PhalconPlus_Base_Model, afterSave) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("optimisticLock"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_TRUE(&_0)) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "resetuniquefields", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM_BOOL(1);

}

/**
 * @alias findByPagable()
 */
PHP_METHOD(PhalconPlus_Base_Model, findByPageable) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval params;
	zval *pagable, pagable_sub, *params_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pagable_sub);
	ZVAL_UNDEF(&params);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pagable, &params_param);

	if (!params_param) {
		ZEPHIR_INIT_VAR(&params);
		array_init(&params);
	} else {
		zephir_get_arrval(&params, params_param);
	}


	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "findbypagable", NULL, 0, pagable, &params);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * find with paginator
 * Sorry for the typo with method name 
 *
 * @var array params
 *    - params["columns"]
 *    - params["conditions"]
 *    - params["bind"]
 *    - params["hydration"]: \Phalcon\Mvc\Model\Resultset::HYDRATE_OBJECTS | HYDRATE_ARRAYS | HYDRATE_RECORDS
 *
 */
PHP_METHOD(PhalconPlus_Base_Model, findByPagable) {

	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	ZEPHIR_CALL_FUNCTION(&orderBys, "array_map", NULL, 32, &_3, &_2);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&orderBys))) {
		ZEPHIR_INIT_VAR(&_4$$3);
		zephir_fast_join_str(&_4$$3, SL(", "), &orderBys);
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
	zephir_create_array(&_6, 3, 0);
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
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 40, pagable, &_10, &_11);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check if a reord is already exists?
 */
PHP_METHOD(PhalconPlus_Base_Model, exists) {

	zval metaData, readConnection, schema, source, table, builds, num, _0, _2, _3, _4, _5, _6, _7, _8, _1$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&readConnection);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&source);
	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&builds);
	ZVAL_UNDEF(&num);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1$$5);

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
		zephir_create_array(&table, 2, 0);
		zephir_array_fast_append(&table, &schema);
		zephir_array_fast_append(&table, &source);
	} else {
		ZEPHIR_CPY_WRT(&table, &source);
	}
	zephir_read_property(&_0, this_ptr, SL("__uniqueKeys"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		ZEPHIR_CALL_METHOD(&_1$$5, this_ptr, "_exists", NULL, 0, &metaData, &readConnection, &table);
		zephir_check_call_status();
		if (zephir_is_true(&_1$$5)) {
			RETURN_MM_BOOL(1);
		}
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&builds, this_ptr, "__builduniquecondition", NULL, 0, &metaData, &readConnection);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&builds)) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&_2, &readConnection, "escapeidentifier", NULL, 0, &table);
	zephir_check_call_status();
	zephir_array_fetch_string(&_3, &builds, SL("uniqueKey"), PH_NOISY | PH_READONLY, "phalconplus/Base/Model.zep", 242);
	ZEPHIR_INIT_VAR(&_4);
	ZEPHIR_CONCAT_SVSV(&_4, "SELECT COUNT(*) \"rowcount\" FROM ", &_2, " WHERE ", &_3);
	zephir_array_fetch_string(&_5, &builds, SL("uniqueParams"), PH_NOISY | PH_READONLY, "phalconplus/Base/Model.zep", 244);
	zephir_array_fetch_string(&_6, &builds, SL("uniqueTypes"), PH_NOISY | PH_READONLY, "phalconplus/Base/Model.zep", 246);
	ZVAL_NULL(&_7);
	ZEPHIR_CALL_METHOD(&num, &readConnection, "fetchone", NULL, 0, &_4, &_7, &_5, &_6);
	zephir_check_call_status();
	zephir_array_fetch_string(&_8, &num, SL("rowcount"), PH_NOISY | PH_READONLY, "phalconplus/Base/Model.zep", 247);
	if (zephir_is_true(&_8)) {
		RETURN_MM_BOOL(1);
	}
	RETURN_MM_BOOL(0);

}

/**
 * 如果想在更新某条记录的时候额外加入其他条件，可以使用此方法
 * where = [
 'id > ?',  // 特别注意！！！ 占位符仅支持?形式，不支持:placeHolder这种形式
 'bind' => [
 14
 ]
 ];
 */
PHP_METHOD(PhalconPlus_Base_Model, setUpdateCondition) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_8 = NULL, *_15 = NULL, *_38 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *params_param = NULL, __$null, __$true, __$false, metaData, writeConnection, columnMap, bindDataTypes, primaryKeys, attributeField, pk, value, type, whereUk, uniqueParams, uniqueTypes, *_0, _1, conditions, bind, bindTypes, _17, _26, _27, _28, _29, countKeys, _30, _31, _32, _34, _35, _36, _37, _40, _41, _42, _43, _2$$5, _3$$5, _5$$7, _6$$7, _7$$3, _9$$3, _10$$12, _11$$12, _12$$14, _13$$14, _14$$10, _16$$10, _18$$18, _19$$18, _20$$19, _21$$19, _22$$19, _23$$20, _24$$20, _25$$20, _33$$22, _39$$24;
	zval params;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&params);
	ZVAL_NULL(&__$null);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
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
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&conditions);
	ZVAL_UNDEF(&bind);
	ZVAL_UNDEF(&bindTypes);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_27);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_29);
	ZVAL_UNDEF(&countKeys);
	ZVAL_UNDEF(&_30);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_32);
	ZVAL_UNDEF(&_34);
	ZVAL_UNDEF(&_35);
	ZVAL_UNDEF(&_36);
	ZVAL_UNDEF(&_37);
	ZVAL_UNDEF(&_40);
	ZVAL_UNDEF(&_41);
	ZVAL_UNDEF(&_42);
	ZVAL_UNDEF(&_43);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$12);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$14);
	ZVAL_UNDEF(&_13$$14);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_18$$18);
	ZVAL_UNDEF(&_19$$18);
	ZVAL_UNDEF(&_20$$19);
	ZVAL_UNDEF(&_21$$19);
	ZVAL_UNDEF(&_22$$19);
	ZVAL_UNDEF(&_23$$20);
	ZVAL_UNDEF(&_24$$20);
	ZVAL_UNDEF(&_25$$20);
	ZVAL_UNDEF(&_33$$22);
	ZVAL_UNDEF(&_39$$24);

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
	zephir_is_iterable(&primaryKeys, 0, "phalconplus/Base/Model.zep", 303);
	if (Z_TYPE_P(&primaryKeys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&primaryKeys), _0)
		{
			ZEPHIR_INIT_NVAR(&pk);
			ZVAL_COPY(&pk, _0);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_OBS_NVAR(&attributeField);
				if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &pk, 0))) {
					ZEPHIR_INIT_NVAR(&_2$$5);
					object_init_ex(&_2$$5, phalconplus_base_exception_ce);
					ZEPHIR_INIT_NVAR(&_3$$5);
					ZEPHIR_CONCAT_SVS(&_3$$5, "Model::setUpdateCond: Column '", &pk, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", &_4, 25, &_3$$5);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_2$$5, "phalconplus/Base/Model.zep", 280);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&attributeField, &pk);
			}
			ZEPHIR_OBS_NVAR(&type);
			if (!(zephir_array_isset_fetch(&type, &bindDataTypes, &pk, 0))) {
				ZEPHIR_INIT_NVAR(&_5$$7);
				object_init_ex(&_5$$7, phalconplus_base_exception_ce);
				ZEPHIR_INIT_NVAR(&_6$$7);
				ZEPHIR_CONCAT_SVS(&_6$$7, "Model::setupdateCond: Column '", &pk, "' isn't part of the table columns");
				ZEPHIR_CALL_METHOD(NULL, &_5$$7, "__construct", &_4, 25, &_6$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$7, "phalconplus/Base/Model.zep", 287);
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&value);
			if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
				zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalconplus/Base/Model.zep", 291);
			} else {
				zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalconplus/Base/Model.zep", 293);
			}
			ZEPHIR_CALL_METHOD(&_7$$3, &writeConnection, "escapeidentifier", &_8, 0, &pk);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&_9$$3);
			ZEPHIR_CONCAT_VS(&_9$$3, &_7$$3, " = ?");
			zephir_array_append(&whereUk, &_9$$3, PH_SEPARATE, "phalconplus/Base/Model.zep", 296);
			zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalconplus/Base/Model.zep", 297);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &primaryKeys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&pk, &primaryKeys, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_OBS_NVAR(&attributeField);
					if (!(zephir_array_isset_fetch(&attributeField, &columnMap, &pk, 0))) {
						ZEPHIR_INIT_NVAR(&_10$$12);
						object_init_ex(&_10$$12, phalconplus_base_exception_ce);
						ZEPHIR_INIT_NVAR(&_11$$12);
						ZEPHIR_CONCAT_SVS(&_11$$12, "Model::setUpdateCond: Column '", &pk, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_10$$12, "__construct", &_4, 25, &_11$$12);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_10$$12, "phalconplus/Base/Model.zep", 280);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&attributeField, &pk);
				}
				ZEPHIR_OBS_NVAR(&type);
				if (!(zephir_array_isset_fetch(&type, &bindDataTypes, &pk, 0))) {
					ZEPHIR_INIT_NVAR(&_12$$14);
					object_init_ex(&_12$$14, phalconplus_base_exception_ce);
					ZEPHIR_INIT_NVAR(&_13$$14);
					ZEPHIR_CONCAT_SVS(&_13$$14, "Model::setupdateCond: Column '", &pk, "' isn't part of the table columns");
					ZEPHIR_CALL_METHOD(NULL, &_12$$14, "__construct", &_4, 25, &_13$$14);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_12$$14, "phalconplus/Base/Model.zep", 287);
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&value);
				if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
					zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalconplus/Base/Model.zep", 291);
				} else {
					zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalconplus/Base/Model.zep", 293);
				}
				ZEPHIR_CALL_METHOD(&_14$$10, &writeConnection, "escapeidentifier", &_15, 0, &pk);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_16$$10);
				ZEPHIR_CONCAT_VS(&_16$$10, &_14$$10, " = ?");
				zephir_array_append(&whereUk, &_16$$10, PH_SEPARATE, "phalconplus/Base/Model.zep", 296);
				zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalconplus/Base/Model.zep", 297);
			ZEPHIR_CALL_METHOD(NULL, &primaryKeys, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&pk);
	ZEPHIR_OBS_VAR(&conditions);
	if (zephir_array_isset_long_fetch(&conditions, &params, 0, 0)) {
	} else {
		ZEPHIR_OBS_NVAR(&conditions);
		if (zephir_array_isset_string_fetch(&conditions, &params, SL("conditions"), 0)) {
		}
	}
	zephir_read_property(&_17, this_ptr, SL("_uniqueKey"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_17))) {
		zephir_read_property(&_18$$18, this_ptr, SL("_uniqueKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_19$$18);
		ZEPHIR_CONCAT_VS(&_19$$18, &_18$$18, " AND ");
		zephir_update_property_zval(this_ptr, SL("_uniqueKey"), &_19$$18);
	}
	if (Z_TYPE_P(&conditions) == IS_ARRAY) {
		zephir_merge_append(&whereUk, &conditions);
		zephir_read_property(&_20$$19, this_ptr, SL("_uniqueKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_21$$19);
		zephir_fast_join_str(&_21$$19, SL(" AND "), &whereUk);
		ZEPHIR_INIT_VAR(&_22$$19);
		ZEPHIR_CONCAT_VV(&_22$$19, &_20$$19, &_21$$19);
		zephir_update_property_zval(this_ptr, SL("_uniqueKey"), &_22$$19);
	} else if (Z_TYPE_P(&conditions) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_23$$20);
		zephir_fast_join_str(&_23$$20, SL(" AND "), &whereUk);
		ZEPHIR_INIT_VAR(&_24$$20);
		ZEPHIR_CONCAT_VSV(&_24$$20, &_23$$20, " AND ", &conditions);
		ZEPHIR_CPY_WRT(&conditions, &_24$$20);
		zephir_read_property(&_25$$20, this_ptr, SL("_uniqueKey"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_NVAR(&_24$$20);
		ZEPHIR_CONCAT_VV(&_24$$20, &_25$$20, &conditions);
		zephir_update_property_zval(this_ptr, SL("_uniqueKey"), &_24$$20);
	}
	ZEPHIR_INIT_VAR(&_26);
	ZEPHIR_CALL_FUNCTION(&_27, "array_values", NULL, 21, &columnMap);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_28);
	zephir_array_keys(&_28, &columnMap);
	zephir_read_property(&_29, this_ptr, SL("_uniqueKey"), PH_NOISY_CC | PH_READONLY);
	zephir_fast_str_replace(&_26, &_27, &_28, &_29);
	zephir_update_property_zval(this_ptr, SL("_uniqueKey"), &_26);
	zephir_read_property(&_30, this_ptr, SL("_uniqueKey"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_31);
	ZVAL_STRING(&_31, "= ?");
	ZEPHIR_CALL_FUNCTION(&countKeys, "substr_count", NULL, 23, &_30, &_31);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&bind);
	if (zephir_array_isset_string_fetch(&bind, &params, SL("bind"), 0)) {
		zephir_merge_append(&uniqueParams, &bind);
	}
	zephir_read_property(&_32, this_ptr, SL("_uniqueParams"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_32) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_33$$22);
		array_init(&_33$$22);
		zephir_update_property_zval(this_ptr, SL("_uniqueParams"), &_33$$22);
	}
	zephir_read_property(&_34, this_ptr, SL("_uniqueParams"), PH_NOISY_CC | PH_READONLY);
	zephir_merge_append(&_34, &uniqueParams);
	zephir_read_property(&_35, this_ptr, SL("_uniqueParams"), PH_NOISY_CC | PH_READONLY);
	ZVAL_NULL(&_36);
	ZEPHIR_CALL_FUNCTION(&_37, "array_pad", &_38, 41, &_35, &countKeys, &_36);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_uniqueParams"), &_37);
	ZEPHIR_OBS_VAR(&bindTypes);
	if (zephir_array_isset_string_fetch(&bindTypes, &params, SL("bindTypes"), 0)) {
		zephir_merge_append(&uniqueTypes, &bindTypes);
	}
	zephir_read_property(&_36, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_36) == IS_NULL) {
		ZEPHIR_INIT_VAR(&_39$$24);
		array_init(&_39$$24);
		zephir_update_property_zval(this_ptr, SL("_uniqueTypes"), &_39$$24);
	}
	zephir_read_property(&_40, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC | PH_READONLY);
	zephir_merge_append(&_40, &uniqueTypes);
	zephir_read_property(&_41, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_42, 1024);
	ZEPHIR_CALL_FUNCTION(&_43, "array_pad", &_38, 41, &_41, &countKeys, &_42);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_uniqueTypes"), &_43);
	if (1) {
		zephir_update_property_zval(this_ptr, SL("optimisticLock"), &__$true);
	} else {
		zephir_update_property_zval(this_ptr, SL("optimisticLock"), &__$false);
	}
	RETURN_MM_BOOL(1);

}

/**
 * columnMap field
 */
PHP_METHOD(PhalconPlus_Base_Model, setUniqueKeys) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *whereUk_param = NULL, field, attributeField, type, metaData, columnMap, bindDataTypes, *_0, _1, tmp$$4, _3$$5, _4$$5, _6$$7, _7$$7, _8$$3, tmp$$9, _9$$10, _10$$10, _11$$12, _12$$12, _13$$8;
	zval whereUk;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&whereUk);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&attributeField);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&metaData);
	ZVAL_UNDEF(&columnMap);
	ZVAL_UNDEF(&bindDataTypes);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&tmp$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&tmp$$9);
	ZVAL_UNDEF(&_9$$10);
	ZVAL_UNDEF(&_10$$10);
	ZVAL_UNDEF(&_11$$12);
	ZVAL_UNDEF(&_12$$12);
	ZVAL_UNDEF(&_13$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &whereUk_param);

	zephir_get_arrval(&whereUk, whereUk_param);


	ZEPHIR_CALL_METHOD(&metaData, this_ptr, "getmodelsmetadata", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&columnMap, &metaData, "getcolumnmap", NULL, 0, this_ptr);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&bindDataTypes, &metaData, "getbindtypes", NULL, 0, this_ptr);
	zephir_check_call_status();
	zephir_is_iterable(&whereUk, 0, "phalconplus/Base/Model.zep", 386);
	if (Z_TYPE_P(&whereUk) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&whereUk), _0)
		{
			ZEPHIR_INIT_NVAR(&attributeField);
			ZVAL_COPY(&attributeField, _0);
			if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
				ZEPHIR_CALL_FUNCTION(&tmp$$4, "array_flip", &_2, 38, &columnMap);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&field);
				if (!(zephir_array_isset_fetch(&field, &tmp$$4, &attributeField, 0))) {
					ZEPHIR_INIT_NVAR(&_3$$5);
					object_init_ex(&_3$$5, phalconplus_base_exception_ce);
					ZEPHIR_INIT_NVAR(&_4$$5);
					ZEPHIR_CONCAT_SVS(&_4$$5, "Model::setUqKeys: Column '", &attributeField, "' isn't part of the column map");
					ZEPHIR_CALL_METHOD(NULL, &_3$$5, "__construct", &_5, 25, &_4$$5);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_3$$5, "phalconplus/Base/Model.zep", 372);
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_CPY_WRT(&field, &attributeField);
			}
			zephir_update_property_array_multi(this_ptr, SL("__uniqueKeys"), &field, SL("zs"), 3, &attributeField, SL("field"));
			ZEPHIR_OBS_NVAR(&type);
			if (!(zephir_array_isset_fetch(&type, &bindDataTypes, &field, 0))) {
				ZEPHIR_INIT_NVAR(&_6$$7);
				object_init_ex(&_6$$7, phalconplus_base_exception_ce);
				ZEPHIR_INIT_NVAR(&_7$$7);
				ZEPHIR_CONCAT_SVS(&_7$$7, "Model::setUqKeys: Column '", &field, "' isn't part of the table columns");
				ZEPHIR_CALL_METHOD(NULL, &_6$$7, "__construct", &_5, 25, &_7$$7);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_6$$7, "phalconplus/Base/Model.zep", 381);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_update_property_array_multi(this_ptr, SL("__uniqueKeys"), &type, SL("zs"), 3, &attributeField, SL("type"));
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZVAL_STRING(&_8$$3, "=");
			zephir_update_property_array_multi(this_ptr, SL("__uniqueKeys"), &_8$$3, SL("zs"), 3, &attributeField, SL("op"));
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &whereUk, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &whereUk, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attributeField, &whereUk, "current", NULL, 0);
			zephir_check_call_status();
				if (Z_TYPE_P(&columnMap) == IS_ARRAY) {
					ZEPHIR_CALL_FUNCTION(&tmp$$9, "array_flip", &_2, 38, &columnMap);
					zephir_check_call_status();
					ZEPHIR_OBS_NVAR(&field);
					if (!(zephir_array_isset_fetch(&field, &tmp$$9, &attributeField, 0))) {
						ZEPHIR_INIT_NVAR(&_9$$10);
						object_init_ex(&_9$$10, phalconplus_base_exception_ce);
						ZEPHIR_INIT_NVAR(&_10$$10);
						ZEPHIR_CONCAT_SVS(&_10$$10, "Model::setUqKeys: Column '", &attributeField, "' isn't part of the column map");
						ZEPHIR_CALL_METHOD(NULL, &_9$$10, "__construct", &_5, 25, &_10$$10);
						zephir_check_call_status();
						zephir_throw_exception_debug(&_9$$10, "phalconplus/Base/Model.zep", 372);
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_CPY_WRT(&field, &attributeField);
				}
				zephir_update_property_array_multi(this_ptr, SL("__uniqueKeys"), &field, SL("zs"), 3, &attributeField, SL("field"));
				ZEPHIR_OBS_NVAR(&type);
				if (!(zephir_array_isset_fetch(&type, &bindDataTypes, &field, 0))) {
					ZEPHIR_INIT_NVAR(&_11$$12);
					object_init_ex(&_11$$12, phalconplus_base_exception_ce);
					ZEPHIR_INIT_NVAR(&_12$$12);
					ZEPHIR_CONCAT_SVS(&_12$$12, "Model::setUqKeys: Column '", &field, "' isn't part of the table columns");
					ZEPHIR_CALL_METHOD(NULL, &_11$$12, "__construct", &_5, 25, &_12$$12);
					zephir_check_call_status();
					zephir_throw_exception_debug(&_11$$12, "phalconplus/Base/Model.zep", 381);
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_update_property_array_multi(this_ptr, SL("__uniqueKeys"), &type, SL("zs"), 3, &attributeField, SL("type"));
				ZEPHIR_INIT_NVAR(&_13$$8);
				ZVAL_STRING(&_13$$8, "=");
				zephir_update_property_array_multi(this_ptr, SL("__uniqueKeys"), &_13$$8, SL("zs"), 3, &attributeField, SL("op"));
			ZEPHIR_CALL_METHOD(NULL, &whereUk, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&attributeField);
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_Model, __buildUniqueCondition) {

	zend_string *_4;
	zend_ulong _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_6 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *metaData, metaData_sub, *connection, connection_sub, __$null, value, type, info, field, whereUk, uniqueParams, uniqueTypes, attributeField, _0, *_1, _2, usefulParams, _12, _13, selfVal$$4, _5$$3, _7$$3, _8$$3, selfVal$$9, _9$$8, _10$$8, _11$$8;
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
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&usefulParams);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&selfVal$$4);
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&selfVal$$9);
	ZVAL_UNDEF(&_9$$8);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &metaData, &connection);



	ZEPHIR_INIT_VAR(&whereUk);
	array_init(&whereUk);
	ZEPHIR_INIT_VAR(&uniqueParams);
	array_init(&uniqueParams);
	ZEPHIR_INIT_VAR(&uniqueTypes);
	array_init(&uniqueTypes);
	zephir_read_property(&_0, this_ptr, SL("__uniqueKeys"), PH_NOISY_CC | PH_READONLY);
	zephir_is_iterable(&_0, 0, "phalconplus/Base/Model.zep", 415);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _3, _4, _1)
		{
			ZEPHIR_INIT_NVAR(&attributeField);
			if (_4 != NULL) { 
				ZVAL_STR_COPY(&attributeField, _4);
			} else {
				ZVAL_LONG(&attributeField, _3);
			}
			ZEPHIR_INIT_NVAR(&info);
			ZVAL_COPY(&info, _1);
			ZEPHIR_OBS_NVAR(&type);
			zephir_array_fetch_string(&type, &info, SL("type"), PH_NOISY, "phalconplus/Base/Model.zep", 398);
			ZEPHIR_OBS_NVAR(&field);
			zephir_array_fetch_string(&field, &info, SL("field"), PH_NOISY, "phalconplus/Base/Model.zep", 399);
			ZEPHIR_INIT_NVAR(&value);
			ZVAL_NULL(&value);
			ZEPHIR_OBS_NVAR(&value);
			if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
				ZEPHIR_OBS_NVAR(&selfVal$$4);
				if (zephir_array_isset_string_fetch(&selfVal$$4, &info, SL("value"), 0)) {
					zephir_array_append(&uniqueParams, &selfVal$$4, PH_SEPARATE, "phalconplus/Base/Model.zep", 404);
				} else {
					zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalconplus/Base/Model.zep", 406);
				}
			} else {
				zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalconplus/Base/Model.zep", 409);
			}
			zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalconplus/Base/Model.zep", 411);
			ZEPHIR_CALL_METHOD(&_5$$3, connection, "escapeidentifier", &_6, 0, &field);
			zephir_check_call_status();
			zephir_array_fetch_string(&_7$$3, &info, SL("op"), PH_NOISY | PH_READONLY, "phalconplus/Base/Model.zep", 412);
			ZEPHIR_INIT_NVAR(&_8$$3);
			ZEPHIR_CONCAT_VSVS(&_8$$3, &_5$$3, " ", &_7$$3, " ?");
			zephir_array_append(&whereUk, &_8$$3, PH_SEPARATE, "phalconplus/Base/Model.zep", 412);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_2, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_2)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&attributeField, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&info, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&type);
				zephir_array_fetch_string(&type, &info, SL("type"), PH_NOISY, "phalconplus/Base/Model.zep", 398);
				ZEPHIR_OBS_NVAR(&field);
				zephir_array_fetch_string(&field, &info, SL("field"), PH_NOISY, "phalconplus/Base/Model.zep", 399);
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_NULL(&value);
				ZEPHIR_OBS_NVAR(&value);
				if (zephir_fetch_property_zval(&value, this_ptr, &attributeField, PH_SILENT_CC)) {
					ZEPHIR_OBS_NVAR(&selfVal$$9);
					if (zephir_array_isset_string_fetch(&selfVal$$9, &info, SL("value"), 0)) {
						zephir_array_append(&uniqueParams, &selfVal$$9, PH_SEPARATE, "phalconplus/Base/Model.zep", 404);
					} else {
						zephir_array_append(&uniqueParams, &value, PH_SEPARATE, "phalconplus/Base/Model.zep", 406);
					}
				} else {
					zephir_array_append(&uniqueParams, &__$null, PH_SEPARATE, "phalconplus/Base/Model.zep", 409);
				}
				zephir_array_append(&uniqueTypes, &type, PH_SEPARATE, "phalconplus/Base/Model.zep", 411);
				ZEPHIR_CALL_METHOD(&_9$$8, connection, "escapeidentifier", &_6, 0, &field);
				zephir_check_call_status();
				zephir_array_fetch_string(&_10$$8, &info, SL("op"), PH_NOISY | PH_READONLY, "phalconplus/Base/Model.zep", 412);
				ZEPHIR_INIT_NVAR(&_11$$8);
				ZEPHIR_CONCAT_VSVS(&_11$$8, &_9$$8, " ", &_10$$8, " ?");
				zephir_array_append(&whereUk, &_11$$8, PH_SEPARATE, "phalconplus/Base/Model.zep", 412);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&info);
	ZEPHIR_INIT_NVAR(&attributeField);
	ZEPHIR_INIT_VAR(&usefulParams);
	array_init(&usefulParams);
	ZEPHIR_INIT_VAR(&_12);
	ZEPHIR_INIT_NVAR(&_12);
	zephir_create_closure_ex(&_12, NULL, phalconplus_1__closure_ce, SL("__invoke"));
	ZEPHIR_CALL_FUNCTION(&usefulParams, "array_filter", NULL, 19, &uniqueParams, &_12);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&usefulParams)) {
		RETURN_MM_BOOL(0);
	}
	zephir_create_array(return_value, 3, 0);
	ZEPHIR_INIT_VAR(&_13);
	zephir_fast_join_str(&_13, SL(" AND "), &whereUk);
	zephir_array_update_string(return_value, SL("uniqueKey"), &_13, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("uniqueParams"), &uniqueParams, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("uniqueTypes"), &uniqueTypes, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_Model, getUniqueFields) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 3, 0);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_uniqueKey"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("key"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_uniqueParams"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("params"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("_uniqueTypes"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("types"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Base_Model, resetUniqueFields) {

	zval __$null;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);


	zephir_update_property_zval(this_ptr, SL("_uniqueKey"), &__$null);
	zephir_update_property_zval(this_ptr, SL("_uniqueParams"), &__$null);
	zephir_update_property_zval(this_ptr, SL("_uniqueTypes"), &__$null);

}

PHP_METHOD(PhalconPlus_Base_Model, toProtoBuffer) {

	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL, *_9 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *columns = NULL, columns_sub, __$null, proto, toArray, key, val, *_0, _1, modelName, manager, relations, referenceModel, referencedEntity, options, alias, lowerAlias, *_7, _8, _4$$3, _6$$4, method$$5, property$$5, _10$$5, _11$$5, method$$9, property$$9, _12$$9, _13$$9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&columns_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&proto);
	ZVAL_UNDEF(&toArray);
	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&val);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&modelName);
	ZVAL_UNDEF(&manager);
	ZVAL_UNDEF(&relations);
	ZVAL_UNDEF(&referenceModel);
	ZVAL_UNDEF(&referencedEntity);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&alias);
	ZVAL_UNDEF(&lowerAlias);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&method$$5);
	ZVAL_UNDEF(&property$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&method$$9);
	ZVAL_UNDEF(&property$$9);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);

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
	if (zephir_has_constructor(&proto)) {
		ZEPHIR_CALL_METHOD(NULL, &proto, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	zephir_is_iterable(&toArray, 0, "phalconplus/Base/Model.zep", 454);
	if (Z_TYPE_P(&toArray) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&toArray), _2, _3, _0)
		{
			ZEPHIR_INIT_NVAR(&key);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&key, _3);
			} else {
				ZVAL_LONG(&key, _2);
			}
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _0);
			ZEPHIR_INIT_NVAR(&_4$$3);
			if (zephir_is_scalar(&val)) {
				ZEPHIR_CPY_WRT(&_4$$3, &val);
			} else {
				ZEPHIR_CALL_FUNCTION(&_4$$3, "strval", &_5, 22, &val);
				zephir_check_call_status();
			}
			zephir_update_property_zval_zval(&proto, &key, &_4$$3);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &toArray, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &toArray, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&key, &toArray, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&val, &toArray, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_6$$4);
				if (zephir_is_scalar(&val)) {
					ZEPHIR_CPY_WRT(&_6$$4, &val);
				} else {
					ZEPHIR_CALL_FUNCTION(&_6$$4, "strval", &_5, 22, &val);
					zephir_check_call_status();
				}
				zephir_update_property_zval_zval(&proto, &key, &_6$$4);
			ZEPHIR_CALL_METHOD(NULL, &toArray, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&val);
	ZEPHIR_INIT_NVAR(&key);
	ZEPHIR_INIT_VAR(&modelName);
	zephir_get_class(&modelName, this_ptr, 0);
	ZEPHIR_CALL_METHOD(&manager, this_ptr, "getmodelsmanager", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&relations, &manager, "getrelations", NULL, 0, &modelName);
	zephir_check_call_status();
	zephir_is_iterable(&relations, 0, "phalconplus/Base/Model.zep", 475);
	if (Z_TYPE_P(&relations) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&relations), _7)
		{
			ZEPHIR_INIT_NVAR(&val);
			ZVAL_COPY(&val, _7);
			ZEPHIR_CALL_METHOD(&referenceModel, &val, "getreferencedmodel", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_INIT_NVAR(&referencedEntity);
			zephir_fast_strtolower(&referencedEntity, &referenceModel);
			ZEPHIR_CALL_METHOD(&options, &val, "getoptions", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&alias);
			if (zephir_array_isset_string_fetch(&alias, &options, SL("alias"), 0)) {
				if (Z_TYPE_P(&alias) != IS_STRING) {
					ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Relation alias must be a string", "phalconplus/Base/Model.zep", 464);
					return;
				}
				ZEPHIR_INIT_NVAR(&lowerAlias);
				zephir_fast_strtolower(&lowerAlias, &alias);
			} else {
				ZEPHIR_CPY_WRT(&lowerAlias, &referencedEntity);
			}
			ZEPHIR_INIT_NVAR(&method$$5);
			ZEPHIR_CONCAT_SV(&method$$5, "get", &alias);
			ZEPHIR_CALL_FUNCTION(&property$$5, "lcfirst", &_9, 42, &alias);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_ZVAL(&_10$$5, this_ptr, &method$$5, NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_11$$5, &_10$$5, "toarray", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_zval_zval(&proto, &property$$5, &_11$$5);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &relations, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_8, &relations, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_8)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&val, &relations, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&referenceModel, &val, "getreferencedmodel", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&referencedEntity);
				zephir_fast_strtolower(&referencedEntity, &referenceModel);
				ZEPHIR_CALL_METHOD(&options, &val, "getoptions", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&alias);
				if (zephir_array_isset_string_fetch(&alias, &options, SL("alias"), 0)) {
					if (Z_TYPE_P(&alias) != IS_STRING) {
						ZEPHIR_THROW_EXCEPTION_DEBUG_STR(zend_exception_get_default(TSRMLS_C), "Relation alias must be a string", "phalconplus/Base/Model.zep", 464);
						return;
					}
					ZEPHIR_INIT_NVAR(&lowerAlias);
					zephir_fast_strtolower(&lowerAlias, &alias);
				} else {
					ZEPHIR_CPY_WRT(&lowerAlias, &referencedEntity);
				}
				ZEPHIR_INIT_NVAR(&method$$9);
				ZEPHIR_CONCAT_SV(&method$$9, "get", &alias);
				ZEPHIR_CALL_FUNCTION(&property$$9, "lcfirst", &_9, 42, &alias);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_ZVAL(&_12$$9, this_ptr, &method$$9, NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&_13$$9, &_12$$9, "toarray", NULL, 0);
				zephir_check_call_status();
				zephir_update_property_zval_zval(&proto, &property$$9, &_13$$9);
			ZEPHIR_CALL_METHOD(NULL, &relations, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("__uniqueKeys"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("__uniqueKeys"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

