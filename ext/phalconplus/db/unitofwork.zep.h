
extern zend_class_entry *phalconplus_db_unitofwork_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Db_UnitOfWork);

PHP_METHOD(PhalconPlus_Db_UnitOfWork, __construct);
PHP_METHOD(PhalconPlus_Db_UnitOfWork, save);
PHP_METHOD(PhalconPlus_Db_UnitOfWork, insert);
PHP_METHOD(PhalconPlus_Db_UnitOfWork, update);
PHP_METHOD(PhalconPlus_Db_UnitOfWork, delete);
PHP_METHOD(PhalconPlus_Db_UnitOfWork, attach);
PHP_METHOD(PhalconPlus_Db_UnitOfWork, detach);
PHP_METHOD(PhalconPlus_Db_UnitOfWork, exec);
PHP_METHOD(PhalconPlus_Db_UnitOfWork, execInsert);
PHP_METHOD(PhalconPlus_Db_UnitOfWork, execUpdate);
PHP_METHOD(PhalconPlus_Db_UnitOfWork, execDelete);
PHP_METHOD(PhalconPlus_Db_UnitOfWork, getObjects);
PHP_METHOD(PhalconPlus_Db_UnitOfWork, getInserted);
PHP_METHOD(PhalconPlus_Db_UnitOfWork, getUpdated);
PHP_METHOD(PhalconPlus_Db_UnitOfWork, getDeleted);
PHP_METHOD(PhalconPlus_Db_UnitOfWork, getException);
PHP_METHOD(PhalconPlus_Db_UnitOfWork, getFailed);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork___construct, 0, 0, 1)
	ZEND_ARG_INFO(0, dbServiceName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_save, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_OBJ_INFO(0, model, PhalconPlus\\Base\\Model, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, initial_data, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, initial_data, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_insert, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_OBJ_INFO(0, model, PhalconPlus\\Base\\Model, 0)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, initial_data, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, initial_data, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_update, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, model)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, initial_data, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, initial_data, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_delete, 0, 0, 2)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_attach, 0, 0, 2)
	ZEND_ARG_INFO(0, model)
	ZEND_ARG_INFO(0, info)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_detach, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_db_unitofwork_exec, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_execinsert, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
	ZEND_ARG_ARRAY_INFO(0, info, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_execupdate, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, info, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, info, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_execdelete, 0, 0, 1)
	ZEND_ARG_INFO(0, model)
#if PHP_VERSION_ID >= 80000
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, info, IS_ARRAY, 0, "[]")
#else
	ZEND_ARG_ARRAY_INFO(0, info, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_getobjects, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_getinserted, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_getupdated, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_getdeleted, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_getexception, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_getfailed, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_db_unitofwork_method_entry) {
	PHP_ME(PhalconPlus_Db_UnitOfWork, __construct, arginfo_phalconplus_db_unitofwork___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Db_UnitOfWork, save, arginfo_phalconplus_db_unitofwork_save, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Db_UnitOfWork, insert, arginfo_phalconplus_db_unitofwork_insert, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Db_UnitOfWork, update, arginfo_phalconplus_db_unitofwork_update, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Db_UnitOfWork, delete, arginfo_phalconplus_db_unitofwork_delete, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Db_UnitOfWork, attach, arginfo_phalconplus_db_unitofwork_attach, ZEND_ACC_PROTECTED)
	PHP_ME(PhalconPlus_Db_UnitOfWork, detach, arginfo_phalconplus_db_unitofwork_detach, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Db_UnitOfWork, exec, arginfo_phalconplus_db_unitofwork_exec, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Db_UnitOfWork, execInsert, arginfo_phalconplus_db_unitofwork_execinsert, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Db_UnitOfWork, execUpdate, arginfo_phalconplus_db_unitofwork_execupdate, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Db_UnitOfWork, execDelete, arginfo_phalconplus_db_unitofwork_execdelete, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Db_UnitOfWork, getObjects, arginfo_phalconplus_db_unitofwork_getobjects, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Db_UnitOfWork, getObjects, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Db_UnitOfWork, getInserted, arginfo_phalconplus_db_unitofwork_getinserted, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Db_UnitOfWork, getInserted, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Db_UnitOfWork, getUpdated, arginfo_phalconplus_db_unitofwork_getupdated, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Db_UnitOfWork, getUpdated, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Db_UnitOfWork, getDeleted, arginfo_phalconplus_db_unitofwork_getdeleted, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Db_UnitOfWork, getDeleted, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Db_UnitOfWork, getException, arginfo_phalconplus_db_unitofwork_getexception, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Db_UnitOfWork, getException, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Db_UnitOfWork, getFailed, arginfo_phalconplus_db_unitofwork_getfailed, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Db_UnitOfWork, getFailed, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
