
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


ZEPHIR_INIT_CLASS(PhalconPlus_Enum_OrderByDirection) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Enum, OrderByDirection, phalconplus, enum_orderbydirection, phalconplus_enum_abstractenum_ce, NULL, 0);

	zephir_declare_class_constant_string(phalconplus_enum_orderbydirection_ce, SL("__default"), "ASC");

	zephir_declare_class_constant_string(phalconplus_enum_orderbydirection_ce, SL("ASC"), "ASC");

	zephir_declare_class_constant_string(phalconplus_enum_orderbydirection_ce, SL("DESC"), "DESC");

	return SUCCESS;

}

