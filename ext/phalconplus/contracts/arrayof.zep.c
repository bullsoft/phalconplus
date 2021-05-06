
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_ArrayOf)
{
	ZEPHIR_REGISTER_INTERFACE(PhalconPlus\\Contracts, ArrayOf, phalconplus, contracts_arrayof, phalconplus_contracts_arrayof_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(PhalconPlus_Contracts_ArrayOf, toArray);
