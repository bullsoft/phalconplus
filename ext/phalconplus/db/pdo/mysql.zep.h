
extern zend_class_entry *phalconplus_db_pdo_mysql_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Db_Pdo_Mysql);

PHP_METHOD(PhalconPlus_Db_Pdo_Mysql, __construct);
PHP_METHOD(PhalconPlus_Db_Pdo_Mysql, __get);
PHP_METHOD(PhalconPlus_Db_Pdo_Mysql, isUnderTransaction);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_pdo_mysql___construct, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, descriptor, 0)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, autoConnect, _IS_BOOL, 0)
#else
	ZEND_ARG_INFO(0, autoConnect)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_db_pdo_mysql___get, 0, 0, 1)
#if PHP_VERSION_ID >= 70200
	ZEND_ARG_TYPE_INFO(0, prop, IS_STRING, 0)
#else
	ZEND_ARG_INFO(0, prop)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_db_pdo_mysql_isundertransaction, 0, 0, _IS_BOOL, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_db_pdo_mysql_isundertransaction, 0, 0, _IS_BOOL, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_db_pdo_mysql_method_entry) {
	PHP_ME(PhalconPlus_Db_Pdo_Mysql, __construct, arginfo_phalconplus_db_pdo_mysql___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Db_Pdo_Mysql, __get, arginfo_phalconplus_db_pdo_mysql___get, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Db_Pdo_Mysql, isUnderTransaction, arginfo_phalconplus_db_pdo_mysql_isundertransaction, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
