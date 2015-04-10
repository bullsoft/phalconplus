
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
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Base_Service) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Base, Service, phalconplus, base_service, phalconplus_base_service_method_entry, 0);

	zend_declare_property_null(phalconplus_base_service_ce, SL("di"), ZEND_ACC_PRIVATE TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Base_Service, __construct) {

	zval *di;

	zephir_fetch_params(0, 1, 0, &di);



	zephir_update_property_this(this_ptr, SL("di"), di TSRMLS_CC);

}

PHP_METHOD(PhalconPlus_Base_Service, getDI) {


	RETURN_MEMBER(this_ptr, "di");

}

