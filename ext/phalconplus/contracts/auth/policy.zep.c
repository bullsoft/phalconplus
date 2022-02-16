
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_Auth_Policy)
{
	ZEPHIR_REGISTER_INTERFACE(PhalconPlus\\Contracts\\Auth, Policy, phalconplus, contracts_auth_policy, phalconplus_contracts_auth_policy_method_entry);

	return SUCCESS;
}

ZEPHIR_DOC_METHOD(PhalconPlus_Contracts_Auth_Policy, list);
ZEPHIR_DOC_METHOD(PhalconPlus_Contracts_Auth_Policy, view);
ZEPHIR_DOC_METHOD(PhalconPlus_Contracts_Auth_Policy, delete);
ZEPHIR_DOC_METHOD(PhalconPlus_Contracts_Auth_Policy, create);
ZEPHIR_DOC_METHOD(PhalconPlus_Contracts_Auth_Policy, update);
