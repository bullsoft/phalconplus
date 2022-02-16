
extern zend_class_entry *phalconplus_auth_userprovider_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Auth_UserProvider);

PHP_METHOD(PhalconPlus_Auth_UserProvider, getEntity);
PHP_METHOD(PhalconPlus_Auth_UserProvider, __construct);
PHP_METHOD(PhalconPlus_Auth_UserProvider, getById);
PHP_METHOD(PhalconPlus_Auth_UserProvider, getByToken);
PHP_METHOD(PhalconPlus_Auth_UserProvider, getByCredentials);
PHP_METHOD(PhalconPlus_Auth_UserProvider, loginByCredentials);
PHP_METHOD(PhalconPlus_Auth_UserProvider, loginByToken);
PHP_METHOD(PhalconPlus_Auth_UserProvider, checkLogin);
PHP_METHOD(PhalconPlus_Auth_UserProvider, checkLoginByToken);
PHP_METHOD(PhalconPlus_Auth_UserProvider, validateCredentials);
PHP_METHOD(PhalconPlus_Auth_UserProvider, guest);
PHP_METHOD(PhalconPlus_Auth_UserProvider, hashPassword);
PHP_METHOD(PhalconPlus_Auth_UserProvider, checkPassword);
PHP_METHOD(PhalconPlus_Auth_UserProvider, can);
PHP_METHOD(PhalconPlus_Auth_UserProvider, entity);
PHP_METHOD(PhalconPlus_Auth_UserProvider, hasAccess);
PHP_METHOD(PhalconPlus_Auth_UserProvider, getId);
PHP_METHOD(PhalconPlus_Auth_UserProvider, getRole);
PHP_METHOD(PhalconPlus_Auth_UserProvider, getName);
PHP_METHOD(PhalconPlus_Auth_UserProvider, getIdName);
PHP_METHOD(PhalconPlus_Auth_UserProvider, getUsernameName);
PHP_METHOD(PhalconPlus_Auth_UserProvider, getRoleName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_auth_userprovider_getentity, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_auth_userprovider___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, user)
	ZEND_ARG_TYPE_INFO(0, role, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_auth_userprovider_getbyid, 0, 1, PhalconPlus\\Auth\\UserProvider, 0)
	ZEND_ARG_TYPE_INFO(0, userId, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_auth_userprovider_getbytoken, 0, 1, PhalconPlus\\Auth\\UserProvider, 0)
	ZEND_ARG_TYPE_INFO(0, token, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_auth_userprovider_getbycredentials, 0, 1, Phalcon\\Mvc\\Model, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_auth_userprovider_loginbycredentials, 0, 1, PhalconPlus\\Auth\\UserProvider, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_auth_userprovider_loginbytoken, 0, 1, PhalconPlus\\Auth\\UserProvider, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_userprovider_checklogin, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_userprovider_checkloginbytoken, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_userprovider_validatecredentials, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, user, Phalcon\\Mvc\\Model, 0)
	ZEND_ARG_ARRAY_INFO(0, credentials, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_auth_userprovider_guest, 0, 0, PhalconPlus\\Auth\\UserProvider, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_userprovider_hashpassword, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, rawPasswd, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, makeSalt, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_userprovider_checkpassword, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, rawPasswd, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, encryptedPasswd, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, salt, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_userprovider_can, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, ability, IS_STRING, 0)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_auth_userprovider_entity, 0, 0, Phalcon\\Mvc\\Model, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_userprovider_hasaccess, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, roleName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_auth_userprovider_getid, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_userprovider_getrole, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_userprovider_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_userprovider_getidname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_userprovider_getusernamename, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_userprovider_getrolename, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_auth_userprovider_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Auth_UserProvider, getEntity, arginfo_phalconplus_auth_userprovider_getentity, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Auth_UserProvider, getEntity, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(PhalconPlus_Auth_UserProvider, __construct, arginfo_phalconplus_auth_userprovider___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Auth_UserProvider, getById, arginfo_phalconplus_auth_userprovider_getbyid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Auth_UserProvider, getByToken, arginfo_phalconplus_auth_userprovider_getbytoken, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Auth_UserProvider, getByCredentials, arginfo_phalconplus_auth_userprovider_getbycredentials, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Auth_UserProvider, loginByCredentials, arginfo_phalconplus_auth_userprovider_loginbycredentials, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Auth_UserProvider, loginByToken, arginfo_phalconplus_auth_userprovider_loginbytoken, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Auth_UserProvider, checkLogin, arginfo_phalconplus_auth_userprovider_checklogin, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Auth_UserProvider, checkLoginByToken, arginfo_phalconplus_auth_userprovider_checkloginbytoken, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Auth_UserProvider, validateCredentials, arginfo_phalconplus_auth_userprovider_validatecredentials, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Auth_UserProvider, guest, arginfo_phalconplus_auth_userprovider_guest, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Auth_UserProvider, hashPassword, arginfo_phalconplus_auth_userprovider_hashpassword, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Auth_UserProvider, checkPassword, arginfo_phalconplus_auth_userprovider_checkpassword, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(PhalconPlus_Auth_UserProvider, can, arginfo_phalconplus_auth_userprovider_can, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Auth_UserProvider, entity, arginfo_phalconplus_auth_userprovider_entity, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Auth_UserProvider, hasAccess, arginfo_phalconplus_auth_userprovider_hasaccess, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Auth_UserProvider, getId, arginfo_phalconplus_auth_userprovider_getid, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Auth_UserProvider, getId, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(PhalconPlus_Auth_UserProvider, getRole, arginfo_phalconplus_auth_userprovider_getrole, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Auth_UserProvider, getName, arginfo_phalconplus_auth_userprovider_getname, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Auth_UserProvider, getIdName, arginfo_phalconplus_auth_userprovider_getidname, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Auth_UserProvider, getUsernameName, arginfo_phalconplus_auth_userprovider_getusernamename, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Auth_UserProvider, getRoleName, arginfo_phalconplus_auth_userprovider_getrolename, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
