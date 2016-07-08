
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

	zend_declare_property_null(phalconplus_base_pagable_ce, SL("pageNo"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_pagable_ce, SL("pageSize"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_pagable_ce, SL("orderBys"), ZEND_ACC_PRIVATE TSRMLS_CC);

	phalconplus_base_pagable_ce->create_object = zephir_init_properties_PhalconPlus_Base_Pagable;
	zend_declare_class_constant_long(phalconplus_base_pagable_ce, SL("DEFAULT_PAGE_NO"), 1 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_base_pagable_ce, SL("DEFAULT_PAGE_SIZE"), 15 TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_Pagable, getPageNo) {

	

	RETURN_MEMBER(this_ptr, "pageNo");

}

PHP_METHOD(PhalconPlus_Base_Pagable, getPageSize) {

	

	RETURN_MEMBER(this_ptr, "pageSize");

}

PHP_METHOD(PhalconPlus_Base_Pagable, getOrderBys) {

	

	RETURN_MEMBER(this_ptr, "orderBys");

}

PHP_METHOD(PhalconPlus_Base_Pagable, setOrderBy) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *orderBy, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &orderBy);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("orderBys"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "array_push", NULL, 33, _0, orderBy);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_Pagable, setPageNo) {

	zval *pageNo;

	zephir_fetch_params(0, 1, 0, &pageNo);



	zephir_update_property_this(this_ptr, SL("pageNo"), pageNo TSRMLS_CC);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_Base_Pagable, setPageSize) {

	zval *pageSize;

	zephir_fetch_params(0, 1, 0, &pageSize);



	zephir_update_property_this(this_ptr, SL("pageSize"), pageSize TSRMLS_CC);
	RETURN_THISW();

}

zend_object_value zephir_init_properties_PhalconPlus_Base_Pagable(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("orderBys"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("orderBys"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

