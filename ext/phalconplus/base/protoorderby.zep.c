
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


ZEPHIR_INIT_CLASS(PhalconPlus_Base_ProtoOrderBy)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, ProtoOrderBy, phalconplus, base_protoorderby, phalconplus_base_protobuffer_ce, phalconplus_base_protoorderby_method_entry, 0);

	/**
	 * @required
	 */
	zend_declare_property_null(phalconplus_base_protoorderby_ce, SL("property"), ZEND_ACC_PROTECTED);
	/**
	 * @required
	 */
	zend_declare_property_null(phalconplus_base_protoorderby_ce, SL("direction"), ZEND_ACC_PROTECTED);
	/**
	 * @optional
	 */
	zend_declare_property_string(phalconplus_base_protoorderby_ce, SL("alias"), "", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, getProperty)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "property");
}

PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, setProperty)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *property_param = NULL;
	zval property;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&property);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(property)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &property_param);
	if (UNEXPECTED(Z_TYPE_P(property_param) != IS_STRING && Z_TYPE_P(property_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'property' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(property_param) == IS_STRING)) {
		zephir_get_strval(&property, property_param);
	} else {
		ZEPHIR_INIT_VAR(&property);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("property"), &property);
	RETURN_THIS();
}

PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, setDirection)
{
	zval *orderBy, orderBy_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&orderBy_sub);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(orderBy, phalconplus_enum_orderbydirection_ce)
	ZEND_PARSE_PARAMETERS_END();
#endif


	zephir_fetch_params_without_memory_grow(1, 0, &orderBy);


	zephir_update_property_zval(this_ptr, ZEND_STRL("direction"), orderBy);
	RETURN_THISW();
}

PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, setAlias)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *alias_param = NULL;
	zval alias;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&alias);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(alias)
	ZEND_PARSE_PARAMETERS_END();
#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &alias_param);
	if (UNEXPECTED(Z_TYPE_P(alias_param) != IS_STRING && Z_TYPE_P(alias_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'alias' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(alias_param) == IS_STRING)) {
		zephir_get_strval(&alias, alias_param);
	} else {
		ZEPHIR_INIT_VAR(&alias);
	}


	zephir_update_property_zval(this_ptr, ZEND_STRL("alias"), &alias);
	RETURN_THIS();
}

PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, getDirection)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "direction");
}

PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, getAlias)
{
	zval *this_ptr = getThis();



	RETURN_MEMBER(getThis(), "alias");
}

PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, __toString)
{
	zval _1, _2, orderBy, _3, _6, _7, _4$$3, _5$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&orderBy);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$3);


	ZEPHIR_MM_GROW();

	zephir_read_property(&_1, this_ptr, ZEND_STRL("property"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "notempty", &_0, 0, &_1);
	zephir_check_call_status();
	zephir_read_property(&_2, this_ptr, ZEND_STRL("direction"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_CE_STATIC(NULL, phalconplus_assert_assertion_ce, "notempty", &_0, 0, &_2);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&orderBy);
	ZVAL_STRING(&orderBy, "");
	zephir_read_property(&_3, this_ptr, ZEND_STRL("alias"), PH_NOISY_CC | PH_READONLY);
	if (!(ZEPHIR_IS_EMPTY(&_3))) {
		zephir_read_property(&_4$$3, this_ptr, ZEND_STRL("alias"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_INIT_VAR(&_5$$3);
		ZEPHIR_CONCAT_VVS(&_5$$3, &orderBy, &_4$$3, ".");
		ZEPHIR_CPY_WRT(&orderBy, &_5$$3);
	}
	zephir_read_property(&_6, this_ptr, ZEND_STRL("property"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_7, this_ptr, ZEND_STRL("direction"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CONCAT_VVSV(return_value, &orderBy, &_6, " ", &_7);
	RETURN_MM();
}

