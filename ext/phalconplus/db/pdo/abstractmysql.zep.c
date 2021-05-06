
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


ZEPHIR_INIT_CLASS(PhalconPlus_Db_Pdo_AbstractMysql)
{
	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Db\\Pdo, AbstractMysql, phalconplus, db_pdo_abstractmysql, zephir_get_internal_ce(SL("phalcon\\db\\adapter\\pdo\\mysql")), NULL, 0);

	return SUCCESS;
}

