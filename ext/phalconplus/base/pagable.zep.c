
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_Pagable) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, Pagable, phalconplus, base_pagable, phalconplus_base_protobuffer_ce, phalconplus_base_pagable_method_entry, 0);

	zend_declare_property_long(phalconplus_base_pagable_ce, SL("pageNo"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_long(phalconplus_base_pagable_ce, SL("pageSize"), 0, ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_pagable_ce, SL("orderBys"), ZEND_ACC_PRIVATE TSRMLS_CC);

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
	ZEPHIR_CALL_FUNCTION(NULL, "array_push", NULL, 45, &_0, orderBy);
	ZEPHIR_UNREF(&_0);
	zephir_check_call_status();
	RETURN_THIS();

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

