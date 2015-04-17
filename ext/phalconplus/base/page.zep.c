
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_Page) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, Page, phalconplus, base_page, phalconplus_base_protobuffer_ce, phalconplus_base_page_method_entry, 0);

	zend_declare_property_null(phalconplus_base_page_ce, SL("pagable"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_page_ce, SL("data"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_page_ce, SL("totalSize"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_page_ce, SL("pageNo"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_page_ce, SL("pageSize"), ZEND_ACC_PRIVATE TSRMLS_CC);

	zend_declare_property_null(phalconplus_base_page_ce, SL("totalPage"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_Page, __construct) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *pagable, *totalSize, *data;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &pagable, &totalSize, &data);



	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "notnull", &_0, pagable);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("pagable"), pagable TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("data"), data TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("totalSize"), totalSize TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setpageno", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "setpagesize", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "settotalpage", NULL);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_Page, setPageNo) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pagable"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "getpageno", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("pageNo"), _1 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_Page, setPageSize) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0, *_1 = NULL;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pagable"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "getpagesize", NULL);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("pageSize"), _1 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_Page, setTotalPage) {

	zval *_0, *_1, *_2, _3;

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(_0);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("totalSize"), PH_NOISY_CC);
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("pageSize"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_3);
	div_function(&_3, _1, _2 TSRMLS_CC);
	zephir_ceil(_0, &_3 TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("totalPage"), _0 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_Page, getPageNo) {


	RETURN_MEMBER(this_ptr, "pageNo");

}

PHP_METHOD(PhalconPlus_Base_Page, getTotalPage) {


	RETURN_MEMBER(this_ptr, "totalPage");

}

PHP_METHOD(PhalconPlus_Base_Page, getTotalSize) {


	RETURN_MEMBER(this_ptr, "totalSize");

}

PHP_METHOD(PhalconPlus_Base_Page, hasPreviousPage) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pageNo"), PH_NOISY_CC);
	RETURN_BOOL(ZEPHIR_GT_LONG(_0, 1));

}

PHP_METHOD(PhalconPlus_Base_Page, isFirstPage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "haspreviouspage", NULL);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(_0));

}

PHP_METHOD(PhalconPlus_Base_Page, isLastPage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasnextpage", NULL);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(_0));

}

PHP_METHOD(PhalconPlus_Base_Page, hasNextPage) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0 = NULL, *_1 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getpageno", NULL);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "gettotalpage", NULL);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_LT(_0, _1));

}

PHP_METHOD(PhalconPlus_Base_Page, getData) {


	RETURN_MEMBER(this_ptr, "data");

}

PHP_METHOD(PhalconPlus_Base_Page, isEmpty) {

	zval *_0;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("data"), PH_NOISY_CC);
	RETURN_BOOL(zephir_fast_count_int(_0 TSRMLS_CC) == 0);

}

