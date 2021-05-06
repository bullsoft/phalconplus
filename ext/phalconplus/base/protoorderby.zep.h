
extern zend_class_entry *phalconplus_base_protoorderby_ce;

ZEPHIR_INIT_CLASS(PhalconPlus_Base_ProtoOrderBy);

PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, getProperty);
PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, setProperty);
PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, setDirection);
PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, setAlias);
PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, getDirection);
PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, getAlias);
PHP_METHOD(PhalconPlus_Base_ProtoOrderBy, __toString);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protoorderby_getproperty, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_protoorderby_setproperty, 0, 1, PhalconPlus\\Base\\ProtoOrderBy, 0)
	ZEND_ARG_TYPE_INFO(0, property, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_protoorderby_setdirection, 0, 1, PhalconPlus\\Base\\ProtoOrderBy, 0)
	ZEND_ARG_OBJ_INFO(0, orderBy, PhalconPlus\\Enum\\OrderByDirection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_protoorderby_setalias, 0, 1, PhalconPlus\\Base\\ProtoOrderBy, 0)
	ZEND_ARG_TYPE_INFO(0, alias, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_phalconplus_base_protoorderby_getdirection, 0, 0, PhalconPlus\\Enum\\OrderByDirection, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protoorderby_getalias, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#if PHP_VERSION_ID >= 80000
ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_phalconplus_base_protoorderby___tostring, 0, 0, IS_STRING, 0)
#else
ZEND_BEGIN_ARG_INFO_EX(arginfo_phalconplus_base_protoorderby___tostring, 0, 0, 0)
#endif
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(phalconplus_base_protoorderby_method_entry) {
	PHP_ME(PhalconPlus_Base_ProtoOrderBy, getProperty, arginfo_phalconplus_base_protoorderby_getproperty, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoOrderBy, setProperty, arginfo_phalconplus_base_protoorderby_setproperty, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoOrderBy, setDirection, arginfo_phalconplus_base_protoorderby_setdirection, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoOrderBy, setAlias, arginfo_phalconplus_base_protoorderby_setalias, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoOrderBy, getDirection, arginfo_phalconplus_base_protoorderby_getdirection, ZEND_ACC_PUBLIC)
	PHP_ME(PhalconPlus_Base_ProtoOrderBy, getAlias, arginfo_phalconplus_base_protoorderby_getalias, ZEND_ACC_PUBLIC)
#if PHP_VERSION_ID >= 80000
	PHP_ME(PhalconPlus_Base_ProtoOrderBy, __toString, arginfo_phalconplus_base_protoorderby___tostring, ZEND_ACC_PUBLIC)
#else
	PHP_ME(PhalconPlus_Base_ProtoOrderBy, __toString, NULL, ZEND_ACC_PUBLIC)
#endif
	PHP_FE_END
};
