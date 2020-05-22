
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_Invoke) {

	ZEPHIR_REGISTER_INTERFACE(PhalconPlus\\Contracts, Invoke, phalconplus, contracts_invoke, phalconplus_contracts_invoke_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(PhalconPlus_Contracts_Invoke, __invoke);

