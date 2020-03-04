
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_Pagable) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, Pagable, phalconplus, base_pagable, phalconplus_base_protobuffer_ce, phalconplus_base_pagable_method_entry, 0);

	zend_declare_property_long(phalconplus_base_pagable_ce, SL("pageNo"), 1, ZEND_ACC_PROTECTED);

	zend_declare_property_long(phalconplus_base_pagable_ce, SL("pageSize"), 15, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_base_pagable_ce, SL("orderBys"), ZEND_ACC_PROTECTED);

	phalconplus_base_pagable_ce->create_object = zephir_init_properties_PhalconPlus_Base_Pagable;
	zephir_declare_class_constant_long(phalconplus_base_pagable_ce, SL("DEFAULT_PAGE_NO"), 1);

	zephir_declare_class_constant_long(phalconplus_base_pagable_ce, SL("DEFAULT_PAGE_SIZE"), 15);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_Pagable, getPageNo) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "pageNo");

}

PHP_METHOD(PhalconPlus_Base_Pagable, getPageSize) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "pageSize");

}

PHP_METHOD(PhalconPlus_Base_Pagable, getOrderBys) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "orderBys");

}

PHP_METHOD(PhalconPlus_Base_Pagable, getOffset) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("pageNo"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("pageSize"), PH_NOISY_CC | PH_READONLY);
	RETURN_LONG((((zephir_get_numberval(&_0) - 1)) * zephir_get_numberval(&_1)));

}

PHP_METHOD(PhalconPlus_Base_Pagable, getLimit) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "pageSize");

}

PHP_METHOD(PhalconPlus_Base_Pagable, setOrderBy) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *orderBy, orderBy_sub, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&orderBy_sub);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &orderBy);



	zephir_read_property(&_0, this_ptr, SL("orderBys"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_MAKE_REF(&_0);
	ZEPHIR_CALL_FUNCTION(NULL, "array_push", NULL, 66, &_0, orderBy);
	ZEPHIR_UNREF(&_0);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_Pagable, setOrderBys) {

	zend_bool _2$$3, _10$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL, *_5 = NULL, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_11 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *orderBys_param = NULL, item, *_0, _1, orderBy$$4, direction$$4, _4$$4, _6$$4, orderBy$$6, direction$$6, _12$$6, _13$$6;
	zval orderBys;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&orderBys);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&orderBy$$4);
	ZVAL_UNDEF(&direction$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&orderBy$$6);
	ZVAL_UNDEF(&direction$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &orderBys_param);

	zephir_get_arrval(&orderBys, orderBys_param);


	zephir_is_iterable(&orderBys, 0, "phalconplus/Base/Pagable.zep", 57);
	if (Z_TYPE_P(&orderBys) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&orderBys), _0)
		{
			ZEPHIR_INIT_NVAR(&item);
			ZVAL_COPY(&item, _0);
			_2$$3 = zephir_array_isset_string(&item, SL("property"));
			if (_2$$3) {
				_2$$3 = zephir_array_isset_string(&item, SL("direction"));
			}
			if (_2$$3) {
				ZEPHIR_INIT_NVAR(&orderBy$$4);
				object_init_ex(&orderBy$$4, phalconplus_base_protoorderby_ce);
				if (zephir_has_constructor(&orderBy$$4)) {
					ZEPHIR_CALL_METHOD(NULL, &orderBy$$4, "__construct", &_3, 0);
					zephir_check_call_status();
				}
				zephir_array_fetch_string(&_4$$4, &item, SL("property"), PH_NOISY | PH_READONLY, "phalconplus/Base/Pagable.zep", 51);
				ZEPHIR_CALL_METHOD(NULL, &orderBy$$4, "setproperty", &_5, 67, &_4$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&direction$$4);
				object_init_ex(&direction$$4, phalconplus_enum_orderbydirection_ce);
				zephir_array_fetch_string(&_6$$4, &item, SL("direction"), PH_NOISY | PH_READONLY, "phalconplus/Base/Pagable.zep", 52);
				ZEPHIR_CALL_METHOD(NULL, &direction$$4, "__construct", &_7, 47, &_6$$4);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &orderBy$$4, "setdirection", &_8, 68, &direction$$4);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "setorderby", &_9, 0, &orderBy$$4);
				zephir_check_call_status();
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &orderBys, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_1, &orderBys, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_1)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&item, &orderBys, "current", NULL, 0);
			zephir_check_call_status();
				_10$$5 = zephir_array_isset_string(&item, SL("property"));
				if (_10$$5) {
					_10$$5 = zephir_array_isset_string(&item, SL("direction"));
				}
				if (_10$$5) {
					ZEPHIR_INIT_NVAR(&orderBy$$6);
					object_init_ex(&orderBy$$6, phalconplus_base_protoorderby_ce);
					if (zephir_has_constructor(&orderBy$$6)) {
						ZEPHIR_CALL_METHOD(NULL, &orderBy$$6, "__construct", &_11, 0);
						zephir_check_call_status();
					}
					zephir_array_fetch_string(&_12$$6, &item, SL("property"), PH_NOISY | PH_READONLY, "phalconplus/Base/Pagable.zep", 51);
					ZEPHIR_CALL_METHOD(NULL, &orderBy$$6, "setproperty", &_5, 67, &_12$$6);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&direction$$6);
					object_init_ex(&direction$$6, phalconplus_enum_orderbydirection_ce);
					zephir_array_fetch_string(&_13$$6, &item, SL("direction"), PH_NOISY | PH_READONLY, "phalconplus/Base/Pagable.zep", 52);
					ZEPHIR_CALL_METHOD(NULL, &direction$$6, "__construct", &_7, 47, &_13$$6);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &orderBy$$6, "setdirection", &_8, 68, &direction$$6);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "setorderby", &_9, 0, &orderBy$$6);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &orderBys, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_Pagable, hasOrderBy) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("orderBys"), PH_NOISY_CC);
	RETURN_MM_BOOL(!(ZEPHIR_IS_EMPTY(&_0)));

}

PHP_METHOD(PhalconPlus_Base_Pagable, setPageNo) {

	zval *pageNo, pageNo_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pageNo_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &pageNo);



	zephir_update_property_zval(this_ptr, SL("pageNo"), pageNo);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_Base_Pagable, setPageSize) {

	zval *pageSize, pageSize_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pageSize_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &pageSize);



	zephir_update_property_zval(this_ptr, SL("pageSize"), pageSize);
	RETURN_THISW();

}

zend_object *zephir_init_properties_PhalconPlus_Base_Pagable(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("orderBys"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("orderBys"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

