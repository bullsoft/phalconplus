
extern zend_class_entry *phalconplus_base_pagable_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_Pagable);

PHP_METHOD(PhalconPlus_Base_Pagable, getPageNo);
PHP_METHOD(PhalconPlus_Base_Pagable, getPageSize);
PHP_METHOD(PhalconPlus_Base_Pagable, getOrderBys);
PHP_METHOD(PhalconPlus_Base_Pagable, getOffset);
PHP_METHOD(PhalconPlus_Base_Pagable, getLimit);
PHP_METHOD(PhalconPlus_Base_Pagable, setOrderBy);
PHP_METHOD(PhalconPlus_Base_Pagable, setOrderBys);
PHP_METHOD(PhalconPlus_Base_Pagable, hasOrderBy);
PHP_METHOD(PhalconPlus_Base_Pagable, setPageNo);
PHP_METHOD(PhalconPlus_Base_Pagable, setPageSize);
zend_object *zephir_init_properties_PhalconPlus_Base_Pagable(zend_class_entry *class_type TSRMLS_DC);

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_pagable_getpageno, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_pagable_getpageno, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_pagable_getpagesize, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_pagable_getpagesize, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_pagable_getorderbys, 0, 0, PhalconPlus\\Base\\ProtoOrderBy, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_pagable_getorderbys, 0, 0, IS_OBJECT, "PhalconPlus\\Base\\ProtoOrderBy", 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_pagable_getoffset, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_pagable_getoffset, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 70200
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_pagable_getlimit, 0, 0, IS_LONG, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_pagable_getlimit, 0, 0, IS_LONG, NULL, 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_pagable_setorderby, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, orderBy, PhalconPlus\\Base\\ProtoOrderBy, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_pagable_setorderbys, 0, 0, 1)
	ZEND_ARG_ARRAY_INFO(0, orderBys, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_pagable_setpageno, 0, 0, 1)
	ZEND_ARG_INFO(0, pageNo)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_pagable_setpagesize, 0, 0, 1)
	ZEND_ARG_INFO(0, pageSize)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_pagable_method_entry) {
	PHP_ME(PhalconPlus_Base_Pagable, getPageNo, arginfo_phalconplus_base_pagable_getpageno, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Pagable, getPageSize, arginfo_phalconplus_base_pagable_getpagesize, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Pagable, getOrderBys, arginfo_phalconplus_base_pagable_getorderbys, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Pagable, getOffset, arginfo_phalconplus_base_pagable_getoffset, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Pagable, getLimit, arginfo_phalconplus_base_pagable_getlimit, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Pagable, setOrderBy, arginfo_phalconplus_base_pagable_setorderby, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Pagable, setOrderBys, arginfo_phalconplus_base_pagable_setorderbys, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Pagable, hasOrderBy, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Pagable, setPageNo, arginfo_phalconplus_base_pagable_setpageno, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Pagable, setPageSize, arginfo_phalconplus_base_pagable_setpagesize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
