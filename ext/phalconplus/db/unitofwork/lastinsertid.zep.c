
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Db_UnitOfWork_LastInsertId) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Db\\UnitOfWork, LastInsertId, phalconplus, db_unitofwork_lastinsertid, phalconplus_db_unitofwork_abstractvalue_ce, phalconplus_db_unitofwork_lastinsertid_method_entry, 0);

	zend_declare_property_null(phalconplus_db_unitofwork_lastinsertid_ce, SL("model"), ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork_LastInsertId, __construct) {

	zval *model, model_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);

	zephir_fetch_params(0, 1, 0, &model);



	zephir_update_property_zval(this_ptr, SL("model"), model);

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork_LastInsertId, getValue) {

	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL, *_6 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *unitwork, unitwork_sub, modelClass, _0, modelHash, _1, inserted, _2, _9, _10, obj$$3, _4$$3, info$$4, _7$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&unitwork_sub);
	ZVAL_UNDEF(&modelClass);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&modelHash);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&inserted);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&obj$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&info$$4);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &unitwork);



	zephir_read_property(&_0, this_ptr, SL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&modelClass);
	zephir_get_class(&modelClass, &_0, 0 TSRMLS_CC);
	zephir_read_property(&_1, this_ptr, SL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&modelHash, "spl_object_hash", NULL, 67, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&inserted, unitwork, "getinserted", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &inserted, "rewind", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_2, &inserted, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_2))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&obj$$3, &inserted, "current", &_3, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, &inserted, "gethash", &_5, 0, &obj$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_EQUAL(&_4$$3, &modelHash)) {
			ZEPHIR_CALL_METHOD(&info$$4, &inserted, "getinfo", &_6, 0);
			zephir_check_call_status();
			zephir_array_fetch_string(&_7$$4, &info$$4, SL("last_insert_id"), PH_NOISY | PH_READONLY, "phalconplus/Db/UnitOfWork/LastInsertId.zep", 23 TSRMLS_CC);
			RETURN_CTOR(&_7$$4);
		}
		ZEPHIR_CALL_METHOD(NULL, &inserted, "next", &_8, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_9);
	object_init_ex(&_9, phalconplus_base_exception_ce);
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CONCAT_SVSVS(&_10, "Object(", &modelHash, ") instance of ", &modelClass, " not in SplObjectStorage");
	ZEPHIR_CALL_METHOD(NULL, &_9, "__construct", NULL, 22, &_10);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_9, "phalconplus/Db/UnitOfWork/LastInsertId.zep", 27 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork_LastInsertId, __toString) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "spl_object_hash", NULL, 67, &_0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SV(return_value, "LastInsertId", &_1);
	RETURN_MM();

}

