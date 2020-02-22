
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


ZEPHIR_INIT_CLASS(PhalconPlus_Facades_Url) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Facades, Url, phalconplus, facades_url, phalconplus_facades_abstractfacade_ce, phalconplus_facades_url_method_entry, 0);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Facades_Url, getName) {

	zval *this_ptr = getThis();


	RETURN_STRING("url");

}

