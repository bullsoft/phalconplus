
extern zend_class_entry *phalconplus_db_mysql_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Db_Mysql);

PHP_METHOD(PhalconPlus_Db_Mysql, __construct);
PHP_METHOD(PhalconPlus_Db_Mysql, getConnection);
zend_object *zephir_init_properties_PhalconPlus_Db_Mysql(zend_class_entry *class_type);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_mysql___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\Di\\Di, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_db_mysql_getconnection, 0, 0, Phalcon\\Db\\Adapter\\Pdo\\Mysql, 0)
	ZEND_ARG_TYPE_INFO(0, autoConnect, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_mysql_zephir_init_properties_phalconplus_db_mysql, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_db_mysql_method_entry) {
	PHP_ME(PhalconPlus_Db_Mysql, __construct, arginfo_phalconplus_db_mysql___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Db_Mysql, getConnection, arginfo_phalconplus_db_mysql_getconnection, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
