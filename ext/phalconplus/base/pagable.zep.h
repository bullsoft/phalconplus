
extern zend_class_entry *phalconplus_base_pagable_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_Pagable);

PHP_METHOD(PhalconPlus_Base_Pagable, getPageNo);
PHP_METHOD(PhalconPlus_Base_Pagable, getPageSize);
PHP_METHOD(PhalconPlus_Base_Pagable, getOrderBys);
PHP_METHOD(PhalconPlus_Base_Pagable, setOrderBy);
PHP_METHOD(PhalconPlus_Base_Pagable, setPageNo);
PHP_METHOD(PhalconPlus_Base_Pagable, setPageSize);
zend_object *zephir_init_properties_PhalconPlus_Base_Pagable(zend_class_entry *class_type TSRMLS_DC);

#ifdef ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_pagable_getorderbys, 0, 0, PhalconPlus\\Base\\ProtoOrderBy, 0)
#else
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_pagable_getorderbys, 0, 0, NULL, "PhalconPlus\\Base\\ProtoOrderBy", 0)
#endif
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_pagable_setorderby, 0, 0, 1)
	ZEND_ARG_OBJ_INFO(0, orderBy, PhalconPlus\\Base\\ProtoOrderBy, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_pagable_setpageno, 0, 0, 1)
	ZEND_ARG_INFO(0, pageNo)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_pagable_setpagesize, 0, 0, 1)
	ZEND_ARG_INFO(0, pageSize)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_pagable_method_entry) {
	PHP_ME(PhalconPlus_Base_Pagable, getPageNo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Pagable, getPageSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Pagable, getOrderBys, arginfo_phalconplus_base_pagable_getorderbys, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Pagable, setOrderBy, arginfo_phalconplus_base_pagable_setorderby, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Pagable, setPageNo, arginfo_phalconplus_base_pagable_setpageno, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_Pagable, setPageSize, arginfo_phalconplus_base_pagable_setpagesize, ZEND_ACC_PUBLIC)
	PHP_FE_END
};
