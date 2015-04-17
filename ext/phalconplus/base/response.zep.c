
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


ZEPHIR_INIT_CLASS(PhalconPlus_Base_Response) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Base, Response, phalconplus, base_response, phalconplus_base_protobuffer_ce, NULL, 0);

	return SUCCESS;

}

