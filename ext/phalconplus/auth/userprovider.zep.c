
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


ZEPHIR_INIT_CLASS(PhalconPlus_Auth_UserProvider) {

	ZEPHIR_REGISTER_CLASS(PhalconPlus\\Auth, UserProvider, phalconplus, auth_userprovider, phalconplus_auth_userprovider_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

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

	zend_class_entry *_2$$3, *_10$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval role;
	zval *user = NULL, user_sub, *role_param = NULL, __$null, _0$$3, _1$$3, idName$$4, usernameName$$4, roleName$$4, _3$$4, _4$$4, _5$$5, _6$$5, _7$$5, _8$$6, _9$$6;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&user_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&idName$$4);
	ZVAL_UNDEF(&usernameName$$4);
	ZVAL_UNDEF(&roleName$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&role);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 2, &user, &role_param);

	if (!user) {
		user = &user_sub;
		user = &__$null;
	}
	if (!role_param) {
		ZEPHIR_INIT_VAR(&role);
		ZVAL_STRING(&role, "Guests");
	} else {
		zephir_get_strval(&role, role_param);
	}


	if (Z_TYPE_P(user) == IS_NULL) {
		ZEPHIR_INIT_ZVAL_NREF(_0$$3);
		ZVAL_LONG(&_0$$3, 0);
		zephir_update_property_zval(this_ptr, SL("id"), &_0$$3);
		_2$$3 = zephir_fetch_class_str_ex(SL("Phalcon\\Text"), ZEND_FETCH_CLASS_AUTO);
		ZVAL_LONG(&_0$$3, 0);
		ZEPHIR_CALL_CE_STATIC(&_1$$3, _2$$3, "random", NULL, 0, &_0$$3);
		zephir_check_call_status();
		zephir_update_property_zval(this_ptr, SL("name"), &_1$$3);
		zephir_update_property_zval(this_ptr, SL("role"), &role);
	} else {
		ZEPHIR_CALL_METHOD(&idName$$4, this_ptr, "getidname", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&usernameName$$4, this_ptr, "getusernamename", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&roleName$$4, this_ptr, "getrolename", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_OBS_VAR(&_3$$4);
		zephir_read_property_zval(&_3$$4, user, &idName$$4, PH_NOISY_CC);
		zephir_update_property_zval(this_ptr, SL("id"), &_3$$4);
		ZEPHIR_OBS_VAR(&_4$$4);
		zephir_read_property(&_4$$4, this_ptr, SL("id"), PH_NOISY_CC);
		if (!(ZEPHIR_IS_EMPTY(&_4$$4))) {
			ZEPHIR_OBS_VAR(&_5$$5);
			zephir_read_property_zval(&_5$$5, user, &usernameName$$4, PH_NOISY_CC);
			zephir_update_property_zval(this_ptr, SL("name"), &_5$$5);
			ZEPHIR_INIT_VAR(&_6$$5);
			ZEPHIR_OBS_VAR(&_7$$5);
			zephir_read_property_zval(&_7$$5, user, &roleName$$4, PH_NOISY_CC);
			if (ZEPHIR_IS_EMPTY(&_7$$5)) {
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZVAL_STRING(&_6$$5, "Members");
			} else {
				ZEPHIR_OBS_NVAR(&_6$$5);
				zephir_read_property_zval(&_6$$5, user, &roleName$$4, PH_NOISY_CC);
			}
			zephir_update_property_zval(this_ptr, SL("role"), &_6$$5);
			zephir_update_property_zval(this_ptr, SL("entity"), user);
		} else {
			ZEPHIR_INIT_ZVAL_NREF(_8$$6);
			ZVAL_LONG(&_8$$6, 0);
			zephir_update_property_zval(this_ptr, SL("id"), &_8$$6);
			_10$$6 = zephir_fetch_class_str_ex(SL("Phalcon\\Text"), ZEND_FETCH_CLASS_AUTO);
			ZVAL_LONG(&_8$$6, 0);
			ZEPHIR_CALL_CE_STATIC(&_9$$6, _10$$6, "random", NULL, 0, &_8$$6);
			zephir_check_call_status();
			zephir_update_property_zval(this_ptr, SL("name"), &_9$$6);
			zephir_update_property_zval(this_ptr, SL("role"), &role);
		}
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

	zend_class_entry *_1;
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
	_1 = zephir_fetch_class_str_ex(SL("Phalcon\\Text"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_CALL_CE_STATIC(&_0, _1, "concat", NULL, 0, &rawPasswd, &salt);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&encryptedPasswd, &sec, "hash", NULL, 0, &_0);
	zephir_check_call_status();
	zephir_create_array(return_value, 3, 0);
	zephir_array_update_string(return_value, SL("raw"), &rawPasswd, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("encrypted"), &encryptedPasswd, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(return_value, SL("salt"), &salt, PH_COPY | PH_SEPARATE);
	RETURN_MM();

}

PHP_METHOD(PhalconPlus_Auth_UserProvider, checkPassword) {

	zend_class_entry *_1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *rawPasswd_param = NULL, *encryptedPasswd_param = NULL, *salt_param = NULL, sec, _0;
	zval rawPasswd, encryptedPasswd, salt;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&rawPasswd);
	ZVAL_UNDEF(&encryptedPasswd);
	ZVAL_UNDEF(&salt);
	ZVAL_UNDEF(&sec);
	ZVAL_UNDEF(&_0);

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
	_1 = zephir_fetch_class_str_ex(SL("Phalcon\\Text"), ZEND_FETCH_CLASS_AUTO);
	ZEPHIR_CALL_CE_STATIC(&_0, _1, "concat", NULL, 0, &rawPasswd, &salt);
	zephir_check_call_status();
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
