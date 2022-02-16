
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

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_page___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, pagable, PhalconPlus\\Base\\Pagable, 0)
	ZEND_ARG_TYPE_INFO(0, totalSize, IS_LONG, 0)
	ZEND_ARG_INFO(0, data)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_page_setpageno, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_page_setpagesize, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_page_settotalpage, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_page_getpageno, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_page_gettotalpage, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_page_gettotalsize, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_page_haspreviouspage, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_page_isfirstpage, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_page_islastpage, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_page_hasnextpage, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_page_getdata, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_page_isempty, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_page_method_entry) {
	PHP_ME(PhalconPlus_Base_Page, __construct, arginfo_phalconplus_base_page___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Page, setPageNo, arginfo_phalconplus_base_page_setpageno, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Page, setPageNo, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Page, setPageSize, arginfo_phalconplus_base_page_setpagesize, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Page, setPageSize, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Page, setTotalPage, arginfo_phalconplus_base_page_settotalpage, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Page, setTotalPage, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Page, getPageNo, arginfo_phalconplus_base_page_getpageno, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Page, getPageNo, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Page, getTotalPage, arginfo_phalconplus_base_page_gettotalpage, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Page, getTotalPage, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Page, getTotalSize, arginfo_phalconplus_base_page_gettotalsize, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Page, getTotalSize, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Page, hasPreviousPage, arginfo_phalconplus_base_page_haspreviouspage, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Page, hasPreviousPage, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Page, isFirstPage, arginfo_phalconplus_base_page_isfirstpage, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Page, isFirstPage, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Page, isLastPage, arginfo_phalconplus_base_page_islastpage, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Page, isLastPage, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Page, hasNextPage, arginfo_phalconplus_base_page_hasnextpage, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Page, hasNextPage, NULL, ZEND_ACC_PUBLIC)
#endif
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_Page, getData, arginfo_phalconplus_base_page_getdata, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_Page, getData, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_ME(PhalconPlus_Base_Page, isEmpty, arginfo_phalconplus_base_page_isempty, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
