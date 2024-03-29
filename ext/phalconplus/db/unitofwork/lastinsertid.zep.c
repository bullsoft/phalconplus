
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


ZEPHIR_INIT_CLASS(PhalconPlus_Db_UnitOfWork_LastInsertId)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Db\\UnitOfWork, LastInsertId, phalconplus, db_unitofwork_lastinsertid, phalconplus_db_unitofwork_abstractvalue_ce, phalconplus_db_unitofwork_lastinsertid_method_entry, 0);

	zend_declare_property_null(phalconplus_db_unitofwork_lastinsertid_ce, SL("model"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalconplus_db_unitofwork_lastinsertid_ce, 1, phalconplus_contracts_stringer_ce);
	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Db_UnitOfWork_LastInsertId, __construct)
{
	zval *model, model_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(model, zephir_get_internal_ce(SL("phalcon\\mvc\\model")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &model);


	zephir_update_property_zval(this_ptr, ZEND_STRL("model"), model);
}

PHP_METHOD(PhalconPlus_Db_UnitOfWork_LastInsertId, getValue)
{
	zend_bool _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *unitwork, unitwork_sub, className, _0, hash, _1, inserted, _2, _3, _8, _9, info$$3, _4$$3, _6$$3, _7$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&unitwork_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&inserted);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&info$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$4);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(unitwork, zephir_get_internal_ce(SL("phalconplus\\db\\unitofwork")))
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &unitwork);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, &_0, 0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&hash, "spl_object_hash", NULL, 122, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&inserted, unitwork, "getinserted", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_3, this_ptr, ZEND_STRL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &inserted, "contains", NULL, 0, &_3);
	zephir_check_call_status();
	if (zephir_is_true(&_2)) {
		ZEPHIR_OBS_VAR(&info$$3);
		ZEPHIR_OBS_VAR(&_4$$3);
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("model"), PH_NOISY_CC);
		zephir_array_fetch(&info$$3, &inserted, &_4$$3, PH_NOISY, "phalconplus/Db/UnitOfWork/LastInsertId.zep", 23);
		_5$$3 = zephir_array_isset_string(&info$$3, SL("last_insert_id"));
		if (_5$$3) {
			zephir_array_fetch_string(&_6$$3, &info$$3, SL("last_insert_id"), PH_NOISY | PH_READONLY, "phalconplus/Db/UnitOfWork/LastInsertId.zep", 24);
			_5$$3 = ZEPHIR_GT_LONG(&_6$$3, 0);
		}
		if (_5$$3) {
			zephir_array_fetch_string(&_7$$4, &info$$3, SL("last_insert_id"), PH_NOISY | PH_READONLY, "phalconplus/Db/UnitOfWork/LastInsertId.zep", 25);
			RETURN_MM_LONG(zephir_get_intval(&_7$$4));
		}
		RETURN_MM_LONG(0);
	}
	ZEPHIR_INIT_VAR(&_8);
	object_init_ex(&_8, phalconplus_base_exception_ce);
	ZEPHIR_INIT_VAR(&_9);
	ZEPHIR_CONCAT_SVSVS(&_9, "Object(", &hash, ") instance of ", &className, " not in SplObjectStorage");
	ZEPHIR_CALL_METHOD(NULL, &_8, "__construct", NULL, 2, &_9);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_8, "phalconplus/Db/UnitOfWork/LastInsertId.zep", 30);
	ZEPHIR_MM_RESTORE();
	return;
}

PHP_METHOD(PhalconPlus_Db_UnitOfWork_LastInsertId, __toString)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, ZEND_STRL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "spl_object_hash", NULL, 122, &_0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SV(return_value, "LastInsertId: ", &_1);
	RETURN_MM();
}

