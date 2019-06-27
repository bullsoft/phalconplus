
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

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *unitwork, unitwork_sub, className, _0, hash, _1, inserted, _2, _3, _6, _7, info$$3, _4$$3, _5$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&unitwork_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&inserted);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&info$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &unitwork);



	zephir_read_property(&_0, this_ptr, SL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, &_0, 0 TSRMLS_CC);
	zephir_read_property(&_1, this_ptr, SL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&hash, "spl_object_hash", NULL, 76, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&inserted, unitwork, "getinserted", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, SL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &inserted, "contains", NULL, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_OBS_VAR(&info$$3);
		ZEPHIR_OBS_VAR(&_4$$3);
		zephir_read_property(&_4$$3, this_ptr, SL("model"), PH_NOISY_CC);
		zephir_array_fetch(&info$$3, &inserted, &_4$$3, PH_NOISY, "phalconplus/Db/UnitOfWork/LastInsertId.zep", 20 TSRMLS_CC);
		zephir_array_fetch_string(&_5$$3, &info$$3, SL("last_insert_id"), PH_NOISY | PH_READONLY, "phalconplus/Db/UnitOfWork/LastInsertId.zep", 21 TSRMLS_CC);
		RETURN_CTOR(&_5$$3);
	}
	ZEPHIR_INIT_VAR(&_6);
	object_init_ex(&_6, phalconplus_base_exception_ce);
	ZEPHIR_INIT_VAR(&_7);
	ZEPHIR_CONCAT_SVSVS(&_7, "Object(", &hash, ") instance of ", &className, " not in SplObjectStorage");
	ZEPHIR_CALL_METHOD(NULL, &_6, "__construct", NULL, 22, &_7);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_6, "phalconplus/Db/UnitOfWork/LastInsertId.zep", 24 TSRMLS_CC);
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
	ZEPHIR_CALL_FUNCTION(&_1, "spl_object_hash", NULL, 76, &_0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SV(return_value, "LastInsertId: ", &_1);
	RETURN_MM();

}

