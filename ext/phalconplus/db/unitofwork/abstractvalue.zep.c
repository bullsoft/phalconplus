
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Db_UnitOfWork_AbstractValue) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Db\\UnitOfWork, AbstractValue, phalconplus, db_unitofwork_abstractvalue, phalconplus_db_unitofwork_abstractvalue_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Db_UnitOfWork_AbstractValue, getValue) {

}

