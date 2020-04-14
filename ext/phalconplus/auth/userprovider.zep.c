
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
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


ZEPHIR_INIT_CLASS(PhalconPlus_Auth_UserProvider) {

	ZEPHIR_REGISTER_CLASS_EX(PhalconPlus\\Auth, UserProvider, phalconplus, auth_userprovider, phalconplus_base_protobuffer_ce, phalconplus_auth_userprovider_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalconplus_auth_userprovider_ce, SL("id"), ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalconplus_auth_userprovider_ce, SL("role"), "Guests", ZEND_ACC_PROTECTED);

	zend_declare_property_string(phalconplus_auth_userprovider_ce, SL("name"), "", ZEND_ACC_PROTECTED);

	zend_declare_property_null(phalconplus_auth_userprovider_ce, SL("entity"), ZEND_ACC_PROTECTED);

	zend_class_implements(phalconplus_auth_userprovider_ce, 1, phalconplus_contracts_auth_userprovider_ce);
	return SUCCESS;

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, getEntity) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "entity");

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, __construct) {

	zend_class_entry *_3$$3, *_14$$8;
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval role;
	zval *user = NULL, user_sub, *role_param = NULL, __$null, _1$$3, _2$$3, _4$$4, _5$$4, _6$$4, idName$$6, usernameName$$6, roleName$$6, _7$$6, _8$$6, _9$$7, _10$$7, _11$$7, _12$$8, _13$$8;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&idName$$6);
	ZVAL_UNDEF(&usernameName$$6);
	ZVAL_UNDEF(&roleName$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&role);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &user, &role_param);

	if (!user) {
		user = &user_sub;
		ZEPHIR_CPY_WRT(user, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(user);
	}
	if (!role_param) {
		ZEPHIR_INIT_VAR(&role);
		ZVAL_STRING(&role, "Guests");
	} else {
		zephir_get_strval(&role, role_param);
	}


	BEGIN:
	_0 = Z_TYPE_P(user) == IS_OBJECT;
	if (_0) {
		_0 = zephir_instance_of_ev(user, zephir_get_internal_ce(SL("phalcon\\mvc\\model")));
	}
	if (Z_TYPE_P(user) == IS_NULL) {
		ZEPHIR_INIT_ZVAL_NREF(_1$$3);
		ZVAL_LONG(&_1$$3, 0);
		zephir_update_property_zval(this_ptr, SL("id"), &_1$$3);
		_3$$3 = zephir_fetch_class_str_ex(SL("Phalcon\\Text"), ZEND_FETCH_CLASS_AUTO);
		ZVAL_LONG(&_1$$3, 0);
		ZEPHIR_CALL_CE_STATIC(&_2$$3, _3$$3, "random", NULL, 0, &_1$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("name"), &_2$$3);
		zephir_update_property_zval(this_ptr, SL("role"), &role);
	} else if (Z_TYPE_P(user) == IS_ARRAY) {
		if (!(zephir_array_isset_string(user, SL("id")))) {
			ZEPHIR_INIT_NVAR(user);
			ZVAL_NULL(user);
			goto BEGIN;
		}
		zephir_array_fetch_string(&_4$$4, user, SL("id"), PH_NOISY | PH_READONLY, "phalconplus/Auth/UserProvider.zep", 28);
		zephir_update_property_zval(this_ptr, SL("id"), &_4$$4);
		zephir_array_fetch_string(&_5$$4, user, SL("name"), PH_NOISY | PH_READONLY, "phalconplus/Auth/UserProvider.zep", 29);
		zephir_update_property_zval(this_ptr, SL("name"), &_5$$4);
		zephir_array_fetch_string(&_6$$4, user, SL("role"), PH_NOISY | PH_READONLY, "phalconplus/Auth/UserProvider.zep", 30);
		zephir_update_property_zval(this_ptr, SL("role"), &_6$$4);
	} else if (_0) {
		ZEPHIR_CALL_METHOD(&idName$$6, this_ptr, "getidname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&usernameName$$6, this_ptr, "getusernamename", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&roleName$$6, this_ptr, "getrolename", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&_7$$6);
		zephir_read_property_zval(&_7$$6, user, &idName$$6, PH_NOISY_CC);
		zephir_update_property_zval(this_ptr, SL("id"), &_7$$6);
		ZEPHIR_OBS_VAR(&_8$$6);
		zephir_read_property(&_8$$6, this_ptr, SL("id"), PH_NOISY_CC);
		if (!(ZEPHIR_IS_EMPTY(&_8$$6))) {
			ZEPHIR_OBS_VAR(&_9$$7);
			zephir_read_property_zval(&_9$$7, user, &usernameName$$6, PH_NOISY_CC);
			zephir_update_property_zval(this_ptr, SL("name"), &_9$$7);
			ZEPHIR_INIT_VAR(&_10$$7);
			ZEPHIR_OBS_VAR(&_11$$7);
			zephir_read_property_zval(&_11$$7, user, &roleName$$6, PH_NOISY_CC);
			if (ZEPHIR_IS_EMPTY(&_11$$7)) {
				ZEPHIR_INIT_NVAR(&_10$$7);
				ZVAL_STRING(&_10$$7, "Members");
			} else {
				ZEPHIR_OBS_NVAR(&_10$$7);
				zephir_read_property_zval(&_10$$7, user, &roleName$$6, PH_NOISY_CC);
			}
			zephir_update_property_zval(this_ptr, SL("role"), &_10$$7);
			zephir_update_property_zval(this_ptr, SL("entity"), user);
		} else {
			ZEPHIR_INIT_ZVAL_NREF(_12$$8);
			ZVAL_LONG(&_12$$8, 0);
			zephir_update_property_zval(this_ptr, SL("id"), &_12$$8);
			_14$$8 = zephir_fetch_class_str_ex(SL("Phalcon\\Text"), ZEND_FETCH_CLASS_AUTO);
			ZVAL_LONG(&_12$$8, 0);
			ZEPHIR_CALL_CE_STATIC(&_13$$8, _14$$8, "random", NULL, 0, &_12$$8);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("name"), &_13$$8);
			zephir_update_property_zval(this_ptr, SL("role"), &role);
		}
	} else {
		ZEPHIR_INIT_NVAR(user);
		ZVAL_NULL(user);
		goto BEGIN;
	}
	ZEPHIR_MM_RESTORE();

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, getById) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *userId_param = NULL;
	zval userId;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&userId);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &userId_param);

	zephir_get_strval(&userId, userId_param);



}

