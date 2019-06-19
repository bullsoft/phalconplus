
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


ZEPHIR_INIT_CLASS(PhalconPlus_Enum_AssertionCode) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Enum, AssertionCode, phalconplus, enum_assertioncode, phalconplus_enum_abstractenum_ce, NULL, 0);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_FLOAT"), 9);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_INTEGER"), 10);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_DIGIT"), 11);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_INTEGERISH"), 12);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_BOOLEAN"), 13);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("VALUE_EMPTY"), 14);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("VALUE_NULL"), 15);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_STRING"), 16);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_REGEX"), 17);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_MIN_LENGTH"), 18);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_MAX_LENGTH"), 19);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_STRING_START"), 20);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_STRING_CONTAINS"), 21);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_CHOICE"), 22);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_NUMERIC"), 23);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_ARRAY"), 24);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_KEY_EXISTS"), 26);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_NOT_BLANK"), 27);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_INSTANCE_OF"), 28);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_SUBCLASS_OF"), 29);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_RANGE"), 30);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_ALNUM"), 31);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_TRUE"), 32);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_EQ"), 33);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_SAME"), 34);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_MIN"), 35);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_MAX"), 36);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_LENGTH"), 37);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_FALSE"), 38);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_STRING_END"), 39);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_UUID"), 40);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_COUNT"), 41);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_NOT_EQ"), 42);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_NOT_SAME"), 43);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_TRAVERSABLE"), 44);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_ARRAY_ACCESSIBLE"), 45);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_KEY_ISSET"), 46);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_DIRECTORY"), 101);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_FILE"), 102);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_READABLE"), 103);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_WRITEABLE"), 104);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_CLASS"), 105);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_EMAIL"), 201);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INTERFACE_NOT_IMPLEMENTED"), 202);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_URL"), 203);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_NOT_INSTANCE_OF"), 204);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("VALUE_NOT_EMPTY"), 205);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_JSON_STRING"), 206);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_OBJECT"), 207);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_METHOD"), 208);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_SCALAR"), 209);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_RESOURCE"), 225);

	zephir_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_STRING_NOT_CONTAINS"), 229);

	return SUCCESS;

}

