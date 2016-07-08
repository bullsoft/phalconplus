
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_ProtoOrderBy) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, ProtoOrderBy, phalconplus, base_protoorderby, phalconplus_base_protobuffer_ce, phalconplus_base_protoorderby_method_entry, 0);

	/**
	 * @required
	 */
	zend_declare_property_null(phalconplus_base_protoorderby_ce, SL("property"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @required
	 */
	zend_declare_property_null(phalconplus_base_protoorderby_ce, SL("direction"), ZEND_ACC_PRIVATE TSRMLS_CC);

	/**
	 * @optional
	 */
	zend_declare_property_string(phalconplus_base_protoorderby_ce, SL("alias"), "", ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, getProperty) {

	

	RETURN_MEMBER(this_ptr, "property");

}

PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, setProperty) {

	zval *property_param = NULL;
	zval *property = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);

	if (unlikely(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(property, property_param);
	} else {
		ZEPHIR_INIT_VAR(property);
		ZVAL_EMPTY_STRING(property);
	}


	zephir_update_property_this(this_ptr, SL("property"), property TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, setDirection) {

	zval *orderBy;

	zephir_fetch_params(0, 1, 0, &orderBy);



	zephir_update_property_this(this_ptr, SL("direction"), orderBy TSRMLS_CC);

}

PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, getDirection) {

	

	RETURN_MEMBER(this_ptr, "direction");

}

PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, getAlias) {

	

	RETURN_MEMBER(this_ptr, "alias");

}

PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, setAlias) {

	zval *alias_param = NULL;
	zval *alias = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias_param);

	if (unlikely(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(alias);
		ZVAL_EMPTY_STRING(alias);
	}


	zephir_update_property_this(this_ptr, SL("alias"), alias TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, __toString) {

	zval *_1, *_2, *orderBy = NULL, *_3, *_6, *_7, *_4$$3, *_5$$3;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;

	ZEPHIR_MM_GROW();

	_1 = zephir_fetch_nproperty_this(this_ptr, SL("property"), PH_NOISY_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "notempty", &_0, 34, _1);
	zephir_check_call_status();
	_2 = zephir_fetch_nproperty_this(this_ptr, SL("direction"), PH_NOISY_CC);
	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "notempty", &_0, 34, _2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(orderBy);
	ZVAL_STRING(orderBy, "", 1);
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("alias"), PH_NOISY_CC);
	if (!(ZEPHIR_IS_EMPTY(_3))) {
		_4$$3 = zephir_fetch_nproperty_this(this_ptr, SL("alias"), PH_NOISY_CC);
		ZEPHIR_INIT_VAR(_5$$3);
		ZEPHIR_CONCAT_VVS(_5$$3, orderBy, _4$$3, ".");
		ZEPHIR_CPY_WRT(orderBy, _5$$3);
	}
	_6 = zephir_fetch_nproperty_this(this_ptr, SL("property"), PH_NOISY_CC);
	_7 = zephir_fetch_nproperty_this(this_ptr, SL("direction"), PH_NOISY_CC);
	ZEPHIR_CONCAT_VVSV(return_value, orderBy, _6, " ", _7);
	RETURN_MM();

}

