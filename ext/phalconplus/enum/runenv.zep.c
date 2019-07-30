
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
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Enum_RunEnv) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Enum, RunEnv, phalconplus, enum_runenv, phalconplus_enum_abstractenum_ce, phalconplus_enum_runenv_method_entry, 0);

	zephir_declare_class_constant_string(phalconplus_enum_runenv_ce, SL("DEV"), "dev");

	zephir_declare_class_constant_string(phalconplus_enum_runenv_ce, SL("DEBUG"), "debug");

	zephir_declare_class_constant_string(phalconplus_enum_runenv_ce, SL("TEST"), "test");

	zephir_declare_class_constant_string(phalconplus_enum_runenv_ce, SL("UAT"), "uat");

	zephir_declare_class_constant_string(phalconplus_enum_runenv_ce, SL("PRE_PRODUCTION"), "pre_production");

	zephir_declare_class_constant_string(phalconplus_enum_runenv_ce, SL("AB_TEST"), "ab_test");

	zephir_declare_class_constant_string(phalconplus_enum_runenv_ce, SL("PRODUCTION"), "production");

	zephir_declare_class_constant_string(phalconplus_enum_runenv_ce, SL("__default"), "dev");

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Enum_RunEnv, isInProd) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *env_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zval env;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&env);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &env_param);

	zephir_get_strval(&env, env_param);


	ZVAL_LONG(&_0, 0);
	ZVAL_LONG(&_1, 7);
	ZEPHIR_INIT_VAR(&_2);
	zephir_substr(&_2, &env, 0 , 7 , 0);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "production");
	ZVAL_LONG(&_4, 0);
	ZVAL_LONG(&_5, 7);
	ZEPHIR_INIT_VAR(&_6);
	zephir_substr(&_6, &_3, 0 , 7 , 0);
	RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(&_2, &_6));

}

PHP_METHOD(PhalconPlus_Enum_RunEnv, isInAbTest) {

	zval _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);


	zephir_read_property(&_0, this_ptr, SL("val"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "ab_test");
	RETURN_BOOL(ZEPHIR_IS_EQUAL(&_1, &_0));

}

