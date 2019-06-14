
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Db_UnitOfWork_Field) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Db\\UnitOfWork, Field, phalconplus, db_unitofwork_field, phalconplus_db_unitofwork_abstractvalue_ce, phalconplus_db_unitofwork_field_method_entry, 0);

	zend_declare_property_null(phalconplus_db_unitofwork_field_ce, SL("model"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalconplus_db_unitofwork_field_ce, SL("attr"), "", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork_Field, __construct) {

	zval attr;
	zval *model, model_sub, *attr_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&attr);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &model, &attr_param);

	if (UNEXPECTED(Z_TYPE_P(attr_param) != IS_STRING && Z_TYPE_P(attr_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'attr' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(attr_param) == IS_STRING)) {
		zephir_get_strval(&attr, attr_param);
	} else {
		ZEPHIR_INIT_VAR(&attr);
		ZVAL_EMPTY_STRING(&attr);
	}


	zephir_update_property_zval(this_ptr, SL("model"), model);
	zephir_update_property_zval(this_ptr, SL("attr"), &attr);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork_Field, getValue) {

	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL, *_8 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *unitwork, unitwork_sub, className, _0, hash, _1, objs, _2, _9, _10, obj$$3, _4$$3, attr$$4, _6$$4, _7$$4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&unitwork_sub);
	ZVAL_UNDEF(&className);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&hash);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&objs);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&obj$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&attr$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &unitwork);



	zephir_read_property(&_0, this_ptr, SL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&className);
	zephir_get_class(&className, &_0, 0 TSRMLS_CC);
	zephir_read_property(&_1, this_ptr, SL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&hash, "spl_object_hash", NULL, 74, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&objs, unitwork, "getobjects", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &objs, "rewind", NULL, 0);
	zephir_check_call_status();
	while (1) {
		ZEPHIR_CALL_METHOD(&_2, &objs, "valid", NULL, 0);
		zephir_check_call_status();
		if (!(zephir_is_true(&_2))) {
			break;
		}
		ZEPHIR_CALL_METHOD(&obj$$3, &objs, "current", &_3, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_4$$3, &objs, "gethash", &_5, 0, &obj$$3);
		zephir_check_call_status();
		if (ZEPHIR_IS_EQUAL(&_4$$3, &hash)) {
			zephir_read_property(&_6$$4, this_ptr, SL("attr"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CPY_WRT(&attr$$4, &_6$$4);
			ZEPHIR_OBS_NVAR(&_7$$4);
			zephir_read_property_zval(&_7$$4, &obj$$3, &attr$$4, PH_NOISY_CC);
			RETURN_CCTOR(&_7$$4);
		}
		ZEPHIR_CALL_METHOD(NULL, &objs, "next", &_8, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_9);
	object_init_ex(&_9, phalconplus_base_exception_ce);
	ZEPHIR_INIT_VAR(&_10);
	ZEPHIR_CONCAT_SVSVS(&_10, "Object(", &hash, ") instance of ", &className, " not in SplObjectStorage");
	ZEPHIR_CALL_METHOD(NULL, &_9, "__construct", NULL, 22, &_10);
	zephir_check_call_status();
	zephir_throw_exception_debug(&_9, "phalconplus/Db/UnitOfWork/Field.zep", 30 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();
	return;

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork_Field, getField) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *unitwork, unitwork_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&unitwork_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &unitwork);



	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "getvalue", NULL, 0, unitwork);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork_Field, __toString) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("model"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "spl_object_hash", NULL, 74, &_0);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SV(return_value, "Field", &_1);
	RETURN_MM();

}

