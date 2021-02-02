
extern zend_class_entry *phalconplus_db_unitofwork_lastinsertid_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Db_UnitOfWork_LastInsertId);

PHP_METHOD(PhalconPlus_Db_UnitOfWork_LastInsertId, __construct);
PHP_METHOD(PhalconPlus_Db_UnitOfWork_LastInsertId, getValue);
PHP_METHOD(PhalconPlus_Db_UnitOfWork_LastInsertId, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_lastinsertid___construct, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_lastinsertid_getvalue, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, unitwork, PhalconPlus\\Db\\UnitOfWork, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_db_unitofwork_lastinsertid___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_db_unitofwork_lastinsertid___tostring, 0, 0, IS_STRING, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_db_unitofwork_lastinsertid_method_entry) {
	PHP_ME(PhalconPlus_Db_UnitOfWork_LastInsertId, __construct, arginfo_phalconplus_db_unitofwork_lastinsertid___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Db_UnitOfWork_LastInsertId, getValue, arginfo_phalconplus_db_unitofwork_lastinsertid_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Db_UnitOfWork_LastInsertId, __toString, arginfo_phalconplus_db_unitofwork_lastinsertid___tostring, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
