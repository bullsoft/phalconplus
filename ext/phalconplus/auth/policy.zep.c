
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Auth_Policy) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Auth, Policy, phalconplus, auth_policy, zephir_get_internal_ce(SL("phalcon\\di\\injectable")), phalconplus_auth_policy_method_entry, 0);

	zend_declare_property_null(phalconplus_auth_policy_ce, SL("acl"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalconplus_auth_policy_ce, 1, phalconplus_contracts_auth_policy_ce);
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Auth_Policy, __construct) {

	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "getdi", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "acl");
	ZEPHIR_CALL_METHOD(&_1, &_0, "get", NULL, 0, &_2);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("acl"), &_1);
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Auth_Policy, list) {

	zval _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *user, user_sub, *model, model_sub, _0, _1, _2, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &user, &model);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("acl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, user, "getrole", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_class(&_2, model, 0);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0);
	zephir_array_fast_append(&_3, user);
	zephir_array_fast_append(&_3, model);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "list");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "isallowed", NULL, 0, &_1, &_2, &_4, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Auth_Policy, view) {

	zval _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *user, user_sub, *model, model_sub, _0, _1, _2, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &user, &model);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("acl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, user, "getrole", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_class(&_2, model, 0);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0);
	zephir_array_fast_append(&_3, user);
	zephir_array_fast_append(&_3, model);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "view");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "isallowed", NULL, 0, &_1, &_2, &_4, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Auth_Policy, delete) {

	zval _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *user, user_sub, *model, model_sub, _0, _1, _2, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &user, &model);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("acl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, user, "getrole", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_class(&_2, model, 0);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0);
	zephir_array_fast_append(&_3, user);
	zephir_array_fast_append(&_3, model);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "delete");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "isallowed", NULL, 0, &_1, &_2, &_4, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Auth_Policy, update) {

	zval _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *user, user_sub, *model, model_sub, _0, _1, _2, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &user, &model);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("acl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, user, "getrole", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_class(&_2, model, 0);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0);
	zephir_array_fast_append(&_3, user);
	zephir_array_fast_append(&_3, model);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "update");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "isallowed", NULL, 0, &_1, &_2, &_4, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Auth_Policy, create) {

	zval _3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *user, user_sub, *model, model_sub, _0, _1, _2, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &user, &model);



	zephir_read_property(&_0, this_ptr, ZEND_STRL("acl"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, user, "getrole", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	zephir_get_class(&_2, model, 0);
	ZEPHIR_INIT_VAR(&_3);
	zephir_create_array(&_3, 2, 0);
	zephir_array_fast_append(&_3, user);
	zephir_array_fast_append(&_3, model);
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "create");
	ZEPHIR_RETURN_CALL_METHOD(&_0, "isallowed", NULL, 0, &_1, &_2, &_4, &_3);
	zephir_check_call_status();
	RETURN_MM();

}

