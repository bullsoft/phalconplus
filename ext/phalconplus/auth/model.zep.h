
extern zend_class_entry *phalconplus_auth_model_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Auth_Model);

PHP_METHOD(PhalconPlus_Auth_Model, getUser);
PHP_METHOD(PhalconPlus_Auth_Model, __construct);
PHP_METHOD(PhalconPlus_Auth_Model, setUser);
PHP_METHOD(PhalconPlus_Auth_Model, beforeDelete);
PHP_METHOD(PhalconPlus_Auth_Model, beforeCreate);
PHP_METHOD(PhalconPlus_Auth_Model, beforeUpdate);
PHP_METHOD(PhalconPlus_Auth_Model, beforeValidation);
PHP_METHOD(PhalconPlus_Auth_Model, getPolicy);
zend_object *zephir_init_properties_PhalconPlus_Auth_Model(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_auth_model_getuser, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_auth_model___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, user, PhalconPlus\\Contracts\\Auth\\UserProvider, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_auth_model_setuser, 0, 1, PhalconPlus\\Auth\\Model, 0)
	ZEND_ARG_OBJ_INFO(0, user, PhalconPlus\\Contracts\\Auth\\UserProvider, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_model_beforedelete, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_model_beforecreate, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_model_beforeupdate, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_auth_model_beforevalidation, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, event, Phalcon\\Events\\Event, 0)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
	ZEND_ARG_INFO(0, context)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_auth_model_getpolicy, 0, 1, PhalconPlus\\Contracts\\Auth\\Policy, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_auth_model_zephir_init_properties_phalconplus_auth_model, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_auth_model_method_entry) {
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Auth_Model, getUser, arginfo_phalconplus_auth_model_getuser, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Auth_Model, getUser, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(PhalconPlus_Auth_Model, __construct, arginfo_phalconplus_auth_model___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Auth_Model, setUser, arginfo_phalconplus_auth_model_setuser, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Auth_Model, beforeDelete, arginfo_phalconplus_auth_model_beforedelete, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Auth_Model, beforeCreate, arginfo_phalconplus_auth_model_beforecreate, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Auth_Model, beforeUpdate, arginfo_phalconplus_auth_model_beforeupdate, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Auth_Model, beforeValidation, arginfo_phalconplus_auth_model_beforevalidation, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Auth_Model, getPolicy, arginfo_phalconplus_auth_model_getpolicy, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
