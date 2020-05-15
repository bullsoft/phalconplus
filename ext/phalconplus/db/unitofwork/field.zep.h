
extern zend_class_entry *phalconplus_db_unitofwork_field_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Db_UnitOfWork_Field);

PHP_METHOD(PhalconPlus_Db_UnitOfWork_Field, __construct);
PHP_METHOD(PhalconPlus_Db_UnitOfWork_Field, getValue);
PHP_METHOD(PhalconPlus_Db_UnitOfWork_Field, getField);
PHP_METHOD(PhalconPlus_Db_UnitOfWork_Field, __toString);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_field___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, model, Phalcon\\Mvc\\Model, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, attr, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, attr)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_field_getvalue, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, unitwork, PhalconPlus\\Db\\UnitOfWork, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_unitofwork_field_getfield, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, unitwork, PhalconPlus\\Db\\UnitOfWork, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_db_unitofwork_field_method_entry) {
	PHP_ME(PhalconPlus_Db_UnitOfWork_Field, __construct, arginfo_phalconplus_db_unitofwork_field___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Db_UnitOfWork_Field, getValue, arginfo_phalconplus_db_unitofwork_field_getvalue, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Db_UnitOfWork_Field, getField, arginfo_phalconplus_db_unitofwork_field_getfield, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Db_UnitOfWork_Field, __toString, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
