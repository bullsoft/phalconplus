
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_Auth_UserProvider) {

	ZEPHIR_REGISTER_INTERFACE(PhalconPlus\\Contracts\\Auth, UserProvider, phalconplus, contracts_auth_userprovider, phalconplus_contracts_auth_userprovider_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(PhalconPlus_Contracts_Auth_UserProvider, getById);

ZEPHIR_DOC_METHOD(PhalconPlus_Contracts_Auth_UserProvider, getRole);

ZEPHIR_DOC_METHOD(PhalconPlus_Contracts_Auth_UserProvider, getIdName);

ZEPHIR_DOC_METHOD(PhalconPlus_Contracts_Auth_UserProvider, getIdValue);

ZEPHIR_DOC_METHOD(PhalconPlus_Contracts_Auth_UserProvider, setIdValue);

