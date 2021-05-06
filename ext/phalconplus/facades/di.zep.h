
extern zend_class_entry *phalconplus_facades_di_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Facades_Di);

PHP_METHOD(PhalconPlus_Facades_Di, getName);
PHP_METHOD(PhalconPlus_Facades_Di, resolve);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_facades_di_getname, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_facades_di_resolve, 0, 1, Phalcon\\Di, 1)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\Di, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_facades_di_method_entry) {
	PHP_ME(PhalconPlus_Facades_Di, getName, arginfo_phalconplus_facades_di_getname, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Facades_Di, resolve, arginfo_phalconplus_facades_di_resolve, ZEND_ACC_PROTECTED)
	PHP_FE_END
};
