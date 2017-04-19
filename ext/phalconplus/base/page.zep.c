
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "ext/spl/spl_array.h"
#include "kernel/iterator.h"
#include "kernel/array.h"
#include "kernel/math.h"


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

	zend_object_iterator *_5$$3, *_8$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_7 = NULL;
	zval *pagable, *totalSize, *data, *hydrateMode = NULL, *tmpData = NULL, *item = NULL, *_9 = NULL, *_10 = NULL, *_1$$3, *_2$$3 = NULL, *_3$$3 = NULL, *_4$$3 = NULL, *_6$$4 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &pagable, &totalSize, &data);



	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "notnull", &_0, 31, pagable);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("pagable"), pagable TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&hydrateMode, data, "gethydratemode", NULL, 0);
	zephir_check_call_status();
	do {
		if (ZEPHIR_IS_LONG(hydrateMode, 0)) {
			ZEPHIR_INIT_VAR(tmpData);
			object_init_ex(tmpData, spl_ce_ArrayObject);
			ZEPHIR_CALL_METHOD(NULL, tmpData, "__construct", NULL, 37);
			zephir_check_call_status();
			ZEPHIR_INIT_VAR(_1$$3);
			ZEPHIR_CALL_METHOD(&_2$$3, data, "getfirst", NULL, 0);
			zephir_check_call_status();
			zephir_get_class(_1$$3, _2$$3, 0 TSRMLS_CC);
			zephir_update_property_zval(tmpData, SL("modelName"), _1$$3 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(&_3$$3, data, "getfirst", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&_4$$3, _3$$3, "columnmap", NULL, 0);
			zephir_check_call_status();
			zephir_update_property_zval(tmpData, SL("columnMap"), _4$$3 TSRMLS_CC);
			_5$$3 = zephir_get_iterator(data TSRMLS_CC);
			_5$$3->funcs->rewind(_5$$3 TSRMLS_CC);
			for (;_5$$3->funcs->valid(_5$$3 TSRMLS_CC) == SUCCESS && !EG(exception); _5$$3->funcs->move_forward(_5$$3 TSRMLS_CC)) {
				{
					zval **ZEPHIR_TMP_ITERATOR_PTR;
					_5$$3->funcs->get_current_data(_5$$3, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
					ZEPHIR_CPY_WRT(item, (*ZEPHIR_TMP_ITERATOR_PTR));
				}
				ZEPHIR_CALL_METHOD(&_6$$4, item, "toarray", NULL, 0);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(NULL, tmpData, "append", &_7, 38, _6$$4);
				zephir_check_call_status();
			}
			_5$$3->funcs->dtor(_5$$3 TSRMLS_CC);
			break;
		}
		ZEPHIR_INIT_NVAR(tmpData);
		array_init(tmpData);
		_8$$5 = zephir_get_iterator(data TSRMLS_CC);
		_8$$5->funcs->rewind(_8$$5 TSRMLS_CC);
		for (;_8$$5->funcs->valid(_8$$5 TSRMLS_CC) == SUCCESS && !EG(exception); _8$$5->funcs->move_forward(_8$$5 TSRMLS_CC)) {
			{
				zval **ZEPHIR_TMP_ITERATOR_PTR;
				_8$$5->funcs->get_current_data(_8$$5, &ZEPHIR_TMP_ITERATOR_PTR TSRMLS_CC);
				ZEPHIR_CPY_WRT(item, (*ZEPHIR_TMP_ITERATOR_PTR));
			}
			zephir_array_append(&tmpData, item, PH_SEPARATE, "phalconplus/Base/Page.zep", 41);
		}
		_8$$5->funcs->dtor(_8$$5 TSRMLS_CC);
		break;
	} while(0);

	zephir_update_property_this(this_ptr, SL("data"), tmpData TSRMLS_CC);
	zephir_update_property_this(this_ptr, SL("totalSize"), totalSize TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_9, this_ptr, "setpageno", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_10, _9, "setpagesize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, _10, "settotalpage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_Page, setPageNo) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pagable"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "getpageno", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("pageNo"), _1 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_Page, setPageSize) {

	zval *_0, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("pagable"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "getpagesize", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_this(this_ptr, SL("pageSize"), _1 TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_Page, setTotalPage) {

	zval *_0, *_1, _2;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("totalSize"), PH_NOISY_CC);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("pageSize"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_2);
	div_function(&_2, _0, _1 TSRMLS_CC);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_DOUBLE(_0, zephir_ceil(&_2 TSRMLS_CC));
	zephir_update_property_this(this_ptr, SL("totalPage"), _0 TSRMLS_CC);
	RETURN_THISW();

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

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "haspreviouspage", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(_0));

}

PHP_METHOD(PhalconPlus_Base_Page, isLastPage) {

	zval *_0 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasnextpage", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(_0));

}

PHP_METHOD(PhalconPlus_Base_Page, hasNextPage) {

	zval *_0 = NULL, *_1 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getpageno", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "gettotalpage", NULL, 0);
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

