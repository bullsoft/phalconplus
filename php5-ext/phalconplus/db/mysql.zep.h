
extern zend_class_entry *phalconplus_db_mysql_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Db_Mysql);

PHP_METHOD(PhalconPlus_Db_Mysql, __construct);
PHP_METHOD(PhalconPlus_Db_Mysql, getConnection);
zend_object_value zephir_init_properties_PhalconPlus_Db_Mysql(zend_class_entry *class_type TSRMLS_DC);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_mysql___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, di, Phalcon\\DI, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_db_mysql_method_entry) {
	PHP_ME(PhalconPlus_Db_Mysql, __construct, arginfo_phalconplus_db_mysql___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Db_Mysql, getConnection, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
