
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

	zend_declare_class_constant_string(phalconplus_enum_runenv_ce, SL("DEV"), "dev" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_runenv_ce, SL("DEBUG"), "debug" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_runenv_ce, SL("TEST"), "test" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_runenv_ce, SL("UAT"), "uat" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_runenv_ce, SL("PRE_PRODUCTION"), "pre_production" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_runenv_ce, SL("AB_TEST"), "ab_test" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_runenv_ce, SL("PRODUCTION"), "production" TSRMLS_CC);

	zend_declare_class_constant_string(phalconplus_enum_runenv_ce, SL("__default"), "dev" TSRMLS_CC);

	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Enum_RunEnv, isInProd) {

	zval *env_param = NULL, _0, _1, *_2, _3, _4, _5, *_6;
	zval *env = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &env_param);

	zephir_get_strval(env, env_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, 0);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_LONG(&_1, 7);
	ZEPHIR_INIT_VAR(_2);
	zephir_substr(_2, env, 0 , 7 , 0);
	ZEPHIR_SINIT_VAR(_3);
	ZVAL_STRING(&_3, "production", 0);
	ZEPHIR_SINIT_VAR(_4);
	ZVAL_LONG(&_4, 0);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_LONG(&_5, 7);
	ZEPHIR_INIT_VAR(_6);
	zephir_substr(_6, &_3, 0 , 7 , 0);
	RETURN_MM_BOOL(ZEPHIR_IS_EQUAL(_2, _6));

}

PHP_METHOD(PhalconPlus_Enum_RunEnv, isInAbTest) {

	zval *_0, _1;


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("val"), PH_NOISY_CC);
	ZEPHIR_SINIT_VAR(_1);
	ZVAL_STRING(&_1, "ab_test", 0);
	RETURN_BOOL(ZEPHIR_IS_EQUAL(&_1, _0));

}

