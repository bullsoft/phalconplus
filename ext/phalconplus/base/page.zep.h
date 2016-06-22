
extern zend_class_entry *phalconplus_base_page_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_Page);

PHP_METHOD(PhalconPlus_Base_Page, __construct);
PHP_METHOD(PhalconPlus_Base_Page, setPageNo);
PHP_METHOD(PhalconPlus_Base_Page, setPageSize);
PHP_METHOD(PhalconPlus_Base_Page, setTotalPage);
PHP_METHOD(PhalconPlus_Base_Page, getPageNo);
PHP_METHOD(PhalconPlus_Base_Page, getTotalPage);
PHP_METHOD(PhalconPlus_Base_Page, getTotalSize);
PHP_METHOD(PhalconPlus_Base_Page, hasPreviousPage);
PHP_METHOD(PhalconPlus_Base_Page, isFirstPage);
PHP_METHOD(PhalconPlus_Base_Page, isLastPage);
PHP_METHOD(PhalconPlus_Base_Page, hasNextPage);
PHP_METHOD(PhalconPlus_Base_Page, getData);
PHP_METHOD(PhalconPlus_Base_Page, isEmpty);
PHP_METHOD(PhalconPlus_Base_Page, data2Array);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_page___construct, 0, 0, 3)
	ZEND_ARG_OBJ_INFO(0, pagable, PhalconPlus\\Base\\Pagable, 0)
	ZEND_ARG_INFO(0, totalSize)
	ZEND_ARG_OBJ_INFO(0, data, Phalcon\\Mvc\\Model\\Resultset, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_page_method_entry) {
	PHP_ME(PhalconPlus_Base_Page, __construct, arginfo_phalconplus_base_page___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(PhalconPlus_Base_Page, setPageNo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Page, setPageSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Page, setTotalPage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Page, getPageNo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Page, getTotalPage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Page, getTotalSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Page, hasPreviousPage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Page, isFirstPage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Page, isLastPage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Page, hasNextPage, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Page, getData, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Page, isEmpty, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Page, data2Array, NULL, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
