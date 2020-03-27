
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
#include "ext/spl/spl_array.h"
#include "kernel/iterator.h"
#include "kernel/array.h"
#include "kernel/math.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_Page) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, Page, phalconplus, base_page, phalconplus_base_protobuffer_ce, phalconplus_base_page_method_entry, 0);

	/**
	 * @var <\Phalcon\Base\Pagable>
	 */
	zend_declare_property_null(phalconplus_base_page_ce, SL("pagable"), ZEND_ACC_PRIVATE);

	/**
	 * @var mixed array | <ArrayObject>
	 */
	zend_declare_property_null(phalconplus_base_page_ce, SL("data"), ZEND_ACC_PRIVATE);

	zend_declare_property_long(phalconplus_base_page_ce, SL("totalSize"), 0, ZEND_ACC_PRIVATE);

	zend_declare_property_long(phalconplus_base_page_ce, SL("pageNo"), 0, ZEND_ACC_PRIVATE);

	zend_declare_property_long(phalconplus_base_page_ce, SL("pageSize"), 0, ZEND_ACC_PRIVATE);

	zend_declare_property_long(phalconplus_base_page_ce, SL("totalPage"), 0, ZEND_ACC_PRIVATE);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_Page, __construct) {

	zend_object_iterator *_8$$6, *_11$$8;
	zend_bool _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_0 = NULL, *_1 = NULL, *_10 = NULL;
	zend_long totalSize, ZEPHIR_LAST_CALL_STATUS;
	zval *pagable, pagable_sub, *totalSize_param = NULL, *data = NULL, data_sub, hydrateMode, tmpData, item, _12, _13, _14, _3$$4, _4$$6, _5$$6, _6$$6, _7$$6, _9$$7;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&pagable_sub);
	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&hydrateMode);
	ZVAL_UNDEF(&tmpData);
	ZVAL_UNDEF(&item);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$6);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &pagable, &totalSize_param, &data);

	totalSize = zephir_get_intval(totalSize_param);
	if (!data) {
		data = &data_sub;
		ZEPHIR_INIT_VAR(data);
		array_init(data);
	}


	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "notnull", &_0, 0, pagable);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "istraversable", &_1, 0, data);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("pagable"), pagable);
	ZEPHIR_INIT_VAR(&tmpData);
	array_init(&tmpData);
	_2 = Z_TYPE_P(data) == IS_OBJECT;
	if (_2) {
		_2 = zephir_instance_of_ev(data, zephir_get_internal_ce(SL("phalcon\\mvc\\model\\resultset")));
	}
	if (Z_TYPE_P(data) == IS_ARRAY) {
		ZEPHIR_CPY_WRT(&tmpData, data);
	} else if (_2) {
		ZEPHIR_CALL_METHOD(&hydrateMode, data, "gethydratemode", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&_3$$4, data, "count", NULL, 0);
		zephir_check_call_status();
		if (ZEPHIR_GT_LONG(&_3$$4, 0)) {
			do {
				if (ZEPHIR_IS_LONG(&hydrateMode, 0)) {
					ZEPHIR_INIT_NVAR(&tmpData);
					object_init_ex(&tmpData, spl_ce_ArrayObject);
					ZEPHIR_CALL_METHOD(NULL, &tmpData, "__construct", NULL, 74);
					zephir_check_call_status();
					ZEPHIR_INIT_VAR(&_4$$6);
					ZEPHIR_CALL_METHOD(&_5$$6, data, "getfirst", NULL, 0);
					zephir_check_call_status();
					zephir_get_class(&_4$$6, &_5$$6, 0);
					zephir_update_property_zval(&tmpData, SL("modelName"), &_4$$6);
					ZEPHIR_CALL_METHOD(&_6$$6, data, "getfirst", NULL, 0);
					zephir_check_call_status();
					ZEPHIR_CALL_METHOD(&_7$$6, &_6$$6, "columnmap", NULL, 0);
					zephir_check_call_status();
					zephir_update_property_zval(&tmpData, SL("columnMap"), &_7$$6);
					_8$$6 = zephir_get_iterator(data);
					_8$$6->funcs->rewind(_8$$6);
					for (;_8$$6->funcs->valid(_8$$6) == SUCCESS && !EG(exception); _8$$6->funcs->move_forward(_8$$6)) {
						{
							ZEPHIR_ITERATOR_COPY(&item, _8$$6);
						}
						ZEPHIR_CALL_METHOD(&_9$$7, &item, "toarray", NULL, 0);
						zephir_check_call_status();
						ZEPHIR_CALL_METHOD(NULL, &tmpData, "append", &_10, 75, &_9$$7);
						zephir_check_call_status();
					}
					zend_iterator_dtor(_8$$6);
					break;
				}
				ZEPHIR_INIT_NVAR(&tmpData);
				array_init(&tmpData);
				_11$$8 = zephir_get_iterator(data);
				_11$$8->funcs->rewind(_11$$8);
				for (;_11$$8->funcs->valid(_11$$8) == SUCCESS && !EG(exception); _11$$8->funcs->move_forward(_11$$8)) {
					{
						ZEPHIR_ITERATOR_COPY(&item, _11$$8);
					}
					zephir_array_append(&tmpData, &item, PH_SEPARATE, "phalconplus/Base/Page.zep", 51);
				}
				zend_iterator_dtor(_11$$8);
				break;
			} while(0);

		}
	}
	zephir_update_property_zval(this_ptr, SL("data"), &tmpData);
	ZEPHIR_INIT_ZVAL_NREF(_12);
	ZVAL_LONG(&_12, totalSize);
	zephir_update_property_zval(this_ptr, SL("totalSize"), &_12);
	ZEPHIR_CALL_METHOD(&_13, this_ptr, "setpageno", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_14, &_13, "setpagesize", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_14, "settotalpage", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_Page, setPageNo) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("pagable"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getpageno", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("pageNo"), &_1);
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_Page, setPageSize) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("pagable"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getpagesize", NULL, 0);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("pageSize"), &_1);
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_Page, setTotalPage) {

	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("totalSize"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_1, this_ptr, SL("pageSize"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_2);
	div_function(&_2, &_0, &_1);
	ZVAL_DOUBLE(&_0, zephir_ceil(&_2));
	ZEPHIR_INIT_ZVAL_NREF(_1);
	ZVAL_LONG(&_1, zephir_get_intval(&_0));
	zephir_update_property_zval(this_ptr, SL("totalPage"), &_1);
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_Page, getPageNo) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "pageNo");

}

PHP_METHOD(PhalconPlus_Base_Page, getTotalPage) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "totalPage");

}

PHP_METHOD(PhalconPlus_Base_Page, getTotalSize) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "totalSize");

}

PHP_METHOD(PhalconPlus_Base_Page, hasPreviousPage) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("pageNo"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(ZEPHIR_GT_LONG(&_0, 1));

}

PHP_METHOD(PhalconPlus_Base_Page, isFirstPage) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "haspreviouspage", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(&_0));

}

PHP_METHOD(PhalconPlus_Base_Page, isLastPage) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "hasnextpage", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(!zephir_is_true(&_0));

}

PHP_METHOD(PhalconPlus_Base_Page, hasNextPage) {

	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getpageno", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "gettotalpage", NULL, 0);
	zephir_check_call_status();
	RETURN_MM_BOOL(ZEPHIR_LT(&_0, &_1));

}

PHP_METHOD(PhalconPlus_Base_Page, getData) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "data");

}

PHP_METHOD(PhalconPlus_Base_Page, isEmpty) {

	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);


	zephir_read_property(&_0, this_ptr, SL("data"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(zephir_fast_count_int(&_0) == 0);

}