PHP_METHOD(PhalconPlus_Auth_UserProvider, getByToken) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *token_param = NULL;
	zval token;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&token);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &token_param);

	zephir_get_strval(&token, token_param);



}

PHP_METHOD(PhalconPlus_Auth_UserProvider, getByCredentials) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *credentials_param = NULL;
	zval credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &credentials_param);

	zephir_get_arrval(&credentials, credentials_param);



}

PHP_METHOD(PhalconPlus_Auth_UserProvider, loginByCredentials) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *credentials_param = NULL;
	zval credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &credentials_param);

	zephir_get_arrval(&credentials, credentials_param);



}

PHP_METHOD(PhalconPlus_Auth_UserProvider, loginByToken) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *credentials_param = NULL;
	zval credentials;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&credentials);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &credentials_param);

	zephir_get_arrval(&credentials, credentials_param);



}

PHP_METHOD(PhalconPlus_Auth_UserProvider, checkLogin) {

	zval *this_ptr = getThis();


	RETURN_BOOL(0);

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, checkLoginByToken) {

	zval *this_ptr = getThis();


	RETURN_BOOL(0);

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, validateCredentials) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval credentials;
	zval *user, user_sub, *credentials_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_UNDEF(&credentials);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &user, &credentials_param);

	zephir_get_arrval(&credentials, credentials_param);


	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, guest) {

	zend_class_entry *_1;
	zval userClass, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&userClass);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&userClass);
	zephir_get_called_class(&userClass);
	zephir_fetch_safe_class(&_0, &userClass);
	_1 = zephir_fetch_class_str_ex(Z_STRVAL_P(&_0), Z_STRLEN_P(&_0), ZEND_FETCH_CLASS_AUTO);
	if(!_1) {
		RETURN_MM_NULL();
	}
	object_init_ex(return_value, _1);
	if (zephir_has_constructor(return_value)) {
		ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0);
		zephir_check_call_status();
	}
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, hashPassword) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zend_bool makeSalt;
	zval *rawPasswd_param = NULL, *makeSalt_param = NULL, sec, salt, encryptedPasswd, _0;
	zval rawPasswd;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawPasswd);
	ZVAL_UNDEF(&sec);
	ZVAL_UNDEF(&salt);
	ZVAL_UNDEF(&encryptedPasswd);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &rawPasswd_param, &makeSalt_param);

	zephir_get_strval(&rawPasswd, rawPasswd_param);
	if (!makeSalt_param) {
		makeSalt = 0;
	} else {
		makeSalt = zephir_get_boolval(makeSalt_param);
	}


	ZEPHIR_INIT_VAR(&salt);
	ZVAL_STRING(&salt, "");
	ZEPHIR_INIT_VAR(&encryptedPasswd);
	ZVAL_STRING(&encryptedPasswd, "");
	ZEPHIR_INIT_VAR(&sec);
	object_init_ex(&sec, zephir_get_internal_ce(SL("phalcon\\security")));
	ZEPHIR_CALL_METHOD(NULL, &sec, "__construct", NULL, 0);
	zephir_check_call_status();
	if (makeSalt == 1) {
		ZEPHIR_CALL_METHOD(&salt, &sec, "getsaltbytes", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VV(&_0, &rawPasswd, &salt);
	ZEPHIR_CALL_METHOD(&encryptedPasswd, &sec, "hash", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_create_array(return_value, 3, 0);
	zephir_array_update_string(return_value, SL("raw"), &rawPasswd, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("encrypted"), &encryptedPasswd, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("salt"), &salt, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, checkPassword) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rawPasswd_param = NULL, *encryptedPasswd_param = NULL, *salt_param = NULL, sec;
	zval rawPasswd, encryptedPasswd, salt, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawPasswd);
	ZVAL_UNDEF(&encryptedPasswd);
	ZVAL_UNDEF(&salt);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&sec);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &rawPasswd_param, &encryptedPasswd_param, &salt_param);

	zephir_get_strval(&rawPasswd, rawPasswd_param);
	zephir_get_strval(&encryptedPasswd, encryptedPasswd_param);
	if (!salt_param) {
		ZEPHIR_INIT_VAR(&salt);
		ZVAL_STRING(&salt, "");
	} else {
		zephir_get_strval(&salt, salt_param);
	}


	ZEPHIR_INIT_VAR(&sec);
	object_init_ex(&sec, zephir_get_internal_ce(SL("phalcon\\security")));
	ZEPHIR_CALL_METHOD(NULL, &sec, "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VV(&_0, &rawPasswd, &salt);
	ZEPHIR_RETURN_CALL_METHOD(&sec, "checkhash", NULL, 0, &_0, &encryptedPasswd);
	zephir_check_call_status();
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, can) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *ability_param = NULL, *params, params_sub;
	zval ability;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&ability);
	ZVAL_UNDEF(&params_sub);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &ability_param, &params);

	zephir_get_strval(&ability, ability_param);


	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, entity) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "entity");

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, hasAccess) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *roleName_param = NULL;
	zval roleName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&roleName);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &roleName_param);

	zephir_get_strval(&roleName, roleName_param);


	RETURN_MM_BOOL(0);

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, getId) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "id");

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, getRole) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "role");

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, getIdName) {

	zval *this_ptr = getThis();


	RETURN_STRING("id");

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, getUsernameName) {

	zval *this_ptr = getThis();


	RETURN_STRING("username");

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, getRoleName) {

	zval *this_ptr = getThis();


	RETURN_STRING("role");

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, jsonSerialize) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_create_array(return_value, 3, 0);
	ZEPHIR_OBS_VAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("name"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("name"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("id"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("id"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_OBS_NVAR(&_0);
	zephir_read_property(&_0, this_ptr, SL("role"), PH_NOISY_CC);
	zephir_array_update_string(return_value, SL("role"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

