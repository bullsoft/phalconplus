
extern zend_class_entry *phalconplus_facades_acl_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Facades_Acl);

PHP_METHOD(PhalconPlus_Facades_Acl, getName);
PHP_METHOD(PhalconPlus_Facades_Acl, resolve);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_facades_acl_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_facades_acl_resolve, 0, 1, Phalcon\\Di\\Di, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\Di\\Di, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_facades_acl_method_entry) {
	PHP_ME(PhalconPlus_Facades_Acl, getName, arginfo_phalconplus_facades_acl_getname, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Facades_Acl, resolve, arginfo_phalconplus_facades_acl_resolve, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
