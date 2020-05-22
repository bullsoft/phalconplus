
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/math.h"
#include "kernel/string.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_Pagable) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, Pagable, phalconplus, base_pagable, phalconplus_base_protobuffer_ce, phalconplus_base_pagable_method_entry, 0);

	zend_declare_property_long(phalconplus_base_pagable_ce, SL("pageNo"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_long(phalconplus_base_pagable_ce, SL("pageSize"), 0, ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_base_pagable_ce, SL("orderBys"), ZEND_ACC_PROTECTED);

	phalconplus_base_pagable_ce->create_object = zephir_init_properties_PhalconPlus_Base_Pagable;
	zephir_declare_class_constant_long(phalconplus_base_pagable_ce, SL("DEFAULT_PAGE_NO"), 1);

	zephir_declare_class_constant_long(phalconplus_base_pagable_ce, SL("DEFAULT_PAGE_SIZE"), 20);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_Pagable, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval orderBys;
	zval *pageNo_param = NULL, *pageSize_param = NULL, *orderBys_param = NULL, _0, _1;
	zend_long pageNo, pageSize, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&orderBys);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 3, &pageNo_param, &pageSize_param, &orderBys_param);

	if (!pageNo_param) {
		pageNo = 0;
	} else {
		pageNo = zephir_get_intval(pageNo_param);
	}
	if (!pageSize_param) {
		pageSize = 0;
	} else {
		pageSize = zephir_get_intval(pageSize_param);
	}
	if (!orderBys_param) {
		ZEPHIR_INIT_VAR(&orderBys);
		array_init(&orderBys);
	} else {
		zephir_get_arrval(&orderBys, orderBys_param);
	}


	if (pageNo < 1) {
		pageNo = 1;
	}
	if (pageSize < 1) {
		pageSize = 20;
	}
	ZVAL_LONG(&_1, pageNo);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "setpageno", NULL, 0, &_1);
	zephir_check_call_status();
	ZVAL_LONG(&_1, pageSize);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setpagesize", NULL, 0, &_1);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&orderBys))) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "setorderbys", NULL, 0, &orderBys);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_Pagable, fromArray) {

	zend_class_entry *_11;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, pageNo = 0, pageSize = 0;
	zend_bool cursor;
	zval *pages_param = NULL, *cursor_param = NULL, clsInst, clsName, _10, _12, _13, _0$$3, _1$$3, _2$$3, _3$$3, _4$$4, _5$$4, _6$$4, _7$$4, _8$$4, _9$$4, _14$$5;
	zval pages;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pages);
	ZVAL_UNDEF(&clsInst);
	ZVAL_UNDEF(&clsName);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_14$$5);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &pages_param, &cursor_param);

	zephir_get_arrval(&pages, pages_param);
	if (!cursor_param) {
		cursor = 0;
	} else {
		cursor = zephir_get_boolval(cursor_param);
	}


	if (cursor == 0) {
		ZEPHIR_INIT_VAR(&_0$$3);
		if (zephir_array_isset_string(&pages, SL("pageNo"))) {
			ZEPHIR_OBS_VAR(&_1$$3);
			zephir_array_fetch_string(&_1$$3, &pages, SL("pageNo"), PH_NOISY, "phalconplus/Base/Pagable.zep", 35);
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_LONG(&_0$$3, zephir_get_intval(&_1$$3));
		} else {
			ZEPHIR_INIT_NVAR(&_0$$3);
			ZVAL_LONG(&_0$$3, 0);
		}
		pageNo = zephir_get_numberval(&_0$$3);
		ZEPHIR_INIT_VAR(&_2$$3);
		if (zephir_array_isset_string(&pages, SL("pageSize"))) {
			ZEPHIR_OBS_VAR(&_3$$3);
			zephir_array_fetch_string(&_3$$3, &pages, SL("pageSize"), PH_NOISY, "phalconplus/Base/Pagable.zep", 36);
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_LONG(&_2$$3, zephir_get_intval(&_3$$3));
		} else {
			ZEPHIR_INIT_NVAR(&_2$$3);
			ZVAL_LONG(&_2$$3, 0);
		}
		pageSize = zephir_get_numberval(&_2$$3);
	} else {
		ZEPHIR_INIT_VAR(&_4$$4);
		if (zephir_array_isset_string(&pages, SL("limit"))) {
			ZEPHIR_OBS_VAR(&_5$$4);
			zephir_array_fetch_string(&_5$$4, &pages, SL("limit"), PH_NOISY, "phalconplus/Base/Pagable.zep", 38);
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_LONG(&_4$$4, zephir_get_intval(&_5$$4));
		} else {
			ZEPHIR_INIT_NVAR(&_4$$4);
			ZVAL_LONG(&_4$$4, 0);
		}
		pageSize = zephir_get_numberval(&_4$$4);
		ZEPHIR_INIT_VAR(&_6$$4);
		if (zephir_array_isset_string(&pages, SL("offset"))) {
			ZEPHIR_OBS_VAR(&_7$$4);
			zephir_array_fetch_string(&_7$$4, &pages, SL("offset"), PH_NOISY, "phalconplus/Base/Pagable.zep", 39);
			ZEPHIR_INIT_NVAR(&_6$$4);
			ZVAL_LONG(&_6$$4, zephir_get_intval(&_7$$4));
		} else {
			ZEPHIR_INIT_NVAR(&_6$$4);
			ZVAL_LONG(&_6$$4, 0);
		}
		pageNo = zephir_get_numberval(&_6$$4);
		ZVAL_DOUBLE(&_8$$4, zephir_safe_div_long_long(pageNo, pageSize));
		ZVAL_DOUBLE(&_9$$4, zephir_ceil(&_8$$4));
		pageNo = (zephir_get_intval(&_9$$4) + 1);
	}
	ZEPHIR_INIT_VAR(&clsInst);
	ZVAL_NULL(&clsInst);
	ZEPHIR_INIT_VAR(&clsName);
	zephir_get_called_class(&clsName);
	ZEPHIR_INIT_NVAR(&clsInst);
	zephir_fetch_safe_class(&_10, &clsName);
	_11 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_10), Z_STRLEN_P(&_10), ZEND_FETCH_CLASS_AUTO);
	if(!_11) {
		RETURN_MM_NULL();
	}
	object_init_ex(&clsInst, _11);
	if (zephir_has_constructor(&clsInst)) {
		ZVAL_LONG(&_12, pageNo);
		ZVAL_LONG(&_13, pageSize);
		ZEPHIR_CALL_METHOD(NULL, &clsInst, "__construct", NULL, 0, &_12, &_13);
		zephir_check_call_status();
	}
	if (zephir_array_isset_string(&pages, SL("orderBys"))) {
		zephir_array_fetch_string(&_14$$5, &pages, SL("orderBys"), PH_NOISY | PH_READONLY, "phalconplus/Base/Pagable.zep", 46);
		ZEPHIR_CALL_METHOD(NULL, &clsInst, "setorderbys", NULL, 0, &_14$$5);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&clsInst);

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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("pageNo"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("pageSize"), PH_NOISY_CC | PH_READONLY);
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



	zephir_read_property(&_0, this_ptr, ZEND_STRL("orderBys"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_MAKE_REF(&_0);
	ZEPHIR_CALL_FUNCTION(NULL, "array_push", NULL, 74, &_0, orderBy);
	ZEPHIR_UNREF(&_0);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_Pagable, setOrderBys) {

	zend_bool _2$$3, _11$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_4 = NULL, *_5 = NULL, *_8 = NULL, *_9 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *orderBys_param = NULL, item, *_0, _1, orderBy$$4, direction$$4, upperDirection$$4, _3$$4, _6$$4, _7$$4, orderBy$$6, direction$$6, upperDirection$$6, _12$$6, _13$$6, _14$$6;
	zval orderBys;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&orderBys);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&orderBy$$4);
	ZVAL_UNDEF(&direction$$4);
	ZVAL_UNDEF(&upperDirection$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&orderBy$$6);
	ZVAL_UNDEF(&direction$$6);
	ZVAL_UNDEF(&upperDirection$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &orderBys_param);

	zephir_get_arrval(&orderBys, orderBys_param);


	zephir_is_iterable(&orderBys, 0, "phalconplus/Base/Pagable.zep", 97);
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
				zephir_array_fetch_string(&_3$$4, &item, SL("direction"), PH_NOISY | PH_READONLY, "phalconplus/Base/Pagable.zep", 88);
				ZEPHIR_INIT_NVAR(&upperDirection$$4);
				zephir_fast_strtoupper(&upperDirection$$4, &_3$$4);
				ZEPHIR_INIT_NVAR(&direction$$4);
				object_init_ex(&direction$$4, phalconplus_enum_orderbydirection_ce);
				ZEPHIR_CALL_METHOD(NULL, &direction$$4, "__construct", &_4, 54, &upperDirection$$4);
				zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&orderBy$$4);
				object_init_ex(&orderBy$$4, phalconplus_base_protoorderby_ce);
				ZEPHIR_CALL_METHOD(NULL, &orderBy$$4, "__construct", &_5, 72);
				zephir_check_call_status();
				zephir_array_fetch_string(&_7$$4, &item, SL("property"), PH_NOISY | PH_READONLY, "phalconplus/Base/Pagable.zep", 92);
				ZEPHIR_CALL_METHOD(&_6$$4, &orderBy$$4, "setproperty", &_8, 75, &_7$$4);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, &_6$$4, "setdirection", &_9, 0, &direction$$4);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "setorderby", &_10, 0, &orderBy$$4);
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
				_11$$5 = zephir_array_isset_string(&item, SL("property"));
				if (_11$$5) {
					_11$$5 = zephir_array_isset_string(&item, SL("direction"));
				}
				if (_11$$5) {
					zephir_array_fetch_string(&_12$$6, &item, SL("direction"), PH_NOISY | PH_READONLY, "phalconplus/Base/Pagable.zep", 88);
					ZEPHIR_INIT_NVAR(&upperDirection$$6);
					zephir_fast_strtoupper(&upperDirection$$6, &_12$$6);
					ZEPHIR_INIT_NVAR(&direction$$6);
					object_init_ex(&direction$$6, phalconplus_enum_orderbydirection_ce);
					ZEPHIR_CALL_METHOD(NULL, &direction$$6, "__construct", &_4, 54, &upperDirection$$6);
					zephir_check_call_status();
					ZEPHIR_INIT_NVAR(&orderBy$$6);
					object_init_ex(&orderBy$$6, phalconplus_base_protoorderby_ce);
					ZEPHIR_CALL_METHOD(NULL, &orderBy$$6, "__construct", &_5, 72);
					zephir_check_call_status();
					zephir_array_fetch_string(&_14$$6, &item, SL("property"), PH_NOISY | PH_READONLY, "phalconplus/Base/Pagable.zep", 92);
					ZEPHIR_CALL_METHOD(&_13$$6, &orderBy$$6, "setproperty", &_8, 75, &_14$$6);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, &_13$$6, "setdirection", &_9, 0, &direction$$6);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "setorderby", &_10, 0, &orderBy$$6);
					zephir_check_call_status();
				}
			ZEPHIR_CALL_METHOD(NULL, &orderBys, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&item);
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_Pagable, hasOrderBy) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("orderBys"), PH_NOISY_CC);
	RETURN_MM_BOOL(!(ZEPHIR_IS_EMPTY(&_0)));

}

PHP_METHOD(PhalconPlus_Base_Pagable, setPageNo) {

	zval *pageNo, pageNo_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pageNo_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &pageNo);



	zephir_update_property_zval(this_ptr, ZEND_STRL("pageNo"), pageNo);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_Base_Pagable, setPageSize) {

	zval *pageSize, pageSize_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pageSize_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &pageSize);



	zephir_update_property_zval(this_ptr, ZEND_STRL("pageSize"), pageSize);
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("orderBys"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("orderBys"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

