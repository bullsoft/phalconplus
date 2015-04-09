
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


ZEPHIR_INIT_CLASS(PhalconPlus_Base_BackendServer) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Base, BackendServer, phalconplus, base_backendserver, NULL, 0);

	return SUCCESS;

}

