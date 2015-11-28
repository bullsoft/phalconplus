
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
#include "kernel/memory.h"
#include "kernel/fcall.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_SimpleResponse) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, SimpleResponse, phalconplus, base_simpleresponse, phalconplus_base_response_ce, phalconplus_base_simpleresponse_method_entry, 0);

	zend_declare_property_null(phalconplus_base_simpleresponse_ce, SL("result"), ZEND_ACC_PRIVATE TSRMLS_CC);

	phalconplus_base_simpleresponse_ce->create_object = zephir_init_properties_PhalconPlus_Base_SimpleResponse;
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_SimpleResponse, getResult) {

	

	RETURN_MEMBER(this_ptr, "result");

}

PHP_METHOD(PhalconPlus_Base_SimpleResponse, setResult) {

	zval *result_param = NULL;
	zval *result = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &result_param);

	zephir_get_arrval(result, result_param);


	zephir_update_property_this(this_ptr, SL("result"), result TSRMLS_CC);
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_SimpleResponse, pushItem) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *val, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &val);



	_0 = zephir_fetch_nproperty_this(this_ptr, SL("result"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_CALL_FUNCTION(NULL, "array_push", NULL, 31, _0, val);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	RETURN_THIS();

}

PHP_METHOD(PhalconPlus_Base_SimpleResponse, popItem) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	_0 = zephir_fetch_nproperty_this(this_ptr, SL("result"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(_0);
	ZEPHIR_RETURN_CALL_FUNCTION("array_pop", NULL, 33, _0);
	ZEPHIR_UNREF(_0);
	zephir_check_call_status();
	RETURN_MM();

}

static zend_object_value zephir_init_properties_PhalconPlus_Base_SimpleResponse(zend_class_entry *class_type TSRMLS_DC) {

		zval *_0, *_1$$3;

		ZEPHIR_MM_GROW();
	
	{
		zval *this_ptr = NULL;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		_0 = zephir_fetch_nproperty_this(this_ptr, SL("result"), PH_NOISY_CC);
		if (Z_TYPE_P(_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(_1$$3);
			array_init(_1$$3);
			zephir_update_property_this(this_ptr, SL("result"), _1$$3 TSRMLS_CC);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJVAL_P(this_ptr);
	}

}

