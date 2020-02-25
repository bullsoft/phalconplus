
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_exceptions.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Contracts_Auth_Access_Authorizable) {

	ZEPHIR_REGISTER_INTERFACE(PhalconPlus\\Contracts\\Auth\\Access, Authorizable, phalconplus, contracts_auth_access_authorizable, phalconplus_contracts_auth_access_authorizable_method_entry);

	return SUCCESS;

}

ZEPHIR_DOC_METHOD(PhalconPlus_Contracts_Auth_Access_Authorizable, can);

