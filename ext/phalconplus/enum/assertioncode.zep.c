
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

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_FLOAT"), 9 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_INTEGER"), 10 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_DIGIT"), 11 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_INTEGERISH"), 12 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_BOOLEAN"), 13 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("VALUE_EMPTY"), 14 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("VALUE_NULL"), 15 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_STRING"), 16 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_REGEX"), 17 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_MIN_LENGTH"), 18 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_MAX_LENGTH"), 19 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_STRING_START"), 20 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_STRING_CONTAINS"), 21 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_CHOICE"), 22 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_NUMERIC"), 23 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_ARRAY"), 24 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_KEY_EXISTS"), 26 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_NOT_BLANK"), 27 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_INSTANCE_OF"), 28 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_SUBCLASS_OF"), 29 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_RANGE"), 30 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_ALNUM"), 31 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_TRUE"), 32 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_EQ"), 33 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_SAME"), 34 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_MIN"), 35 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_MAX"), 36 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_LENGTH"), 37 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_FALSE"), 38 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_STRING_END"), 39 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_UUID"), 40 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_COUNT"), 41 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_NOT_EQ"), 42 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_NOT_SAME"), 43 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_TRAVERSABLE"), 44 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_ARRAY_ACCESSIBLE"), 45 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_KEY_ISSET"), 46 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_DIRECTORY"), 101 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_FILE"), 102 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_READABLE"), 103 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_WRITEABLE"), 104 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_CLASS"), 105 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_EMAIL"), 201 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INTERFACE_NOT_IMPLEMENTED"), 202 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_URL"), 203 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_NOT_INSTANCE_OF"), 204 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("VALUE_NOT_EMPTY"), 205 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_JSON_STRING"), 206 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_OBJECT"), 207 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_METHOD"), 208 TSRMLS_CC);

	zend_declare_class_constant_long(phalconplus_enum_assertioncode_ce, SL("INVALID_SCALAR"), 209 TSRMLS_CC);

	return SUCCESS;

}

