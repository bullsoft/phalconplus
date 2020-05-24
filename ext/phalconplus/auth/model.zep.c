
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Auth_Model) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Auth, Model, phalconplus, auth_model, phalconplus_auth_model_method_entry, 0);

	zend_declare_property_null(phalconplus_auth_model_ce, SL("user"), ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_auth_model_ce, SL("policies"), ZEND_ACC_PROTECTED);

	phalconplus_auth_model_ce->create_object = zephir_init_properties_PhalconPlus_Auth_Model;

	zend_class_implements(phalconplus_auth_model_ce, 1, phalconplus_contracts_auth_access_modelevent_ce);
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Auth_Model, getUser) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "user");

}

PHP_METHOD(PhalconPlus_Auth_Model, __construct) {

	zval *user, user_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &user);



	zephir_update_property_zval(this_ptr, ZEND_STRL("user"), user);

}

PHP_METHOD(PhalconPlus_Auth_Model, setUser) {

	zval *user, user_sub;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);

	zephir_fetch_params_without_memory_grow(1, 0, &user);



	zephir_update_property_zval(this_ptr, ZEND_STRL("user"), user);
	RETURN_THISW();

}

PHP_METHOD(PhalconPlus_Auth_Model, beforeDelete) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, *model, model_sub, *context = NULL, context_sub, __$null, instance, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &event, &model, &context);

	if (!context) {
		context = &context_sub;
		context = &__$null;
	}


	ZEPHIR_CALL_METHOD(&instance, this_ptr, "getpolicy", NULL, 0, model);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	if (zephir_is_true(&instance)) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_0, &instance, "delete", NULL, 0, &_1, model);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	RETURN_CCTOR(&_0);

}

PHP_METHOD(PhalconPlus_Auth_Model, beforeCreate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, *model, model_sub, *context = NULL, context_sub, __$null, instance, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &event, &model, &context);

	if (!context) {
		context = &context_sub;
		context = &__$null;
	}


	ZEPHIR_CALL_METHOD(&instance, this_ptr, "getpolicy", NULL, 0, model);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	if (zephir_is_true(&instance)) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_0, &instance, "create", NULL, 0, &_1, model);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	RETURN_CCTOR(&_0);

}

PHP_METHOD(PhalconPlus_Auth_Model, beforeUpdate) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *event, event_sub, *model, model_sub, *context = NULL, context_sub, __$null, instance, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &event, &model, &context);

	if (!context) {
		context = &context_sub;
		context = &__$null;
	}


	ZEPHIR_CALL_METHOD(&instance, this_ptr, "getpolicy", NULL, 0, model);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	if (zephir_is_true(&instance)) {
		zephir_read_property(&_1, this_ptr, ZEND_STRL("user"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_0, &instance, "update", NULL, 0, &_1, model);
		zephir_check_call_status();
	} else {
		ZVAL_BOOL(&_0, 0);
	}
	RETURN_CCTOR(&_0);

}

PHP_METHOD(PhalconPlus_Auth_Model, beforeValidation) {

	zval *event, event_sub, *model, model_sub, *context = NULL, context_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&event_sub);
	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&context_sub);
	ZVAL_NULL(&__$null);

	zephir_fetch_params_without_memory_grow(2, 1, &event, &model, &context);

	if (!context) {
		context = &context_sub;
		context = &__$null;
	}


	RETURN_BOOL(1);

}

PHP_METHOD(PhalconPlus_Auth_Model, getPolicy) {

	zend_class_entry *_4$$5;
	zval _1$$4;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *model, model_sub, modelClass, policyClass, instance, _2, _3$$5;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&model_sub);
	ZVAL_UNDEF(&modelClass);
	ZVAL_UNDEF(&policyClass);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &model);



	_0 = Z_TYPE_P(model) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(model, zephir_get_internal_ce(SL("phalcon\\mvc\\model")));
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&modelClass);
		zephir_get_class(&modelClass, model, 0);
	} else {
		zephir_get_strval(&_1$$4, model);
		ZEPHIR_CPY_WRT(&modelClass, &_1$$4);
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("policies"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&instance);
	if (zephir_array_isset_fetch(&policyClass, &_2, &modelClass, 1)) {
		zephir_fetch_safe_class(&_3$$5, &policyClass);
		_4$$5 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_3$$5), Z_STRLEN_P(&_3$$5), ZEND_FETCH_CLASS_AUTO);
		if(!_4$$5) {
			RETURN_MM_NULL();
		}
		object_init_ex(&instance, _4$$5);
		if (zephir_has_constructor(&instance)) {
			ZEPHIR_CALL_METHOD(NULL, &instance, "__construct", NULL, 0);
			zephir_check_call_status();
		}
	} else {
		object_init_ex(&instance, phalconplus_auth_policy_ce);
		ZEPHIR_CALL_METHOD(NULL, &instance, "__construct", NULL, 63);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&instance);

}

zend_object *zephir_init_properties_PhalconPlus_Auth_Model(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("policies"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("policies"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

