
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
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Curl_Exception) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Curl, Exception, phalconplus, curl_exception, phalconplus_base_exception_ce, phalconplus_curl_exception_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Curl_Exception, getRequest) {

	zval _0, _1, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);


	zephir_read_property(&_0, this_ptr, ZEND_STRL("info"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_long(&_1, &_0, 1, PH_NOISY | PH_READONLY, "phalconplus/Curl/Exception.zep", 9);
	zephir_array_fetch_long(&_2, &_1, 0, PH_NOISY | PH_READONLY, "phalconplus/Curl/Exception.zep", 9);
	RETURN_CTORW(&_2);

}

