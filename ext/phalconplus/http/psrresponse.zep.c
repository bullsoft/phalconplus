
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


ZEPHIR_INIT_CLASS(PhalconPlus_Http_PsrResponse) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Http, PsrResponse, phalconplus, http_psrresponse, zephir_get_internal_ce(SL("guzzlehttp\\psr7\\response")), NULL, 0);

	return SUCCESS;

}

