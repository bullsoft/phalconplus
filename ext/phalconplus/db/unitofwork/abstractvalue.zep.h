
extern zend_class_entry *phalconplus_db_unitofwork_abstractvalue_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Db_UnitOfWork_AbstractValue);

PHP_METHOD(PhalconPlus_Db_UnitOfWork_AbstractValue, getValue);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_abstractvalue_getvalue, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, unitwork, PhalconPlus\\Db\\UnitOfWork, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_db_unitofwork_abstractvalue_method_entry) {
	PHP_ME(PhalconPlus_Db_UnitOfWork_AbstractValue, getValue, arginfo_phalconplus_db_unitofwork_abstractvalue_getvalue, ZEND_ACC_ABSTRACT|ZEND_ACC_PUBLIC)
	PHP_FE_END
};
